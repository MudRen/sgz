// this room is created by initarea.c
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"������վ"+"%^RESET%^");
set_long("
    ��վ��һ���ª����é�ݺ�ľ������������������ôִֵ���
��Χ��Ȩ����Ϊ��������վ�õ�������ط��������档һ��վ��
һ��С���ӣ�����ȥ���Ǹϴ󳵵ģ��������ȥʲô�ط��Ļ�������
��������\n\n");
set_exits( ([
"west":"/a/huayin/nancunkou.c",
 ]));
set_objects( (["/sgdomain/yizhan/mafu.c" : 1]) );
set_objects( (["/wiz/ljty/npc/mafu.c" : 1]) );
}
