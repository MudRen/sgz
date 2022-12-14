//*****************************************************************
// day_d.c  by fire on Jan 1, 1998
// by ljty on Apr 20, 1998
// updated by tset Dec 10, 1998
#include <mudlib.h>
#include <security.h>
#include <clean_up.h>
#include <localtime.h>
inherit M_ACCESS;
#define SAVE_FILE "/data/daemons/day"
#define LOG_FILE "/data/daemons/daylog"
#define WEATHER_CHANNEL "weather"
#define CHANNEL_FORMAT "%%^WEATHER_CHANNEL%%^【%s】%s%%^RESET%%^\n"
#define MORN "东方露出一丝黎明的曙光，新的一天开始了。"
#define NOON "太阳升到了正天顶，已经是中午了。"
#define AFTN "太阳落山了，西方天际被落日映出一片火红。"
#define NIGT "已经是子夜了，周围的一切都笼罩在黑暗之中。"
#define SPRING "春天来了，大地呈现一片绿色。"
#define SUMMER "夏天来了，小河里满是赤身戏水的孩童。"
#define AUTUMN "秋天来了，人间充满了丰收的喜悦。"
#define WINTER "冬天来了，洁白的雪似乎在净化人间的罪恶。"
#define DAY_LENGTH 240
#define W_SUNN 0
#define W_RAIN 1
#define W_FOGG 2
#define W_SNOW 3
#define W_WIND 4
#define W_BIGRAIN 5
#define W_HALL 6
#define MAXWEATHERTYPE 7
#define SUNN "太阳出来了，蓝蓝的天空没有一丝云彩。"
#define RAIN "天上下起雨来。"
#define FOGG "起雾了。"
#define SNOW "天上静静地飘起雪来。"
#define WIND "起风了，. . . ."
#define BIGRAIN "大雨倾盆而降，道路一片泥泞。"
#define HALL "一阵闪电过后，天空降下了冰雹。"
#define W_UNKNOW "天气不明不白。"
#define PROTECTION_TIME (3600*24*5)  //重新启动后的不能war的时间,暂时为5天
#define DAY_IN_SECONDS (3600*24) //a whole day in seconds

private int p_day;
private int p_month;
private int p_hour;
private int p_year;

//private int can_war=1;
private int change_time;
//private int war_start_hour, war_hour, war_interval; 

private int is_crash;

private int generation=7;

static float p_utime,p_stime;
static int p_uptime;
static int p_boottime;

void deliver_weather();

int get_can_war() {
	if(time()>change_time)
		return 1;
	else
		return 0;
}
int get_change_time() {
	return change_time-time();
}
int get_temp_wartime(string c_id) //check if a country's temp wartime is open
{
	int t1,t2;
	t1 = time();
	t2 = COUNTRY_D->get_country(c_id,"temptime");
	if (t1 < t2)
		return t2 - t1;
	else 
		return 0; 
}

void block_war (int hour)
{
	change_time=time()+hour*3600;
	//SGSYS(" 战争现在被巫师禁止了.");
}

int war_status (string c_id)
{
	int _t, *_lt;
	int weekday;
	int hour;
	
	if (get_can_war() == 0)
		return 2; //message for system blocked
	_t = time();
	if (get_temp_wartime(c_id) > 0) // temp wartime opens
		return 0;
	_lt = localtime(_t);
	weekday = _lt[LT_WDAY]; //看今天是星期几
	if ((_lt[LT_HOUR] == COUNTRY_D->get_wartime(c_id,weekday*2))
	   || ( _lt[LT_HOUR] == COUNTRY_D->get_wartime(c_id,weekday*2+1)))//match any of war time period
	   	return 0; //message for can war
	else
		return 1; //message for can not war
}
int beijing_time(int base_time)
{
	return localtime(base_time)[LT_GMTOFF]+28800; 
	//第一个参数是当地时间相对于标准时间的秒差，不知道是否能解决夏令时问题
	//28800是北京时间相对于标准时间的秒差-8小时
}
int london_time(int base_time)//+0 hour
{
	return localtime(base_time)[LT_GMTOFF];
}

int sydney_time(int base_time)//+10 hour
{
	return localtime(base_time)[LT_GMTOFF]+10*3600; //冬令时only
}

int next_modified_day(int base_time)
{
	int *lt;
	lt = localtime (base_time);
	return base_time - lt[LT_HOUR] * 3600 - lt[LT_MIN] * 60 - lt[LT_SEC] + 2 * DAY_IN_SECONDS;
	
	//base_time-=localtime(base_time)[LT_GMTOFF]*3600; //
	//return (base_time/DAY_IN_SECONDS+1)*DAY_IN_SECONDS; //两天后的系统零点
}
string English_time(int time)
{
	int *_lt;
	int month;
	string minutes;
	
	_lt=localtime(time);
	month = _lt[LT_MON]+1;
	if ( _lt[LT_MIN] < 10 )
		minutes = "0" + _lt[LT_MIN];
	else
		minutes = "" + _lt[LT_MIN];
	return _lt[LT_YEAR] + "年" + month + "月" + _lt[LT_MDAY] + "日 "
		+ _lt[LT_HOUR] + ":" + minutes ;
}
	
	
/*
void recover_war ()
{
	can_war = 1;
	SGSYS(" 战争现在被巫师恢复了.");
}
*/
/*

int set_war_time(int s, int h, int i) {
    int _t, *_lt;
    war_start_hour = s;
    war_hour = h;
    war_interval = i;
    if (h == 0 || can_war) return 0;
    _t = time();
    _lt = localtime(_t);
    change_time = _t + war_start_hour * 3600 + war_interval * 3600
        - (_lt[LT_HOUR] * 3600 + _lt[LT_MIN] * 60 + _lt[LT_SEC]);
    return 1;
}
    
int set_can_war(int a) 
{
	int last, _t, *_lt;
	if(a==1) // set can war 
	{
		can_war=1;
		if (war_hour > 0) {	// which means fixed war time
		    last = war_hour;
	        }
	        else {
                    last=2+random(4);

	        }
		change_time=time()+last*3600;  // open hour from 3 to 12 hours
"/sgdomain/event/ev_cast.c"->start(); // open the auto cast
		CHANNEL_D->deliver_tell("gossip","汉献帝",
			"今奸臣当道，朝纲不振，朕特许天下诸侯讨伐贼逆"+chinese_number(last)+
			"个时辰。");
	}
	else {
		can_war=0;
		if (war_hour > 0) {	// which means fixed war time
		    _t = time();
		    _lt = localtime(_t);
		    last = war_start_hour * 3600 + war_interval * 3600
			- (_lt[LT_HOUR] * 3600 + _lt[LT_MIN] * 60 + 
				_lt[LT_SEC]);
		}
		else {    
		    last=12+random(24);
		    last*=3600;
		}
		change_time=time()+last;  // open hour from 3 to 12 hours
		CHANNEL_D->deliver_tell("gossip","汉献帝",
			"今战祸不断，生灵涂炭，百姓受苦，朕特令天下诸侯停战"+
			CHINESE_D->chinese_period(last)+"。");
	}
}
void check_can_war() {
	if(time()>change_time) {
		set_can_war(1-can_war);
	}
}
*/
array query_date()
{
	array p_date=({p_hour,p_day,p_month,p_year});
	return p_date;
}

string query_season(int eng) {
	switch(p_month) {
	  case 12:
	  case 1:
	  case 2:
		if (eng)
		  return "winter";
		else
		  return "冬季";
	  case 3:
	  case 4:
	  case 5:
		if (eng)
		  return "spring";
		else
		  return "春季";
	  case 6:
	  case 7:
	  case 8:
		if (eng)
		  return "summer";
		else
		  return "夏季";
	  case 9:
	  case 10:
	  case 11:
		if (eng)
		  return "winter";
		else
		  return "秋季";
	  default:
		if (eng) 
		  return "unknown";
		else
		  return "不确";
	}
}

string query_string_day()
{
	if(p_day<4)
		return "上旬";
	if(p_day>7)
		return "下旬";
	return "中旬";
}

string query_string_hour(int eng)
{
	switch(p_hour)
	{
	case 0:
		if (eng)
		  return "morning";
		else
		  return "清晨";
	case 1:
		if (eng)
		  return "noon";
		else
		  return "正午";
	case 2:
		if (eng)
		  return "afternoon";
		else
		  return "黄昏";
	default:
		if (eng)
		  return "night";
		else
		  return "夜间";
	}
}

void arrange_weather_next()
{
    string * p_areas;
    int p_w;
    p_areas=AREA_D->list_areas();
    foreach(string area in p_areas)
    {
	p_w=AREA_D->get_area(area,"n_weather");
	AREA_D->set_area(area,"weather",p_w);
        p_w=random(MAXWEATHERTYPE);
        if ((p_month!=12)&&(p_month!=1)&&(p_month!=2)&&p_w==W_SNOW)
        p_w=W_SUNN;
        if ((p_month!=6)&&(p_month!=7)&&(p_month!=8)&&p_w==W_HALL)
        p_w=W_SUNN;
		AREA_D->set_area(area, "n_weather", p_w);
    }
}
void arrange_wind_next()
{
    string * p_areas;
    int p_w;
    p_areas=AREA_D->list_areas();
    foreach(string area in p_areas)
    {
        if( !p_w=AREA_D->get_area(area,"n_wind") )p_w = 0;
	if( AREA_D->get_area(area, "weather") == 4 && p_w == 0)
	        AREA_D->set_area(area,"wind", random(7)+1);
        else AREA_D->set_area(area,"wind",p_w);
	if( p_month == 12 || p_month == 1 || p_month == 2 )p_w = 1 - random(3);
	else if( p_month == 6  || p_month == 7 || p_month == 8 )p_w = 3+random(3);
	else p_w = random(9);
	if( p_w < 0 ) p_w = p_w + 9;
	p_w = p_w + (1-random(3));
	if( p_w > 9 ) p_w = p_w - 9;
        AREA_D->set_area(area, "n_wind", p_w);
    };
}
string get_wind_short(int wind)
{
	switch(wind){
		case 1 : return "北风";	break;
		case 2 : return "东北风";break;
		case 3 : return "东风";break;
		case 4 : return "东南风";break;
		case 5 : return "南风";break;
		case 6 : return "西南风";break;
		case 7 : return "西风";break;
		case 8 : return "西北风";break;
		default : return "无风";
	};
}
string get_weather_short(int p_w)
{
	switch(p_w) {
        case W_SUNN:
            return "晴天";
        case W_RAIN :
            return "下雨";
        case W_FOGG :
            return "起雾";
        case W_SNOW :
            return "下雪";
        case W_WIND :
            return "大风";
        case W_BIGRAIN :
            return "暴雨";
        case W_HALL :
            return "冰雹";
        default :
            return "未知";
    }
}

string weather_str_desc(int p_w)
{
    switch(p_w) {
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

void show_weather() {
    arrange_weather_next();
    arrange_wind_next();
    deliver_weather();
}

void show_season() {
    string p_tmp;
    p_tmp="";
    switch(p_month) {
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
           return;
    }

    CHANNEL_D->deliver_channel(WEATHER_CHANNEL, p_tmp);
    
}
void active_handi() {
	object o;
	o=load_object("/sgdomain/area/emp/dadi");
	if(!objectp(o))
		SGSYS("找不到汉帝宫");
}
void do_log() {
    string msg;
    mixed rusage;
    int upt;
    float st,ut;
    msg=sprintf("buut_time %d year: %d month: %d day: %d hour: %d realtime: %d\n",
      p_boottime,p_year,p_month,p_day,p_hour,time());
    p_boottime++;
    /*rusage=rusage();
    st=rusage["stime"]-p_stime;
    ut=rusage["utime"]-p_utime;
    upt=uptime()-p_uptime;

    p_stime=rusage["stime"];
    p_utime=rusage["utime"];
    p_uptime=uptime();
  
    st=st/10.0/upt;
    ut=ut/10.0/upt;

    msg+=sprintf("system useage: %2.2f%%, user useage: %2.2f%%\n",st,ut);
    msg+=sprintf("Average load: %s\n",query_load_average());
    msg+=sprintf("Objnumber: %d\n",sizeof(objects()));
    msg+=sprintf("Memory useage: %d\n\n",memory_info());*/
    unguarded(1, (: write_file, LOG_FILE, msg :));
    
}
void day_goes_on()
{
    string p_dis;
    remove_call_out("day_goes_on");
    call_out( "day_goes_on", DAY_LENGTH);
    call_out("active_handi",2); //汉帝
//by listen for do not need to update everyday    check_can_war();
//    call_out("do_log",3);
    p_hour++;
    if(p_hour<0)
    p_hour=0;
    if(p_hour>=4) {
        p_hour=0;
        p_day++;
        if((p_day<1)||(p_day>10)) {
            p_day=1;
            p_month++;
            if((p_month<0)||(p_month>12)) {
                p_month=1;
		p_year++;
            }
            remove_call_out("show_season");
            call_out( "show_season", DAY_LENGTH/2);
        }
    }
    
    switch(p_hour)
    {
        case 0:
            p_dis=MORN;
            remove_call_out("show_weather");
            call_out( "show_weather", DAY_LENGTH*2/3);
            break;
        case 1:
            p_dis=NOON;
            break;
        case 2:
            p_dis=AFTN;
            break;
        case 3:
            p_dis=NIGT;
	    unguarded(1, (: save_object, SAVE_FILE :));
        break;
    }
    CHANNEL_D->deliver_channel(WEATHER_CHANNEL, p_dis);
    AI_D->start();
}

void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));

    if(is_crash) 
         unguarded(1, (: write_file, LOG_FILE, "\n\n====\nThis may be a crash\n\n" :));
    else
         unguarded(1, (: write_file, LOG_FILE, "\n\n====\nThis may be normal start or update\n\n" :));

    is_crash=1;
    day_goes_on();
    return;
}

nomask void deliver_weather() {

    string* p_areas;
    string  area_name;
    string* r_areas;
    int p_w;
    string w_info;
    object env;
    object* listeners = CHANNEL_D->query_listeners("weather");
    object body;
    
    p_areas = AREA_D->list_areas();
    if (!listeners) return;
    foreach (object user in listeners) {
if(!user) continue;
   body = user->query_body();
        if (!objectp(body)) continue;
        env = environment(body);
        while (env && !inherits(BASE_ROOM, env)) 
            env = environment(env);
        if (!objectp(env)) continue;
        area_name=env->get_area();
	r_areas=AREA_D->check_area("area", area_name);
		
	if (sizeof(r_areas)) area_name=r_areas[0];
	else continue;              // no area, no weather

        p_w=AREA_D->get_area(area_name, "weather");
        w_info=weather_str_desc(p_w);
        if (!env->is_indoors()) {
	    w_info = sprintf(CHANNEL_FORMAT, "户外", w_info);
	} else {
	    w_info = sprintf(CHANNEL_FORMAT, "天气", w_info);
	}
        tell(({user}), w_info, MSG_INDENT);
    }
}
void clean_up() {
  return NEVER_AGAIN;
}
void remove()
{
    is_crash=0;
    unguarded(1, (: save_object, SAVE_FILE :));
}
string query_chinese_day() {
	return "三国"+chinese_number(p_year)+"年"+chinese_number(p_month)+"月"+
		chinese_number(p_day)+"日";
}

//added by suicide on 20001.03.07
void add_generation()
{
generation++;
//can_war=0;
change_time=time()+PROTECTION_TIME;
CHANNEL_D->deliver_tell("gossip","汉献帝",
			"今战祸不断，生灵涂炭，百姓受苦，朕特令天下诸侯停战"+
			CHINESE_D->chinese_period(PROTECTION_TIME)+"。");

}

int get_generation()
{
return  generation;
}

int set_date(int day)
{
p_day = day;
p_hour = 3;
return p_day;
}
void init_day_d(){
    p_day = 0;
    p_month = 0;
    p_hour = 0;
    p_year = 0;
}
