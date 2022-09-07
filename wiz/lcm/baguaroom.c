#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

private mapping exits;

void bind_exit(string direction, object room, int both);
void setexits();


void setup()
{
    set_area("lcm_room");
    set_light(50);
    set_brief(""+YEL+"����"+NOR+"��");
    set_long(
"\n�����þ�˵�����������󷨵ľ��ѳ�����
������仯��ˣ����ص��ǵ������ױ���ס��");
    set_exits( (["up" : "/wiz/lcm/lcmroom.c",
                 ]) );              
}

string opposite(string direction)
{
    switch(direction)
    {
        case "north": return "south";
        case "east": return "west";
        case "south": return "north";
        case "west": return "east";
        case "northeast": return "southwest";
        case "southeast": return "northwest";
        case "southwest": return "northeast";
        case "northwest": return "southeast";
        case "up": return "down";
        case "down": return "up";
        default: return "";
    }
}

//void bind_exit(string direction, object room, status both)
void bind_exit(string direction, object room, int both)
{
//    if (exits[direction]==0) 
//    {
        exits[direction] = room;
//        set_exits(exits);
        if (both)
            room->bind_exit(opposite(direction), this_object(), 0);
//    }
}

void setexits()
{
    set_exits(exits);
}
