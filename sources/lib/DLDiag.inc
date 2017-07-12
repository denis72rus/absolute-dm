/*
 _____  _      _____  _
|  __ \| |    |  __ \(_)
| |  | | |    | |  | |_  __ _  __ _
| |  | | |    | |  | | |/ _` |/ _` |
| |__| | |____| |__| | | (_| | (_| |
|_____/|______|_____/|_|\__,_|\__, |
   DynamicListDialog (v1.2)    __/ |
                   ByTheXIII  |___/
                                    */


/*=====================================

native AddDListItem(playerid, Item[], ItemID = -1, ItemParam = -1);
native ShowPlayerDList(playerid, DialogID, Caption[], Button1[], Button2[]);
native Clear_DList(playerid);

=====================================*/

#if defined _DLDiag_included
    #endinput
#endif
#define _DLDiag_included

#if !defined _samp_included
    #error "<a_samp> must be included before <DLDiag>"
#endif

#if !defined DLD_STRING_SIZE
    #define DLD_STRING_SIZE 512
#endif

#if !defined DLD_MAX_LIST_ITEMS
    #define DLD_MAX_LIST_ITEMS 20
#endif
#define DLItemID DLDPlayerListItems[playerid][listitem]
#define DLItemName DLDPlayerListItemsName[playerid][listitem]
#define DLParam DLDPlayerListParam[playerid][listitem]

new DLDString[DLD_STRING_SIZE];
new DLDPlayerListItems[MAX_PLAYERS][DLD_MAX_LIST_ITEMS];
new DLDPlayerListParam[MAX_PLAYERS][DLD_MAX_LIST_ITEMS];
new DLDPlayerListItemsName[MAX_PLAYERS][DLD_MAX_LIST_ITEMS][DLD_STRING_SIZE];
new DLDLastIS;

stock AddDListItem(playerid, ItemStr[DLD_STRING_SIZE], d_ItemID = -1, ItemParam = -1)
{
    DLDPlayerListItems[playerid][DLDLastIS] = d_ItemID;
    DLDPlayerListParam[playerid][DLDLastIS] = ItemParam;
    if( !DLDLastIS ){DLDString = ""; format(DLDString, sizeof(DLDString), "%s", ItemStr);}
    else format(DLDString, sizeof(DLDString), "%s\r\n%s", DLDString, ItemStr);
    DLDLastIS++;
    return DLDLastIS -1;
}
stock AddDListItemEx(playerid, ItemStr[DLD_STRING_SIZE], ItemParam = -1)
{
	DLDPlayerListItemsName[playerid][DLDLastIS] = ItemStr;
    DLDPlayerListParam[playerid][DLDLastIS] = ItemParam;
    if( !DLDLastIS ){DLDString = ""; format(DLDString, sizeof(DLDString), "%s", ItemStr);}
    else format(DLDString, sizeof(DLDString), "%s\r\n%s", DLDString, ItemStr);
    DLDLastIS++;
    return DLDLastIS -1;
}
stock ShowPlayerDList(playerid, Dialog1ID, Caption[], Button1[], Button2[])
{
    DLDLastIS = 0;
    ShowPlayerDialog(playerid, Dialog1ID, DIALOG_STYLE_LIST, Caption, DLDString, Button1, Button2);
	DLDString = "";
	return true;
}
stock Clear_DList(playerid)
{
	for( new i; i < DLD_MAX_LIST_ITEMS; i++ )
	{
	    DLDPlayerListItems[playerid][i] = 0;
		DLDPlayerListItemsName[playerid][i] = "";
	    DLDPlayerListParam[playerid][i] = 0;
	}
	return true;
}
