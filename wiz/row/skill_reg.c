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
