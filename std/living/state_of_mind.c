// Updated by stefan on 10 Jan 1997
// update by tset on 13 Dec 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

//### This stuff needs to be linked to affect commands.
//### some of these also should probably be bits
private static int stunned, asleep, chance, prone; // fire move busy from static to normal variable
private string busy_msg; // private static string busy_msg;
private int busy;

int query_ghost() {
    return 0;
}

int query_asleep() {
    return asleep;
}

int query_stunned() {
    return stunned;
}

int query_prone() {
    return prone;
}

mixed query_busy(int shown) {
    if ( !shown ) return busy;
    if ( busy > time() )
        return busy_msg + "����ʣ"+ CHINESE_D->chinese_period(busy - time());
    else
        return "��æ��";
}

int lie_down() {
    prone = 1;
    return 1;
}

int get_up() {
    prone = 0;
    return 1;
}

/* Call the following to make your monster do the appropriate thing */

//:FUNCTION stun
//Stun us
void stun() {
    stunned = time() + 5;
}

//:FUNCTION wake_up
//Wake up after being asleep or knocked out
void wake_up() {
    if (asleep) {
        asleep = 0;
        stunned = time() + 5;
    }
}

//:FUNCTION knock_out
//Knock us out
void knock_out() {
    asleep = 1;
    chance = 0;
}

//:FUNCTION start_busy
//Starts busy time for a given period
void start_busy(int n, mixed msg) 
{
    if(busy<(time()+n))
    busy = time() + n;
    if (!msg)
        msg = "��������æ�ţ�";
    if (pointerp(msg))  
        busy_msg = msg[random(sizeof(msg))];
    else
        busy_msg = msg;
    if ( busy_msg[<1] != '\n' )
        busy_msg += "\n";
}

//:FUNCTION stop_busy
//Interrupts busy time
void stop_busy() {
    busy = time();
}

// Warning: Elsewhere we rely on the fact that if urgent == 0, nothing
// is printed, and a complete sentence is returned.
mixed check_condition(int urgent) {
    if (query_ghost()) {
        stunned = 0;
        asleep = 0;
        return 0;
    }

    if (query_prone())
        return "��Ҫ��վ������\n";//"You will have to get up first.\n";
    
    if (urgent && stunned > time())
        return //"$N $vare still recovering from that last blow, ";
               "$N��û�д��ش������ѹ�����";

    if (asleep) {
        if (urgent) {
            if (random(5)<=chance++) {
                wake_up();
//FIXME: print_result takes a class combat_result array now.
#if 0
                print_result("wakeup");
#endif
            } else
                return "��ƴ��Ҫ�ѹ�����������ʧ���ˡ�\n";
        } else {                                          
            return "������˯���С�\n";
        }
    }

    if (busy > time())
	return busy_msg;

    return 0;
}
