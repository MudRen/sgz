// warfield.c 
// by fire on Sep 4, 1998
// used for player char to risign a position
inherit M_ANSI;
void start(string arg)
{
        string ret;
        if(arg=="")
        {
                write("�÷�����");
                write("�� cmd help warfield �鿴��ϸ������\n");
                return;
        }
        if(arg=="here")
        {
                object env;
                mixed tmp;
                env=environment(this_body());
                arg=env->get_area();
                tmp=AREA_D->check_area("area",arg);
                if(sizeof(tmp)==0)
                {
                        write("û�д˴��ĵ�ͼ����map����Ŀǰ���еĵ�ͼ��\n");
                            return;
                }
                arg=tmp[0];
        }
        this_body()->move(AREA_D->get_area(arg,"path")+"warroom/0/0");
        write("hehe\n");
}
