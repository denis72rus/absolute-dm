#if defined _anticheat_included
	#endinput
#endif

#define _anticheat_included
#pragma library anticheat

forward OnCheatDetected(suspectid, code, targetid);

#define AC_GODMODE_1 1
#define AC_GODMODE_2 2
#define AC_HEALTH    3
#define AC_ARMOUR    4
#define AC_WEAPON    5
#define AC_AMMO      6
#define AC_AMMO_INF  7

enum ACInfo
{
	acTimer,
	//AC_GODMODE
    acGMDamageTime[2],
    acGMWarring[2],
    Float:acGMOldHP[2],
    Float:acGMOldArmour,
    bool:acGMShooted,
    acGMShootedID,
	//AC_HEALTH è AC_ARMOUR
	acHealthHack,
	acHealthWarring,
	acArmourHack,
	acArmourWarring,
	//AC_WEAPON è AC_AMMO
	acWeapon[13],
	acAmmo[13],
	acAmmo_inf[13],
    
};

new AntiCheatInfo[MAX_PLAYERS][ACInfo];

public OnPlayerConnect(playerid)
{
	AntiCheatInfo[playerid][acTimer] = SetTimerEx("ac_Timer", 1000, 1, "d", playerid);
	//AC_GODMODE
    AntiCheatInfo[playerid][acGMDamageTime][0] = 0;
    AntiCheatInfo[playerid][acGMDamageTime][1] = 0;
    AntiCheatInfo[playerid][acGMWarring][0] = 0;
    AntiCheatInfo[playerid][acGMWarring][1] = 0;
    AntiCheatInfo[playerid][acGMOldHP][0] = 0.0;
    AntiCheatInfo[playerid][acGMOldHP][1] = 0.0;
    AntiCheatInfo[playerid][acGMOldArmour] = 0.0;
    AntiCheatInfo[playerid][acGMShooted] = false;
    AntiCheatInfo[playerid][acGMShootedID] = INVALID_PLAYER_ID;
	//AC_HEALTH è AC_ARMOUR
	AntiCheatInfo[playerid][acHealthWarring] = 0;
	AntiCheatInfo[playerid][acArmourWarring] = 0;
	//AC_WEAPON è AC_AMMO
	for(new i = 0; i < 13; i++)
	{
		AntiCheatInfo[playerid][acWeapon][i] = 0;
		AntiCheatInfo[playerid][acAmmo][i] = 0;
		AntiCheatInfo[playerid][acAmmo_inf][i] = 0;
	}

	CallLocalFunction("ac_OnPlayerConnect", "i", playerid);
	return 1;
}

#if defined _ALS_OnPlayerConnect
#undef OnPlayerConnect
#else
#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect ac_OnPlayerConnect

forward ac_OnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid, reason)
{
    KillTimer(AntiCheatInfo[playerid][acTimer]);
    
    CallLocalFunction("ac_OnPlayerDisconnect", "is", playerid, reason);
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
#undef OnPlayerDisconnect
#else
#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect ac_OnPlayerDisconnect

forward ac_OnPlayerDisconnect(playerid, reason);

public OnPlayerGiveDamage(playerid, damagedid, Float: amount, weaponid, bodypart)
{
	//AC_GODMODE_1
    if(damagedid != INVALID_PLAYER_ID)
	{
		if(GetPlayerTeam(playerid) == NO_TEAM || GetPlayerTeam(playerid) != GetPlayerTeam(damagedid))
		{
	        new Float: Health;
			GetPlayerHealth(damagedid, Health);
	  		if(AntiCheatInfo[damagedid][acGMOldHP][0] == Health && GetTickCount() - AntiCheatInfo[damagedid][acGMDamageTime][0] > 120)
			{
				if(++AntiCheatInfo[damagedid][acGMWarring][0] >= 30) return OnCheatDetected(damagedid, AC_GODMODE_1, playerid), 0;
			}
			AntiCheatInfo[damagedid][acGMOldHP][0] = Health;
			AntiCheatInfo[damagedid][acGMDamageTime][0] = GetTickCount();
		}
    }
    
    CallLocalFunction("ac_OnPlayerGiveDamage", "iifii", playerid, damagedid, Float: amount, weaponid, bodypart);
    return 1;
}

#if defined _ALS_OnPlayerGiveDamage
#undef OnPlayerGiveDamage
#else
#define _ALS_OnPlayerGiveDamage
#endif

#define OnPlayerGiveDamage ac_OnPlayerGiveDamage

forward ac_OnPlayerGiveDamage(playerid, damagedid, Float: amount, weaponid, bodypart);

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	//AC_GODMODE_2
    if(hittype == 1 && IsPlayerConnected(hitid))
    {
	    AntiCheatInfo[hitid][acGMShooted] = true;
		AntiCheatInfo[hitid][acGMShootedID] = playerid;
		AntiCheatInfo[hitid][acGMDamageTime][1] = GetTickCount();
    }
    //AC_AMMO_INF
	new slot = GetWeaponSlot(weaponid);
	if(AntiCheatInfo[playerid][acWeapon][slot])
	{
		if(AntiCheatInfo[playerid][acAmmo_inf][slot]+10 < GetPlayerAmmo(playerid))
		{
			OnCheatDetected(playerid, AC_AMMO_INF, INVALID_PLAYER_ID);
		}
	}
    AntiCheatInfo[playerid][acAmmo_inf][slot] --;
    
    CallLocalFunction("ac_OnPlayerWeaponShot", "iiiifff", playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
    return 1;
}

#if defined _ALS_OnPlayerWeaponShot
#undef OnPlayerWeaponShot
#else
#define _ALS_OnPlayerWeaponShot
#endif

#define OnPlayerWeaponShot ac_OnPlayerWeaponShot

forward ac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);

/*public OnPlayerUpdate(playerid)
{
	CallLocalFunction("ac_OnPlayerUpdate", "i", playerid);
    return 1;
}

#if defined _ALS_OnPlayerUpdate
#undef OnPlayerUpdate
#else
#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate ac_OnPlayerUpdate

forward ac_OnPlayerUpdate(playerid);*/

forward ac_Timer(playerid);
public ac_Timer(playerid)
{
	//AC_GODMODE_2
	if (GetPlayerState(playerid) != PLAYER_STATE_WASTED && GetPlayerState(playerid) != PLAYER_STATE_SPAWNED && GetPlayerState(playerid) != PLAYER_STATE_SPECTATING && !IsPlayerPaused(playerid))
    {
	    if(GetPlayerTeam(playerid) == NO_TEAM || GetPlayerTeam(playerid) != GetPlayerTeam(AntiCheatInfo[playerid][acGMShootedID]))
		{
			new Float:pHealth, Float:pArmour, pPing = GetPlayerPing(playerid) + 150;
		    GetPlayerHealth(playerid, pHealth);
		    GetPlayerArmour(playerid, pArmour);
		    if(pHealth < AntiCheatInfo[playerid][acGMOldHP][1] || pArmour < AntiCheatInfo[playerid][acGMOldArmour])
		    {
				AntiCheatInfo[playerid][acGMWarring][1] = 0;
				AntiCheatInfo[playerid][acGMShooted] = false;
		    }
		    else if(AntiCheatInfo[playerid][acGMShooted] && GetTickCount() > AntiCheatInfo[playerid][acGMDamageTime][1] + pPing)
		    {
				AntiCheatInfo[playerid][acGMShooted] = false;
			    if(++AntiCheatInfo[playerid][acGMWarring][1] >= 15) return OnCheatDetected(playerid, AC_GODMODE_2, AntiCheatInfo[playerid][acGMShootedID]), 0;
			}
			AntiCheatInfo[playerid][acGMOldHP][1] = pHealth;
			AntiCheatInfo[playerid][acGMOldArmour] = pArmour;
		}
	}
	//AC_HEALTH è AC_ARMOUR
	if (GetPlayerState(playerid) != PLAYER_STATE_WASTED && GetPlayerState(playerid) != PLAYER_STATE_SPAWNED && GetPlayerState(playerid) != PLAYER_STATE_SPECTATING && !IsPlayerPaused(playerid))
    {
		new Float:health;
	    GetPlayerHealth(playerid, health);
	    while(AntiCheatInfo[playerid][acHealthHack] > health + 255) health += 256;
	    if(health > AntiCheatInfo[playerid][acHealthHack])
	    {
		    if(++AntiCheatInfo[playerid][acHealthWarring] >= 3) return OnCheatDetected(playerid, AC_HEALTH, INVALID_PLAYER_ID);
	    }
	    else if(health < AntiCheatInfo[playerid][acHealthHack])
	    {
		    AntiCheatInfo[playerid][acHealthHack] = floatround(health, floatround_tozero);
		    if(AntiCheatInfo[playerid][acHealthHack] < 0) AntiCheatInfo[playerid][acHealthHack] = 0;
	    }
	    new Float:armour;
	    GetPlayerArmour(playerid, armour);
	    while(AntiCheatInfo[playerid][acArmourHack] > armour + 255) armour += 256;
	    if(armour > AntiCheatInfo[playerid][acArmourHack])
	    {
		    if(++AntiCheatInfo[playerid][acArmourWarring] >= 3) return OnCheatDetected(playerid, AC_ARMOUR, INVALID_PLAYER_ID);
	    }
	    else if(armour < AntiCheatInfo[playerid][acArmourHack])
	    {
		    AntiCheatInfo[playerid][acArmourHack] = floatround(armour, floatround_tozero);
			if(AntiCheatInfo[playerid][acArmourHack] < 0) AntiCheatInfo[playerid][acArmourHack]= 0;
	    }
    }
    //AC_WEAPON è AC_AMMO
    if (GetPlayerState(playerid) != PLAYER_STATE_WASTED && GetPlayerState(playerid) != PLAYER_STATE_SPAWNED && GetPlayerState(playerid) != PLAYER_STATE_SPECTATING && !IsPlayerPaused(playerid))
    {
	    new weap = GetPlayerWeapon(playerid);
	    new ammo = GetPlayerAmmo(playerid);
	    new slot = GetWeaponSlot(weap);
	    if(weap != AntiCheatInfo[playerid][acWeapon][slot] && ammo > 0)
	    {
			OnCheatDetected(playerid, AC_WEAPON, INVALID_PLAYER_ID);
	    }
		if(AntiCheatInfo[playerid][acWeapon][slot] && ammo != AntiCheatInfo[playerid][acAmmo][slot])
		{
			if(ammo < AntiCheatInfo[playerid][acAmmo][slot])
			{
					AntiCheatInfo[playerid][acAmmo][slot] = ammo;
			}
			else if((weap >= 16 && weap <= 18) || (weap >= 22 && weap <= 39) || (weap >= 41 && weap <= 43))
			{
				OnCheatDetected(playerid, AC_AMMO, INVALID_PLAYER_ID);
			}
		}
	}
	return 1;
}

stock ac_SetPlayerHealth(playerid, Float:health)
{
	AntiCheatInfo[playerid][acHealthHack] = floatround(health, floatround_tozero);
	SetPlayerHealth(playerid, health);
	return 1;
}

stock ac_SetPlayerArmour(playerid, Float:armour)
{
	AntiCheatInfo[playerid][acArmourHack] = floatround(armour, floatround_tozero);
	SetPlayerArmour(playerid, armour);
	return 1;
}

stock ac_GivePlayerWeapon(playerid,weaponid,ammo)
{
	new slot = GetWeaponSlot(weaponid);
	AntiCheatInfo[playerid][acWeapon][slot] = weaponid;
	AntiCheatInfo[playerid][acAmmo][slot] += ammo;
	AntiCheatInfo[playerid][acAmmo_inf][slot] += ammo;
	GivePlayerWeapon(playerid,weaponid,ammo);
	return 1;
}

stock ac_ResetPlayerWeapons(playerid)
{
	ResetPlayerWeapons(playerid);
	for(new i = 0; i < 13; i++)
	{
		AntiCheatInfo[playerid][acWeapon][i] = 0;
		AntiCheatInfo[playerid][acAmmo][i] = 0;
		AntiCheatInfo[playerid][acAmmo_inf][i] = 0;
	}
	return 1;
}

stock GetWeaponSlot(weaponid)
{
     new slot;
     switch(weaponid)
     {
        case 0,1: slot = 0;
        case 2..9: slot = 1;
        case 22..24: slot = 2;
        case 25..27: slot = 3;
        case 28,29,32: slot = 4;
        case 30,31: slot = 5;
        case 33,34: slot = 6;
        case 35..38: slot = 7;
        case 16..18,39: slot = 8;
        case 41..43: slot = 9;
        case 10..15: slot = 10;
        case 44..46: slot = 11;
        case 40: slot = 12;
        default: slot = -1;
     }
     return slot;
}
