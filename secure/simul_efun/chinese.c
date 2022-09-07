// Updated by stefan on 10 Jan 1997
#include <daemons.h>

static mapping prep_info = ([ 
        "in"    : "%s����",
        "from"  : "��%s",
        "on"    : "%s��",
        "under" : "%s����",
        "behind": "%s����",
        "beside": "%s���Ա�",
        "to"    : "%s",
        "with"  : "��%sһ��", 
        "at"    : "��%s", 
        "off"   : "%s��", 
        "out"   : "%s����", 
        "down"  : "%s�·�", 
        "up"    : "%s�Ϸ�", 
        "around": "%s��Χ", 
        "over"  : "%s����",
        "into"  : "%s��", 
        "about" : "����%s",
       ]); 
                

string prep_calc(string prep, string name) {
        if (member_array(prep, keys(prep_info))==-1) return prep + name;
        else return sprintf(prep_info[prep], name);
        	
}

string chinese_number(int i)
{
        return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
        return CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
        if (strlen(str)>=2 && str[0]>128 && str[0]<255) return 1;
        return 0;
}

string gender_self(string sex)
{
        switch(sex) {
                case "Ů��": return "��";       break;
                default: return "��";
        }
}

string gender_pronoun(string sex)
{
        switch(sex) {
                case "����":    return "��";    break;
                case "Ů��":    return "��";    break;
                case "����":
                case "����":    return "��";    break;
                default: return "��";
        }
}
