// task_d.c
// this is the one used to maintain all the tasks
// a very important daemon
// by fire on July 29, 1998
// id, type, stage, timer, timeaim, a_para1, a_para2, m_para1,m_para2
#define STAGE_NEW 0
#include <mudlib.h>
#include <security.h>
inherit M_ACCESS;
private mapping tasks=([]);
static int save_mark;
private int max_task_id;
#define SAVE_FILE "/data/daemons/task"
void save_data()
{
	
	save_mark++;
	if((save_mark<0)||(save_mark>20))
	{
		save_mark=0;
        unguarded(1, (: save_object, SAVE_FILE :));
	}
}
void task_increase()
{
	int p_num,i;
	int *list;
	list=keys(tasks);
	p_num=sizeof(list);
	for(i=0;i<p_num;++i)
	{
         tasks[list[i]]["timer"]=tasks[list[i]]["timer"]+1;
	}
}
void run_task(int p_id)
{
	switch(tasks[p_id]["type"])
	{
	case TT_LOCALMEETING:
		(EV_LOCALMEETING)->meet_process(p_id);
		break;
        case TT_WAR:
            (EV_WAR)->meet_process(p_id);
            break;
        case TT_TRAIN:
            (EV_WAR)->train_process(p_id);
            break;
	case 255: // TT_PARTY
	    load_object("/sgdomain/event/ev_party.c")->meet_process(p_id);
	    break;
	}
}
void task_check()
{
	int p_num,i;
	int *list;
	list=keys(tasks);
	p_num=sizeof(list);
	for(i=0;i<p_num;++i)
	{
		if(tasks[list[i]]["timer"]>=tasks[list[i]]["timaim"])
		{
			tasks[list[i]]["timer"]=0;
			run_task(list[i]);
		}
	}
}
void task_heart()
{
	call_out("task_heart",5);
	task_increase();
	task_check();
	save_data();
}
int add_task(int p_type)
{
	int p_id=0;
	if((max_task_id>1000)||(max_task_id==0)) // this is for don't want disturb current task
		max_task_id=10;

	max_task_id++;
	while(mapp(tasks[max_task_id]))
		max_task_id++;
	p_id=max_task_id;  // incase one task removed and another added with the
                           // same value, may cause bug
	tasks[p_id]=([]);
	tasks[p_id]["type"]=p_type;
	tasks[p_id]["stage"]=STAGE_NEW;
	tasks[p_id]["timer"]=0;
	tasks[p_id]["timaim"]=100; // should determined by type
	tasks[p_id]["chars"]=([]);
	return p_id;
}
mixed get_task(int task_id,string p_name)
{
	if(!tasks[task_id])
		return 0;
	if((!p_name)||(p_name=="")) 
		return tasks[task_id];
	if(!tasks[task_id][p_name])
		return 0;
	return tasks[task_id][p_name];
}
int set_task(int task_id,string p_name,mixed p_val)
{
	if(!tasks[task_id])
		return 0;
	tasks[task_id][p_name]=p_val;
	return 1;
}
void remove_task(int p_id)
{
	mixed chars;
	string *c_list;
	if(!tasks[p_id])
            return;
	chars=tasks[p_id]["chars"];
	if(sizeof(chars))
	{
		c_list=keys(chars);
		foreach(string c_id in c_list)
		{
			if(CHAR_D->get_char(c_id,"is_tmp"))
				CHAR_D->remove_char(c_id);
		}
	}
    map_delete(tasks,p_id);
}
mixed query_tasks()
{
	return tasks;
}
void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	call_out("task_heart",5);
    return;
}
// this is the most inquire function
// will return a char's task number
// task type 
// and his position
int* get_char_task(string c_id)
{
	int *list;
	int i,p_num;
	list=keys(tasks);
	p_num=sizeof(list);
	for(i=0;i<p_num;++i)
	{
		if(!sizeof(tasks[list[i]]["chars"]))
			continue;
		if(tasks[list[i]]["chars"][c_id])
			return ({list[i],tasks[list[i]]["type"],
			tasks[list[i]]["chars"][c_id]});
	}
// no task, no type, no position;	
	return ({-1,0,0});
}
int get_area_task(string a_id)
{
        int *list;
        int i,p_num;
        list=keys(tasks);
        p_num=sizeof(list);
        for(i=0;i<p_num;++i)
        {
		if(tasks[list[i]]["area"]==a_id)
			switch(tasks[list[i]]["type"])
			{
				case TT_WAR: return ST_WAR;
				case TT_LOCALMEETING: return ST_MEETING;
				case TT_TRAIN: return ST_TRAIN;
				default :return 10000; // this is unknow
			}
        }
	return ST_NORMAL;
}
int get_area_task_id(string a_id) {
    int *list;
    int i,p_num;
    list=keys(tasks);
    p_num=sizeof(list);
    for(i=0;i<p_num;++i)
    {
		if(tasks[list[i]]["area"]==a_id)
			return list[i];
    }
	return -1;
	
}
int add_char(int t_id,string c_id,mixed pos)
{
	mixed chars;
	if(!tasks[t_id])
		return 0;
	chars=tasks[t_id]["chars"];
	if(!chars)
		chars=([]);
	chars[c_id]=pos;
	tasks[t_id]["chars"]=chars;
	return 1;
}
void remove() {
   save_mark=20;
   save_data();
}
int clean_up() {
   return 0; // means never_again
}
string get_typestring(int t) {
	switch(t) {
	case TT_LOCALMEETING:
		return "��������";
        case TT_WAR:
		return "ս��";
        case TT_TRAIN:
		return "ѵ��";
	case 255: // TT_PARTY
		return "���";
	default : return "δ֪";

	}
}
string show_me() {
	int *ids;
	string ret="";
	ids=keys(tasks);
	if(!sizeof(ids)) {
		return "Ŀǰû���κ�����\n";
	}
	foreach(int id in ids) {
		string a,*cids;
		int t;
		a=tasks[id]["area"];
		cids=tasks[id]["chars"];
		t=tasks[id]["type"];
		ret+="����ID��"+id+" ";
		ret+="���������"+AREA_D->get_area(a,"name")+"("+a+") ";
		ret+="�������ͣ�"+get_typestring(t)+" \n";
		if(sizeof(cids)) {
			ret+="�μӽ�ɫ��";
			foreach(string c,int p in cids) {
				ret+=CHAR_D->get_char(c,"name")+"("+c+"):"+p+" ";
			}
			ret+="\n";
		}
		ret+="---------------------------------------------------------------\n";

	}
	return ret;
}
int task_exist(int t_id) {
	if(mapp(tasks[t_id])) return 1;
	return 0;
}
