/* buildcity_d.c by suicide on 21/02/02
** This is used to handle city building. 
*/
#include <security.h>
#include <ansi.h>

#define SAVE_FILE "/data/daemons/buildcity"
#define AREA_SERVER load_object("/a/area_server")

inherit M_ACCESS;
private mapping build_info=([]);

static mixed opdirs=(["east":"west", "south":"north", "north":"south",
"west":"east","southeast":"northwest","southwest":"northeast","up":"down",
"enter":"out","northeast":"southwest","northwest":"southeast","down":"up",
"out":"enter",]);

void save_data()
{  
   	unguarded(1, (: save_object, SAVE_FILE :));
}

mixed set_city_build_info(string p_id,string para,mixed data)
{
if (!undefinedp(build_info[p_id])) 
   {if (para=="baseinfo") return "�ó��Ѿ��ڽ����У��޷��������ã�\n";}
else
    build_info[p_id]=([]);
build_info[p_id][para]=data;
save_data();
return 0;
}

mixed get_city_build_info(string p_id,string para)
{
if (undefinedp(build_info[p_id])) return 0;
switch(para)
{
case "creator" : return build_info[p_id]["baseinfo"][0];
case "name" : return build_info[p_id]["baseinfo"][1];
case "zhou" : return build_info[p_id]["baseinfo"][2];
case "short": return build_info[p_id]["baseinfo"][3];
case "level": return build_info[p_id]["baseinfo"][4];
default : return build_info[p_id][para];
}
}

void remove_city_build_info(string p_id)
{
if (undefinedp(build_info[p_id])) return ;
map_delete(build_info,p_id);
save_data();
}


int is_room_exist(string p_id,string r_id)
{
AREA_SERVER->set_area(p_id);
if (member_array(r_id,AREA_SERVER->get_room("list",""))!=-1)
   return 1;
else
   return 0;
AREA_SERVER->set_area(0);
}

void init_city_info(string p_id,string p_name,string p_zhou,string sht,int level)
{string tmp;

 if (!get_city_build_info(p_id,"prison")) tmp=RED"�������û�м�����������ʱ���ܿ��ţ�\n";
 if (!get_city_build_info(p_id,"go"))     tmp+="�������û�г�����ڣ�������ʱ���ܿ��ţ�\n";
 if (!get_city_build_info(p_id,"meeting")) tmp+="�������û����������������ʱ���ܿ��ţ�\n";
 if (!get_city_build_info(p_id,"fly")) tmp+="�������û��У����������ʱ���ܿ��ţ�\n";
 if (!get_city_build_info(p_id,"yizhan")) tmp+="�������û����վ��������ʱ���ܿ��ţ�\n"NOR;
 if (tmp) {write(tmp);return;}
 
 if (AREA_D->area_exist(p_id)) {write(RED"�õ����Ѿ����ڣ��޷�׷��!\n"NOR);return;}
 AREA_D->add_area(p_id); 
 AREA_D->set_area(p_id,"creator",this_body()->query_primary_id());
 AREA_D->set_area(p_id,"path","/a/"+p_id+"/");
 AREA_D->set_area(p_id,"fly",sht+"_lsjlg");
 AREA_D->set_area(p_id,"name",p_name);
 AREA_D->set_area(p_id,"zhou",p_zhou);
 AREA_D->set_area(p_id,"level",level);
 AREA_D->set_area(p_id,"safe",level*20+100);  //2001.4.13
 AREA_D->set_area(p_id,"population",level*1000);
 AREA_D->set_area(p_id,"gold",level*100);
 AREA_D->set_area(p_id,"st",0);
 AREA_D->set_area(p_id,"food",level*3000);
 AREA_D->set_area(p_id,"taxlocal",30);
 AREA_D->set_area(p_id,"taxnation",10);
 AREA_D->set_area(p_id,"bussiness",50);
 AREA_D->set_area(p_id,"business",50);
 AREA_D->set_area(p_id,"industry",50);
 AREA_D->set_area(p_id,"agriculture",50);
 AREA_D->set_area(p_id,"importance",0);
 AREA_D->set_area(p_id,"bl",0);
 AREA_D->set_area(p_id,"base",0);
 AREA_D->set_area(p_id,"troop",([])); 
 AREA_D->set_area(p_id,"prison",get_city_build_info(p_id,"prison"));
 AREA_D->set_area(p_id,"fly",get_city_build_info(p_id,"fly"));
 AREA_D->set_area(p_id,"go",get_city_build_info(p_id,"go"));
 AREA_D->set_area(p_id,"meeting",get_city_build_info(p_id,"meeting"));
 write("%^CYAN%^���ų��гɹ�!%^RESET%^\n");
}

void update_room(string p_id,string r_id)
{
 int n;
 object *obs = 0;
 object room= find_object("/a/"+p_id+"/"+r_id);
 if (room) {
 	obs = all_inventory(room);
 	for (n = 0; n < sizeof(obs); n++)
 	{
  	if (obs[n]->query_link() && interactive(obs[n]->query_link()))
      	  obs[n]->move(VOID_ROOM);
  	else destruct(obs[n]);
	}
           }
 destruct(find_object("/a/"+p_id),1);
 destruct(find_object("/a/"+p_id+"/"+r_id),1);
 for (n=0; n<sizeof(obs); n++) 
      if (obs[n]) obs[n]->move("/a/"+p_id+"/"+r_id);
}

void create_first_room_of_city(string p_id,string sht)
{   
    AREA_SERVER->set_area(p_id);
    if (AREA_SERVER->get_room(sht+"_lsjlg","b"))
       {
       write("%^RED%^�����Ѿ����������޷����δ�����%^RESET%^\n");
       return;
       }
    AREA_SERVER->add_room(sht+"_lsjlg");
    AREA_SERVER->set_room(sht+"_lsjlg","b","%^YELLOW%^��ʷ��¼��%^RESET%^");
    AREA_SERVER->set_room(sht+"_lsjlg","e",([]));
    AREA_SERVER->set_room(sht+"_lsjlg","l","
    �������������е���ʷ��¼�ݣ�����ǽ�ϵľ޴�ʯ����shibei��
��¼��������д����ɳ�����ʷ�����ȱ��Ĺ���¼���
");
    AREA_SERVER->set_room(sht+"_lsjlg","o",([
  "/sgdomain/obj/other/shibei.c" : ({
      1,
      "ʯ��",
      "city."+p_id,
    }),
]));
   update_room(p_id,sht+"_lsjlg");
   AREA_SERVER->set_area(0);
   write("%^CYAN%^�������гɹ�!%^RESET%^\n");
}

void trans_room(string sp_id,string sr_id,string dp_id,string dr_id)
{
mapping data,exits;
AREA_SERVER->set_area(sp_id);
data = AREA_SERVER->get_room(sr_id,"");
AREA_SERVER->set_area(dp_id);
exits=AREA_SERVER->get_room(dr_id,"e");
//printf("%O\n",exits);
AREA_SERVER->set_room(dr_id,"",data);
if (exits&&exits!=([]))
   {AREA_SERVER->set_room(dr_id,"e",exits);  //����roomʱ,��Դroom�г���,����������,���򸲸�
    update_room(dp_id,dr_id);}
AREA_SERVER->set_area(0);
}


void add_room(string p_id,string r_id) {
    AREA_SERVER->set_area(p_id);
    AREA_SERVER->add_room(r_id);
    AREA_SERVER->set_room(r_id,"b","%^YELLOW%^�շ���("+r_id+")%^RESET%^");
    AREA_SERVER->set_room(r_id,"l","");
    AREA_SERVER->set_room(r_id,"e",([]));
    AREA_SERVER->set_room(r_id,"t",0);
    AREA_SERVER->set_room(r_id,"o",([]));
    update_room(p_id,r_id);
    AREA_SERVER->set_area(0);
  }
  
void del_room(string p_id,string r_id)
{mapping r_info;
 int n;
 object *obs = 0;
 object room= find_object("/a/"+p_id+"/"+r_id);
 if (!room) return;
 obs = all_inventory(room);
 for (n = 0; n < sizeof(obs); n++)
 {
  if (obs[n]->query_link() && interactive(obs[n]->query_link()))
     obs[n]->move("/a/"+p_id+"/"+get_city_build_info(p_id,"short")+"_lsjlg");
  else destruct(obs[n]);
 }
 AREA_SERVER->set_area(p_id);
 r_info=AREA_SERVER->get_room(r_id,"e");
 AREA_SERVER->del_room(r_id);
 destruct(find_object("/a/"+p_id),1);
 foreach(string dir in keys(r_info))
  	  {mapping exits;
    	   exits=AREA_SERVER->get_room(r_info[dir],"e");
    	   if (exits&&exits!=([]))
    	       {map_delete(exits,opdirs[dir]);
       	        AREA_SERVER->set_room(r_info[dir],"e",exits);
       	        update_room(p_id,r_info[dir]);}
    	}
 destruct(find_object("/a/"+p_id+"/"+r_id),1);
 AREA_SERVER->set_area(0);
}

void set_room(string p_id,string r_id,string para,mixed data)
{
AREA_SERVER->set_area(p_id);
AREA_SERVER->set_room(r_id,para,data);
update_room(p_id,r_id);
AREA_SERVER->set_area(0);
}

mixed get_room(string p_id,string r_id,string para)
{mixed result;
AREA_SERVER->set_area(p_id);
result = AREA_SERVER->get_room(r_id,para);
AREA_SERVER->set_area(0);
return result;
}

int insert_connection(string p_id,string source,string dir,string dest) {
    mapping exits;
    AREA_SERVER->set_area(p_id);
    exits=AREA_SERVER->get_room(source,"e");
    if (!exits) exits=([]);
    if (member_array(dir,keys(exits))!=-1)
       {
       write("�÷����Ѿ��з������ӡ�\n");
       return;
       }
    exits[dir] = dest;
    AREA_SERVER->set_room(source,"e",exits);
    AREA_SERVER->set_area(0);
}

void del_connection(string p_id,string source,string dir){
    mapping exits;
    AREA_SERVER->set_area(p_id);
    exits=AREA_SERVER->get_room(source,"e");
    if (!exits) return;
    if (member_array(dir,keys(exits))==-1)
       {
       write("�÷���û�з������ӡ�\n");
       return;
       }
    map_delete(exits,dir);
    AREA_SERVER->set_room(source,"e",exits);
    update_room(p_id,source);
    AREA_SERVER->set_area(0);
}

void create()
{
unguarded(1, (: restore_object, SAVE_FILE, 1 :));
}
