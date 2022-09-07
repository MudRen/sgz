#include <mudlib.h>
#include <daemons.h>

string get_top10(string prop)
{string *ids;
 string msg="";
 mixed c;
 int MAX=10;
 ids = CHAR_D->check_char("type",1);
 ids = filter_array(ids, (: !wizardp($1) :));
 switch (prop)
 {
  case "reputation" :
    {
     ids= sort_array(ids, (: (( CHAR_D->get_char($1,"reputation") >
                      CHAR_D->get_char($2,"reputation") ) ? -1 : 1):));
     msg+="ID          ����        ������    ����  �Ա�  ����    \n";
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-12s%-12s%-10s%-6d%-6s%-8d\n",
             ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "����" :"Ů��" ),
             c["reputation"]);
        }
      return msg;      
     }
  case "literate" :                            
    {
     ids= sort_array(ids, (: (( CHAR_D->get_char($1,"literate") >
                      CHAR_D->get_char($2,"literate") ) ? -1 : 1):));
     msg+="ID          ����        ������    ����  �Ա�  ��ѧ����    \n";
     for (int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-12s%-12s%-10s%-6d%-6s%-8d\n",
             ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "����" :"Ů��" ),
             c["literate"]);
        }
      return msg;      
    }   
  case "sgrate" :
    {
     ids= sort_array(ids, (: (( CHAR_D->get_sgrate($1) >
                      CHAR_D->get_sgrate($2) ) ? -1 : 1):));
     tell_user("group","process 1");
	msg+="ID          ����        ������    ����  �Ա�  �����ȼ���  \n";
     for (int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-12s%-12s%-10s%-6d%-6s%-8d\n",
             ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "����" :"Ů��" ),
 CHAR_D->get_char(ids[i],"sgrate"));
        }
      return msg;      
    }  
      
                 
   default :
      return "�����͵����а���δ����\n";
 }
}
  
void log_news(string type)
{
 array p_date;
 int MAX=10;
 p_date = DAY_D->query_date();
 switch (type)
 {
  case "reputation" :
    NEWS_D->system_post("ranks",
            "����־"+chinese_number(p_date[3])+"��"+chinese_number(MAX)+"������", 
             get_top10("reputation"),"suicide");
    break;
  case  "literate"  :
    NEWS_D->system_post("ranks",
            "����־"+chinese_number(p_date[3])+"��"+chinese_number(MAX)+"�����", 
             get_top10("literate"),"suicide");
    break;
  case  "sgrate"  :
    NEWS_D->system_post("ranks",
            "����־"+chinese_number(p_date[3])+"��"+chinese_number(MAX)+"������", 
             get_top10("sgrate"),"suicide");
    break;
  default :
    break;
 }
}
