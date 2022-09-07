//******************************************************************* 
// score.c *******************************************************
// by fire on Dec 30 1997
// last modified by tset Feb 7 1998
// last modified by row June 1999
#include <ansi.h>
#define p_sep "%^H_YELLOW%^��%^H_CYAN%^����������������%^B_RED%^%^H_YELLOW%^����  ��  ��  ����%^RESET%^%^H_CYAN%^����������������%^H_YELLOW%^��%^RESET%^"
inherit VERB_OB;
inherit M_OUT;
inherit CHINESE_DA;
inherit M_ANSI;
string bar="%^H_CYAN%^��%^RESET%^",space="                                      ";
int N1=24 , N2=24;

mixed can_score_liv(object liv)
{
        return 1;
}

private void score_print(object who)
{
        string p_name;  
		string p_hd;
		string p_jy;
	    				
        int p_age, p_gender,i;
        int p_zhimou,p_meili,p_wuli,p_rongmao;
        string p_id,tm1,tm2;
        mapping p_jyxd;
		p_id=who->query_id()[0];
		//printf("p_id = %s\n", p_id); DEBUG
        p_name=who->query_title();
		//printf("p_name = %s\n", p_name); DEBUG
        if(!p_name)
			p_name=who->query_name();
        if(!p_name)
			p_name=who->query_in_room_desc();
        printf("\n");
        printf("%s\n",p_sep);
        printf("%%^H_CYAN%%^��                                                  ��\n");
        
        p_age=who->query_age();
        p_gender=who->query_gender();
		//printf("���е�query_gender()��.\n"); DEBUG
// row, all you need just follow the style of the following three lines
// very simple, addoil :)
        tm1="%^H_CYAN%^��������������"+who->query_name();
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);
        tm1="%^H_CYAN%^��Ӣ�Ĵ��š���"+p_id;
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);
//        printf("%s%s%s%s%s%s\n",bar,tm1,space[0..N1-colour_strlen(tm1)],
//        tm2,space[0..N2-colour_strlen(tm2)],bar);

        tm1="%^H_GREEN%^����    �䡿��"+chinese_number(p_age);
        tm2="%^H_GREEN%^����    �𡿣�"+( p_gender==1 ? "��" : "Ů")+"%^RESET%^";
        printf("%s%s%s%s%s%s\n",bar,tm1,space[0..N1-colour_strlen(tm1)],
           tm2,space[0..N2-colour_strlen(tm2)],bar);

        p_wuli=who->query_wuli_pure();
        p_zhimou=who->query_zhimou_pure();
        p_meili=who->query_meili_pure();
        p_rongmao=who->query_sg_rongmao();
        tm1="%^H_YELLOW%^����    ò����"+p_rongmao;
        tm2="%^H_RED%^�������书����"+FIGHT_D->get_pure_att_abi(who)+"[+"+FIGHT_D->get_add_att_abi(who)+"]";
        printf("%s%s%s%s%s%s\n",bar,tm1,space[0..N1-colour_strlen(tm1)],

        tm2,space[0..N2-colour_strlen(tm2)],bar);
        
        tm1="%^H_YELLOW%^����    ������"+p_wuli;
        tm2="%^H_RED%^��ɱ �� ������"+FIGHT_D->get_pure_att_pow(who)+"[+"+FIGHT_D->get_add_att_pow(who)+"]";
        printf("%s%s%s%s%s%s\n",bar,tm1,space[0..N1-colour_strlen(tm1)],
        tm2,space[0..N2-colour_strlen(tm2)],bar);
        
        tm1="%^H_YELLOW%^����    ı����"+p_zhimou;
        tm2="%^H_RED%^���� �� ������"+FIGHT_D->get_pure_def_pow(who)+"[+"+FIGHT_D->get_add_def_pow(who)+"]";
        printf("%s%s%s%s%s%s\n",bar,tm1,space[0..N1-colour_strlen(tm1)],
        tm2,space[0..N2-colour_strlen(tm2)],bar);
        
        tm1="%^H_YELLOW%^����    ������"+p_meili;
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);
	
	  p_hd=CHAR_D->get_char(p_id,"mar");
	  p_hd=CHAR_D->get_char(p_hd,"name");
	  if(!stringp(p_hd)) p_hd="%^H_MAGENTA%^��%^RESET%^";

/* jie yi xiongdi*/
        p_jyxd = CHAR_D->get_char(p_id,"jy");
        if(!sizeof(p_jyxd))
        p_jy= "��";
        else 
        {
		string *j_ids;
		j_ids=values(p_jyxd);
		foreach(string j_id in j_ids) {
			if(!CHAR_D->char_exist(j_id))
			j_ids-=({j_id});
		}
		if(!sizeof(j_ids)) {
			p_jy="��";
		}
		else
		{
			p_jy=CHAR_D->get_char(j_ids[0],"name");
			if(sizeof(j_ids)>1) {
				int js;
				for(js=1;js<sizeof(j_ids);++js) {
                                        p_jy+="��";
					p_jy+=CHAR_D->get_char(j_ids[js],"name");
				}
			}
		}
        }
        if(p_gender==1)        
	{
	tm1="%^H_MAGENTA%^�������ֵܡ���"+p_jy+"%^RESET%^";
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);
	tm1="%^H_MAGENTA%^���ᷢ���ӡ���"+p_hd;
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);
	}
	else
	{
	tm1="%^H_MAGENTA%^���������á���"+p_jy+"%^RESET%^";
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);
	tm1="%^H_MAGENTA%^���ᷢ�ɷ򡿣�"+p_hd;
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);
	}
//        printf("%%^H_CYAN%%^��%%^H_MAGENTA%%^�������ֵܡ�����         ���ᷢ���ӡ���%-10s %%^H_CYAN%%^��%%^RESET%%^\n",p_hd);
//        }
//        else
//        {
//        printf("%%^H_CYAN%%^��%%^H_MAGENTA%%^���������á�����         ���ᷢ�ɷ򡿣�%-10s %%^H_CYAN%%^��%%^RESET%%^\n",p_hd);
//        }

        tm1="%^H_BLUE%^���� �� ������"+(sizeof(COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name")) ? COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name"): "����%^RESET%^");
        tm2="%^H_BLUE%^���� �� �ء���"+(sizeof(AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name")) ? AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name") : "����%^RESET%^");
        printf("%s%s%s%s%s%s\n",bar,tm1,space[0..N1-colour_strlen(tm1)],
        tm2,space[0..N2-colour_strlen(tm2)],bar);

        tm1="%^H_GREEN%^�����ҹ�ְ����"+OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"ranknation"));
        tm2="%^H_GREEN%^���ط���ְ����"+(sizeof(AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name")) ? AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name") : "����")
        +OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"ranklocal"));
        printf("%s%s%s%s%s%s\n",bar,tm1,space[0..N1-colour_strlen(tm1)],
        tm2,space[0..N2-colour_strlen(tm2)],bar);

        tm1="%^H_GREEN%^����͢��ְ����"+(sizeof(OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"royalrank"))) ?OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"royalrank")) :"����"+"%^RESET%^");
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);

tm1="%^H_RED%^����    λ����%^RESET%^"+(sizeof(CHENGHU_D->query_char_jun(p_id)) ?CHENGHU_D->query_char_jun(p_id) :"����"+"");
          printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);
        tm1="%^H_YELLOW%^��ٺ    »����"+CHAR_D->get_char(p_id,"salary");
        tm2="%^H_YELLOW%^����    �ϡ���"+CHAR_D->get_char(p_id,"loyalty");
        printf("%s%s%s%s%s%s\n",bar,tm1,space[0..N1-colour_strlen(tm1)],
        tm2,space[0..N2-colour_strlen(tm2)],bar);
        
        tm1="%^H_WHITE%^����    ������"+(sizeof(CHAR_D->get_char(p_id,"reputationstr")) ? CHAR_D->get_char(p_id,"reputationstr") :"%^H_WHITE%^ĬĬ����%^RESET%^")+"%^H_WHITE%^("+
        CHAR_D->get_char(p_id,"reputation")+")";
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);

        tm1="%^H_WHITE%^����ѧ��������"+(sizeof(who->query_literate_str()) ? who->query_literate_str() : "%^H_RED%^Ŀ��ʶ��%^RESET%^")+"%^H_WHITE%^("+who->query_literate()+")";
        printf("%s%s%s%s\n",bar,tm1,space[0..1+N2+N1-colour_strlen(tm1)],bar);

        printf("%%^H_CYAN%%^��                                                  ��\n");
        printf("%%^H_YELLOW%%^��%%^H_CYAN%%^������������������%%^B_MAGENTA%%^����  ��  ־��%%^RESET%%^%%^H_CYAN%%^������������������%%^H_YELLOW%%^��%%^RESET%%^\n");
        return;
}
void do_score()
{
        object who;
        who=this_body();
		//printf("����this_body()\n"); DEBUG
        score_print(who);
}
void do_score_str(string liv)
{
        object ob;
        if(!(wizardp(this_body()->query_userid())))
        {
                printf("ֻ����ʦ�ſ���͸�ӱ��˵�״����\n");
                return;
        }
        else
        {
                ob = present(liv, environment(this_body()));
                if (!ob) ob = find_body(liv);
                if (!ob) {
                        write("��Ҫ�쿴˭��״����\n"); 
                        return;
                }
                if (!ob->is_living()) {
                        write("�쿴����ĳɼ���\n"); 
                        return;
                }
                score_print(ob);
        }
}
array query_verb_info()
{
    return ({ ({ "", "STR", }), ({  }) });
}
