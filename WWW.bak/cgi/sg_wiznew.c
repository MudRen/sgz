#include <mudlib.h>
#define GOT_WIZ_MSG load_object("/daemons/history_d.c")->wiz_for_web()

string main(string str)
{
	string html;

	html =@HTML
<html>
<body  topmargin="12" background="http://sgz.yesite.com/images/desk5.gif" text="#FFFFFF">
<br>
<head><h2><center>�����������</center></h2><head>
<br><br>
HTML;
	html = html + GOT_WIZ_MSG;
	html = html + "</body></html>";

	return html;
}
