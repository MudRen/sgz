// created by ice on Jul 21 1999
#include <ansi.h>
inherit FURNITURE;
void setup()
{
  set_id("sign", HIY+"��ʾ"+NOR);
  set_in_room_desc("һ��Ǯׯ��"+HIY+"��ʾ"+NOR+"��(sign)");
  set_long("��Ǯ����%^H_CYAN%^ deposit %^H_YELLOW%^<amount> %^H_MAGENTA%^<type>%^RESET%^��
ȡǮ����%^H_CYAN%^ withdraw %^H_YELLOW%^<amount> %^H_MAGENTA%^<type>%^RESET%^��
��Աȡٺ»������ %^H_CYAN%^withdraw salary%^RESET%^ �����ٺ��ת��˽���˻�����Ȼ���Ǯׯ��ȡ��
��ʹ�� %^H_CYAN%^money%^RESET%^ ��ѯ�Լ��Ĳ���״����
���������ս��Ϊ���ϱ�Ǯׯ���棬ÿ����Ǯ����ȡ�����ѡ�\n");
}
