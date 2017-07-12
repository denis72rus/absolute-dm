#if defined _fix_included
	#endinput
#endif

#define _fix_included
#pragma library fix

forward KickTimer(playerid);
public KickTimer(playerid)
{
	if(playerid != INVALID_PLAYER_ID) Kick(playerid);
}

#define Kick(%0) SetTimerEx("KickTimer", 900, false, "d", %0)

forward fix_SpawnPlayer(playerid);
public fix_SpawnPlayer(playerid)
{
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new tmpcar = GetPlayerVehicleID(playerid);
		new Float:carx,Float:cary,Float:carz;
		GetVehiclePos(tmpcar, carx, cary, carz),
		SetPlayerPos(playerid, carx, cary, carz);
	}
	SpawnPlayer(playerid);
	return 1;
}

#define SpawnPlayer(%0) fix_SpawnPlayer(%0)

forward fix_SetPlayerPos(playerid, Float:x, Float:y, Float:z);
public  fix_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new tmpcar = GetPlayerVehicleID(playerid);
		new Float:carx,Float:cary,Float:carz;
		GetVehiclePos(tmpcar, carx, cary, carz),
		SetPlayerPos(playerid, carx, cary, carz);
	}
	SetPlayerPos(playerid, x, y, z);
	return 1;
}

#define SetPlayerPos(%0) fix_SetPlayerPos(%0)

forward fix_SetPlayerHealth(playerid, Float:health);
public fix_SetPlayerHealth(playerid, Float:health)
{
	//if(health >= 100.0 && health <= 150.0) health = 100.0;
	if(health < 0.0) health = 0.0;
#if defined _anticheat_included
	ac_SetPlayerHealth(playerid, health);
#else
	SetPlayerHealth(playerid, health);
#endif
	return 1;
}

#define SetPlayerHealth(%0) fix_SetPlayerHealth(%0)

forward fix_SetPlayerArmour(playerid, Float:armour);
public fix_SetPlayerArmour(playerid, Float:armour)
{
	//if(armour >= 100.0 && armour <= 150.0) armour = 100.0;
	if(armour < 0.0) armour = 0.0;
#if defined _anticheat_included
	ac_SetPlayerArmour(playerid, armour);
#else
	SetPlayerArmour(playerid, armour);
#endif
	return 1;
}

#define SetPlayerArmour(%0) fix_SetPlayerArmour(%0)

forward fix_GivePlayerWeapon(playerid,weaponid,ammo);
public fix_GivePlayerWeapon(playerid,weaponid,ammo)
{
#if defined _anticheat_included
	ac_GivePlayerWeapon(playerid,weaponid,ammo);
#else
	GivePlayerWeapon(playerid,weaponid,ammo);
#endif
	return 1;
}

#define GivePlayerWeapon(%0) fix_GivePlayerWeapon(%0)

forward fix_ResetPlayerWeapons(playerid);
public fix_ResetPlayerWeapons(playerid)
{
#if defined _anticheat_included
	ac_ResetPlayerWeapons(playerid);
#else
	ResetPlayerWeapons(playerid);
#endif
	return 1;
}

#define ResetPlayerWeapons(%0) fix_ResetPlayerWeapons(%0)
