/*

	About: player spawn system
	Author:	ziggi

*/

#if defined _pl_spawn_included
	#endinput
#endif

#define _pl_spawn_included
#pragma library pl_spawn

// ���� �������
#define SPAWN_HOUSE_NONE	-1
#define SPAWN_HOUSE_GANG	-2

enum camera_PlaceArray_Info {
	camera_Interior,
	Float:camera_pos_X,
	Float:camera_pos_Y,
	Float:camera_pos_Z,
	Float:camera_look_X,
	Float:camera_look_Y,
	Float:camera_look_Z,
}

new camera_PlaceArray[][camera_PlaceArray_Info] = {
	{0,		-2785.616943, 26.270446, 17.054141,		-2775.761230, 15.552896, 12.677975},
	{0,		-785.4092, 1668.5923, 67.8387,			-785.9841, 1667.7692, 67.6387},
	{0,		1937.4159, 1251.2012, 97.4819,			1938.1495, 1251.8807, 97.0875}
};

enum spawns_Info {
	Float:spawn_x,
	Float:spawn_y,
	Float:spawn_z,
	Float:spawn_a
}

static Float:spawns_array[][spawns_Info] = {
	{2517.5344, -1694.0607, 18.4772, 47.2527},
	{2494.6113, -1694.2920, 23.5697, 7.8082},
	{2524.2092, -1675.8125, 19.9302, 65.8183},
	{2066.9448, -1700.1219, 14.1484, 276.0525},
	{2065.0754, -1732.0588, 18.7969, 308.6771},
	{2042.3877, -1722.0016, 13.5469, 339.7588},
	{2040.6575, -1646.1099, 13.5469, 1.2393},
	{1641.0234, -1545.1201, 13.5803, 293.5606},
	{1585.7887, -1539.0266, 13.5864, 265.2574},
	{1606.7871, -1476.6110, 13.5804, 0.8114},
	{1885.8452, -1087.4312, 23.9185, 279.8816},
	{2008.4741, -1098.7870, 24.9058, 256.2135},
	{2045.3113, -1158.0294, 23.4437, 145.6347},
	{2022.5231, -1210.7472, 21.7610, 35.7139},
	{1933.6676, -1226.6060, 20.1364, 97.0786},
	{1332.1099, -911.0746, 39.5781, 168.9972},
	{1309.1066, -847.0045, 64.8932, 315.8327},
	{1285.2598, -830.9579, 83.1406, 171.4035},
	{1243.5209, -743.7954, 94.9519, 191.1576},
	{655.1062, -543.5223, 16.3281, 349.4992},
	{702.5857, -463.9641, 16.3359, 189.5556},
	{852.9753, -587.0893, 18.0406, 8.3576},
	{744.7605, -582.7914, 16.9987, 84.0696},
	{248.1220, -278.0332, 1.5781, 52.9390},
	{326.3771, -53.1227, 1.5285, 111.6351},
	{214.2944, -89.7956, 1.5710, 312.5051},
	{614.6899, 43.1528, 0.0748, 344.7167},
	{867.4291, -30.7355, 63.1953, 176.7125},
	{1011.3226, 11.4864, 93.0156, 302.5121},
	{751.2596, 383.9003, 23.1719, 335.8973},
	{1222.3271, 300.4901, 19.5547, 155.6648},
	{1284.9962, 175.7558, 20.3423, 73.2174},
	{1426.9465, 371.7816, 18.8869, 257.0709},
	{1572.3761, 36.5942, 24.5907, 242.6472},
	{2215.1565, 123.8511, 26.4844, 350.1021},
	{2281.3704, -49.9920, 27.0176, 207.7730},
	{2162.9019, -102.3568, 2.7500, 27.7265},
	{2459.7744, -40.9547, 26.4844, 25.8460},
	{1958.3783, 1343.1572, 15.3746, 0.0},
	{2199.6531, 1393.3678, 10.8203, 0.0},
	{2483.5977, 1222.0825, 10.8203, 0.0},
	{2637.2712, 1129.2743, 11.1797, 0.0},
	{2000.0106, 1521.1111, 17.0625, 0.0},
	{2024.8190, 1917.9425, 12.3386, 0.0},
	{2261.9048, 2035.9547, 10.8203, 0.0},
	{2262.0986, 2398.6572, 10.8203, 0.0},
	{2244.2566, 2523.7280, 10.8203, 0.0},
	{2335.3228, 2786.4478, 10.8203, 0.0},
	{2150.0186, 2734.2297, 11.1763, 0.0},
	{2158.0811, 2797.5488, 10.8203, 0.0},
	{1969.8301, 2722.8564, 10.8203, 0.0},
	{1652.0555, 2709.4072, 10.8265, 0.0},
	{1564.0052, 2756.9463, 10.8203, 0.0},
	{1271.5452, 2554.0227, 10.8203, 0.0},
	{1441.5894, 2567.9099, 10.8203, 0.0},
	{1480.6473, 2213.5718, 11.0234, 0.0},
	{1400.5906, 2225.6960, 11.0234, 0.0},
	{1598.8419, 2221.5676, 11.0625, 0.0},
	{1318.7759, 1251.3580, 10.8203, 0.0},
	{1558.0731, 1007.8292, 10.8125, 0.0},
	{1705.2347, 1025.6808, 10.8203, 0.0}
};

stock pl_spawn_OnPlayerRequestClass(playerid, classid)
{
	#pragma unused classid
	if (player_IsLogin(playerid)) {
		TogglePlayerSpectating(playerid, 1);
		SetSpawnInfo(playerid, 0, player_GetSkin(playerid), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		TogglePlayerSpectating(playerid, 0);
		return 0;
	}

	// clean chat
	chat_Clean(playerid);

	// hide class selection buttons
	TogglePlayerSpectating(playerid, 1);
	SetSpawnInfo(playerid, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	// set camera pos
	SetTimerEx("pl_spawn_UpdateCamera", 200, 0, "d", playerid);
	return 1;
}

stock pl_spawn_OnPlayerDeath(playerid, killerid, reason)
{
	#pragma unused killerid, reason
	SetPVarFloat(playerid, "Coord_X", 0.0);
	SetPVarFloat(playerid, "Coord_Y", 0.0);
	SetPVarFloat(playerid, "Coord_Z", 0.0);
	SetPVarFloat(playerid, "Coord_A", 0.0);
}

DialogCreate:PlayerSpawnMenu(playerid)
{
	new string[ MAX_NAME * (MAX_PLAYER_HOUSES + 1) + 8 + (2 * (MAX_PLAYER_HOUSES + 1)) ],
		count = 0,
		playername[MAX_PLAYER_NAME+1];
	
	GetPlayerName(playerid, playername, sizeof(playername));
	
	new gangid = player_GetGangID(playerid);
	new gang_houseid = -1;

	if (gangid != 0) {
		gang_houseid = gang_GetHouseID(gangid);
		if (gang_houseid != -1) {
			count++;
			strcat(string, "[�����] ", sizeof(string));
			strcat(string, house_GetName(gang_houseid), sizeof(string));
			strcat(string, "\n", sizeof(string));
		}
	}

	for (new i = 0; i < house_GetCount(); i++) {
		if (gang_houseid != i && (!strcmp(house_GetOwner(i), playername, true) || !strcmp(house_GetRenter(i), playername, true))) {
			count++;
			strcat(string, house_GetName(i), sizeof(string));
			strcat(string, "\n", sizeof(string));
		}
	}

	if (count < 1) {
		Dialog_MessageEx(playerid, Dialog:PlayerReturnMenu, "���� ������ ������", "� ��� ��� ��������� �������", "�����", "������");
		return 1;
	}

	Dialog_Open(playerid, Dialog:PlayerSpawnMenu, DIALOG_STYLE_LIST,
		"���� ������ ������",
		string,
		"��", "�����"
	);
	return 1;
}

DialogResponse:PlayerSpawnMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:PlayerMenu);
		return 1;
	}

	new playername[MAX_PLAYER_NAME + 1];
	GetPlayerName(playerid, playername, sizeof(playername));
	
	new gangid = player_GetGangID(playerid);
	if (listitem == 0 && gangid != 0 && gang_GetHouseID(gangid) != -1) {
		player_SetSpawnHouseID(playerid, SPAWN_HOUSE_GANG);
		SendClientMessage(playerid, COLOUR_WHITE, "����� ������ ��������.");
		return 1;
	}
	
	new count = 0;
	if (gangid != 0 && gang_GetHouseID(gangid) != -1) {
		count++;
	}

	for (new i = 0; i < house_GetCount(); i++) {
		if (gang_GetHouseID(gangid) == i || strcmp(house_GetOwner(i), playername, true) && strcmp(house_GetRenter(i), playername, true)) {
			continue;
		}

		if (listitem == count) {
			player_SetSpawnHouseID(playerid, i);
			SendClientMessage(playerid, COLOUR_WHITE, "����� ������ ��������.");
			// ���� �����, ��������� ����� - ����� �����, �� ������������� ����� ����� ���� ���
			if (gang_IsLeader(playerid)) {
				gang_SetHouse(player_GetGangID(playerid), i);
				SendClientMessage(playerid, COLOUR_WHITE, "����� ������ ��� ����� ��������.");
			}
			return 1;
		}

		count++;
	}
	return 1;
}

stock pl_spawn_SetSpawnPos(playerid)
{
	SetPlayerInterior(playerid, 0);
	SetPlayerFacingAngle(playerid, GetPVarFloat(playerid, "Coord_A"));

	if (GetPVarFloat(playerid, "Coord_Z") > 900.0) {
		SetPVarFloat(playerid, "Coord_X", 0.0);
		SetPVarFloat(playerid, "Coord_Y", 0.0);
		SetPVarFloat(playerid, "Coord_Z", 0.0);
	}

	if (GetPVarFloat(playerid, "Coord_X") != 0.0 && GetPVarFloat(playerid, "Coord_Y") != 0.0 && GetPVarFloat(playerid, "Coord_Z") != 0.0) {
		oSetPlayerPos(playerid, GetPVarFloat(playerid, "Coord_X"), GetPVarFloat(playerid, "Coord_Y"), GetPVarFloat(playerid, "Coord_Z"));
		return 1;
	}

	new house_id = player_GetSpawnHouseID(playerid);
	if (house_id >= 0 && !IsPlayerHouse(playerid, house_id) && !IsPlayerRenter(playerid, house_id)) {
		house_id = SPAWN_HOUSE_NONE;
		player_SetSpawnHouseID(playerid, SPAWN_HOUSE_NONE);
		SendClientMessage(playerid, COLOUR_RED, lang_texts[8][60]);
	}

	if (house_id == SPAWN_HOUSE_NONE) {
		pl_spawn_SetPosByID(playerid, pl_spawn_GetRandomID());
	} else if (house_id == SPAWN_HOUSE_GANG) {
		new gangid = player_GetGangID(playerid);
		new gang_houseid = gang_GetHouseID(gangid);

		if (gangid == 0 || gang_houseid == -1) {
			player_SetSpawnHouseID(playerid, SPAWN_HOUSE_NONE);
		} else {
			SetPlayerPosToHouse(playerid, gang_houseid);
		}
	} else {
		SetPlayerPosToHouse(playerid, house_id);

		new tmp[MAX_STRING];
		format(tmp, sizeof(tmp),
			lang_texts[8][51],
			house_GetName(house_id), house_GetUpKeepLeft(house_id), house_GetUpKeepMax(house_id)
		);
		SendClientMessage(playerid, COLOUR_RED, tmp);
	}
	return 1;
}

stock pl_spawn_GetRandomID()
{
	return random( sizeof(spawns_array) + 1 );
}

stock pl_spawn_SetPosByID(playerid, spawnid)
{
	SetPlayerPosEx(playerid, spawns_array[spawnid][spawn_x], spawns_array[spawnid][spawn_y], spawns_array[spawnid][spawn_z], spawns_array[spawnid][spawn_a], 0, 0);
}

forward pl_spawn_UpdateCamera(playerid);
public pl_spawn_UpdateCamera(playerid)
{
	new camera_id = random( sizeof(camera_PlaceArray) );
	SetPlayerInterior(playerid, camera_PlaceArray[camera_id][camera_Interior]);
	SetPlayerCameraPos(playerid, camera_PlaceArray[camera_id][camera_pos_X], camera_PlaceArray[camera_id][camera_pos_Y], camera_PlaceArray[camera_id][camera_pos_Z]);
	SetPlayerCameraLookAt(playerid, camera_PlaceArray[camera_id][camera_look_X], camera_PlaceArray[camera_id][camera_look_Y], camera_PlaceArray[camera_id][camera_look_Z]);
}

stock player_IsSpawned(playerid) {
	return (GetPVarInt(playerid, "Spawned") == 1 ? 1 : 0);
}

stock player_SetSpawned(playerid, isspawned) {
	SetPVarInt(playerid, "Spawned", isspawned);
}

stock player_GetSpawnHouseID(playerid) {
	return GetPVarInt(playerid, "SpawnHouseID");
}

stock player_SetSpawnHouseID(playerid, houseid) {
	SetPVarInt(playerid, "SpawnHouseID", houseid);
}