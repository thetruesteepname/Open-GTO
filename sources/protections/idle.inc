/*

	Aurthor:	Iain Gilbert
	Modified by ziggi

*/

#if defined _antiidle_included
	#endinput
#endif

#define _antiidle_included
#pragma library antiidle


static
	IsEnabled = ANTI_IDLE_ENABLED,
	MaxTime = MAX_IDLE_TIME;

stock pt_idle_LoadConfig(file_config)
{
	ini_getInteger(file_config, "Protection_Idle_IsEnabled", IsEnabled);
	ini_getInteger(file_config, "Protection_Idle_MaxTime", MaxTime);
}

stock pt_idle_SaveConfig(file_config)
{
	ini_setInteger(file_config, "Protection_Idle_IsEnabled", IsEnabled);
	ini_setInteger(file_config, "Protection_Idle_MaxTime", MaxTime);
}

stock pt_idle_OnGameModeInit()
{
	if (!IsEnabled) {
		return 0;
	}

	GameMSG("SERVER: (protections)AntiIdle module init");
	return 1;
}

stock pt_idle_PlayerTimer(playerid)
{
	if (!IsEnabled) {
		return 0;
	}

	if (Groundhold_IsEnabled == 1 && IsPlayerInAnyGround(playerid) && !IsPlayerRconAdmin(playerid)) {
		new
			Float:pos[3],
			Float:idle_pos[3],
			string[MAX_STRING];

		GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
		
		idle_pos[0] = GetPVarFloat(playerid, "playerIdlePos_X");
		idle_pos[1] = GetPVarFloat(playerid, "playerIdlePos_Y");
		idle_pos[2] = GetPVarFloat(playerid, "playerIdlePos_Z");

		if (pos[0] == idle_pos[0] && pos[1] == idle_pos[1] && pos[2] == idle_pos[2]) {
			GivePVarInt(playerid, "playerIdle", 1);
			
			if (GetPVarInt(playerid, "playerIdle") > MaxTime - 1) {
				format(string, sizeof(string), lang_texts[11][1], MaxTime - 1);
				SendClientMessage(playerid, COLOUR_RED, string);
				SendClientMessage(playerid, COLOUR_RED, lang_texts[11][2]);
			}
			if (GetPVarInt(playerid, "playerIdle") > MaxTime) {
				SetPVarInt(playerid, "playerIdle", 0);
				KickPlayer(playerid, lang_texts[11][3]);
			}
		} else {
			SetPVarInt(playerid, "playerIdle", 0);
		}

		SetPVarFloat(playerid, "playerIdlePos_X", pos[0]);
		SetPVarFloat(playerid, "playerIdlePos_Y", pos[1]);
		SetPVarFloat(playerid, "playerIdlePos_Z", pos[2]);
   	}
   	return 1;
}
