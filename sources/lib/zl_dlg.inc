#include <a_samp>

#if defined _zl_dlg
	#endinput
#else
	#define _zl_dlg
	
#define DLG:%0() \
	forward dlg_%0(playerid,dialogid,response,listitem,inputtext[]);\
	public dlg_%0(playerid,dialogid,response,listitem,inputtext[])

public OnDialogResponse(playerid,dialogid,response,listitem,inputtext[])
{
	new _zl_functiondlgid[32];
	format(_zl_functiondlgid,sizeof(_zl_functiondlgid),"dlg_%i",dialogid);
	return CallLocalFunction(_zl_functiondlgid,"iiiis",playerid,dialogid,response,listitem,inputtext);
}

#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif

#define OnDialogResponse ZL_DLG_OnDialogResponse

forward ZL_DLG_OnDialogResponse(playerid,dialogid,response,listitem,inputtext[]);