/*
  Copyright (c) 2016 Untonyst.
  All rights reserved.
  
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

#if defined _u_dlg_included
	#endinput
#endif
#define _u_dlg_included

#if !defined VALID_DIALOGEX_ID
	#define VALID_DIALOGEX_ID (32767)
#endif

#define DIALOG:%0(%1,%2,%3,%4) \
		forward dlg_%0(%1,%2,%3,%4); \
		public dlg_%0(%1,%2,%3,%4)

#define dlg:%0(%1) \
		DIALOG:%0(%1)

#define dialog:%0(%1) \
		DIALOG:%0(%1)

#define DLG:%0(%1) \
		DIALOG:%0(%1)

#if !defined isnull
	#define isnull(%0) \
			(((%0[0]) == 0) || ((%0[0]) == '\1') && ((%0[1]) == 0))
#endif

static dlg_func_name[MAX_PLAYERS][(32 char)];

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) 
{
	if (dialogid == VALID_DIALOGEX_ID)
	{
		CallLocalFunction(dlg_func_name[playerid], !"ddds", playerid, response, listitem, 
			((inputtext[0] == EOS) ? (!"\1") : (inputtext))
		);
		return 1;
	}
	
	static dlg_func[(10 char)], dlg_id[(6 char)];
	
	dlg_func = !"dlg_";
	valstr(dlg_id, dialogid, true);
	strcat(dlg_func, dlg_id);
	CallLocalFunction(dlg_func, !"ddds", playerid, response, listitem, 
		((inputtext[0] == EOS) ? (!"\1") : (inputtext))
	);
	
	#if defined u_OnDialogResponse
		u_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#endif

	return 1;
}
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse u_OnDialogResponse
#if defined u_OnDialogResponse
	forward u_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

stock 
	ShowPlayerDialogEx(playerid, function[], style, caption[], info[], button1[], button2[])
{
	strpack(dlg_func_name[playerid], function);
	
	return ShowPlayerDialog(playerid, VALID_DIALOGEX_ID, style, caption, info, button1, button2);
}
