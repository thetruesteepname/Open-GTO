/*

	Created: 07.04.2011
	Author: ziggi
	
*/

#if defined _player_menu_included
  #endinput
#endif

#define _player_menu_included
#pragma library player_menu


DialogCreate:PlayerMenu(playerid)
{
	Dialog_Open(playerid, Dialog:PlayerMenu, DIALOG_STYLE_LIST,
		"���� ������",
		"���������� � ���������\n\
		�����\n\
		����� ������\n\
		��������\n\
		���������\n\
		��������� ������\n\
		����� ������\n\
		��� �������\n\
		��� ���������\n\
		������������� ������\n\
		���������\n\
		������",
		"��", "������"
	);
}

DialogResponse:PlayerMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		return 1;
	}

	switch (listitem) {
		// ���������� � ���������
		case 0: {
			new vip_status[MAX_NAME];
			if (GetPlayerVIP(playerid) == 1) {
				format(vip_status, sizeof(vip_status), "�� %s", GetPlayerVIPDate(playerid));
			} else {
				set(vip_status, "���");
			}

			new Float:kill_on_death = 0.0;
			if (player_GetDeaths(playerid) != 0) {
				kill_on_death = float(player_GetKills(playerid)) / float(player_GetDeaths(playerid));
			}

			new fstylename[MAX_STRING];
			fights_GetNameByLevel( pl_fights_GetPlayerStyleUsed(playerid) , fstylename);
			
			new string[1024];
			format(string, sizeof(string),
				"�������: %d, ���� �� ������: %d\n\
				\n\
				�����: %s\n\
				\n\
				������: $%d, ������ � �����: $%d. ����� �����: $%d\n\
				\n\
				�������: %d, �������: %d (%.2f%%)\n\
				�����: %d\n\
				�����: %d\n\
				\n\
				����� ������: %s\n\
				VIP ������: %s",
				GetPlayerLevel(playerid),
				GetXPToLevel(playerid, GetPlayerLevel(playerid) + 1),
				
				player_GetGangName(playerid),
				
				oGetPlayerMoney(playerid), GetPlayerBankMoney(playerid), GetPlayerTotalMoney(playerid),
				
				player_GetKills(playerid), player_GetDeaths(playerid), kill_on_death,
				player_GetJailCount(playerid),
				player_GetMuteCount(playerid),
				
				fstylename,
				vip_status
			);

			Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX, "���������� � ���������", string, "�����", "�����");
			return 1;
		}
		// �����
		case 1: {
			Dialog_Show(playerid, Dialog:GangMenu);
			return 1;
		}
		// ����� ������
		case 2: {
			Dialog_Show(playerid, Dialog:PlayerFights);
			return 1;
		}
		// ��������
		case 3: {
			Dialog_Show(playerid, Dialog:AnimLib);
			return 1;
		}
		// ���������
		case 4: {
			if (GetPVarInt(playerid, "teleports_Pause") == 1) {
				Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX, "���� ����������", "�� ������� �����������������, �����...", "�����", "�����");
				return 0;
			}
			Dialog_Show(playerid, Dialog:PlayerTeleportMenu);
			return 1;
		}
		// ��������� ������
		case 5: {
			oResetPlayerWeapons(playerid);
			Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX, "��������� ������", "�� ����������� ���������� �� ����� ������.", "�����", "�����");
			return 1;
		}
		// ����� ������
		case 6: {
			Dialog_Show(playerid, Dialog:PlayerSpawnMenu);
			return 1;
		}
		// ��� �������
		case 7: {
			Dialog_Show(playerid, Dialog:BusinessPlayerOwned);
			return 1;
		}
		// ��� ���������
		case 8: {
			Dialog_Show(playerid, Dialog:PlayerVehicleMenu);
			return 1;
		}
		// ������������� ������
		case 9: {
			new idsa = 0,
				idsm = 0,
				admins[(MAX_PLAYER_NAME + 1 + 5) * 10],
				moders[(MAX_PLAYER_NAME + 1 + 5) * 10];
			
			foreach (new id : Player) {
				if (IsPlayerAdm(id)) {
					format(admins, sizeof(admins), "%s%s(%d)\n", admins, oGetPlayerName(id), id);
					idsa++;
				} else if (IsPlayerMod(id)) {
					format(moders, sizeof(moders), "%s%s(%d)\n", moders, oGetPlayerName(id), id);
					idsm++;
				}
			}

			new string[(MAX_PLAYER_NAME + 1 + 5) * 20 + 64];
			if (idsa == 0 && idsm == 0) {
				format(string, sizeof(string), lang_texts[1][31]);
			} else {
				if (idsa != 0) {
					format(string, sizeof(string), "�������������:\n%s\n", admins);
				}

				if (idsm != 0) {
					format(string, sizeof(string), "%s\n���������:\n%s\n", string, moders);
				}
			}

			Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX, "������������� ������", string, "�����", "�����");
			return 1;
		}
		// ���������
		case 10: {
			Dialog_Show(playerid, Dialog:PlayerSettingsMenu);
			return 1;
		}
		// ������
		case 11: {
			Dialog_Open(playerid, Dialog:PlayerReturnMenu, DIALOG_STYLE_MSGBOX,
				"���������� � ������",
				"{AFE7FF}�� ������� �������:\n\
				\n\
				\t{FFFFFF}Open - Grand Theft Online {AA3333}"VERSION"{FFFFFF}.\n\
				\n\
				\n\
				{00C0DD}������ {AFE7FF}Iain Gilbert\n\
				\n\
				{00C0DD}����������:{AFE7FF}\n\
							\t\tPeter Steenbergen\n\
							\t\tRobin Kikkert\n\
							\t\tAsturel\n\
							\t\tDmitry Frolov (FP)\n\
							\t\tOpen-GTO Team:\n\
							\t\t\tCurrent: ziggi\n\
							\t\t\tPrevious: GhostTT, heufix, Elbi\n\
				\n\
				{00C0DD}��������� ������������: {AFE7FF}\n\
							\t\tMX_Master(mxINI, Chat-Guard)\n\
							\t\twups(Default map icons)\n\
							\t\tY_Less(foreach)\n\
				\n\
				",
				"�����", "�����"
			);
			return 1;
		}
	}
	return 1;
}

DialogResponse:PlayerReturnMenu(playerid, response, listitem, inputtext[])
{
	if (response) {
		Dialog_Show(playerid, Dialog:PlayerMenu);
	}
	return 1;
}
