// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** suicide.c
**
*/

inherit CMD;

nomask void main(string arg) {
    string my_id=this_user()->query_userid();
    if(CHAR_D->get_char(my_id,"ranknation")==R_KING)
    {
         write("��Ϊһ��֮�������������\n");
         return;
    }
    if(MUSEUM_D->char_exist(my_id))
    {
         write("�Ѿ����˵�عݣ���ô����˼����ɱ��\n");
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
    USER_D->suicide();    
}

