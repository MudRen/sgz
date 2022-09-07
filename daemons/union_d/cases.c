private mapping cases;

static mapping types = ([ "player_recover" : "�ָ���������",
		   	"player_conflict": "��Ҿ���",
		   	"nation_recover" : "�ָ���������",
		   	"nation_conflict": "���Ҿ���",
		   	"others"	    : "����", ]);

void save_data();

mapping query_types()
{
    return types;
}
int set_case(string who, string para, mixed val)
{
    if ( !cases||!mapp(cases) ) cases = ([ ]);
    if ( !who||who==""||!stringp(who) ) return 1;
    if ( member_array(who, keys(cases))==-1 ) return 2;
    if ( !para||para==""||!stringp(para) ) return 3; 
    cases[who][para] = val;
    save_data();
    return 4;
}
mixed query_case(string who, string para)
{
    if ( !cases||!mapp(cases) ) cases = ([ ]);
    if ( !who||who==""||!stringp(who) ) return cases;
    if ( member_array(who, keys(cases))==-1 ) return cases;
    if ( !para||para==""||!stringp(para) ) return cases[who];
    return cases[who][para];
}
int add_case(string who, string type)
{
    if ( !cases||!mapp(cases) ) cases = ([ ]);
    if ( member_array(who, keys(cases))!=-1 ) return 1;
    cases[who] = (["who":who, "whom":"", "reason":"", 
		"type":type, "solution":"", "ev": ([ ]), "comment":([ ]), ]);
    save_data();
    return 2;
}
int remove_case(string who)
{
    map_delete(cases, who);
    save_data();
    return 2;
}
string format_ev(mapping m)
{
    string who, str = "";
    if ( !sizeof(m) ) return "����";
    foreach ( string s in keys(m) ) {
        if ( CHAR_D->char_exist(s) ) who = CHAR_D->get_char(s,"name");
        else who = "����";
	if ( m[s] !=- 1 ) str += "%^H_CYAN%^"+who+"%^RESET%^"+"("+s+")  ";
        else str += who+"("+s+")  ";
    }
    return str;
}
string query_case_list()
{
    int i;
    string str, *list, who;
    mapping m;

    if ( !mapp(cases) ) str = "Ŀǰû�������κ�Ͷ�ߣ�\n";
    else {
	list = keys(cases);
	str = "Ŀǰ�����Ͷ���У�\n";
        str+= sprintf("   %-12s     %-12s       %-11s     %s\n", 
		"Ͷ����", "��������", "��Ͷ����/��", "֤��");
	for ( i=0; i<sizeof(list); i++ ) {
            m = cases[list[i]];
            if ( m["type"]=="nation_conflict" ){
		who = COUNTRY_D->get_country(m["whom"],"name");
                if ( !who ) who = "����";
                else who += "("+m["whom"]+")";
            } else {
                who = CHAR_D->get_char(m["whom"], "name");
		if ( !who ) who = "����";
                else who += "("+m["whom"]+")";
            }
            str+=sprintf("%-2s)%-12s     %-12s       %-11s     %s\n",
                ((i+1)>9?(i+1):" "+(i+1)),
		CHAR_D->get_char(m["who"], "name")+"("+m["who"]+")",
		types[m["type"]],
		who,
                format_ev(m["ev"]), );
        }
    }
    return str;
}
string view_case(string who, int level)
{
    string w, str;
    mapping m;

    if ( !who||who==""||!stringp(who) ) return "";
    if ( member_array(who, keys(cases))==-1 ) return "";
    m = cases[who];

    if ( m["type"]=="nation_conflict" ){
         w = COUNTRY_D->get_country(m["whom"],"name");
         if ( !w ) w = "����";
         else w += "("+m["whom"]+")";
    } else {
         w = CHAR_D->get_char(m["whom"], "name");
         if ( !w ) w = "����";
         else w += "("+m["whom"]+")";
    }
    str= sprintf("��%-12s     %-12s       %-11s     %s\n",
	"Ͷ����", "��������", "��Ͷ����/��", "֤��");
    str+=sprintf("��%-12s     %-12s       %-11s     %s\n",
                CHAR_D->get_char(m["who"], "name")+"("+m["who"]+")",
                types[m["type"]], w, format_ev(m["ev"]), );
    str+= "%^H_CYAN%^"+CHAR_D->get_char(m["who"], "name")+"���������£�\n%^RESET%^"+m["reason"]+"\n";
    if ( level == 1 )
    	str+= "%^H_CYAN%^"+CHAR_D->get_char(m["who"], "name")+"����Ĵ������£�\n%^RESET%^"+m["solution"]+"\n";
    if ( sizeof(m=m["comment"]) ) {
        str+= "%^H_CYAN%^"+"����"+chinese_number(sizeof(m))+"�˶Ա����������Լ��Ŀ�����\n%^RESET%^";
        foreach(string s in keys(m) ){
 	    str+="%^H_YELLOW%^"+CHAR_D->get_char(s, "name")+"����Ŀ������£�%^RESET%^ \n";
	    if ( stringp(m[s])&&sizeof(m[s])&&m[s][0]=='*'&&level!=1 )
		str+= "������Ϊ�������ԡ�\n";
	    else str+=m[s]+"\n";
 	}
    }
    return str;
}
