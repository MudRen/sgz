// ǣ��
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob, string who);
int p_id;
int e_id;
string e_name, p_name;
void main(object ob, string who)
{
	int x,y,x2,y2;
	object env;
	string where;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_primary_id());
	e_id=TROOP_D->get_char_troop(who);
	e_name=CHAR_D->get_char(who,"name");
	p_name=CHAR_D->get_char(ob->query_primary_id(),"name");
	where = TROOP_D->get_troop_area(p_id);
	if( !p_id){
                write("ֻ�����ھ��в���ǣ�Ƶз�ʿ����\n");
                return;
        }	
	// In the furture, We have to consider theplayer's ablility
	// add the exp of this jimou, reduce mp, etc.
	if ( !e_id || TROOP_D->get_troop_area(e_id)!=where)
		{ write("�Է����ڴ�ս���ϡ�\n");
			return;
		}
	x =TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];

	x2 = TROOP_D->get_troop_position(e_id)[0];
                y2 = TROOP_D->get_troop_position(e_id)[1];

                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 9 ){
			write("�������̫Զ�޷�ʩ�ơ�\n");
			return;}
                tell(deep_inventory(TROOP_D->find_troop(e_id)),
	"ʿ��һ��������ԭ����"+p_name+"����Ĳ���ʹ��ǣ��֮�ơ�\n",
                        MSG_INDENT);
                // In future, we have to consider effects of the
                // ablility of general, zhenxing, dixing, etc.
                // Now the damage depends only on the No of bowman
	ob->simple_action("$Nʹ��ǣ��֮�ƣ���ͼ�ش�"+e_name+"ʿ����\n");
	ob->start_busy(10, "����æ��ǣ�Ƶз�ʿ���ء�");
	
	call_out("show_result", 5+random(5), ob, who);
}
void show_result(object ob, string who)
{	
	int mora,mora1;
	int rep=0, rep1=0;
	
	rep =random(CHAR_D->get_char(ob->query_primary_id(),"reputation"));
	rep1 =random(CHAR_D->get_char(who,"reputation"));
	rep = rep*2 - rep1 *3;
	ob->stop_busy();
	if( rep>100000)
	{	tell(deep_inventory(TROOP_D->find_troop(e_id)),
                "ʿ��һƬ���ң�ʿ�������\n",
                        MSG_INDENT);
		mora = random (-20) -10;
		mora1 = random (6) +2;
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋ���ȫ�ɹ�������ʿ���ͽ���\n",
                        MSG_INDENT);
	} 
	else
	{     if(rep>10000)
		{
	tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"ʿ��һƬ���ƣ�ʿ���󽵡�\n",
                        MSG_INDENT);	
		mora = random (-10) - 5;
		mora1 = random (3) + 1;
	tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋߴ�ɹ����з�ʿ���󽵡�\n",
                        MSG_INDENT);	
		}
	      else if( rep>1000)
		{
		tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"ʿ����¶ãȻ֮ɫ��ʿ�����͡�\n",
                        MSG_INDENT);
		mora = random(-5) - 1;
		mora1 = 1;
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋ߳ɹ�������ʿ�����͡�\n",
                        MSG_INDENT);
		}	
	      else 
		{
		tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"ʿ��ʶ�Ƶ��˼Ʋߣ�ʿ��������\n",
                        MSG_INDENT);
		mora = random(8) + 3;
		mora1 = random(-8) - 3;
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋ�ʧ�ܣ�����ʿ������������ʿ���½���\n",
                        MSG_INDENT);
		}
	}
	
	TROOP_D->add_morale(p_id,mora1);
	TROOP_D->add_morale(e_id,mora);
	return;
}
