// suicide.c 
// by fire on Sep 05, 1998
// used for player char to risign a position
void start(string arg)
{
        int my_id,task_id;
        int* my_task;
        my_id=this_body()->query_id()[0];
        if(CHAR_D->get_char(my_id,"ranknation")==R_KING)
        {
                write("��Ϊһ��֮�������������\n");
                return;
        }
        if(AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"leader")==my_id)
        {
                write("��Ϊ���죬�����������\n");
                return;
        }

        if(wizardp(this_user()))
	{
                write("��Ϊ��ʦ�������������\n");
                return;
	}
"/secure/daemons/suicide_d"->suicide();
}
