// stat_me.c by fire on Dec 1998
// 
#include <char.h>
string stat_me(string p_id,int priority)
{
   string p_ret="";
   mixed c;
   if(!char_exist(p_id))
       return "û�������ɫ��\n";
   c=get_char(p_id,"");
   if(!c["gift"]) c["gift"]=([]);
   p_ret+=sprintf("��ɫ���ţ�%-14s������%s\n",p_id, c["name"]);
   p_ret+="������������������������������������������������\n";
   p_ret+=sprintf("�֣�%4s  �Ա�%2s  ���䣺%3d ��ò��%d\n",
       (sizeof(c["zi"]) ? c["zi"] : "����" ),
       (c["gender"]==1 ? "��" :"Ů"),c["age"],c["gift"]["rongmao"]);
   p_ret+=sprintf("��������%-10s  ���ڵأ�%-8s\n",
     (sizeof(c["nation"]) ? COUNTRY_D->get_country(c["nation"],"name") : "����"),
     (sizeof(c["area"]) ? AREA_D->get_area(c["area"],"name") : "����" ));
   p_ret+=sprintf("��͢��ְ��%-8s  �ط���ְ��%-8s\n",
     OFFICER_D->query_rank_name(c["ranknation"]),
     OFFICER_D->query_rank_name(c["ranklocal"]));
   if(priority<2)
   {  if(!c["skills"]) c["skills"]=([]);
      p_ret+=sprintf("������%d  ��ı��%d  ������%d  ٺ»��%d\n",
       c["skills"]["sk_wuli"],c["skills"]["sk_zhimou"],
       c["skills"]["sk_meili"],get_char(p_id,"salary"));
      p_ret+=sprintf("������%s(%d) �������ף�%d  ���ҹ��ף�%d �ҳϣ�%d\n",
        get_char(p_id,"reputationstr"),c["reputation"],
        get_char(p_id,"localcontribution"),get_char(p_id,"nationcontribution"),get_char(p_id,"loyalty"));
      p_ret+=sprintf("���ͣ�%s  ״̬��%s  ����%s\n",
        (c["type"]==TYPE_NPC ? "NPC " :"���"),
        get_char(p_id,"statustr"),get_char(p_id,"taskstr"));
   }
   if(priority<1)
   {  string *list,*a_tmp;
      string s_tmp;
      p_ret+="��������ϵ��\n";
      list=COUNTRY_D->list_countries();
      s_tmp=c["nation"];
      list-=({s_tmp});
      a_tmp=({});
      foreach(string n_id in list)
      {  s_tmp=sprintf("%6s��%3d ",
            COUNTRY_D->get_country(n_id,"name"),
            CHAR_D->get_char_loyalty(p_id,n_id));
         a_tmp+=({s_tmp});
      }
      p_ret+=sprintf("%-#50s\n",implode(a_tmp,"\n"));
      if(!c["myarmy"]) c["myarmy"]=([]);
      p_ret+=sprintf("�ױ�����%d  ѵ����%d  ��ƥ��%d  ������%d  ��ʳ��%d\n",
        c["myarmy"]["qbnum"],c["myarmy"]["train"],
        c["myarmy"]["horse"],c["myarmy"]["bow"],c["myarmy"]["food"]);
   }
   return p_ret;
}
