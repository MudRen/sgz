// memorial plank.c ��λ by row
// for wan especially

#include <ansi.h>
#include <mudlib.h>
inherit OBJ;
inherit M_INPUT;

void setup()
{
	set_unit("��");
	set_id("plank","%^H_YELLOW%^��λ%^RESET%^");
	set_long(
"               %^YELLOW%^����������%^RESET%^\n"+
"               %^YELLOW%^��  %^H_RED%^��%^RESET%^  %^YELLOW%^��%^RESET%^\n"+
"               %^YELLOW%^��  %^H_RED%^��%^RESET%^  %^YELLOW%^��%^RESET%^\n"+
"               %^YELLOW%^��  %^H_RED%^��%^RESET%^  %^YELLOW%^��%^RESET%^\n"+
"               %^YELLOW%^��  %^H_RED%^�%^RESET%^  %^YELLOW%^��%^RESET%^\n"+
"               %^YELLOW%^��  %^H_RED%^Ө%^RESET%^  %^YELLOW%^��%^RESET%^\n"+
"               %^YELLOW%^��  %^H_RED%^ӯ%^RESET%^  %^YELLOW%^��%^RESET%^\n"+
"               %^YELLOW%^��  %^H_RED%^֮%^RESET%^  %^YELLOW%^��%^RESET%^\n"+
"               %^YELLOW%^��  %^H_RED%^λ%^RESET%^  %^YELLOW%^��%^RESET%^\n"+
"           %^YELLOW%^�����ة������ة���%^RESET%^\n"+
"           %^YELLOW%^�� %^H_CYAN%^�ã���������%^RESET%^ %^YELLOW%^��%^RESET%^\n"+
"           %^YELLOW%^������������������%^RESET%^\n");
	set_in_room_desc("һ����λ��(plank)��������������˵����䡣\n");
}
