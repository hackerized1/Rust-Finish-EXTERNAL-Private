#pragma once
#include <cstdint>
#include <stdio.h>
#include <string>
#include <random>
#include <Windows.h>
#include "skCrypt.h"
#include "sinmapper/drv_image.hpp"
#include "sinmapper/vdm.hpp"
#include "sinmapper/vdm_ctx.hpp"
#include "driver.h"
namespace fptr_data
{


	enum class kernel_opr : uint32_t
	{
		read = 1,
		write = 2,
		get_process_module = 3,
		get_process_base = 4,
		unhook_driver = 5,


		alloc = 6,
		free = 7,
		protect = 8,
		get_guarded_base = 9,
		hide_window = 10,
		mouse_move = 11,
		get_peb = 12
	};


	enum class kernel_err : uint16_t
	{
		invalid_process = 2,
		check_fail,
		no_operation,
		invalid_data,

		no_error = 0,
		unset_err = 1
	};

	struct kernel_com
	{
		int request_key;
		uint64_t game;
		bool success;
		kernel_err error;
		float x;
		float y;
		unsigned short button_flags;
		uint32_t target_pid;
		uint32_t user_pid;

		uintptr_t address;
		uintptr_t buffer;

		union
		{
			size_t size;
			const char* name;
		};

		size_t transfer;
	};
}
namespace kernel
{
	class driver2
	{
	public:
		driver2();
		~driver2();

	public:
		uint32_t pid;
		uintptr_t VirtualAddress;
		void attach(uint32_t pid) { this->pid = pid; }
		bool init();

		bool IsGuarded2(uintptr_t pointer)
		{
			constexpr uintptr_t filter = 0xFFFFFFF000000000;
			uintptr_t result = pointer & filter;
			return result == 0x8000000000 || result == 0x10000000000;
		}
		uint64_t ValidatePtr2(uint64_t address)
		{
			if (IsGuarded2(address)) {
				return VirtualAddress + (address & 0xFFFFFF);
			}
			else {
				return address;
			}
		}
		void unload();
		template<typename Value_T>
		Value_T read(uintptr_t addr)
		{
			Value_T val;
			if (!this->read_buffer(addr, (uint8_t*)&val, sizeof(Value_T)))
				memset((void*)&val, 0, sizeof(val));
			return val;
		}

		template<typename Value_T>
		Value_T read_guarded(uintptr_t addr)
		{
			Value_T val;
			if (!this->read_buffer(addr, (uint8_t*)&val, sizeof(Value_T)))
				memset((void*)&val, 0, sizeof(val));
			if (IsGuarded2(val))
			{
				val = ValidatePtr2(val);
			}
			return val;
		}
		template<typename T>
		void read_array(uint64_t address, T* array, size_t len) {
			read_buffer(address, (uint8_t*)&array, sizeof(T) * len);
		}

		uint64_t read_chain(uint64_t base, const std::vector<uint64_t>& offsets) {
			uint64_t result = read<uint64_t>(base + offsets.at(0));
			for (int i = 1; i < offsets.size(); i++) {
				result = read<uint64_t>(result + offsets.at(i));
			}
			return result;
		}

		std::wstring read_wstring(uintptr_t String_address, SIZE_T size)
		{
			const auto buffer = std::make_unique<wchar_t[]>(size);
			read_buffer(String_address, (uint8_t*)buffer.get(), size * 2);
			return std::wstring(buffer.get());
		}

		std::wstring read_unicode(const std::uintptr_t address, std::size_t size)
		{
			const auto buffer = std::make_unique<wchar_t[]>(size);
			read_buffer(address, (uint8_t*)buffer.get(), size * 2);
			return std::wstring(buffer.get());
		}

		template<typename Value_T>
		void write(uintptr_t addr, Value_T val) { this->write_buffer(addr, (uint8_t*)&val, sizeof(Value_T)); }
		uintptr_t get_process_module(const char* name);
		uintptr_t get_process_base(uint32_t _pid = 0);
		uintptr_t get_guarded_base();
		uintptr_t get_peb(uint32_t pid);
		NTSTATUS setwindowaffinity(HWND window_handle, uint32_t value);
		bool read_buffer(uintptr_t addr, uint8_t* buffer, size_t size, size_t* transfer = nullptr);
		bool write_buffer(uintptr_t addr, uint8_t* buffer, size_t size, size_t* transfer = nullptr);

	};
}
inline kernel::driver2 driver;
inline bool LoadDriver()
{

	const auto nt_headers = portable_executable::get_nt_headers(Drv.data());

	if (nt_headers->Signature != IMAGE_NT_SIGNATURE)
	{
		std::printf(skCrypt("[-] invalid nt signature of target file\n"));
		system("pause");
	}

	std::uint32_t image_size = nt_headers->OptionalHeader.SizeOfImage;
	std::string str = ".data";
	char* cstr = str.data();
	potential_drivers signed_driver = util::get_driver_info("mlx4_bus.sys", cstr, image_size);

	if (signed_driver.number_of_sections == 0)
	{
		std::printf(skCrypt("[-] failed to get info for potential driver.\n"));
		system("pause");
	}

	NTSTATUS load_status = driver2::load(signed_driver.file_path, signed_driver.file_name);
	std::uintptr_t signed_module_base = util::get_module_base(signed_driver.file_name.c_str());

	if ((load_status != STATUS_SUCCESS && load_status != 0x1) || !signed_module_base)
	{
		printf(skCrypt("[-] failed to load [%s] [0x%x]\n"), signed_driver.file_name.c_str(), load_status);
		system("pause");
	}

	//std::printf(skCrypt("[+] loaded [vgk.sys] at [%p] with result [0x%x]\n"), signed_driver.file_name, signed_module_base, load_status);

	std::uintptr_t start_map = signed_module_base + signed_driver.section_offset;


	static const auto kernel_base = util::get_module_base(skCrypt("ntoskrnl.exe"));

	static const auto mm_pte_offset = util::memory::get_mi_pte_address_fn();
	static const auto mm_pde_offset = util::memory::get_mi_pde_address_fn();

	if (!mm_pte_offset || !mm_pde_offset)
	{
		printf(skCrypt("[-] failed to sig scan pte functions\n"));
		system("pause");
	}

	const auto [drv_handle, drv_key] = vdm::load_drv();
	if (!drv_handle || drv_key.empty())
	{
		std::printf(skCrypt("[-] unable to load vulnerable driver\n"));
		system("pause");
	}

	//std::printf(skCrypt("[+] vulnerable driver loaded [%s]\n"), drv_key.c_str());

	vdm::vdm_ctx kernel{};

	if (!kernel.clear_piddb_cache(drv_key, util::get_file_header((void*)vdm::raw_driver)->TimeDateStamp))
	{
		std::printf(skCrypt("[-] failed to clear piddbcache table\n"));
		vdm::unload_drv(drv_handle, drv_key);

		system("pause");
	}

	for (std::uintptr_t start = start_map; start < start_map + image_size; start += PAGE_4KB)
	{
		auto pde = kernel.syscall<MiGetPteAddress>(reinterpret_cast<void*>(mm_pde_offset), start);

		::pde new_pde = kernel.rkm<::pde>(pde);

		std::printf(skCrypt("[+] manipulating page table [%p] large page [%x]\n"), start, new_pde.large_page);

		if (new_pde.large_page)
		{
			new_pde.nx = 0;
			new_pde.rw = 1;

			kernel.wkm<::pde>(pde, new_pde);
		}
		else
		{
			auto pte = kernel.syscall<MiGetPteAddress>(reinterpret_cast<void*>(mm_pte_offset), start);

			::pte new_pte = kernel.rkm<::pte>(pte);

			new_pte.nx = 0;
			new_pte.rw = 1;

			kernel.wkm<::pte>(pte, new_pte);
		}
	}

	void* local_image_base = VirtualAlloc(0, image_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	memcpy(local_image_base, Drv.data(), nt_headers->OptionalHeader.SizeOfHeaders);

//	std::printf(skCrypt("\n[+] local mapped image base [%p]\n"), local_image_base);

	PIMAGE_SECTION_HEADER current_image_section = IMAGE_FIRST_SECTION(nt_headers);

	for (auto i = 0; i < nt_headers->FileHeader.NumberOfSections; ++i)
	{
		void* local_section = reinterpret_cast<void*>(reinterpret_cast<uint64_t>(local_image_base) + current_image_section[i].VirtualAddress);
		memcpy(local_section, reinterpret_cast<void*>(reinterpret_cast<uint64_t>(Drv.data()) + current_image_section[i].PointerToRawData), current_image_section[i].SizeOfRawData);

		std::printf(skCrypt("[+] mapping section [%s] [%p] > [%p] [0x%x]\n"), current_image_section[i].Name, local_section, start_map + current_image_section[i].VirtualAddress, current_image_section[i].SizeOfRawData);
	}


	portable_executable::relocate_image_by_delta(portable_executable::get_relocations(local_image_base), start_map - nt_headers->OptionalHeader.ImageBase);

	if (!portable_executable::resolve_imports(portable_executable::get_imports(local_image_base)))
	{
		std::printf(skCrypt("[-] failed to resolve imports\n"));
		vdm::unload_drv(drv_handle, drv_key);
		system("pause");
	}

	RtlZeroMemory(local_image_base, nt_headers->OptionalHeader.SizeOfHeaders);
	kernel.wkm(reinterpret_cast<void*>(start_map), local_image_base, image_size);

	std::uintptr_t entry_point = start_map + nt_headers->OptionalHeader.AddressOfEntryPoint;

	//std::printf(skCrypt("\n[+] mapped entry point [%p]\n"), entry_point);

	NTSTATUS result = kernel.syscall<EntryCall>(reinterpret_cast<void*>(entry_point), start_map, nt_headers->OptionalHeader.SizeOfImage);

	//std::printf(skCrypt("[+] driver entry returned [0x%x]\n"), result);

	if (!vdm::unload_drv(drv_handle, drv_key))
	{
		std::printf(skCrypt("[-] unable to unload vulnerable driver\n"));
		system("pause");
	}
}
