#if defined _news_included
	#endinput
#endif

#define _news_included
#pragma library news

enum nInfo
{
	nDate[15],
	nVersion[15],
	nAdded[512],
	nFixed[512],
	nActive,
}
new NewsInfo[nInfo];

forward LoadNews();
public LoadNews()
{
	new rows,fields;
    cache_get_data(rows,fields,mysqlConnection);
    if(rows)
    {
	    cache_get_field_content(0,"nDate", NewsInfo[nDate], mysqlConnection, 15);
	    cache_get_field_content(0,"nVersion", NewsInfo[nVersion], mysqlConnection, 15);
	    cache_get_field_content(0,"nAdded", NewsInfo[nAdded], mysqlConnection, 512);
	    cache_get_field_content(0,"nFixed", NewsInfo[nFixed], mysqlConnection, 512);

		strreplace(NewsInfo[nAdded], "<br>", "\n", false, true, sizeof(NewsInfo[nAdded]));
		strreplace(NewsInfo[nFixed], "<br>", "\n", false, true, sizeof(NewsInfo[nFixed]));
    }
    else
    {
	    NewsInfo[nActive] = 1;
    }
    return true;
}
