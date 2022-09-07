//#include <sanguo.h>
//#include <global.h>
#include <security.h>
inherit M_ACCESS;
#define LOG_FILE "/daemons/nation_channel_d/tran.log"
mixed get_suggest(string n_id,string what);
mixed set_suggest(string n_id, string what, mixed val);
void discuss_suggest(string n_id);
void announce_suggest(string n_id);
void add_suggest(string n_id,string topic,mixed para,string who,string *areas);
void deliever_tell(string p_id,string n_id,string msg);

int log_me(string msg) {
	unguarded(1, (: write_file, LOG_FILE, msg :));
	return 1;
}

mixed do_check_can_tran(string who)
{
//	object ply; // put all check under the do_check_chan_para

//	ply = find_body("who");
//	if( objectp(ply)&&ply->query_sk_level("sk_wuli")<=50 )
//		return "����ѧ����̫�ͣ����ܶ��������־�������ָ�ֻ��ţ�\n";
//	else return 1;
	return 1;
}
mixed legal_stuff(string p_stuf) {
        string *lst;
        if(p_stuf=="gold") return "gold"; // gold
        lst=TROOP_TYPE_D->get_troop_type("list");
        if(member_array(p_stuf,lst)!=-1) return "troop"; // troop
        lst=(EV_MERCHANT)->query_goods("list");
        if(member_array(p_stuf,lst)!=-1) return "stuff"; // stuff
        return 0; // illegal
}
string stuff_name(string p_stuf,string typ) {
        switch(typ) {
                case "gold": return "�ƽ�";
                case "troop" : return TROOP_TYPE_D->get_troop_type(p_stuf,"name");
                case "stuff" : return (EV_MERCHANT)->query_goods(p_stuf,"name");
                default : return "δ֪����";
        }
}
int have_enough_stuf(string b_area,string p_stuf,string typ,int val) {
        mapping tmp;
        switch(typ) {
                case "gold":
                        if(AREA_D->get_area(b_area,"gold")>=val)
                                return 1;
                        return 0;
                case "troop" :
                        tmp=AREA_D->get_area(b_area,"troop");
                        if(!mapp(tmp)) tmp=([]);
                        if(tmp[p_stuf]>=val) return 1;
                        return 0;
                default :
                        if(AREA_D->get_area(b_area,p_stuf)>=val)
                                return 1;
                        return 0;

        }
}
mixed do_check_tran_para(string *para, string who)
{
	string n_id,from, to,p_stuff,name,typ,f_leader;
	int val;
        
        n_id = CHAR_D->get_char(who,"nation");
	if (CHAR_D->get_char(n_id,"type")==TYPE_NPC)
	   return "NPC���ҵı���������Ҳ����������!\n";
	if(sizeof(para)!=5&&sizeof(para)!=6) return "����ĸ�ʽ��\n";
	from = para[1];
	if(!AREA_D->area_exist(from)) return "û��"+from+"���������\n";
        if(AREA_D->get_area(from,"nation")!=n_id)
                return AREA_D->get_area(from,"name")+"�����ڱ�����\n";
	to   = para[2];

	if(!CHAR_D->get_char(who,"ranknation")) {
		if((AREA_D->get_area(from,"leader")!=who)&&(AREA_D->get_area(to,"leader")!=who))
			return "ֻ�й��ҹ�Ա����ص�����̫�زſ���������佨�顣\n";
	}
	
	//Added by suicide for can't tran stuff or soldier from area which �������˷�ͬ��ϵ
	if (CHAR_D->get_char(n_id,"type")==TYPE_NPC)
	{
	f_leader = AREA_D->get_area(from,"leader");
	if ((f_leader!=who)&&
	    (CHAR_D->get_char(f_leader,"fealty")!=who)&&
	    (CHAR_D->get_char(f_leader,"fealty")!=CHAR_D->get_char(who,"fealty")))
	   return "����������ֵ�����̫�غ��㲻��һ����ϵ�����²����Ӧ��\n";
	}
	//Added end 2000.08.07
	
	
	if(!AREA_D->area_exist(to)) return "û��"+to+"���������\n";
        if(AREA_D->get_area(to,"nation")!=n_id)
                return AREA_D->get_area(to,"name")+"�����ڱ�����\n";
	if(AREA_D->get_distance(from,to)!=1)
                return AREA_D->get_area(from,"name")+"��"+
                        AREA_D->get_area(to,"name")+"�������ڵ�����\n";
	if(sizeof(para)==6){
		p_stuff=para[3]+" "+para[4] ; 
		val=to_int(para[5]);
        } else {
                p_stuff=para[3]; 
		val=to_int(para[4]);	
	}
        typ=legal_stuff(p_stuff);
	if( !stringp(typ) ) return "û��"+p_stuff+"���ֻ������֡�\n";
        if( val<=0 ) 	return "����������������㡣\n";
        if( val>1000000 ) return "һ��������������һ����\n";
    	name=stuff_name(p_stuff,typ);
        if( !have_enough_stuf(from,p_stuff,typ,val) ) 
		return AREA_D->get_area(from,"name")+"û����ô��"+name+"��\n";

        add_suggest(n_id,"tran",({from,to,p_stuff,val,typ,name}), who,({from,to}));
        set_suggest(n_id,"str","��"+AREA_D->get_area(from,"name")+
		"��"+name+"��"+chinese_number(val)+"��"+AREA_D->get_area(to,"name"));
        set_suggest(n_id,"reason","Ϊƽ�ⷢչ");

        announce_suggest(n_id);
        call_out("discuss_suggest",2,n_id);
	return 1;
}
void do_tran(string n_id)
{
	mapping para;
        string b_area,t_area,p_id, p_stuff,typ,name;
        int val,finalval;
        int anding,rea;
        string dis;
        string p_tmp;

        p_id	= get_suggest(n_id,"who");
        para	= get_suggest(n_id,"para");
        b_area	= para[0];t_area=para[1];p_stuff=para[2];val=para[3];
        typ	= para[4]; 
	name	= para[5];

        if( !have_enough_stuf(b_area,p_stuff,typ,val) ){
		deliever_tell(p_id,n_id,"��֪ʲôԭ��"+AREA_D->get_area(b_area,"name")
			+"��û����ô��"+name+"������ȡ����\n");
                return;
        }
        anding=AREA_D->get_area(b_area,"safe")+AREA_D->get_area(t_area,"safe");
	switch (typ) {
                case "gold" :
                case "stuff" :
                        AREA_D->set_area(b_area,p_stuff,
                                AREA_D->get_area(b_area,p_stuff)-val);
                        rea=anding;
          
                        break;
                default :
                        AREA_D->set_area_soldier(b_area,p_stuff,
                                AREA_D->get_area_soldier(b_area,p_stuff)-val);
                        rea=AREA_D->get_area(b_area,"train")+AREA_D->get_area(b_area,"morale");
        		
                        break;
        }
        finalval=val;
        if((rea<100)) //big penalty
        {
        	finalval=finalval/10+finalval*(rea+random(rea))/500;
        	dis="�ǳ����ң�ֻ��"+name+chinese_number(finalval)+name+
                	"��ȫ����"+AREA_D->get_area(t_area,"name")+"��";
        }
        else if(((random(rea)<160)&&(rea<320))) 
        {
            	finalval*=(rea*13+random(rea)*2)/320+85;
            	finalval/=100;
                dis="��������ԭ��";
                dis+="ֻ��"+chinese_number(finalval)+name+
                	"��ȫ����"+AREA_D->get_area(t_area,"name")+"��";
        }else if (anding <140 && random(anding)<100)
        {
        	finalval*=(random(anding/6)+anding/3+930);
        	finalval/=1000;
            	dis="��������ԭ��";
                dis+="ֻ��"+chinese_number(finalval)+name+
                	"��ȫ����"+AREA_D->get_area(t_area,"name")+"��";
        } 
        else
        	dis = "�ǳ����ˣ�����"+chinese_number(finalval)+name+
        		"ȫ����ȫ����"+AREA_D->get_area(t_area,"name")+"��";
        switch ( typ ) {
                case "gold" :
                case "stuff" :
                        AREA_D->set_area(t_area,p_stuff,
                                AREA_D->get_area(t_area,p_stuff)+finalval);
                        break;
                default :
                        AREA_D->add_soldier(t_area,p_stuff,finalval,
                                AREA_D->get_area(b_area,"morale")-10,
                                AREA_D->get_area(b_area,"train"));

                        break;
        }
	p_tmp=sprintf("\ntran %s from %s to %s, rea=%d, anding=%d,value from %d to %d",typ
		,AREA_D->get_area(b_area,"name"),AREA_D->get_area(t_area,"name")
		,rea,anding,val,finalval);
	log_me(p_tmp);
        deliever_tell(p_id,n_id,dis);
}
