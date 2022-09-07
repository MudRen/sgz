#include <ansi.h>
#include <sanguo.h>
// m_sggift.c by fire on Dec 20 1997
private int sg_wuli;  // ���� from 10 to 30 with special weapon can be higher
private int sg_zhimou;  // ��ı as above this are orignal one, can't changed
private int sg_meili; // ����
private int sg_exp; // this will increase during fight and . . .
private int sg_shengwang; // ���� ; very important to judge player's level
private int sg_age; // ����;
private int sg_shouming; // ���� = max age over than that will die
private int sg_rongmao; // ��ò from 10 to 30;
private int sg_cur_hp; //  if one is
private int sg_cur_max_hp; // from 100 and increase every year; before 30
                        // decrease after 50
private int sg_max_hp;  // the real max hp
private int sg_food;  // ����
private int sg_junzi; // ����
private int sg_bing_number;  // ʿ����
private int sg_bing_max ;   //��������  ����ֵ
private int sg_bing_shiqi;  // ʿ��
private int sg_bing_type;  // ����  0 ���� 1 ��� 2 ����
private int sg_fight_value;  // ս����
private int sg_rank; // ��ְ
private string sg_zi;   // ��
static int is_hp_heal;  // 1 when auto heal needed 0 on need
#define SG_DEFAULT 20
#define SG_RANGE 6
// other information
nomask void set_sg_rongmao(int p_rongmao)
{
	sg_rongmao=p_rongmao;
}
nomask int query_sg_rongmao()
{
	if(!sg_rongmao)
		sg_rongmao=random(21)+10;
	return sg_rongmao;
}
nomask void set_sg_zi(string p_zi)
{
	sg_zi=p_zi;
}
nomask string query_sg_zi()
{
	return sg_zi;
}
//*******************************************************
nomask void set_sg_food(int i)
{
        sg_food=i;
}       
nomask void set_sg_junzi(int i)
{
        sg_junzi=i;
}       
nomask int query_sg_food()
{
        return sg_food;
}
nomask int query_sg_junzi()
{
        return sg_junzi;
}
// *******************************************************
nomask void set_bing_number(int i)
{
        sg_bing_number=i;
}       
nomask void set_bing_shiqi(int i)
{
        sg_bing_shiqi=i;
}
nomask void set_bing_type(int i)
{
        sg_bing_type=i;
}
nomask int query_bing_number()
{
        return sg_bing_number;
}
nomask int query_bing_max()
{
        int p_tmp;
        p_tmp=this_object()->query_sk_level("sk_wuli");
        if(this_object()->query_sk_level("sk_zhimou")>p_tmp)
                p_tmp=this_object()->query_sk_level("sk_zhimou");
        if(this_object()->query_sk_level("sk_meili")>p_tmp)
                p_tmp=this_object()->query_sk_level("sk_meili");
        return p_tmp*100;
}
nomask int query_bing_shiqi()
{
        if (!sg_bing_number)
                return 0;
        return sg_bing_shiqi;
}
nomask string query_bing_type()
{
        if(!sg_bing_number)
        {
                return "----";
        }
        switch(sg_bing_type)
        {
                case 0:
                        return "����";
                case 1:
                        return "���";
                case 2:
                        return "����";
                default: 
                        return "δ֪";
        }
        return "δ֪";
}
nomask int query_fight_value()  // this part mast be cauculte carefully
{
        int p_tmp;
        p_tmp=(this_object()->query_sk_level("sk_wuli"))*10;
        p_tmp=p_tmp+
        (sg_bing_number*sg_bing_shiqi*
(this_object()->query_sk_level("sk_wuli")+
this_object()->query_sk_level("sk_zhimou")+
this_object()->query_sk_level("sk_meili")))/3000;
        return p_tmp;
}
// ���� and ����*****************************************
nomask int query_age()
{
        return sg_age;
}
nomask int query_shouming()
{
        return sg_shouming;
}
void set_age(int i)
{
        sg_age=i;
}
void set_shouming(int i)
{
        sg_shouming=i;
}
// ���� ****************************************************
void auto_heal()
{
	int p_wuli;
	if(sg_cur_hp==sg_max_hp)
	{
		is_hp_heal=0;
		return;
	}
	else
	{
		p_wuli=this_object()->query_sk_level("sk_wuli");
		p_wuli=p_wuli/2;
		if(sg_cur_hp<sg_cur_max_hp)
		{
			sg_cur_hp+=p_wuli;
			if (sg_cur_hp>sg_cur_max_hp)
				sg_cur_hp=sg_cur_max_hp;
			if((sg_cur_max_hp<sg_max_hp) && 
			   ((sg_cur_max_hp-sg_cur_hp) < 3))
				sg_cur_max_hp++;
		}
		call_out((: auto_heal :), 30);	
	}
}
void check_need_heal()
{
	if (sg_cur_max_hp>sg_max_hp)
		sg_cur_max_hp=sg_max_hp;
	if (sg_cur_hp>sg_cur_max_hp)
		sg_cur_hp=sg_cur_max_hp;
	if (sg_cur_hp==sg_max_hp)
	{
		is_hp_heal=0;
	}
	else
	{
		if (is_hp_heal==1) // already auto heal
			return;
		else
		{
			is_hp_heal=1;
			call_out((: auto_heal :), 30);	
		}
	}
}
int query_cur_hp()
{
	check_need_heal();
        return sg_cur_hp;       
}
int query_cur_max_hp()
{
	check_need_heal();
        return sg_cur_max_hp;   
}
int query_sg_max_hp()
{
	check_need_heal();
        return sg_max_hp;
}
void set_cur_hp(int i)
{
        sg_cur_hp=i;
	check_need_heal();
		
}
void set_cur_max_hp(int i)
{
        sg_cur_max_hp=i;
	check_need_heal();
}
void set_sg_max_hp(int i)
{
        sg_max_hp=i;
	check_need_heal();
}
nomask void init_hp()
{
        if(sg_age)
        {
                write("���ܴ����������䡣\n");
        }
	else
	{
        	set_age(14);
	        set_shouming(70+random(30));
	}
        set_cur_hp(100);
        set_cur_max_hp(100);
        set_sg_max_hp(100);
        set_bing_number(0);
        set_bing_shiqi(0);
        set_bing_type(0);
        return;
}
// gift *****************************************************
nomask int query_wuli_pure()
{
    return sg_wuli;
}
nomask int query_zhimou_pure()
{
    return sg_zhimou;
}
nomask int query_meili_pure()
{
    return sg_meili;
}
nomask void init_sg_gifts(int p_wuli,int p_zhimou,int p_meili)
{
    if ((p_wuli+p_zhimou+p_meili)!=(SG_DEFAULT*3))
        error("* �Ƿ����츳����ֵ\n");
    sg_wuli=p_wuli;
    sg_zhimou=p_zhimou;
    sg_meili=p_meili;
    write("�츳���óɹ�\n");
}
// used for hp system
// ***************************for ���� *******************************
void set_shengwang(int i)
{	
	if(i<0)
		i=0;
	if(i>10000000)
		i=10000000;
	sg_shengwang=i;
}
int query_shengwang_int()
{
	return sg_shengwang;
}
string query_shengwang_str()
{
	if(sg_shengwang<10)
		return "ĬĬ����" ;
	if(sg_shengwang<100)
		return RED + "С������"+NOR ;
	if(sg_shengwang<1000)
 		return YEL + "��¶��â" +NOR;
	if(sg_shengwang<10000)
		return GRN + "�ư�һ��"+NOR ;
	if(sg_shengwang<100000)
		return HIY + "��¹��ԭ"+NOR ;
	if(sg_shengwang<1000000)
		return HIR + "�ʶ�����"+NOR ;
	if(sg_shengwang<10000000)
		return HIG + "��������"+NOR ;
	return HIC+"һͳ����"+NOR ;
	
}
//******************* RANK ****************
void set_sg_rank(int i)
{
	sg_rank=i;
}
int query_sg_rank()
{
	return sg_rank;
}
string query_guanzhi()
{
	return CHENGHU_D->query_rank_str(sg_rank);
}
int query_is_junzhu()   // �Ƿ����
{
	if(sg_rank==R_KING)
		return 1;
	return 0;
}
int query_is_jiangjun() // �Ƿ񽫾�
{
	if((sg_rank>1)&&(sg_rank<100))
		return 1;
	return 0;
}
int query_is_guan() // �Ƿ�Ϊ��
{
	if(sg_rank>=100)
		return 1;
	return 0;
}
mixed direct_hp_liv(object liv) 
{
	return 1;
}
mixed direct_follow_liv(object liv)
{
	return 1;
}
mixed direct_score_liv(object liv)
{
	return 1;
}
