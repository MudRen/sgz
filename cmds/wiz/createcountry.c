/* createcountry.c by fire on 26/06/98
this cmd is used to create a newcountry 
in the sg system, this cmmond should
set some priviliage in case careless
wiz may cause unnessary data just by testing
usage: createcountry <char id>
example: createcountry ma teng
*/
#include <mudlib.h>
#include <daemons.h>
#include <country.h>
inherit CMD;
nomask private void main(string str)
{
	string p_id=str;
    int extra = 0;
	string ret;
    if (!str)
    {
        write("�÷���createcountry <char id>\n");
        return;
    }
	extra=COUNTRY_D->creat_country(str);
	switch(extra)
	{
	case CC_ALREADYEXIST:
		ret="�ý�ɫ�Ѿ��ǹ�����\n";
		break;
	case CC_CHARNOTEXIST:
		ret="û�иý�ɫ��\n";
		break;
	case CC_CHARNOAREA:
		ret="�ý�ɫû�����ڵأ�\n";
		break;
		case CC_OTHERCOUNTRYCAPITAL:
			ret="�õ�Ϊ����������\n";
			break;
	case CC_ACCEPTED:
		ret ="�ɹ���\n";
		break;
	default:
		ret= "δ�ɹ�\n";
	}
	write(ret);
}
