// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** who.c -- intermud who
**
** 95-May-15.  Deathblade.  Created.
*/
#include <log.h>
#define CMD_WHO_OBJ "/cmds/player/who.c"

private mapping	mudlist_user_num = ([ ]); 	//added by suicide in 2000.01.12
private mixed* userlist = ({});				//who-reply���д��Ĳ�������������({"username",idle time,"extra info"})

mapping query_mudlist();
void send_to_mud(string type, string mudname, mixed * message);
void send_to_user(string type, string mudname, string username,
                  mixed * message);
void return_error(string mudname, string username,
                  string errcode, string errmsg);
string canon_mudname(string mudname);
//nomask mixed* get_who_list();

nomask void do_who(string mudname, string arg)
{
    //send_to_mud("who-req", canon_mudname(mudname), ({ arg }));
	send_to_mud("who-req", canon_mudname(mudname), ({}));
}

static nomask void rcv_who_req(string orig_mud, string orig_user,
                               string targ_user, mixed * message)
{
    string ret;
	mixed* wholist = ({});

	//tell_user("huaer",sprintf("����/imud/who.c��\n"));
	//tell_user("huaer",sprintf("orig_mud = %s\n",orig_mud));
	//tell_user("huaer",sprintf("orig_user = %s\n",orig_user));
	//tell_user("huaer",sprintf("targ_user = %s\n",targ_user));
	//tell_user("huaer",sprintf("message = %O\n",message));
    ret = implode(message, "");
	//tell_user("huaer",sprintf("ret = %s\n",ret));

    /*if ( !ret||ret=="" ) 
    	userlist = load_object(CMD_WHO_OBJ)->get_who_list();
    else */
		wholist = load_object(CMD_WHO_OBJ)->get_who_list();
		//ret = load_object(CMD_WHO_OBJ)->get_who_string();
	//get_who_list();
	//wholist = userlist;
	//userlist = ({});
	
	//tell_user("huaer",sprintf("wholist = %O\n",wholist));
	
    //send_to_user("who-reply", orig_mud, orig_user, ({ ret }));
	for(int i = 0; i < sizeof(wholist); i++)
	{
		//tell_user("huaer",sprintf("wholist[i] = %O\n",wholist[i]));
		send_to_user("who-reply", orig_mud, orig_user, ({ wholist[i] }));
	}
	//send_to_user("who-reply", orig_mud, orig_user, ({ ({"����",0,"hello"}), }));
	//send_to_user("who-reply", orig_mud, orig_user, wholist);
}

static nomask void rcv_who_reply(string orig_mud, string orig_user,
                                 string targ_user, mixed * message)
{
    object p;
    string t1, t2;
    int num;

    p = find_user(targ_user);
    /*if (stringp(message[0])) {
    	if (p) tell(p, message[0]);
    	if (sscanf(message[0], "%sĿǰ��������%d��%s", t1, num, t2) == 3)
    	    LOG_D->log(LOG_I3, sprintf("%d\t%s\t%d\n", time(), orig_mud, num));
    	mudlist_user_num[orig_mud] = num;  	
    }
    else if (!p) 
    	return_error(orig_mud, orig_user, "unk-user",
                     sprintf("Returned who-reply to unknown user '%s'",
                             targ_user));
    else if ( !sizeof(message)||!message[0]||!stringp(message[0]) )
    {
		tell(p, "no infomation availble!\n");
    }
    else {
    	tell(p, message[0]+"\n");
    }*/
	tell(p, "\n");
	foreach(array oneuser in message)
	{
		tell(p, sprintf("%s",oneuser[0]));
	}
}

nomask void count_users() {
    mapping mudlist;
    remove_call_out("count_users");
    mudlist = query_mudlist();
    if (mapp(mudlist)) {
    	string mud;
    	array muds = keys(mudlist);
    	foreach (mud in muds) {
    		mudlist_user_num[mud] = 0; 
                if (stringp(mud) && (mudlist[mud][0] == -1)) 
                    do_who(mud, "");
                     
    	}
    }
    call_out("count_users", 600);
}

nomask mapping get_mudlist_user_num()
{
return mudlist_user_num;
}

/*
private nomask void get_who_list()
{
	object* alluser;
	string name;
	int num;
	//mixed* out = ({});
	array one = allocate(3);
	
	alluser = users();
	num = sizeof(alluser);
	tell_user("huaer",sprintf("num = %d\n",num));
	
	for(int i=0; i<num; i++)
	{
		tell_user("huaer",sprintf("objectp = %d\n",objectp(alluser[i])));
        if ( !objectp(alluser[i]) ) {
			tell_user("huaer","objectp���ﷵ��\n");
			continue;
		}
		tell_user("huaer",sprintf("alluser = %O\n",alluser[i]));
		tell_user("huaer",sprintf("query_body = %O\n",alluser[i]->query_body()));
        if ( !alluser[i]->query_body() ) {
			tell_user("huaer","query_body���ﷵ��\n");
			continue;
		}
        name = alluser[i]->query_body()->in_room_desc();
		tell_user("huaer",sprintf("name = %O\n",name));
        if(!name) name = alluser[i]->query_userid();
 		tell_user("huaer",sprintf("name = %O\n",name));
		if(!(alluser[i]->query_body()->is_visible())) name = "("+name+")";
		tell_user("huaer",sprintf("name = %O\n",name));
		one[0] = sprintf("%s%s\n", CHENGHU_D->query_char_jun_who(alluser[i]->query_body()->query_primary_id()) ,name);
		//one[0] = name;
		tell_user("huaer",sprintf("one[0] = %O\n",one[0]));
		one[1] = 0;
		tell_user("huaer",sprintf("one[1] = %O\n",one[1]));
		one[2] = "hello";
		tell_user("huaer",sprintf("one[2] = %O\n",one[2]));
		tell_user("huaer",sprintf("one = %O\n",one));
		userlist += one;
	}
	
	tell_user("huaer",sprintf("userlist = %O\n",userlist));
	//return out;
}*/