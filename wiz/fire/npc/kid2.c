// kid1.c "��Ƥ��С�к�"
#include <mudlib.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
void setup()
{
    set_name("kid", "С�к�");
    set_gender(1);
    set_proper_name("��Ƥ��С�к�");
    set_in_room_desc("һ����Ƥ��С�к�(kid)");
    add_id("boy");
    set_long("��������ģ����Ǹմ������������. . .");
    set_actions( 2, ({
        "say ���ڵ�ʲô�أ�",
            "say ���������",
            "say �һ��ס���������������󲿷�ʱ�䶼��������ϡ�",
            "say Է������Ǵ�����Ư���Ĺ�����������",
            "say ���ֵļ��ڴ��Ӷ�ͷ��",
            "say ����˭��",
            "say ����ô����������",
            "say ������������أ�",
            "say ������ɽ��������вƱ�",
            "xixi",
            "jump",
            "kick",
                "escape"
            }) );
    add_pattern("%sһ���ߵ���%s��",function(){ 
	respond("ah");
//	respond((: "say ��"+$1 :));
//	respond((: "say //��Ƥ��С�к�һ���ߵ�"+$1+"��ƨ���ϣ��ߵ�"+$1+"��Ƥ��һ��������Ȧ��":)); 
} );
    add_pattern("%s�����̾�˿�����","say �һ���ϲ��̾�������������һ��ѽ
��");
    add_pattern("%s�þ�ȫ������ͷ����ȥ%s", function() {
        respond("pain");
        respond("say ΪʲôҪ���ң���");
          respond("cry");
    } );
}
