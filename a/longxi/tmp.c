// this room is created by initarea.c
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"¤����վ"+"%^RESET%^");
set_long("
    ������¤����վ,��վ��������������
�ݵĽ�ͨ����,��վ�õ�������ط��������档һ��վ
��һ��С���ӣ�����ȥ���Ǹϴ󳵵ģ��������ȥʲô��
���Ļ�������������ask ma fu about �ط�id(changan)��\n\n");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([ /* sizeof() == 1 */
  "west" : "/a/longxi/lx_dounanjie1.c",
]));

}
