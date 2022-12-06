#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <emmintrin.h>
#include "struct.h"
#include <iostream>
#include <iostream>
#define COLOUR(x) x/255
uintptr_t Entity;

static std::string random_string(int length)
{
	std::string str(("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(str.begin(), str.end(), generator);
	return str.substr(0, length);    // assumes 32 < number of characters in str         
}

static DWORDLONG random_number(DWORDLONG min, DWORDLONG max)
{
	srand(time(0));
	DWORDLONG out = min + rand() % (max - min + 1);
	return out;
}

static std::string randomclassname = "Rust-Cheat                                                                                          " + random_string(random_number(4, 16));


int realkey;
int keystatus;
int aimkey;

bool showmenu = true;
bool espvisiblecheck;
bool box;
ImVec4 boxcolor = ImVec4(255, 255, 255, 255);
bool box3;
ImVec4 box3color = ImVec4(255, 255, 255, 255);
bool box2;
ImVec4 box2color = ImVec4(255, 255, 255, 255);
bool skeleton;
ImVec4 skeletoncolor = ImVec4(255, 255, 255, 255);
bool snapline;
ImVec4 snaplinecolor = ImVec4(255, 255, 255, 120);
bool paintinside;
ImVec4 paintinsidecolor = ImVec4(0, 0, 0, 100);
bool name;
ImVec4 namecolor = ImVec4(255, 255, 255, 255);
bool healthbar;
bool healthbar2;
bool WoundedAlert;
ImVec4 WoundedAlertColor = ImVec4(255, 0, 0, 255);
bool handweapon;
ImVec4 handweaponcolor = ImColor(155, 255, 255);
bool showdistancee;
ImVec4 showdistanceecolor = ImColor(255, 255, 255);

bool sleeper;
bool backpack;
ImVec4 backpackcolor = ImVec4(255, 255, 255, 255);
bool playercorpse;
ImVec4 playercorpsecolor = ImVec4(255, 255, 255, 255);
bool NPCNames;
ImVec4 NPCNamescolor = ImVec4(255, 255, 255, 255);
bool tunneldweller;
ImVec4 tunneldwellerscolor = ImColor(255, 127, 0);
bool scientistnpc;
ImVec4 scientistnpccolor = ImColor(10, 10, 143);
bool scarecrow;
ImVec4 scarecrowcolor = ImColor(143, 10, 143);


bool playerinfoo;
//
bool wolf;
ImVec4 wolfcolor = ImVec4(215, 240, 180, 255);
bool bear;
ImVec4 bearcolor = ImVec4(215, 240, 180, 255);
bool stag;
ImVec4 stagcolor = ImVec4(215, 240, 180, 255);
bool chicken;
ImVec4 chickencolor = ImVec4(215, 240, 180, 255);
bool boar;
ImVec4 boarcolor = ImVec4(215, 240, 180, 255);
bool horse;
ImVec4 horsecolor = ImVec4(215, 240, 180, 255);
//
bool weapons = false;
ImVec4 weaponscolor = ImVec4(216, 216, 0, 200);

//
bool stone;
ImVec4 stonecolor = ImVec4(255, 255, 255, 255);
bool sulfur;
ImVec4 sulfurcolor = ImVec4(216, 216, 0, 200);
bool metal;
ImVec4 metalcolor = ImColor(128, 128, 128);
bool hemp;
ImVec4 hempcolor = ImColor(25, 255, 25);
bool mushroom;
ImVec4 mushroomcolor = ImColor(255, 128, 0);

bool military;
ImVec4 militarycolor = ImColor(236, 236, 236);
bool elite;
ImVec4 elitecolor = ImColor(236, 236, 236);
bool loot;
ImVec4 lootcolor = ImColor(236, 236, 236);
bool food;
ImVec4 foodcolor = ImColor(236, 236, 236);
bool medical;
ImVec4 medicalcolor = ImColor(236, 236, 236);
bool toolbox;
ImVec4 toolboxcolor = ImColor(236, 236, 236);

bool VisibleCheck = true;

bool autoturret;
ImVec4 autoturretcolor = ImColor(236, 236, 236);
bool toolcupboard;
ImVec4 toolcupboardcolor = ImColor(236, 236, 236);

bool stone2;
ImVec4 stone2color = ImVec4(255, 255, 255, 255);
bool sulfur2;
ImVec4 sulfur2color = ImVec4(216, 216, 0, 255);
bool metal2;
ImVec4 metal2color = ImColor(128, 128, 128);

bool airdrop;
ImVec4 airdropcolor = ImColor(255, 255, 0);
bool minicopter;
ImVec4 minicoptercolor = ImColor(236, 236, 236);
bool cars;
ImVec4 carscolor = ImColor(236, 236, 236);
bool scrapheli;
ImVec4 scraphelicolor = ImColor(236, 236, 236);
bool patrolheli;
ImVec4 patrolhelicolor = ImColor(236, 236, 236);
bool rhib;
ImVec4 rhibcolor = ImColor(236, 236, 236);
bool boat;
ImVec4 boatcolor = ImColor(236, 236, 236);
bool teamignore;
bool stash;
ImVec4 stashcolor = ImVec4(255, 255, 0, 255);

#define safe_read(Addr, Type) driver.read<Type>(Addr)
#define safe_write(Addr, Data, Type) driver.write<Type>(Addr, Data)

#define BaseGameMode 56833128 // "Signature": "System_Collections_Generic_List_BaseGameMode__c*"
#define BaseGameMode2 56833280 // "Signature": "BaseGameMode_c*"
#define ConVar_Client_c 56835360 // ConVar_Client_c*
#define ConVar_Admin_c 56830176 // ConVar_Admin_c*
#define TodSkyy 56852656 // "Signature": "TOD_Sky_c*"
#define oFovConVarGraphics 56843288 // "Signature": "ConVar_Graphics_c*"
#define ConsoleSystem_Index_c 56943440 // "Signature": "ConsoleSystem_Index_c*"

#define playerflags 0x690 // public BasePlayer.PlayerFlags playerFlags;
#define groundAngle 0xC4 // groundAngle
#define groundAngleNew 0xC8 // groundAngleNew
#define oGravityMultiplier 0x84 // public float gravityMultiplier;
#define oclothingWaterSpeedBonus 0x768 // public float clothingWaterSpeedBonus;
#define clothingMoveSpeedReduction 0x764 // public float clothingMoveSpeedReduction;
#define gravityTestRadius 0x80// public float gravityTestRadius
#define capsuleHeight 0x68 // public float capsuleHeight
#define capsuleCenter 0x6C // public float capsuleCenter
#define oGameObjectManager 0x17C1F18 // GOM OFFSET
#define oVisible 0x288 //	internal bool visible;

//class BasePlayer
#define oPlayerFlags 0x690 // 0x680 // public BasePlayer.PlayerFlags playerFlags;
#define oPlayerMovement 0x4F8 // 0x4E8 // public BaseMovement movement;
#define wasFalling  0x148// private bool wasFalling
#define previousVelocity  0xE4// private Vector3 previousVelocity
#define groundTime  0xCC// private float groundTime
#define oLifestate 0x224 // public BaseCombatEntity.LifeState lifestate;
#define oClientTeam 0x5A8 // public PlayerTeam clientTeam;
#define oSteamID 0x6D8 // public ulong userID;

#define oFlying 0x149 // private bool flying;
#define oPlayerDistance 0x10 //public float Distance;



//jump shot icin //dump.cs
#define oFlagOnGround 4 // public const ModelState.Flag OnGround = 4;
#define oModelState 0x600 // 0x5C8 // public ModelState modelState;

//RECOIL ICIN
#define oPlayerActiveItem 0x5D8 // private uint clActiveItem; // 0x5C8
#define oPlayerInput 0x4F0 // public PlayerInput input;
#define bodyRotation 0x2C // private Quaternion bodyRotation; // 0x2C
#define headRotation 0x48 // private Quaternion headRotation; // 0x48

#define oPlayerModel 0x4D0 // public PlayerModel playerModel;
#define onewVelocity 0x23C // private Vector3 newVelocity



#define oItemListOffset 0x38 //public List<Item> itemList; // 0x38
#define oBeltOffset 0x28 // public List<PlayerInventoryProperties.ItemAmountSkinned> belt;
#define oBeltContaint 0x38
#define oEokaSuccessFraction 0x378 // public float successFraction;
#define oFastCompoundBow 0x390    // public float stringHoldDurationMax; // 0x378
#define oCreatedProjectile 0x370 // private List<Projectile> createdProjectiles; // 0x358
#define oFastCompoundBowMoving 0x3D8 // protected float movementPenalty; // 0x3B8
#define oAutomatic 0x290 // public bool automatic;


#define oCorpsePlayerName 0x2C8// public string _playerName; // 0x2B0

#define oSparkThisFrame 0x388 // private bool _didSparkThisFrame; // 0x370

#define oAttackready 0x378 // protected bool attackready;
#define oArrowBack 0x37C // private float arrowBack;

#define oCamSpeed 0x3C // public static float camspeed; // 0x2C
#define oCamLerp 0x30 // public static float camlerp; // 0x20

#define oAmbientMode 0x18DEF90 //// public static void set_ambientMode(AmbientMode value) { }  // 0x1857540
#define oambientIntensit 0x18DEED0 //public static void set_ambientIntensity(float value) { } // 0x1857480
#define oambientLight 0x18DEF50 //public static void set_ambientLight(Color value) { } // 0x1857500

#define oClothingMoveSpeedReduction 0x764 // public float clothingMoveSpeedReduction;
#define oClothingWaterSpeedBonus 0x768 // public float clothingWaterSpeedBonus;

#define oTodSky 0x11AFFF0 // public T GetComponent() { } public static TOD_Sky get_Instance() { }


#define oClothingBlocksAiming 0x760 // public bool clothingBlocksAiming
#define oClothingAccuracyBonus 0x76C // public float clothingAccuracyBonus;

#define oPlayerEyes 0x698 // public PlayerEyes eyes; 
#define oHeld 0xA0 // private EntityRef heldEntity
#define oActiveUID 0x5D8 // private uint clActiveItem;
#define oPlayerInventory 0x6A0 // public PlayerInventory inventory;
#define oContainerBelt 0x28 // public ItemContainer
#define oBeltContentList 0x38 // public List<Item> contents   or   public List<int> availableSlots;
#define oRecoilProperties 0x2E0 // public RecoilProperties recoil;

#define oRecoilYawMin 0x18  // public float recoilYawMin;
#define oRecoilYawMax 0x1C  // public float recoilYawMax;
#define oRecoilPitchMin 0x20 // public float recoilPitchMin;
#define oRecoilPitchMax 0x24 // public float recoilPitchMax;

#define oAimconeCurveScale 0x60 // public float aimconeCurveScale;
#define oStancePenalty 0x324 //private float stancePenalty;
#define oAimCone 0x2F0 //public float aimCone;
#define oHipAimCone 0x2F4 //public float hipAimCone;
#define oAimconePenaltyPerShot 0x2F8 //public float aimconePenaltyPerShot;


#define oAttackRadius 0x29C // public float attackRadius;
#define oisAutomatic 0x2A0//public bool isAutomatic;
#define omaxDistance 0x298 //public float maxDistance;
#define oBlockSprintOnAttack 0x2A1 //public bool blockSprintOnAttack;
#define oonlyThrowAsProjectile 0x282 //public bool onlyThrowAsProjectile;
#define othrowReady 0x2D8 //private bool throwReady;




std::uint32_t get_pid(const std::string& name = "RustClient.exe")
{
	const auto snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 proc_entry{};
	proc_entry.dwSize = sizeof proc_entry;

	auto found_process = false;
	if (!!Process32First(snap, &proc_entry)) {
		do {
			if (name == proc_entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!Process32Next(snap, &proc_entry));
	}

	CloseHandle(snap);
	return found_process
		? proc_entry.th32ProcessID
		: 0;
}
struct monostr
{
	char buffer[128];
};

std::string readchar(uintptr_t addr) {
	std::string str = safe_read(addr, monostr).buffer;
	if (!str.empty())
		return str;
	else
		return "31";
}
enum BoneList : int
{
	l_hip = 1,
	l_knee,
	l_foot,
	l_toe,
	l_ankle_scale,
	pelvis,
	penis,
	GenitalCensor,
	GenitalCensor_LOD0,
	Inner_LOD0,
	GenitalCensor_LOD1,
	GenitalCensor_LOD2,
	r_hip,
	r_knee,
	r_foot,
	r_toe,
	r_ankle_scale,
	spine1,
	spine1_scale,
	spine2,
	spine3,
	spine4,
	l_clavicle,
	l_upperarm,
	l_forearm,
	l_hand,
	l_index1,
	l_index2,
	l_index3,
	l_little1,
	l_little2,
	l_little3,
	l_middle1,
	l_middle2,
	l_middle3,
	l_prop,
	l_ring1,
	l_ring2,
	l_ring3,
	l_thumb1,
	l_thumb2,
	l_thumb3,
	IKtarget_righthand_min,
	IKtarget_righthand_max,
	l_ulna,
	neck,
	head,
	jaw,
	eyeTranform,
	l_eye,
	l_Eyelid,
	r_eye,
	r_Eyelid,
	r_clavicle,
	r_upperarm,
	r_forearm,
	r_hand,
	r_index1,
	r_index2,
	r_index3,
	r_little1,
	r_little2,
	r_little3,
	r_middle1,
	r_middle2,
	r_middle3,
	r_prop,
	r_ring1,
	r_ring2,
	r_ring3,
	r_thumb1,
	r_thumb2,
	r_thumb3,
	IKtarget_lefthand_min,
	IKtarget_lefthand_max,
	r_ulna,
	l_breast,
	r_breast,
	BoobCensor,
	BreastCensor_LOD0,
	BreastCensor_LOD1,
	BreastCensor_LOD2,
	collision,
	displacement
};
int length(uintptr_t addr) { return safe_read(addr + 0x10, int); }

std::string readstring(uintptr_t addr) {
	try {
		static char buff[128] = { 0 };
		buff[length(addr)] = '\0';

		for (int i = 0; i < length(addr); ++i) {
			if (buff[i] < 128) {
				buff[i] = safe_read(addr + 0x14 + (i * 2), char);
			}
			else {
				buff[i] = '?';
				if (buff[i] >= 0xD800 && buff[i] <= 0xD8FF)
					i++;
			}
		}
		return std::string(&buff[0], &buff[length(addr)]);
	}
	catch (const std::exception& exc) {}
	return "Error";
}
UINT64 GetHeldItem(UINT64 LocalPlayer)
{
	const auto base_player = LocalPlayer;
	const auto active_item_id = driver.read<UINT64>(base_player + oActiveUID);
	const auto player_inventory = driver.read<UINT64>(base_player + oPlayerInventory);
	const auto inventory_belt = driver.read<UINT64>(player_inventory + oContainerBelt);
	const auto belt_contents_list = driver.read<UINT64>(inventory_belt + oBeltContentList);
	const auto belt_contents_sz = driver.read<uint32_t>(belt_contents_list + 0x14);
	const auto belt_contents = driver.read<UINT64>(belt_contents_list + 0x10);



	for (auto i = 0u; i <= 6; i++)
	{
		if (belt_contents != 0)
		{
			const auto current_item = driver.read<UINT64>(belt_contents + (0x20 + (i * 8)));
			if (!current_item) continue;
			if (active_item_id == driver.read<uint32_t>(current_item + 0x28)) return current_item;
		}
	}
}
struct FMinimalViewInfo {
	struct Vector3 Location; // 0x00(0x0c)
	struct Vector3 Rotation; // 0x0c(0x0c)
	float FOV; // 0x18(0x04)
};

#define oItemDefinition 0x20 // public ItemDefinition info;
#define oItemid 0x18 // public int itemid;

class WeaponData
{
public:
	int __fastcall GetItemID()
	{
		auto Info = driver.read<uintptr_t>((const uintptr_t)this + oItemDefinition);
		return driver.read<int>((const uintptr_t)Info + oItemid);
	}
	int __fastcall GetUID()
	{
		return driver.read<int>((const uintptr_t)this + 0x28);
	}

	std::string GetItemNameS()
	{
		auto info = driver.read<uintptr_t>((const uintptr_t)this + 0x20);

		auto display_name = driver.read<uintptr_t>(info + 0x20);

		std::wstring wide_name = driver.read_unicode(display_name + 0x14, sizeof(std::wstring));

		if (!wide_name.empty())
			return std::string(wide_name.begin(), wide_name.end()).c_str();

		return "No Item";


	}

	std::string GetAmmoType()
	{
		auto item_def = driver.read<uintptr_t>((const uintptr_t)this + 0x20);
		auto short_name = driver.read<uintptr_t>(item_def + 0x20);

		std::wstring wide_name = driver.read_unicode(short_name + 0x14, sizeof(std::wstring));

		return std::string(wide_name.begin(), wide_name.end()).c_str();

	}

};


class BasePlayer
{
public:

	Vector3 getBasePosition()
	{
		return driver.read<Vector3>((uintptr_t)this + oPlayerModel);
	}
	Vector3 Position3()
	{
		return GetPosition(GetTransform(l_index1)).midPoint(GetPosition(GetTransform(l_index1)));
	}

	Vector3 Position2()
	{
		return GetPosition(GetTransform(head)).midPoint(GetPosition(GetTransform(head)));
	}

	Vector3 Position()
	{
		return GetPosition(GetTransform(15)).midPoint(GetPosition(GetTransform(3)));
	}

	uintptr_t GetName() {
		auto player_name = safe_read((uintptr_t)this + 0x6F0, UINT_PTR);
		return player_name;
	}

	bool IsSleeping()
	{
		if (!(DWORD64)this)
			return true;

		DWORD64 Flags = driver.read<DWORD64>((DWORD64)this + oPlayerFlags);
		return Flags & 16;
	}
	float Health()
	{
		return driver.read<float>((uintptr_t)this + 0x22C);
	}
	bool IsDead()
	{
		if (!(const uintptr_t)this) return true;
		return driver.read<bool>((const uintptr_t)(const uintptr_t)this + oLifestate);
	}
	int GetTeamSize()
	{
		UINT64 ClientTeam = driver.read<UINT64>((const uintptr_t)(const uintptr_t)this + oClientTeam); // valid
		UINT64 members = driver.read<UINT64>(ClientTeam + 0x30);
		return driver.read<UINT64>(members + 0x18);
	}
	uintptr_t __fastcall IsTeamMate(int Id)
	{
		auto ClientTeam = driver.read<uintptr_t>((const uintptr_t)(const uintptr_t)this + oClientTeam);
		auto members = driver.read<uintptr_t>(ClientTeam + 0x30);
		auto List = driver.read<uintptr_t>(members + 0x10);
		auto player = driver.read<uintptr_t>(List + 0x20 + (Id * 0x8));
		return driver.read<uintptr_t>(player + 0x20);
	}
	Vector3 GetBoneByID(int BoneID) {
		return GetPosition(GetTransform(BoneID));
	}

	Vector3 GetPosition(uint64_t transform)
	{
		auto transform_internal = driver.read<uint64_t>(transform + 0x10);

		if (!transform_internal)
			return Vector3(0, 0, 0);

		auto some_ptr = driver.read<uint64_t>(transform_internal + 0x38);
		auto index = driver.read<int32_t>(transform_internal + 0x38 + sizeof(uint64_t));
		if (!some_ptr)
			return Vector3();

		auto relation_array = driver.read<uint64_t>(some_ptr + 0x18);
		if (!relation_array)
			return Vector3();

		auto dependency_index_array = driver.read<uint64_t>(some_ptr + 0x20);
		if (!dependency_index_array)
			return Vector3();

		__m128i temp_0;
		__m128 xmmword_1410D1340 = { -2.f, 2.f, -2.f, 0.f };
		__m128 xmmword_1410D1350 = { 2.f, -2.f, -2.f, 0.f };
		__m128 xmmword_1410D1360 = { -2.f, -2.f, 2.f, 0.f };
		__m128 temp_1;
		__m128 temp_2;
		auto temp_main = driver.read<__m128>(relation_array + index * 48);
		auto dependency_index = driver.read<int32_t>(dependency_index_array + 4 * index);

		while (dependency_index >= 0) {
			auto relation_index = 6 * dependency_index;

			temp_0 = driver.read<__m128i>(relation_array + 8 * relation_index + 16);
			temp_1 = driver.read<__m128>(relation_array + 8 * relation_index + 32);
			temp_2 = driver.read<__m128>(relation_array + 8 * relation_index);

			__m128 v10 = _mm_mul_ps(temp_1, temp_main);
			__m128 v11 = _mm_castsi128_ps(_mm_shuffle_epi32(temp_0, 0));
			__m128 v12 = _mm_castsi128_ps(_mm_shuffle_epi32(temp_0, 85));
			__m128 v13 = _mm_castsi128_ps(_mm_shuffle_epi32(temp_0, -114));
			__m128 v14 = _mm_castsi128_ps(_mm_shuffle_epi32(temp_0, -37));
			__m128 v15 = _mm_castsi128_ps(_mm_shuffle_epi32(temp_0, -86));
			__m128 v16 = _mm_castsi128_ps(_mm_shuffle_epi32(temp_0, 113));
			__m128 v17 = _mm_add_ps(
				_mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(v11, xmmword_1410D1350), v13),
								_mm_mul_ps(_mm_mul_ps(v12, xmmword_1410D1360), v14)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(v10), -86))),
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(v15, xmmword_1410D1360), v14),
								_mm_mul_ps(_mm_mul_ps(v11, xmmword_1410D1340), v16)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(v10), 85)))),
					_mm_add_ps(
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(v12, xmmword_1410D1340), v16),
								_mm_mul_ps(_mm_mul_ps(v15, xmmword_1410D1350), v13)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(v10), 0))),
						v10)),
				temp_2);

			temp_main = v17;
			dependency_index = driver.read<int32_t>(dependency_index_array + 4 * dependency_index);
		}

		return *reinterpret_cast<Vector3*>(&temp_main);
	}


	uintptr_t __fastcall GetItemsList() {
		auto Inventory = driver.read<uintptr_t>((const uintptr_t)this + oPlayerInventory);
		auto Belt = driver.read <uintptr_t>(Inventory + 0x28);
		auto ItemList = driver.read<uintptr_t>(Belt + 0x38);
		return driver.read<uintptr_t>(ItemList + 0x10);
	}

	std::wstring GetItemName()
	{
		auto Info = driver.read<uintptr_t>((const uintptr_t)this + 0x20); //Item -> info.

		auto ShortName = driver.read<uintptr_t>(Info + 0x20); //ItemDefinitnion -> shortname.

		auto wname = driver.read_unicode(ShortName + 0x14, 64);
		if (!wname.empty())
		{
			return wname;
		}
	}
	std::string __fastcall GetBeltItems(uintptr_t ItemsList, int Slot) {
		uintptr_t SlotItem;
		if (Slot == 1) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x20);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 2) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x28);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 3) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x30);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 4) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x38);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 5) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x40);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 6) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x48);
			if (!SlotItem) {
				return ("");
			}
		}

		auto Item1Info = driver.read<uintptr_t>(SlotItem + 0x20);
		if (!Item1Info) {
			return ("");
		}

		auto ItemDisplayName = driver.read<uintptr_t>(Item1Info + 0x28);
		if (!ItemDisplayName) {
			return ("");
		}

		auto ItemDisplayEnglish = driver.read<uintptr_t>(ItemDisplayName + 0x18);
		if (!ItemDisplayEnglish) {
			return ("");
		}

		auto NameTest = driver.read<uintptr_t>(ItemDisplayEnglish + 0x14);

		if (!NameTest) {
			return ("");
		}

		std::wstring Name = driver.read_wstring(ItemDisplayEnglish + 0x14, 1024);

		std::string output(Name.begin(), Name.end());
		if (output == "Dxeso") {
			return "";
		}

		return output;
	}
	bool __fastcall HasFlags(int Flg)
	{
		return driver.read<int>((const uintptr_t)(const uintptr_t)this + oPlayerFlags) & Flg;
	}
	bool __fastcall IsWounded()
	{
		if (!this) return false;
		return HasFlags(64); // wounded
	}
	UINT64 GetSteamID()
	{
		return driver.read<UINT64>((const uintptr_t)(const uintptr_t)this + oSteamID);
	}
	uintptr_t GetClothingItemsList() {
		auto Inventory = driver.read<uintptr_t>((const uintptr_t)this + oPlayerInventory);
		auto Belt = driver.read <uintptr_t>(Inventory + 0x30);
		auto ItemList = driver.read<uintptr_t>(Belt + 0x38);
		return driver.read<uintptr_t>(ItemList + 0x10);
	}
	std::string __fastcall GetClothingItems(uintptr_t ItemsList, int Slot) {
		uintptr_t SlotItem;
		if (Slot == 1) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x20);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 2) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x28);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 3) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x30);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 4) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x38);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 5) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x40);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 6) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x48);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 7) {
			SlotItem = driver.read<uintptr_t>(ItemsList + 0x50);
			if (!SlotItem) {
				return ("");
			}
		}

		auto Item1Info = driver.read<uintptr_t>(SlotItem + 0x20);
		if (!Item1Info) {
			return ("");
		}

		auto ItemDisplayName = driver.read<uintptr_t>(Item1Info + 0x28);
		if (!ItemDisplayName) {
			return ("");
		}

		auto ItemDisplayEnglish = driver.read<uintptr_t>(ItemDisplayName + 0x18);
		if (!ItemDisplayEnglish) {
			return ("");
		}

		std::wstring Name = driver.read_wstring(ItemDisplayEnglish + 0x14, 1024);

		std::string output(Name.begin(), Name.end());

		if (output == "Dxeso") {
			return " ";
		}
		return output;
	}

	uintptr_t GetTransform(int bone)
	{
		uintptr_t player_model = driver.read<uintptr_t>((uintptr_t)this + 0x130);// public Model model;_public class BaseEntity : BaseNetworkable, IProvider, ILerpTarget, IPrefabPreProcess // TypeDefIndex: 8714
		uintptr_t boneTransforms = driver.read<uintptr_t>(player_model + 0x48);//public Transform[] boneTransforms;
		uintptr_t BoneValue = driver.read<uintptr_t>((boneTransforms + (0x20 + (bone * 0x8))));
		return BoneValue;
	}

	void SetVA(const Vector2& VA)
	{
		UINT64 Input = driver.read<UINT64>(Local_Player + oPlayerInput);
		driver.write<Vector2>(Input + 0x3C, VA); //     private Vector3 bodyAngles;
	}

	Vector3 __fastcall GetVelocity()
	{
		auto PlayerModel = driver.read<uintptr_t>((const uintptr_t)this + oPlayerModel);
		return driver.read<Vector3>(PlayerModel + onewVelocity); //     private Vector3 newVelocity;
	}

	bool IsVisible() {
		auto PlayerModel = driver.read<UINT64>((const uintptr_t)this + oPlayerModel);
		return driver.read<bool>(PlayerModel + oVisible);
	}

	WeaponData* __fastcall GetWeaponInfo(int Id)
	{
		auto Inventory = driver.read<uintptr_t>((const uintptr_t)this + oPlayerInventory);
		auto Belt = driver.read<uintptr_t>(Inventory + 0x28);
		auto ItemList = driver.read<uintptr_t>(Belt + 0x38);
		auto Items = driver.read<uintptr_t>(ItemList + 0x10);
		return (WeaponData*)driver.read<uintptr_t>(Items + 0x20 + (Id * 0x8));
	}

	WeaponData* __fastcall GetActiveWeapon()
	{
		int ActUID = driver.read<int>((const uintptr_t)this + oActiveUID);
		if (!ActUID) return nullptr;
		WeaponData* ActiveWeapon;
		for (int i = 0; i < 6; i++)
			if (ActUID == (ActiveWeapon = GetWeaponInfo(i))->GetUID()) {
				return ActiveWeapon;
			}
		return nullptr;
	}
	std::string __fastcall GetActiveWeaponText() {
		uint16_t ItemID = this->GetActiveWeapon()->GetItemID();
		if (ItemID == 0xB98E) { //AK
			return ("Assault Rifle");
		}
		else if (ItemID == 0x31E1) { //SMG
			return ("Custom SMG");
		}
		else if (ItemID == 0x9A57) { //lR
			return ("LR-300 Assault Rifle");
		}
		else if (ItemID == 0x9C37) { //MP5
			return ("MP5");
		}
		else if (ItemID == 0xA375) { //Tommy???
			return ("Thompson");
		}
		else if (ItemID == 0xBB78) { //m249
			return ("M249");
		}
		else if (ItemID == 0x0EC1) { //l96
			return ("L96");
		}
		else if (ItemID == 0x82C3) { //Bolty???
			return ("Bolt Rifle");
		}
		else if (ItemID == 0x5371) { //M39
			return ("M39");
		}
		else if (ItemID == 0x3261) { //Uknown
			return ("Nail Gun");
		}
		else if (ItemID == 0x2660) { //Uknown
			return ("Grenade Launcher");
		}
		else if (ItemID == 0xE126) { //REVO
			return ("Revolver");
		}
		else if (ItemID == 0x2593) { //PYTHON
			return ("Python");
		}
		else if (ItemID == 0xEBB5) { //m92 pistol
			return ("M92");
		}
		else if (ItemID == 0x142C) { //SEMI PISTOL
			return ("Semi Pistol");
		}
		else if (ItemID == 0xE257) { //SAR
			return ("Semi Auto Rifle");
		}
		else
		{
			return (" "); // No Item
		}
	}
};



class LPlayerBase
{
public:
	BasePlayer* closestPlayer;
	BasePlayer* BasePlayer = nullptr;
	Matrix4x4* pViewMatrix = nullptr;
	bool WorldToScreen(const Vector3& EntityPos, Vector2& ScreenPos)
	{
		if (!pViewMatrix) return false;
		Vector3 TransVec = Vector3(safe_read((ULONG64)&pViewMatrix->_14, float), safe_read((ULONG64)&pViewMatrix->_24, float), safe_read((ULONG64)&pViewMatrix->_34, float));
		Vector3 RightVec = Vector3(safe_read((ULONG64)&pViewMatrix->_11, float), safe_read((ULONG64)&pViewMatrix->_21, float), safe_read((ULONG64)&pViewMatrix->_31, float));
		Vector3 UpVec = Vector3(safe_read((ULONG64)&pViewMatrix->_12, float), safe_read((ULONG64)&pViewMatrix->_22, float), safe_read((ULONG64)&pViewMatrix->_32, float));
		float w = Dot(TransVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_44, float);
		if (w < 0.098f) return false;
		float y = Dot(UpVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_42, float);
		float x = Dot(RightVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_41, float);
		ScreenPos = Vector2((GetWindowSize().x / 2) * (1.f + x / w), (GetWindowSize().y / 2) * (1.f - y / w));
		return true;
	}

	bool WorldToScreen(const Vector3& EntityPos, Vector3& ScreenPos)
	{
		if (!pViewMatrix) return false;
		Vector3 TransVec = Vector3(safe_read((ULONG64)&pViewMatrix->_14, float), safe_read((ULONG64)&pViewMatrix->_24, float), safe_read((ULONG64)&pViewMatrix->_34, float));
		Vector3 RightVec = Vector3(safe_read((ULONG64)&pViewMatrix->_11, float), safe_read((ULONG64)&pViewMatrix->_21, float), safe_read((ULONG64)&pViewMatrix->_31, float));
		Vector3 UpVec = Vector3(safe_read((ULONG64)&pViewMatrix->_12, float), safe_read((ULONG64)&pViewMatrix->_22, float), safe_read((ULONG64)&pViewMatrix->_32, float));
		float w = Dot(TransVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_44, float);
		if (w < 0.098f) return false;
		float y = Dot(UpVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_42, float);
		float x = Dot(RightVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_41, float);
		ScreenPos = Vector3((GetWindowSize().x / 2) * (1.f + x / w), (GetWindowSize().y / 2) * (1.f - y / w), 0);
		return true;
	}
};


LPlayerBase LocalPlayer;


void DrawHealthBarScientist(BasePlayer* player, float health) {
	Vector3 head = (player->GetBoneByID(BoneList::head) + Vector3(0, 0.2, 0));
	Vector3 feet = (player->GetBoneByID(BoneList::l_foot) + player->GetBoneByID(BoneList::r_foot)) / 2.f;
	Vector2 tempFeet, tempHead;
	if (LocalPlayer.WorldToScreen(head, tempHead) && LocalPlayer.WorldToScreen(feet, tempFeet)) {
		float height = (tempHead.y - tempFeet.y);
		float width = height / 4.0f;
		float Entity_x = tempFeet.x - width;
		float Entity_y = tempFeet.y;
		float flBoxes = std::ceil(health / 15.f);
		float flX = Entity_x + 4; float flY = Entity_y;
		float flHeight = height / 10.f;
		float flMultiplier = 12 / 360.f; flMultiplier *= flBoxes - 1;
		int G = (255 * health / 150);
		int R = 255 - G;
		RGBA healthcol = { R, G, 0, 255 };
		RGBA col = { 80,80,80,160 };
		DrawFilledRect(flX + 1, flY, 2, flHeight * flBoxes + 1, &healthcol);
	}
}

void DrawHealthBar(BasePlayer* player, float health) {
	Vector3 head = (player->GetBoneByID(BoneList::head) + Vector3(0, 0.2, 0));
	Vector3 feet = (player->GetBoneByID(BoneList::l_foot) + player->GetBoneByID(BoneList::r_foot)) / 2.f;
	Vector2 tempFeet, tempHead;
	if (LocalPlayer.WorldToScreen(head, tempHead) && LocalPlayer.WorldToScreen(feet, tempFeet)) {
		float height = (tempHead.y - tempFeet.y);
		float width = height / 6.0f;
		float Entity_x = tempFeet.x - width;
		float Entity_y = tempFeet.y;
		float flBoxes = std::ceil(health / 10.f);
		float flX = Entity_x + 6; float flY = Entity_y;
		float flHeight = height / 10.f;
		float flMultiplier = 12 / 360.f; flMultiplier *= flBoxes - 1;
		int G = (255 * health / 100);
		int R = 255 - G;
		RGBA healthcol = { R, G, 0, 255 };

		DrawFilledRect(flX, flY, 2, flHeight * 10 + 2, &Col.black);
		DrawFilledRect(flX + 2, flY, 2, flHeight * 10 + 2, &Col.black);

		DrawFilledRect(flX + 1, flY, 2, flHeight * flBoxes + 1, &healthcol);
	}
}
static D3DXVECTOR2 calcmyangles(D3DXVECTOR3* LocalPos, D3DXVECTOR3* EnemyPos) {
	D3DXVECTOR2 toWrite;
	D3DXVECTOR3 relative;
	D3DXVec3Subtract(&relative, LocalPos, EnemyPos);
	float magnitude = D3DXVec3Length(&relative);
	double pitch = asin(relative[1] / magnitude);
	double yaw = -atan2(relative[0], -relative[2]);

	yaw = D3DXToDegree(yaw);
	pitch = D3DXToDegree(pitch);

	toWrite.x = pitch;
	toWrite.y = yaw;
	return toWrite;
}

static const char* snaplinee[] = { "Middle Down", "Crosshair", "Middle Top" };
static int selectedsnapline = 0;


double ToRad(double degree)
{
	double pi = 3.14159265359;
	return (degree * (pi / 180));
}
Vector4 ToQuat(Vector3 Euler) {

	double heading = ToRad(Euler.x);
	double attitude = ToRad(Euler.y);
	double bank = ToRad(Euler.z);

	double c1 = cos(heading / 2);
	double s1 = sin(heading / 2);
	double c2 = cos(attitude / 2);
	double s2 = sin(attitude / 2);
	double c3 = cos(bank / 2);
	double s3 = sin(bank / 2);
	double c1c2 = c1 * c2;
	double s1s2 = s1 * s2;
	Vector4 Quat;
	Quat.w = c1c2 * c3 - s1s2 * s3;
	Quat.x = c1c2 * s3 + s1s2 * c3;
	Quat.y = s1 * c2 * c3 + c1 * s2 * s3;
	Quat.z = c1 * s2 * c3 - s1 * c2 * s3;
	Vector4 Quat2;
	Quat2 = { Quat.y, Quat.z, (Quat.x * -1), Quat.w };
	return Quat2;
}


float Calc2D_Distt(const Vector2& Src, const Vector2& Dst) {
	return sqrt(powf(Src.x - Dst.x, 2) + powf(Src.y - Dst.y, 2));
}

float AimFov(BasePlayer* Entity)
{
	Vector2 ScreenPos;
	if (!LocalPlayer.WorldToScreen(Entity->GetBoneByID(BoneList::head), ScreenPos)) return 1000.f;
	return Calc2D_Distt(Vector2(GetWindowSize().x / 2, GetWindowSize().y / 2), ScreenPos);
}

bool woundedignore = false;
bool visiblecheck = false;
bool sleeperignore = false;
bool teamignoree = false;

bool autoshot = false;
bool drawaimbot = false;
bool aimbot = false;
bool silent = false;
bool silentline = false;
bool psilent = false;
bool ssilent = false;
float aimfovv = 60;
float aimsmooth = 1;
bool Predictionn = false;

static const char* Type[] = { "Head", "Body", "Leg" };
static int selectedType = 0;

int Typeee = BoneList::head;

static int ScreenWidths = GetSystemMetrics(SM_CXSCREEN);
static int ScreenHeighth = GetSystemMetrics(SM_CYSCREEN);



float ProjectileSpeed_Normal(float dist) {
	std::string held_item = LocalPlayer.BasePlayer->GetActiveWeapon()->GetItemNameS();
	if (held_item == "No Item")                 return 300.0f;
	if (held_item == "rifle.ak")                return 374.9f * 1.0f;
	if (held_item == "rifle.lr300")             return 374.9f * 1.0f;
	if (held_item == "rifle.bolt")              return 656.0f * 1.0f;
	if (held_item == "rifle.l96")               return 1125.0f * 1.0f;
	if (held_item == "rifle.m39")               return 374.9f * 1.0f;
	if (held_item == "rifle.semiauto")          return 374.9f * 1.0f;
	if (held_item == "lmg.m249")                return 487.4f * 1.0f;
	if (held_item == "hmlmg")                   return 487.4f * 1.0f;
	if (held_item == "lmg.hmlmg")               return 487.4f * 1.0f;
	if (held_item == "smg.thompson")            return 300.0f * 1.0f;
	if (held_item == "smg.custom")              return 240.0f * 1.0f;
	if (held_item == "smg.mp5")                 return 240.0f * 1.0f;
	if (held_item == "smg.2")                   return 240.0f * 1.0f;
	if (held_item == "pistol.python")           return 300.0f * 1.0f;
	if (held_item == "pistol.semi")             return 300.0f * 1.0f;
	if (held_item == "pistol.revolver")         return 300.0f * 1.0f;
	if (held_item == "pistol.m92")              return 300.0f * 1.0f;
	if (held_item == "pistol.eoka")             return 50.0f * 1.55f;
	if (held_item == "pistol.nailgun")          return 50.0f * 1.19f;
	if (held_item == "crossbow") {
		if (dist <= 83.f)
		{
			return 90.f;
		}
		else
			if (dist <= 123.f)
			{
				return 88.f;
			}
			else
				if (dist <= 223.f)
				{
					return 86.f;
				}
				else
					if (dist <= 254.f)
					{
						return 85.5f;
					}
					else
						if (dist <= 285.f)
						{
							return 85.f;
						}
						else
							if (dist <= 500.f)
							{
								return 84.7f;
							}
	}
	if (held_item == "bow.compound")            return 100.0f * 1.14f;
	if (held_item == "bow.hunting") {
		if (dist <= 41.f)
		{
			return 60.f;
		}
		else
			if (dist <= 82.f)
			{
				return  58.f;
			}
			else
				if (dist <= 102.f)
				{
					return  57.5f;
				}
				else
					if (dist <= 112.f)
					{
						return  57.3f;
					}
					else
						if (dist <= 127.f)
						{
							return  57.f;
						}
						else
							if (dist <= 146.f)
							{
								return  56.5f;
							}
							else
								if (dist <= 153.f)
								{
									return  56.3f;
								}
								else
									if (dist <= 163.f)
									{
										return  56.f;
									}
									else
										if (dist <= 172.f)
										{
											return  55.7f;
										}
										else
											if (dist <= 178.f)
											{
												return  55.5f;
											}
											else
												if (dist <= 184.f)
												{
													return  55.3f;
												}
												else
													if (dist <= 189.f)
													{
														return  55.1f;
													}
													else
														if (dist <= 196.f)
														{
															return  54.9f;
														}
														else
															if (dist <= 201.f)
															{
																return  54.7f;
															}
															else
																if (dist <= 206.f)
																{
																	return  54.5f;
																}
																else
																	if (dist <= 210.f)
																	{
																		return  54.3f;
																	}
																	else
																		if (dist <= 215.f)
																		{
																			return 54.1f;
																		}
																		else
																			if (dist <= 220.f)
																			{
																				return  53.9f;
																			}
																			else
																				if (dist <= 225.1f)
																				{
																					return 53.7f;
																				}
																				else
																					if (dist <= 230.1f)
																					{
																						return  53.5f;
																					}
																					else
																						if (dist <= 233.1f)
																						{
																							return  53.3f;
																						}
																						else
																							if (dist <= 237.1f)
																							{
																								return  53.1f;
																							}
																							else
																								if (dist <= 241.1f)
																								{
																									return  52.9f;
																								}
																								else
																									if (dist <= 244.1f)
																									{
																										return  52.7f;
																									}
																									else
																										if (dist <= 248.1f)
																										{
																											return  52.5f;
																										}
																										else
																											if (dist <= 252.1f)
																											{
																												return  52.3f;
																											}
																											else
																												if (dist <= 255.1f)
																												{
																													return  52.1f;
																												}
																												else
																													if (dist <= 500.f)
																													{
																														return 50.f;
																													}
	}
	if (held_item == "shotgun.pump")            return 80.0f * 1.0f;
	if (held_item == "shotgun.spas12")          return 80.0f * 1.0f;
	if (held_item == "shotgun.waterpipe")       return 80.0f * 1.0f;
	if (held_item == "shotgun.doublebarrel")    return 80.0f * 1.0f;
	return 300.0f;
}

Vector3 Prediction(const Vector3& LP_Pos, BasePlayer* Player, BoneList Bone, Vector3 BonePos) {
	float Dist = Calc3D_Dist(LP_Pos, BonePos);
	if (Dist > 0.001f) {
		float BulletTime = Dist / ProjectileSpeed_Normal(Dist);
		Vector3 vel = Player->GetVelocity();
		Vector3 PredictVel;
		PredictVel.x = vel.x * BulletTime * 0.75f;
		PredictVel.y = vel.y * BulletTime * 0.75f;
		PredictVel.z = vel.z * BulletTime * 0.75f;

		BonePos.x += PredictVel.x;
		BonePos.y += PredictVel.y;
		BonePos.z += PredictVel.z;
		BonePos.y += (4.905f * BulletTime * BulletTime);
	} return BonePos;
}

Vector3 LocalPlayerHead;
Vector3 pLocalPlayerHead;
Vector3 sLocalPlayerHead;

Vector3 TargetBonePos;
Vector3 pTargetBonePos;
Vector3 sTargetBonePos;
static void DrawFilledRectImGui(int x, int y, int w, int h, ImVec4 color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(color), 0, 0);
}
void aimbott(BasePlayer* Player)
{

	if (teamignoree)
	{
		uintptr_t EntitySID = Player->GetSteamID();
		bool Skip = false;
		for (int i = 0; i < LocalPlayer.BasePlayer->GetTeamSize(); i++) {
			uintptr_t CacheSID = LocalPlayer.BasePlayer->IsTeamMate(i);
			if (EntitySID == CacheSID) {
				Skip = true;
			}
		}

		if (Skip) {
			return;
		}
	}
	if (Player->IsDead())
	{
		return;
	}
	if (sleeperignore)
	{
		if (Player->IsSleeping())
		{
			return;
		}
	}
	if (woundedignore)
	{
		if (Player->IsWounded())
		{
			return;
		}
	}

	if (visiblecheck) {
		if (!Player->IsVisible())
		{
			return;
		}
	}

	//Vector2 TargetAngles;
	//LocalPlayer.WorldToScreen(Player->Position2(), TargetAngles);

	//if (GetAsyncKeyState(aimkey))
	//{
	//	if (AimFov(Player) < aimfovv)
	//	{
	//		//UINT64 Input = driver.read<UINT64>(Local_Player + oPlayerInput);
	//		//driver.write<Vector2>(Input + 0x3C, Vector2((TargetAngles.x - 960) / aimsmooth, (TargetAngles.y - 540) / aimsmooth)); //     private Vector3 bodyAngles;
	//		mouse_event(MOUSEEVENTF_MOVE, (TargetAngles.x - ScreenWidths / 2) / aimsmooth, (TargetAngles.y - ScreenHeighth / 2) / aimsmooth, 0, 0);
	//		if (autoshot)
	//		{
	//			Sleep(1);
	//			mouse_event(MOUSEEVENTF_LEFTDOWN, ScreenWidths / 2, ScreenHeighth / 2, 0, 0);
	//			mouse_event(MOUSEEVENTF_LEFTUP, ScreenWidths / 2, ScreenHeighth / 2, 0, 0);
	//		}
	//	}
	//}

	LocalPlayerHead = LocalPlayer.BasePlayer->Position2();
	TargetBonePos = Player->Position2();

	if (TargetBonePos.x == 0 || TargetBonePos.y == 0) {
		return;
	}
	if (Predictionn) {
		TargetBonePos = Prediction(LocalPlayerHead, Player, BoneList(head), TargetBonePos);
	}

	Vector3 TargetAngles = CalcAngle(LocalPlayerHead, TargetBonePos);
	Vector2 Angles; Angles.x = TargetAngles.x, Angles.y = TargetAngles.y;
	Normalize(Angles.y, Angles.x);
	if (isnan(Angles.x) || isnan(Angles.y))
	{
		return;
	}

	Vector2 BoneHeadd;
	LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::head), BoneHeadd);


	if (silent)
	{
		auto eyes = driver.read<uintptr_t>((uintptr_t)LocalPlayer.BasePlayer + oPlayerEyes);
		Vector4 QuatAngles = ToQuat({ Angles.x, Angles.y, 0.0f });
		if (GetAsyncKeyState(aimkey)) {
			driver.write<Vector4>(eyes + 0x44, QuatAngles);
		}
	}

	if (aimbot && GetAsyncKeyState(aimkey)) {
		LocalPlayer.BasePlayer->SetVA(Angles);
	}
}
static Vector3 pRadar;
void skeletonesp(int X, int Y, int W, int H, int thickness) {
	auto RGB = ImGui::GetColorU32(skeletoncolor);
	ImDrawList* Renderer = ImGui::GetOverlayDrawList();
	Renderer->AddLine(ImVec2(X, Y), ImVec2(W, H), RGB, thickness);

}
void DrawRadar(Vector3 EntityPos)
{
	auto radar_posX = pRadar.x + 135;
	auto radar_posY = pRadar.y + 135;
	uintptr_t Input = driver.read<uintptr_t>(Local_Player + oPlayerEyes);
	Vector3 yaw = driver.read<Vector3>(Input + 0x38);
	Vector3 LocalPos = LocalPlayer.BasePlayer->GetBoneByID(head);
	auto Radar2D = WorldRadar(LocalPos, EntityPos, yaw.y, radar_posX, radar_posY, 135.f);
	DrawCircleFilled2(Radar2D.x, Radar2D.y, 2, &Col.red);
}

void ESP_Player(BasePlayer* Player)
{
	Vector3 tempFeetR, tempFeetL;
	Vector3 ro = Player->GetBoneByID(r_foot);
	if (ro.x == 0 && ro.y == 0 && ro.z == 0) return;
	if (LocalPlayer.WorldToScreen(ro, tempFeetR) && LocalPlayer.WorldToScreen(Player->GetBoneByID(l_foot), tempFeetL))
		Vector2 tempFeetR, tempFeetL;
	if (LocalPlayer.WorldToScreen(Player->GetBoneByID(r_foot), tempFeetR) && LocalPlayer.WorldToScreen(Player->GetBoneByID(l_foot), tempFeetL))
	{
		Vector2 tempHead;
		if (LocalPlayer.WorldToScreen(Player->GetBoneByID(jaw) + Vector3(0.f, 0.16f, 0.f), tempHead))
		{
			Vector2 PlayerHeadScreen;    LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::head), PlayerHeadScreen);
			Vector3 tempFeet = (tempFeetR + tempFeetL) / 2.f;
			float Entity_h = tempHead.y - tempFeet.y;
			float w = Entity_h / 4;
			float Entity_x = tempFeet.x - w;
			float Entity_y = tempFeet.y;
			float Entity_w = Entity_h / 2;
			wchar_t res[90];

			int distation = (int)Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), ro);



			//pRadar.x = (GetWindowSize().x / GetWindowSize().x);
			//pRadar.y = GetWindowSize().x / 2 - GetWindowSize().y / 2 - 410;
			//DrawRect(pRadar.x, pRadar.y, 270, 270, &Col.black, 1);
			//DrawBorder(pRadar.x, pRadar.y, 270, 270, 1, &Col.SilverWhite);
			//auto radar_posX = pRadar.x + 135;
			//auto radar_posY = pRadar.y + 135;
			//DrawLine3(radar_posX, radar_posY, radar_posX, radar_posY + 135, &Col.SilverWhite, 1);
			//DrawLine3(radar_posX, radar_posY, radar_posX, radar_posY - 135, &Col.SilverWhite, 1);
			//DrawLine3(radar_posX, radar_posY, radar_posX + 135, radar_posY, &Col.SilverWhite, 1);
			//DrawLine3(radar_posX, radar_posY, radar_posX - 135, radar_posY, &Col.SilverWhite, 1);
			//DrawCircleFilled2(radar_posX - 0.5f, radar_posY - 0.5f, 3, &Col.yellow);
			//Vector3 pos = Player->GetBoneByID(head);
			//DrawRadar(pos);



			if (!Player->IsWounded())
			{
				if (teamignore)
				{
					uintptr_t EntitySID = Player->GetSteamID();
					bool Skip = false;
					for (int i = 0; i < LocalPlayer.BasePlayer->GetTeamSize(); i++) {
						uintptr_t CacheSID = LocalPlayer.BasePlayer->IsTeamMate(i);
						if (EntitySID == CacheSID) {
							Skip = true;
						}
					}

					if (Skip) {
						return;
					}
				}
				if (Player->IsDead())
				{
					//Drawalien(1920 / 2, 1080 / 2, 15, true, false, "DEATH");
					return;
				}
				if (sleeper)
				{
					if (Player->IsSleeping())
					{
						return;
					}
				}
				if (box | box2)
				{
					if (paintinside)
					{
						DrawFilledRectImGui(tempFeet.x - (Entity_w / 2), tempFeet.y, Entity_w, Entity_h, paintinsidecolor);
						//DrawFilledRect((Entity_x - Entity_h / Entity_h), Entity_y, Entity_w, Entity_h, &Col.black_);
					}
				}
				if (box)
				{
					//DrawCorneredBox(tempFeet.x - (Entity_w / 2) - 1, tempFeet.y - 1, Entity_w + 2, Entity_h + 2, ImVec4(0.f, 0.f, 0.f, 255.f), 1.0f);
					DrawCorneredBox(tempFeet.x - (Entity_w / 2), tempFeet.y, Entity_w, Entity_h, boxcolor, 1.0f);
					//DrawCorneredBox(tempFeet.x - (Entity_w / 2) + 1, tempFeet.y + 1, Entity_w - 2, Entity_h - 2, ImVec4(0.f, 0.f, 0.f, 255.f), 1.0f);
				}
				if (espvisiblecheck)
				{
					if (!Player->IsVisible())
					{
						r = 255;
						g = 0;
						b = 0;
					}
					else
					{
						r = 255;
						g = 255;
						b = 255;
					}
				}
				else
				{
					r = 255;
					g = 255;
					b = 255;
				}

				if (box3)
				{
					Vector3 lFoot = Player->GetBoneByID(l_foot);
					Vector3 rFoot = Player->GetBoneByID(r_foot);

					Vector3 vBaseBone = (lFoot + rFoot) / 2;
					Vector3 bottom1;
					LocalPlayer.WorldToScreen(Vector3(vBaseBone.x + 0.4, vBaseBone.y, vBaseBone.z - 0.4), bottom1);
					Vector3 bottom2;
					LocalPlayer.WorldToScreen(Vector3(vBaseBone.x - 0.4, vBaseBone.y, vBaseBone.z - 0.4), bottom2);
					Vector3 bottom3;
					LocalPlayer.WorldToScreen(Vector3(vBaseBone.x - 0.4, Player->GetBoneByID(BoneList::head).y + 0.25, vBaseBone.z - 0.4), bottom3);
					Vector3 bottom4;
					LocalPlayer.WorldToScreen(Vector3(vBaseBone.x + 0.4, Player->GetBoneByID(BoneList::head).y + 0.25, vBaseBone.z - 0.4), bottom4);

					Vector3 vHeadBone = (lFoot + rFoot) / 2;
					Vector3 top1;
					LocalPlayer.WorldToScreen(Vector3(vHeadBone.x + 0.4, vHeadBone.y, vHeadBone.z + 0.4), top1);
					Vector3 top2;
					LocalPlayer.WorldToScreen(Vector3(vHeadBone.x - 0.4, vHeadBone.y, vHeadBone.z + 0.4), top2);
					Vector3 top3;
					LocalPlayer.WorldToScreen(Vector3(vHeadBone.x - 0.4, Player->GetBoneByID(BoneList::head).y + 0.25, vHeadBone.z + 0.4), top3);
					Vector3 top4;
					LocalPlayer.WorldToScreen(Vector3(vHeadBone.x + 0.4, Player->GetBoneByID(BoneList::head).y + 0.25, vHeadBone.z + 0.4), top4);

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
				}
				//DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y / 2), ImVec2(tempFeet.x, tempFeet.y), ImGui::ColorConvertFloat4ToU32(ImColor(r, g, b)), 1.f); // ASAGIDAN
				if (box2)
				{
					//Draw2DBox(Entity_x, Entity_y, Entity_w, Entity_h, ImColor(255,255,255));
					//DrawRectImGui(tempFeet.x - (Entity_w / 2) - 1, tempFeet.y - 1, Entity_w + 2, Entity_h + 2, ImVec4(0.f, 0.f, 0.f, 255.f), 1.0f);
					DrawRectImGui(tempFeet.x - (Entity_w / 2), tempFeet.y, Entity_w, Entity_h, box2color, 1.f);
					//DrawRectImGui(tempFeet.x - (Entity_w / 2) + 1, tempFeet.y + 1, Entity_w - 2, Entity_h - 2, ImVec4(0.f, 0.f, 0.f, 255.f), 1.0f);
					//DrawBox(tempFeet.x - (Entity_w / 2), tempFeet.y, Entity_w, Entity_h, 0.6f);
				}
				if (skeleton)
				{
					if (distation < 120)
					{
						Vector2 BoneHead;    LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::head), BoneHead);
						Vector2 BoneNeck;    LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::neck), BoneNeck);
						Vector2 BoneStomach; LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::spine1_scale), BoneStomach);
						Vector2 BoneLArm3;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::l_hand), BoneLArm3);
						Vector2 BoneLArm2;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::l_forearm), BoneLArm2);
						Vector2 BoneLArm1;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::l_upperarm), BoneLArm1);
						Vector2 BoneRArm3;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::r_hand), BoneRArm3);
						Vector2 BoneRArm2;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::r_forearm), BoneRArm2);
						Vector2 BoneRArm1;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::r_upperarm), BoneRArm1);
						Vector2 BoneLLeg3;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::r_foot), BoneLLeg3);
						Vector2 BoneLLeg2;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::r_knee), BoneLLeg2);
						Vector2 BoneLLeg1;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::r_hip), BoneLLeg1);
						Vector2 BoneRLeg3;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::l_foot), BoneRLeg3);
						Vector2 BoneRLeg2;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::l_knee), BoneRLeg2);
						Vector2 BoneRLeg1;   LocalPlayer.WorldToScreen(Player->GetBoneByID(BoneList::l_hip), BoneRLeg1);
						skeletonesp(BoneHead.x, BoneHead.y, BoneNeck.x, BoneNeck.y, 1.5f);
						skeletonesp(BoneNeck.x, BoneNeck.y, BoneLArm1.x, BoneLArm1.y, 1.5f);
						skeletonesp(BoneLArm1.x, BoneLArm1.y, BoneLArm2.x, BoneLArm2.y, 1.5f);
						skeletonesp(BoneLArm2.x, BoneLArm2.y, BoneLArm3.x, BoneLArm3.y, 1.5f);
						skeletonesp(BoneNeck.x, BoneNeck.y, BoneRArm1.x, BoneRArm1.y, 1.5f);
						skeletonesp(BoneRArm1.x, BoneRArm1.y, BoneRArm2.x, BoneRArm2.y, 1.5f);
						skeletonesp(BoneRArm2.x, BoneRArm2.y, BoneRArm3.x, BoneRArm3.y, 1.5f);
						skeletonesp(BoneNeck.x, BoneNeck.y, BoneStomach.x, BoneStomach.y, 1.5f);
						skeletonesp(BoneStomach.x, BoneStomach.y, BoneLLeg1.x, BoneLLeg1.y, 1.5f);
						skeletonesp(BoneLLeg1.x, BoneLLeg1.y, BoneLLeg2.x, BoneLLeg2.y, 1.5f);
						skeletonesp(BoneLLeg2.x, BoneLLeg2.y, BoneLLeg3.x, BoneLLeg3.y, 1.5f);
						skeletonesp(BoneStomach.x, BoneStomach.y, BoneRLeg1.x, BoneRLeg1.y, 1.5f);
						skeletonesp(BoneRLeg1.x, BoneRLeg1.y, BoneRLeg2.x, BoneRLeg2.y, 1.5f);
						skeletonesp(BoneRLeg2.x, BoneRLeg2.y, BoneRLeg3.x, BoneRLeg3.y, 1.5f);
					}
				}
				if (snapline)
				{
					if (selectedsnapline == 0)
					{
						//DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y), ImVec2(tempFeet.x, tempFeet.y - 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0)), 1.f); // ASAGIDAN
						DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y), ImVec2(tempFeet.x, tempFeet.y), ImGui::ColorConvertFloat4ToU32(snaplinecolor), 1.f); // ASAGIDAN
						//DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y), ImVec2(tempFeet.x, tempFeet.y + 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0)), 1.f); // ASAGIDAN
					}
					if (selectedsnapline == 1)
					{
						//DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y / 2), ImVec2(tempFeet.x, tempFeet.y - 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0)), 1.f); // ASAGIDAN
						DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y / 2), ImVec2(tempFeet.x, tempFeet.y), ImGui::ColorConvertFloat4ToU32(snaplinecolor), 1.f); // ASAGIDAN
						//DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y / 2), ImVec2(tempFeet.x, tempFeet.y + 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0)), 1.f); // ASAGIDAN
					}
					if (selectedsnapline == 2)
					{
						//DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y / GetWindowSize().y), ImVec2(tempFeet.x, tempFeet.y - 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0)), 1.f); // ASAGIDAN
						DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y / GetWindowSize().y), ImVec2(PlayerHeadScreen.x, PlayerHeadScreen.y), ImGui::ColorConvertFloat4ToU32(snaplinecolor), 1.f); // ASAGIDAN
						//DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y / GetWindowSize().y), ImVec2(tempFeet.x, tempFeet.y + 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0)), 1.f); // ASAGIDAN
					}
				}
				if (name)
				{
					std::string name = readstring(Player->GetName());
					//ImVec2 value_text_size = ImGui::CalcTextSize(name.c_str(), NULL, true);
					//DrawShadowTextImGui(tempHead.x - (value_text_size.x / 2), PlayerHeadScreen.y, &Col.white, name.c_str());
					DrawLString(12, tempHead.x, (tempHead.y), namecolor, true, true, name.c_str());
				}
				//auto s = ImVec2{}, gs = ImVec2{ 1920, 1080 };
				//s = ImVec2(ImGui::GetWindowSize().x - ImGui::GetStyle().WindowPadding.x * 2, ImGui::GetWindowSize().y - ImGui::GetStyle().WindowPadding.y * 2); ImVec2(tempFeet.x / 2, tempFeet.y / 2) = ImVec2(ImGui::GetWindowPos().x + ImGui::GetStyle().WindowPadding.x, ImGui::GetWindowPos().y + ImGui::GetStyle().WindowPadding.y);
				////draw->AddRectFilled(p, ImVec2(p.x + s.x, p.y + s.y), ImColor(15, 17, 19), 5);
				//ImGui::GetOverlayDrawList()->AddImage(Logo, ImVec2(tempFeet.x, tempFeet.y), ImVec2(tempFeet.x + s.x, tempFeet.y + s.y), ImVec2(1, 1), ImVec2(0, 0), ImColor(255, 255, 255));
				if (handweapon)
				{
					if (showdistancee)
					{
						DrawLString(12, tempFeet.x, (tempFeet.y + 25), handweaponcolor, true, true, Player->GetActiveWeaponText().c_str());
					}
					else
					{
						DrawLString(12, tempFeet.x, (tempFeet.y + 15), handweaponcolor, true, true, Player->GetActiveWeaponText().c_str());
					}
				}
				if (showdistancee)
				{
					if (box || box2 || box3)
					{
						char text[0x100];
						sprintf(text, skCrypt("[%d m]"), distation);
						DrawLString(12, tempFeet.x, tempFeet.y + 15, showdistanceecolor, true, true, text);
					}
				}

				if (healthbar2)
				{
					float entHp = Player->Health();
					if (entHp > 101) entHp = 100;
					if (distation < 28)
					{
						if (distation < 10)
						{
							if (distation < 5)
							{
								float HealthHeightCalc = ((float)entHp / 100) * ((float)Entity_w + 320);
								DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 160, tempHead.y - 22, Entity_w + 320, 4, ImVec4(COLOUR(30.0f), COLOUR(30.0f), COLOUR(30.0f), COLOUR(220.0f)));
								DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 160, tempHead.y - 22, HealthHeightCalc, 4, ImVec4(COLOUR(80.0f), COLOUR(220.0f), COLOUR(100.0f), COLOUR(255.0f)));
							}
							else
							{
								float HealthHeightCalc = ((float)entHp / 100) * ((float)Entity_w + 160);
								DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 80, tempHead.y - 22, Entity_w + 160, 4, ImVec4(COLOUR(30.0f), COLOUR(30.0f), COLOUR(30.0f), COLOUR(220.0f)));
								DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 80, tempHead.y - 22, HealthHeightCalc, 4, ImVec4(COLOUR(80.0f), COLOUR(220.0f), COLOUR(100.0f), COLOUR(255.0f)));
							}
						}
						else
						{
							float HealthHeightCalc = ((float)entHp / 100) * ((float)Entity_w + 80);
							DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 40, tempHead.y - 20, Entity_w + 80, 4, ImVec4(COLOUR(30.0f), COLOUR(30.0f), COLOUR(30.0f), COLOUR(220.0f)));
							DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 40, tempHead.y - 20, HealthHeightCalc, 4, ImVec4(COLOUR(80.0f), COLOUR(220.0f), COLOUR(100.0f), COLOUR(255.0f)));
						}
					}
					else
					{
						float HealthHeightCalc = ((float)entHp / 100) * ((float)Entity_w + 40);
						DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 20, tempHead.y - 15, Entity_w + 40, 4, ImVec4(COLOUR(30.0f), COLOUR(30.0f), COLOUR(30.0f), COLOUR(220.0f)));
						DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 20, tempHead.y - 15, HealthHeightCalc, 4, ImVec4(COLOUR(80.0f), COLOUR(220.0f), COLOUR(100.0f), COLOUR(255.0f)));
					}
				}
				if (healthbar)
				{
					float entHp = Player->Health();
					if (entHp > 101) entHp = 100;
					float HealthHeightCalc = ((float)entHp / 100) * (float)Entity_h;

					DrawFilledRectImGui(tempFeet.x - (Entity_w / 2), tempFeet.y, 2, Entity_h, ImVec4(COLOUR(30.0f), COLOUR(30.0f), COLOUR(30.0f), COLOUR(220.0f)));
					DrawFilledRectImGui(tempFeet.x - (Entity_w / 2), tempFeet.y, 2, HealthHeightCalc, ImVec4(COLOUR(80.0f), COLOUR(220.0f), COLOUR(100.0f), COLOUR(255.0f)));
				}

				//DrawHealthBar(Player, Player->Health());
			}
			else
			{
				if (WoundedAlert)
				{
					if (box3)
					{
						Vector3 lFoot = Player->GetBoneByID(spine1_scale);
						Vector3 rFoot = Player->GetBoneByID(spine1_scale);

						Vector3 vBaseBone = (lFoot + rFoot) / 2;
						Vector3 bottom1;
						LocalPlayer.WorldToScreen(Vector3(vBaseBone.x + 0.5, vBaseBone.y, vBaseBone.z - 0.5), bottom1);
						Vector3 bottom2;
						LocalPlayer.WorldToScreen(Vector3(vBaseBone.x - 0.5, vBaseBone.y, vBaseBone.z - 0.5), bottom2);
						Vector3 bottom3;
						LocalPlayer.WorldToScreen(Vector3(vBaseBone.x - 0.5, vBaseBone.y - 1.0, vBaseBone.z - 0.5), bottom3);
						Vector3 bottom4;
						LocalPlayer.WorldToScreen(Vector3(vBaseBone.x + 0.5, vBaseBone.y - 1.0, vBaseBone.z - 0.5), bottom4);

						Vector3 vHeadBone = (lFoot + rFoot) / 2;
						Vector3 top1;
						LocalPlayer.WorldToScreen(Vector3(vHeadBone.x + 0.5, vHeadBone.y, vHeadBone.z + 0.5), top1);
						Vector3 top2;
						LocalPlayer.WorldToScreen(Vector3(vHeadBone.x - 0.5, vHeadBone.y, vHeadBone.z + 0.5), top2);
						Vector3 top3;
						LocalPlayer.WorldToScreen(Vector3(vHeadBone.x - 0.5, vHeadBone.y - 1.0, vHeadBone.z + 0.5), top3);
						Vector3 top4;
						LocalPlayer.WorldToScreen(Vector3(vHeadBone.x + 0.5, vHeadBone.y - 1.0, vHeadBone.z + 0.5), top4);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(box3color), 1.f);
					}
					DrawLString(12, tempFeet.x, (tempFeet.y + 25), WoundedAlertColor, true, true, skCrypt("Wounded"));
					if (name)
					{
						std::string name = readstring(Player->GetName());
						DrawLString(12, tempFeet.x, (tempFeet.y + 15), namecolor, true, true, name.c_str());
					}
					if (showdistancee)
					{
						char text[0x100];
						sprintf(text, skCrypt("[%d m]"), distation);
						DrawLString(12, tempFeet.x, tempFeet.y, showdistanceecolor, true, true, text);
					}
				}
			}
		}

	}
}

static int xekran2 = 220, yekran2 = 284;
void playerinfo(BasePlayer* Player)
{
	if (sleeper)
	{
		if (Player->IsSleeping())
		{
			return;
		}
	}
	if (teamignore)
	{
		uintptr_t EntitySID = Player->GetSteamID();
		bool Skip = false;
		for (int i = 0; i < LocalPlayer.BasePlayer->GetTeamSize(); i++) {
			uintptr_t CacheSID = LocalPlayer.BasePlayer->IsTeamMate(i);
			if (EntitySID == CacheSID) {
				Skip = true;
			}
		}

		if (Skip) {
			return;
		}
	}
	if (Player->IsDead())
	{
		//Drawalien(1920 / 2, 1080 / 2, 15, true, false, "DEATH");
		return;
	}


	std::string weapon = Player->GetBeltItems(Player->GetItemsList(), 1);
	std::string weapon2 = Player->GetBeltItems(Player->GetItemsList(), 2);
	std::string weapon3 = Player->GetBeltItems(Player->GetItemsList(), 3);
	std::string weapon4 = Player->GetBeltItems(Player->GetItemsList(), 4);
	std::string weapon5 = Player->GetBeltItems(Player->GetItemsList(), 5);
	std::string weapon6 = Player->GetBeltItems(Player->GetItemsList(), 6);

	std::string armor = Player->GetClothingItems(Player->GetClothingItemsList(), 1);
	std::string armor2 = Player->GetClothingItems(Player->GetClothingItemsList(), 2);
	std::string armor3 = Player->GetClothingItems(Player->GetClothingItemsList(), 3);
	std::string armor4 = Player->GetClothingItems(Player->GetClothingItemsList(), 4);
	std::string armor5 = Player->GetClothingItems(Player->GetClothingItemsList(), 5);
	std::string armor6 = Player->GetClothingItems(Player->GetClothingItemsList(), 6);
	std::string armor7 = Player->GetClothingItems(Player->GetClothingItemsList(), 7);

	std::string name = readstring(Player->GetName());
	std::string healthhh(std::to_string((int)Player->Health()));
	int Ger = (255 * Player->Health() / 100);
	int Rer = 255 - Ger;
	ImGui::SetNextWindowSize(ImVec2(xekran2, yekran2));
	ImGui::Begin(skCrypt("PLAYERINFO"), NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	//ImGui::Text(skCrypt("")); ImGui::SameLine();
	ImGui::TextDisabled(skCrypt("Name:   "));
	ImGui::SameLine();
	ImGui::Text(name.c_str());
	//ImGui::Text(skCrypt("")); ImGui::SameLine();
	ImGui::TextDisabled(skCrypt("Health:  "));
	ImGui::SameLine();
	ImGui::TextColored(ImColor(Rer, Ger, 0), (healthhh.c_str()));



	ImGui::Separator();
	ImGui::TextDisabled(skCrypt("Slot 1:  ")); ImGui::SameLine();
	ImGui::Text(weapon.c_str());
	ImGui::TextDisabled(skCrypt("Slot 2:  ")); ImGui::SameLine();
	ImGui::Text(weapon2.c_str());
	ImGui::TextDisabled(skCrypt("Slot 3:  ")); ImGui::SameLine();
	ImGui::Text(weapon3.c_str());
	ImGui::TextDisabled(skCrypt("Slot 4:  ")); ImGui::SameLine();
	ImGui::Text(weapon4.c_str());
	ImGui::TextDisabled(skCrypt("Slot 5:  ")); ImGui::SameLine();
	ImGui::Text(weapon5.c_str());
	ImGui::TextDisabled(skCrypt("Slot 6:  ")); ImGui::SameLine();
	ImGui::Text(weapon6.c_str());
	ImGui::Separator();
	ImGui::TextDisabled(skCrypt("Cloth 1: ")); ImGui::SameLine();
	ImGui::Text(armor.c_str());
	ImGui::TextDisabled(skCrypt("Cloth 2: ")); ImGui::SameLine();
	ImGui::Text(armor2.c_str());
	ImGui::TextDisabled(skCrypt("Cloth 3: ")); ImGui::SameLine();
	ImGui::Text(armor3.c_str());
	ImGui::TextDisabled(skCrypt("Cloth 4: ")); ImGui::SameLine();
	ImGui::Text(armor4.c_str());
	ImGui::TextDisabled(skCrypt("Cloth 5: ")); ImGui::SameLine();
	ImGui::Text(armor5.c_str());
	ImGui::TextDisabled(skCrypt("Cloth 6: ")); ImGui::SameLine();
	ImGui::Text(armor6.c_str());
	ImGui::TextDisabled(skCrypt("Cloth 7: ")); ImGui::SameLine();
	ImGui::Text(armor7.c_str());

	ImGui::End();
}



void ESP_Scientist(BasePlayer* Player, int TunnelOrScientist)
{
	Vector2 tempFeetR, tempFeetL;
	Vector3 ro = Player->GetBoneByID(r_foot);
	if (ro.x == 0 && ro.y == 0 && ro.z == 0) return;
	if (LocalPlayer.WorldToScreen(ro, tempFeetR) && LocalPlayer.WorldToScreen(Player->GetBoneByID(l_foot), tempFeetL))
		Vector2 tempFeetR, tempFeetL;
	if (LocalPlayer.WorldToScreen(Player->GetBoneByID(r_foot), tempFeetR) && LocalPlayer.WorldToScreen(Player->GetBoneByID(l_foot), tempFeetL))
	{
		Vector2 tempHead;
		if (LocalPlayer.WorldToScreen(Player->GetBoneByID(jaw) + Vector3(0.f, 0.16f, 0.f), tempHead))
		{
			Vector2 tempFeet = (tempFeetR + tempFeetL) / 2.f;
			float Entity_h = tempHead.y - tempFeet.y;
			float w = Entity_h / 4;
			float Entity_x = tempFeet.x - w;
			float Entity_y = tempFeet.y;
			float Entity_w = Entity_h / 2;

			Vector3 lFoot = Player->GetBoneByID(l_foot);
			Vector3 rFoot = Player->GetBoneByID(r_foot);

			Vector3 vBaseBone = (lFoot + rFoot) / 2;
			Vector3 bottom1;
			LocalPlayer.WorldToScreen(Vector3(vBaseBone.x + 0.4, vBaseBone.y, vBaseBone.z - 0.4), bottom1);
			Vector3 bottom2;
			LocalPlayer.WorldToScreen(Vector3(vBaseBone.x - 0.4, vBaseBone.y, vBaseBone.z - 0.4), bottom2);
			Vector3 bottom3;
			LocalPlayer.WorldToScreen(Vector3(vBaseBone.x - 0.4, vBaseBone.y + 1.7, vBaseBone.z - 0.4), bottom3);
			Vector3 bottom4;
			LocalPlayer.WorldToScreen(Vector3(vBaseBone.x + 0.4, vBaseBone.y + 1.7, vBaseBone.z - 0.4), bottom4);

			Vector3 vHeadBone = (lFoot + rFoot) / 2;
			Vector3 top1;
			LocalPlayer.WorldToScreen(Vector3(vHeadBone.x + 0.4, vHeadBone.y, vHeadBone.z + 0.4), top1);
			Vector3 top2;
			LocalPlayer.WorldToScreen(Vector3(vHeadBone.x - 0.4, vHeadBone.y, vHeadBone.z + 0.4), top2);
			Vector3 top3;
			LocalPlayer.WorldToScreen(Vector3(vHeadBone.x - 0.4, vHeadBone.y + 1.7, vHeadBone.z + 0.4), top3);
			Vector3 top4;
			LocalPlayer.WorldToScreen(Vector3(vHeadBone.x + 0.4, vHeadBone.y + 1.7, vHeadBone.z + 0.4), top4);


			if (TunnelOrScientist == 1)
			{
				if (NPCNames)
					DrawLString(12, tempFeet.x, (tempFeet.y + 15), NPCNamescolor, true, true, "Tunnel Dweller");
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);

				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);

				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(tunneldwellerscolor), 1.f);
			}
			if (TunnelOrScientist == 2)
			{
				if (NPCNames)
					DrawLString(12, tempFeet.x, (tempFeet.y + 15), NPCNamescolor, true, true, "Scientist");
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);

				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);

				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(scientistnpccolor), 1.f);
			}
			if (TunnelOrScientist == 3)
			{
				if (NPCNames)
					DrawLString(12, tempFeet.x, (tempFeet.y + 15), NPCNamescolor, true, true, "Scarecrow");
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);

				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);

				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(scarecrowcolor), 1.f);
			}

			float entHp = Player->Health();
			if (entHp > 101) entHp = 100;
			float HealthHeightCalc = ((float)entHp / 100) * ((float)Entity_w + 20);
			DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 10, tempHead.y - 5, Entity_w + 20, 4, ImVec4(COLOUR(30.0f), COLOUR(30.0f), COLOUR(30.0f), COLOUR(220.0f)));
			DrawFilledRectImGui(tempFeet.x - (Entity_w / 2) - 10, tempHead.y - 5, HealthHeightCalc, 4, ImVec4(COLOUR(80.0f), COLOUR(220.0f), COLOUR(100.0f), COLOUR(255.0f)));
		}
	}
}

void ESP_ResourceL(DWORD64 ObjectClass, bool showDistance, float drawDistance, const wchar_t* targettext, ImVec4 col) {
	uintptr_t gameObject = driver.read<uintptr_t>(ObjectClass + 0x30);
	uintptr_t transform = driver.read<uintptr_t>(gameObject + 0x8);
	uintptr_t vector = driver.read<uintptr_t>(transform + 0x38);
	Vector3 game_Pos = driver.read<Vector3>(vector + 0x90);
	Vector3 screen_Pos, BoxPos;
	if (LocalPlayer.WorldToScreen(game_Pos, screen_Pos) && LocalPlayer.WorldToScreen(game_Pos + Vector3(0.f, 1.f, 0.f), BoxPos)) {

		if ((int)Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(r_foot), game_Pos) <= drawDistance) {
			std::wstring ws(targettext);
			std::string str(ws.begin(), ws.end());
			DrawLString(12, screen_Pos.x, screen_Pos.y + 8, col, true, true, str.c_str());
			if (showdistancee) {
				int distation = (int)Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), game_Pos);
				char text[0x100];
				sprintf(text, skCrypt("[%d m]"), distation);
				DrawLString(12, screen_Pos.x, screen_Pos.y + 15, col, true, true, text);
			}
		}
	}
}


void ESP_Resource(DWORD64 ObjectClass, bool showDistance, float drawDistance, const wchar_t* targettext, RGBA* col) {
	uintptr_t gameObject = driver.read<uintptr_t>(ObjectClass + 0x30);
	uintptr_t transform = driver.read<uintptr_t>(gameObject + 0x8);
	uintptr_t vector = driver.read<uintptr_t>(transform + 0x38);
	Vector3 game_Pos = driver.read<Vector3>(vector + 0x90);
	Vector3 screen_Pos, BoxPos;
	if (LocalPlayer.WorldToScreen(game_Pos, screen_Pos) && LocalPlayer.WorldToScreen(game_Pos + Vector3(0.f, 1.f, 0.f), BoxPos)) {

		if ((int)Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(r_foot), game_Pos) <= drawDistance) {
			std::wstring ws(targettext);
			std::string str(ws.begin(), ws.end());
			DrawString(12, screen_Pos.x, screen_Pos.y + 8, col, true, true, str.c_str());
			if (showdistancee) {
				int distation = (int)Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), game_Pos);
				char text[0x100];
				sprintf(text, skCrypt("[%d m]"), distation);
				DrawString(12, screen_Pos.x, screen_Pos.y + 15, col, true, true, text);
			}
		}
	}
}


bool GetKey(int key)
{
	realkey = key;
	return true;
}
void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				aimkey = i;
				keystatus = 0;
				return;
			}
		}
	}
}
static const char* keyNames[] = {
	"",
	"Left Mouse",
	"Right Mouse",
	"Cancel",
	"Middle Mouse",
	"Mouse 5",
	"Mouse 4",
	"",
	"Backspace",
	"Tab",
	"",
	"",
	"Clear",
	"Enter",
	"",
	"",
	"Shift",
	"Control",
	"Alt",
	"Pause",
	"Caps",
	"",
	"",
	"",
	"",
	"",
	"",
	"Escape",
	"",
	"",
	"",
	"",
	"Space",
	"Page Up",
	"Page Down",
	"End",
	"Home",
	"Left",
	"Up",
	"Right",
	"Down",
	"",
	"",
	"",
	"Print",
	"Insert",
	"Delete",
	"",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",
	"",
	"",
	"",
	"",
	"",
	"Numpad 0",
	"Numpad 1",
	"Numpad 2",
	"Numpad 3",
	"Numpad 4",
	"Numpad 5",
	"Numpad 6",
	"Numpad 7",
	"Numpad 8",
	"Numpad 9",
	"Multiply",
	"Add",
	"",
	"Subtract",
	"Decimal",
	"Divide",
	"F1",
	"F2",
	"F3",
	"F4",
	"F5",
	"F6",
	"F7",
	"F8",
	"F9",
	"F10",
	"F11",
	"F12",
};
static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}
void HotkeyButton(int aimkey, void* changekey, int status)
{
	const char* preview_value = NULL;
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
		Items_ArrayGetter(keyNames, aimkey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = skCrypt("Select Key");
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = skCrypt("Press key to bind");
	}
	if (ImGui::Button(aimkeys.c_str(), ImVec2(100, 20)))
	{
		if (status == 0)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}