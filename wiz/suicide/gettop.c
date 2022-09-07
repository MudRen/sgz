//create by suicide@sgz in 2000/02/28 for top 50 
int cal_sgrate(string id)
{mixed c;
 int rate,ext_skil;
 c = CHAR_D->get_char(id,"");
 if(sizeof(c["skills"])) 
   {
foreach(string s,int r in c["skills"])
           ext_skil+=r;
   }
 rate = (c["skills"]["sk_wuli"]+c["skills"]["sk_meili"]+c["skills"]["sk_zhimou"])*20
         +ext_skil*10+c["reputation"]/100
         +c["literate"]*2+c["ju"]*1000
 +CHAR_D->get_char(id,"nationcontribution")/10;
 return rate;
}
	
string get_top(string prop)
{
string *ids;
mapping title =([
"reputation" :"����  ID          ����        ������    ����  �Ա�  ����      \n",
"literate"   :"����  ID          ����        ������    ����  �Ա�  ��ѧ����  \n",
"sgrate"     :"����  ID          ����        ������    ����  �Ա�  �����ȼ���\n",
"beauty"     :"����  ID          ����        ������    ����  �Ա�  ��ò\n",
"handsome"   :"����  ID          ����        ������    ����  �Ա�  ��ò\n",
"sk_wuli"    :"����  ID          ����        ������    ����  �Ա�  ����\n",
"sk_meili"   :"����  ID          ����        ������    ����  �Ա�  ����\n",
"sk_zhimou"  :"����  ID          ����        ������    ����  �Ա�  ����\n",
"age"        :"����  ID          ����        ������    ����  �Ա�  ����\n",
"newbie"     :"����  ID          ����        ������    ����  �Ա�  �����ȼ���\n",
"nationcontribution":"����  ID          ����        ������    ����  �Ա�  ���ҹ���\n"
]);
 string msg="";
 mixed c;
 int MAX=50;
 ids = CHAR_D->check_char("type",1);
 ids = filter_array(ids, (: !wizardp($1) :));
 ids = filter_array(ids, (: CHAR_D->get_char($1,"level") :));
 switch (prop)
 {
  case "sgrate"     :
case "newbie"    :
    {
if (prop=="newbie")
ids = filter_array(ids, (: (CHAR_D->get_char($1,"age")<18) :));
     ids= sort_array(ids, (: ((cal_sgrate($1) >
                               cal_sgrate($2) ) ? -1 : 1):));
     msg+=title[prop];
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-6d%-12s%-12s%-10s%-6d%-6s%-8d\n",
             i+1,ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "����" :"Ů��" ),
             cal_sgrate(ids[i]));
        }
      return msg;      
     }
 	
  case "reputation" :
  case "literate"   :
  case "age"        :
  case "nationcontribution" :
  {
     ids= sort_array(ids, (: (( CHAR_D->get_char($1,$(prop)) >
                      CHAR_D->get_char($2,$(prop)) ) ? -1 : 1):));
     msg+=title[prop];
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-6d%-12s%-12s%-10s%-6d%-6s%-8d\n",
             i+1,ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "����" :"Ů��" ),
             CHAR_D->get_char(ids[i],prop));
        }
      return msg;      
     }
  case "beauty"     :
  case "handsome"   :
  
    {
     if (prop=="beauty")
        ids = filter_array(ids, (: (CHAR_D->get_char($1,"gender")==2) :));
     if (prop=="handsome")
        ids = filter_array(ids, (: (CHAR_D->get_char($1,"gender")==1) :));
     ids= sort_array(ids, (: (( CHAR_D->get_char($1,"gift")["rongmao"] >
                      CHAR_D->get_char($2,"gift")["rongmao"] ) ? -1 : 1):));
     msg+=title[prop];
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-6d%-12s%-12s%-10s%-6d%-6s%-8d\n",
             i+1,ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "����" :"Ů��" ),
             c["gift"]["rongmao"]);
        }
      return msg;      
     }
       
   case "sk_wuli"  :
   case "sk_meili" :
   case "sk_zhimou":
   {
       
     ids= sort_array(ids, (: (( CHAR_D->get_char($1,"skills")[$(prop)] >
                      CHAR_D->get_char($2,"skills")[$(prop)] ) ? -1 : 1):));
     msg+=title[prop];
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-6d%-12s%-12s%-10s%-6d%-6s%-8d\n",
             i+1,ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "����" :"Ů��" ),
             c["skills"][prop]);
        }
      return msg;      
     }       
   default :
      return "�����͵����а���δ����\n";
 }
}
  
string log_news(string type)
{
 array p_date;
 int MAX=50;
 mapping rank=([
 "reputation" : "����",
 "literate"   : "����",
 "sgrate"     : "����",
 "beauty"     : "��Ů",
 "handsome"   : "˧��",
 "sk_wuli"    : "����",
 "sk_meili"   : "����",
 "sk_zhimou"  : "ıʿ",
 "age"        : "Ԫ��",
"newbie"     : "����",
 "nationcontribution" : "����"
 ]);
 if (member_array(type,keys(rank))==-1)
      return "�����͵����а���δ����\n";
 p_date = DAY_D->query_date();
NEWS_D->system_post("ranks",
            "����־"+chinese_number(p_date[3])+"��"
            +chinese_number(MAX)+"��"+rank[type], 
get_top(type),"��������");
 tell(users(),"%^YELLOW%^���������а�"+rank[type]+
 "���а�����ˣ�����пյ����������Ŀ����Լ��Ƿ��������Ŷ!\n%^RESET%^");
 return  rank[type]+"���а񴴽��ɹ�!\n";
}
void log_all(int i)
{
array type= ({"reputation",
            "literate",
            "beauty",
            "handsome",
            "age",
            "nationcontribution",
            "sk_wuli",
            "sk_meili",
            "sk_zhimou",
            "newbie",
            "sgrate"
           });
 log_news(type[i]);
 i++;
if (i<sizeof(type)) 
 call_out((:log_all:),10,i);
else
     SGSYS("�������а񴴽��ɹ�!\n");
}
void start()
{log_all(0);}
