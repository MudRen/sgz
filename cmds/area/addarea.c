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
        write("用法：addarea <建城者ID> <地区ID> <地区名称> <所属州郡> <地区简称ID> <地区level>\n");
        write("例子：addarea hrbl nanyang 南阳 北荆州 ny 2\n");
        return;
    }
    if (CHAR_D->char_exist(char_id))
    {
    if (CHAR_D->get_char(char_id,"type")==TYPE_PLAYER)
       {CHAR_D->set_char(char_id,"buildcity",p_id);
        if (stringp(BUILDCITY_D->set_city_build_info(p_id,"baseinfo",({char_id,p_name,p_zhou,sht,level}))))
            write("该城已经在建设中，无法二次设置！\n");
        else
        {
         create_city_file(p_id);
         NEWS_D->add_city_group("city."+p_id);
         write("你赋予"+char_id+"修建"+p_name+"("+p_id+")的权力，城市等级为"+chinese_number(level)+
              "，隶属于"+p_zhou+"。\n");
         tell(bodies(),YEL+"【天道】"+"因为"+CHAR_D->get_char(char_id,"name")+"("+char_id+")"+
                      "统一天下有功，天神赋予其在"+p_zhou+"一带建造新城"+p_name+"("+p_id+")"+
                      "的权力。"+NOR+"\n");
        }
       }
    else
      write("机器人NPC怎么建城市？\n");
    
    }
    else
      write("必须是定居的玩家角色才能具有修建新城的资格！\n");
      
    return;
}
