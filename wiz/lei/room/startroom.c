// startroom.c
inherit ROOM;

void create()
{
    set("short","�ݺ�յ�");
    set("long",@TEXT
      ���ǰ��ɿ�ջ�����һ���յ�,�������µ�����һ�ִ���,������ô�������
      ���������������Զ��,�������������,�Ϳ��Ե�Ұ��ȥ��.
      TEXT);
  set("exit",([
               "west" : __DIR__"sroad1",
"east" : __DIR__"startroom",
               ]));
  set("outdoors","snow");
  setup();
  replace_program(ROOM);
}
