/*
	
	��������: ������� � ��������� �� ���������
	�����: ziggi

*/

#if defined _config_included
	#endinput
#endif

#define _config_included
#pragma library config

#pragma tabsize 0
#pragma dynamic 13000

#define VERSION					"v2.0.0 alpha" // ������ ����
#define GTO_FILES_FORMAT		".gto" // ����������(.txt ��� ������������ ������ �� ���� GNU/Linux �� �������������)
#define GTO_FILES_FOLDER		"Open-GTO/" // �����, ��� �������� ����� Open-GTO, � scriptfiles/

#define LANGUAGE_USE			"Russian" // ������������ ����

#define MAX_STRING				160 // �� ������, ���-�� �������� ��� ����������� ��������� ����������
#define MAX_NAME				40 // ���-�� �������� ��� ���, ������� � ��.
#define MAX_IP					16 // ������������ ���������� �������� ��� IP ������

#define USE_PASSWORD_ENCRYPT // ���� �����������, �� ������ � ����� ������ ����� �����������
#if defined USE_PASSWORD_ENCRYPT
new ENCRYPTION_KEY[] = "_C)2^K�RPXjwE8b\\p{Df+=Q3(O*vgu9ZH[!1\"Le0->?/hSF<'xVzm]$4%5a`Jdny�IUW@G7s6&l:k;i~ YsoM�.cBq#|}NrTtA, ";
#endif

#define SERVER_REAL_TIME			1 // ������� ����� ������������� �������� ������� �������
#define SERVER_REAL_TIME_OFFSET		0 // �������� ������� ������������ �������

#define MAX_PLAYER_LOGIN_ATTEMPT	3 // ������������ ���������� ������� �����

#define MAX_MONEY				999999999 // ������������ ���-�� �����, ������� ����� ����� �����
#define MIN_SEND_SYMBOLS		3 // ����������� ���-�� ������������ �������� � ��
#define MAX_SEND_SYMBOLS		100 // ������������ ���-�� ������������ �������� � ��

#define MAX_QUESTS				255

#define WORLD_SAVE_TIME			300000		// 1 ���, �� ��� ���-�� ���������� ����������� ���������� ����� ����(300000 - 5 �����)
#define GameMSG_USE_PRINT // ���� ����������, �� ������� GameMSG ������� ��������� � ������� �������
//#define DebugMSG_USE_PRINT // ���� ����������, �� ������� DMSG ������� ��������� � ������� �������

// ����(��������� �� ���������) 1 ���, 0 ����
#define LOGGING_GAME_LOG_ENABLED	1 // ����������� ��������� ���������
#define LOGGING_DEBUG_LOG_ENABLED	1 // ����������� ���������� ���������
#define LOGGING_CHAT_LOG_ENABLED	1 // ����������� ��������� � ���
#define LOGGING_CMD_LOG_ENABLED		1 // ����������� �������� ������

// �������(��������� �� ���������), � ������ ������������...
#define ANTI_HEALTH_HACK_ENABLED	1 // ������ �� ���� �� ��������

#define ANTI_HIGH_PING_ENABLED		1 // ������ �� �������� �����
#define MAXIMAL_PING				500 // ����, ��� ������� ������

#define ANTI_IDLE_ENABLED			1 // ������ �� ��� �� ������ ��������
#define MAX_IDLE_TIME				5 // ���-�� �����, ����� ������� ������

#define CHAT_GUARD_ENABLED			1 // ������ ����
#define ANTI_JETPACK_ENABLED		1 // ������ �� ������������� JetPack
#define ANTI_RCON_HACK_ENABLED		1 // ������ �� ������ rcon ������
#define ANTI_ARMOUR_HACK_ENABLED	1 // ������ �� ���� �� �����
#define ANTI_WEAPON_HACK_ENABLED	1 // ������ �� ���� �� ������ � �������

#define ANTI_SPEED_HACK_ENABLED		0 // ������ �� speedhack, airbreak, ������������(���� ����������� ������ ������������, �������������� �������� ����)
#define ANTI_SPEED_HACK_CHECK_TIME	900 // ����� ������� ��� ������ �� ��������, �� ���������� ��������� 1000
										// ��� ����� ����������� �������� ����� ������������� ���� ������� ��������


// ��������� � ������
#define VEHICLE_FUEL_ENABLED	1
#define VEHICLE_FUEL_TD_FONT	2 // ������������ id ������ � ����������
#define VEHICLE_FUEL_SPEED		2 // ���������� �������, ������������� �� 1 �������
#define VEHICLE_FUEL_TARIF		10 // ���� ������ ����� �������, � ��������

// ������
#define MAX_GULPS			3 // ������������ ���������� ������� �� �������

// admin
#define ADMIN_TELEPORT_ENABLED		1 // ��������-�� ������� ������������ ������������� �� ����� �� �����
#define ADMIN_TELEPORT_MIN_STATUS	STATUS_LEVEL_ADMIN // ����������� ������� ������� ��� ������������

// �������
#define LOTTERY_ENABLED		1 // �������-�� ������ �������
#define LOTTERY_TIME		10 // ����� ���������, � �������
#define LOTTERY_WIN_MONEY	200000 // ���������� ����� ���������� � �������
#define LOTTERY_TICKET_COST	5000 // ���� ����������� ������

// skins
#define SKINS_COST			0 // ���� ������� �����
#define SKINS_IGNORE		0, 74  // ������ ������������ ������
#define SKINS_MAXID			299
#define SKINS_MINID			1
#define PLAYER_DEFAULT_SKIN	95

#define GROUNDHOLD_ENABLED		1 // ����� ��������
#define GROUNDHOLD_HOLD_TIME	2 // �������� ������ ����� ��� ������ �� ����

#define BANK_PROFIT			2 // ������� ���������� ������� �� �������� � �����
#define BANK_PROFIT_VIP		(BANK_PROFIT * 2) // ������� ���������� ������� �� �������� � ����� ��� ������� � VIP
#define MAX_BANK_MONEY		1000000000 // ������������ ���������� �����, ������� ����� ������� � �����

#define PAYDAY_BASE_PAY		25 // PayDay ����� �� ������
#define PAYDAY_CUTOFF		MAX_MONEY / 2 // ���-�� �����, ��� ������� ���������� �������� ������ �� PayDay
#define	PAYDAY_PAYXP		200 // PayDay ����� �� ����

#define CHAT_SHOW_ID		"(%d)" // ��� ����������� ��� � ����

#define WEAPON_SKILL_ENABLED	1 // �������� �������� ������ (���� ���������, �� ������ �� ���������)
#define WEAPON_SKILL_SPEED		10 // ���������� ��������� ������ �� ���� ��������
#define WEAPON_DROP_ENABLED		1 // �������� ��������� ������
#define WEAPON_DROP_TIME		10 // �����, ����� �������� �������� ������, �������� �� ������, � ��������
#define WEAPON_DROP_BULL		5 // ������� ��������� ���������� ������ ������� �� ������
#define MAX_DROPPED_WEAPONS		64 // ������������ ���������� ��������� ������ �������������(� ���� �������)

#define SKYDIVE_TIME		5 // �����, ����� ������� ����� ����� ����� ������������ /skydive, � �������

#define SYS_WEATHER_UPDATE	20 // �����, ����� ������� ��������� ��������� ������, � �������, ���� 0, �� ���������

#define TELEPORTS_PAUSE_TIME	300 // ����� ����� ����������������, ����� ������� ����� ��������� �����������������, � ��������

// ����������� ������� � ���������
#define ALLOWED_STRING_SYMBOLS		'a'..'z','A'..'Z','0'..'9','_','[',']','=','(',')',' '
#define ALLOWED_STRING_SYMBOLS_STR	"'a'..'z','A'..'Z','0'..'9','_','[',']','=','(',')',' '"
#define ALLOWED_NICK_SYMBOLS		'a'..'z','A'..'Z','0'..'9','_','[',']','.','=','(',')'
#define ALLOWED_NICK_SYMBOLS_STR	"'a'..'z','A'..'Z','0'..'9','_','[',']','.','=','(',')'"
// ����������� ������(by wups, ��������������)
#define MAPICON_PAY_SPRAY
#define MAPICON_TUNE
//

// ����
#define MAX_PLAYER_HOUSES			3 // ���������� �����, ������� ����� ����� �����(����� ������� �� �������������)
#define HOUSE_UPGRADE_ARMOUR_COST	100000
#define HOUSE_UPGRADE_HEALTH_COST	100000
#define HOUSE_UPGRADE_USE_TIME		300 // ����� ����� ������� ����� ������������ ������� � ���� (� ��������)
//#define BUY_ALL_HOUSES // ��������� ��������� �������� ����� ����(���� ���������������� �� ����� ���� ������ ��������)
//

// �������
#define MAX_PLAYER_BUSINESS		3 // ���������� ��������, ������� ����� ����� �����(����� ������� �� �������������)
#define MAX_BUSINESS_LEVEL		30 // ������������ ������� �������� �������
#define UPGRADE_TARIF			10 // ����� ����� �� ��������� ������, �������: (Businesses[id][Business_Upgrade]+1) * Businesses[id][Business_Value] * UPGRADE_TARIF
//#define BUY_ALL_BUSINESS // ��������� ��������� �������� ����� �������(���� ���������������� �� ����� ������� ������ ��������)
#define BUSINESS_UNLOGIN_SELL_DAYS	14 // ���������� ����, ����� ������� ������ ����� ������, ���� ����� �� ������ � ����
//

// ���������
#define CARS_RESPAWN_TIME	600 // ����� �������� ���������� � �������� (86400 - ���� ����) 
#define OLD_ENGINE_DO // ��� � ��������� - ��������, ����� - ������(���� �����������)

// ��������� � VEHICLE_LIGHTS_ON_TIME � VEHICLE_LIGHTS_OFF_TIME �������� 0, ���� ������, ����� ���� ���������� � ����� �����
#define VEHICLE_LIGHTS_ON_TIME		16 // �����(�����), ����� ���� ���������� ����� ������������� ����������
#define VEHICLE_LIGHTS_OFF_TIME		7 // �����(�����), ����� ���� ���������� ����� ������������� �����������

#define VEHICLE_DAMAGE_ENABLE_TIRES // �������� ������������ ��� � ������� ����������
//#define VEHICLE_DAMAGE_ENABLE_DAMAGE // �������� ���� � ������� ����������
//
#define MAX_PLAYER_VEHICLES			4 // ������������ ���������� ������� ����������
#define VEHSHOP_CAR_CHANGE_TIME		3 // ���������� �����, ����� ������� ��������� � �������� ��������

// �����
#define MAX_GANGS			MAX_PLAYERS // �������� ���� ������
#define MAX_GANG_SIZE		12 // ������������ ���-�� ����� � �����

#define MIN_GANG_NAME_LEN	3 // ����������� ����� ����� �����
#define MAX_GANG_NAME_LEN	40 // ������������ ����� ����� �����

#define MAX_GANG_MOTD_LEN	64 // ������������ ����� ���������� �����

#define GANG_CREATE_COST	500000 // ���-�� �����, ��������� �� �������� �����
#define GANG_COLOUR_COST	20000 // ���-�� �����, ��������� �� ����� ����� �����

#define MAX_GANG_BANK		2000000000 // ������������ ���������� �����, ������� ����� ������� � ����� �����
//

// �����
#define MIN_HEALTH				35.0 // �����������(���������) ���-�� ��������
#define MAX_HEALTH				100.0 // ������������ ���-�� ��������
#define HEALTH_TARIF			3.0	// ������� ���������� ������������� �������� �� ���, �������: MIN_HEALTH + (GetPlayerLevel(playerid) * HEALTH_TARIF)
#define HEALTH_REGEN_TARIF		0.1 // ������� ���-�� ����������������� ��������, �������: (GetPlayerLevel(id) * HEALTH_REGEN_TARIF)

#define CHANGE_NICK_COST		100000 // ���-�� �����, ��������� ��� ����� ����
#define MIN_PLAYER_NAME			3
#define CHANGE_PASS_COST		5000 // ���-�� �����, ��������� ��� ����� ������
#define MIN_PASS_LEN			3
#define MAX_PASS_LEN			40

#define MIN_REPORTS_FOR_JAIL	3 // ����������� ���������� �������� ��� ������� � ������

#define PLAYER_XP_VIP_PROFIT	10 // vip ������ �������� �� PLAYER_XP_VIP_PROFIT ��������� ������ �����
// ������
	// trucker
	#define TRUCKER_ENABLED					1
	#define TRUCKER_XP_RATE					20 // ���-�� ����� �� �����, �������: ( (GetPlayerLevel(playerid)+1) * 2 )^2 * trucker_GIVE_XP_RATE
	#define TRUCKER_MONEY_RATE				10
	#define TRUCKER_MONEY_PENALTY			2000 // ���-�� ����� ���������� ��� ������������ ��������
	#define TRUCKER_TIME_GET_TRAILER		120 // ���-�� ������, �������� �� ����������� ���� � ������
	#define TRUCKER_MISSION_TRY_COUNT		2 // ���-�� ���������� � ������������� ������ �� ��������
	#define TRUCKER_MISSION_TIME			480 // ����� �������� �� ����������� ������
	#define TRUCKER_RUNNER_MISSION_TIME		300 // ����� �������� ����� ��������, � ��������
	#define TRUCKER_CAR_SPAWN_TIME			300
	//

	// �������
	#define SWAGUP_ENABLED		1 // �������� �� ������� ������
	#define SWAGUP_MONEY_RATE	30 // �������� ���������� �����, �� �������� �������
	#define SWAGUP_XP_RATE		30 // �������� ���������� �����, �� �������� �������
	#define SWAGUP_PAUSE_TIME	480000
	//
	
//
// ��� ������
#define PLAYER_XP_DEATH_MINUS_PROC		3 // ������� ��������� XP ��������� �� ��� ���������� �����
#define PLAYER_MONEY_DEATH_MINUS_PROC	20 // ������� ��������� ����� ���������
#define PLAYER_XP_KILL_TARIF			5 // �������� �� ���������� ����������� ����� ��� ��������, ��������� � ������� player_OnPlayerKill

// ��������� ��������� ������
#define FIRST_LEVEL				1 // �������, ������� ����� ������ ����� �����������
#define PLAYER_START_MONEY		1500 // ���-�� ��������� �����

#define MAX_COUNTDOWN		4 // ���-�� ������ ��� ������� ����� � ��
#define KEY_USING			KEY_YES // ������ 'Y' - �������� �� �������� ��������(����, ������� ����������...), ������/�������
#define KEY_NAME			"Y"
#define PICKUP_TEXT			"\n{33AA33}������� ������ '{FFFFFF}"KEY_NAME"{33AA33}'"

stock Text3D:CreatePickupText(text[], Float:pos_x, Float:pos_y, Float:pos_z)
{
	new string[MAX_STRING];
	format(string, sizeof(string), "%s%s", text, PICKUP_TEXT);
	return Create3DTextLabel(string, 0xFFFFFFFF, pos_x, pos_y, pos_z, 20.0, 0, 1);
}

enum clickText_Info {
	Text:sshop_left,
	Text:sshop_right,
	Text:sshop_buy,
	Text:sshop_list,
	Text:sshop_exit,
}

new Text:clickText[clickText_Info];

// ������
#define SPECIAL_ACTION_PISS	68

// �������������� ������� '���' mxINI
#define ini_fileRemove	fremove
#define ini_fileExist	fexist

// �� �������
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
