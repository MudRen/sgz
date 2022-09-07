/* char_d.c by fire on 26/06/98
this is used to handle the direct control of chars
include npc and players
*/
#include <mudlib.h>
#include <security.h>
#include <ansi.h>
#include <char.h>
inherit M_ACCESS;
inherit __DIR__+"char_d/string";
inherit __DIR__+"char_d/task";
inherit __DIR__+"char_d/localcontribution";
inherit __DIR__+"char_d/appear";
inherit __DIR__+"char_d/level";
inherit __DIR__+"char_d/myarmy";
inherit __DIR__+"char_d/salary";
inherit __DIR__+"char_d/loyalty";
inherit __DIR__+"char_d/char_obj";
inherit __DIR__+"char_d/stat_me";
inherit __DIR__+"char_d/sgrate";
private mapping chars;
private mapping room_char;
private mapping chars_backup;
static private mapping area_char=([]);
static private mapping nation_char=([]);
static private *char_list=({});

#define SAVE_FILE "/data/daemons/char"
static private int m_modified;				//�޸ı�־

//void add_hook(string, function);
//static private function  my_hook;

string change_id(string o_id,string n_id);

void init_char_list() {
	char_list=keys(chars);
}
mixed get_area_char() {
	return area_char;
}
void init_area_char(string a_id) {
	string *ret;
    ret=filter_array(char_list, (: chars[$1]["area"]==$(a_id) :));
	area_char[a_id]=ret;
	return;
}

void remove_area_char(string p_id) {
	string p_area;
	p_area=chars[p_id]["area"];
	if(!stringp(p_area)) return;
	if(!arrayp(area_char[p_area])) init_area_char(p_area);
	area_char[p_area]-=({p_id});
}

void add_area_char(string p_id) {
	string p_area;
	p_area=chars[p_id]["area"];
	if(!stringp(p_area)) return;
	if(!arrayp(area_char[p_area])) init_area_char(p_area);
	area_char[p_area]-=({p_id});
	area_char[p_area]+=({p_id});
}

mixed get_nation_char() {
	return nation_char;
}

void init_nation_char(string a_id) {
	string *ret;
        ret=filter_array(char_list, (: chars[$1]["nation"]==$(a_id) :));
	nation_char[a_id]=ret;
	return;
}

void remove_nation_char(string p_id) {
	string p_nation;
	p_nation=chars[p_id]["nation"];
	if(!stringp(p_nation)) return;
	if(!arrayp(nation_char[p_nation])) init_nation_char(p_nation);
	nation_char[p_nation]-=({p_id});
}

void add_nation_char(string p_id) {
	string p_nation;
	p_nation=chars[p_id]["nation"];
	if(!stringp(p_nation)) return;
	if(!arrayp(nation_char[p_nation])) init_nation_char(p_nation);
	nation_char[p_nation]-=({p_id});
	nation_char[p_nation]+=({p_id});
}

void set_char_modified()
{  
	m_modified=1;
}

void save_data()
{
    if(m_modified)
    {
       unguarded(1, (: save_object, SAVE_FILE :));
       m_modified=0;
    }
}

void create()
{
    string *kk;
	//write("����char_d.c��create()\n");
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    if(!mapp(room_char)) room_char=([]);
    init_char_list();
    return;
}
// this is just suitable for add npc chars manuly
string add_char(string p_id)
{
    string p_surname,p_givenname;
    int p_namepart;
    int p_tmp;


    p_namepart=sscanf(p_id,"%s %s",p_surname,p_givenname);
    if(p_namepart!=2)
        return "������֮��Ҫ�пո�\n";
    if(!chars) chars=([]);
    if(!chars[p_id])
    {
        chars[p_id]=([]);
        chars[p_id]["type"]=TYPE_NPC;
        chars[p_id]["state"]=STATUS_NOTFINISHED; // could be on line
                                                                          
        chars[p_id]["gender"]=1; // default is male
        chars[p_id]["age"]=20+random(20); // default age for npcs
        chars[p_id]["gift"]=([]);
        chars[p_id]["skills"]=([]);
        chars[p_id]["gift"]["rongmao"]=10+random(20); // default beauty
        p_tmp=10+random(20);
        chars[p_id]["gift"]["wuli"]=p_tmp; // default beauty
        chars[p_id]["skills"]["sk_wuli"]=p_tmp*2+40-random(10);
        p_tmp=10+random(10);
        chars[p_id]["gift"]["zhimou"]=p_tmp; // default beauty
        chars[p_id]["skills"]["sk_zhimou"]=p_tmp*2+40-random(10);
        p_tmp=10+random(10);
        chars[p_id]["gift"]["meili"]=p_tmp; // default beauty
        chars[p_id]["skills"]["sk_meili"]=p_tmp*2+40-random(10);
                
        m_modified=1;
	char_list-=({p_id});
	char_list+=({p_id});
           return "�½�ɫ���ӳɹ���\n";
    }
    else
    {  return "�ý�ɫ�Ѿ����ڣ�\n";
    }
}

void remove_char_room(string p_id) {
	mixed od_room;
	od_room=chars[p_id]["room"];
	if(stringp(od_room)) {
		if(!arrayp(room_char[od_room]))
			room_char[od_room]=({});
		room_char[od_room]-=({p_id});
		if(!sizeof(room_char[od_room])) 
			map_delete(room_char,od_room);
	}

}
void add_char_room(string p_id,mixed para_value) {
	if(stringp(para_value)&&(para_value!="")) {
		chars[p_id]["room"]=para_value;
		if(!arrayp(room_char[para_value]))
			room_char[para_value]=({});
		room_char[para_value]-=({p_id});
		room_char[para_value]+=({p_id});
	}
	else {
		map_delete(chars[p_id],"room");
	}
}
void set_char_room(string p_id,mixed para_value) {
	remove_char_room(p_id);
	add_char_room(p_id,para_value);
	return ;
}


// just remove the id

string remove_char_d(string p_id) { 
   remove_area_char(p_id);
   remove_nation_char(p_id);
   remove_char_room(p_id);   

   if(mapp(chars[p_id])) {
	if(chars[p_id]["is_maker"]) error("some one want remove maker "+p_id);
	if(chars[p_id]["is_xianren"]) error("some one want remove xianren "+p_id);
	if(!chars[p_id]["is_tmp"]&&(chars[p_id]["type"]==TYPE_NPC)) error("some one want remove npc char "+p_id);

   }
   map_delete(chars,p_id);
   char_list-=({p_id});
   m_modified=1;
}
// this function should be just used in the early develop 
// time. later to use it may cause other conflict
string remove_char(string p_id) 
{
   if (!chars[p_id]) 
      return "�ý�ɫ�����ڣ�\n";
   CHAR_D->remove_npc_char(p_id);
   remove_char_d(p_id);
    return "��ɫɾ���ɹ���\n";
}
string change_id(string o_id,string n_id)
{
	mixed tmp;
	if(chars[n_id]) return "��ID�Ѿ��������ˡ�\n";
	if(!chars[o_id]) return "û�д�ID��\n";
	tmp=chars[o_id];
	CHAR_D->remove_char(o_id);
	CHAR_D->add_id(n_id);
	chars[n_id]=tmp;	
	m_modified=1;
	return "�ɹ�, need update\n";
}

string set_char(string p_id,string para_name,mixed para_value)
{
        string p_ret;
        if(!chars[p_id])
                return "�ý�ɫ�����ڣ�\n";
        if(intp(para_value))
        {   if(para_value<0)
                para_value=0;
        }
        switch (para_name)
        {
       case "gift":
         if (!chars[p_id]["gift"])
            chars[p_id]["gift"]=([]);
         chars[p_id][para_name]=para_value;  
	if(para_value==0)  // used to remove useless record
		map_delete(chars[p_id],para_name); //becare ful 
         p_ret="��ɫ�츳���óɹ���\n";  // related with level
         break;
       case "skills":
         if (!chars[p_id]["skills"])
              chars[p_id]["skills"]=([]);
         chars[p_id][para_name]=para_value; 
	if(para_value==0)  // used to remove useless record
		map_delete(chars[p_id],para_name); //becare ful 

         p_ret="��ɫ�������óɹ���\n";  // related with level
         break;
       case "id":
		   if(chars[p_id]["type"]==TYPE_PLAYER)
		   {
			   p_ret="��ҽ�ɫ���ܸ�ID\n";
			   break;
		   }
		   p_ret=change_id(p_id,para_value);
		   break;
       case "loyalty":
            CHAR_D->set_char_loyalty(p_id,"", para_value);
            return "��ɫ�ҳ����óɹ���\n";
        case "rongmao":
            if(!chars[p_id]["gift"])
               return "wrong\n";
            chars[p_id]["gift"][para_name]=para_value;  
            p_ret="��ɫ��ò���óɹ���\n";   // from 10 to 30
            break;                                          
        case "wuli":
        case "zhimou":
        case "meili":
            if(!chars[p_id]["gift"])
               return "wrong\n";
            chars[p_id]["gift"][para_name]=para_value;
            chars[p_id]["skills"]["sk_"+para_name]=para_value*2+40-
               random(3);
            p_ret="��ɫ�����츳�뼼�����óɹ���\n"; 
            break;
	case "room" :
		set_char_room(p_id,para_value);
		p_ret="ok";
		break;
	case "area" :
	        if (chars[p_id]["ranknation"]==1) //2001.4.13
	           if (chars[p_id]["type"]==TYPE_NPC)
	              if (AREA_D->get_area(chars[p_id]["area"],"nation")==p_id)//�׶�δ���з�ռ��
	                   return "NPC���������뿪�׶��ص�!\n";                    
		remove_area_char(p_id);
		chars[p_id][para_name]=para_value;
		add_area_char(p_id);
		break;
	case "nation" :
		remove_nation_char(p_id);
		chars[p_id][para_name]=para_value;
		add_nation_char(p_id);
		break;

        case "localcontribution":
            CHAR_D->setchar_localcontribution(p_id,para_value,"");
            p_ret="ok";
            break;
        case "newqb":
            CHAR_D->new_qb(p_id,para_value);
            p_ret="ok"; break;
        default:
            chars[p_id][para_name]=para_value;  
			if(para_value==0)  // used to remove useless record
				map_delete(chars[p_id],para_name); //becare ful 
            p_ret="��ɫ�������óɹ���\n";
            break;
        }
        m_modified=1;
        return p_ret;
}
mixed get_char_status(string p_id) {
	if(find_body(p_id)) return STATUS_ONLINE;
//	if(CHAR_D->find_npc_char(p_id)) return STATUS_ACTIVE;
	if(!mapp(chars[p_id])) return 0;
	if(stringp(chars[p_id]["room"])) return STATUS_ACTIVE;
	return STATUS_SLEEPING;
}
int get_char_level(string p_id) {
    int l_n,l_l;
    l_n=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranknation"));
    l_l=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranklocal"));
    return bmax(l_n,l_l);
}
string get_char_name(string p_id) {
   if((chars[p_id]["type"]==TYPE_NPC)&&(!chars[p_id]["is_tmp"]))
       return "%^H_CYAN%^"+chars[p_id]["name"]+"%^RESET%^";
   else
       return chars[p_id]["name"];
}
mixed get_char(string p_id,string para_name)
{
    if (!chars[p_id])   return 0;
    if((!para_name)||(para_name=="")) return chars[p_id];
    switch(para_name)
    { 
      case "level" : return get_char_level(p_id);
      case "task": return get_task(p_id);
      case "statustr": return query_status(get_char(p_id,"status"));
      case "loyalty": 
           return get_char_loyalty(p_id,"");
      case "r_name" : return chars[p_id]["name"];
      case "sgrate" :
            return get_sgrate(p_id);

      case "name" :
            return get_char_name(p_id);
      case "reputationstr": 
            return get_char_reputation(get_char(p_id,"reputation"));
      case "salarylocal":
            return get_char_salarylocal(p_id);
      case "salarynation":
            return get_char_salarynation( p_id);
      case "salary":
            return get_char_salary( p_id);
      case "localcontribution":
            return CHAR_D->getchar_localcontribution(p_id,"");
      case "nationcontribution":
            return get_nation_contribution( p_id);

      case "taskstr": return get_taskstr( p_id);
	  case "troop": return TROOP_D->get_char_troop(p_id);
	  case "status": return get_char_status(p_id);
      //added by suicide for return oneself's id when he haven't fealty others.  
      case "fealty" : 
            if (!chars[p_id]["fealty"])  return p_id;
            else return chars[p_id]["fealty"];
      //added end 2000.08.07  
      //added by suicide for char's character,and i give it a chinese id ����.  
      case "bazi" : 
            if (!chars[p_id]["bazi"])  
            {   chars[p_id]["bazi"] = random(100)+1 ; //now only 100 type of character
                m_modified=1;
            	return chars[p_id]["bazi"];
            }
            else return chars[p_id]["bazi"];
      //added end 2000.08.27  
      default : return chars[p_id][para_name];      
    }
}

//����key��para_valueʱ��valueֵ
//�����һ����������area��nation,��ô���������Ƿ���para_name����ֵ��para_value������char
string* check_char(string para_name,mixed para_value)
{
	string* ret;
	if(para_name=="room") {
		if(!arrayp(room_char[para_value]))
			return ({});
		return room_char[para_value];
	}
	if(para_name=="area") {
		if(!arrayp(area_char[para_value])) init_area_char(para_value);
		return area_char[para_value];
	}
	if(para_name=="nation") {
		if(!arrayp(nation_char[para_value])) init_nation_char(para_value);
		return nation_char[para_value];
	}

    ret=filter_array(char_list, (: chars[$1][$(para_name)]==$(para_value) :));
    return ret;
}

string* check_char_area(string para_name,mixed para_value,string p_area)
{       string* ret;
        string* list;

	if(!arrayp(area_char[p_area])) init_area_char(p_area);
	list=area_char[p_area];
        ret=filter_array(list, (:(chars[$1][$(para_name)]==$(para_value)) :));
        return ret;
}

string* check_char_nation(string para_name,mixed para_value,string p_nation)
{       string* ret;
        string* list;

	if(!arrayp(nation_char[p_nation])) init_nation_char(p_nation);
	list=nation_char[p_nation];
        ret=filter_array(list, (:(chars[$1][$(para_name)]==$(para_value)) :));
        return ret;
}

int char_exist(string p_id)
{       
	//write("chars֮ǰp_id��ֵ��: " + p_id + "\n");

	if(chars[p_id])
		return 1;
	return 0;
}
mixed list_chars()
{   
	return char_list;
}

int remove_bad_named_chars()
{   
	string* names = keys(chars);
	int i;
	for (i = sizeof(names) - 1; i >= 0; i--)
	    if (names[i][0] < 'a' || names[i][0] > 'z') {
	        set_char(names[i], "is_tmp", 1);
	        remove_char(names[i]);
	    }
	return 1;
}
void char_check()
{   string* list;
    string* a_list;
    int i;
// disable char_check, because it is too time consuming 
/*   list=check_char("type",TYPE_NPC); // first step just check npcs
    list=filter_array(list, (: (!chars[$1]["is_tmp"]) :)); // tmp need notcheck
    a_list=AREA_D->list_areas();
    for(i=0;i<sizeof(list);++i)
    {
        string p_id;
        p_id=list[i];
        if (!chars[p_id]["name"])
        {
           chars[p_id]["status"]=STATUS_NOTFINISHED;
           continue;
        }
        if ((!chars[p_id]["area"])||(!AREA_D->get_area(chars[p_id]["area"],"name")))
        {
            chars[p_id]["area"]=a_list[random(sizeof(a_list))];
            if(objectp(find_char(p_id)))
                  destruct(find_char(p_id));
            chars[p_id]["status"]=STATUS_SLEEPING;
        }
    }
    m_modified=1; */
}
void init_char() // this is just used for test
{
        string* list;
        int i;
        list=check_char("type",TYPE_NPC); // first step just check npcs
        for(i=0;i<sizeof(list);++i)
        {
          string p_id;
          p_id=list[i];
          if(chars[p_id]["ranknation"]!=R_KING)
          {
                  chars[p_id]["nation"]=0;
                  chars[p_id]["ranknation"]=0;
                  chars[p_id]["ranklocal"]=0;
          }
    }
    m_modified=1;
}
void new_player_char(string m_id)
{
        chars[m_id]=([]);
        chars[m_id]["type"]=TYPE_PLAYER;
	char_list-=({m_id});
	char_list+=({m_id});
        m_modified=1;
}
void new_player_back_char(string m_id,mapping data) {
	chars[m_id]=([]);
	chars[m_id]=data;
	chars[m_id]["type"]=TYPE_PLAYER;
	char_list-=({m_id});
	char_list+=({m_id});
	m_modified=1;
}

// this is the only way to remove a char from a room
// it is the call program's responsibility to check 
// if it is time to call this program
void remove_npc_char(string c_id)
{       
        object o_id;
	string p_room;
       if(!mapp(chars[c_id]))
           return;
        o_id=find_npc_char(c_id);
        if(objectp(o_id)) {
              o_id->remove();
        }
	set_char(c_id,"room",0);
        return; 
}
int get_skill(string p_id,string p_sk)
{   mixed skills;
    skills=get_char(p_id,"skills");
    if(!skills)
       return 0;
    if(!skills[p_sk])
    return 0;
    return skills[p_sk];
}
// set loyalty
/* no use now
int set_lo()
{  string *list;
   list=keys(chars);
   foreach(string p_id in list)
   {  mixed m;
      m=chars[p_id]["loyalty"];
       map_delete(chars[p_id],"loyalty");
       if(m) chars[p_id]["lo"]=m;
    }
    return 1;
}
*/
/* now this is handled by ev_npc_move called from npc body directly
void npc_move()
{
        string *list;
        string *ret;
        int i;
        string p_id;
        string *p_a;
        string p_curarea,p_desarea;
        object p_o;
        list=check_char("type",TYPE_NPC);
        ret=filter_array(list, 
                (: (!chars[$1]["nation"])||(chars[$1]["nation"]=="") :));
        ret=filter_array(ret, (: (!chars[$1]["is_tmp"]) :)); 
        if(!sizeof(ret))
                return;
        i=random(sizeof(ret));
        p_id=ret[i];
        p_curarea=chars[p_id]["area"];
        p_a=AREA_D->get_area(p_curarea,"neighbor");
        if(!sizeof(p_a))
                return;
        p_desarea=p_a[random(sizeof(p_a))];
        p_o=find_char(p_id);
        if(objectp(p_o))
        {
                p_o->simple_action("$N̾�˿��������������˴����ҷ�չ֮�ء�\n");
                p_o->simple_action("$N�Ҵ��뿪�ˡ�\n");
                destruct(p_o);
                chars[p_id]["status"]=STATUS_SLEEPING;
        }
        chars[p_id]["area"]=p_desarea;
        CHANNEL_D->deliver_tell("rumor","system",
                sprintf("%sͶ��%sȥ�ˡ�",chars[p_id]["name"],
                        AREA_D->get_area(p_desarea,"name")));
}
*/
void remove()
{
    save_data();   
}
mixed get_room_char(mixed val) {
	if(!val) return room_char;
	return room_char[val];
}
int clean_up() {
   return 0; // means never_again
}
mixed pick_char(int i) {
	i=bmin(i,sizeof(char_list));
	if(i<0) i=0;
	if(!i) return char_list[random(sizeof(char_list))];
	return char_list[i-1];
}

void backup_player_chars(){
	chars_backup = ([]);
	foreach(string p_id in CHAR_D->list_chars()){
		if(CHAR_D->get_char(p_id,"type")!=TYPE_NPC){
			chars_backup[p_id] = CHAR_D->get_char(p_id, "");
			CHAR_D->remove_char(p_id);
		}
	}
	set_char_modified();
	save_data();
}
mixed get_chars_backup(){
	return chars_backup;
}
