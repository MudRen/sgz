#include <mudlib.h>
#include <ansi.h>
#include </wiz/fire/fire.h>

inherit ROOM;
void setup(){
    set_area("shaoyng_room");
    set_light(50);
    set_brief(""+HIR+"����ͤ"+NOR+"�ҵ�"+HIG+"��԰"+NOR+"");
    set_long(
"\n ������������ˮ���˻��Ծ�Ӣ�ۡ�
 �Ƿǳɰ�תͷ�գ���ɽ�����ڣ�����Ϧ���졣
 �׷����Խ���ϣ��߿����´��硣
 һ���Ǿ�ϲ��꣺�Ž�����£�����Ц̸�С�\n
 ���������������գ������µµ����������ǿ������
 ֻ��һֻ�Ϻ��������Ϸɽ�������������ϡ�����������\n");
    set_exits( (["out" :  FROOMPATH+"vzhu_lin.c",
                 "dating" : __DIR__+"taoyuanting.c",
                 "houyuan" :  __DIR__+"houyuan.c",
                ]) );
}


