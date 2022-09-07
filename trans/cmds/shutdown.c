/* Do not remove the headers from this file! see /USAGE for more info. */

/*
**  /trans/cmds/shutdown - shuts the game down imediately or starts the
**                         shutdown daemon.
**
**  960614 - Alexus adds timed shutdown daemon support
*/
#include <log.h>

inherit CMD;

static void do_shutdown(string s)
{
    if (!check_privilege(1)) 	//"Admin:system"
	{
        LOG_D->log(LOG_SHUTDOWN,
                   sprintf("do_shutdown() failed due to insufficient privilege (possibly due to being called directly) at %s\n", ctime(time())));
        return;
    }
    
    LOG_D->log(LOG_SHUTDOWN,
      sprintf("SHUTDOWN executed at %s [%s]\n",
        ctime(time()), s));

    foreach (object ob in users())
        catch(ob->quit());
 
    unguarded(1, (: shutdown :));
}

nomask void count_down(int num, string s) {
    string time;
    int interval;
    if(!num)
    {
        tell(users(), "ϵͳ���ĸ����㣺ϵͳ���� �ӣȣգ� �ģϣףΣ�\n");
        do_shutdown(s);
        return;
    }
    if (num >= 60) {
    	time = CHINESE_D->chinese_number(num/60) + "����";
    	if (num == 60) interval = 30;
    	else interval = 60;
    }
    else {
    	time = CHINESE_D->chinese_number(num) + "����";
    	if (num > 10) interval = 10;
    	else interval = 1;
    }
    CHANNEL_D->deliver_tell("gossip","���",
       "����ҹ�����󣬵��Ǵ��죬���ʱ������֮�ף���ر���" +
       time + "�����䣬̾쨣���쨡�");
    
    call_out("count_down", interval, num - interval, s);
}

private void main(mixed args, mapping flags)
{
    int num;
    string s;
     
    if ( !check_privilege(1) )	//ԭ����"Admin:system"
    {
        outf("����Ϊ����˭ѽ���㲻���ʸ�\n");
        return;
    }

    s = implode(args[0], " ");

    // handle cancelation checking first!
    if(flags["c"]) {
        if (remove_call_out("count_down") == -1) {
            write("Ŀǰû�� shutdown �Ľ����������С�\n");
            return;
        }
        LOG_D->log(LOG_SHUTDOWN,
                   sprintf( "Shutdown cancelled %s by %s [%s]\n",
                            ctime(time()), this_body()->query_userid(), s));
        tell(users(), "ϵͳ���ĸ����㣺ϵͳ �ӣȣգ� �ģϣף� ����ֹ�ˡ�\n");
        return;
    }

    // Check to see if a -t # switch was given.  If so, don't shut down,
    // just start the shutdown daemon.
    if(flags["t"]) {
        LOG_D->log(LOG_SHUTDOWN,
                   sprintf("Shutdown started %s by %s [%s]\n",
                           ctime(time()), this_body()->query_userid(), s));
        num = to_int(flags["t"]);
        count_down(num * 60, s);
        write("ϵͳ shutdown ���̿�ʼ...\n");
        return;
    }
    LOG_D->log(LOG_SHUTDOWN,
               sprintf("Immediate shutdown requested by %s\n",
                       this_user()->query_userid()));
    tell(users(), "ϵͳ���ĸ����㣺ϵͳ���� �ӣȣգ� �ģϣףΣ�\n");
    do_shutdown(s);
}

