/*
    Version: 1.1
   
    Copyright (c) 2016, Untonyst aka Anton Styazhkin
    
    This software is provided 'as-is', without any express or implied
    warranty. In no event will the authors be held liable for any damages
    arising from the use of this software.
    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:
    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgement in the product documentation would be
       appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
*/

#if !defined _samp_included
	#include <a_samp>
#endif

#if defined _u_dlg_included
	#endinput
#endif
#define _u_dlg_included

#define dlg(%0,%1)\
        DLG:%0(%1)

#define dialog(%0,%1)\
        DLG:%0(%1)

#define DLG:%0(%1)\
        DIALOG:%0(%1)

#define DIALOG:%0(%1,%2,%3,%4)\
		forward dlg_%0(%1,%2,%3,%4);\
		public dlg_%0(%1,%2,%3,%4)
		
// It's a constant that mean the unique id's dialog of ShowPlayerDialogEx function.
// Important that this id's dialog never been use!!!
#define VALID_CDR_ID (32767)
#define VALID_DLG_ID (1024)

static stock g_f_spd_name[MAX_PLAYERS][32];
static stock g_f_spd_id[MAX_PLAYERS];

stock ShowPlayerDialogEx(playerid, dialogname[], style, caption[], info[], button1[], button2[]) 
{
	g_f_spd_name[playerid][0] = EOS;
	g_f_spd_id[playerid] ++;
	if(g_f_spd_id[playerid] > VALID_CDR_ID)
	{
		g_f_spd_id[playerid] = 1;
	}
	strcat(g_f_spd_name[playerid], dialogname);
	return ShowPlayerDialog(playerid, g_f_spd_id[playerid]+VALID_DLG_ID, style, caption, info, button1, button2);
}

stock ShowPlayerDListEx(playerid, dialogname[], Caption[], Button1[], Button2[])
{
	g_f_spd_name[playerid][0] = EOS;
	g_f_spd_id[playerid] ++;
	if(g_f_spd_id[playerid] > VALID_CDR_ID)
	{
		g_f_spd_id[playerid] = 1;
	}
	strcat(g_f_spd_name[playerid], dialogname);
	return ShowPlayerDList(playerid, g_f_spd_id[playerid]+VALID_DLG_ID, Caption, Button1, Button2);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) 
{
	//printf("playerid: %d dialogid: %d response: %d listitem: %d inputtext: %s", playerid, dialogid, response, listitem, inputtext);
	static const f_spd_args[] = "iiis";
	new f_spd_name[32] = "dlg_";
	strcat(f_spd_name, g_f_spd_name[playerid]);
	if (dialogid == g_f_spd_id[playerid]+VALID_DLG_ID)
	{
		CallLocalFunction(
			f_spd_name,
			f_spd_args,
			playerid,
			response,
			listitem,
			(inputtext[0] == EOS) ? ("\1") : (inputtext)
		);
		return 1;
	}
	static const l_dlg_args[] = "iiis";
	new f_dlg_name[10] = "dlg_", f_dlg_id[6];
	valstr(f_dlg_id, dialogid);
	strcat(f_dlg_name, f_dlg_id);
	CallLocalFunction(
		f_dlg_name,
		l_dlg_args,
		playerid,
		response,
		listitem,
		(inputtext[0] == EOS) ? ("\1") : (inputtext)
	);
	#if defined u_dlg__OnDialogResponse
	    return u_dlg__OnDialogResponse(
			playerid,
			dialogid,
			response,
			listitem,
			inputtext
		);
	#else
		return 0;
	#endif
}
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse u_dlg__OnDialogResponse
#if defined u_dlg__OnDialogResponse
forward u_dlg__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
