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
	#define GEOIP_UNKNOWN              "Неизвестно"
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
    {"AU","Австралия"},
    {"AT","Австрия"},
    {"AZ","Азербайджан"},
    {"AX","Аландские острова"},
    {"AL","Албания"},
    {"DZ","Алжир"},
    {"VI","Американские Виргинские острова"},
    {"AS","Американское Самоа"},
    {"AI","Ангилья"},
    {"AO","Ангола"},
    {"AD","Андорра"},
    {"AQ","Антарктида"},
    {"AG","Антигуа и Барбуда"},
    {"AR","Аргентина"},
    {"AM","Армения"},
    {"AW","Аруба"},
    {"AF","Афганистан"},
    {"BS","Багамы"},
    {"BD","Бангладеш"},
    {"BB","Барбадос"},
    {"BH","Бахрейн"},
    {"BZ","Белиз"},
    {"BY","Белоруссия"},
    {"BE","Бельгия"},
    {"BJ","Бенин"},
    {"BM","Бермуды"},
    {"BG","Болгария"},
    {"BO","Боливия"},
    {"BQ","Бонэйр, Синт-Эстатиус и Саба"},
    {"BA","Босния и Герцеговина"},
    {"BW","Ботсвана"},
    {"BR","Бразилия"},
    {"IO","Британская территория в Индийском океане"},
    {"VG","Британские Виргинские острова"},
    {"BN","Бруней"},
    {"BF","Буркина-Фасо"},
    {"BI","Бурунди"},
    {"BT","Бутан"},
    {"VU","Вануату"},
    {"VA","Ватикан"},
    {"GB","Великобритания"},
    {"HU","Венгрия"},
    {"VE","Венесуэла"},
    {"UM","Внешние малые острова (США)"},
    {"TL","Восточный Тимор"},
    {"VN","Вьетнам"},
    {"GA","Габон"},
    {"HT","Гаити"},
    {"GY","Гайана"},
    {"GM","Гамбия"},
    {"GH","Гана"},
    {"GP","Гваделупа"},
    {"GT","Гватемала"},
    {"GF","Гвиана"},
    {"GN","Гвинея"},
    {"GW","Гвинея-Бисау"},
    {"DE","Германия"},
    {"GG","Гернси"},
    {"GI","Гибралтар"},
    {"HN","Гондурас"},
    {"HK","Гонконг"},
    {"GD","Гренада"},
    {"GL","Гренландия"},
    {"GR","Греция"},
    {"GE","Грузия"},
    {"GU","Гуам"},
    {"DK","Дания"},
    {"JE","Джерси"},
    {"DJ","Джибути"},
    {"DM","Доминика"},
    {"DO","Доминиканская Республика"},
    {"CD","ДР Конго"},
    {"EU","Европейский союз"},
    {"EG","Египет"},
    {"ZM","Замбия"},
    {"EH","Западная Сахара"},
    {"ZW","Зимбабве"},
    {"IL","Израиль"},
    {"IN","Индия"},
    {"ID","Индонезия"},
    {"JO","Иордания"},
    {"IQ","Ирак"},
    {"IR","Иран"},
    {"IE","Ирландия"},
    {"IS","Исландия"},
    {"ES","Испания"},
    {"IT","Италия"},
    {"YE","Йемен"},
    {"CV","Кабо-Верде"},
    {"KZ","Казахстан"},
    {"KY","Каймановы острова"},
    {"KH","Камбоджа"},
    {"CM","Камерун"},
    {"CA","Канада"},
    {"QA","Катар"},
    {"KE","Кения"},
    {"CY","Кипр"},
    {"KG","Киргизия"},
    {"KI","Кирибати"},
    {"TW","Китайская Республика"},
    {"KP","КНДР"},
    {"CN","КНР"},
    {"CC","Кокосовые острова"},
    {"CO","Колумбия"},
    {"KM","Коморы"},
    {"CR","Коста-Рика"},
    {"CI","Кот-д’Ивуар"},
    {"CU","Куба"},
    {"KW","Кувейт"},
    {"CW","Кюрасао"},
    {"LA","Лаос"},
    {"LV","Латвия"},
    {"LS","Лесото"},
    {"LR","Либерия"},
    {"LB","Ливан"},
    {"LY","Ливия"},
    {"LT","Литва"},
    {"LI","Лихтенштейн"},
    {"LU","Люксембург"},
    {"MU","Маврикий"},
    {"MR","Мавритания"},
    {"MG","Мадагаскар"},
    {"YT","Майотта"},
    {"MO","Макао"},
    {"MK","Македония"},
    {"MW","Малави"},
    {"MY","Малайзия"},
    {"ML","Мали"},
    {"MV","Мальдивы"},
    {"MT","Мальта"},
    {"MA","Марокко"},
    {"MQ","Мартиника"},
    {"MH","Маршалловы Острова"},
    {"MX","Мексика"},
    {"FM","Микронезия"},
    {"MZ","Мозамбик"},
    {"MD","Молдавия"},
    {"MC","Монако"},
    {"MN","Монголия"},
    {"MS","Монтсеррат"},
    {"MM","Мьянма"},
    {"NA","Намибия"},
    {"NR","Науру"},
    {"NP","Непал"},
    {"NE","Нигер"},
    {"NG","Нигерия"},
    {"NL","Нидерланды"},
    {"NI","Никарагуа"},
    {"NU","Ниуэ"},
    {"NZ","Новая Зеландия"},
    {"NC","Новая Каледония"},
    {"NO","Норвегия"},
    {"AE","ОАЭ"},
    {"OM","Оман"},
    {"BV","Остров Буве"},
    {"IM","Остров Мэн"},
    {"CK","Острова Кука"},
    {"NF","Остров Норфолк"},
    {"CX","Остров Рождества"},
    {"PN","Острова Питкэрн"},
    {"SH","Острова Святой Елены, Вознесения и Тристан-да-Кунья"},
    {"PK","Пакистан"},
    {"PW","Палау"},
    {"PS","Палестинская национальная администрация"},
    {"PA","Панама"},
    {"PG","Папуа — Новая Гвинея"},
    {"PY","Парагвай"},
    {"PE","Перу"},
    {"PL","Польша"},
    {"PT","Португалия"},
    {"PR","Пуэрто-Рико"},
    {"CG","Республика Конго"},
    {"KR","Республика Корея"},
    {"RE","Реюньон"},
    {"RU","Россия"},
    {"RW","Руанда"},
    {"RO","Румыния"},
    {"SV","Сальвадор"},
    {"WS","Самоа"},
    {"SM","Сан-Марино"},
    {"ST","Сан-Томе и Принсипи"},
    {"SA","Саудовская Аравия"},
    {"SZ","Свазиленд"},
    {"MP","Северные Марианские острова"},
    {"SC","Сейшельские Острова"},
    {"BL","Сен-Бартелеми"},
    {"MF","Сен-Мартен"},
    {"PM","Сен-Пьер и Микелон"},
    {"SN","Сенегал"},
    {"VC","Сент-Винсент и Гренадины"},
    {"KN","Сент-Китс и Невис"},
    {"LC","Сент-Люсия"},
    {"RS","Сербия"},
    {"SG","Сингапур"},
    {"SX","Синт-Мартен"},
    {"SY","Сирия"},
    {"SK","Словакия"},
    {"SI","Словения"},
    {"SB","Соломоновы Острова"},
    {"SO","Сомали"},
    {"SD","Судан"},
    {"SU","СССР"},
    {"SR","Суринам"},
    {"US","США"},
    {"SL","Сьерра-Леоне"},
    {"TJ","Таджикистан"},
    {"TH","Таиланд"},
    {"TZ","Танзания"},
    {"TC","Тёркс и Кайкос"},
    {"TG","Того"},
    {"TK","Токелау"},
    {"TO","Тонга"},
    {"TT","Тринидад и Тобаго"},
    {"TV","Тувалу"},
    {"TN","Тунис"},
    {"TM","Туркмения"},
    {"TR","Турция"},
    {"UG","Уганда"},
    {"UZ","Узбекистан"},
    {"UA","Украина"},
    {"WF","Уоллис и Футуна"},
    {"UY","Уругвай"},
    {"FO","Фарерские острова"},
    {"FJ","Фиджи"},
    {"PH","Филиппины"},
    {"FI","Финляндия"},
    {"FK","Фолклендские острова"},
    {"FR","Франция"},
    {"PF","Французская Полинезия"},
    {"TF","Французские Южные и Антарктические Территории"},
    {"HM","Херд и Макдональд"},
    {"HR","Хорватия"},
    {"CF","ЦАР"},
    {"TD","Чад"},
    {"ME","Черногория"},
    {"CZ","Чехия"},
    {"CL","Чили"},
    {"CH","Швейцария"},
    {"SE","Швеция"},
    {"SJ","Шпицберген и Ян-Майен"},
    {"LK","Шри-Ланка"},
    {"EC","Эквадор"},
    {"GQ","Экваториальная Гвинея"},
    {"ER","Эритрея"},
    {"EE","Эстония"},
    {"ET","Эфиопия"},
    {"ZA","ЮАР"},
    {"GS","Южная Георгия и Южные Сандвичевы острова"},
    {"SS","Южный Судан"},
    {"JM","Ямайка"},
    {"JP","Япония"}
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
	printf("GetGeoIP:(%s, %s, %s, %s): %d мс", ip, country, city, region, GetTickCount() - count);
	return 1;
}
