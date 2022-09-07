/* addarea.c by fire on 16/06/98
this cmd is used to add a new area
in the sg system, this cmmond should
set some priviliage in case careless
wiz may cause unnessary data just by testing
usage: addarea <area_id>
example: addarea luoyang
*/
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>

#define BUILDCITY_D "/daemons/buildcity_d"

inherit CMD;


int create_city_file(string p_id) {     //write file in /a with name p_id.c
    string ret;
    string driver,tim;
    int res;
    driver=this_body()->short();
    tim=ctime(time());
    ret= "// this file is created by addarea.c\n";
    ret+="// driver is "+driver+"\n";
    ret+="// created date is "+tim+"\n";
    ret+="inherit __DIR__ + \"area_server.c\";\n";
    ret+="void create() {\n";
    ret+="set_area(\""+p_id+"\");\n";
    ret+="}\n";
    res=unguarded(1, (: write_file, "/a/"+p_id+".c",ret,1 :)); 
    return res;
}

nomask private void main(string str)
{
    string char_id,p_id,p_name,p_zhou,sht,result;
    int level =1;
    if (!str||sscanf(str, "%s %s %s %s %s %d", char_id,p_id,p_name,p_zhou,sht,level)!=6)
    {
        write("�÷���addarea <������ID> <����ID> <��������> <�����ݿ�> <�������ID> <����level>\n");
        write("���ӣ�addarea hrbl nanyang ���� ������ ny 2\n");
        return;
    }
    if (CHAR_D->char_exist(char_id))
    {
    if (CHAR_D->get_char(char_id,"type")==TYPE_PLAYER)
       {CHAR_D->set_char(char_id,"buildcity",p_id);
        if (stringp(BUILDCITY_D->set_city_build_info(p_id,"baseinfo",({char_id,p_name,p_zhou,sht,level}))))
            write("�ó��Ѿ��ڽ����У��޷��������ã�\n");
        else
        {
         create_city_file(p_id);
         NEWS_D->add_city_group("city."+p_id);
         write("�㸳��"+char_id+"�޽�"+p_name+"("+p_id+")��Ȩ�������еȼ�Ϊ"+chinese_number(level)+
              "��������"+p_zhou+"��\n");
         tell(bodies(),YEL+"�������"+"��Ϊ"+CHAR_D->get_char(char_id,"name")+"("+char_id+")"+
                      "ͳһ�����й�������������"+p_zhou+"һ�������³�"+p_name+"("+p_id+")"+
                      "��Ȩ����"+NOR+"\n");
        }
       }
    else
      write("������NPC��ô�����У�\n");
    
    }
    else
      write("�����Ƕ��ӵ���ҽ�ɫ���ܾ����޽��³ǵ��ʸ�\n");
      
    return;
}
