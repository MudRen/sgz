#include <ansi.h>

inherit INDOOR_ROOM;
static string * nogo = ({
"\n$Ņ����������ȥ����ԥ��һ�£��ַ����ˡ�\n\n",
"\n������������һ������������գ�$N���������ö��ˡ�\n\n",
});
string * going = ({ "��һ��","ͷҲ����","һ������", });
int do_go_backdoor() {
    object r;
    if( !wizardp(this_body()) ) {
        this_body()->simple_action(nogo[random(sizeof(nogo))]+"\n");
        return 1;
    }
    r = 
load_object(query_exits()[query_exit_directions(1)[random(sizeof(query_exit_directions(
1)))]]);
    this_body()->simple_action("\n$N"+going[random(sizeof(going))]+
        "������ų�ȥ�������������\n\n");
    this_body()->move(r);
    tell_environment(this_body(), sprintf("\n%sʧ�����ǵ����˹�����\n\n",
        this_body()->short()), 0, ({ this_body() }) );
    this_body()->force_look();
    return 1;
}

void setup(){
    set_area("westside");
    set_light(50);
        set_brief(""+YEL+"Ʈѩ�Ĺ�����"+NOR+"");
    set_long("
    ������Ʈѩ�Ĺ����ң�����Ƚϼ򵥣����������Գ�һ�ָ߹�����ʡ�
��������ʱ������ʹ����Ȼ����һ�ֳ羴�ĸо������ˣ����Ǹ������ˣ�
Ʈѩ��ϲ���˴�£���ģ������������ȥ��Ҫ���������ˣ����ܻ�ɱ��
��ġ�С�ĵ�á�
\n\n"
);
    set_exits( ([
        "goout" : "/sgdomain/museum/yard.c",
        "fire" : "/wiz/fire/workroom.c",
        "row" : "/wiz/row/workroom.c",
        "suicide" : "/wiz/suicide/workroom.c",
        "ice" : "/wiz/ice/workroom.c",
        "palace" : "/sgdomain/area/emp/dadi.c",
        "bwdh" : "/sgdomain/event/ev_bwdh/bw_room.c",
          "west" : "/wiz/ghyg/bedroom.c",
        "caolu" : "/a/huayin/vhall.c",
        "luoyang" : "/a/luoyang/ly_ly.c",
    ]) );
    set_enter_msg("house","\n$N�ƿ��ţ�������ŵ����˽�����\n\n");
    set_enter_msg("goup","\n$N����ʧ��شӴ��������˳�����\n\n");
    set_objects( ([
__DIR__"npc/newslady.c":1,
__DIR__"npc/lch.c":1,
__DIR__"npc/piaox.c":1,
    ]) );
}
