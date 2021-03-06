/*  SA-MP Geoip Functions
 *
 *  (c) Copyright 2016-20xx
 *
 */

#if defined _geoip_included
	#endinput
#endif
#define _geoip_included
#pragma library geoip

#if !defined mysql_host_geoip
	#define mysql_host_geoip           "127.0.0.1"
#endif
#if !defined mysql_db_geoip
	#define mysql_db_geoip             "getgeoip"
#endif
#if !defined mysql_user_geoip
	#define mysql_user_geoip           "root"
#endif
#if !defined mysql_pass_geoip
	#define mysql_pass_geoip           ""
#endif
#if !defined GEOIP_UNKNOWN
	#define GEOIP_UNKNOWN              "����������"
#endif
#if !defined MAX_COUNTRY_NAME
	#define MAX_COUNTRY_NAME           64
#endif
#if !defined MAX_CITY_NAME
	#define MAX_CITY_NAME              32
#endif
#if !defined MAX_REGION_NAME
	#define MAX_REGION_NAME            64
#endif

new geoipDB;

enum geoipCode
{
	CC[4],
	CN_rus[60]
}

static const arGeoCodes[][geoipCode] =
{
    {"AU","���������"},
    {"AT","�������"},
    {"AZ","�����������"},
    {"AX","��������� �������"},
    {"AL","�������"},
    {"DZ","�����"},
    {"VI","������������ ���������� �������"},
    {"AS","������������ �����"},
    {"AI","�������"},
    {"AO","������"},
    {"AD","�������"},
    {"AQ","����������"},
    {"AG","������� � �������"},
    {"AR","���������"},
    {"AM","�������"},
    {"AW","�����"},
    {"AF","����������"},
    {"BS","������"},
    {"BD","���������"},
    {"BB","��������"},
    {"BH","�������"},
    {"BZ","�����"},
    {"BY","����������"},
    {"BE","�������"},
    {"BJ","�����"},
    {"BM","�������"},
    {"BG","��������"},
    {"BO","�������"},
    {"BQ","������, ����-�������� � ����"},
    {"BA","������ � �����������"},
    {"BW","��������"},
    {"BR","��������"},
    {"IO","���������� ���������� � ��������� ������"},
    {"VG","���������� ���������� �������"},
    {"BN","������"},
    {"BF","�������-����"},
    {"BI","�������"},
    {"BT","�����"},
    {"VU","�������"},
    {"VA","�������"},
    {"GB","��������������"},
    {"HU","�������"},
    {"VE","���������"},
    {"UM","������� ����� ������� (���)"},
    {"TL","��������� �����"},
    {"VN","�������"},
    {"GA","�����"},
    {"HT","�����"},
    {"GY","������"},
    {"GM","������"},
    {"GH","����"},
    {"GP","���������"},
    {"GT","���������"},
    {"GF","������"},
    {"GN","������"},
    {"GW","������-�����"},
    {"DE","��������"},
    {"GG","������"},
    {"GI","���������"},
    {"HN","��������"},
    {"HK","�������"},
    {"GD","�������"},
    {"GL","����������"},
    {"GR","������"},
    {"GE","������"},
    {"GU","����"},
    {"DK","�����"},
    {"JE","������"},
    {"DJ","�������"},
    {"DM","��������"},
    {"DO","������������� ����������"},
    {"CD","�� �����"},
    {"EU","����������� ����"},
    {"EG","������"},
    {"ZM","������"},
    {"EH","�������� ������"},
    {"ZW","��������"},
    {"IL","�������"},
    {"IN","�����"},
    {"ID","���������"},
    {"JO","��������"},
    {"IQ","����"},
    {"IR","����"},
    {"IE","��������"},
    {"IS","��������"},
    {"ES","�������"},
    {"IT","������"},
    {"YE","�����"},
    {"CV","����-�����"},
    {"KZ","���������"},
    {"KY","��������� �������"},
    {"KH","��������"},
    {"CM","�������"},
    {"CA","������"},
    {"QA","�����"},
    {"KE","�����"},
    {"CY","����"},
    {"KG","��������"},
    {"KI","��������"},
    {"TW","��������� ����������"},
    {"KP","����"},
    {"CN","���"},
    {"CC","��������� �������"},
    {"CO","��������"},
    {"KM","������"},
    {"CR","�����-����"},
    {"CI","���-������"},
    {"CU","����"},
    {"KW","������"},
    {"CW","�������"},
    {"LA","����"},
    {"LV","������"},
    {"LS","������"},
    {"LR","�������"},
    {"LB","�����"},
    {"LY","�����"},
    {"LT","�����"},
    {"LI","�����������"},
    {"LU","����������"},
    {"MU","��������"},
    {"MR","����������"},
    {"MG","����������"},
    {"YT","�������"},
    {"MO","�����"},
    {"MK","���������"},
    {"MW","������"},
    {"MY","��������"},
    {"ML","����"},
    {"MV","��������"},
    {"MT","������"},
    {"MA","�������"},
    {"MQ","���������"},
    {"MH","���������� �������"},
    {"MX","�������"},
    {"FM","����������"},
    {"MZ","��������"},
    {"MD","��������"},
    {"MC","������"},
    {"MN","��������"},
    {"MS","����������"},
    {"MM","������"},
    {"NA","�������"},
    {"NR","�����"},
    {"NP","�����"},
    {"NE","�����"},
    {"NG","�������"},
    {"NL","����������"},
    {"NI","���������"},
    {"NU","����"},
    {"NZ","����� ��������"},
    {"NC","����� ���������"},
    {"NO","��������"},
    {"AE","���"},
    {"OM","����"},
    {"BV","������ ����"},
    {"IM","������ ���"},
    {"CK","������� ����"},
    {"NF","������ �������"},
    {"CX","������ ���������"},
    {"PN","������� �������"},
    {"SH","������� ������ �����, ���������� � �������-��-�����"},
    {"PK","��������"},
    {"PW","�����"},
    {"PS","������������ ������������ �������������"},
    {"PA","������"},
    {"PG","����� � ����� ������"},
    {"PY","��������"},
    {"PE","����"},
    {"PL","������"},
    {"PT","����������"},
    {"PR","������-����"},
    {"CG","���������� �����"},
    {"KR","���������� �����"},
    {"RE","�������"},
    {"RU","������"},
    {"RW","������"},
    {"RO","�������"},
    {"SV","���������"},
    {"WS","�����"},
    {"SM","���-������"},
    {"ST","���-���� � ��������"},
    {"SA","���������� ������"},
    {"SZ","���������"},
    {"MP","�������� ���������� �������"},
    {"SC","����������� �������"},
    {"BL","���-���������"},
    {"MF","���-������"},
    {"PM","���-���� � �������"},
    {"SN","�������"},
    {"VC","����-������� � ���������"},
    {"KN","����-���� � �����"},
    {"LC","����-�����"},
    {"RS","������"},
    {"SG","��������"},
    {"SX","����-������"},
    {"SY","�����"},
    {"SK","��������"},
    {"SI","��������"},
    {"SB","���������� �������"},
    {"SO","������"},
    {"SD","�����"},
    {"SU","����"},
    {"SR","�������"},
    {"US","���"},
    {"SL","������-�����"},
    {"TJ","�����������"},
    {"TH","�������"},
    {"TZ","��������"},
    {"TC","Ҹ��� � ������"},
    {"TG","����"},
    {"TK","�������"},
    {"TO","�����"},
    {"TT","�������� � ������"},
    {"TV","������"},
    {"TN","�����"},
    {"TM","���������"},
    {"TR","������"},
    {"UG","������"},
    {"UZ","����������"},
    {"UA","�������"},
    {"WF","������ � ������"},
    {"UY","�������"},
    {"FO","��������� �������"},
    {"FJ","�����"},
    {"PH","���������"},
    {"FI","���������"},
    {"FK","������������ �������"},
    {"FR","�������"},
    {"PF","����������� ���������"},
    {"TF","����������� ����� � �������������� ����������"},
    {"HM","���� � ����������"},
    {"HR","��������"},
    {"CF","���"},
    {"TD","���"},
    {"ME","����������"},
    {"CZ","�����"},
    {"CL","����"},
    {"CH","���������"},
    {"SE","������"},
    {"SJ","���������� � ��-�����"},
    {"LK","���-�����"},
    {"EC","�������"},
    {"GQ","�������������� ������"},
    {"ER","�������"},
    {"EE","�������"},
    {"ET","�������"},
    {"ZA","���"},
    {"GS","����� ������� � ����� ���������� �������"},
    {"SS","����� �����"},
    {"JM","������"},
    {"JP","������"}
};

public OnGameModeInit()
{
    geoipDB = mysql_connect(mysql_host_geoip, mysql_user_geoip, mysql_db_geoip, mysql_pass_geoip);
    mysql_tquery(geoipDB, "SET NAMES cp1251", "", "");
    mysql_tquery(geoipDB, "SET CHARACTER SET cp1251", "", "");
    mysql_query(geoipDB, "SET NAMES cp1251");
    mysql_query(geoipDB, "SET CHARACTER SET cp1251");

	CallLocalFunction("geoip_OnGameModeInit", "");
	return 1;
}

#if defined _ALS_OnGameModeInit
#undef OnGameModeInit
#else
#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit geoip_OnGameModeInit

forward geoip_OnGameModeInit(playerid);

public OnGameModeExit()
{
	mysql_close(geoipDB);

	CallLocalFunction("geoip_OnGameModeExit", "");
	return 1;
}

#if defined _ALS_OnGameModeExit
#undef OnGameModeExit
#else
#define _ALS_OnGameModeExit
#endif

#define OnGameModeExit geoip_OnGameModeExit

forward geoip_OnGameModeExit(playerid);

stock GeoIPCodesCountry(dest[])
{
	for (new i = 0; i < sizeof(arGeoCodes); i++)
	{
		if(!strcmp(dest, arGeoCodes[i][CC], false)) format(dest, 128, "%s", arGeoCodes[i][CN_rus]);
	}
	return true;
}

stock GetGeoIP(ip[], country[], city[], region[], geoipHandle = 1)
{
	new count = GetTickCount();
	new query[256];
	new Cache:result, city_id;
	if(mysql_errno(geoipHandle) != 0)
	{
		if(!strlen(country)) format(country, MAX_COUNTRY_NAME, GEOIP_UNKNOWN);
		if(!strlen(city)) format(city, MAX_CITY_NAME, GEOIP_UNKNOWN);
		if(!strlen(region)) format(region, MAX_REGION_NAME, GEOIP_UNKNOWN);
		return 0;
	}
	if(!city_id)
	{
		mysql_format(geoipHandle, query, sizeof(query),"SELECT `country`, `city_id` FROM `ipgeobase_country` WHERE `long_ip1` <= INET_ATON('%e') AND `long_ip2` >= INET_ATON('%e') LIMIT 1", ip, ip);
		result = mysql_query(geoipHandle, query);
		if (result)
		{
			if (cache_get_row_count())
			{
				cache_get_field_content(0, "country", country, geoipHandle, MAX_COUNTRY_NAME);
				GeoIPCodesCountry(country);
				city_id = cache_get_field_content_int(0, "city_id");
			}
			cache_delete(result);
		}
		if(city_id)
		{
			mysql_format(geoipHandle, query, sizeof(query),"SELECT `city`, `region`, `district` FROM `ipgeobase_city` WHERE `city_id` = '%d' LIMIT 1", city_id);
			result = mysql_query(geoipHandle, query);
			if (result)
			{
				if (cache_get_row_count())
				{
					new regdist[2][MAX_REGION_NAME/2];
					cache_get_field_content(0, "city", city, geoipHandle, MAX_CITY_NAME);
					cache_get_field_content(0, "region", regdist[0], geoipHandle, MAX_REGION_NAME);
					cache_get_field_content(0, "district", regdist[1], geoipHandle, MAX_REGION_NAME);
					format(region, MAX_REGION_NAME, "%s, %s", regdist[0], regdist[1]);
				}
				cache_delete(result);
			}
		}
	}
	if(!city_id)
	{
		if(!strlen(country))
		{
			mysql_format(geoipHandle, query, sizeof(query),"SELECT `country_code` FROM `maxmind_ipcountry` WHERE `ip_to` >= INET_ATON('%e') ORDER BY `ip_to` ASC LIMIT 1", ip);
			result = mysql_query(geoipHandle, query);
			if (result)
			{
				if (cache_get_row_count())
				{
					cache_get_field_content(0, "country_code", country, geoipHandle, MAX_COUNTRY_NAME);
					GeoIPCodesCountry(country);
				}
				cache_delete(result);
			}
		}
		mysql_format(geoipHandle, query, sizeof(query),"SELECT `locid` FROM `maxmind_ipcity` WHERE `ip_to` >= INET_ATON('%e') ORDER BY `ip_to` ASC LIMIT 1", ip);
		result = mysql_query(geoipHandle, query);
		if (result)
		{
			if (cache_get_row_count())
			{
				city_id = cache_get_field_content_int(0, "locid");
			}
			cache_delete(result);
		}
		if(city_id)
		{
			mysql_format(geoipHandle, query, sizeof(query),"SELECT `city` FROM `mixmind_cityloc` WHERE `locid` = '%d' LIMIT 1", city_id);
			result = mysql_query(geoipHandle, query);
			if (result)
			{
				if (cache_get_row_count())
				{
					cache_get_field_content(0, "city", city, geoipHandle, MAX_CITY_NAME);
				}
				cache_delete(result);
			}
		}
	}
	if(!strlen(country)) format(country, MAX_COUNTRY_NAME, GEOIP_UNKNOWN);
	if(!strlen(city)) format(city, MAX_CITY_NAME, GEOIP_UNKNOWN);
	if(!strlen(region)) format(region, MAX_REGION_NAME, GEOIP_UNKNOWN);
	printf("GetGeoIP:(%s, %s, %s, %s): %d ��", ip, country, city, region, GetTickCount() - count);
	return 1;
}
