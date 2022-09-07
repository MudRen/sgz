/* workroom.c
** Coded by ����@����
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
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
    r = load_object(query_exits()[query_exit_directions(1)[random(sizeof(query_exit_directions(1)))]]);
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
        set_brief(""+YEL+"�����Сľ��"+NOR+"");
    set_long("
    Сľ����İ���ܼ򵥣�һ��С�輸��һ�ų����Ĵ�ɳ����û��
����, ���ݵ������ƺ�ϲ��ϯ�ض�����͸��һ�����ʽ���ӣ�����
����һ���ɰ���С��Ӿ���������������֮�¡�
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
        "caolu" : "/sgdomain/area/guan/huayin/vhall.c",
        "luoyang" : "/sgdomain/area/cities/luoyang/ly_ly.c",
    ]) );
    set_hidden_exits("fire", "row", "suicide", "ice", "bwdh", "palace", "caolu", "luoyang");
    set_enter_msg("house","\n$N�ƿ��ţ�������ŵ����˽�����\n\n");
    set_enter_msg("goup","\n$N����ʧ��شӴ��������˳�����\n\n");
    set_objects( ([
"/wiz/ice/obj/furniture/sofa.c":1,
    ]) );
}
