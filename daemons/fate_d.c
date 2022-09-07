//filename /daemons/fate_d.c
//Created by Suicide in 02/20/2000
//modified by suicide in 03/19/2000
#include <mudlib.h>
#include <security.h>
#include <daemons.h>
#define SAVE_FILE "/data/daemons/fate_d"
#define LOG       "/data/log/fates.log"
#define NO_ALERT 1
inherit M_ACCESS;
static string array sym_tien = ({ "��","��","��","��","��","��","��","��","��","��" });
static string array sym_dee = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });
static string array season = ({"spring","summer","autumn","winter"});
static mapping fate_name = ([
"goodsign"  :"����",
"snow"      :"��ѩ",
"foison"    :"����",
"fire"      :"���",
"flood"     :"��ˮ",
"earthquake":"����",
"locust"    :"�ȳ�",
"murrain"   :"����",
"drought"   :"�ɺ�",
"cyclone"   :"쫷�",
"bandit"    :"�˻�",
"riot"      :"����",
]);
static array omen=({
({"good","east","north"}),
({"bad","east","center"}),
({"good","east","south"}), 
({"good","east","south"}),
({}),
({"good","center","south"}),
({"bad","west","south"}),
({"good","center","west"}),
({"good","west","north"}),
({"good","west","north"}),
({"bad","east","center"}),
({"good","east","north"}),
({"bad","south","north"}),
({"good","center","south"}),
({"bad","center","east"}),
({"bad","center","east"}),
({"good","center","west"}),
({"bad","west","south"}),
({"bad","south","north"}),
({"bad","center","north"}),
({"bad","east","west"}),
({"bad","east","west"}),
({"good","center","south"}),
({"bad","south","north"}),
({"bad","center","north"}),
({}),
({"bad","east","west"}),
({"bad","east","west"}),
({"bad","center","north"}),
({"bad","south","north"}),
({"good","east","south"}),
({"bad","center","east"}),
({"bad","west","south"}),
({"bad","west","south"}),
({}),
({"bad","center","north"}),
({"good","west","north"}),
({"good","center","west"}),
({"good","east","north"}),
({"good","east","north"}),
({"bad","center","north"}),
({"good","east","south"}),
({}),
({"good","center","south"}),
({"good","center","west"}),
({"good","center","west"}),
({"good","center","west"}),
({"good","west","north"}),
({}),
({"bad","center","north"}),
({}),
({}),
({"good","center","south"}),
({}),
({"good","center","south"}),
({}),
({}),
({}),
({"bad","center","north"}),
({})
                     });
                     
static mapping geo = ([
"east":({"����","����","����"}),            //5+3+5=13 cities
"south":({"����","۫��","����","�Ͼ���"}),  //7+6+3+8=24 cities
"center":({"˾��","ԥ��","������"}),          //7+4+7=18 cities
"west":({"����","����","����","Ӻ��"}),    //4+8+8+8=28 cities
"north":({"����","����","����"})           //4+4+6=14 cities
      ]);
static string seasonnow="spring";
static int times=3;
static array info=({});
private int adjust_level;  
private int create_year;  
private mapping tz_type;                  
private mapping fate_table;
void log(string msg)
{
 unguarded(1, (: write_file, LOG,msg:));
}
void save_data()
{
    unguarded(1, (: save_object, SAVE_FILE, 1 :));
    return;
}


//add fate type
mixed add_fate_type(string what,string type,array seasons)
{
if ((type!="good")&&(type!="bad")) return "���ʱ������ֻ��good��bad����.\n";
foreach(string ss in seasons)
{int index = member_array(season,ss);
 if (index!=-1)
    tz_type[type][index] -= ({what});
    tz_type[type][index] += ({what});
}
save_data();
return 1;
}

//delete fate type
mixed del_fate_type(string what,string type,array seasons)
{
if ((type!="good")&&(type!="bad")) return "���ʱ������ֻ��good��bad����.\n";
foreach(string ss in seasons)
{int index = member_array(season,ss);
 if (index!=-1)
    tz_type[type][index] -= ({what});
}
save_data();
return 1;
}
string get_fate_type(string fate)
{string type = "good";
 foreach(array ss in tz_type["bad"])
    if (member_array(fate,ss)!=-1)
         {type = "bad";break;}
 return type;
}
string get_fate_name(string fate)
{
 if (stringp(fate_name[fate]))
 return fate_name[fate];
 else 
    return fate;
}

//update the fate_table when one fate event happened or runaway.
//info[2]=-1       δ����
//         0       �������ֹ
//         [1..10] �����ļ���
void update_fate_info(int level)
{
 if (!sizeof(info)) return ;
 //SGSYS(sprintf("seasonnow=%s\n",seasonnow));
 fate_table[seasonnow] -=({info});
 info[2]=level;
 fate_table[seasonnow] +=({info});
 save_data();
 info=({});
 times=3;
 return;
}

//damage adjust key 
int get_adjust_level()
{  
  return adjust_level;
}
int set_adjust_level(int lvl)
{ 
  adjust_level = lvl;
  save_data();
  return adjust_level;
       
}

//get the create year of fate_table
int get_create_year()
{
  return create_year;
}

//damage the area
void area_effect(string p_area,mapping effect,int damage_level) 
{ 
 mixed val;      
 foreach(string st in keys(effect))
 {
  val=AREA_D->get_area(p_area,st);
  if (mapp(val))
     {foreach(string ss in keys(val))
      if (val[ss]["num"]>0)
          val[ss]["num"] += val[ss]["num"]*damage_level*adjust_level*effect[st]/5000;
     }
  else
     val += val*damage_level*adjust_level*effect[st]/5000;
  AREA_D->set_area(p_area,st,val);
 }
}


int get_damage_level(string p_area,mapping condition,int type)
{
 int i=0;int j=0;  
 foreach(string ss in keys(condition))
   { 
     if ((j=AREA_D->get_area(p_area,ss))<condition[ss])
        i +=  (condition[ss]-j)*10/condition[ss]+1;
   }
 if (i==0) 
    if (type==0) return 0;   //type =0 �ֻ� type = 1 ����
    else      return 6+random(5);
 if (type==1) i= 10*sizeof(condition)-i;
 if (random(10)<=(i/sizeof(condition))) 
    if (type==0) return random(10)+1;
    else return 1+random(5);
 else return 0;   
}            
 
                     
string get_tgdz(int year)  //�õ���Ӧ��ݵ���ɵ�֧
{year -= 184;        //������������ʼ��Ϊ184��,Ϊ������
 return sym_tien[year%10]+sym_dee[year%12];
}

//create the fate_table
mapping create_tz_table(int year)  //�õ�ÿ������ֱ�
{
 array data=({});
 array zhou=({});
 array type=({});
 array areas=({});
 mapping table=([
 "spring":({}),
 "summer":({}),
 "autumn":({}),
 "winter":({})
               ]);
 int datalen,i,rad,tgdz;
 array seek;
 create_year= year;
tgdz=(year+56)%60;
 data = omen[tgdz];
if (!(datalen=sizeof(data))) {
fate_table = ([]);
save_data();
return ([]);}
 //if (data[0]=="good") type =1;
   // else type = 0;
 for (i=1;i<datalen;i++)
 {
   zhou+=geo[data[i]];
 }
 //SGSYS(sprintf("list is %O\n",zhou ));
 areas = filter_array(AREA_D->list_areas(),(: (member_array(AREA_D->get_area($1,"zhou"),$(zhou))!=-1) :));
 datalen = sizeof(areas);
 i=0;
 seek=({});
 while (i<=datalen/3)
 { rad= random(datalen);
   if (member_array(rad,seek)==-1)
      { 
       	i++;
        seek += ({rad});
        type = tz_type[data[0]][i%4]; //��i�����ļ�
      	table[season[i%4]] += ({({areas[rad],type[random(sizeof(type))],-1})});
      }
 }
  fate_table = table;
  save_data();
  return fate_table;
}

array query_tz_info(string season)
{if (!fate_table[season]) return ({});
 return fate_table[season];}  
 
mapping query_fate_table()
{
if (mapp(fate_table))
    return fate_table;
}
     
void create()
{   array p_date;   
    p_date = DAY_D->query_date(); 
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    if (!adjust_level) adjust_level=5;
    if (!sizeof(tz_type)||!mapp(tz_type))
        tz_type =([
        "bad" : ({
         ({"earthquake","flood","fire","murrain"}),     //spring
         ({"earthquake","flood","drought","locust","fire","cyclone","murrain"}), //summer
         ({"earthquake","drought","locust","fire","murrain"}), //autumn
         ({"earthquake","fire","murrain"})  //winter
        }),
        "good" : ({
         ({"goodsign"}),        
         ({"goodsign"}),
         ({"goodsign","foison"}),
         ({"goodsign","snow"})
        })
                   ]);
        	
    if ( !sizeof(fate_table)||!mapp(fate_table)||(create_year!=p_date[3]) )
        {
         fate_table = create_tz_table(p_date[3]);	
         create_year = p_date[3];
         save_data();
         }
    call_out("start_fate",0);
  }

void start_fate()
{ 
  array  tz_info;
 string filename;
mixed msg;
  int    adjust;
  array  p_date;
  
  remove_call_out("start_fate");
  call_out("start_fate",240*5); //mud�������һ�Σ�
    
  if (times<0) times=3;   //���ѣ��Σ����Ĵη�����
                          //�м��κ�һ�������жϲ��������������¼���
    
  if (!sizeof(info))      //���û�е�ǰ��fate��Ϣ��ȡֵ��
  {
  p_date = DAY_D->query_date(); 
if (p_date[3]!=FATE_D->get_create_year())
FATE_D->create_tz_table(p_date[3]);
  switch (p_date[2]) 
  {
   case 1:
   case 2:
   case 3:
        seasonnow="spring";
        break;
   case 4:
   case 5:
   case 6:
        seasonnow="summer";
        break;
   case 7:
   case 8:
   case 9:
        seasonnow="autumn";
        break;
   case 10:
   case 11:
   case 12:
        seasonnow="winter";
        break;
  }
  tz_info = query_tz_info(seasonnow);
  tz_info = filter_array(tz_info,(: (($1)[2]==-1) :));
  if (!sizeof(tz_info)) 
   {SGSYS("û�ж�Ӧ��������Ϣ!");
       return;}
       
 // foreach(array info in tz_info){
  info=tz_info[0];
  }
  //SGSYS(sprintf("times=%d\n",times));   
  filename = "/sgdomain/event/ev_fate/ev_"+info[1];
  if (times)  //�������Ѵ���
    {msg = (filename)->get_alert_msg(info[0],times); 
// if (intp(msg)&&msg==NO_ALERT) return;
     //don't alert for good things in defualt
    if (adjust=(filename)->can_do_fate(info[0])) //�ܷ�����
    {     
     if (!stringp(msg))
if (FATE_D->get_fate_type(info[1])=="bad")
        msg = "%^B_RED%^%^H_YELLOW%^��������ϻ����ɣ�����ҹ��"+AREA_D->get_area(info[0],"name")+
            "֮�����Ǹ��֣����տ�������֮�֣�������������\n%^RESET%^";
else
  msg = "%^B_RED%^%^H_YELLOW%^��������ϻ����ɣ�����ҹ��"+AREA_D->get_area(info[0],"name")+
        "֮�ظ�����ҫ������Ӧ���콵�͸���\n%^RESET%^";
     tell(users(),msg);
     times--;
    return;}
    else //���ܷ���
    {
if (FATE_D->get_fate_type(info[1])=="bad")
     msg = "%^B_RED%^%^H_YELLOW%^��������ϻ����ɣ�����ҹ�����࣬��"+AREA_D->get_area(info[0],"name")+
            "֮�ذ����ϣ����Ǳӻ�������֮���������Σ�\n%^RESET%^";
else
msg = "%^B_RED%^%^H_YELLOW%^��������ϻ����ɣ�����ҹ�����࣬��"+AREA_D->get_area(info[0],"name")+
            "֮����Թ���𣬸��ǰ������콵�͸��������Σ�\n%^RESET%^";
     tell(users(),msg);
     //SGSYS(sprintf("%s�����%s��fate\n",info[0],info[1]));
     msg = sprintf("%s ��� %s at %s\n",info[0],info[1],ctime(time()));
     update_fate_info(0);
     log(msg);
     
     return;
    }
    }
  else //���Ѵ��������꣮
    if (adjust=(filename)->can_do_fate(info[0])) //����
      {
       (filename)->do_fate(info[0],adjust);
     //   msg = "%^B_RED%^%^H_YELLOW%^��������ϻ����ɣ�"+AREA_D->get_area(info[0],"name")+
     //       "���յض�ɽҡ���������أ���������ʧ����\n%^RESET%^";
     //   tell(users(),msg);

        msg = sprintf("%s ���� %s ���� %d at %s \n",info[0],info[1],adjust, ctime(time()));
        update_fate_info(adjust);
        log(msg);
        info=({});times=3;
      }
    else  //������
      {//SGSYS(sprintf("%s�����%s��fate\n",info[0],info[1]));
       msg = sprintf("%s ��� %s at %s\n",info[0],info[1],ctime(time()));
       log(msg);
       msg = "%^B_RED%^%^H_YELLOW%^��������ϻ����ɣ�����ҹ�����࣬��"+AREA_D->get_area(info[0],"name")+
            "֮�ذ����ϣ����Ǳӻ�������֮���������Σ�\n%^RESET%^";
       tell(users(),msg);
       update_fate_info(0);
       info=({});times=3;
      }
 
  
  
  return;  
}
 
//stop the repeated func call(start_fate) 
void remove()
{
   remove_call_out("start_fate");
}

int clean_up() {
   return 0; // means never_again
}
