#if defined _animlist_included
	#endinput
#endif

#define _animlist_included
#pragma library animlist

new const g_aPreloadLibs[][] =
{
    "AIRPORT",      "ATTRACTORS",   "BAR",          "BASEBALL",     "BD_FIRE",
    "BEACH",        "BENCHPRESS",   "BF_INJECTION", "BIKE_DBZ",     "BIKED",
    "BIKEH",        "BIKELEAP",     "BIKES",        "BIKEV",        "BLOWJOBZ",
    "BMX",          "BOMBER",       "BOX",          "BSKTBALL",     "BUDDY",
    "BUS",          "CAMERA",       "CAR",          "CAR_CHAT",     "CARRY",
    "CASINO",       "CHAINSAW",     "CHOPPA",       "CLOTHES",      "COACH",
    "COLT45",       "COP_AMBIENT",  "COP_DVBYZ",    "CRACK",        "CRIB",
    "DAM_JUMP",     "DANCING",      "DEALER",       "DILDO",        "DODGE",
    "DOZER",        "DRIVEBYS",     "FAT",          "FIGHT_B",      "FIGHT_C",
    "FIGHT_D",      "FIGHT_E",      "FINALE",       "FINALE2",      "FLAME",
    "FLOWERS",      "FOOD",         "FREEWEIGHTS",  "GANGS",        "GFUNK",
    "GHANDS",       "GHETTO_DB",    "GOGGLES",      "GRAFFITI",     "GRAVEYARD",
    "GRENADE",      "GYMNASIUM",    "HAIRCUTS",     "HEIST9",       "INT_HOUSE",
    "INT_OFFICE",   "INT_SHOP",     "JST_BUISNESS", "KART",         "KISSING",
    "KNIFE",        "LAPDAN1",      "LAPDAN2",      "LAPDAN3",      "LOWRIDER",
    "MD_CHASE",     "MD_END",       "MEDIC",        "MISC",         "MTB",
    "MUSCULAR",     "NEVADA",       "ON_LOOKERS",   "OTB",          "PARACHUTE",
    "PARK",         "PAULNMAC",     "PED",          "PLAYER_DVBYS", "PLAYIDLES",
    "POLICE",       "POOL",         "POOR",         "PYTHON",       "QUAD",
    "QUAD_DBZ",     "RAPPING",      "RIFLE",        "RIOT",         "ROB_BANK",
    "ROCKET",       "RUNNINGMAN",   "RUSTLER",      "RYDER",        "SCRATCHING",
    "SEX",          "SHAMAL",       "SHOP",         "SHOTGUN",      "SILENCED",
    "SKATE",        "SMOKING",      "SNIPER",       "SNM",          "SPRAYCAN",
    "STRIP",        "SUNBATHE",     "SWAT",         "SWEET",        "SWIM",
    "SWORD",        "TANK",         "TATTOOS",      "TEC",          "TRAIN",
    "TRUCK",        "UZI",          "VAN",          "VENDING",      "VORTEX",
    "WAYFARER",     "WEAPONS",      "WOP",          "WUZI",         "SAMP"
};

stock PreloadAnimations(playerid)
{
    for (new i = 0; i < sizeof(g_aPreloadLibs); i ++) {
        ApplyAnimation(playerid, g_aPreloadLibs[i], "null", 4.0, 0, 0, 0, 0, 0, 1);
    }
    return 1;
}

/*cmd:dance(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_GREY,"Ты в транспорте!");
	if(strval(params) < 1 || strval(params) > 15)) return SendClientMessage(playerid,-1,"Пишите /танец [1-15]");
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_NONE);
	switch(strval(params))
	{
	    case 1: ApplyAnimation(playerid, "DANCING", "bd_clap", 4.1, 1, 1, 1, 1, 1, 1);
	    case 2: ApplyAnimation(playerid, "DANCING", "dance_loop", 4.1, 1, 1, 1, 1, 1, 1);
	    case 3: ApplyAnimation(playerid, "DANCING", "DAN_Down_A", 4.1, 1, 1, 1, 1, 1, 1);
	    case 4: ApplyAnimation(playerid, "DANCING", "DAN_Left_A", 4.1, 1, 1, 1, 1, 1, 1);
	    case 5: ApplyAnimation(playerid, "DANCING", "DAN_Loop_A", 4.1, 1, 1, 1, 1, 1, 1);
	    case 6: ApplyAnimation(playerid, "DANCING", "DAN_Right_A", 4.1, 1, 1, 1, 1, 1, 1);
	    case 7: ApplyAnimation(playerid, "DANCING", "DAN_Up_A", 4.1, 1, 1, 1, 1, 1, 1);
	    case 8: ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.1, 1, 1, 1, 1, 1, 1);
	    case 9: ApplyAnimation(playerid, "DANCING", "dnce_M_b", 4.1, 1, 1, 1, 1, 1, 1);
	    case 10: ApplyAnimation(playerid, "DANCING", "dnce_M_c", 4.1, 1, 1, 1, 1, 1, 1);
	    case 11: ApplyAnimation(playerid, "DANCING", "dnce_M_d", 4.1, 1, 1, 1, 1, 1, 1);
	    case 12: ApplyAnimation(playerid, "DANCING", "dnce_M_e", 4.1, 1, 1, 1, 1, 1, 1);
	    case 13: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
	    case 14: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
	    case 15: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
	}
    return 1;
}
alias:dance("танец");

cmd:animswat(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_GREY,"Ты в транспорте!");
	if(strval(params) < 1 || strval(params) > 12) return SendClientMessage(playerid,-1,"Пишите /сват [1-12]");
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_NONE);
	switch(strval(params))
	{
	    case 1: ApplyAnimation(playerid,"SWAT","gnstwall_injurd",4.1,0,1,0,0,0,0);
	    case 2: ApplyAnimation(playerid,"SWAT","JMP_Wall1m_180",4.1,0,1,0,0,0,0);
	    case 3: ApplyAnimation(playerid,"SWAT","Rail_fall",4.1,0,1,0,0,0,0);
	    case 4: ApplyAnimation(playerid,"SWAT","Rail_fall_crawl",4.1,0,1,0,0,0,0);
	    case 5: ApplyAnimation(playerid,"SWAT","swt_breach_01",4.1,0,1,0,0,0,0);
	    case 6: ApplyAnimation(playerid,"SWAT","swt_breach_02",4.1,0,1,0,0,0,0);
	    case 7: ApplyAnimation(playerid,"SWAT","swt_go",4.1,0,1,0,0,0,0);
	    case 8: ApplyAnimation(playerid,"SWAT","swt_wllpk_L",4.1,0,1,0,0,0,0);
	    case 9: ApplyAnimation(playerid,"SWAT","swt_wllpk_R_back",4.1,0,1,0,0,0,0);
	    case 10: ApplyAnimation(playerid,"SWAT","swt_wllshoot_in_R",4.1,0,1,0,0,0,0);
	    case 11: ApplyAnimation(playerid,"SWAT","swt_wllshoot_out_L",4.1,0,1,0,0,0,0);
	    case 12: ApplyAnimation(playerid,"SWAT","swt_wllshoot_out_R",4.1,0,1,0,0,0,0);
	}
    return 1;
}
alias:animswat("сват");

cmd:animstrip(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_GREY,"Ты в транспорте!");
	if(strval(params) < 1 || strval(params) > 20) return SendClientMessage(playerid,-1,"Пишите /стрип [1-20]");
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_NONE);
	switch(strval(params))
	{
	    case 1: ApplyAnimation(playerid,"STRIP","PLY_CASH",4.1,0,1,0,0,0,0);
	    case 2: ApplyAnimation(playerid,"STRIP","PUN_CASH",4.1,0,1,0,0,0,0);
	    case 3: ApplyAnimation(playerid,"STRIP","PUN_HOLLER",4.1,0,1,0,0,0,0);
	    case 4: ApplyAnimation(playerid,"STRIP","PUN_LOOP",4.1,0,1,0,0,0,0);
	    case 5: ApplyAnimation(playerid,"STRIP","strip_A",4.1,0,1,0,0,0,0);
	    case 6: ApplyAnimation(playerid,"STRIP","strip_B",4.1,0,1,0,0,0,0);
	    case 7: ApplyAnimation(playerid,"STRIP","strip_C",4.1,0,1,0,0,0,0);
	    case 8: ApplyAnimation(playerid,"STRIP","strip_D",4.1,0,1,0,0,0,0);
	    case 9: ApplyAnimation(playerid,"STRIP","strip_E",4.1,0,1,0,0,0,0);
	    case 10: ApplyAnimation(playerid,"STRIP","strip_F",4.1,0,1,0,0,0,0);
	    case 11: ApplyAnimation(playerid,"STRIP","strip_G",4.1,0,1,0,0,0,0);
	    case 12: ApplyAnimation(playerid,"STRIP","STR_A2B",4.1,0,1,0,0,0,0);
	    case 13: ApplyAnimation(playerid,"STRIP","STR_B2A",4.1,0,1,0,0,0,0);
	    case 14: ApplyAnimation(playerid,"STRIP","STR_B2C",4.1,0,1,0,0,0,0);
	    case 15: ApplyAnimation(playerid,"STRIP","STR_C1",4.1,0,1,0,0,0,0);
	    case 16: ApplyAnimation(playerid,"STRIP","STR_C2",4.1,0,1,0,0,0,0);
	    case 17: ApplyAnimation(playerid,"STRIP","STR_C2B",4.1,0,1,0,0,0,0);
	    case 18: ApplyAnimation(playerid,"STRIP","STR_Loop_A",4.1,0,1,0,0,0,0);
	    case 19: ApplyAnimation(playerid,"STRIP","STR_Loop_B",4.1,0,1,0,0,0,0);
	    case 20: ApplyAnimation(playerid,"STRIP","STR_Loop_C",4.1,0,1,0,0,0,0);
	}
    return 1;
}
alias:animstrip("стрип");
