// skill_reg.c write by fire on Dec 26 
#include <mudlib.h>
#include <config.h>
#include <classes.h>
#include <ansi.h>
#include <sanguo.h>
inherit CMD;
inherit CLASS_SG_SKILL;
	
class sg_skill_reg p_sk;
void def_skill(string skill)
{
	switch(skill)
	{
		case "sk_wuli" :
		    p_sk->sk_name=HIR+"��ѧ����"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_NOR;
                    p_sk->sk_get=
"$Nһ�������е�ȫ��һ�����ɣ�˫���ƺ������������������\n"+
HIG+"$N��"+HIR+"��ѧ����"+HIG+"����ˡ�"+NOR+"\n";
                    p_sk->sk_use=""; // when this skill used what will display
    		    p_sk->sk_succ=""; // when this skill succedd what will display
    		    p_sk->sk_fail=""; // when this skill fail what will display
		    break;
		case "sszf" :
		    p_sk->sk_name="˲ɱ��";
    		    p_sk->sk_type=SK_ZHENG;
	            p_sk->sk_get=
HIG+"$N�������顮������磬�滺���֣�������𣬼�����ɽ����һ��ʱ���ٿ�é����$N�ġ�˲ɱ�󡯽����ˡ�"+NOR+"\n";
	            p_sk->sk_use=
HIY+"$N���һ�������н����ˣ����δ�ɣ���ʶ�ñ������ġ�˲ɱ�󡯣� ������ȥ������һ������"+NOR+"\n";
	            p_sk->sk_succ=
HIG+"$N���С��硯���֡����𡯡�ɽ���������ӭ��Ʈ�裬��ľ�Ա��� �о��ۻ����ң���ʱ��ͷת��������š�"+NOR+"\n";
	            p_sk->sk_fail=
RED+"$Nֻ��ս���к�ɱ������˷���������������ʿ��ɱ������ ��Ȼ�������Ӻ����˲ɱ��ʧ�ܡ�"+NOR+"\n";
		    break;
		case "jbzf" :
		    p_sk->sk_name="�ű���";
    		    p_sk->sk_type=SK_ZHENG;
                    p_sk->sk_get=
HIG+"$N��ϸ��Ħ�������޳�ʤ����ʱ�޳�λ�����ж̳������������������־�������˼�� $N�ġ��ű��󡯽����ˡ�"+NOR+"\n";
		    p_sk->sk_use=		
HIM+"$N˫��ƽ�٣����ӳ��գ�����ս���ɼ�ת������ʿ��������ᣬ ��ʼ���б��Ī��ġ��ű��󡯡�"+NOR+"\n";
		    p_sk->sk_succ=
HIG+"$N���н�ʿѵ�����أ�������λ�����о�Ȼ�ں��žŰ�ʮһ�ֱ仯�� ��о��ѱ���ʵ����֪���롣"+NOR+"\n";
		    p_sk->sk_fail=
RED+"ʧ��ʱ������:$NͻȻ����һ�����ƽ�ض��𣬽�ʿ������������䡣���ű���ʧ�ܡ�"+NOR+"\n";
		    break;
		case "cszf" :
		    p_sk->sk_name="������";
    		    p_sk->sk_type=SK_ZHENG;
                    p_sk->sk_get=
HIG+"$N��ϥ���£���㱼���һ�������������衣$N�ġ�һ�ֳ���������ˡ�"+NOR+"\n";
		    p_sk->sk_use=
HIB+"$N���н�����һ�ӣ��ȵ�������������β��������β������������������β�������о����� ��һ�ֳ����󡯣�"+NOR+"\n";
		    p_sk->sk_succ=
HIG+"ֻ�����б�ʿһ���ſ�����β��Ӧ��ԶԶ��ȥ������һ�����ߣ� ��о��޴����֡�"+NOR+"\n";
		    p_sk->sk_fail=
RED+"ֻ�����б�ʿ��������һ�ţ����ﻹ�˵���ʲô��, ��һ�ֳ�����ʧ�ܣ���"+NOR+"\n";
		    break;
		case "zxzf" :
		    p_sk->sk_name="׶����";
    		    p_sk->sk_type=SK_ZHENG;
                    p_sk->sk_get=
"$Nüͷһ�壬ͻȻ���Թ�Ϊ�صĲ��������ĵá�\n"+
HIG+"$N��"+NOR+"׶����"+HIG+"����ˡ�"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$N˫��һ�ӣ��ߺ�������רΪһ���з�Ϊʮ������ʮ����һҲ�������ڶ��йѡ����š�׶���󡯣���"+NOR+"\n";
                    p_sk->sk_succ=HIG+"$N���й�������
,��ʿ������磬ɲ�Ǽ��ų����޼᲻�ݵ�׶����"+NOR+"\n";
p_sk->sk_fail=RED+"$N����һ��ɢɳ����ʿ��æ���ң���׶����ʧ�ܡ�"+NOR+"\n";
		    break;
		case "qmdj" :
		    p_sk->sk_name=HIB+"���Ŷݼ�"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_FIGHT;
                    p_sk->sk_get=
"$N�е�������ƮƮ�ĺ��������˿ǡ�"+
HIG+"\n$N��"+HIB+"���Ŷݼ�"+HIG+"֮�������ˡ�"+NOR+"\n";
                    p_sk->sk_use="";
    		    p_sk->sk_succ="";
		    break;
		case "jbsj" :
		    p_sk->sk_name=NOR+"����ˮ��"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_JI;
                    p_sk->sk_get=
"$Nһ���񣬷·������˹�����ˮ��������������\n"+
HIG+"$N��"+NOR+"����ˮ��"+HIG+"����ˡ�"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$N�ֳ����ƣ��ȵ������ڽ�ʿ�����բ��ˮ��������"+NOR;
    		    p_sk->sk_succ=
HIG+"ֻ��һ�����£��������������Ӫ��$N�����Ц���������������� . . .��\n";
    		    p_sk->sk_fail=RED+"ֻ��һ�����£���ˮ��ô������ˡ�$N��С�����ѽ����\n"+NOR; 
		    break;
		case "jbhj" :
		    p_sk->sk_name=NOR+"�������"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_JI;
                    p_sk->sk_get=
"$Nһ̧ͷ�����󿴵���ս�����ޱߵ�"+RED+"��"+NOR+"��\n"+
HIG+"$N��"+NOR+"�������"+HIG+"����ˡ�"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$N�ֳ����ƣ��ȵ������ڽ�ʿ�����𣡣�����"+NOR;
    		    p_sk->sk_succ=
HIG+"ֻ��һ�����£��Ĵ�"+HIR+"��"+HIG+"��$N�����Ц���������������� . . .��\n";
    		    p_sk->sk_fail=RED+"ֻ��һ�����£��Ĵ�ð��һ�����̡�$N��ֵء��ס���һ����\n"+NOR; 
		    break;
			
		case "sk_zhimou" :
		    p_sk->sk_name=HIC+"��������"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_NOR;
                    p_sk->sk_get=
"$NͻȻ����һʱ���ƺ��������ȫ����Ȼ���ء�\n"+
HIG+"$N��"+HIC+"��������"+HIG+"����ˡ�"+NOR+"\n";
                    p_sk->sk_use=""; // when this skill used what will display
    		    p_sk->sk_succ=""; // when this skill succedd what will display
    		    p_sk->sk_fail=""; // when this skill fail what will display
		    break;
		case "sk_meili" :
		    p_sk->sk_name=HIY+"�ι�����"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_NOR;
                    p_sk->sk_get=
"$N����Զ�������۴�ý�ɽ��������\n"+
HIG+"$N��"+HIY+"�ι�����"+HIG+"����ˡ�"+NOR+"\n";
                    p_sk->sk_use=""; // when this skill used what will display
    		    p_sk->sk_succ=""; // when this skill succedd what will display
    		    p_sk->sk_fail=""; // when this skill fail what will display
		    break;
		case "fyzf" :
		    p_sk->sk_name="��Բ��"; // the chinese name for a skill
    		    p_sk->sk_type=SK_ZHENG;
                    p_sk->sk_get=
"$N��ͷ�˼�������ƺ�������ս������ɱ����\n"+
HIG+"$N��"+NOR+"��Բ��"+HIG+"����ˡ�"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$N�־ٺ��죬������������һ�£��ȵ���\n"+
"���ڽ�ʿ�����"+NOR+"��Բ��"+HIG+"����"+NOR;
    		    p_sk->sk_succ=
HIC+"ֻ������һ�����ս����������ɱ���죬�ж����룬\n"+
"��ʿ���沼�����γɷ����ȹ̵ķ�Բ����\n"+NOR; 
    		    p_sk->sk_fail=RED+"ֻ������һ�����ս����������ɱ���죬�жӻ��Ҳ��룬\n"+
"��ʿ��֪���룬��ȫ������ţ���Բ��ʧ�ܡ�\n"+NOR; 
		    break;
		case "zmyj" :
		    p_sk->sk_name=HIR+"����һ��"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_FIGHT;
                    p_sk->sk_get=
"$NǱ��������ֻ��ȫ������������˫�ۡ�\n"+
HIG+"$N��"+HIR+"����һ��"+HIG+"����ˡ�"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$NǱ��������һ�����ȣ�ʹ����ɱ����"+HIR+"������һ����"+NOR;
    		    p_sk->sk_succ=
RED+"$Nһʱ�����ֽţ���֪����мܣ�ֻ�����ۡ���һ���Ѿ����С�\n"+
"$N����һ����Ѫ . . .\n"+NOR; 
    		    p_sk->sk_fail=HIG+"$N΢΢һЦ��һ������������һ�С�"+
"˳�Ƹ��������Ļػ���\n"+NOR; 
		    break;
			
		default :
		    printf("ddd\n");
		    p_sk->sk_name="";
  		    printf("ccc\n");
             
	}
}
			
// SK_NOR normal skills such as the wuli weili and zhimou 1
// SK_FIGHT skills used in fight such as ����ǹ 2
// SK_ZHENG skills for �� 3
// SK_JI skills of �� 
private void main(string arg)
{
    string skill;
    skill=arg;  // ��ѧ����
    p_sk=new(class sg_skill_reg, 
		    sk_name : "",
    		    sk_type : 0,
                    sk_get : "",
                    sk_use : "" ,
    		    sk_succ : "",
    		    sk_fail : "" );
    def_skill(skill);
    if((p_sk->sk_name)!="")
    {
  	    SG_SKILL_D->register_skill(skill, p_sk);
    } 
   else
    {
	  printf("can't register this kind of skills\n");
    }
}
