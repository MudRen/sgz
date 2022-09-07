// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OUTDOOR_ROOM;

void obj_arrived(object ob) {
    if (ob->get_size() >= VERY_LARGE) 
      {
     if(!ob->is_living())
        receive_inside_msg(ob->short() + "����ˮ�У�ˮ���Ľ���\n");
        return;
      }
    receive_inside_msg(ob->short() + "����ˮ�У��ܿ죬�ڷ��ڵ��˻�����ʧ����Ӱ��\n");
    destruct(ob);
}

void setup()
{
    string m = "�����ɽ�ڹ��ڶ��ͣ����޷��ʵǡ�\n";
    string o = "��ᱻ�����ģ�\n";

  set_brief("�ⶴ");
  set_area ("pirate");
  set_long("����վ�ڼ�ϥ���ˮ���Զ�����������Ǹ�Сɽ����"
           "�������ҵس����ɽ�ڡ�Ҫ�뱣��ƽ�ⶼʮ�����ѡ��ذ���ɽ��"
           "��������Щ��յأ��γ�һ������ɳ̲��");
  set_exits( ([
               "in" : "../caves/grotto.c",
               "north" : "../caves/grotto.c",
               "east" : "rocky_beach.c",
               "west" : "sandy_beach.c",
               "northeast" :  m,
               "northwest" :  m,
               "south" : o,
               "southeast" : o,
               "southwest" : o,
               ]) );

  add_item( "surf", "water",  "����", "��ˮ",
           ([
             "adjs": "fierce",
             "look": "��ͷ�ܴ���ֻ�о�����֤�������ߡ�",
             "wade": "������ˮ���ء�",
             "swim": "��ᱻ�����ģ�",
             ]));

  add_item( "cave", "tiny cave", "Сɽ��", "ɽ��", 
                "������Ƕȣ��㿴�������١�");

  add_item( "ocean", "��", "����", ([
           "look" :  "�㾡���뿴�庣����һͷ��ʲô�������ǰ׷�����"
                     "����󿴵�Զ����ʲô�������������̫Զ���᲻��"
                     "���Ҵ��أ�",
           "wade":   "������ˮ���ء�",
           "swim":   "��ᱻ�����ģ�",
             ]));

  add_item( "mountains", "steep mountains", "ɽ��",
            ([
              "climb" : m,
              "look" : m,
             ]));

  add_item( "sand", "beach" , "ɳ̲", "���ɳ̲�Ƕ�����ġ�" );

  set_hidden_exits("northeast","northwest","south","southeast","southwest", 
                   "in");

  add_hook("object_arrived", (: obj_arrived :));
}


void do_enter(string s)
{
  if(s == "cave")
    this_body()->do_game_command("in");
  else
    write(this_body()->nonsense());
}


mixed direct_enter_obj()
{
  return 1;
}
