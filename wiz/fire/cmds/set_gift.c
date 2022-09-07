//***********************************************************************
// set_gift.c  by fire on Dec 20 1997
#include <menu.h>
#include <sanguo.h>
inherit MENUS;
inherit M_ACCESS;
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM goto_main_menu_item;
MENU_ITEM main_seperator;
MENU_ITEM blank_seperator;
MENU_ITEM help_item;
int p_wuli,p_zhimou,p_meili;
void accept_gift()
{
	this_body()->init_sg_gifts(p_wuli,p_zhimou,p_meili);
}
void view_dir(int i)
{
  MENU m;
  MENU_ITEM item;
  string p_lx;
  string p_disp="dfasfda";
  int p_pointleft,p_ran;
  switch(i)
  {
	case 1:
		p_lx="Ӣ����ս�͡�";
		p_wuli=20;
		p_zhimou=10;
		p_meili=10;
		break;
	case 2:
	       	p_lx="���Ƕ�ı�͡�";
		p_wuli=10;
		p_zhimou=20;
		p_meili=10;
		break;
	case 3:
		p_lx="ʶ�������͡�";
		p_wuli=10;
		p_zhimou=10;
		p_meili=20;
		break;
	case 4:
		p_lx="����ȫ���͡�";
		p_wuli=14;
		p_zhimou=14;
		p_meili=12;		
		break;
   }
   m= new_menu("�佫ѡ��:"+p_lx);
   p_pointleft=60-p_wuli-p_zhimou-p_meili;
   while(p_pointleft)
   {
	p_ran=random(3);
	switch(p_ran)
	{
		case 0:
			if(p_wuli<30)
			{
				p_wuli++;
				p_pointleft--;
			}
			break;
		case 1:
			if(p_zhimou<30)
			{
				p_zhimou++;
				p_pointleft--;
			}
			break;
	
		case 2:
			if(p_meili<30)
			{
				p_meili++;
				p_pointleft--;
			}
			break;
	}
    }
  p_disp=sprintf("                ������%d     ��ı��%d      ������%d",p_wuli,p_zhimou,p_meili);
	
  item=new_menu_item("���ܴ��츳��",(: accept_gift() :),"r");
  add_menu_item(m, main_seperator);
//  add_menu_item(m, blank_seperator);
  add_menu_item(m, new_seperator("�����츳ֵ������"));
  add_menu_item(m, new_seperator(p_disp));
  add_menu_item(m, item);
  add_menu_item(m, blank_seperator);
  add_menu_item(m, main_seperator);
  add_menu_item(m, blank_seperator);
  add_menu_item(m, help_item);  
  add_menu_item(m, goto_main_menu_item);
  add_menu_item(m, quit_item);
  add_menu_item(m, blank_seperator);
//  add_menu_item (toplevel, main_seperator);
  allow_empty_selection(m);
//  set_no_match_function(m,(:quit_if_cr:));
  set_menu_prompt (m, "r�����ܴ��츳��h��������m�������ϼ�ѡ����q���˳��� ");
  previous_menu = current_menu;
  current_menu = m;
}
void gift_set_help()
{
        write(read_file(HELP_GIFT));
	return;
}
void create()
{
  toplevel      = new_menu("���������塷����츳����"); 
  quit_item = new_menu_item("�˳�", (:quit_menu_application:), "q");
  goto_main_menu_item =new_menu_item("����ѡ��", toplevel, "m");
  help_item = new_menu_item("����", (: gift_set_help() :),  "h");
  main_seperator = 
    new_seperator("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
                  "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  blank_seperator = new_seperator("");
  // Add items to the toplevel (main) menu.  
  add_menu_item (toplevel, new_seperator("��ѡ���ɫ���ͣ�"));
  add_menu_item (toplevel, main_seperator);
  add_menu_item(toplevel,new_menu_item("Ӣ����ս�͡�",(: view_dir(1) :)));
  add_menu_item(toplevel,new_menu_item("���Ƕ�ı�͡�",(: view_dir(2) :)));
  add_menu_item(toplevel,new_menu_item("ʶ�������͡�",(: view_dir(3) :)));
  add_menu_item(toplevel,new_menu_item("����ȫ���͡�",(: view_dir(4) :)));
  add_menu_item(toplevel,blank_seperator);
  add_menu_item (toplevel, main_seperator);
  add_menu_item (toplevel, help_item);
  add_menu_item (toplevel, quit_item);
  add_menu_item (toplevel, blank_seperator);
  add_menu_item (toplevel, main_seperator);
  set_menu_prompt (toplevel, "�����ּ�������Ӧ��ģ��ѡ���츳��h��������q���˳��� ");
  allow_empty_selection(toplevel);
//  set_no_match_function(toplevel,(:quit_if_cr:));
  }
void start_menu()
{
  init_menu_application(toplevel);
}
