#if defined _mysql_connect_included
	#endinput
#endif

#define _mysql_connect_included
#pragma library mysql_connect

new mysqlConnection;

public OnGameModeInit()
{	
    //mysqlConnection = mysql_connect(mysql_host, mysql_user, mysql_db, mysql_pass);
    mysqlConnection = SQL::Connect(mysql_host, mysql_user, mysql_db, mysql_pass);
    if(mysql_errno())
	{
		//print("База данных не подключена\n* Проверьте введенные вами данные");
		OnGameModeExit();
		return 1;
	}
    mysql_tquery(mysqlConnection, "SET NAMES cp1251", "", "");
    mysql_tquery(mysqlConnection, "SET CHARACTER SET cp1251", "", "");
    mysql_query(mysqlConnection, "SET NAMES cp1251");
    mysql_query(mysqlConnection, "SET CHARACTER SET cp1251");
    
	//Create table
	mysql_query(mysqlConnection, " \
		CREATE TABLE IF NOT EXISTS `logs_accounts` ( \
		  `Name` varchar(24) NOT NULL, \
		  `Account` int(11) NOT NULL, \
		  `IP` varchar(32) NOT NULL, \
		  `Time` int(11) NOT NULL \
		) ENGINE=InnoDB DEFAULT CHARSET=utf8; \
	");
	
	mysql_query(mysqlConnection, " \
		CREATE TABLE IF NOT EXISTS `logs_admins` ( \
		  `Time` int(11) NOT NULL, \
		  `Action` varchar(128) NOT NULL \
		) ENGINE=InnoDB DEFAULT CHARSET=utf8; \
	");
	
	mysql_query(mysqlConnection, " \
		CREATE TABLE IF NOT EXISTS `logs_banip` ( \
		  `Account` int(11) NOT NULL, \
		  `IP` varchar(32) NOT NULL, \
		  `BanDate` int(11) NOT NULL, \
		  `UnBanDate` int(11) NOT NULL \
		) ENGINE=InnoDB DEFAULT CHARSET=utf8; \
	");
	
	mysql_query(mysqlConnection, " \
		CREATE TABLE IF NOT EXISTS `logs_setname` ( \
		`Name` varchar(24) NOT NULL, \
		`NewName` varchar(24) NOT NULL, \
		`Account` int(11) NOT NULL, \
		`Time` int(11) NOT NULL \
		) ENGINE=InnoDB DEFAULT CHARSET=utf8; \
	");
	
	mysql_query(mysqlConnection, " \
		CREATE TABLE IF NOT EXISTS `news` ( \
		  `nID` int(11) NOT NULL AUTO_INCREMENT, \
		  `nDate` varchar(15) NOT NULL, \
		  `nVersion` varchar(15) NOT NULL, \
		  `nAdded` varchar(512) NOT NULL, \
		  `nFixed` varchar(512) NOT NULL, \
		  PRIMARY KEY (`nID`) \
		) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ; \
	");
	
    mysql_query(mysqlConnection, "CREATE TABLE IF NOT EXISTS `d_accounts` LIKE `accounts`");
	
	CallLocalFunction("mysql_OnGameModeInit", "");
	return 1;
}

#if defined _ALS_OnGameModeInit
#undef OnGameModeInit
#else
#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit mysql_OnGameModeInit

forward mysql_OnGameModeInit(playerid);

public OnGameModeExit()
{
	mysql_close(mysqlConnection);
	
	CallLocalFunction("mysql_OnGameModeExit", "");
	return 1;
}

#if defined _ALS_OnGameModeExit
#undef OnGameModeExit
#else
#define _ALS_OnGameModeExit
#endif

#define OnGameModeExit mysql_OnGameModeExit

forward mysql_OnGameModeExit(playerid);
