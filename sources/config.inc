#if defined _config_included
	#endinput
#endif

#define _config_included
#pragma library config


new mode_hostname[] =
{
	"Universal Mod"
};
new mode_site[] =
{
	"www.none.ru"
};
new mode_language[] =
{
	"Russian"
};
new mode_gametext[] =
{
	"Default"
};

new admin_accountid = 0; // Номер аккаунта администратора сервера

#define TEST_SERVER

/*
 * Core settings
 */

#if !defined TEST_SERVER

	#define mysql_host          "127.0.0.1"
	#define mysql_db            "server_db"
	#define mysql_user          "root"
	#define mysql_pass          "jeoccn81wg"
	
	#define mysql_host_geoip           "52.201.5.54"
	#define mysql_db_geoip             "geoip"
	#define mysql_user_geoip           "userdb"
	#define mysql_pass_geoip           "jeoccn81wg"
	
	#define SERVER_GMT          0 // Временная зона сервера (5 - Тюмень, 3 - Москва, 0 - Гринвич)

#else

	#define mysql_host          "127.0.0.1"
	#define mysql_db            "database"
	#define mysql_user          "root"
	#define mysql_pass          ""
	
	#define mysql_host_geoip           "127.0.0.1"
	#define mysql_db_geoip             "getgeoip"
	#define mysql_user_geoip           "root"
	#define mysql_pass_geoip           ""
	
	#define SERVER_GMT          5 // Временная зона сервера (5 - Тюмень, 3 - Москва, 0 - Гринвич)

#endif

#define VALID_ADMIN_LEVEL   100,500,700,1000,2000

/*
 * Player settings
 */

#define COLOR_DIALOG_MENU   FFFFFF
#define CAPTURE_ZONE_TIME   360

#define EMAIL_RECEIVER      "begin@none"
#define EMAIL_SENDERMAIL    "www.none.ru"

#define INVALID_DEATHMATCH_ID   -1
#define INVALID_HOUSE_ID        -1

#define MAX_CLAN            251
#define MAX_CLAN_MEMBERS    50
#define MAX_ZONES           506
#define MAX_HOUSES          2250

#define MAX_HOUSE_NAME      50
#define MAX_PLAYER_PASSWORD 100
#define MAX_PLAYER_EMAIL    32

/*
 * Referal System settings
 */
 
#define REFERAL_BONUS_LEVEL     1
#define REFERAL_BONUS_MONEY     10000
#define REFERAL_BONUS_POINTS    5

/*
 * Virtual worlds settings
 */

#define VW_DM               350
#define VW_PLAYER           1
#define VW_HOUSE            10000

/*
 * FlyMode settings
 */

#define MOVE_SPEED              100.0
#define ACCEL_RATE              0.03

#define CAMERA_MODE_NONE    	0
#define CAMERA_MODE_FLY     	1

#define MOVE_FORWARD    		1
#define MOVE_BACK       		2
#define MOVE_LEFT       		3
#define MOVE_RIGHT      		4
#define MOVE_FORWARD_LEFT       5
#define MOVE_FORWARD_RIGHT      6
#define MOVE_BACK_LEFT          7
#define MOVE_BACK_RIGHT         8

/*
 * File\MySQL settings
 */

new ClanMemberPatch[] = "clan/%d.ini";
new DMCoordPatch[]    = "dm/mapcoord_%d.ini";
new DMPickupPatch[]   = "dm/dropgun_%d.ini";

#define f(%1, 		        format(%1,sizeof(%1),

public OnGameModeInit()
{
	new str[128];
    format(str, sizeof(str),"hostname %s", mode_hostname);
    SendRconCommand(str);
    format(str, sizeof(str),"weburl %s", mode_site);
    SendRconCommand(str);
    format(str, sizeof(str),"language %s", mode_language);
    SendRconCommand(str);
    SetGameModeText(mode_gametext);
	EnableStuntBonusForAll(false);
	DisableInteriorEnterExits();
	EnableVehicleFriendlyFire();
	UsePlayerPedAnims();
    LimitPlayerMarkerRadius(1000.0);
	
	CallLocalFunction("config_OnGameModeInit", "");
	return 1;
}

#if defined _ALS_OnGameModeInit
#undef OnGameModeInit
#else
#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit config_OnGameModeInit

forward config_OnGameModeInit(playerid);
