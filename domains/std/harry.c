// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;

string *query_channel_list() {
    return ({ "plyr_gossip" });
}

void setup()
{
    set_name("Harry", "����");
    set_gender(1);
    set_proper_name("�Ȱ��Ĺ���");
    set_in_room_desc("�Ȱ��Ĺ���(harry)");
    add_id("dude");
    set_long("���ﳤ�û�����...");
    set_actions( 10, ({
	"say ���ڵ�ʲô�أ�",
	    "say ��λ�����ˣ�",
	    "say �Ҳ�ϲ������...",
	    "say �Ҳ�ϲ����ѩ��",
	    "say �Ҳ�ϲ���꼾...",
	    "say ����˭��",
	    "say ����ô����������",
	    "say ������������أ�",
	    "say �����������Ǻ�...���Ǻã�",
	    "smile",
	    "lsfbog",
	    "ack",
//      "chan gossip Is this thing on?",
	    "rock"
	    }) );
    add_pattern("%s���ֵ�΢Ц�š�", (: $1 != "�Ȱ��Ĺ���" ? "smile" : 0 :));
    add_pattern("%s has left the game.", (: "say Ϊʲô" + $1
					  + "�뿪����Ϸ��" :));
    add_pattern("%sʰ��%s��", (: "say Ϊʲô" + $1
				+ "Ҫ����" + $2 + "��" :));
    add_pattern("%s����%s��", (: "say " + $1
				 + "Ϊʲô��" + $2 + "���ڵ��ϣ�" :));
    add_pattern("%s kicks you.", (: "kick " + $1 :));
    add_pattern("%s kisses you.", "blush");
    add_pattern("%s���˵�ͷ��", function() {
	respond("nod sol*");
	respond("say �Ҵ����ʲô��Ҫ������");
    } );
    add_pattern("%s������Ц��", "say ����ʲô��Ц������");
    add_pattern("%s chuckles.", "smirk");
    add_pattern("%s boggles.", "bog");
    add_pattern("%s���˹�����", (: "say " + $1 + "����ã��ǳ����˼����㣡" :) );
    add_pattern("%s��%s�뿪�ˡ�", (: "go " + $2 :));

    // This subrule says that the right hand side will give us a string
    // we should sprintf() the name into, with the additional stipulation
    // that we ignore other Harry's
    add_pattern("%s˵����%s.", (: ($2 && $1 != "����")
				 ? sprintf($2, $1)
				 : 0 :),
		0, "say_rule");
    add_sub_pattern("say_rule", "yes", "say �Ҳ�ͬ�⡣");
    add_sub_pattern("say_rule", "right", "no", "say �Ҳ�ͬ�⡣");
    add_sub_pattern("say_rule", "shut up",
                    "say ��ƾʲô����ס�죿");
    add_sub_pattern("say_rule", 
		    "%shello%s", "say �һᡢ�һᣡ");
    add_sub_pattern("say_rule", 
		    "%sLPC%s", "turing %s");
    add_sub_pattern("say_rule", 
                    "%sstay here%s", "say �Ǻð�...");
    add_sub_pattern("say_rule", 
                    "%snot follow%s", "say �Ǻð�...");
    add_sub_pattern("say_rule", 
                    "%sget lost%s", "say �Ǻð�...");
    add_sub_pattern("say_rule", 
                    "%s", (: random(5) == 0 
			   ? "say ��Ϊʲô˵'" + $1 + "'???" 
			   : 0 :));
}
