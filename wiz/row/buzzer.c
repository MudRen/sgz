// buzzer.c by fire
// this cmd is used create quick room
#include <mudlib.h>
#include <daemons.h>
#include <sanguo.h>
inherit CMD;
array dirs=({"east","west","south","north","southeast","southwest","northeast","northwest","up","down","enter","out",});
   
string p_area,p_dir,p_id,p_name;
string m_id;
string p_path;
int is_indoor;
mixed opdirs=(["east":"west", "south":"north", "north":"south", "west":"east","southeast":"northwest","southwest":"northeast","up":"down","enter":"out","northeast":"southwest","northwest":"southeast","down":"up","out":"enter",]);


int insert_connection(string m_file,string dir,string t_f) {
   string f_c,f_b,f_e;
   string f_exit;
   int f_p;
   mixed dirs;
   f_c=read_file(m_file);
   f_p=strsrch(f_c,"set_exits",1);
   if(f_p==-1) // no set_exist
   {
      f_p=strsrch(f_c,";",-1); // the last ;
      f_b=f_c[0..f_p];
      f_e=f_c[(f_p+1)..<1];
      dirs=([]);
      dirs[dir]=t_f;
      rm(m_file);
      write_file(m_file,f_b+sprintf("\n// connection added by buzzer 
      set_exits(%O);\n",dirs)+f_e);

   }
   else
   {
      f_b=f_c[0..(f_p-1)];

      f_c=f_c[f_p..<1];
      f_p=strsrch(f_c,"[",1);
      f_b=f_b+f_c[0..f_p];
      f_e=f_c[(f_p+1)..<1];
      rm(m_file);
      write_file(m_file,f_b+"\n\""+dir+"\":\""+t_f+"\",\n"+f_e);

   }
}

string get_cnt() {
    string ret;
    string driver,tim;
    driver=this_body()->short();
    tim=ctime(time());
    ret= "// this room is created by buzzer.c\n";
    ret+="// driver is "+driver+"\n";
    ret+="// created date is "+tim+"\n";
    ret+="#include <mudlib.h>\n";
    ret+="#include \"/wiz/fire/fire.h\"\n";
    ret+="#include <ansi.h>\n";
    if(is_indoor) 
      ret+="inherit INDOOR_ROOM;\n";
    else
      ret+="inherit OUTDOOR_ROOM;\n";
    ret+="void setup() {\n";
    ret+="set_area(\""+p_area+"\");\n";
    ret+="set_light(50);\n";

    ret+="set_brief(\"%^YELLOW%^"+p_name+"%^RESET%^\");\n";
    ret+="set_long(\"\");\n";
    ret+="set_exits( ([ ]));\n}\n";

    return ret;
}
void create_t_room() {
   string ret;
   int res;
   ret=get_cnt();
   res=unguarded(1, (: write_file, p_path+p_id+".c",ret,1 :)); 
   if(res) write("room "+p_name+" created.\n");
   else write ("room "+p_name+" crated fail.\n");
   
}

void input_indoor(string s) {
   this_user()->modal_pop();
   if(s=="q") return; //
    is_indoor=0;
   if(s=="y") is_indoor=1;
   write("Area is "+p_area+"\n");
   write("Direction is "+p_dir+"\n");
   write("Room's Eng name is "+p_id+"\n");
   write("Room's Chinese name is "+p_name+"\n");
   write("Path is "+ p_path+"\n");
   write("Room is "+(is_indoor? "indoor": "outdoor")+"\n");
   write("My room is "+m_id+"\n");
   create_t_room();  
   insert_connection(p_path+m_id+".c",p_dir,p_path+p_id+".c");
   insert_connection(p_path+p_id+".c",opdirs[p_dir],p_path+m_id+".c");

}


void input_name(string s) {
   this_user()->modal_pop();
   if(s=="q") return; //
   if(!sizeof(s)) {
     write("wrong name\n");
     return;
   }
   p_name=s;
   write("Is this an indoor room ?<y|n>\n");
   this_user()->modal_push((:input_indoor:),"",0,0);

}

void input_id(string s) {
   this_user()->modal_pop();
   if(s=="q") return; //
   if(!sizeof(s)) {
     write("wrong name\n");
     return;
   }
   p_id=s;
   write("Please input the chinese name of new room:\n");
   this_user()->modal_push((:input_name:),"",0,0);

}

void input_dir(string s) {
   this_user()->modal_pop();
   if(s=="q") return; //
   if(member_array(s,dirs)==-1) {
     write("illegal direction\n");
     return;
   }
   p_dir=s;
   write("Please input the file name of new room:\n");
   this_user()->modal_push((:input_id:),"",0,0);

}
private void main(string notused)
{
   object o;
   o=this_body()->query_room();
   p_area=o->get_area();
   if(!AREA_D->area_exist(p_area)) {
      write("Here is not sanguo area.\n");
      return;
   }
   p_path=AREA_D->get_area(p_area,"path");
   m_id=file_name(o);
   m_id=m_id[sizeof(p_path)..<1];
   write("Please input the direction:\n");
   this_user()->modal_push((:input_dir:),"",0,0);
}


