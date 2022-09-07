// stat_me.c by fire on Dec 1998
// 
#include <char.h>
#include <ansi.h>
inherit VERB_OB;
inherit M_OUT;
inherit CHINESE_DA;
inherit M_ANSI;
string space="                                        ";
void skill_check(string p_id) {
	mapping gift;
	if(CHAR_D->get_char(p_id,"is_tmp")) return;
	if(CHAR_D->get_char(p_id,"type")==TYPE_PLAYER) return;
	gift=CHAR_D->get_char(p_id,"gift");
	if(!mapp(gift)) {
		SGSYS(p_id+"don't have gift !!!!!!");
	}
	if(CHAR_D->get_skill(p_id,"sk_zhimou")<31)
		CHAR_D->set_char(p_id,"zhimou",gift["zhimou"]);
	if(CHAR_D->get_skill(p_id,"sk_meili")<31)
		CHAR_D->set_char(p_id,"meili",gift["meili"]);
	if(CHAR_D->get_skill(p_id,"sk_wuli")<31)
		CHAR_D->set_char(p_id,"wuli",gift["wuli"]);

}
string stat_me(string p_id,int priority)
{
	string p_ret="";
    string tm1,tm2;
	mixed c;
	//write("���е�char_exist()����ǰ����\n"); DEBUG
	if(!char_exist(p_id))
		return "û�������ɫ��\n";
	c=get_char(p_id,"");
	if(!c["gift"]) c["gift"]=([]);
		skill_check(p_id);
   
	p_ret+=
      "%^MAGENTA%^����������%^H_GREEN%^��%^RESET%^%^MAGENTA%^����������%^H_GREEN%^"+
      "��%^RESET%^%^MAGENTA%^����������%^H_GREEN%^��%^RESET%^%^MAGENTA%^����������"+
      "%^H_GREEN%^Ѷ%^RESET%^%^MAGENTA%^����������%^RESET%^\n\n";
    p_ret+="%^H_GREEN%^��һ����Ѷ��%^RESET%^\n";
    p_ret+=sprintf("%%^H_YELLOW%%^����ɫ���š�%-8s����    ����%-8s%%^RESET%%^%%^H_RED%%^��   ��   ��%4s%%^RESET%%^  \n"
            ,p_id, c["name"],(sizeof(c["zi"]) ? c["zi"] : "����" ));
	p_ret+=sprintf("%%^H_YELLOW%%^����    ��%-8s����    �䡿%-8d����    ò��%d%%^RESET%%^\n",
       (c["gender"]==1 ? "��" :"Ů"),c["age"],c["gift"]["rongmao"]);
        tm1="%^H_CYAN%^�� ������ ��"+(sizeof(c["nation"]) ? COUNTRY_D->get_country(c["nation"],
           "name") : "����")+"("+
        (sizeof(c["nation"]) ? CHAR_D->get_char(p_id,"nation") : "����")+")%^RESET%^";
        tm2="%^H_CYAN%^����    �ϡ�"+CHAR_D->get_char(p_id,"loyalty")+"%^RESET%^";
        p_ret+=sprintf("%s%s%s\n",tm1,space[0..39-colour_strlen(tm1)],tm2);

    tm1=sprintf("%%^H_CYAN%%^�� ���ڵ� ��%s(%s)%%^RESET%%^",
   (sizeof(c["area"]) ? AREA_D->get_area(c["area"],"name") : "����"),
   (sizeof(c["area"]) ? CHAR_D->get_char(p_id,"area") : "����"));
   tm2="%^H_CYAN%^���� �� �ȡ�"+CHAR_D->get_char(p_id,"tsx")+"%^RESET%^";
     p_ret+=sprintf("%s%s%s\n",tm1,space[0..39-colour_strlen(tm1)],tm2);
   p_ret+=sprintf("%%^H_CYAN%%^�����ҹ�ְ��%-8s���ط���ְ��%-8s����͢��ְ��%s%%^RESET%%^\n",
     OFFICER_D->query_rank_name(c["ranknation"]),
     OFFICER_D->query_rank_name(c["ranklocal"]),
	OFFICER_D->query_rank_name(c["royalrank"]));
	p_ret+=sprintf("%%^H_YELLOW%%^��ٺ    »��%d%%^RESET%%^\n",get_char(p_id,"salary"));

   if(priority<2)
   {  if(!c["skills"]) c["skills"]=([]);
      p_ret+=sprintf("%%^H_RED%%^����    ����%-8d����    ı��%-8d����    ����%d%%^RESET%%^\n",
       c["skills"]["sk_wuli"],c["skills"]["sk_zhimou"],
       c["skills"]["sk_meili"]);
      p_ret+=sprintf("%%^H_RED%%^���������ס�%-8d�����ҹ��ס�%-8d\n",
        get_char(p_id,"localcontribution"),get_char(p_id,"nationcontribution"));
      p_ret+=sprintf("%%^H_GREEN%%^����    ����%%^RESET%%^%s%%^H_WHITE%%^(%d)%%^RESET%%^\n",get_char(p_id,"reputationstr"),c["reputation"]);


      p_ret+=sprintf("%%^H_WHITE%%^����    �͡�%-8s��״    ̬��%-8s����    ��%-8s%%^RESET%%^\n",
        (c["type"]==TYPE_NPC ? "NPC " :"���"),
        get_char(p_id,"statustr"),get_char(p_id,"taskstr"));
   }
   if(priority<1)
   {  string *list,*a_tmp;
      string s_tmp;
      p_ret+="%^H_BLUE%^����������ϵ��%^RESET%^\n";
      list=COUNTRY_D->list_countries();
      s_tmp=c["nation"];
      list-=({s_tmp});
      a_tmp=({});
      foreach(string n_id in list)
      {  s_tmp=sprintf("��%8s����%3d ",
            COUNTRY_D->get_country(n_id,"name"),
            CHAR_D->get_char_loyalty(p_id,n_id));
         a_tmp+=({s_tmp});
      }
      p_ret+=sprintf("%-#60s\n",implode(a_tmp,"\n"));
      if(!c["myarmy"]) c["myarmy"]=([]);
      p_ret+="%^H_CYAN%^��˽����װ��%^RESET%^\n";
      p_ret+=sprintf("%%^H_YELLOW%%^���ױ�������%-28d��ѵ    ����%d%%^RESET%%^\n",
        c["myarmy"]["qbnum"],c["myarmy"]["train"]);
        p_ret+=sprintf("%%^H_YELLOW%%^����    ƥ��%-8d����    ����%-8d����    ʳ��%-8d%%^RESET%%^\n",
        c["myarmy"]["horse"],c["myarmy"]["bow"],c["myarmy"]["food"]);
	if(sizeof(c["wear"])){
      p_ret+=sprintf("%%^H_MAGENTA%%^����    ���%%^RESET%%^%s\n",
	(sizeof(c["wear"]["horse"]) ? OBJ_D->get_obj(c["wear"]["horse"],"name"): "��"));}
	if(!sizeof(c["wear"])){
	p_ret+=sprintf("%%^H_MAGENTA%%^����    ���%%^RESET%%^��\n"
);}
      p_ret+="%^H_CYAN%^�����ﰤ����"+chinese_number(c["myarmy"]["h_nf"])+"���¡�%^RESET%^\n";

   }
     p_ret+="\n%^B_RED%^%^H_YELLOW%^�������ȼ����%^RESET%^%^H_YELLOW%^��%^H_MAGENTA%^"+get_char(p_id,"sgrate")+"%^RESET%^\n";
   p_ret+="\n%^MAGENTA%^������������������������������������������������%^B_WHITE%^%^BLACK%^����־%^RESET%^%^MAGENTA%^����%^RESET%^\n";
   return p_ret;
}
