
#include "memory.h"
kernel::driver2::driver2() : pid(0u)
{}

kernel::driver2::~driver2()
{}



typedef __int64(__fastcall* pfunc_hk_t)(__int64 a1);;
pfunc_hk_t pHookFunc = (pfunc_hk_t)NULL;



template<bool debug>
bool invoke_driver(fptr_data::kernel_com* com, fptr_data::kernel_opr op)
{
	if (!pHookFunc) return false;

	com->error = fptr_data::kernel_err::unset_err;
	if (!pHookFunc((uintptr_t)com) &&
		com->error == fptr_data::kernel_err::unset_err)
	{
		printf(skCrypt("Driver not loaded.\n"));
		return false;
	}

	if (com->success) return true && com->error == fptr_data::kernel_err::no_error;
	if (!debug) return false;
	return false;
}



HMODULE ensure_dll_load()
{
	return LoadLibraryA(skCrypt("win32u.dll"));
}


bool kernel::driver2::init()
{
	if (!pHookFunc)
	{
		HMODULE hDll = GetModuleHandleA(skCrypt("win32u.dll"));
		if (!hDll)
		{
			hDll = ensure_dll_load();
			if (!hDll) return false;
		}

		pHookFunc = (pfunc_hk_t)GetProcAddress(hDll, skCrypt("NtUserShutdownBlockReasonQuery"));
		if (!pHookFunc)
		{
			pHookFunc = (pfunc_hk_t)NULL;
			return false;
		}
	}

	if (get_process_base(GetCurrentProcessId()) != (uintptr_t)GetModuleHandle(NULL))
		return false;
	return true;
}



void kernel::driver2::unload()
{
	fptr_data::kernel_com com{};
	invoke_driver<true>(&com, fptr_data::kernel_opr::unhook_driver);
}

uintptr_t kernel::driver2::get_process_module(const char* name)
{
	fptr_data::kernel_com com{};
	com.target_pid = this->pid;
	com.name = name;
	com.request_key = 3;
	if (!invoke_driver<true>(&com, fptr_data::kernel_opr::get_process_module))
		return 0;
	return com.buffer;
}

uintptr_t kernel::driver2::get_process_base(uint32_t _pid)
{
	fptr_data::kernel_com com{};
	com.target_pid = _pid ? _pid : this->pid;
	com.request_key = 4;
	if (invoke_driver<true>(&com, fptr_data::kernel_opr::get_process_base))
		return com.buffer;
	return 0;
}
uintptr_t kernel::driver2::get_guarded_base()
{
	fptr_data::kernel_com com{};
	com.request_key = 9;
	if (invoke_driver<true>(&com, fptr_data::kernel_opr::get_guarded_base))
		return com.buffer;
	return 0;
}
uintptr_t kernel::driver2::get_peb(uint32_t pid)
{
	fptr_data::kernel_com com{};
	com.request_key = 12;
	com.target_pid = pid;
	if (invoke_driver<true>(&com, fptr_data::kernel_opr::get_peb))
		return com.buffer;
	return 0;
}
bool kernel::driver2::read_buffer(uintptr_t addr, uint8_t* buffer, size_t size, size_t* transfer)
{
	fptr_data::kernel_com com{};
	com.target_pid = this->pid;
	com.user_pid = GetCurrentProcessId();

	com.address = addr;
	com.buffer = (uintptr_t)buffer;
	com.size = size;
	com.request_key = 1;
	if (!invoke_driver<true>(&com, fptr_data::kernel_opr::read))
		return false;

	if (transfer)
		*transfer = com.transfer;
	return true;
}
bool kernel::driver2::write_buffer(uintptr_t addr, uint8_t* buffer, size_t size, size_t* transfer)
{
	fptr_data::kernel_com com{};
	com.target_pid = this->pid;
	com.user_pid = GetCurrentProcessId();

	com.address = addr;
	com.buffer = (uintptr_t)buffer;
	com.size = size;
	com.request_key = 2;
	if (!invoke_driver<true>(&com, fptr_data::kernel_opr::write))
		return false;

	if (transfer)
		*transfer = com.transfer;
	return true;
}

NTSTATUS kernel::driver2::setwindowaffinity(HWND window_handle, uint32_t value)
{
	fptr_data::kernel_com com{};
	com.request_key = 10;
	com.game = reinterpret_cast<uint64_t>(window_handle);
	com.target_pid = value;

	if (!invoke_driver<true>(&com, fptr_data::kernel_opr::hide_window))
		return false;
	return true;
}




