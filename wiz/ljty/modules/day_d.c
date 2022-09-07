//*****************************************************************
// day_d.c  by fire on Jan 1, 1998
#include <ansi.h>
#include <mudlib.h>
// #include <area.h>
#define MORN HIG+"����¶��һ˿��������⣬�µ�һ�쿪ʼ�ˡ�"+NOR
#define NOON HIW+"̫�����������춥���Ѿ��������ˡ�"+NOR
#define AFTN HIR+"̫����ɽ�ˣ�������ʱ�����ӳ��һƬ��졣"+NOR
#define NIGT HIB+"�Ѿ�����ҹ�ˣ���Χ��һ�ж������ںڰ�֮�С�"+NOR
#define SPRING HIG+"�������ˣ���س���һƬ��ɫ��"+NOR
#define SUMMER HIR+"�������ˣ�С�������ǳ���Ϸˮ�ĺ�ͯ��"+NOR
#define AUTUMN HIY+"�������ˣ��˼�����˷��յ�ϲ�á�"+NOR
#define WINTER HIC+"�������ˣ���׵�ѩ�ƺ��ھ����˼�����"+NOR
#define DAY_LENGTH 240
#define W_SUNN 0
#define W_RAIN 1
#define W_FOGG 2
#define W_SNOW 3
#define W_WIND 4
#define W_BIGRAIN 5
#define W_HALL 6
#define MAXWEATHERTYPE 7
#define SUNN HIG+"̫�������ˣ����������û��һ˿�Ʋʡ�"+NOR
#define RAIN HIB+"��������������"+NOR
#define FOGG HIW+"�����ˡ�"+NOR
#define SNOW HIW+"���Ͼ�����Ʈ��ѩ����"+NOR
#define WIND HIR+"����ˣ�. . . ."+NOR
#define BIGRAIN HIG+"���������������·һƬ��Ţ��"+NOR
#define HALL HIC+"һ�����������ս����˱�����"+NOR
#define W_UNKNOW HIR+"�����������ס�"+NOR
static private int p_day;
static private int p_month;
static private int p_hour;
static private mapping p_weather=(["ly_area" : 0,"xbv_area" : 0 , 
"xiakou" : 1 , "others" : 0 ]);
static private mapping p_weather_next=(["ly_area" : 0,"xbv_area" : 0 , 
"xiakou" : 1 , "others" : 0 ]);
void arrange_weather_next()
{
	string * p_areas;
	int p_w;
	string w_info;
	object env;
	p_areas=keys(p_weather);
	foreach(string area in p_areas)
	{
		p_weather[area]=p_weather_next[area];
		p_weather_next[area]=random(MAXWEATHERTYPE);		
		if ((p_month!=12)&&(p_month!=1)&&(p_month!=2)&&p_weather_next[area]==W_SNOW)
			p_weather_next[area]=W_SUNN;
		if ((p_month!=6)&&(p_month!=7)&&(p_month!=8)&&p_weather_next[area]==W_HALL)
			p_weather_next[area]=W_SUNN;
	}
	
}
string weather_str_desc(int p_w)
{
	switch(p_w)
	{
		case W_SUNN:
			return SUNN;
		case W_RAIN :
			return RAIN;
		case W_FOGG :
			return FOGG;
		case W_SNOW :
			return SNOW;
		case W_WIND :
			return WIND;
		case W_BIGRAIN :
			return BIGRAIN;
		case W_HALL :
			return HALL;
		default :
			return W_UNKNOW;
	}
}
void show_weather()
{
	string * p_areas;
	string area_name;
	int p_w;
	string w_info;
	object env;
	p_areas=keys(p_weather);
	arrange_weather_next();
        foreach (object user in users()) 
	{
                if(objectp(user->query_body()))
		{
			env=environment(user->query_body());
			if(objectp(env))
			{
				if(!(env->is_indoors()) && !(env->is_outdoors()))
				{
					env=environment(env); // in case ride horse or sleep
				}
				area_name=env->get_area();
				if(member_array(area_name,p_areas)==-1)
					area_name="others";
				p_w=p_weather[area_name];
				w_info=weather_str_desc(p_w)+"\n";
				if(env->is_indoors())
					w_info="�����⡿"+w_info;
				else
					w_info="��������"+w_info;
	        		tell(({user}), w_info, MSG_INDENT);
			}
		}
	}
}
void show_season()
{
	string p_tmp;
	p_tmp="";
	switch(p_month)
	{
		case 3:
			p_tmp=SPRING;
			break;
		case 6:
			p_tmp=SUMMER;
			break;
		case 9:
			p_tmp=AUTUMN;
			break;
		case 12:
			p_tmp=WINTER;	
			break;
		default:
			break;
	}
	if(p_tmp!="")
	        tell(users(), p_tmp, MSG_INDENT);
}
void get_hour()
{
        string p_dis,p_disa;
        p_hour++;
        if(p_hour<0)
                p_hour=0;
        if(p_hour>=4)
	{
                p_hour=0;
		p_day++;
		if((p_day<1)||(p_day>10))
		{	p_day=1;
			p_month++;
			if((p_month<0)||(p_month>12))
			{
				p_month=1;
                                call_out((: show_season :),DAY_LENGTH/2);
			}
		}
	}
        switch(p_hour)
        {
                case 0:
                        p_dis=MORN;
			call_out((: show_weather :),DAY_LENGTH*2/3);
                        break;
                case 1:
                        p_dis=NOON;
                        break;
                case 2:
                        p_dis=AFTN;
                        break;
                case 3:
                        p_dis=NIGT;
                        break;
        }
       p_disa=sprintf("%s\n",p_dis);
       tell(users(), p_disa, MSG_INDENT);
        call_out((: get_hour :),DAY_LENGTH);
}
void create()
{
        get_hour();
}
