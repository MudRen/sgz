// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CONTAINER;
inherit M_OPENABLE;
inherit M_READABLE;
inherit M_GETTABLE;

void setup() {
    
    set_adj("�޴��", "�䱦");
    set_unit("��");
    set_id("chest", "����");
    set_untouched_desc("�ڶ�����һ�������ӡ�");
    set_long("�����Ϻܶ�ɳ�������������Щ�֡�\n");
    set_gettable(1);
    set_objects( ([
                   ]) );
    set_size(LARGE);
    set_max_capacity(LARGE);
    set_closed(1);
    set_text("������д��һ��Ӣ��ʫ��\n"
             "\tI used to have a treasure chest.\n"
             "\tIt got so heavy that I had to rest.\n"
             "\tI let it slip away from me,\n"
             "\tBut I didn't need it anyway,\n"
             "\tSo I let it slip away...\n");
}

            
