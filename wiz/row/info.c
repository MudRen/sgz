// infor.c
// by fire on 7 July 1998
// this is used to 
// give detailed information for
// a cetain char, country, or area
#include <mudlib.h>
#include <daemons.h>
#define HEADER "������������������������������������������������������������������������\n"
inherit CMD;
inherit M_GLOB;
string bar="����������������������������������������������������������������������\n";

void infoac(string a_id)
{
        string *chars;
    string dis="";
        if((a_id=="here")&&(objectp(this_body()))) {
                a_id=this_body()->query_room()->get_area();
        }
        if(!AREA_D->area_exist(a_id)) {
                write("û������������� info a list ������嵥��\n");
                return;
        }
        chars=CHAR_D->check_char_area("is_tmp",0,a_id);
    if(sizeof(chars)) {
                write("    ��ɫ����  ��ɫ����  �ط���ְ  ���ҹ�ְ\n");
                foreach(string ch in chars) {
                        dis+=sprintf("%12s  %8s  %8s  %8s\n",
                                ch,CHAR_D->get_char(ch,"name"),
                                OFFICER_D->query_rank_name(CHAR_D->get_char(ch,"ranklocal")),
                                OFFICER_D->query_rank_name(CHAR_D->get_char(ch,"ranknation")));
                }
                more (dis);
                return;
        }
        write("�õ���û�н�ɫ��\n");
}

void infoa(string a_id,string para)
{
   string p_id=this_body()->query_id()[0];
   int priorit=2;
   string mess;
   if(a_id=="list")
   {
       mixed keys,dis;
       keys=sort_array(AREA_D->list_areas(),1);
       dis=map_array(keys, (: AREA_D->get_area(($1),"name")+"("+($1)+")" :));
       outf("����־�����б�\n");
       if(end_of_pipeline())
          out(HEADER + sprintf("%-#79s\n", implode(dis, "\n")));
       else
          outf("%s\n", implode(dis, "\n"));
       outf("%s����������%d����\n",HEADER,sizeof(dis));
       return;       
   }
	if(!a_id)
{
	mess=AREA_D->stat_me(a_id,"",2); 
	more(mess);	
}
	if(a_id=="here")
{
	object env=environment(this_body());
	mixed tmp;
	string arg;
	while( env && !inherits(BASE_ROOM, env) ) 
	env = environment( env );
	arg = env->get_area();
	tmp=AREA_D->check_area("area",arg);
	if(sizeof(tmp)==0)
	{
	write("�˵ز���������������\n");
	return;
	};
	arg=tmp[0];
	a_id=arg;
}
   if(AREA_D->get_area(a_id,"nation")==CHAR_D->get_char(p_id,"nation"))
      priorit=1;
   if(AREA_D->get_area(a_id,"leader")==p_id)
      priorit=0;
   if((CHAR_D->get_char(p_id,"area")==a_id)&&(priorit==1)&&(CHAR_D->get_char(p_id,"level")>1))
           priorit=0;
   if(AREA_D->get_area(a_id,"nation")==this_body()->query_primary_id())
        priorit=0;
   if(wizardp(this_body()))
      priorit=0;
   mess=AREA_D->stat_me(a_id,para,priorit); 
   more(mess);
}
void infon(string n_id)
{
   string p_id=this_body()->query_id()[0];
   int priorit=2;
   string mess;
   if(n_id=="list")
   {
       mixed keys,dis;
       keys=sort_array(COUNTRY_D->list_countries(),1);
       dis=map_array(keys, (: COUNTRY_D->get_country(($1),"name")+"("+($1)
+")" :));
       outf("����־�����б�\n");
       if(end_of_pipeline())
          out(HEADER + sprintf("%-#79s\n", implode(dis, "\n")));
       else
          outf("%s\n", implode(dis, "\n"));
       outf("%s����������%d����\n",HEADER,sizeof(dis));
      return;
   }
   if(n_id==CHAR_D->get_char(p_id,"nation"))
      priorit=1;
   if(n_id==p_id)
      priorit=0;
   if(wizardp(this_body()))
      priorit=0;
   mess=COUNTRY_D->stat_me(n_id,priorit); 
   more(mess);
}
void infoc(string c_id)
{
   string p_id=this_body()->query_id()[0];
   string p_nation,mess;
   int priorit=2;
   if(c_id=="list")
   {
       mixed keys,dis;
       keys=sort_array(CHAR_D->check_char("is_tmp",0),1);
       dis=map_array(keys, (: CHAR_D->get_char(($1),"name")+"("+($1)+")" :));
       outf("����־��ɫ�б�\n");
       if(end_of_pipeline())
          out(HEADER + sprintf("%-#79s\n", implode(dis, "\n")));
       else
          outf("%s\n", implode(dis, "\n"));
       outf("%s��ɫ������%d����\n",HEADER,sizeof(dis));
       return;       
   }
   if(c_id==p_id) priorit=0;
   else
   {
      p_nation=CHAR_D->get_char(p_id,"nation");
      if((sizeof(p_nation))&&
         (CHAR_D->get_char(c_id,"nation")==p_nation))
      priorit=1;
   }
   if(wizardp(this_body())) priorit=0;
   mess=CHAR_D->stat_me(c_id,priorit); 
   more(mess);
}
void infob(string par){
   write(BASE_D->stat_me(par));
   return;
}
void infop(string str){
        int num, nn;
        string out, *zhou, *city;

        num = 0;
        out = mud_name()+"�ݿ��б�\n"+bar;
        zhou = ({"����","����","����","����","ԥ��","����","����",
                "˾��","Ӻ��","����","����","����","������","�Ͼ���",
                "۫��","����","����", });
        
        if( str&&stringp(str)&&member_array(str,zhou)!=-1 ) zhou = ({ str });
        foreach(string ss in zhou){
                nn++;
                city = AREA_D->check_area("zhou", ss);
                out = out +sprintf("(%-2d)",nn)+ss+"("+
			AREA_D->get_area(AREA_D->get_zhou_head(ss),"name")
			+")������"+chinese_number(sizeof(city))
	+"����\n";
                num+=sizeof(city);
                foreach(string ss2 in city)
                                out = out + sprintf("%-8s",AREA_D->get_area(ss2,"name"));
                out = out + "\n";
        }
        out = out +bar;
        out = out +"������"+chinese_number(sizeof(zhou))+"��"+chinese_number(num)
	+"����\n";
        more(out);
}

void infoo(string c_id)
{
   string par,tag;
   int pnum,par2=0;
   string ret;
   pnum=sscanf(c_id,"%s %s",par,tag);
   if(pnum==2)  {
	if(par=="a") par="area";
	if(par=="n") par="nation";
	par2=to_int(tag);
   }
   else {
	par=c_id;
	switch(c_id) {
		case "a":
			par="area";
			break;
		case "n":			
			par="nation";
			break;
	}
	par2=-1;
   }
   ret=OFFICER_D->stat_me(par,par2);

   more(ret);
}

void infot(string c_id)
{
   string ret;
   ret=TROOP_TYPE_D->stat_me(c_id);

   more(ret);
}
void infor(string c_id)
{
   string ret;
   ret="/daemons/restart_d"->stat_me(c_id);

   more(ret);
}
void infoh(string c_id)
{
   string ret;
   ret="/daemons/house_d"->stat_me(c_id);

   more(ret);
}

void infoj()
{
   string ret;
   ret="/daemons/chenghu_d"->stat_me_ju();

   more(ret);
}
void infos(string s_id) {
	string ret;
	if(s_id=="list") ret=BASE_D->show_stuff_list();
	else ret=BASE_D->show_stuff(s_id);
	more(ret);
}
private void main(string arg)
{
    string p_type,p_name;
    if(!arg)
       arg="";
    switch (arg)
    {
      case "me":
        infoc(this_body()->query_id()[0]);
        return;
      case "jimou" :
	load_object("/daemons/cast_d.c")->stat_me();
	return;
      case "here":
        {
           object env=environment(this_body());
           mixed tmp;
            while( env && !inherits(BASE_ROOM, env) ) 
                            env = environment( env );
            arg = env->get_area();
            tmp=AREA_D->check_area("area",arg);
            if(sizeof(tmp)==0){
                write("�˵ز���������������\n");
                   return;
            };
            arg=tmp[0];
            infoa(arg,"");
            return;
        }
    }
    if(sscanf(arg, "%s %s", p_type,p_name)!=2)
    {
        p_type=arg;p_name="list";
    }
 
    switch(p_type)
    {   case "a":
          infoa(p_name,"");
          return;
        case "c":
          infoc(p_name);
          return;
        case "n":
          infon(p_name);
          return;
	case "o": infoo(p_name); return; // officer
        case "ac":
                infoac(p_name);
                return;
	case "aa":
		infoa(p_name,"a");
		return;
	case "ag":
		infoa(p_name,"g");
		return;
	case "am":
		infoa(p_name,"m");
		return;
	case "af":
		infoa(p_name,"f");
		return;
	case "ao":
		infoa(p_name,"o");
		return;
        case "b":
                infob(p_name);
                return;
        case "p":
                infop(p_name);
                return;
        case "t":
                infot(p_name);
                return;
	case "r" :
		infor(p_name);
		return;
	case "h" :
		infoh(p_name);
		return;
	case "j" :
		infoj();
		return;
	case "s":
		infos(p_name);
		return;
	default:
                write("�÷����ԣ��� help info ��������\n");
            return;

    }
}
