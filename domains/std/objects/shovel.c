// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_DIGGER;
inherit M_GETTABLE;
inherit M_INPUT;

void setup()
{
  set_adj("����");
  set_unit("��");
  set_id("shovel", "����");
  set_long ("���Ǹ�С���ϲ��ӡ�\n");
  set_size (SMALL);
  set_gettable(1);
}
