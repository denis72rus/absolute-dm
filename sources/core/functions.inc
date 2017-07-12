#if defined _functions_included
	#endinput
#endif

#define _functions_included
#pragma library functions

stock MTF(time)
{
    new MT[128];
	if(time == 2000000000) format(MT, sizeof(MT), "вечность");
    else if(time < 60) format(MT, sizeof(MT), "%dc", time);
    else if(time == 60) MT = "1м:0с";
    else if(time > 60 && time < 3600)
    {
        new Float: timeM;
        new timeS;
        timeM = time / 60;
        timeS = time % 60;
        format(MT, sizeof(MT), "%.0fм:%dс", timeM, timeS);
    }
    else if(time == 3600) MT = "1ч:0м:0с";
    else if(time > 3600 && time < 86400)
	{
        new Float: timeH;
        new timeMInt;
        new Float: timeM;
        new timeS;
        timeH = time / 3600;
        timeMInt = time % 3600;
        timeM = timeMInt / 60;
        timeS = timeMInt % 60;
        format(MT, sizeof(MT), "%.0fч:%.0fм:%dс", timeH, timeM, timeS);
    }
    else if(time == 86400) MT = "1д:0ч:0м:0с";
    else if(time > 86400)
    {
        new Float: timeD;
        new Float: timeH;
        new timeMInt, timeHInt;
        new Float: timeM;
        new timeS;
        timeD = time / 86400;
        timeHInt = time % 86400;
        timeMInt = time % 3600;
        timeH = timeHInt / 3600;
        timeM = timeMInt / 60;
        timeS = timeMInt % 60;
        format(MT, sizeof(MT), "%.0fд:%.0fч:%.0fм:%dс", timeD, timeH, timeM, timeS);
    }
    return MT;
}

stock JTF(time)
{
    new MT[128];
    if(time < 60) format(MT, sizeof(MT), "0:%d", time);
    else if(time == 60) MT = "1:0";
    else if(time > 60 && time < 3600)
    {
        new Float: timeM;
        new timeS;
        timeM = time / 60;
        timeS = time % 60;
        format(MT, sizeof(MT), "%.0f:%d", timeM, timeS);
    }
    else if(time == 3600) MT = "1:0:0";
    else if(time > 3600 && time < 86400)
	{
        new Float: timeH;
        new timeMInt;
        new Float: timeM;
        new timeS;
        timeH = time / 3600;
        timeMInt = time % 3600;
        timeM = timeMInt / 60;
        timeS = timeMInt % 60;
        format(MT, sizeof(MT), "%.0f:%.0f:%d", timeH, timeM, timeS);
    }
    else if(time == 86400) MT = "1:0:0:0";
    else if(time > 86400)
    {
        new Float: timeD;
        new Float: timeH;
        new timeMInt, timeHInt;
        new Float: timeM;
        new timeS;
        timeD = time / 86400;
        timeHInt = time % 86400;
        timeMInt = time % 3600;
        timeH = timeHInt / 3600;
        timeM = timeMInt / 60;
        timeS = timeMInt % 60;
        format(MT, sizeof(MT), "%.0f:%.0f:%.0f:%d", timeD, timeH, timeM, timeS);
    }
    return MT;
}

stock GetWeaponModel(weaponid)
{
    switch(weaponid)
	{
        case 1: return 331;
        case 2..8: return weaponid+331;
        case 9: return 341;
	    case 10..15: return weaponid+311;
		case 16..18: return weaponid+326;
		case 22..29: return weaponid+324;
		case 30,31: return weaponid+325;
		case 32: return 372;
		case 33..45: return weaponid+324;
		case 46: return 371;
	}
	return 0;
}

stock IsCharName(string[])
{
    for(new i; i < strlen(string); i++) switch(string[i])
	{
        case '0'..'9': continue;
        case 'a'..'z': continue;
        case 'A'..'Z': continue;
        case 'а'..'я': continue;
        case 'А'..'Я': continue;
        case ']','[': continue;
        case ')','(': continue;
        case '_','$','=','@','.': continue;
        default: return 0;
    }
    return 1;
}

stock IsClanName(string[])
{
    for(new i; i < strlen(string); i++) switch(string[i])
	{
        case '0'..'9': continue;
        case 'a'..'z': continue;
        case 'A'..'Z': continue;
        case 'а'..'я': continue;
        case 'А'..'Я': continue;
        case ']','[': continue;
        case ')','(': continue;
        case '_','$','=','@','.': continue;
        default: return 0;
    }
    return 1;
}

stock IsPassword(string[])
{
    for(new i; i < strlen(string); i++) switch(string[i])
	{
        case '0'..'9': continue;
        case 'a'..'z': continue;
        case 'A'..'Z': continue;
        case 'а'..'я': continue;
        case 'А'..'Я': continue;
        case ']','[': continue;
        case ')','(': continue;
        case '_','$','=','@','.': continue;
        default: return 0;
    }
    return 1;
}

stock IsValidHEX(str[])
{
	new len = strlen(str);
	if(len != 6) return false;
	for(new i = 0; i < len; i++) if(str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != 'A' && str[i] != 'B' && str[i] != 'C' && str[i] != 'D' && str[i] != 'E' && str[i] != 'F') return false;
	return true;
}

stock AntiCaps(string[], pos = 1)
{
    static symbol;
    for (;;++pos)
    {
        if (0 != (symbol = string[pos]))
        {
            if (symbol < 'A' || 'Z' < symbol) continue;
            string[pos] = symbol + ('a' - 'A');
            continue;
        }
        break;
    }
}

stock emptyMessage(string[])
{
    for(new i; string[i]; i++)
    {
		if(string[i] == '\1') continue;
        switch(string[i])
        {
            case 0x20: continue;
            default: return false;
        }
    }
    return true;
}

stock split(const strsrc[], strdest[][], delimiter)
{
	new i, li;
	new aNum;
	new len;
	while(i <= strlen(strsrc))
	{
		if(strsrc[i]==delimiter || i==strlen(strsrc))
		{
			len = strmid(strdest[aNum], strsrc, li, i, 128);
			strdest[aNum][len] = 0;
			li = i+1;
			aNum++;
		}
		i++;
	}
	return 1;
}

stock HexToInt(string[])
{
	if(string[0]==0) return 0;
	new i;
	new cur=1;
	new res=0;
	for (i=strlen(string); i>0; i--)
	{
		if (string[i-1]<58) res=res+cur*(string[i-1]-48);
		else res = res+cur*(string[i-1]-65+10);
     	cur=cur*16;
 	}
	return res;
}

stock VehicleInPlayer(vehicleid, playerid, Float:radius)
{
	new Float:OnePos[3], Float:TwoPos[3], Float:TmpPos[3];
	GetPlayerPos(playerid, OnePos[0], OnePos[1], OnePos[2]);
	GetVehiclePos(vehicleid, TwoPos[0], TwoPos[1], TwoPos[2]);
	if(!IsPlayerInRangeOfPoint(playerid, radius, TwoPos[0], TwoPos[1], TwoPos[2])) return false;
	TmpPos[0] = (TwoPos[0] - OnePos[0]);
	TmpPos[1] = (TwoPos[1] - OnePos[1]);
	TmpPos[2] = (TwoPos[2] - OnePos[2]);
	if(((TmpPos[0] < radius) && (TmpPos[0] > -radius)) && ((TmpPos[1] < radius) && (TmpPos[1] > -radius)) && ((TmpPos[2] < radius) && (TmpPos[2] > -radius))) return true;
   	return false;
}

stock ProxDetectorS(Float:radi, playerid, targetid)
{
	if(IsPlayerConnected(playerid)&&IsPlayerConnected(targetid))
	{
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		//radi = 2.0; //Trigger Radius
		GetPlayerPos(targetid, posx, posy, posz);
		tempposx = (oldposx -posx);
		tempposy = (oldposy -posy);
		tempposz = (oldposz -posz);
		//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return true;
		}
	}
	return false;
}

stock GetClosestPlayer(p1)
{
	new Float:dis,Float:dis2,player;
	player = -1;
	dis = 99999.99;
	for(new x = GetPlayerPoolSize(); x >= 0; x--)
	{
		if(x != p1)
		{
			dis2 = GetDistanceBetweenPlayers(x,p1);
			if(dis2 < dis && dis2 != -1.00)
			{
				dis = dis2;
				player = x;
			}
		}
	}
	return player;
}

forward Float:GetDistanceBetweenPlayers(p1,p2);
public Float:GetDistanceBetweenPlayers(p1,p2)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    if(!IsPlayerConnected(p1) || !IsPlayerConnected(p2))
    {
  		return -1.00;
    }
    GetPlayerPos(p1,x1,y1,z1);
    GetPlayerPos(p2,x2,y2,z2);
    return floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
}

stock GetPasswordLevel(pass[])
{
	new bool:have_chars = false, bool:have_numbers = false, bool:have_upercase = false, bool:have_lowercase = false;

	const LOW = 0, MEDIUM = 1, HIGH = 2;

	for(new i = 0; pass[i] != 0x0; i++)
	{
		switch(pass[i])
		{
			case '0'..'9': have_numbers = true;
			case 'A'..'Z': have_upercase = true;
			case 'a'..'z': have_lowercase = true;
			case 'А'..'Я': have_upercase = true;
			case 'а'..'я': have_lowercase = true;
			default: have_chars = true;
		}
	}

	if(have_lowercase && have_numbers && have_chars && have_upercase) return HIGH;

	return ((have_lowercase ? 1 : 0) + (have_numbers ? 1 : 0) + (have_chars ? 1 : 0) + (have_upercase ? 1 : 0)) > 1 ? MEDIUM : LOW;
}

stock GetPlayerHighestScores(id[], score[], left, right)
{
    new
        tempLeft = left,
        tempRight = right,
        pivot = score[(left + right) / 2],
        tempVar
    ;
    while(tempLeft <= tempRight)
    {
        while(score[tempLeft] > pivot) tempLeft++;
        while(score[tempRight] < pivot) tempRight--;

        if(tempLeft <= tempRight)
        {
            tempVar = score[tempLeft], score[tempLeft] = score[tempRight], score[tempRight] = tempVar;
            tempVar = id[tempLeft], id[tempLeft] = id[tempRight], id[tempRight] = tempVar;
            tempLeft++, tempRight--;
        }
    }
    if(left < tempRight) GetPlayerHighestScores(id, score, left, tempRight);
    if(tempLeft < right) GetPlayerHighestScores(id, score, tempLeft, right);
}

stock strreplace(dest[], const string[], const replacestr[], bool:ignorecase = true, bool:ReplaceAll = true, maxlenght = sizeof(dest))
{
	new pos = strfind(dest, string, ignorecase);
	if(!strlen(dest) || !strlen(string) || pos == -1 || (!strcmp(string, replacestr, ignorecase) && strlen(replacestr))) return false;
	if(ReplaceAll) while(pos != -1)
	{
		strdel(dest, pos, pos + strlen(string));
		strins(dest, replacestr, pos, maxlenght);
		pos = strfind(dest, string, ignorecase);
	} else strdel(dest, pos, pos + strlen(string)), strins(dest, replacestr, pos, maxlenght);
	return true;
}

stock Float:GetPlayerPacketLoss(playerid)
{

    new stats[401], stringstats[70];
    GetPlayerNetworkStats(playerid, stats, sizeof(stats));
    new len = strfind(stats, "Packetloss: ");
    new Float:packetloss = 0.0;
	if(len != -1)
	{
		strmid(stringstats, stats, len, strlen(stats));
		new len2 = strfind(stringstats, "%");
		if(len != -1)
		{
			strdel(stats, 0, strlen(stats));
			strmid(stats, stringstats, len2-3, len2);
			packetloss = floatstr(stats);
		}
	}
    return packetloss;
}

stock IsNumeric(string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}

stock ifStrStartedFromStr(str1[], str2[])
{
   if(strlen(str1) < strlen(str2)) return false;
   if(strlen(str2) == 0) return true;
   new tmp[256];
   strmid(tmp, str1, 0, strlen(str2), 256);
   if(strcmp(tmp, str2, true) == 0) return true;
   return false;
}

stock ReadConf(File:f, st[], siz, minLen=5)
{
   new tmp[256];
   while(fread(f, tmp))
   {
      if((strlen(tmp) < minLen) ||
	     ifStrStartedFromStr(tmp, "//") ||
		 ifStrStartedFromStr(tmp, "*")  ||
		 ifStrStartedFromStr(tmp, "#"))
		   continue;
	  format(st, siz, "%s", tmp);
	  return true;
   }
   return false;
}

stock IsWeapIDCorrectly(weapID)
{
	if(weapID < 1) return false;
	if((weapID >= 19) && (weapID <= 21)) return false;
	if(weapID > 46) return false;
	return true;
}

stock StripNewLine(string[]) {
    new len = strlen(string);
    if (string[0]==0) return ;
    if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
        string[len - 1] = 0;
        if (string[0]==0) return ;
        if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
    }
}

stock minrandom(min, max)
{
	new tmp = floatround(random(max - min) + min);
	if((tmp >= max) || (tmp<min)) tmp = min;
	return tmp;
}

stock strmidex(dest[], const src[],  start, end, maxlength=sizeof dest)
{
	if(end - start > 1)
	strmid(dest, src,  start, end, maxlength);
}

stock LowerToUpper(text[])
{
	for(new i;i<strlen(text);i++)
	{
		text[i] = toupper(text[i]);
	}
}

stock GeneratePassword(passlength=8)
{
    new tmp[MAX_PLAYER_PASSWORD];
    if(passlength <= MAX_PLAYER_PASSWORD)
    {
        for(new i = 0; i < passlength; i++)
        {
	        new mode = random(3);
	        if(mode == 0) tmp[i] = random('z' - 'a') + 'a';
	        else if(mode == 1) tmp[i] = toupper(random('z' - 'a') + 'a');
	        else if(mode == 2) valstr(tmp[i],random(9));
        }
    }
    return tmp;
}
