#if defined _log_included
	#endinput
#endif

#define _log_included
#pragma library log

stock Logs_Accounts(name[], account, ip[], gpci[], time, action[])
{
	new L_str[256];
	format(L_str, sizeof(L_str), "INSERT INTO `logs_accounts` (`Name`, `Account`, `IP`, `Gpci`, `Time`, `Action`) VALUES ('%s', '%d', '%s', '%s', '%d', '%s')", name, account, ip, gpci, time, action);
    mysql_tquery(mysqlConnection, L_str, "", "");
    return 1;
}

stock Logs_Admins(time, action[])
{
	new L_str[256];
	format(L_str, sizeof(L_str), "INSERT INTO `logs_admins` (`Time`, `Action`) VALUES ('%d', '%s')", time, action);
    mysql_tquery(mysqlConnection, L_str, "", "");
    return 1;
}

stock Logs_SetName(name[], newname[], account, time)
{
	new L_str[256];
	format(L_str, sizeof(L_str), "INSERT INTO `logs_setname` (`Name`, `NewName`, `Account`, `Time`) VALUES ('%s', '%s', '%d', '%d')", name, newname, account, time);
    mysql_tquery(mysqlConnection, L_str, "", "");
    return 1;
}

stock Logs_Promocods(account, promocodeid, promocode[], time)
{
	new L_str[256];
	format(L_str, sizeof(L_str), "INSERT INTO `logs_promocods` (`Account`, `PromocodeID`, `Promocode`, `Time`) VALUES ('%d', '%d', '%s', '%d')", account, promocodeid, promocode, time);
    mysql_tquery(mysqlConnection, L_str, "", "");
    return 1;
}
