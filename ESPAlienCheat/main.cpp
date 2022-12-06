#include "overlay.h"
#include "memory.h"
#include "utility.h"
#include "struct.h"
#include "protect/protectmain.h"
#include<direct.h>
#include "auth.hpp"

#include "SnowFlake.hpp"
#define SNOW_LIMIT 300
std::vector<Snowflake::Snowflake> snow;


ImColor cRainbow;

using namespace KeyAuth;

std::string namee = _xor_("AlienCheatRust"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = _xor_("Y1f7i5nnTa"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = _xor_("aae50125a5ad65dac7434bdfb723f82348656684dcdec883aa86f11c085ae6f6"); // app secret, the blurred text on licenses tab and other tabs
std::string version = _xor_("1.1"); // leave alone unless you've changed version on website
std::string url = _xor_("https://auth.aliencheats.com/api/1.1/"); // change if you're self-hosting
std::string sslPin = _xor_("ssl pin key (optional)"); // don't change unless you intend to pin public certificate key. you can get here in the "Pin SHA256" field https://www.ssllabs.com/ssltest/analyze.html?d=keyauth.win&latest. If you do this you need to be aware of when SSL key expires so you can update it
api KeyAuthApp(namee, ownerid, secret, version, url, sslPin);
POINT p;
RECT rc;
POINT xy;

static int xekran = 576, yekran = 386;
static int sayfa = 1;

bool font1 = true;
bool font2;
bool font3;
bool font4;

static int MenuSayfasi = 6;
bool cross = false;
bool ADS_Hide = false;
bool Giris = true;

inline bool enable = false;
inline bool esp = false;
inline bool espon = false;

inline float timee = 12;
inline float light = 1;
inline float gravity_distancee = 5;
static bool bok = false;

inline bool hepsi = true;
static bool hidescript1 = true;
static bool hidescript2 = true;
static bool hidescript3 = true;
static bool hidescript4 = true;
inline bool admin_flag_checkboxx = false;
inline bool hardcoremodeMap = false;
inline bool spiderman = false;
inline bool norecoil = false;
inline bool hanging = false;
inline bool thirdperson = false;
inline bool gravity = false;
inline bool fatbullet = false;
inline bool nospread = false;
inline bool alwaysday = false;
inline bool alwaysdaytog = true;
inline bool fovtamiri = false;
inline bool nightmodetamiri = false;
inline bool fakeworkbench = false;
inline bool Spectating = false;
inline bool fov = false;
inline bool WalkOnWater = false;
inline bool flyhack = false;
inline bool climb = false;
inline bool infinitejump = false;
inline bool nospread_checkbox = false;
inline bool fat_bullet_checkbox = false;
inline bool super_eoka_checkbox = false;
inline bool full_automatic_checkbox = false;
inline bool jumpshot = false;
inline bool aydinlik = false;
inline bool fastswim = false;
inline bool fastswimm = false;
inline bool SPEEDhack = false;
inline bool change_time_checkbox = false;
inline bool zoom = false;
inline bool suicide = false;
inline bool AdminEsp = false;
inline bool nighttmode = false;
inline bool cullingtamiri = false;
inline bool fatbullettamiri = false;
inline bool eokatamiri = false;
inline bool ototamiri = false;
inline bool instantCompound = false;
inline bool instabow = false;
inline bool fakelag = false;
inline bool nosway = false;
inline bool supermeele = false;
inline bool fastswitch = false;
inline bool meeletamiri = false;
inline bool noshotgunspread = false;
inline bool longneck = false;
inline bool cameraaa = false;
inline bool timer = false;
inline bool chams = false;
inline bool chamstamiri = false;
inline bool spinbot = false;

static int WalkOnWaterr = 0x5A;
static int FlyHackButon = 0x46;
static int hangingg = VK_XBUTTON2;
static int speedbutton = VK_XBUTTON1;
static int zoombutton = 0;
static int climbbutton = 0x58;



float FOVV = 120.f;
float speedBonus = 0.5f;
float flyhackspeed = 0.f;
float zoomyer = 42.f;
float timervalue = 2.f;

float NeckWidgth = 0.f;
float NeckLength = 0.f;
float NeckWeigth = 0.f;

bool control = false;


std::wstring get_item_name(uintptr_t item)
{
	auto unk = driver.read<UINT64>(item + 0x20);
	unk = driver.read<UINT64>(unk + 0x20);
	return driver.read_wstring(unk + 0x14, 14);
}
bool is_weapon(uintptr_t helditem)
{
	auto ItemName = get_item_name(helditem);
	if (ItemName.find(L"rifle") != std::string::npos) return true;
	if (ItemName.find(L"pistol") != std::string::npos) return true;
	if (ItemName.find(L"bow.hunting") != std::string::npos) return true;
	if (ItemName.find(L"bow") != std::string::npos) return true;
	if (ItemName.find(L"lmg") != std::string::npos) return true;
	if (ItemName.find(L"shotgun") != std::string::npos) return true;
	if (ItemName.find(L"smg") != std::string::npos) return true;
	else return false;
}

bool is_meele(uintptr_t helditem)
{
	auto ItemName = get_item_name(helditem);
	if (ItemName.find(L"rock") != std::string::npos) return true;
	if (ItemName.find(L"hatchet") != std::string::npos) return true;
	if (ItemName.find(L"stone.pickaxe") != std::string::npos) return true;
	if (ItemName.find(L"stonehatchet") != std::string::npos) return true;
	if (ItemName.find(L"pickaxe") != std::string::npos) return true;
	if (ItemName.find(L"hammer.salvage") != std::string::npos) return true;
	if (ItemName.find(L"icepick.salvag") != std::string::npos) return true;
	if (ItemName.find(L"axe.salvaged") != std::string::npos) return true;
	if (ItemName.find(L"pitchfork") != std::string::npos) return true;
	if (ItemName.find(L"mace") != std::string::npos) return true;
	if (ItemName.find(L"spear.stone") != std::string::npos) return true;
	if (ItemName.find(L"spear.wooden") != std::string::npos) return true;
	if (ItemName.find(L"machete") != std::string::npos) return true;
	if (ItemName.find(L"bone.club") != std::string::npos) return true;
	if (ItemName.find(L"paddle") != std::string::npos) return true;
	if (ItemName.find(L"salvaged.sword") != std::string::npos) return true;
	if (ItemName.find(L"salvaged.cleav") != std::string::npos) return true;
	if (ItemName.find(L"knife.combat") != std::string::npos) return true;
	if (ItemName.find(L"knife.butcher") != std::string::npos) return true;
	if (ItemName.find(L"jackhammer") != std::string::npos) return true;
	if (ItemName.find(L"chainsaw") != std::string::npos) return true;
	if (ItemName.find(L"knife.bone") != std::string::npos) return true;
	if (ItemName.find(L"torch") != std::string::npos) return true;
	if (ItemName.find(L"hammer") != std::string::npos) return true;
	if (ItemName.find(L"sickle") != std::string::npos) return true;
	else return false;
}
void omni()
{
	while (true)
	{
		auto baseMove = driver.read<uintptr_t>(Local_Player + oPlayerMovement); //baseplayer -> basemovement
		driver.write<float>(baseMove + 0x40, 5.f);
	}
}

unsigned short lfsr = 0xACE1u;
unsigned int bit = 0;

unsigned RANDOMVECTOR()
{
	if (!lfsr) {
		lfsr = 0xACE1u; bit = 0;
	}
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return lfsr = (lfsr >> 1) | (bit << 15);
}



bool moon = true;

Vector3 multiplyQuad(Vector4 quat, Vector3 vec)
{
	float num = quat.x * 2.f;
	float num2 = quat.y * 2.f;
	float num3 = quat.z * 2.f;
	float num4 = quat.x * num;
	float num5 = quat.y * num2;
	float num6 = quat.z * num3;
	float num7 = quat.x * num2;
	float num8 = quat.x * num3;
	float num9 = quat.y * num3;
	float num10 = quat.w * num;
	float num11 = quat.w * num2;
	float num12 = quat.w * num3;
    Vector3 result;
	result.x = (1.f - (num5 + num6)) * vec.x + (num7 - num12) * vec.y + (num8 + num11) * vec.z;
	result.y = (num7 + num12) * vec.x + (1.f - (num4 + num6)) * vec.y + (num9 - num10) * vec.z;
	result.z = (num8 - num11) * vec.x + (num9 + num10) * vec.y + (1.f - (num4 + num5)) * vec.z;
	return result;
}

void Hilee()
{
	while (true)
	{

		/*	auto main_offsets = driver.read<uintptr_t>(g_assembly + BaseGameMode);
			Local_Player = driver.read_chain(main_offsets, { 0xb8, 0x20, 0x10, 0x28, 0x18, 0x20 });*/
			/// 

		int flag = driver.read<int>(Local_Player + playerflags);
		auto Movement = driver.read<uintptr_t>(Local_Player + oPlayerMovement);

		const auto current_item = GetHeldItem(Local_Player);
		auto base_projectile = driver.read<uintptr_t>(current_item + oHeld);
		auto recoil_prop = driver.read<uintptr_t>(base_projectile + oRecoilProperties);
		auto newRecoilOverride = driver.read<uintptr_t>(recoil_prop + 0x78);




		//uintptr_t BaseGameMode = driver.read<uintptr_t>(g_assembly + BaseGameMode);
		//uintptr_t h1 = driver.read<uintptr_t>(BaseGameMode + 0xB8);
		//uintptr_t h2 = driver.read<uintptr_t>(h1 + 0x20);
		//uintptr_t h3 = driver.read<uintptr_t>(h2 + 0x10);
		//uintptr_t h4 = driver.read<uintptr_t>(h3 + 0x28);
		//objectList = driver.read<uintptr_t>(h4 + 0x18);
		//objectListSize = driver.read<uint32_t>(h4 + 0x10);
		//if (!objectListSize)
		//	return;


		//	



		if (hardcoremodeMap)
		{
			auto HardCoreMap = driver.read<uintptr_t>(g_assembly + BaseGameMode2); //       "Signature": "BaseGameMode_c*"	
			auto HardCoreMapOn = driver.read_chain(HardCoreMap, { 0xb8, 0x8 });
			driver.write<bool>(HardCoreMapOn + 0x17C, true); // public bool ingameMap;
			driver.write<bool>(HardCoreMapOn + 0x17D, true); // public bool compass;
		}

		if (admin_flag_checkboxx == true) { // adminmode ve debugcamera repair


			auto player_flags = driver.read<uintptr_t>(Local_Player + oPlayerFlags);
			if (!player_flags) {

				return;
			}
			player_flags |= 4;
			driver.write(Local_Player + oPlayerFlags, player_flags);


			auto klass = driver.read<uintptr_t>(g_assembly + ConVar_Client_c);
			auto static_fields = driver.read<uintptr_t>(klass + 0xB8);
			driver.write<float>(static_fields + oCamSpeed, 1.f);
			driver.write<float>(static_fields + oCamLerp, 1.f);



			driver.write<bool>(Movement + 0x18, false); // noclipi oto kapatýyor

			auto ConsoleSystemCommands15 = driver.read<uintptr_t>(g_assembly + ConsoleSystem_Index_c); // "Signature": "ConsoleSystem_Index_c*"
			auto ConsoleSystemCommands16 = driver.read_chain(ConsoleSystemCommands15, { 0xb8 });
			uintptr_t ConsoleSystemCommands = driver.read<uintptr_t>(ConsoleSystemCommands16 + 0x10);
			if (!ConsoleSystemCommands) return;

				
			for (int x = 0; x < 7000; x++)
			{
				uintptr_t ConsoleSystemCommand = driver.read<uintptr_t>(ConsoleSystemCommands + 0x20 + (x * 0x8));
				if (!ConsoleSystemCommand) continue;

				uintptr_t Name = driver.read<uintptr_t>(ConsoleSystemCommand + 0x10);
				if (!Name) continue;

				wchar_t command_name[36] = { '\0' };
				driver.read_array(Name + 0x14, command_name, sizeof(command_name));

				if (!wcscmp(command_name, L"debugcamera"))
				{
					driver.write<bool>(0, ConsoleSystemCommand + 0x57);
				}
			}

		}
		if (thirdperson == true)
		{
			if (driver.read<uintptr_t>(Local_Player + playerflags) != 1024) {
				driver.write<uintptr_t>(Local_Player + playerflags, 1024);
			}
		}
		if (AdminEsp == true)
		{
			if (cullingtamiri)
			{
				auto OcclusionCulling = driver.read<uintptr_t>(g_assembly + 56755032); //       "Signature": "OcclusionCulling_c*"
				auto CullingDebugOnOff = driver.read<uintptr_t>(OcclusionCulling + 0xB8);
				auto OcclusionCullingEditted = driver.read_chain(OcclusionCulling, { 0xB8, 128, 0x18 });
				driver.write<uintptr_t>(OcclusionCullingEditted + 0x20, 131072);
				if (driver.read<uintptr_t>(CullingDebugOnOff + 0x94) != 1) {
					driver.write<uintptr_t>(CullingDebugOnOff + 0x94, 1);
				}
				cullingtamiri = false;
			}
		}
		else
		{
			if (!cullingtamiri)
			{
				auto OcclusionCulling = driver.read<uintptr_t>(g_assembly + 56755032); //       "Signature": "OcclusionCulling_c*"
				auto CullingDebugOnOff = driver.read<uintptr_t>(OcclusionCulling + 0xB8);
				if (driver.read<uintptr_t>(CullingDebugOnOff + 0x94) != 0) {
					driver.write<uintptr_t>(CullingDebugOnOff + 0x94, 0);
				}
				cullingtamiri = true;
			}
		}
		auto klass2 = driver.read<uintptr_t>(g_assembly + ConVar_Admin_c); // convar_admin_c*
		auto static_fields2 = driver.read<uintptr_t>(klass2 + 0xb8);
		if (nighttmode)
		{
			driver.write<float>(static_fields2 + 0xC, 2); // public static float adminambientmultiplier;
		}
		else
		{
			driver.write<float>(static_fields2 + 0xC, -1);  // public static float adminambientmultiplier;
		}
		if (alwaysday)
		{
			alwaysdaytog = false;
			if (driver.read<float>(static_fields2 + 0x0) != timee) {
				driver.write<float>(static_fields2 + 0x0, timee); // public static float admintime;
			}
			if (driver.read<float>(static_fields2 + 0x4) != light) {
				driver.write<float>(static_fields2 + 0x4, light); // public static float admintime;
			}
		}
		else
		{
			if (!alwaysdaytog)
			{
				if (driver.read<float>(static_fields2 + 0x0) != -1) {
					driver.write<float>(static_fields2 + 0x0, -1); // public static float admintime;
				}
				if (driver.read<float>(static_fields2 + 0x4) != -1) {
					driver.write<float>(static_fields2 + 0x4, -1); // public static float admintime;
				}
				alwaysdaytog = true;
			}
		}
		if (spiderman == true) {
			if (driver.read<float>(Movement + groundAngle) != 0.f) {
				driver.write<float>(Movement + groundAngle, 0.f);
			}
			if (driver.read<float>(Movement + groundAngleNew) != 0.f) {
				driver.write<float>(Movement + groundAngleNew, 0.f);
			}
		}
		if (infinitejump == true) {
			if (GetAsyncKeyState(VK_SPACE))
			{
				driver.write<Vector3>(Movement + 0xc8, Vector3(0, 10000000, 0));
				driver.write<Vector3>(Movement + 0xc4, Vector3(99999999, 99999999, 99999999));
			}
		}
		if (suicide == true)
		{
			if (GetAsyncKeyState(VK_END))
			{
				driver.write<bool>(Movement + wasFalling, true);
				driver.write<Vector3>(Movement + previousVelocity, Vector3(0, -20, 0));
				driver.write<float>(Movement + groundTime, 0.f);
			}
		}
		if (gravity == true) {
			if (GetAsyncKeyState(VK_SPACE))
			{
				if (driver.read<float>(Movement + oGravityMultiplier) != gravity_distancee / 2) {
					driver.write<float>(Movement + oGravityMultiplier, gravity_distancee / 2);
				}
			}
		}
		if (fakeworkbench == true) {
			auto player_flags = driver.read<uintptr_t>(Local_Player + oPlayerFlags);
			if (!player_flags) {

				return;
			}
			player_flags |= 4194304;
			driver.write(Local_Player + oPlayerFlags, player_flags);
		}
		if (WalkOnWater == true) {
			if (GetAsyncKeyState(WalkOnWaterr))
			{
				if (driver.read<float>(Movement + groundAngle) != 0.f) {
					driver.write<float>(Movement + groundAngle, 0.f);//groundAngle
					driver.write<float>(Movement + groundAngleNew, 0.f);//groundAngleNew
					driver.write<float>(Movement + oGravityMultiplier, 0.f);//gravityMultiplier
				}
			}
			else
			{
				if (driver.read<float>(Movement + oGravityMultiplier) != 2.5f) {
					driver.write<float>(Movement + oGravityMultiplier, 2.5f);//gravityMultiplier
				}
			}
		}
		if (flyhack == true) {
			if (GetAsyncKeyState(FlyHackButon))
			{

				driver.write<float>(Movement + groundAngle, flyhackspeed);//groundAngle
				driver.write<float>(Movement + groundAngleNew, flyhackspeed);//groundAngleNew
				driver.write<float>(Movement + oGravityMultiplier, flyhackspeed);//gravityMultiplier

			}
			else
			{
				if (driver.read<float>(Movement + oGravityMultiplier) != 2.5f) {
					driver.write<float>(Movement + oGravityMultiplier, 2.5f);//gravityMultiplier
				}
			}
		}
		if (climb == TRUE)
		{
			if (GetAsyncKeyState(climbbutton))
			{
				auto PlayerTick = driver.read_chain(Local_Player + 0x65C, { 0x30, 0x0 });
				driver.write<int>(PlayerTick + 0x24, 64);
				driver.write<float>(Movement + capsuleHeight, -100);
				driver.write<float>(Movement + capsuleCenter, -100);
				driver.write<float>(Local_Player + 0x658, 50.33f);
				driver.write<float>(Local_Player + 0x654, 50.33f); // public float serverTickInterval; // 0x658
			}	
			else
			{
				driver.write<float>(Local_Player + 0x658, 0.005f);
				if (driver.read<float>(Movement + capsuleHeight) != 1.79f) {
					driver.write<float>(Movement + capsuleHeight, 1.79f);
					driver.write<float>(Movement + capsuleCenter, 0.899f);
				}
			}
		}
		if (fov == TRUE) {
			uint64_t fov = driver.read<UINT64>(g_assembly + oFovConVarGraphics); // "Signature": "ConVar_Graphics_c"
			uint64_t instance = driver.read<UINT64>(fov + 0xB8);
			if (driver.read<float>(instance + 0X18) != FOVV) {
				driver.write<float>(instance + 0X18, FOVV); // public static float admintime;
			}
			alwaysdaytog = false;
		}
		if (!fov == TRUE)
		{
			if (!fovtamiri)
			{
				uint64_t fov = driver.read<UINT64>(g_assembly + oFovConVarGraphics); // "Signature": "ConVar_Graphics_c"
				uint64_t instance = driver.read<UINT64>(fov + 0xB8);
				if (driver.read<float>(instance + 0X18) != 90) {
					driver.write<float>(instance + 0X18, 90); // public static float admintime;
				}
				alwaysdaytog = true;
			}
		}
		if (jumpshot == TRUE) {
			auto mov_flag = driver.read<uintptr_t>(Movement + oModelState);
			driver.write<uintptr_t>(mov_flag, oFlagOnGround);
			driver.write<float>(Movement + groundAngle, 1.f);
			driver.write<float>(Movement + groundAngleNew, 1.f);
		}
		if (zoom == TRUE)
		{
			if (GetAsyncKeyState(VK_RBUTTON))
			{
				uint64_t fov = driver.read<UINT64>(g_assembly + oFovConVarGraphics); // "Signature": "ConVar_Graphics_c" // DONE
				uint64_t instance = driver.read<UINT64>(fov + 0xB8);
				if (driver.read<float>(instance + 0X18) != zoomyer) {
					driver.write<float>(instance + 0X18, zoomyer); // public static float admintime;
				}
			}
		}
		if (fastswim == TRUE)
		{
			if (driver.read<float>(Local_Player + oclothingWaterSpeedBonus) != 0.2f) {
				driver.write<float>(Local_Player + oclothingWaterSpeedBonus, 0.2f); // public static float admintime;
			}
			fastswimm == false;
		}
		if (!fastswim == TRUE)
		{
			if (!fastswimm)
			{
				if (driver.read<float>(Local_Player + oclothingWaterSpeedBonus) != 0.1) {
					driver.write<float>(Local_Player + oclothingWaterSpeedBonus, 0.1); // public static float admintime;
				}
				fastswimm == true;
			}
		}
		if (SPEEDhack == TRUE)
		{
			if (GetAsyncKeyState(speedbutton))
			{
				driver.write<float>(Local_Player + clothingMoveSpeedReduction, 0.f - speedBonus); // public static float admintime;
			}
			if (!GetAsyncKeyState(speedbutton))
			{
				driver.write<float>(Local_Player + clothingMoveSpeedReduction, 0.f - 0.f); // public static float admintime;
			}
		}
		if (cameraaa)
		{
			auto eyes = driver.read<uintptr_t>(Local_Player + oPlayerEyes);
			driver.write<Vector3>(eyes + 0x38, Vector3(NeckWeigth, NeckLength, NeckWidgth)); //private Vector3 viewOffset; // 0x38

			if (GetAsyncKeyState(VK_PRIOR) & 1)
			{
				NeckLength++;
			}
			if (GetAsyncKeyState(VK_NEXT) & 1)
			{
				NeckLength--;
			}

			if (GetAsyncKeyState(VK_LEFT) & 1)
			{
				NeckWeigth--;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 1)
			{
				NeckWeigth++;
			}
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				NeckWidgth++;
			}
			if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				NeckWidgth--;
			}
			if (GetAsyncKeyState(VK_HOME) & 1)
			{
				NeckLength = 0.f;
				NeckWeigth = 0.f;
				NeckWidgth = 0.f;
			}
		}
		if (longneck)
		{
			auto eyes = driver.read<uintptr_t>(Local_Player + oPlayerEyes);
			driver.write<Vector3>(eyes + 0x38, Vector3(0.f, 2.0f, 0.f)); //private Vector3 viewOffset; // 0x38
		}
		if (timer)
		{
			auto time = driver.read<uintptr_t>(g_unityplayer + 0x17C1CD0 + 7 * 8);
			if (time) {
				if (GetAsyncKeyState(hangingg))
				{
					driver.write<float>(time + 0xFC, timervalue);
				}
				else {
					driver.write<float>(time + 0xFC, 1.f);
				}
			}
		}
		//auto ItemName = get_item_name(current_item);
		//std::string wsTmp(ItemName.begin(), ItemName.end());
		//std::string text = wsTmp;
		//std::cout << text << std::endl;

		bool ismeele = is_meele(current_item);
		if (ismeele) {
			if (supermeele)
			{
				if (driver.read<float>(base_projectile + omaxDistance) != 3.0f) {
					driver.write<float>(base_projectile + omaxDistance, 3.0f);
				}
				if (driver.read<float>(base_projectile + oAttackRadius) != 1.0f) {
					driver.write<float>(base_projectile + oAttackRadius, 1.0f);
				}

				if (driver.read<bool>(base_projectile + oBlockSprintOnAttack) != false) {
					driver.write<bool>(base_projectile + oBlockSprintOnAttack, false);
					driver.write<bool>(base_projectile + oonlyThrowAsProjectile, false);
					driver.write<bool>(base_projectile + othrowReady, true);
				}
			}
		}
		bool isWeapon = is_weapon(current_item);

		//std::wcout << get_item_name(current_item) << std::endl;

		if (isWeapon) {
			if (norecoil) {
				if (newRecoilOverride) {
						driver.write<int>(newRecoilOverride + oRecoilYawMin, 0);
						driver.write<int>(newRecoilOverride + oRecoilYawMax, 0);
						driver.write<int>(newRecoilOverride + oRecoilPitchMin, 0);
						driver.write<int>(newRecoilOverride + oRecoilPitchMax, 0);
				}
				if (!newRecoilOverride) {
						driver.write<int>(recoil_prop + oRecoilYawMin, 0);
						driver.write<int>(recoil_prop + oRecoilYawMax, 0);
						driver.write<int>(recoil_prop + oRecoilPitchMin, 0);
						driver.write<int>(recoil_prop + oRecoilPitchMax, 0);
				}
			}
			if (noshotgunspread)
			{
				auto List = driver.read<uintptr_t>(base_projectile + 0x370); // private List<Projectile> createdProjectiles;
				int size = driver.read<int>(List + 0x18);
				auto listt = driver.read<uintptr_t>(List + 0x10);
				for (int i = 0; i < size; ++i)
				{
					auto Projectile = driver.read<uintptr_t>(listt + 0x20 + (i * 0x8));
					auto ProjectileMod = driver.read<uintptr_t>(Projectile + 0xE8);

					driver.write<float>(ProjectileMod + 0x30, 0.f); // public float initialDistance;
					driver.write<float>(ProjectileMod + 0x38, 0.f); // public float stickProbability;
				}
			}
			if (fat_bullet_checkbox)
			{

				auto List = driver.read<uintptr_t>(base_projectile + 0x370); //private List<Projectile> createdProjectiles;
				int size = driver.read<uintptr_t>(List + 0x18);
				List = driver.read<uintptr_t>(List + 0x10);
				for (int i = 0; i < size; ++i)
				{
					auto Item = driver.read<uintptr_t>(List + 0x20 + (i * 0x8));
					if (driver.read<float>(Item + 0x2C) != 0.7f) {
						driver.write<float>(Item + 0x2C, 0.7f);
					}
				}
			}		
			if (nospread)
			{

				if (newRecoilOverride)
				{
					driver.write<int>(newRecoilOverride + oAimconeCurveScale, -1);
					driver.write<int>(newRecoilOverride + oStancePenalty, -1);
					driver.write<int>(newRecoilOverride + oAimCone, -1);
					driver.write<int>(newRecoilOverride + oHipAimCone, -1);
					driver.write<int>(newRecoilOverride + oAimconePenaltyPerShot, -1);

				}
				else
				{
					driver.write<int>(recoil_prop + oAimconeCurveScale, -1);
					driver.write<int>(recoil_prop + oStancePenalty, -1);
					driver.write<int>(recoil_prop + oAimCone, -1);
					driver.write<int>(recoil_prop + oHipAimCone, -1);
					driver.write<int>(recoil_prop + oAimconePenaltyPerShot, -1);
				}
			}

			if (full_automatic_checkbox)
			{
				if (driver.read<bool>(base_projectile + oAutomatic) != full_automatic_checkbox) {
					driver.write<bool>(base_projectile + oAutomatic, full_automatic_checkbox);
				}
			}

			if (nosway)
			{
				if (driver.read<float>(base_projectile + 0x2D8) != 0.f) {
					driver.write<float>(base_projectile + 0x2D8, 0.f);// public float aimSway;
				}
				if (driver.read<float>(base_projectile + 0x2DC) != 0.f) {
					driver.write<float>(base_projectile + 0x2DC, 0.f);// public float aimSwaySpeed;
				}
			}
			if (super_eoka_checkbox)
			{
				if (eokatamiri == false)
				{
					if (driver.read<float>(base_projectile + 0x378) != 100.f) {
						driver.write<float>(base_projectile + 0x378, 100.f); // successFraction
					}
					eokatamiri = true;
				}
				if (driver.read<bool>(base_projectile + 0x388) != true) {
					driver.write<bool>(base_projectile + 0x388, true); // didSparkThisFrame
				}
			}
			else
			{
				eokatamiri = false;
			}
			if (instantCompound == true)
			{
				if (driver.read<float>(base_projectile + 0x390) != 0) {
					driver.write<float>(base_projectile + 0x390, 0);//stringHoldDurationMax
				}
				if (driver.read<float>(base_projectile + 0x394) != 1000000) {
					driver.write<float>(base_projectile + 0x394, 1000000);//stringBonusDamage
					driver.write<float>(base_projectile + 0x3A0, 1000000);//movementPenaltyRampUpTime
				}
			}
			if (instabow == true)
			{
				driver.write<bool>(base_projectile + 0x360, true); // private bool triggerReady; // 0x360
				driver.write<float>(base_projectile + 0x364, 9999.f);
			}
		}
		if (fakelag == true)
		{
			driver.write<float>(Local_Player + 0x654, 0.8f); // public float serverTickInterval; // 0x658
			driver.write<float>(Local_Player + 0x658, 0.10f); // public float clientTickInterval; // 0x658
		}
		if (spinbot == true) {
			auto aPlayerInput = driver.read<uintptr_t>(Local_Player + oPlayerInput);
			driver.write<Vector4>(aPlayerInput + bodyRotation, Vector4(16.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + bodyRotation, Vector4(-16.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			auto aPlayerInput1 = driver.read<uintptr_t>(Local_Player + oPlayerInput);
			driver.write<Vector4>(aPlayerInput1 + headRotation, Vector4(-5.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput1 + headRotation, Vector4(22.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + bodyRotation, Vector4(-100.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + bodyRotation, Vector4(60.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + headRotation, Vector4(-100.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + headRotation, Vector4(30.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		}

		
		

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}

bool homee = true;


std::vector<BasePlayer*> enemy_list;
std::vector<BasePlayer*> enemy_listTunnel;
std::vector<BasePlayer*> enemy_listScientist;
std::vector<BasePlayer*> enemy_scarecrow;

std::vector<DWORD64> BackPack;
std::vector<DWORD64> Corpse;

std::vector<DWORD64> StoneOre;
std::vector<DWORD64> SulfurOre;
std::vector<DWORD64> MetalOre;

std::vector<DWORD64> Stone;
std::vector<DWORD64> Sulfur;
std::vector<DWORD64> Metal;

std::vector<DWORD64> Hemp;

std::vector<DWORD64> mushroom1;
std::vector<DWORD64> mushroom2;

std::vector<DWORD64> AirDrop;

std::vector<DWORD64> MiniCopter;
std::vector<DWORD64> Carss;
std::vector<DWORD64> ScrapHeli;
std::vector<DWORD64> PatrolHeli;
std::vector<DWORD64> Boat;
std::vector<DWORD64> Rhib;
std::vector<DWORD64> Horsee;

std::vector<DWORD64> Stash;

std::vector<DWORD64> Military;
std::vector<DWORD64> Elite;
std::vector<DWORD64> Loot;
std::vector<DWORD64> Food;
std::vector<DWORD64> Medical;
std::vector<DWORD64> ToolBox;

std::vector<DWORD64> AutoTurret;
std::vector<DWORD64> ToolCupboard;

std::vector<DWORD64> Wolf;
std::vector<DWORD64> Bear;
std::vector<DWORD64> Stag;
std::vector<DWORD64> Chicken;
std::vector<DWORD64> Boar;

std::vector<DWORD64> RifleAk;
std::vector<DWORD64> RifleAkIce;
std::vector<DWORD64> Revolver;
std::vector<DWORD64> Python;
std::vector<DWORD64> HuntingBow;
std::vector<DWORD64> Compound;
std::vector<DWORD64> DoubleShotgun;
std::vector<DWORD64> Nailgun;
std::vector<DWORD64> Thompson;
std::vector<DWORD64> pSemi;
std::vector<DWORD64> Semi;
std::vector<DWORD64> WaterPipe;
std::vector<DWORD64> Spas12;
std::vector<DWORD64> M39;
std::vector<DWORD64> M92;
std::vector<DWORD64> MP5;
std::vector<DWORD64> SMG;
std::vector<DWORD64> Pump6;
std::vector<DWORD64> M249;
std::vector<DWORD64> L96;
std::vector<DWORD64> Bolt;
std::vector<DWORD64> Hmlmg;
std::vector<DWORD64> Eoka;
std::vector<DWORD64> Multiplegrenad;
std::vector<DWORD64> RocketLauncher;
std::vector<DWORD64> LR300;
void cheat()
{
	while (true)
	{
		/*	uintptr_t buffer_list = driver.read_chain(g_assembly, { BaseEntity, 0xB8, 0x10, 0x10, 0x28 });
			if (!buffer_list)
				buffer_list = driver.read_chain(g_assembly, { BaseEntity, 0xB8, 0x40, 0x10, 0x28 });
			auto objectList = driver.read<uintptr_t>(buffer_list + 0x18);
			auto objectListSize = driver.read<uint32_t>(buffer_list + 0x10);
			if (!objectListSize)
				return;*/
		auto main_offsets = driver.read<uintptr_t>(g_assembly + BaseGameMode);
		Local_Player = driver.read_chain(main_offsets, { 0xb8, 0x20, 0x10, 0x28, 0x18, 0x20 });

		const auto camera_manager_offset = driver.read<uintptr_t>(g_unityplayer + 0x1762E80);
		const auto camera_manager = driver.read<uintptr_t>(camera_manager_offset);
		const auto camera = driver.read<uintptr_t>(camera_manager);
		const auto camera_object = driver.read<uintptr_t>(camera + 0x30);
		if (!camera_object)
			return;

		const auto object_class = driver.read<uintptr_t>(camera_object + 0x30);
		if (!object_class)
			return;
		const auto Entityy = driver.read<uintptr_t>(object_class + 0x18);
		if (!Entityy)
			return;
		LocalPlayer.pViewMatrix = (Matrix4x4*)(Entityy + 0x2E4);

		uintptr_t BaseGameModee = driver.read<uintptr_t>(g_assembly + BaseGameMode);
		uintptr_t h1 = driver.read<uintptr_t>(BaseGameModee + 0xB8);
		uintptr_t h2 = driver.read<uintptr_t>(h1 + 0x20);
		uintptr_t h3 = driver.read<uintptr_t>(h2 + 0x10);
		uintptr_t h4 = driver.read<uintptr_t>(h3 + 0x28);
		auto objectList = driver.read<uintptr_t>(h4 + 0x18);
		auto objectListSize = driver.read<uint32_t>(h4 + 0x10);
		if (!objectListSize)
			return;

		for (int i = 0; i < objectListSize; i++) {
			auto curObject = driver.read<uintptr_t>(objectList + (0x20 + (i * 8)));
			auto baseObject = driver.read<uintptr_t>(curObject + 0x10);
			auto object = driver.read<uintptr_t>(baseObject + 0x30);
			auto tag = driver.read<WORD>(object + 0x54);
			auto buff = readchar(driver.read<uintptr_t>(object + 0x60));
			Entity = driver.read<uintptr_t>(objectList + 0x20 + (i * 0x8)); if (Entity <= 100000) continue;
			uintptr_t Object = driver.read<uintptr_t>(Entity + 0x10); if (Object <= 100000) continue;
			uintptr_t ObjectClass = driver.read<uintptr_t>(Object + 0x30); if (ObjectClass <= 100000) continue;


			auto SKY_C = driver.read<uintptr_t>(g_assembly + TodSkyy); // "Signature": "TOD_Sky_c*"
			auto SKYINSTANCE = driver.read<uintptr_t>(SKY_C + 0xB8);
			auto SKYINSTANCELIST = driver.read<uintptr_t>(SKYINSTANCE + 0x0);
			auto INSTANCES = driver.read<uintptr_t>(SKYINSTANCELIST + 0x10);
			auto Dome = driver.read<uintptr_t>(INSTANCES + 0x20);

			//auto TodCycle = driver.read<uintptr_t>(Dome + 0x38);
			//driver.write<float>(TodCycle + 0x10, 12.f); // Always day

			//auto Stars = driver.read<uintptr_t>(Dome + 0x70);
			//driver.write<float>(Stars + 0x10, 1.0f); //MESH SIZE
			//driver.write<float>(Stars + 0x14, 150.0f); //MESH BRIGHTNESS
			//driver.write<int>(Stars + 0x18, 1); //MESH Position

			////MOON SHIT
			//auto Moon = driver.read<uintptr_t>(Dome + 0x68);
			//driver.write<float>(Moon + 0x14, 6.0f); //MESH BRIGHTNESS
			//driver.write<float>(Moon + 0x10, 5.0f); //MESH SIZE
			//driver.write<float>(Moon + 0x18, 1.0f); //MESH CONTRAST
			//driver.write<float>(Moon + 0x24, 5.0f); //POSITION
			////MOON COLOR SHIT
			//auto Night = driver.read<uintptr_t>(Dome + 0x58);
			//auto MoonColorPtr = driver.read<uintptr_t>(Night + 0x10);
			//auto MoonColor = driver.read<uintptr_t>(MoonColorPtr + 0x10);
			//driver.write<float>(MoonColor, 1.0f);
			//driver.write<float>(MoonColor + 0x4, 1.0f);
			//driver.write<float>(MoonColor + 0x8, 0.6f);

			//driver.write<float>(MoonColor + 0xC, 0.6f);
			//driver.write<float>(MoonColor + 0x10, 0.6f);

			//driver.write<float>(MoonColor + 0x14, 0.0f);
			//driver.write<float>(MoonColor + 0x18, 1.0f);
			//driver.write<float>(MoonColor + 0x1C, 1.0f);

			//auto StarQuality = driver.read<uintptr_t>(Dome + 0x30);
			//driver.write<float>(StarQuality + 0x0, 2);

			if (chams)
			{
				if (!chamstamiri)
				{
					uintptr_t player_model = driver.read<uintptr_t>(Entity + 0x4D0); // public PlayerModel playerModel;

					auto components = driver.read<uintptr_t>(Dome + 0xA8);
					auto scattering = driver.read<uintptr_t>(components + 0x1A0);
					auto material = driver.read<uintptr_t>(scattering + 0x78);

					//Cinsiyet 1
					auto player_skin_component = driver.read<uintptr_t>(player_model + 0x1A0); // public SkinSetCollection MaleSkin; // 0x1A0
					auto skins = driver.read<uintptr_t>(player_skin_component + 0x18);
					auto skins_sz = driver.read<int32_t>(skins + 0x18);
					for (int i = NULL; i <= (int)skins_sz; i++)
					{
						auto current_skin = driver.read<uintptr_t>(skins + 0x20 + (i * 0x8));

						driver.write<uintptr_t>(current_skin + 0x68, material);
						driver.write<uintptr_t>(current_skin + 0x70, material);
						driver.write<uintptr_t>(current_skin + 0x78, material);
					}
					//Cinsiyet 2
					auto player_skin_component2 = driver.read<uintptr_t>(player_model + 0x1A8); // public SkinSetCollection MaleSkin; // 0x1A0
					auto skins2 = driver.read<uintptr_t>(player_skin_component2 + 0x18);
					auto skins_sz2 = driver.read<int32_t>(skins2 + 0x18);
					for (int i = NULL; i <= (int)skins_sz2; i++)
					{
						auto current_skin2 = driver.read<uintptr_t>(skins2 + 0x20 + (i * 0x8));

						driver.write<uintptr_t>(current_skin2 + 0x68, material);
						driver.write<uintptr_t>(current_skin2 + 0x70, material);
						driver.write<uintptr_t>(current_skin2 + 0x78, material);
					}
					chamstamiri = true;
				}
			}
			else
			{
				chamstamiri = false;
			}
			BasePlayer* Player = (BasePlayer*)driver.read<DWORD64>(Object + 0x28); //public ulong playerID;
			if (buff.find(skCrypt("Local")) != std::string::npos) {
				BasePlayer* Player = driver.read<BasePlayer*>(baseObject + 0x28);
				if (Player != LocalPlayer.BasePlayer) {}
				LocalPlayer.BasePlayer = Player;
			}
			if (buff.find(skCrypt("player.prefab")) != std::string::npos)
			{
				enemy_list.push_back(Player);
			}
			if (buff.find(skCrypt("tunneldweller.prefab")) != std::string::npos)
			{
				enemy_listTunnel.push_back(Player);
			}
			if (buff.find(skCrypt("scientistnpc")) != std::string::npos)
			{
				enemy_listScientist.push_back(Player);
			}
			if (buff.find(skCrypt("scarecrow")) != std::string::npos)
			{
				enemy_scarecrow.push_back(Player);
			}
			if (buff.find(skCrypt("item_drop_backpack")) != std::string::npos)
			{
				BackPack.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("player_corpse")) != std::string::npos)
			{
				Corpse.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("stone-ore.prefab")) != std::string::npos)
			{
				StoneOre.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("sulfur-ore.prefab")) != std::string::npos)
			{
				SulfurOre.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("metal-ore.prefab")) != std::string::npos)
			{
				MetalOre.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("stone-collectable.prefab")) != std::string::npos)
			{
				Stone.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("sulfur-collectable.prefab")) != std::string::npos)
			{
				Sulfur.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("metal-collectable.prefab")) != std::string::npos)
			{
				Metal.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("hemp-collectable.prefab")) != std::string::npos)
			{
				Hemp.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("mushroom-cluster-5.prefab")) != std::string::npos)
			{
				mushroom1.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("mushroom-cluster-6.prefab")) != std::string::npos)
			{
				mushroom2.push_back(ObjectClass);
			}
     		if (buff.find(skCrypt("supply_drop.prefab")) != std::string::npos)
			{
				AirDrop.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("minicopter.entity.prefab")) != std::string::npos)
			{
				MiniCopter.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("car_")) != std::string::npos)
			{
				Carss.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("scraptransporthelicopter")) != std::string::npos)
			{
				ScrapHeli.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("patrolhelicopter")) != std::string::npos)
			{
				PatrolHeli.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("rowboat.prefab")) != std::string::npos)
			{
				Boat.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("rhib.prefab")) != std::string::npos)
			{
				Rhib.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("testridablehorse.prefab")) != std::string::npos)
			{
				Horsee.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("small_stash_deployed.prefab")) != std::string::npos)
			{
				Stash.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_normal.prefab")) != std::string::npos)
			{
				Military.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_elite.prefab")) != std::string::npos)
			{
				Elite.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_normal_2.prefab")) != std::string::npos)
			{
				Loot.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_normal_2_food.prefab")) != std::string::npos)
			{
				Food.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_normal_2_medical.prefab")) != std::string::npos)
			{
				Medical.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_tools.prefab")) != std::string::npos)
			{
				ToolBox.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("autoturret.prefab")) != std::string::npos)
			{
				AutoTurret.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("cupboard.tool.deployed.prefab")) != std::string::npos)
			{
				ToolCupboard.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("wolf.prefab")) != std::string::npos)
			{
				Wolf.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("bear.prefab")) != std::string::npos)
			{
				Bear.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("stag.prefab")) != std::string::npos)
			{
				Stag.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("chicken.prefab")) != std::string::npos)
			{
				Chicken.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("boar.prefab")) != std::string::npos)
			{
				Boar.push_back(ObjectClass);
			}
			if (weapons)
			{
				if (buff.find(skCrypt("rifle.ak")) != std::string::npos)
				{
					RifleAk.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.ak.ice")) != std::string::npos)
				{
					RifleAkIce.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.revolve")) != std::string::npos)
				{
					Revolver.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.python")) != std::string::npos)
				{
					Python.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("bow.hunting")) != std::string::npos)
				{
					HuntingBow.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("bow.compound")) != std::string::npos)
				{
					Compound.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("shotgun.double")) != std::string::npos)
				{
					DoubleShotgun.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.nailgun")) != std::string::npos)
				{
					Nailgun.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("smg.thompson")) != std::string::npos)
				{
					Thompson.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.semiaut")) != std::string::npos)
				{
					pSemi.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.semiauto")) != std::string::npos)
				{
					Semi.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("shotgun.waterp")) != std::string::npos)
				{
					WaterPipe.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("shotgun.spas12")) != std::string::npos)
				{
					Spas12.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.m39")) != std::string::npos)
				{
					M39.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.m92")) != std::string::npos)
				{
					M92.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("smg.mp5")) != std::string::npos)
				{
					MP5.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("smg.2")) != std::string::npos)
				{
					SMG.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("shotgun.pump")) != std::string::npos)
				{
					Pump6.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("lmg.m249")) != std::string::npos)
				{
					M249.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.l96")) != std::string::npos)
				{
					L96.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.bolt")) != std::string::npos)
				{
					Bolt.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("lmg.hmlmg")) != std::string::npos)
				{
					Hmlmg.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.eoka")) != std::string::npos)
				{
					Eoka.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("multiplegrenad")) != std::string::npos)
				{
					Multiplegrenad.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rocket.launche")) != std::string::npos)
				{
					RocketLauncher.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.lr300")) != std::string::npos)
				{
					LR300.push_back(ObjectClass);
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
		enemy_list.clear();
		enemy_listTunnel.clear();
		enemy_listScientist.clear();
		enemy_scarecrow.clear();
		BackPack.clear();
		Corpse.clear();
		StoneOre.clear();
		SulfurOre.clear();
		MetalOre.clear();
		Stone.clear();
		Sulfur.clear();
		Metal.clear();
		Hemp.clear();
		mushroom1.clear();
		mushroom2.clear();
		AirDrop.clear();
		MiniCopter.clear();
		Carss.clear();
		ScrapHeli.clear();
		ScrapHeli.clear();
		PatrolHeli.clear();
		Boat.clear();
		Rhib.clear();
		Horsee.clear();
		Stash.clear();
		Military.clear();
		Elite.clear();
		Loot.clear();
		Food.clear();
		Medical.clear();
		ToolBox.clear();
		AutoTurret.clear();
		ToolCupboard.clear();
		Wolf.clear();
		Bear.clear();
		Stag.clear();
		Chicken.clear();
		Boar.clear();
		if (weapons)
		{
			RifleAk.clear();
			RifleAkIce.clear();
			Revolver.clear();
			Python.clear();
			HuntingBow.clear();
			Compound.clear();
			DoubleShotgun.clear();
			Nailgun.clear();
			Thompson.clear();
			pSemi.clear();
			Semi.clear();
			WaterPipe.clear();
			Spas12.clear();
			M39.clear();
			M92.clear();
			MP5.clear();
			SMG.clear();
			Pump6.clear();
			M249.clear();
			L96.clear();
			Bolt.clear();
			Hmlmg.clear();
			Eoka.clear();
			Multiplegrenad.clear();
			RocketLauncher.clear();
			LR300.clear();
		}
	}
}

void draw()
{
	for (auto Player : enemy_list)
	{
		ESP_Player(Player);
		/*if (AimFov(Player) < aimfovv)
		{
			aimbott(Player);
		}*/
		if (playerinfoo)
		{
			if (AimFov(Player) < 30)
			{
				playerinfo(Player);
			}
		}
	}
	if (tunneldweller)
	{
		for (auto Player : enemy_listTunnel)
		{

			ESP_Scientist(Player, 1);
			//if (ssilent)
			//{
			//	sLocalPlayerHead = LocalPlayer.BasePlayer->Position2();
			//	sTargetBonePos = Player->Position2();
			//	Vector3 sTargetAngles = CalcAngle(sLocalPlayerHead, sTargetBonePos);
			//	Vector2 sAngles; sAngles.x = sTargetAngles.x, sAngles.y = sTargetAngles.y;

			//	if (Predictionn) {
			//		sTargetBonePos = Prediction(sLocalPlayerHead, Player, BoneList(head), sTargetBonePos);
			//	}

			//	if (AimFov(Player) < aimfovv)
			//	{
			//		/*if (ssilent && GetAsyncKeyState(aimkey)) {
			//			auto eyes = driver.read<uintptr_t>((uintptr_t)LocalPlayer.BasePlayer + oPlayerEyes);
			//			Vector4 sQuatAngles = ToQuat({ sAngles.x, sAngles.y, 0.0f });
			//			driver.write<Vector4>(eyes + 0x44, sQuatAngles);
			//		}*/
			//		if (ssilent && GetAsyncKeyState(aimkey)) {
			//			LocalPlayer.BasePlayer->SetVA(sAngles);
			//		}
			//	}
			//}
		}
	}
	if (scarecrow) {
		for (auto Player : enemy_scarecrow)
		{

			ESP_Scientist(Player, 3);
			//if (ssilent)
			//{
			//	sLocalPlayerHead = LocalPlayer.BasePlayer->Position2();
			//	sTargetBonePos = Player->Position2();
			//	Vector3 sTargetAngles = CalcAngle(sLocalPlayerHead, sTargetBonePos);
			//	Vector2 sAngles; sAngles.x = sTargetAngles.x, sAngles.y = sTargetAngles.y;

			//	if (Predictionn) {
			//		sTargetBonePos = Prediction(sLocalPlayerHead, Player, BoneList(head), sTargetBonePos);
			//	}

			//	if (AimFov(Player) < aimfovv)
			//	{
			//		/*	if (ssilent && GetAsyncKeyState(aimkey)) {
			//				auto eyes = driver.read<uintptr_t>((uintptr_t)LocalPlayer.BasePlayer + oPlayerEyes);
			//				Vector4 sQuatAngles = ToQuat({ sAngles.x, sAngles.y, 0.0f });
			//				driver.write<Vector4>(eyes + 0x44, sQuatAngles);
			//			}*/
			//		if (ssilent && GetAsyncKeyState(aimkey)) {
			//			LocalPlayer.BasePlayer->SetVA(sAngles);
			//		}
			//	}
			//}
		}
	}
	if (scientistnpc)
	{
		for (auto Player : enemy_listScientist)
		{

			ESP_Scientist(Player, 2);
			//if (ssilent)
			//{
			//	sLocalPlayerHead = LocalPlayer.BasePlayer->Position2();
			//	sTargetBonePos = Player->Position2();
			//	Vector3 sTargetAngles = CalcAngle(sLocalPlayerHead, sTargetBonePos);
			//	Vector2 sAngles; sAngles.x = sTargetAngles.x, sAngles.y = sTargetAngles.y;

			//	if (Predictionn) {
			//		sTargetBonePos = Prediction(sLocalPlayerHead, Player, BoneList(head), sTargetBonePos);
			//	}

			//	if (AimFov(Player) < aimfovv)
			//	{
			//	/*	if (ssilent && GetAsyncKeyState(aimkey)) {
			//			auto eyes = driver.read<uintptr_t>((uintptr_t)LocalPlayer.BasePlayer + oPlayerEyes);
			//			Vector4 sQuatAngles = ToQuat({ sAngles.x, sAngles.y, 0.0f });
			//			driver.write<Vector4>(eyes + 0x44, sQuatAngles);
			//		}*/
			//		if (ssilent && GetAsyncKeyState(aimkey)) {
			//			LocalPlayer.BasePlayer->SetVA(sAngles);
			//		}
			//	}
			//}
		}
	}
	if (backpack)
	{
		for (auto Player : BackPack)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Backpack"), backpackcolor);
		}
	}
	if (playercorpse)
	{
		for (auto Player : Corpse)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Corpse"), playercorpsecolor);
		}
	}
	if (stone)
	{
		for (auto Player : StoneOre)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Stone Ore"), stonecolor);
		}
	}
	if (sulfur)
	{
		for (auto Player : SulfurOre)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Sulfur Ore"), sulfurcolor);
		}
	}
	if (metal)
	{
		for (auto Player : MetalOre)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Metal Ore"), metalcolor);
		}
	}
	if (stone2)
	{
		for (auto Player : Stone)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Stone"), stone2color);
		}
	}
	if (sulfur2)
	{
		for (auto Player : Sulfur)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Sulfur"), sulfur2color);
		}
	}
	if (metal2)
	{
		for (auto Player : Metal)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Metal"), metal2color);
		}
	}
	if (hemp)
	{
		for (auto Player : Hemp)
		{
			ESP_ResourceL(Player, true, 300, skCrypt(L"Hemp"), hempcolor);
		}
	}
	if (mushroom)
	{
		for (auto Player : mushroom1)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Mushroom"), mushroomcolor);
		}
	}
	if (mushroom)
	{
		for (auto Player : mushroom2)
		{

			ESP_ResourceL(Player, true, 300, skCrypt(L"Mushroom"), mushroomcolor);
		}
	}
	if (airdrop)
	{
		for (auto Player : AirDrop)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Airdrop"), airdropcolor);
		}
	}
	if (minicopter)
	{
		for (auto Player : MiniCopter)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Minicopter"), minicoptercolor);
		}
	}
	if (cars)
	{
		for (auto Player : Carss)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Car"), carscolor);
		}
	}
	if (scrapheli)
	{
		for (auto Player : ScrapHeli)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Scrap Heli"), scraphelicolor);
		}
	}
	if (patrolheli)
	{
		for (auto Player : PatrolHeli)
		{
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Patrol Heli"), patrolhelicolor);
		}
	}
	if (boat)
	{
		for (auto Player : Boat)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Boat"), boatcolor);
		}
	}
	if (rhib)
	{
		for (auto Player : Rhib)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Rhib"), rhibcolor);
		}
	}
	if (stash)
	{
		for (auto Player : Stash)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Stash"), stashcolor);
		}
	}
	if (military)
	{
		for (auto Player : Military)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Military Crate"), militarycolor);
		}
	}
	if (elite)
	{
		for (auto Player : Elite)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Elite Crate"), elitecolor);
		}
	}
	if (loot)
	{
		for (auto Player : Loot)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Loot Crate"), lootcolor);
		}
	}
	if (food)
	{
		for (auto Player : Food)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Food Crate"), foodcolor);
		}
	}
	if (medical)
	{
		for (auto Player : Medical)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Medical Crate"), medicalcolor);
		}
	}
	if (toolbox)
	{
		for (auto Player : ToolBox)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Tool Crate"), toolboxcolor);
		}
	}
	if (autoturret)
	{
		for (auto Player : AutoTurret)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Auto Turret"), autoturretcolor);
		}
	}
	if (toolcupboard)
	{
		for (auto Player : ToolCupboard)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Tool Cupboard"), toolcupboardcolor);
		}
	}
	if (wolf)
	{
	for (auto Player : Wolf)
	{
	
		ESP_ResourceL(Player, true, 50000, skCrypt(L"Wolf"), wolfcolor);
		}
	}
	if (bear)
	{
	for (auto Player : Bear)
	{
	
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Bear"), bearcolor);
		}
	}
	if (stag)
	{
	for (auto Player : Stag)
	{
	
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Stag"), stagcolor);
		}
	}
	if (chicken)
	{
	for (auto Player : Chicken)
	{
	
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Chicken"), chickencolor);
		}
	}
	if (boar)
	{
		for (auto Player : Boar)
		{
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Boar"), boarcolor);
		}
	}
	if (horse)
	{
		for (auto Player : Horsee)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Horse"), horsecolor);
		}
	}
	if (weapons)
	{
		for (auto Player : RifleAk)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"AK-47"), weaponscolor);

		}
		for (auto Player : RifleAkIce)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"AK-47"), weaponscolor);

		}
		for (auto Player : Revolver)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Revolver"), weaponscolor);

		}
		for (auto Player : Python)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Python"), weaponscolor);

		}
		for (auto Player : HuntingBow)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Hunting Bow"), weaponscolor);

		}
		for (auto Player : Compound)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Compound Bow"), weaponscolor);

		}
		for (auto Player : DoubleShotgun)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Double Barrel"), weaponscolor);

		}
		for (auto Player : Nailgun)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Nailgun"), weaponscolor);

		}
		for (auto Player : Thompson)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Thompson"), weaponscolor);

		}
		for (auto Player : pSemi)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Pistol Semiauto"), weaponscolor);

		}
		for (auto Player : Semi)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Rifle Semiauto"), weaponscolor);

		}
		for (auto Player : WaterPipe)
		{
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Waterpipe Shotgun"), weaponscolor);

		}
		for (auto Player : Spas12)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Spas12 Shotgun"), weaponscolor);

		}
		for (auto Player : M39)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"M39"), weaponscolor);

		}
		for (auto Player : M92)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"M92 Pistol"), weaponscolor);

		}
		for (auto Player : MP5)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"MP5A4"), weaponscolor);

		}
		for (auto Player : SMG)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"SMG"), weaponscolor);

		}
		for (auto Player : Pump6)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Pump Shotgun"), weaponscolor);

		}
		for (auto Player : M249)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"M249"), weaponscolor);

		}
		for (auto Player : L96)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"L96 Rifle"), weaponscolor);

		}
		for (auto Player : Bolt)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"Bolt Rifle"), weaponscolor);

		}
		for (auto Player : Hmlmg)
		{

			ESP_ResourceL(Player, true, 50000, skCrypt(L"HMLMG"), weaponscolor);

		}
		for (auto Player : Eoka)
		{
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Eoka"), weaponscolor);

		}
		for (auto Player : Multiplegrenad)
		{
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Grenade Launcher"), weaponscolor);
		}
		for (auto Player : RocketLauncher)
		{
			ESP_ResourceL(Player, true, 50000, skCrypt(L"Rocket Launcher"), weaponscolor);
		}
		for (auto Player : LR300)
		{
			ESP_ResourceL(Player, true, 50000, skCrypt(L"LR300 Rifle"), weaponscolor);
		}
	}
}

int g_menuKeyBind = VK_INSERT;

void stylemenu2()
{
	ImGuiStyle& style = ImGui::GetStyle();
	//style.WindowRounding = 5.0f;
	//style.WindowBorderSize = 2.0f;

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.85f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.17f, 0.17f, 0.17f, 0.85f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);


	style.WindowPadding = ImVec2(8.00f, 8.00f);
	style.FramePadding = ImVec2(5.00f, 2.00f);
	style.CellPadding = ImVec2(6.00f, 6.00f);
	//style.ItemSpacing = ImVec2(6.00f, 6.00f);
	style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 25;
	style.ScrollbarSize = 15;
	style.GrabMinSize = 10;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	style.FrameBorderSize = 1;
	style.TabBorderSize = 1;
	style.WindowRounding = 7;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.GrabRounding = 3;
	style.LogSliderDeadzone = 4;
	style.TabRounding = 4;
}

D3DCOLOR FLOAT4TOD3DCOLOR(float Col[])
{
	ImU32 col32_no_alpha = ImGui::ColorConvertFloat4ToU32(ImVec4(Col[0], Col[1], Col[2], Col[3]));
	float a = (col32_no_alpha >> 24) & 255;
	float r = (col32_no_alpha >> 16) & 255;
	float g = (col32_no_alpha >> 8) & 255;
	float b = col32_no_alpha & 255;
	return D3DCOLOR_ARGB((int)a, (int)r, (int)g, (int)b);
}

namespace Screen
{
	static int Width = GetSystemMetrics(SM_CXSCREEN);
	static int Height = GetSystemMetrics(SM_CYSCREEN);
}

namespace Colors
{
	float CrosshairColors[] = { 255.f, 55.f, 55.f, 255.f };
}


namespace crosshair
{
	namespace sizes
	{

		namespace cross
		{
			float length = 4.0f;
			float gap = 1.0f;
		}


	}
}
void Crosshair()
{
	auto RGB = ImGui::GetColorU32({ 255, 255, 255, 255 });
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 + crosshair::sizes::cross::gap + 1, GetWindowSize().y / 2 - 1), ImVec2(GetWindowSize().x / 2 + crosshair::sizes::cross::length + crosshair::sizes::cross::gap + 1, GetWindowSize().y / 2 + 1), cRainbow);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 - crosshair::sizes::cross::gap - 1, GetWindowSize().y / 2 + 1), ImVec2(GetWindowSize().x / 2 - crosshair::sizes::cross::length - crosshair::sizes::cross::gap - 1, GetWindowSize().y / 2 - 1), cRainbow);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 - 1, GetWindowSize().y / 2 + crosshair::sizes::cross::gap + 1), ImVec2(GetWindowSize().x / 2 + 1, GetWindowSize().y / 2 + crosshair::sizes::cross::length + crosshair::sizes::cross::gap + 1), cRainbow);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 + 1, GetWindowSize().y / 2 - crosshair::sizes::cross::gap - 1), ImVec2(GetWindowSize().x / 2 - 1, GetWindowSize().y / 2 - crosshair::sizes::cross::length - crosshair::sizes::cross::gap - 1), cRainbow);
}
int tab = 1;


void draw_menu()
{
	auto s = ImVec2{}, p = ImVec2{}, gs = ImVec2{ 620, 485 };
	ImGui::SetNextWindowSize(ImVec2(gs));
	ImGui::SetNextWindowBgAlpha(1.0f);
	ImGui::Begin(skCrypt("Steam"), NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_::ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);
	{
	
		ImGui::SetCursorPosX(121);
		s = ImVec2(ImGui::GetWindowSize().x - ImGui::GetStyle().WindowPadding.x * 2, ImGui::GetWindowSize().y - ImGui::GetStyle().WindowPadding.y * 2); p = ImVec2(ImGui::GetWindowPos().x + ImGui::GetStyle().WindowPadding.x, ImGui::GetWindowPos().y + ImGui::GetStyle().WindowPadding.y); auto draw = ImGui::GetWindowDrawList();
		draw->AddRectFilled(p, ImVec2(p.x + s.x, p.y + s.y), ImColor(15, 17, 19), 5);
		draw->AddRectFilled(ImVec2(p.x, p.y + 40), ImVec2(p.x + s.x, p.y + s.y), ImColor(18, 20, 21), 5, ImDrawCornerFlags_Bot);

		ImGui::PushFont(icons);
		auto logo_size = ImGui::CalcTextSize(skCrypt("A"));
		draw->AddText(ImVec2(p.x + 28 - logo_size.x / 2, p.y + 29 - (logo_size.y / 2) + 4), cRainbow, skCrypt("A"));
		ImGui::PopFont();

		ImGui::PushFont(main_font2);
		auto logo_size2 = ImGui::CalcTextSize(skCrypt("A"));
		draw->AddText(ImVec2(p.x + 42 - logo_size2.x / 2, p.y + 29 - logo_size2.y), cRainbow, skCrypt("AlienCheats"));
		ImGui::PopFont();
		ImGui::PushFont(main_font);
		draw->AddText(ImVec2(p.x + 42 - logo_size2.x / 2, p.y + 40 - logo_size2.y), cRainbow, "(PRIVATE)");
		ImGui::PopFont();

		ImGui::PushFont(main_font);
		ImGui::BeginGroup();
		ImGui::SameLine(60);
		if (ImGui::tab(skCrypt("AIMBOT"), tab == 1))tab = 1; ImGui::SameLine();
		if (ImGui::tab(skCrypt("ESP"), tab == 2))tab = 2; ImGui::SameLine();
		if (ImGui::tab(skCrypt("Visuals"), tab == 3))tab = 3; ImGui::SameLine();
		if (ImGui::tab(skCrypt("Misc"), tab == 4))tab = 4; ImGui::SameLine();
		if (ImGui::tab(skCrypt("Settings"), tab == 5))tab = 5;
		ImGui::EndGroup();
		ImGui::PopFont();

		if (tab == 1)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("Aimbot"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Aim Bot"), &aimbot); 
					ImGui::Text(skCrypt("")); ImGui::SameLine(8); HotkeyButton(aimkey, ChangeKey, keystatus); ImGui::SameLine(); ImGui::Text(skCrypt("Aimbot Key"));
					ImGui::Checkbox(skCrypt("Silent"), &silent);
					//ImGui::Checkbox(skCrypt("Patrolhelicopter Silent"), &psilent);
					ImGui::Checkbox(skCrypt("Silent Line"), &silentline);
					ImGui::Checkbox(skCrypt("Scientist Aimbot"), &ssilent);
					ImGui::Checkbox(skCrypt("Prediction"), &Predictionn);
					ImGui::SliderFloat(skCrypt("Fov"), &aimfovv, 1, 360, "% .2f");
					ImGui::SliderFloat(skCrypt("Smooth"), &aimsmooth, 1, 10, "% .2f");
					ImGui::Checkbox(skCrypt("Sleeper Ignore"), &sleeperignore);
					ImGui::Checkbox(skCrypt("Team Ignore"), &teamignoree);
					ImGui::Checkbox(skCrypt("Wounded Ignore"), &woundedignore);
					ImGui::Checkbox(skCrypt("Visible Check"), &visiblecheck);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("Weapon"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("No Recoil"), &norecoil);
					ImGui::Checkbox(skCrypt("No Spread"), &nospread);
					ImGui::Checkbox(skCrypt("Fat Bullet"), &fat_bullet_checkbox);
					ImGui::Checkbox(skCrypt("Automatic"), &full_automatic_checkbox);
					ImGui::Checkbox(skCrypt("No Sway"), &nosway);
					ImGui::Checkbox(skCrypt("Super Eoka"), &super_eoka_checkbox);
					ImGui::Checkbox(skCrypt("Super Meele"), &supermeele);
					ImGui::Checkbox(skCrypt("Shotgun No Spread"), &noshotgunspread);
					ImGui::Checkbox(skCrypt("Super Compound Bow"), &instantCompound);
					ImGui::Checkbox(skCrypt("Zoom"), &zoom);
					ImGui::Checkbox(skCrypt("ADS Hide"), &ADS_Hide);
					ImGui::Checkbox(skCrypt("Crosshair"), &cross);
					ImGui::Checkbox(skCrypt("InstaBow"), &instabow);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
				ImGui::PopFont();
			}
		}
		if (tab == 2)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("PLAYER esp"), ImVec2(285, 415), false);
				{
					ImGui::SetCursorPos({ 120,35 }); ImGui::ColorEdit4("2D Box Color", (float*)&box2color, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,35 });
					ImGui::Checkbox(skCrypt("2D Box"), &box2); 
					if (box2)
					{
						box = false;
						box3 = false;
					}
					ImGui::SetCursorPos({ 120,60 }); ImGui::ColorEdit4("3D Box Color", (float*)&box3color, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,60 });
					ImGui::Checkbox(skCrypt("3D Box"), &box3);
					if (box3)
					{
						box = false;
						box2 = false;
					}
					ImGui::SetCursorPos({ 120,85 }); ImGui::ColorEdit4("Corner Box Color", (float*)&boxcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,85 });
					ImGui::Checkbox(skCrypt("Corner Box"), &box);	
					if (box)
					{
						box2 = false;
						box3 = false;
					}
					ImGui::SetCursorPos({ 120,110 }); ImGui::ColorEdit4("Skeleton Color", (float*)&skeletoncolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,110 });
					ImGui::Checkbox(skCrypt("Skeleton"), &skeleton);
					ImGui::SetCursorPos({ 120,135 }); ImGui::ColorEdit4("Name Color", (float*)&namecolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,135 });
					ImGui::Checkbox(skCrypt("Name Tag"), &name);
					ImGui::SetCursorPos({ 120,160 }); ImGui::ColorEdit4("Fill Box Color", (float*)&paintinsidecolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,160 });
					ImGui::Checkbox(skCrypt("Fill Box"), &paintinside);
					ImGui::SetCursorPos({ 0,185 });
					ImGui::Checkbox(skCrypt("Health Bar Style 1"), &healthbar); 
					if (healthbar)
					{
						healthbar2 = false;
					}
					ImGui::SetCursorPos({ 0,210 });
					ImGui::Checkbox(skCrypt("Health Bar Style 2"), &healthbar2); 
					if (healthbar2)
					{
						healthbar = false;
					}
					ImGui::SetCursorPos({ 120,235 }); ImGui::ColorEdit4("Snapline Color", (float*)&snaplinecolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,235 });
					ImGui::Checkbox(skCrypt("Snapline"), &snapline);
					ImGui::SetCursorPos({ 120,260 }); ImGui::ColorEdit4("Hand Weapon Color", (float*)&handweaponcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,260 });
					ImGui::Checkbox(skCrypt("Weapon Info"), &handweapon);
					ImGui::SetCursorPos({ 0,285 });
					ImGui::Checkbox(skCrypt("Player info"), &playerinfoo); 
					ImGui::SetCursorPos({ 0,310 });
					ImGui::Checkbox(skCrypt("Sleep Ignore"), &sleeper);
					ImGui::SetCursorPos({ 0,335 });
					ImGui::Checkbox(skCrypt("Team Ignore"), &teamignore);
					ImGui::SetCursorPos({ 120,360 }); ImGui::ColorEdit4("Wounded Alert Color", (float*)&WoundedAlertColor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,360 });
					ImGui::Checkbox(skCrypt("Wounded Alert"), &WoundedAlert);
					//ImGui::Checkbox(skCrypt("esp Visible Check"), &espvisiblecheck);
					ImGui::SetCursorPos({ 120,385 }); ImGui::ColorEdit4("Player Corpse Color", (float*)&playercorpsecolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,385 });
					ImGui::Checkbox(skCrypt("Player Corpse"), &playercorpse);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("MISC ESP"), ImVec2(285, 415), false);
				{
					ImGui::SetCursorPos({ 120,35 }); ImGui::ColorEdit4("Wolf Color", (float*)&wolfcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,35 });
					ImGui::Checkbox(skCrypt("Wolf"), &wolf);
					ImGui::SetCursorPos({ 120,60 }); ImGui::ColorEdit4("Bear Color", (float*)&bearcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,60 });
					ImGui::Checkbox(skCrypt("Bear"), &bear);
					ImGui::SetCursorPos({ 120,85 }); ImGui::ColorEdit4("Stag Color", (float*)&stagcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,85 });
					ImGui::Checkbox(skCrypt("Stag"), &stag);
					ImGui::SetCursorPos({ 120,110 }); ImGui::ColorEdit4("Chicken Color", (float*)&chickencolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,110 });
					ImGui::Checkbox(skCrypt("Chicken"), &chicken);
					ImGui::SetCursorPos({ 120,135 }); ImGui::ColorEdit4("Boar Color", (float*)&boarcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,135 });
					ImGui::Checkbox(skCrypt("Boar"), &boar);
					ImGui::SetCursorPos({ 120,160 }); ImGui::ColorEdit4("Horse Color", (float*)&horsecolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,160 });
					ImGui::Checkbox(skCrypt("Horse"), &horse);
					ImGui::SetCursorPos({ 0,180 });
					ImGui::Separator();
					ImGui::SetCursorPos({ 120,185 }); ImGui::ColorEdit4("Weapons Color", (float*)&weaponscolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,185 });
					ImGui::Checkbox(skCrypt("Weapons"), &weapons);
					ImGui::SetCursorPos({ 120,210 }); ImGui::ColorEdit4("ShowDistance Color", (float*)&showdistanceecolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,210 });
					ImGui::Checkbox(skCrypt("Show Distance"), &showdistancee);	
					ImGui::SetCursorPos({ 0,230 });
					ImGui::Separator();
					ImGui::SetCursorPos({ 120,235 }); ImGui::ColorEdit4("NPC Names Color", (float*)&NPCNamescolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,235 });
					ImGui::Checkbox(skCrypt("NPC Names"), &NPCNames);
					ImGui::SetCursorPos({ 120,260 }); ImGui::ColorEdit4("Tunnel Dweller Color", (float*)&tunneldwellerscolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,260 });
					ImGui::Checkbox(skCrypt("Tunnel Dweller"), &tunneldweller);
					ImGui::SetCursorPos({ 120,285 }); ImGui::ColorEdit4("Scientist Color", (float*)&scientistnpccolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,285 });
					ImGui::Checkbox(skCrypt("Scientist NPC"), &scientistnpc);
					ImGui::SetCursorPos({ 120,310 }); ImGui::ColorEdit4("Scarecrow Color", (float*)&scarecrowcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,310 });
					ImGui::Checkbox(skCrypt("Scarecrow"), &scarecrow);
					ImGui::SetCursorPos({ 0,330 });
					ImGui::Separator();
					ImGui::SetCursorPos({ 120,335 }); ImGui::ColorEdit4("Airdrop Color", (float*)&airdropcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,335 });
					ImGui::Checkbox(skCrypt("Airdrop"), &airdrop);
					ImGui::SetCursorPos({ 120,360 }); ImGui::ColorEdit4("Stash Color", (float*)&stashcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,360 });
					ImGui::Checkbox(skCrypt("Stash"), &stash);
					ImGui::SetCursorPos({ 0,380 });
					ImGui::Separator();
					ImGui::SetCursorPos({ 120,385 }); ImGui::ColorEdit4("BackPack Color", (float*)&backpackcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,385 });
					ImGui::Checkbox(skCrypt("Backpack"), &backpack);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
		if (tab == 3)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("RESOURCES"), ImVec2(285, 415), false);
				{
					ImGui::SetCursorPos({ 120,35 }); ImGui::ColorEdit4("Stone Ore Color", (float*)&stonecolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,35 });
					ImGui::Checkbox(skCrypt("Stone Ore"), &stone);
					ImGui::SetCursorPos({ 120,60 }); ImGui::ColorEdit4("Stone Color", (float*)&stone2color, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,60 });
					ImGui::Checkbox(skCrypt("Stone"), &stone2);
					ImGui::SetCursorPos({ 120,85 }); ImGui::ColorEdit4("Sulfur Ore Color", (float*)&sulfurcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,85 });
					ImGui::Checkbox(skCrypt("Sulfur Ore"), &sulfur);
					ImGui::SetCursorPos({ 120,110 }); ImGui::ColorEdit4("Sulfur Color", (float*)&sulfur2color, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,110 });
					ImGui::Checkbox(skCrypt("Sulfur"), &sulfur2);
					ImGui::SetCursorPos({ 120,135 }); ImGui::ColorEdit4("Metal Ore Color", (float*)&metalcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,135 });
					ImGui::Checkbox(skCrypt("Metal Ore"), &metal);
					ImGui::SetCursorPos({ 120,160 }); ImGui::ColorEdit4("Metal Color", (float*)&metal2color, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,160 });
					ImGui::Checkbox(skCrypt("Metal"), &metal2);
					ImGui::SetCursorPos({ 120,185 }); ImGui::ColorEdit4("Mushroom Color", (float*)&mushroomcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,185 });
					ImGui::Checkbox(skCrypt("Mushroom"), &mushroom);
					ImGui::SetCursorPos({ 120,210 }); ImGui::ColorEdit4("Hemp Color", (float*)&hempcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,210 });
					ImGui::Checkbox(skCrypt("Hemp"), &hemp);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("LOOTS & VEHICLES"), ImVec2(285, 415), false);
				{
					ImGui::SetCursorPos({ 120,35 }); ImGui::ColorEdit4("Military Color", (float*)&militarycolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,35 });
					ImGui::Checkbox(skCrypt("military crate"), &military);
					ImGui::SetCursorPos({ 120,60 }); ImGui::ColorEdit4("Elite Color", (float*)&elitecolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,60 });
					ImGui::Checkbox(skCrypt("elite crate"), &elite);
					ImGui::SetCursorPos({ 120,85 }); ImGui::ColorEdit4("Loot Color", (float*)&lootcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,85 });
					ImGui::Checkbox(skCrypt("loot crate"), &loot);
					ImGui::SetCursorPos({ 120,110 }); ImGui::ColorEdit4("Food Color", (float*)&foodcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,110 });
					ImGui::Checkbox(skCrypt("food crate"), &food);
					ImGui::SetCursorPos({ 120,135 }); ImGui::ColorEdit4("Medical Color", (float*)&medicalcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,135 });
					ImGui::Checkbox(skCrypt("medical crate"), &medical);
					ImGui::SetCursorPos({ 120,160 }); ImGui::ColorEdit4("Toolbox Color", (float*)&toolboxcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,160 });
					ImGui::Checkbox(skCrypt("toolbox crate"), &toolbox);
					ImGui::SetCursorPos({ 0,180 });
					ImGui::Separator();
					ImGui::SetCursorPos({ 120,185 }); ImGui::ColorEdit4("Minicopter Color", (float*)&minicoptercolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,185 });
					ImGui::Checkbox(skCrypt("Minicopter"), &minicopter);
					ImGui::SetCursorPos({ 120,210 }); ImGui::ColorEdit4("Scrap Heli Color", (float*)&scraphelicolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,210 });
					ImGui::Checkbox(skCrypt("Scrap Heli"), &scrapheli);
					ImGui::SetCursorPos({ 120,235 }); ImGui::ColorEdit4("Patrol Heli Color", (float*)&patrolhelicolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,235 });
					ImGui::Checkbox(skCrypt("Patrol Heli"), &patrolheli);
					ImGui::SetCursorPos({ 120,260 }); ImGui::ColorEdit4("Boat Color", (float*)&boatcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,260 });
					ImGui::Checkbox(skCrypt("Boat"), &boat);
					ImGui::SetCursorPos({ 120,285 }); ImGui::ColorEdit4("Rhib Color", (float*)&rhibcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,285 });
					ImGui::Checkbox(skCrypt("Rhib"), &rhib);
					ImGui::SetCursorPos({ 120,310 }); ImGui::ColorEdit4("Cars Color", (float*)&carscolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,310 });
					ImGui::Checkbox(skCrypt("Cars"), &cars);
					ImGui::SetCursorPos({ 0,330 });
					ImGui::Separator();
					ImGui::SetCursorPos({ 120,335 }); ImGui::ColorEdit4("Auto Turret Color", (float*)&autoturretcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,335 });
					ImGui::Checkbox(skCrypt("Auto Turret"), &autoturret);
					ImGui::SetCursorPos({ 120,360 }); ImGui::ColorEdit4("Toolcupboard Color", (float*)&toolcupboardcolor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); ImGui::SetCursorPos({ 0,360 });
					ImGui::Checkbox(skCrypt("Tool Cupboard"), &toolcupboard);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
		if (tab == 4)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("Functions"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Admin Flag"), &admin_flag_checkboxx);
					ImGui::Checkbox(skCrypt("Graphic Fov"), &fov);
					ImGui::Checkbox(skCrypt("FakeWorkbench"), &fakeworkbench);
					ImGui::Checkbox(skCrypt("ThirdPerson"), &thirdperson);
					ImGui::Checkbox(skCrypt("Instantly Suicide"), &suicide);
					ImGui::Checkbox(skCrypt("Time Changer"), &alwaysday);
					ImGui::Checkbox(skCrypt("Brightness"), &nighttmode);
					ImGui::Checkbox(skCrypt("Old Box ESP"), &AdminEsp);
					ImGui::Checkbox(skCrypt("Fake Lag"), &fakelag);
					ImGui::Checkbox(skCrypt("Spin Bot"), &spinbot);
					ImGui::Checkbox(skCrypt("HardCoreMode Map"), &hardcoremodeMap);
					ImGui::Checkbox(skCrypt("Camera [PGUP] [PGDOWN] [ARROW KEYS]"), &cameraaa);
					ImGui::Checkbox(skCrypt("Chams"), &chams);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("MISC"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Spiderman"), &spiderman);
					ImGui::Checkbox(skCrypt("Fly Hack [F]"), &flyhack);
					ImGui::Checkbox(skCrypt("Infinity Jump"), &infinitejump);
					ImGui::Checkbox(skCrypt("Timer [MB3]"), &timer);
					ImGui::Checkbox(skCrypt("Gravity"), &gravity);
					ImGui::Checkbox(skCrypt("Walk On Water [Z]"), &WalkOnWater);
					ImGui::Checkbox(skCrypt("Jump Shot"), &jumpshot);
					ImGui::Checkbox(skCrypt("Fly Bypass [X]"), &climb);	
					ImGui::Checkbox(skCrypt("Long Neck"), &longneck);
					ImGui::Checkbox(skCrypt("Speed Hack [MB4]"), &SPEEDhack);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
		if (tab == 5)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("Values"), ImVec2(285, 415), false);
				{
					ImGui::SliderFloat(skCrypt("Gravity Distance"), &gravity_distancee, 1, 5, "% .2f");
					ImGui::SliderFloat(skCrypt("Fov Value"), &FOVV, 90, 150, "% .2f");
					ImGui::SliderFloat(skCrypt("Speed Value"), &speedBonus, 0, 1, "% .3f");
					ImGui::SliderFloat(skCrypt("FlyHack Speed Value"), &flyhackspeed, 0, 1, "% .3f");
					ImGui::SliderFloat(skCrypt("Timer Value"), &timervalue, 1, 8, "% .2f");
					ImGui::SliderFloat(skCrypt("Time Value"), &timee, 0, 24, "% .2f");
					ImGui::SliderFloat(skCrypt("Light Value"), &light, 0, 5, "% .2f");
					ImGui::SliderFloat(skCrypt("Crosshair Length"), &crosshair::sizes::cross::length, 1, 15, "% .2f");
                    ImGui::SliderFloat(skCrypt("Crosshair Gap"), &crosshair::sizes::cross::gap, 1, 15, "% .2f");
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("Config"), ImVec2(285, 415), false);
				{
					//if (ImGui::Button(_xor_("Rage Config ").c_str())) { /*sayfa1*/ aimkey = VK_LBUTTON; silent = true; Predictionn = true; aimfovv = 90; sleeperignore = true; teamignoree = true; /*sayfa2*/ box3 = true; snapline = false; teamignore = true; name = true; healthbar = true; handweapon = true; sleeper = true; paintinside = false; weapons = true; playerinfoo = true; /*sayfa3*/ airdrop = true; minicopter = true; scrapheli = true; /*sayfa4*/ norecoil = true; nospread = true; fat_bullet_checkbox = true; full_automatic_checkbox = true; nosway = true; super_eoka_checkbox = true; supermeele = true; noshotgunspread = true; instantCompound = true; cross = true; instabow = true; spiderman = true; flyhack = true; timer = true; climb = true; /*sayfa5*/ spinbot = true; fov = true; alwaysday = true; FOVV = 110; WoundedAlert = true; showdistancee = true; visiblecheck = true; }
					//if (ImGui::Button(_xor_("Legit Config").c_str())) { /*sayfa1*/  /*sayfa2*/ WoundedAlert = true; box3 = true; snapline = false; teamignore = true; name = true; healthbar = true; handweapon = true; sleeper = true; paintinside = false; weapons = true; playerinfoo = true; /*sayfa3*/ airdrop = true; minicopter = true; scrapheli = true; /*sayfa4*/ norecoil = true; full_automatic_checkbox = true; nosway = true; instantCompound = true; cross = true; instabow = true; spiderman = true;/*sayfa5*/ fov = true; alwaysday = true; FOVV = 110; showdistancee = true; }
					//if (ImGui::Button(_xor_("Zero Config").c_str())) { /*sayfa1*/ aimbot = false; silent = false; silentline = false; ssilent = false; Predictionn = false;  sleeperignore = false; teamignoree = false; woundedignore = false;/*sayfa2*/box3 = false; box = false; snapline = false; name = false; box2 = false; healthbar = false; chams = false; skeleton = false; playercorpse = false; handweapon = false; backpack = false; sleeper = false; teamignore = false; playerinfoo = false; paintinside = false; wolf = false; bear = false; stag = false; chicken = false; boar = false; horse = false; weapons = false; showdistancee = false;  tunneldweller = false; scientistnpc = false; /*sayfa3*/ stone = false; stone2 = false; sulfur = false; sulfur2 = false; metal = false; metal2 = false; mushroom = false; hemp = false; military = false;  elite = false; loot = false; food = false; medical = false; toolbox = false; airdrop = false; stash = false; minicopter = false;  scrapheli = false; patrolheli = false; boat = false; rhib = false;  toolcupboard = false; autoturret = false; cars = false; /*sayfa4*/ norecoil = false; nospread = false; fat_bullet_checkbox = false; full_automatic_checkbox = false; nosway = false; super_eoka_checkbox = false; supermeele = false; noshotgunspread = false; instantCompound = false; zoom = false; ADS_Hide = false; cross = false; instabow = false; spiderman = false; flyhack = false; infinitejump = false; timer = false; gravity = false;  WalkOnWater = false; jumpshot = false;  climb = false; longneck = false;  SPEEDhack = false; /*sayfa5*/ admin_flag_checkboxx = false; fov = false; fakeworkbench = false; thirdperson = false; suicide = false;  alwaysday = false; nighttmode = false; AdminEsp = false;  fakelag = false;  spinbot = false; hardcoremodeMap = false;  WoundedAlert = false; visiblecheck = false; espvisiblecheck = false; }
					ImGui::SetCursorPos({ 0,35 });
					if (ImGui::Button("CONFIG SAVE"))
					{
						system("mkdir C:\\AlienCheatsCONFIG");
						Sleep(5);
						std::ofstream dosyaYaz1("C:\\AlienCheatsCONFIG\\aimbot.txt");
						dosyaYaz1.is_open();
						if (aimbot)
							dosyaYaz1 << "aimbot = true";
						else
							dosyaYaz1 << "aimbot = false";
						dosyaYaz1.close();
						//
						std::ofstream dosyaYaz2("C:\\AlienCheatsCONFIG\\silent.txt");
						dosyaYaz2.is_open();
						if (silent)
							dosyaYaz2 << "silent = true";
						else
							dosyaYaz2 << "silent = false";
						dosyaYaz2.close();
						//
						std::ofstream dosyaYaz3("C:\\AlienCheatsCONFIG\\silentline.txt");
						dosyaYaz3.is_open();
						if (silentline)
							dosyaYaz3 << "silentline = true";
						else
							dosyaYaz3 << "silentline = false";
						dosyaYaz3.close();
						//
						std::ofstream dosyaYaz4("C:\\AlienCheatsCONFIG\\ssilent.txt");
						dosyaYaz4.is_open();
						if (ssilent)
							dosyaYaz4 << "ssilent = true";
						else
							dosyaYaz4 << "ssilent = false";
						dosyaYaz4.close();
						//
						std::ofstream dosyaYaz5("C:\\AlienCheatsCONFIG\\Predictionn.txt");
						dosyaYaz5.is_open();
						if (Predictionn)
							dosyaYaz5 << "Predictionn = true";
						else
							dosyaYaz5 << "Predictionn = false";
						dosyaYaz5.close();
						//
						std::ofstream dosyaYaz6("C:\\AlienCheatsCONFIG\\sleeperignore.txt");
						dosyaYaz6.is_open();
						if (sleeperignore)
							dosyaYaz6 << "sleeperignore = true";
						else
							dosyaYaz6 << "sleeperignore = false";
						dosyaYaz6.close();
						//
						std::ofstream dosyaYaz7("C:\\AlienCheatsCONFIG\\teamignoree.txt");
						dosyaYaz7.is_open();
						if (teamignoree)
							dosyaYaz7 << "teamignoree = true";
						else
							dosyaYaz7 << "teamignoree = false";
						dosyaYaz7.close();
						//
						std::ofstream dosyaYaz8("C:\\AlienCheatsCONFIG\\woundedignore.txt");
						dosyaYaz8.is_open();
						if (woundedignore)
							dosyaYaz8 << "woundedignore = true";
						else
							dosyaYaz8 << "woundedignore = false";
						dosyaYaz8.close();
						//
						std::ofstream dosyaYaz9("C:\\AlienCheatsCONFIG\\visiblecheck.txt");
						dosyaYaz9.is_open();
						if (visiblecheck)
							dosyaYaz9 << "visiblecheck = true";
						else
							dosyaYaz9 << "visiblecheck = false";
						dosyaYaz9.close();
						//
						std::ofstream dosyaYaz10("C:\\AlienCheatsCONFIG\\norecoil.txt");
						dosyaYaz10.is_open();
						if (norecoil)
							dosyaYaz10 << "norecoil = true";
						else
							dosyaYaz10 << "norecoil = false";
						dosyaYaz10.close();
						//
						std::ofstream dosyaYaz11("C:\\AlienCheatsCONFIG\\nospread.txt");
						dosyaYaz11.is_open();
						if (nospread)
							dosyaYaz11 << "nospread = true";
						else
							dosyaYaz11 << "nospread = false";
						dosyaYaz11.close();
						//
						std::ofstream dosyaYaz12("C:\\AlienCheatsCONFIG\\fat_bullet_checkbox.txt");
						dosyaYaz12.is_open();
						if (fat_bullet_checkbox)
							dosyaYaz12 << "fat_bullet_checkbox = true";
						else
							dosyaYaz12 << "fat_bullet_checkbox = false";
						dosyaYaz12.close();
						//
						std::ofstream dosyaYaz13("C:\\AlienCheatsCONFIG\\full_automatic_checkbox.txt");
						dosyaYaz13.is_open();
						if (full_automatic_checkbox)
							dosyaYaz13 << "full_automatic_checkbox = true";
						else
							dosyaYaz13 << "full_automatic_checkbox = false";
						dosyaYaz13.close();
						//
						std::ofstream dosyaYaz14("C:\\AlienCheatsCONFIG\\nosway.txt");
						dosyaYaz14.is_open();
						if (nosway)
							dosyaYaz14 << "nosway = true";
						else
							dosyaYaz14 << "nosway = false";
						dosyaYaz14.close();
						//
						std::ofstream dosyaYaz15("C:\\AlienCheatsCONFIG\\super_eoka_checkbox.txt");
						dosyaYaz15.is_open();
						if (super_eoka_checkbox)
							dosyaYaz15 << "super_eoka_checkbox = true";
						else
							dosyaYaz15 << "super_eoka_checkbox = false";
						dosyaYaz15.close();
						//
						std::ofstream dosyaYaz16("C:\\AlienCheatsCONFIG\\supermeele.txt");
						dosyaYaz16.is_open();
						if (supermeele)
							dosyaYaz16 << "supermeele = true";
						else
							dosyaYaz16 << "supermeele = false";
						dosyaYaz16.close();
						//
						std::ofstream dosyaYaz17("C:\\AlienCheatsCONFIG\\noshotgunspread.txt");
						dosyaYaz17.is_open();
						if (noshotgunspread)
							dosyaYaz17 << "noshotgunspread = true";
						else
							dosyaYaz17 << "noshotgunspread = false";
						dosyaYaz17.close();
						//
						std::ofstream dosyaYaz18("C:\\AlienCheatsCONFIG\\instantCompound.txt");
						dosyaYaz18.is_open();
						if (instantCompound)
							dosyaYaz18 << "instantCompound = true";
						else
							dosyaYaz18 << "instantCompound = false";
						dosyaYaz18.close();
						//
						std::ofstream dosyaYaz19("C:\\AlienCheatsCONFIG\\zoom.txt");
						dosyaYaz19.is_open();
						if (zoom)
							dosyaYaz19 << "zoom = true";
						else
							dosyaYaz19 << "zoom = false";
						dosyaYaz19.close();
						//
						std::ofstream dosyaYaz20("C:\\AlienCheatsCONFIG\\ADS_Hide.txt");
						dosyaYaz20.is_open();
						if (ADS_Hide)
							dosyaYaz20 << "ADS_Hide = true";
						else
							dosyaYaz20 << "ADS_Hide = false";
						dosyaYaz20.close();
						//
						std::ofstream dosyaYaz21("C:\\AlienCheatsCONFIG\\cross.txt");
						dosyaYaz21.is_open();
						if (cross)
							dosyaYaz21 << "cross = true";
						else
							dosyaYaz21 << "cross = false";
						dosyaYaz21.close();
						//
						std::ofstream dosyaYaz22("C:\\AlienCheatsCONFIG\\instabow.txt");
						dosyaYaz22.is_open();
						if (cross)
							dosyaYaz22 << "instabow = true";
						else
							dosyaYaz22 << "instabow = false";
						dosyaYaz22.close();
						//
						std::ofstream dosyaYaz23("C:\\AlienCheatsCONFIG\\box2.txt");
						dosyaYaz23.is_open();
						if (box2)
							dosyaYaz23 << "box2 = true";
						else
							dosyaYaz23 << "box2 = false";
						dosyaYaz23.close();
						//
						std::ofstream dosyaYaz24("C:\\AlienCheatsCONFIG\\box3.txt");
						dosyaYaz24.is_open();
						if (box3)
							dosyaYaz24 << "box3 = true";
						else
							dosyaYaz24 << "box3 = false";
						//
						std::ofstream dosyaYaz25("C:\\AlienCheatsCONFIG\\box.txt");
						dosyaYaz25.is_open();
						if (box)
							dosyaYaz25 << "box = true";
						else
							dosyaYaz25 << "box = false";
						dosyaYaz25.close();
						//
						std::ofstream dosyaYaz26("C:\\AlienCheatsCONFIG\\skeleton.txt");
						dosyaYaz26.is_open();
						if (skeleton)
							dosyaYaz26 << "skeleton = true";
						else
							dosyaYaz26 << "skeleton = false";
						dosyaYaz26.close();
						//
						std::ofstream dosyaYaz27("C:\\AlienCheatsCONFIG\\name.txt");
						dosyaYaz27.is_open();
						if (name)
							dosyaYaz27 << "name = true";
						else
							dosyaYaz27 << "name = false";
						dosyaYaz27.close();
						//
						std::ofstream dosyaYaz28("C:\\AlienCheatsCONFIG\\paintinside.txt");
						dosyaYaz28.is_open();
						if (paintinside)
							dosyaYaz28 << "paintinside = true";
						else
							dosyaYaz28 << "paintinside = false";
						dosyaYaz28.close();
						//
						std::ofstream dosyaYaz29("C:\\AlienCheatsCONFIG\\healthbar.txt");
						dosyaYaz29.is_open();
						if (healthbar)
							dosyaYaz29 << "healthbar = true";
						else
							dosyaYaz29 << "healthbar = false";
						dosyaYaz29.close();
						//
						std::ofstream dosyaYaz30("C:\\AlienCheatsCONFIG\\healthbar2.txt");
						dosyaYaz30.is_open();
						if (healthbar2)
							dosyaYaz30 << "healthbar2 = true";
						else
							dosyaYaz30 << "healthbar2 = false";
						dosyaYaz30.close();
						//
						std::ofstream dosyaYaz31("C:\\AlienCheatsCONFIG\\snapline.txt");
						dosyaYaz31.is_open();
						if (snapline)
							dosyaYaz31 << "snapline = true";
						else
							dosyaYaz31 << "snapline = false";
						dosyaYaz31.close();
						//
						std::ofstream dosyaYaz32("C:\\AlienCheatsCONFIG\\handweapon.txt");
						dosyaYaz32.is_open();
						if (handweapon)
							dosyaYaz32 << "handweapon = true";
						else
							dosyaYaz32 << "handweapon = false";
						dosyaYaz32.close();
						//
						std::ofstream dosyaYaz33("C:\\AlienCheatsCONFIG\\playerinfoo.txt");
						dosyaYaz33.is_open();
						if (playerinfoo)
							dosyaYaz33 << "playerinfoo = true";
						else
							dosyaYaz33 << "playerinfoo = false";
						dosyaYaz33.close();
						//
						std::ofstream dosyaYaz34("C:\\AlienCheatsCONFIG\\sleeper.txt");
						dosyaYaz34.is_open();
						if (sleeper)
							dosyaYaz34 << "sleeper = true";
						else
							dosyaYaz34 << "sleeper = false";
						dosyaYaz34.close();
						//
						std::ofstream dosyaYaz35("C:\\AlienCheatsCONFIG\\teamignore.txt");
						dosyaYaz35.is_open();
						if (teamignore)
							dosyaYaz35 << "teamignore = true";
						else
							dosyaYaz35 << "teamignore = false";
						dosyaYaz35.close();
						//
						std::ofstream dosyaYaz36("C:\\AlienCheatsCONFIG\\WoundedAlert.txt");
						dosyaYaz36.is_open();
						if (teamignore)
							dosyaYaz36 << "WoundedAlert = true";
						else
							dosyaYaz36 << "WoundedAlert = false";
						dosyaYaz36.close();
						//
						std::ofstream dosyaYaz37("C:\\AlienCheatsCONFIG\\playercorpse.txt");
						dosyaYaz37.is_open();
						if (playercorpse)
							dosyaYaz37 << "playercorpse = true";
						else
							dosyaYaz37 << "playercorpse = false";
						dosyaYaz37.close();
						//
						std::ofstream dosyaYaz38("C:\\AlienCheatsCONFIG\\wolf.txt");
						dosyaYaz38.is_open();
						if (wolf)
							dosyaYaz38 << "wolf = true";
						else
							dosyaYaz38 << "wolf = false";
						dosyaYaz38.close();
						//
						std::ofstream dosyaYaz39("C:\\AlienCheatsCONFIG\\bear.txt");
						dosyaYaz39.is_open();
						if (bear)
							dosyaYaz39 << "bear = true";
						else
							dosyaYaz39 << "bear = false";
						dosyaYaz39.close();
						//
						std::ofstream dosyaYaz40("C:\\AlienCheatsCONFIG\\stag.txt");
						dosyaYaz40.is_open();
						if (stag)
							dosyaYaz40 << "stag = true";
						else
							dosyaYaz40 << "stag = false";
						dosyaYaz40.close();
						//
						std::ofstream dosyaYaz41("C:\\AlienCheatsCONFIG\\chicken.txt");
						dosyaYaz41.is_open();
						if (chicken)
							dosyaYaz41 << "chicken = true";
						else
							dosyaYaz41 << "chicken = false";
						dosyaYaz41.close();
						//
						std::ofstream dosyaYaz42("C:\\AlienCheatsCONFIG\\boar.txt");
						dosyaYaz42.is_open();
						if (boar)
							dosyaYaz42 << "boar = true";
						else
							dosyaYaz42 << "boar = false";
						dosyaYaz42.close();
						//
						std::ofstream dosyaYaz43("C:\\AlienCheatsCONFIG\\horse.txt");
						dosyaYaz43.is_open();
						if (horse)
							dosyaYaz43 << "horse = true";
						else
							dosyaYaz43 << "horse = false";
						dosyaYaz43.close();
						//
						std::ofstream dosyaYaz44("C:\\AlienCheatsCONFIG\\weapons.txt");
						dosyaYaz44.is_open();
						if (weapons)
							dosyaYaz44 << "weapons = true";
						else
							dosyaYaz44 << "weapons = false";
						dosyaYaz44.close();
						//
						std::ofstream dosyaYaz45("C:\\AlienCheatsCONFIG\\showdistancee.txt");
						dosyaYaz45.is_open();
						if (weapons)
							dosyaYaz45 << "showdistancee = true";
						else
							dosyaYaz45 << "showdistancee = false";
						dosyaYaz45.close();
						//
						std::ofstream dosyaYaz46("C:\\AlienCheatsCONFIG\\NPCNames.txt");
						dosyaYaz46.is_open();
						if (NPCNames)
							dosyaYaz46 << "NPCNames = true";
						else
							dosyaYaz46 << "NPCNames = false";
						dosyaYaz46.close();
						//
						std::ofstream dosyaYaz47("C:\\AlienCheatsCONFIG\\tunneldweller.txt");
						dosyaYaz47.is_open();
						if (tunneldweller)
							dosyaYaz47 << "tunneldweller = true";
						else
							dosyaYaz47 << "tunneldweller = false";
						dosyaYaz47.close();
						//
						std::ofstream dosyaYaz48("C:\\AlienCheatsCONFIG\\scientistnpc.txt");
						dosyaYaz48.is_open();
						if (tunneldweller)
							dosyaYaz48 << "scientistnpc = true";
						else
							dosyaYaz48 << "scientistnpc = false";
						dosyaYaz48.close();
						//
						std::ofstream dosyaYaz49("C:\\AlienCheatsCONFIG\\scarecrow.txt");
						dosyaYaz49.is_open();
						if (tunneldweller)
							dosyaYaz49 << "scarecrow = true";
						else
							dosyaYaz49 << "scarecrow = false";
						dosyaYaz49.close();
						//
						std::ofstream dosyaYaz50("C:\\AlienCheatsCONFIG\\airdrop.txt");
						dosyaYaz50.is_open();
						if (tunneldweller)
							dosyaYaz50 << "airdrop = true";
						else
							dosyaYaz50 << "airdrop = false";
						dosyaYaz50.close();
						//
						std::ofstream dosyaYaz51("C:\\AlienCheatsCONFIG\\stash.txt");
						dosyaYaz51.is_open();
						if (tunneldweller)
							dosyaYaz51 << "stash = true";
						else
							dosyaYaz51 << "stash = false";
						dosyaYaz51.close();
						//
						std::ofstream dosyaYaz52("C:\\AlienCheatsCONFIG\\backpack.txt");
						dosyaYaz52.is_open();
						if (tunneldweller)
							dosyaYaz52 << "backpack = true";
						else
							dosyaYaz52 << "backpack = false";
						dosyaYaz52.close();
						//
						std::ofstream dosyaYaz53("C:\\AlienCheatsCONFIG\\stone.txt");
						dosyaYaz53.is_open();
						if (stone)
							dosyaYaz53 << "stone = true";
						else
							dosyaYaz53 << "stone = false";
						dosyaYaz53.close();
						//
						std::ofstream dosyaYaz54("C:\\AlienCheatsCONFIG\\stone2.txt");
						dosyaYaz54.is_open();
						if (stone2)
							dosyaYaz54 << "stone2 = true";
						else
							dosyaYaz54 << "stone2 = false";
						dosyaYaz54.close();
						//
						std::ofstream dosyaYaz55("C:\\AlienCheatsCONFIG\\sulfur.txt");
						dosyaYaz55.is_open();
						if (sulfur)
							dosyaYaz55 << "sulfur = true";
						else
							dosyaYaz55 << "sulfur = false";
						dosyaYaz55.close();
						//
						std::ofstream dosyaYaz56("C:\\AlienCheatsCONFIG\\sulfur2.txt");
						dosyaYaz56.is_open();
						if (sulfur2)
							dosyaYaz56 << "sulfur2 = true";
						else
							dosyaYaz56 << "sulfur2 = false";
						dosyaYaz56.close();
						//
						std::ofstream dosyaYaz57("C:\\AlienCheatsCONFIG\\metal.txt");
						dosyaYaz57.is_open();
						if (metal)
							dosyaYaz57 << "metal = true";
						else
							dosyaYaz57 << "metal = false";
						dosyaYaz57.close();
						//
						std::ofstream dosyaYaz58("C:\\AlienCheatsCONFIG\\metal2.txt");
						dosyaYaz58.is_open();
						if (metal2)
							dosyaYaz58 << "metal2 = true";
						else
							dosyaYaz58 << "metal2 = false";
						dosyaYaz58.close();
						//
						std::ofstream dosyaYaz59("C:\\AlienCheatsCONFIG\\mushroom.txt");
						dosyaYaz59.is_open();
						if (mushroom)
							dosyaYaz59 << "mushroom = true";
						else
							dosyaYaz59 << "mushroom = false";
						dosyaYaz59.close();
						//
						std::ofstream dosyaYaz60("C:\\AlienCheatsCONFIG\\hemp.txt");
						dosyaYaz60.is_open();
						if (hemp)
							dosyaYaz60 << "hemp = true";
						else
							dosyaYaz60 << "hemp = false";
						dosyaYaz60.close();
						//
						std::ofstream dosyaYaz61("C:\\AlienCheatsCONFIG\\military.txt");
						dosyaYaz61.is_open();
						if (military)
							dosyaYaz61 << "military = true";
						else
							dosyaYaz61 << "military = false";
						dosyaYaz61.close();
						//
						std::ofstream dosyaYaz62("C:\\AlienCheatsCONFIG\\elite.txt");
						dosyaYaz62.is_open();
						if (elite)
							dosyaYaz62 << "elite = true";
						else
							dosyaYaz62 << "elite = false";
						dosyaYaz62.close();
						//
						std::ofstream dosyaYaz63("C:\\AlienCheatsCONFIG\\loot.txt");
						dosyaYaz63.is_open();
						if (loot)
							dosyaYaz63 << "loot = true";
						else
							dosyaYaz63 << "loot = false";
						dosyaYaz63.close();
						//
						std::ofstream dosyaYaz64("C:\\AlienCheatsCONFIG\\food.txt");
						dosyaYaz64.is_open();
						if (food)
							dosyaYaz64 << "food = true";
						else
							dosyaYaz64 << "food = false";
						dosyaYaz64.close();
						//
						std::ofstream dosyaYaz65("C:\\AlienCheatsCONFIG\\medical.txt");
						dosyaYaz65.is_open();
						if (medical)
							dosyaYaz65 << "medical = true";
						else
							dosyaYaz65 << "medical = false";
						dosyaYaz65.close();
						//
						std::ofstream dosyaYaz66("C:\\AlienCheatsCONFIG\\toolbox.txt");
						dosyaYaz66.is_open();
						if (toolbox)
							dosyaYaz66 << "toolbox = true";
						else
							dosyaYaz66 << "toolbox = false";
						dosyaYaz66.close();
						//
						std::ofstream dosyaYaz67("C:\\AlienCheatsCONFIG\\minicopter.txt");
						dosyaYaz67.is_open();
						if (minicopter)
							dosyaYaz67 << "minicopter = true";
						else
							dosyaYaz67 << "minicopter = false";
						dosyaYaz67.close();
						//
						std::ofstream dosyaYaz68("C:\\AlienCheatsCONFIG\\scrapheli.txt");
						dosyaYaz68.is_open();
						if (scrapheli)
							dosyaYaz68 << "scrapheli = true";
						else
							dosyaYaz68 << "scrapheli = false";
						dosyaYaz68.close();
						//
						std::ofstream dosyaYaz69("C:\\AlienCheatsCONFIG\\patrolheli.txt");
						dosyaYaz69.is_open();
						if (patrolheli)
							dosyaYaz69 << "patrolheli = true";
						else
							dosyaYaz69 << "patrolheli = false";
						dosyaYaz69.close();
						//
						std::ofstream dosyaYaz70("C:\\AlienCheatsCONFIG\\boat.txt");
						dosyaYaz70.is_open();
						if (boat)
							dosyaYaz70 << "boat = true";
						else
							dosyaYaz70 << "boat = false";
						dosyaYaz70.close();
						//
						std::ofstream dosyaYaz71("C:\\AlienCheatsCONFIG\\rhib.txt");
						dosyaYaz71.is_open();
						if (rhib)
							dosyaYaz71 << "rhib = true";
						else
							dosyaYaz71 << "rhib = false";
						dosyaYaz71.close();
						//
						std::ofstream dosyaYaz72("C:\\AlienCheatsCONFIG\\cars.txt");
						dosyaYaz72.is_open();
						if (cars)
							dosyaYaz72 << "cars = true";
						else
							dosyaYaz72 << "cars = false";
						dosyaYaz72.close();
						//
						std::ofstream dosyaYaz73("C:\\AlienCheatsCONFIG\\autoturret.txt");
						dosyaYaz73.is_open();
						if (autoturret)
							dosyaYaz73 << "autoturret = true";
						else
							dosyaYaz73 << "autoturret = false";
						dosyaYaz73.close();
						//
						std::ofstream dosyaYaz74("C:\\AlienCheatsCONFIG\\toolcupboard.txt");
						dosyaYaz74.is_open();
						if (toolcupboard)
							dosyaYaz74 << "toolcupboard = true";
						else
							dosyaYaz74 << "toolcupboard = false";
						dosyaYaz74.close();
						//
						std::ofstream dosyaYaz75("C:\\AlienCheatsCONFIG\\admin_flag_checkboxx.txt");
						dosyaYaz75.is_open();
						if (toolcupboard)
							dosyaYaz75 << "admin_flag_checkboxx = true";
						else
							dosyaYaz75 << "admin_flag_checkboxx = false";
						dosyaYaz75.close();
						//
						std::ofstream dosyaYaz76("C:\\AlienCheatsCONFIG\\fov.txt");
						dosyaYaz76.is_open();
						if (fov)
							dosyaYaz76 << "fov = true";
						else
							dosyaYaz76 << "fov = false";
						dosyaYaz76.close();
						//
						std::ofstream dosyaYaz77("C:\\AlienCheatsCONFIG\\fakeworkbench.txt");
						dosyaYaz77.is_open();
						if (fakeworkbench)
							dosyaYaz77 << "fakeworkbench = true";
						else
							dosyaYaz77 << "fakeworkbench = false";
						dosyaYaz77.close();
						//
						std::ofstream dosyaYaz78("C:\\AlienCheatsCONFIG\\thirdperson.txt");
						dosyaYaz78.is_open();
						if (thirdperson)
							dosyaYaz78 << "thirdperson = true";
						else
							dosyaYaz78 << "thirdperson = false";
						dosyaYaz78.close();
						//
						std::ofstream dosyaYaz79("C:\\AlienCheatsCONFIG\\suicide.txt");
						dosyaYaz79.is_open();
						if (suicide)
							dosyaYaz79 << "suicide = true";
						else
							dosyaYaz79 << "suicide = false";
						dosyaYaz79.close();
						//
						std::ofstream dosyaYaz80("C:\\AlienCheatsCONFIG\\alwaysday.txt");
						dosyaYaz80.is_open();
						if (alwaysday)
							dosyaYaz80 << "alwaysday = true";
						else
							dosyaYaz80 << "alwaysday = false";
						dosyaYaz80.close();
						//
						std::ofstream dosyaYaz81("C:\\AlienCheatsCONFIG\\nighttmode.txt");
						dosyaYaz81.is_open();
						if (nighttmode)
							dosyaYaz81 << "nighttmode = true";
						else
							dosyaYaz81 << "nighttmode = false";
						dosyaYaz81.close();
						//
						std::ofstream dosyaYaz82("C:\\AlienCheatsCONFIG\\AdminEsp.txt");
						dosyaYaz82.is_open();
						if (AdminEsp)
							dosyaYaz82 << "AdminEsp = true";
						else
							dosyaYaz82 << "AdminEsp = false";
						dosyaYaz82.close();
						//
						std::ofstream dosyaYaz83("C:\\AlienCheatsCONFIG\\fakelag.txt");
						dosyaYaz83.is_open();
						if (fakelag)
							dosyaYaz83 << "fakelag = true";
						else
							dosyaYaz83 << "fakelag = false";
						dosyaYaz83.close();
						//
						std::ofstream dosyaYaz84("C:\\AlienCheatsCONFIG\\spinbot.txt");
						dosyaYaz84.is_open();
						if (spinbot)
							dosyaYaz84 << "spinbot = true";
						else
							dosyaYaz84 << "spinbot = false";
						dosyaYaz84.close();
						//
						std::ofstream dosyaYaz85("C:\\AlienCheatsCONFIG\\hardcoremodeMap.txt");
						dosyaYaz85.is_open();
						if (hardcoremodeMap)
							dosyaYaz85 << "hardcoremodeMap = true";
						else
							dosyaYaz85 << "hardcoremodeMap = false";
						dosyaYaz85.close();
						//
						std::ofstream dosyaYaz86("C:\\AlienCheatsCONFIG\\cameraaa.txt");
						dosyaYaz86.is_open();
						if (cameraaa)
							dosyaYaz86 << "cameraaa = true";
						else
							dosyaYaz86 << "cameraaa = false";
						dosyaYaz86.close();
						//
						std::ofstream dosyaYaz87("C:\\AlienCheatsCONFIG\\chams.txt");
						dosyaYaz87.is_open();
						if (chams)
							dosyaYaz87 << "chams = true";
						else
							dosyaYaz87 << "chams = false";
						dosyaYaz87.close();
						//
						std::ofstream dosyaYaz88("C:\\AlienCheatsCONFIG\\spiderman.txt");
						dosyaYaz88.is_open();
						if (spiderman)
							dosyaYaz88 << "spiderman = true";
						else
							dosyaYaz88 << "spiderman = false";
						dosyaYaz88.close();
						//
						std::ofstream dosyaYaz89("C:\\AlienCheatsCONFIG\\flyhack.txt");
						dosyaYaz89.is_open();
						if (flyhack)
							dosyaYaz89 << "flyhack = true";
						else
							dosyaYaz89 << "flyhack = false";
						dosyaYaz89.close();
						//
						std::ofstream dosyaYaz90("C:\\AlienCheatsCONFIG\\infinitejump.txt");
						dosyaYaz90.is_open();
						if (infinitejump)
							dosyaYaz90 << "infinitejump = true";
						else
							dosyaYaz90 << "infinitejump = false";
						dosyaYaz90.close();
						//
						std::ofstream dosyaYaz91("C:\\AlienCheatsCONFIG\\timer.txt");
						dosyaYaz91.is_open();
						if (timer)
							dosyaYaz91 << "timer = true";
						else
							dosyaYaz91 << "timer = false";
						dosyaYaz91.close();
						//
						std::ofstream dosyaYaz92("C:\\AlienCheatsCONFIG\\gravity.txt");
						dosyaYaz92.is_open();
						if (gravity)
							dosyaYaz92 << "gravity = true";
						else
							dosyaYaz92 << "gravity = false";
						dosyaYaz92.close();
						//
						std::ofstream dosyaYaz93("C:\\AlienCheatsCONFIG\\WalkOnWater.txt");
						dosyaYaz93.is_open();
						if (gravity)
							dosyaYaz93 << "WalkOnWater = true";
						else
							dosyaYaz93 << "WalkOnWater = false";
						dosyaYaz93.close();
						//
						std::ofstream dosyaYaz94("C:\\AlienCheatsCONFIG\\jumpshot.txt");
						dosyaYaz94.is_open();
						if (jumpshot)
							dosyaYaz94 << "jumpshot = true";
						else
							dosyaYaz94 << "jumpshot = false";
						dosyaYaz94.close();
						//
						std::ofstream dosyaYaz95("C:\\AlienCheatsCONFIG\\climb.txt");
						dosyaYaz95.is_open();
						if (climb)
							dosyaYaz95 << "climb = true";
						else
							dosyaYaz95 << "climb = false";
						dosyaYaz95.close();
						//
						std::ofstream dosyaYaz96("C:\\AlienCheatsCONFIG\\longneck.txt");
						dosyaYaz96.is_open();
						if (longneck)
							dosyaYaz96 << "longneck = true";
						else
							dosyaYaz96 << "longneck = false";
						dosyaYaz96.close();
						//
						std::ofstream dosyaYaz97("C:\\AlienCheatsCONFIG\\SPEEDhack.txt");
						dosyaYaz97.is_open();
						if (SPEEDhack)
							dosyaYaz97 << "SPEEDhack = true";
						else
							dosyaYaz97 << "SPEEDhack = false";
						dosyaYaz97.close();
					}
					ImGui::SetCursorPos({ 0,60 });
					if (ImGui::Button("CONFIG LOAD"))
					{ 
						std::ifstream dosyaOku1("C:\\AlienCheatsCONFIG\\aimbot.txt");
						std::string satir1 = "";
						dosyaOku1.is_open();
						getline(dosyaOku1, satir1);
						if (satir1 == "aimbot = true")
						{
							aimbot = true;
						}
						if (satir1 == "aimbot = false")
						{
							aimbot = false;
						}
						dosyaOku1.close();
						//
						std::ifstream dosyaOku2("C:\\AlienCheatsCONFIG\\silent.txt");
						std::string satir2 = "";
						dosyaOku2.is_open();
						getline(dosyaOku2, satir2);
						if (satir2 == "silent = true")
						{
							silent = true;
						}
						if (satir2 == "silent = false")
						{
							silent = false;
						}
						dosyaOku2.close();
						//
						std::ifstream dosyaOku3("C:\\AlienCheatsCONFIG\\silentline.txt");
						std::string satir3 = "";
						dosyaOku3.is_open();
						getline(dosyaOku3, satir3);
						if (satir3 == "silentline = true")
						{
							silentline = true;
						}
						if (satir3 == "silentline = false")
						{
							silentline = false;
						}
						dosyaOku3.close();
						//
						std::ifstream dosyaOku4("C:\\AlienCheatsCONFIG\\ssilent.txt");
						std::string satir4 = "";
						dosyaOku4.is_open();
						getline(dosyaOku4, satir4);
						if (satir4 == "ssilent = true")
						{
							ssilent = true;
						}
						if (satir4 == "ssilent = false")
						{
							ssilent = false;
						}
						dosyaOku4.close();
						//
						std::ifstream dosyaOku5("C:\\AlienCheatsCONFIG\\Predictionn.txt");
						std::string satir5 = "";
						dosyaOku5.is_open();
						getline(dosyaOku5, satir5);
						if (satir5 == "Predictionn = true")
						{
							Predictionn = true;
						}
						if (satir5 == "Predictionn = false")
						{
							Predictionn = false;
						}
						dosyaOku5.close();
						//
						std::ifstream dosyaOku6("C:\\AlienCheatsCONFIG\\sleeperignore.txt");
						std::string satir6 = "";
						dosyaOku6.is_open();
						getline(dosyaOku6, satir6);
						if (satir6 == "sleeperignore = true")
						{
							sleeperignore = true;
						}
						if (satir6 == "sleeperignore = false")
						{
							sleeperignore = false;
						}
						dosyaOku6.close();
						//
						std::ifstream dosyaOku7("C:\\AlienCheatsCONFIG\\teamignoree.txt");
						std::string satir7 = "";
						dosyaOku7.is_open();
						getline(dosyaOku7, satir7);
						if (satir6 == "teamignoree = true")
						{
							teamignoree = true;
						}
						if (satir6 == "teamignoree = false")
						{
							teamignoree = false;
						}
						dosyaOku7.close();
						//
						std::ifstream dosyaOku8("C:\\AlienCheatsCONFIG\\woundedignore.txt");
						std::string satir8 = "";
						dosyaOku8.is_open();
						getline(dosyaOku8, satir8);
						if (satir8 == "woundedignore = true")
						{
							woundedignore = true;
						}
						if (satir8 == "woundedignore = false")
						{
							woundedignore = false;
						}
						dosyaOku8.close();
						//
						std::ifstream dosyaOku9("C:\\AlienCheatsCONFIG\\visiblecheck.txt");
						std::string satir9 = "";
						dosyaOku9.is_open();
						getline(dosyaOku9, satir9);
						if (satir9 == "visiblecheck = true")
						{
							visiblecheck = true;
						}
						if (satir9 == "visiblecheck = false")
						{
							visiblecheck = false;
						}
						dosyaOku9.close();
						//
						std::ifstream dosyaOku10("C:\\AlienCheatsCONFIG\\norecoil.txt");
						std::string satir10 = "";
						dosyaOku10.is_open();
						getline(dosyaOku10, satir10);
						if (satir10 == "norecoil = true")
						{
							norecoil = true;
						}
						if (satir10 == "norecoil = false")
						{
							norecoil = false;
						}
						dosyaOku10.close();
						//
						std::ifstream dosyaOku11("C:\\AlienCheatsCONFIG\\nospread.txt");
						std::string satir11 = "";
						dosyaOku11.is_open();
						getline(dosyaOku11, satir11);
						if (satir11 == "nospread = true")
						{
							nospread = true;
						}
						if (satir11 == "nospread = false")
						{
							nospread = false;
						}
						dosyaOku11.close();
						//
						std::ifstream dosyaOku12("C:\\AlienCheatsCONFIG\\fat_bullet_checkbox.txt");
						std::string satir12 = "";
						dosyaOku12.is_open();
						getline(dosyaOku12, satir12);
						if (satir12 == "fat_bullet_checkbox = true")
						{
							fat_bullet_checkbox = true;
						}
						if (satir12 == "fat_bullet_checkbox = false")
						{
							fat_bullet_checkbox = false;
						}
						dosyaOku12.close();
						//
						std::ifstream dosyaOku13("C:\\AlienCheatsCONFIG\\full_automatic_checkbox.txt");
						std::string satir13 = "";
						dosyaOku13.is_open();
						getline(dosyaOku12, satir13);
						if (satir13 == "full_automatic_checkbox = true")
						{
							full_automatic_checkbox = true;
						}
						if (satir13 == "full_automatic_checkbox = false")
						{
							full_automatic_checkbox = false;
						}
						dosyaOku13.close();
						//
						std::ifstream dosyaOku14("C:\\AlienCheatsCONFIG\\nosway.txt");
						std::string satir14 = "";
						dosyaOku14.is_open();
						getline(dosyaOku14, satir14);
						if (satir14 == "nosway = true")
						{
							nosway = true;
						}
						if (satir14 == "nosway = false")
						{
							nosway = false;
						}
						dosyaOku14.close();
						//
						std::ifstream dosyaOku15("C:\\AlienCheatsCONFIG\\super_eoka_checkbox.txt");
						std::string satir15 = "";
						dosyaOku15.is_open();
						getline(dosyaOku15, satir15);
						if (satir15 == "super_eoka_checkbox = true")
						{
							super_eoka_checkbox = true;
						}
						if (satir15 == "super_eoka_checkbox = false")
						{
							super_eoka_checkbox = false;
						}
						dosyaOku15.close();
						//
						std::ifstream dosyaOku16("C:\\AlienCheatsCONFIG\\supermeele.txt");
						std::string satir16 = "";
						dosyaOku16.is_open();
						getline(dosyaOku16, satir16);
						if (satir16 == "supermeele = true")
						{
							supermeele = true;
						}
						if (satir16 == "supermeele = false")
						{
							supermeele = false;
						}
						dosyaOku16.close();
						//
						std::ifstream dosyaOku17("C:\\AlienCheatsCONFIG\\noshotgunspread.txt");
						std::string satir17 = "";
						dosyaOku17.is_open();
						getline(dosyaOku17, satir17);
						if (satir17 == "noshotgunspread = true")
						{
							noshotgunspread = true;
						}
						if (satir17 == "noshotgunspread = false")
						{
							noshotgunspread = false;
						}
						dosyaOku17.close();
						//
						std::ifstream dosyaOku18("C:\\AlienCheatsCONFIG\\instantCompound.txt");
						std::string satir18 = "";
						dosyaOku18.is_open();
						getline(dosyaOku18, satir18);
						if (satir18 == "instantCompound = true")
						{
							instantCompound = true;
						}
						if (satir18 == "instantCompound = false")
						{
							instantCompound = false;
						}
						dosyaOku18.close();
						//
						std::ifstream dosyaOku19("C:\\AlienCheatsCONFIG\\zoom.txt");
						std::string satir19 = "";
						dosyaOku19.is_open();
						getline(dosyaOku19, satir19);
						if (satir19 == "zoom = true")
						{
							zoom = true;
						}
						if (satir19 == "zoom = false")
						{
							zoom = false;
						}
						dosyaOku19.close();
						//
						std::ifstream dosyaOku20("C:\\AlienCheatsCONFIG\\ADS_Hide.txt");
						std::string satir20 = "";
						dosyaOku20.is_open();
						getline(dosyaOku20, satir20);
						if (satir20 == "ADS_Hide = true")
						{
							ADS_Hide = true;
						}
						if (satir20 == "ADS_Hide = false")
						{
							ADS_Hide = false;
						}
						dosyaOku20.close();
						//
						std::ifstream dosyaOku21("C:\\AlienCheatsCONFIG\\cross.txt");
						std::string satir21 = "";
						dosyaOku21.is_open();
						getline(dosyaOku21, satir21);
						if (satir21 == "cross = true")
						{
							cross = true;
						}
						if (satir21 == "cross = false")
						{
							cross = false;
						}
						dosyaOku21.close();
						//
						std::ifstream dosyaOku22("C:\\AlienCheatsCONFIG\\instabow.txt");
						std::string satir22 = "";
						dosyaOku22.is_open();
						getline(dosyaOku22, satir22);
						if (satir22 == "instabow = true")
						{
							instabow = true;
						}
						if (satir22 == "instabow = false")
						{
							instabow = false;
						}
						dosyaOku22.close();
						//
						std::ifstream dosyaOku23("C:\\AlienCheatsCONFIG\\box2.txt");
						std::string satir23 = "";
						dosyaOku23.is_open();
						getline(dosyaOku23, satir23);
						if (satir23 == "box2 = true")
						{
							box2 = true;
						}
						if (satir23 == "box2 = false")
						{
							box2 = false;
						}
						dosyaOku23.close();
						//
						std::ifstream dosyaOku24("C:\\AlienCheatsCONFIG\\box3.txt");
						std::string satir24 = "";
						dosyaOku24.is_open();
						getline(dosyaOku24, satir24);
						if (satir24 == "box3 = true")
						{
							box3 = true;
						}
						if (satir24 == "box3 = false")
						{
							box3 = false;
						}
						dosyaOku24.close();
						//
						std::ifstream dosyaOku25("C:\\AlienCheatsCONFIG\\box.txt");
						std::string satir25 = "";
						dosyaOku25.is_open();
						getline(dosyaOku25, satir25);
						if (satir25 == "box = true")
						{
							box = true;
						}
						if (satir25 == "box = false")
						{
							box = false;
						}
						dosyaOku25.close();
						//
						std::ifstream dosyaOku26("C:\\AlienCheatsCONFIG\\skeleton.txt");
						std::string satir26 = "";
						dosyaOku26.is_open();
						getline(dosyaOku26, satir26);
						if (satir26 == "skeleton = true")
						{
							skeleton = true;
						}
						if (satir26 == "skeleton = false")
						{
							skeleton = false;
						}
						dosyaOku26.close();
						//
						std::ifstream dosyaOku27("C:\\AlienCheatsCONFIG\\name.txt");
						std::string satir27 = "";
						dosyaOku27.is_open();
						getline(dosyaOku27, satir27);
						if (satir27 == "name = true")
						{
							name = true;
						}
						if (satir27 == "name = false")
						{
							name = false;
						}
						dosyaOku27.close();
						//
						std::ifstream dosyaOku28("C:\\AlienCheatsCONFIG\\paintinside.txt");
						std::string satir28 = "";
						dosyaOku28.is_open();
						getline(dosyaOku28, satir28);
						if (satir28 == "paintinside = true")
						{
							paintinside = true;
						}
						if (satir28 == "paintinside = false")
						{
							paintinside = false;
						}
						dosyaOku28.close();
						//
						std::ifstream dosyaOku29("C:\\AlienCheatsCONFIG\\healthbar.txt");
						std::string satir29 = "";
						dosyaOku29.is_open();
						getline(dosyaOku29, satir29);
						if (satir29 == "healthbar = true")
						{
							healthbar = true;
						}
						if (satir29 == "healthbar = false")
						{
							healthbar = false;
						}
						dosyaOku29.close();
						//
						std::ifstream dosyaOku30("C:\\AlienCheatsCONFIG\\healthbar2.txt");
						std::string satir30 = "";
						dosyaOku30.is_open();
						getline(dosyaOku30, satir30);
						if (satir30 == "healthbar2 = true")
						{
							healthbar2 = true;
						}
						if (satir30 == "healthbar2 = false")
						{
							healthbar2 = false;
						}
						dosyaOku30.close();
						//
						std::ifstream dosyaOku31("C:\\AlienCheatsCONFIG\\snapline.txt");
						std::string satir31 = "";
						dosyaOku31.is_open();
						getline(dosyaOku31, satir31);
						if (satir31 == "snapline = true")
						{
							snapline = true;
						}
						if (satir31 == "snapline = false")
						{
							snapline = false;
						}
						dosyaOku31.close();
						//
						std::ifstream dosyaOku32("C:\\AlienCheatsCONFIG\\handweapon.txt");
						std::string satir32 = "";
						dosyaOku32.is_open();
						getline(dosyaOku32, satir32);
						if (satir32 == "handweapon = true")
						{
							handweapon = true;
						}
						if (satir32 == "handweapon = false")
						{
							handweapon = false;
						}
						dosyaOku32.close();
						//
						std::ifstream dosyaOku33("C:\\AlienCheatsCONFIG\\playerinfoo.txt");
						std::string satir33 = "";
						dosyaOku33.is_open();
						getline(dosyaOku33, satir33);
						if (satir33 == "playerinfoo = true")
						{
							playerinfoo = true;
						}
						if (satir33 == "playerinfoo = false")
						{
							playerinfoo = false;
						}
						dosyaOku33.close();
						//
						std::ifstream dosyaOku34("C:\\AlienCheatsCONFIG\\sleeper.txt");
						std::string satir34 = "";
						dosyaOku34.is_open();
						getline(dosyaOku34, satir34);
						if (satir34 == "sleeper = true")
						{
							sleeper = true;
						}
						if (satir34 == "sleeper = false")
						{
							sleeper = false;
						}
						dosyaOku34.close();
						//
						std::ifstream dosyaOku35("C:\\AlienCheatsCONFIG\\teamignore.txt");
						std::string satir35 = "";
						dosyaOku35.is_open();
						getline(dosyaOku35, satir35);
						if (satir35 == "teamignore = true")
						{
							teamignore = true;
						}
						if (satir35 == "teamignore = false")
						{
							teamignore = false;
						}
						dosyaOku35.close();
						//
						std::ifstream dosyaOku36("C:\\AlienCheatsCONFIG\\WoundedAlert.txt");
						std::string satir36 = "";
						dosyaOku36.is_open();
						getline(dosyaOku36, satir36);
						if (satir36 == "WoundedAlert = true")
						{
							WoundedAlert = true;
						}
						if (satir36 == "WoundedAlert = false")
						{
							WoundedAlert = false;
						}
						dosyaOku36.close();
						//
						std::ifstream dosyaOku37("C:\\AlienCheatsCONFIG\\playercorpse.txt");
						std::string satir37 = "";
						dosyaOku37.is_open();
						getline(dosyaOku37, satir37);
						if (satir37 == "playercorpse = true")
						{
							playercorpse = true;
						}
						if (satir37 == "playercorpse = false")
						{
							playercorpse = false;
						}
						dosyaOku37.close();
						//
						std::ifstream dosyaOku38("C:\\AlienCheatsCONFIG\\wolf.txt");
						std::string satir38 = "";
						dosyaOku38.is_open();
						getline(dosyaOku38, satir38);
						if (satir38 == "wolf = true")
						{
							wolf = true;
						}
						if (satir38 == "wolf = false")
						{
							wolf = false;
						}
						dosyaOku38.close();
						//
						std::ifstream dosyaOku39("C:\\AlienCheatsCONFIG\\bear.txt");
						std::string satir39 = "";
						dosyaOku39.is_open();
						getline(dosyaOku39, satir39);
						if (satir39 == "bear = true")
						{
							bear = true;
						}
						if (satir39 == "bear = false")
						{
							bear = false;
						}
						dosyaOku39.close();
						//
						std::ifstream dosyaOku40("C:\\AlienCheatsCONFIG\\stag.txt");
						std::string satir40 = "";
						dosyaOku40.is_open();
						getline(dosyaOku40, satir40);
						if (satir40 == "stag = true")
						{
							stag = true;
						}
						if (satir40 == "stag = false")
						{
							stag = false;
						}
						dosyaOku40.close();
						//
						std::ifstream dosyaOku41("C:\\AlienCheatsCONFIG\\chicken.txt");
						std::string satir41 = "";
						dosyaOku41.is_open();
						getline(dosyaOku41, satir41);
						if (satir41 == "chicken = true")
						{
							chicken = true;
						}
						if (satir41 == "chicken = false")
						{
							chicken = false;
						}
						dosyaOku41.close();
						//
						std::ifstream dosyaOku42("C:\\AlienCheatsCONFIG\\boar.txt");
						std::string satir42 = "";
						dosyaOku42.is_open();
						getline(dosyaOku42, satir42);
						if (satir42 == "boar = true")
						{
							boar = true;
						}
						if (satir42 == "boar = false")
						{
							boar = false;
						}
						dosyaOku42.close();
						//
						std::ifstream dosyaOku43("C:\\AlienCheatsCONFIG\\horse.txt");
						std::string satir43 = "";
						dosyaOku43.is_open();
						getline(dosyaOku43, satir43);
						if (satir43 == "horse = true")
						{
							horse = true;
						}
						if (satir43 == "horse = false")
						{
							horse = false;
						}
						dosyaOku43.close();
						//
						std::ifstream dosyaOku44("C:\\AlienCheatsCONFIG\\weapons.txt");
						std::string satir44 = "";
						dosyaOku44.is_open();
						getline(dosyaOku44, satir44);
						if (satir44 == "weapons = true")
						{
							weapons = true;
						}
						if (satir44 == "weapons = false")
						{
							weapons = false;
						}
						dosyaOku44.close();
						dosyaOku43.close();
						//
						std::ifstream dosyaOku45("C:\\AlienCheatsCONFIG\\showdistancee.txt");
						std::string satir45 = "";
						dosyaOku45.is_open();
						getline(dosyaOku45, satir45);
						if (satir45 == "showdistancee = true")
						{
							showdistancee = true;
						}
						if (satir45 == "showdistancee = false")
						{
							showdistancee = false;
						}
						dosyaOku45.close();
						//
						std::ifstream dosyaOku46("C:\\AlienCheatsCONFIG\\NPCNames.txt");
						std::string satir46 = "";
						dosyaOku46.is_open();
						getline(dosyaOku46, satir46);
						if (satir46 == "NPCNames = true")
						{
							NPCNames = true;
						}
						if (satir46 == "NPCNames = false")
						{
							NPCNames = false;
						}
						dosyaOku46.close();
						//
						std::ifstream dosyaOku47("C:\\AlienCheatsCONFIG\\tunneldweller.txt");
						std::string satir47 = "";
						dosyaOku47.is_open();
						getline(dosyaOku47, satir47);
						if (satir47 == "tunneldweller = true")
						{
							tunneldweller = true;
						}
						if (satir47 == "tunneldweller = false")
						{
							tunneldweller = false;
						}	
						dosyaOku47.close();
						//
						std::ifstream dosyaOku48("C:\\AlienCheatsCONFIG\\scientistnpc.txt");
						std::string satir48 = "";
						dosyaOku48.is_open();
						getline(dosyaOku48, satir48);
						if (satir48 == "scientistnpc = true")
						{
							scientistnpc = true;
						}
						if (satir48 == "scientistnpc = false")
						{
							scientistnpc = false;
						}
						dosyaOku48.close();
						//
						std::ifstream dosyaOku49("C:\\AlienCheatsCONFIG\\scarecrow.txt");
						std::string satir49 = "";
						dosyaOku49.is_open();
						getline(dosyaOku49, satir49);
						if (satir49 == "scarecrow = true")
						{
							scarecrow = true;
						}
						if (satir49 == "scarecrow = false")
						{
							scarecrow = false;
						}
						dosyaOku49.close();
						//
						std::ifstream dosyaOku50("C:\\AlienCheatsCONFIG\\airdrop.txt");
						std::string satir50 = "";
						dosyaOku50.is_open();
						getline(dosyaOku50, satir50);
						if (satir50 == "airdrop = true")
						{
							airdrop = true;
						}
						if (satir50 == "airdrop = false")
						{
							airdrop = false;
						}
						dosyaOku50.close();
						//
						std::ifstream dosyaOku51("C:\\AlienCheatsCONFIG\\stash.txt");
						std::string satir51 = "";
						dosyaOku51.is_open();
						getline(dosyaOku51, satir51);
						if (satir51 == "stash = true")
						{
							stash = true;
						}
						if (satir51 == "stash = false")
						{
							stash = false;
						}
						dosyaOku51.close();
						//
						std::ifstream dosyaOku52("C:\\AlienCheatsCONFIG\\backpack.txt");
						std::string satir52 = "";
						dosyaOku52.is_open();
						getline(dosyaOku52, satir52);
						if (satir52 == "backpack = true")
						{
							backpack = true;
						}
						if (satir52 == "backpack = false")
						{
							backpack = false;
						}
						dosyaOku52.close();
						//
						std::ifstream dosyaOku53("C:\\AlienCheatsCONFIG\\stone.txt");
						std::string satir53 = "";
						dosyaOku53.is_open();
						getline(dosyaOku53, satir53);
						if (satir53 == "stone = true")
						{
							stone = true;
						}
						if (satir53 == "stone = false")
						{
							stone = false;
						}
						dosyaOku53.close();
						//
						std::ifstream dosyaOku54("C:\\AlienCheatsCONFIG\\stone2.txt");
						std::string satir54 = "";
						dosyaOku54.is_open();
						getline(dosyaOku54, satir54);
						if (satir54 == "stone2 = true")
						{
							stone2 = true;
						}
						if (satir54 == "stone2 = false")
						{
							stone2 = false;
						}
						dosyaOku54.close();
						//
						std::ifstream dosyaOku55("C:\\AlienCheatsCONFIG\\sulfur.txt");
						std::string satir55 = "";
						dosyaOku55.is_open();
						getline(dosyaOku55, satir55);
						if (satir55 == "sulfur = true")
						{
							sulfur = true;
						}
						if (satir55 == "sulfur = false")
						{
							sulfur = false;
						}
						dosyaOku55.close();
						//
						std::ifstream dosyaOku56("C:\\AlienCheatsCONFIG\\sulfur2.txt");
						std::string satir56 = "";
						dosyaOku56.is_open();
						getline(dosyaOku56, satir56);
						if (satir56 == "sulfur2 = true")
						{
							sulfur2 = true;
						}
						if (satir56 == "sulfur2 = false")
						{
							sulfur2 = false;
						}
						dosyaOku56.close();
						//
						std::ifstream dosyaOku57("C:\\AlienCheatsCONFIG\\metal.txt");
						std::string satir57 = "";
						dosyaOku57.is_open();
						getline(dosyaOku57, satir57);
						if (satir57 == "metal = true")
						{
							metal = true;
						}
						if (satir57 == "metal = false")
						{
							metal = false;
						}
						dosyaOku57.close();
						//
						std::ifstream dosyaOku58("C:\\AlienCheatsCONFIG\\metal2.txt");
						std::string satir58 = "";
						dosyaOku58.is_open();
						getline(dosyaOku58, satir58);
						if (satir58 == "metal2 = true")
						{
							metal2 = true;
						}
						if (satir58 == "metal2 = false")
						{
							metal2 = false;
						}
						dosyaOku58.close();
						//
						std::ifstream dosyaOku59("C:\\AlienCheatsCONFIG\\mushroom.txt");
						std::string satir59 = "";
						dosyaOku59.is_open();
						getline(dosyaOku59, satir59);
						if (satir59 == "mushroom = true")
						{
							mushroom = true;
						}
						if (satir59 == "mushroom = false")
						{
							mushroom = false;
						}
						dosyaOku59.close();
						//
						std::ifstream dosyaOku60("C:\\AlienCheatsCONFIG\\hemp.txt");
						std::string satir60 = "";
						dosyaOku60.is_open();
						getline(dosyaOku60, satir60);
						if (satir60 == "hemp = true")
						{
							hemp = true;
						}
						if (satir60 == "hemp = false")
						{
							hemp = false;
						}
						dosyaOku60.close();
						//
						std::ifstream dosyaOku61("C:\\AlienCheatsCONFIG\\military.txt");
						std::string satir61 = "";
						dosyaOku61.is_open();
						getline(dosyaOku61, satir61);
						if (satir61 == "military = true")
						{
							military = true;
						}
						if (satir61 == "military = false")
						{
							military = false;
						}
						dosyaOku61.close();
						//
						std::ifstream dosyaOku62("C:\\AlienCheatsCONFIG\\elite.txt");
						std::string satir62 = "";
						dosyaOku62.is_open();
						getline(dosyaOku62, satir62);
						if (satir62 == "elite = true")
						{
							elite = true;
						}
						if (satir62 == "elite = false")
						{
							elite = false;
						}
						dosyaOku62.close();
						//
						std::ifstream dosyaOku63("C:\\AlienCheatsCONFIG\\loot.txt");
						std::string satir63 = "";
						dosyaOku63.is_open();
						getline(dosyaOku63, satir63);
						if (satir63 == "loot = true")
						{
							loot = true;
						}
						if (satir63 == "loot = false")
						{
							loot = false;
						}
						dosyaOku63.close();
						//
						std::ifstream dosyaOku64("C:\\AlienCheatsCONFIG\\food.txt");
						std::string satir64	 = "";
						dosyaOku64.is_open();
						getline(dosyaOku64, satir64);
						if (satir64 == "food = true")
						{
							food = true;
						}
						if (satir64 == "food = false")
						{
							food = false;
						}
						dosyaOku64.close();
						//
						std::ifstream dosyaOku65("C:\\AlienCheatsCONFIG\\medical.txt");
						std::string satir65 = "";
						dosyaOku65.is_open();
						getline(dosyaOku65, satir65);
						if (satir65 == "medical = true")
						{
							medical = true;
						}
						if (satir65 == "medical = false")
						{
							medical = false;
						}
						dosyaOku65.close();
						//
						std::ifstream dosyaOku66("C:\\AlienCheatsCONFIG\\toolbox.txt");
						std::string satir66 = "";
						dosyaOku66.is_open();
						getline(dosyaOku66, satir66);
						if (satir66 == "toolbox = true")
						{
							toolbox = true;
						}
						if (satir66 == "toolbox = false")
						{
							toolbox = false;
						}
						dosyaOku66.close();
						//
						std::ifstream dosyaOku67("C:\\AlienCheatsCONFIG\\minicopter.txt");
						std::string satir67 = "";
						dosyaOku67.is_open();
						getline(dosyaOku67, satir67);
						if (satir67 == "minicopter = true")
						{
							minicopter = true;
						}
						if (satir67 == "minicopter = false")
						{
							minicopter = false;
						}
						dosyaOku67.close();
						//
						std::ifstream dosyaOku68("C:\\AlienCheatsCONFIG\\scrapheli.txt");
						std::string satir68 = "";
						dosyaOku68.is_open();
						getline(dosyaOku68, satir68);
						if (satir68 == "scrapheli = true")
						{
							scrapheli = true;
						}
						if (satir68 == "scrapheli = false")
						{
							scrapheli = false;
						}
						dosyaOku68.close();
						//
						std::ifstream dosyaOku69("C:\\AlienCheatsCONFIG\\patrolheli.txt");
						std::string satir69 = "";
						dosyaOku69.is_open();
						getline(dosyaOku69, satir69);
						if (satir69 == "patrolheli = true")
						{
							patrolheli = true;
						}
						if (satir69 == "patrolheli = false")
						{
							patrolheli = false;
						}
						dosyaOku69.close();
						//
						std::ifstream dosyaOku70("C:\\AlienCheatsCONFIG\\boat.txt");
						std::string satir70 = "";
						dosyaOku70.is_open();
						getline(dosyaOku70, satir70);
						if (satir70 == "boat = true")
						{
							boat = true;
						}
						if (satir70 == "boat = false")
						{
							boat = false;
						}
						dosyaOku70.close();
						//
						std::ifstream dosyaOku71("C:\\AlienCheatsCONFIG\\rhib.txt");
						std::string satir71 = "";
						dosyaOku71.is_open();
						getline(dosyaOku71, satir71);
						if (satir71 == "rhib = true")
						{
							rhib = true;
						}
						if (satir71 == "rhib = false")
						{
							rhib = false;
						}
						dosyaOku71.close();
						//
						std::ifstream dosyaOku72("C:\\AlienCheatsCONFIG\\cars.txt");
						std::string satir72 = "";
						dosyaOku72.is_open();
						getline(dosyaOku72, satir72);
						if (satir72 == "cars = true")
						{
							cars = true;
						}
						if (satir72 == "cars = false")
						{
							cars = false;
						}
						dosyaOku72.close();
						//
						std::ifstream dosyaOku73("C:\\AlienCheatsCONFIG\\autoturret.txt");
						std::string satir73 = "";
						dosyaOku73.is_open();
						getline(dosyaOku73, satir73);
						if (satir73 == "autoturret = true")
						{
							autoturret = true;
						}
						if (satir73 == "autoturret = false")
						{
							autoturret = false;
						}
						dosyaOku73.close();
						//
						std::ifstream dosyaOku74("C:\\AlienCheatsCONFIG\\toolcupboard.txt");
						std::string satir74 = "";
						dosyaOku74.is_open();
						getline(dosyaOku74, satir74);
						if (satir74 == "toolcupboard = true")
						{
							toolcupboard = true;
						}
						if (satir74 == "toolcupboard = false")
						{
							toolcupboard = false;
						}
						dosyaOku74.close();
						//
						std::ifstream dosyaOku75("C:\\AlienCheatsCONFIG\\admin_flag_checkboxx.txt");
						std::string satir75 = "";
						dosyaOku75.is_open();
						getline(dosyaOku75, satir75);
						if (satir75 == "admin_flag_checkboxx = true")
						{
							admin_flag_checkboxx = true;
						}
						if (satir75 == "admin_flag_checkboxx = false")
						{
							admin_flag_checkboxx = false;
						}
						dosyaOku75.close();
						//
						std::ifstream dosyaOku76("C:\\AlienCheatsCONFIG\\fov.txt");
						std::string satir76 = "";
						dosyaOku76.is_open();
						getline(dosyaOku76, satir76);
						if (satir76 == "fov = true")
						{
							fov = true;
						}
						if (satir76 == "fov = false")
						{
							fov = false;
						}
						dosyaOku76.close();
						//
						std::ifstream dosyaOku77("C:\\AlienCheatsCONFIG\\fakeworkbench.txt");
						std::string satir77 = "";
						dosyaOku77.is_open();
						getline(dosyaOku77, satir77);
						if (satir77 == "fakeworkbench = true")
						{
							fakeworkbench = true;
						}
						if (satir77 == "fakeworkbench = false")
						{
							fakeworkbench = false;
						}
						dosyaOku77.close();
						//
						std::ifstream dosyaOku78("C:\\AlienCheatsCONFIG\\thirdperson.txt");
						std::string satir78 = "";
						dosyaOku78.is_open();
						getline(dosyaOku78, satir78);
						if (satir78 == "thirdperson = true")
						{
							thirdperson = true;
						}
						if (satir78 == "thirdperson = false")
						{
							thirdperson = false;
						}
						dosyaOku78.close();
						//
						std::ifstream dosyaOku79("C:\\AlienCheatsCONFIG\\alwaysday.txt");
						std::string satir79 = "";
						dosyaOku79.is_open();
						getline(dosyaOku79, satir79);
						if (satir79 == "alwaysday = true")
						{
							alwaysday = true;
						}
						if (satir79 == "alwaysday = false")
						{
							alwaysday = false;
						}
						dosyaOku79.close();
						//
						std::ifstream dosyaOku80("C:\\AlienCheatsCONFIG\\nighttmode.txt");
						std::string satir80 = "";
						dosyaOku80.is_open();
						getline(dosyaOku80, satir80);
						if (satir80 == "nighttmode = true")
						{
							nighttmode = true;
						}
						if (satir80 == "nighttmode = false")
						{
							nighttmode = false;
						}
						dosyaOku80.close();
						//
						std::ifstream dosyaOku81("C:\\AlienCheatsCONFIG\\AdminEsp.txt");
						std::string satir81 = "";
						dosyaOku81.is_open();
						getline(dosyaOku81, satir81);
						if (satir81 == "AdminEsp = true")
						{
							AdminEsp = true;
						}
						if (satir81 == "AdminEsp = false")
						{
							AdminEsp = false;
						}
						dosyaOku81.close();
						//
						std::ifstream dosyaOku82("C:\\AlienCheatsCONFIG\\fakelag.txt");
						std::string satir82 = "";
						dosyaOku82.is_open();
						getline(dosyaOku82, satir82);
						if (satir82 == "fakelag = true")
						{
							fakelag = true;
						}
						if (satir82 == "fakelag = false")
						{
							fakelag = false;
						}
						dosyaOku82.close();
						//
						std::ifstream dosyaOku83("C:\\AlienCheatsCONFIG\\spinbot.txt");
						std::string satir83 = "";
						dosyaOku83.is_open();
						getline(dosyaOku83, satir83);
						if (satir83 == "spinbot = true")
						{
							spinbot = true;
						}
						if (satir83 == "spinbot = false")
						{
							spinbot = false;
						}
						dosyaOku83.close();
						//
						std::ifstream dosyaOku84("C:\\AlienCheatsCONFIG\\hardcoremodeMap.txt");
						std::string satir84 = "";
						dosyaOku84.is_open();
						getline(dosyaOku84, satir84);
						if (satir84 == "hardcoremodeMap = true")
						{
							hardcoremodeMap = true;
						}
						if (satir84 == "hardcoremodeMap = false")
						{
							hardcoremodeMap = false;
						}
						dosyaOku84.close();
						//
						std::ifstream dosyaOku85("C:\\AlienCheatsCONFIG\\cameraaa.txt");
						std::string satir85 = "";
						dosyaOku85.is_open();
						getline(dosyaOku85, satir85);
						if (satir85 == "cameraaa = true")
						{
							cameraaa = true;
						}
						if (satir85 == "cameraaa = false")
						{
							cameraaa = false;
						}
						dosyaOku85.close();
						//
						std::ifstream dosyaOku86("C:\\AlienCheatsCONFIG\\chams.txt");
						std::string satir86 = "";
						dosyaOku86.is_open();
						getline(dosyaOku86, satir86);
						if (satir86 == "chams = true")
						{
							chams = true;
						}
						if (satir86 == "chams = false")
						{
							chams = false;
						}
						dosyaOku86.close();
						//
						std::ifstream dosyaOku87("C:\\AlienCheatsCONFIG\\spiderman.txt");
						std::string satir87 = "";
						dosyaOku87.is_open();
						getline(dosyaOku87, satir87);
						if (satir87 == "spiderman = true")
						{
							spiderman = true;
						}
						if (satir87 == "spiderman = false")
						{
							spiderman = false;
						}
						dosyaOku87.close();
						//
						std::ifstream dosyaOku88("C:\\AlienCheatsCONFIG\\flyhack.txt");
						std::string satir88 = "";
						dosyaOku88.is_open();
						getline(dosyaOku88, satir88);
						if (satir88 == "flyhack = true")
						{
							flyhack = true;
						}
						if (satir88 == "flyhack = false")
						{
							flyhack = false;
						}
						dosyaOku88.close();
						//
						std::ifstream dosyaOku89("C:\\AlienCheatsCONFIG\\infinitejump.txt");
						std::string satir89 = "";
						dosyaOku89.is_open();
						getline(dosyaOku89, satir89);
						if (satir89 == "infinitejump = true")
						{
							infinitejump = true;
						}
						if (satir89 == "infinitejump = false")
						{
							infinitejump = false;
						}
						dosyaOku89.close();
						//
						std::ifstream dosyaOku90("C:\\AlienCheatsCONFIG\\timer.txt");
						std::string satir90 = "";
						dosyaOku90.is_open();
						getline(dosyaOku90, satir90);
						if (satir90 == "timer = true")
						{
							timer = true;
						}
						if (satir90 == "timer = false")
						{
							timer = false;
						}
						dosyaOku90.close();
						//
						std::ifstream dosyaOku91("C:\\AlienCheatsCONFIG\\gravity.txt");
						std::string satir91 = "";
						dosyaOku91.is_open();
						getline(dosyaOku91, satir91);
						if (satir91 == "gravity = true")
						{
							gravity = true;
						}
						if (satir91 == "gravity = false")
						{
							gravity = false;
						}
						dosyaOku91.close();
						//
						std::ifstream dosyaOku92("C:\\AlienCheatsCONFIG\\suicide.txt");
						std::string satir92 = "";
						dosyaOku92.is_open();
						getline(dosyaOku92, satir92);
						if (satir92 == "suicide = true")
						{
							suicide = true;
						}
						if (satir92 == "suicide = false")
						{
							suicide = false;
						}
						dosyaOku92.close();
						//
						std::ifstream dosyaOku93("C:\\AlienCheatsCONFIG\\WalkOnWater.txt");
						std::string satir93 = "";
						dosyaOku93.is_open();
						getline(dosyaOku93, satir93);
						if (satir93 == "WalkOnWater = true")
						{
							WalkOnWater = true;
						}
						if (satir93 == "WalkOnWater = false")
						{
							WalkOnWater = false;
						}
						dosyaOku93.close();
						//
						std::ifstream dosyaOku94("C:\\AlienCheatsCONFIG\\jumpshot.txt");
						std::string satir94 = "";
						dosyaOku94.is_open();
						getline(dosyaOku94, satir94);
						if (satir94 == "jumpshot = true")
						{
							WalkOnWater = true;
						}
						if (satir94 == "jumpshot = false")
						{
							WalkOnWater = false;
						}
						dosyaOku94.close();
						//
						std::ifstream dosyaOku95("C:\\AlienCheatsCONFIG\\climb.txt");
						std::string satir95 = "";
						dosyaOku95.is_open();
						getline(dosyaOku95, satir95);
						if (satir95 == "climb = true")
						{
							climb = true;
						}
						if (satir95 == "climb = false")
						{
							climb = false;
						}
						dosyaOku95.close();
						//
						std::ifstream dosyaOku96("C:\\AlienCheatsCONFIG\\longneck.txt");
						std::string satir96 = "";
						dosyaOku96.is_open();
						getline(dosyaOku96, satir96);
						if (satir96 == "longneck = true")
						{
							longneck = true;
						}
						if (satir96 == "longneck = false")
						{
							longneck = false;
						}
						dosyaOku96.close();
						//
						std::ifstream dosyaOku97("C:\\AlienCheatsCONFIG\\SPEEDhack.txt");
						std::string satir97 = "";
						dosyaOku97.is_open();
						getline(dosyaOku97, satir97);
						if (satir97 == "SPEEDhack = true")
						{
							SPEEDhack = true;
						}
						if (satir97 == "SPEEDhack = false")
						{
							SPEEDhack = false;
						}
						dosyaOku97.close();

					}
					ImGui::SetCursorPos({ 0,305 });
					ImGui::Separator();
					ImGui::SetCursorPos({ 0,310 });
					ImGui::Checkbox(skCrypt("Pixel Font"), &font1);
					if (font1)
					{
						font2 = false;
						font3 = false;
						font4 = false;
					}
					ImGui::SetCursorPos({ 0,335 });
					ImGui::Checkbox(skCrypt("Arial Font"), &font2);
					if (font2)
					{
						font1 = false;
						font3 = false;
						font4 = false;
					}
					ImGui::SetCursorPos({ 0,360 });
					ImGui::Checkbox(skCrypt("Classic Font"), &font3);
					if (font3)
					{
						font1 = false;
						font2 = false;
						font4 = false;
					}
					ImGui::SetCursorPos({ 0,385 });
					ImGui::Checkbox(skCrypt("Sebastien Font"), &font4);
					if (font4)
					{
						font1 = false;
						font2 = false;
						font3 = false;
					}
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
	}
	ImGui::End();
}

void render()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImVec2 curPos = ImGui::GetCursorPos();
	ImVec2 curWindowPos = ImGui::GetWindowPos();
	curPos.x += curWindowPos.x;
	curPos.y += curWindowPos.y;
	static float flRainbow;
	float flSpeed = 0.0025f;
	flRainbow += flSpeed;
	if (flRainbow > 1.f) flRainbow = 0.f;
	for (int i = 0; i < 485; i++)
	{
		float hue = (1.f / (float)485) * i;
		hue -= flRainbow;
		if (hue < 0.f) hue += 1.f;

		cRainbow = ImColor::HSV(hue, 1.f, 1.f);
		//ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(curPos.x + i, 10), ImVec2(curPos.x + 485, curPos.y - 3), cRainbow);
	}

	if (ssilent || psilent || aimbot || silent)
	{
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), aimfovv, IM_COL32_WHITE, 10000, 1);	
	}

	if (cross)
	{
		Crosshair();
	}
	if (ADS_Hide == true) {
		if (!GetAsyncKeyState(VK_RBUTTON))
		{
			cross = true;
		}
		else {
			cross = false;
		}
	}


	if (GetAsyncKeyState(g_menuKeyBind) & 1) { showmenu = !showmenu; }	


	ImGui::PushFont(Font);
	draw();
	ImGui::PopFont();

	if(font1)
	{
		Font = main_font;
	}
	if (font2)
	{
		Font = main_font4;
	}
	if (font3)
	{
		Font = main_font3;
	}
	if (font4)
	{
		Font = main_font5;
	}

	if (GetAsyncKeyState(VK_END) & 1) { exit(0); }
	

	if (showmenu) {
		//// render this before anything else so it is the background
		//ImGui::SetNextWindowSize(ImVec2(ScreenCenterX * 2, ScreenCenterY * 2));
		//ImGui::SetNextWindowBgAlpha(1.0f);
		//ImGui::Begin(skCrypt("Steamm"), NULL, ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
		//{
		//	GetCursorPos(&xy);
		//	Snowflake::Update(snow, Snowflake::vec3(xy.x, xy.y)/*mouse x and y*/, Snowflake::vec3(rc.left, rc.top)/*hWnd x and y positions*/); // you can change a few things inside the update function
		//}
			
		draw_menu();
	}	
	else
	{
		ImGui::PushFont(main_font3);
		DrawLString(20, 50, 10, cRainbow, true, true, "ALIENCHEATS.COM");
		ImGui::PopFont();
	}
	ImGui::EndFrame();
	p_Device->SetRenderState(D3DRS_ZENABLE, false);
	p_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	p_Device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	p_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (p_Device->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		p_Device->EndScene();
	}

	HRESULT result = p_Device->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && p_Device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		p_Device->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}


namespace Util
{
	std::string RandomString(const int len);
	bool RenameFile(std::string& path);

}
std::string Util::RandomString(const int len)
{
	const std::string alpha_numeric(skCrypt("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"));

	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

	std::string str(len, 0);
	for (auto& it : str)
		it = alpha_numeric[distribution(generator)];

	return str;
}

bool Util::RenameFile(std::string& path)
{
	std::string newPath = ("RUST CHEAT - " + Util::RandomString(16) + ".exe"); // generate a random string
	SetConsoleTitleA(Util::RandomString(16).c_str()); // set the console title to another random string

	if (std::rename(path.c_str(), newPath.c_str())) return false; // rename the file and return false if it failed

	path = newPath; // set the value of the path argument to the new path

	return true;
}

void AimbotTridi()
{
	while (true)
	{
		//auto baseMove = driver.read<uintptr_t>(Local_Player + oPlayerMovement); //baseplayer -> basemovement
		//driver.write<float>(baseMove + 0x40, 5000.f);
		for (auto Player : enemy_list)
		{
			if (AimFov(Player) < aimfovv)
			{
				aimbott(Player);
			}
		}
		//auto Movement = driver.read<uintptr_t>(Local_Player + oPlayerMovement);
		//float speed = (driver.read<bool>(Movement + 0x146) /*swim*/ || driver.read<float>(Movement + 0x44) /* ducking */ > 0.5f) ? 1.7f : (driver.read<bool>(Movement + 0x148) /*jump*/ ? 8.f : 5.5f);// playermovmen
		//Vector3 vel = driver.read<Vector3>(Movement + 0x34);
		//speed = max(speed, vel.Length());
		///*	if (settings::misc::always_sprint) {*/
		//float len = vel.Length();
		//if (len > 0.f) {
		//	vel = Vector3(vel.x / len * speed, vel.y, vel.z / len * speed);
		//	driver.write<Vector3>(Movement + 0x34, vel);
		//}	
		//modelstate->set_flag(rust::classes::ModelState_Flag::Sprinting);
		//driver.write<uintptr_t>(Local_Player + playerflags, 16);

//	}	
	/*	if (psilent)
		{
			for (auto Player : PatrolHeli)
			{
				if (AimFov(Player) < aimfovv)
				{
					pLocalPlayerHead = LocalPlayer.BasePlayer->Position2();
					pTargetBonePos = Player->Position3();
					Vector3 pTargetAngles = CalcAngle(pLocalPlayerHead, pTargetBonePos);
					Vector2 pAngles; pAngles.x = pTargetAngles.x, pAngles.y = pTargetAngles.y;


					pTargetBonePos = Prediction(pLocalPlayerHead, Player, BoneList(head), pTargetBonePos);



					if (GetAsyncKeyState(VK_LBUTTON)) {
						auto eyes = driver.read<uintptr_t>((uintptr_t)LocalPlayer.BasePlayer + oPlayerEyes);
						Vector4 pQuatAngles = ToQuat({ pAngles.x, pAngles.y, 0.0f });
						driver.write<Vector4>(eyes + 0x44, pQuatAngles);
					}
				}
			}
		}*/
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

//enum console_color
//{
//	Black = 0,
//	Blue,
//	Green,
//	Cyan,
//	Red,
//	Magenta,
//	Brown,
//	LightGray,
//	DarkGray,
//	LightBlue,
//	LightGreen,
//	LightCyan,
//	LightRed,
//	LightMagenta,
//	Yellow,
//	White,
//};
//void set_color(const int forg_col)
//{
//	const auto h_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	if (GetConsoleScreenBufferInfo(h_std_out, &csbi))
//	{
//		const WORD w_color = (csbi.wAttributes & 0xF0) + (forg_col & 0x0F);
//		SetConsoleTextAttribute(h_std_out, w_color);
//	}
//}
//
//void set_text(const char* text, const int color)
//{
//	set_color(color);
//	printf(static_cast<const char*>(text));
//	set_color(White);
//}
//system(_xor_("cls").c_str());
//Sleep(1200);
//set_text(_xor_("Your license has been successfully activated").c_str(), Yellow);   BURASI ORNEK KISIM
//Sleep(5000);
//system(_xor_("cls").c_str());
//set_text(_xor_("Please Wait").c_str(), Yellow);

int main(int argCount, char** argVector)
{




	randomclassname2 = ("Steam");
	/*std::string filePath = argVector[0];
	if (!Util::RenameFile(filePath))
	{
		Sleep(5000);
		return -1;
	}*/

	//if (driver.get_process_module("easyanticheat.sys") || driver.get_process_module("bedaisy.sys") || driver.get_process_module("vgk.sys"))
	//{
	//	ExRaiseStatus(STATUS_ABANDONED);
	//	ExRaiseAccessViolation();
	//	*(uint32_t*)0 = 0x13376969;
	//	return 0xBADC0DE;
	//}

	SetConsoleTitle("Steam");
	int horizontal = 0, vertical = 0;
	int x = 350, y = 250; //// alta doðru
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	SetConsoleCursorInfo(out, &cursorInfo);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 15;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	system(skCrypt("color 4"));
	wcscpy_s(cfi.FaceName, skCrypt(L"Consolas"));
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 0, 0, x, y, TRUE);
	LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
	lStyle &= ~(WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	SetWindowLong(hwnd, GWL_STYLE, lStyle);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(console, &csbi);
	COORD scrollbar = {
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};
	if (console == 0)
		throw 0;
	else
		SetConsoleScreenBufferSize(console, scrollbar);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, 0, 225, LWA_ALPHA);
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);

	SetConsoleTitleA("Steam");
	mainprotect();

	std::string DosyaKonumu = (_xor_("C:\\Windows\\System\\RustPrivateLicense.txt"));

	KeyAuthApp.init();
	EnBasaDon:
	std::string License;
	FILE* Dosya;
	if (Dosya = fopen((DosyaKonumu.c_str()), skCrypt("r"))) {
		std::ifstream DosyaOku(DosyaKonumu.c_str());
		std::string Anahtar;	
		std::getline(DosyaOku, Anahtar);
		DosyaOku.close();
		fclose(Dosya);
		License = Anahtar;
		goto LisansaGit;
	}
	else
	{
		SetConsoleTitleA(skCrypt("  "));

		system(skCrypt("cls"));
		std::cout << skCrypt("\n\n  [+] Connecting..");
		std::cout << skCrypt("\n\n  [+] Enter License: ");
		std::cin >> License;
	LisansaGit:
		std::ofstream key; key.open(DosyaKonumu.c_str());
		key << License;
		key.close();
		KeyAuthApp.license(License);
		if (!KeyAuthApp.data.success)
		{
			std::cout << _xor_("\n Status: ").c_str() + KeyAuthApp.data.message;
			Sleep(1500);
			remove(DosyaKonumu.c_str());
			goto EnBasaDon;
			//exit(0);
		}
		system(skCrypt("cls"));
		Sleep(300);
		std::cout << skCrypt("\n\n  [+] License Activated.") << std::endl;;
	}

r8:
	if (!driver.init())
	{
	r7:
		if (FindWindowA(skCrypt("UnityWndClass"), NULL))
		{
			printf(skCrypt("[>] Close Rust...\n"));
			Sleep(1000);
			goto r7;	
		}
		if (LoadDriver())
		{
			printf(skCrypt("[>] Driver loaded!\n"));
			Sleep(1000);
			//system(skCrypt("cls"));
			goto r8;
		}
	}

	HWND Entryhwnd = NULL;
	while (Entryhwnd == NULL)
	{
		printf(skCrypt("[>] Open Rust\n"));
		Sleep(1);
		g_pid = get_pid("RustClient.exe");
		//printf(skCrypt("[>] pid: %d\n"), g_pid);
		Entryhwnd = get_process_wnd(g_pid);
		Sleep(1);
	}
	driver.attach(g_pid);
	setup_window();
	init_wndparams(MyWnd);
	g_assembly = driver.get_process_module(skCrypt("GameAssembly.dll"));
	g_unityplayer = driver.get_process_module(skCrypt("UnityPlayer.dll"));
	if (!g_assembly) { printf(skCrypt("[>] GameAssembly can't found!\n")); return 0; }
	if (!g_unityplayer) { printf(skCrypt("[>] UnityPlayer can't found\n")); return 0; }
	//printf("[>] GameAssembly: 0x%p\n[>] Unityplayer: 0x%p\n", g_assembly, g_unityplayer);
	::SetWindowPos(GetConsoleWindow(), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_HIDEWINDOW);
	//std::thread(omni).detach();
	std::thread(Hilee).detach();
	std::thread(cheat).detach();
	std::thread(AimbotTridi).detach();
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));	
	stylemenu2();
	//ImGui::StyleColorsDark();

	Snowflake::CreateSnowFlakes(snow, SNOW_LIMIT, 5.f/*minimum size*/, 10.f/*maximum size*/, 0/*imgui window x position*/, 0/*imgui window y position*/, ScreenCenterX * 2, ScreenCenterY * 2, Snowflake::vec3(0.f, 0.005f)/*gravity*/, IM_COL32(8, 232, 222, 50)/*color*/);

	while (Message.message != WM_QUIT)
	{

		if (PeekMessage(&Message, MyWnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();


		if (hwnd_active == GameWnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(MyWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
	

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(GameWnd, &rc);
		ClientToScreen(GameWnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = GameWnd;
		io.DeltaTime = 1.0f / 60.0f;

		
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;
		if (GetAsyncKeyState(0x1)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom) {

			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			p_Params.BackBufferWidth = Width;
			p_Params.BackBufferHeight = Height;
			SetWindowPos(MyWnd, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			p_Device->Reset(&p_Params);
		}
		render();
		Sleep(10);
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	cleanup_d3d();
	DestroyWindow(MyWnd);
	return Message.wParam;
}