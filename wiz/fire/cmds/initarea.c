// to create basic stuff for all new areas
inherit CMD;
void add_path(string a_id) {
    string p_path;
    int p_level,ret;
    p_path=AREA_D->get_area(a_id,"path");
    if(!p_path) {
       p_level=AREA_D->get_area(a_id,"level");
       switch (p_level) {
          case 1:
          case 2:
             p_path=PAREA+"guan/"+a_id+"/";
             break;
          case 3:
             p_path=PAREA+"town/"+a_id+"/";
             break;
          case 4:
          case 5:
             p_path=PAREA+"cities/"+a_id+"/";
             break;
          default:
              write("area " + a_id + " has illegal level.\n"); 
              return;
       }
          ret=unguarded(1, (: mkdir, p_path :)); 
          if(ret) {
             AREA_D->set_area(a_id,"path",p_path);
             write(a_id + " path set and created.\n");
          }
          else 
             write(a_id + " path created failed.\n");
    }
}
string get_cnt(string a_id) {
    string ret;
    ret= "// this room is created by initarea.c\n";
    ret+="inherit OUTDOOR_ROOM;\n";
    ret+="void setup() {\n";
    ret+="set_area(\""+a_id+"\");\n";
    ret+="set_light(50);\n";
    ret+="set_brief(\""+AREA_D->get_area(a_id,"name")+"\");\n";
    ret+="set_long(\"\");\n";
ret+="set_objects( ([\"/sgdomain/yizhan/mafu.c\" : 1 ]) );\n}\n"; 
    return ret;
}
void add_meetflyroom(string a_id) {
       string p_name;
       object o;
       string cnt;
       int ret;
       p_name=AREA_D->get_area(a_id,"path")+AREA_D->get_area(a_id,"fly");
       o=load_object(p_name);
       if(objectp(o)) return;
       p_name=AREA_D->get_area(a_id,"path");
       if(!p_name) {write(a_id+ " does not have path.\n"); return; }
       p_name+="tmp";
       unguarded(1,(:rm, p_name:));
       p_name+=".c";
       cnt=get_cnt(a_id);
       ret=unguarded(1, (: write_file, p_name,cnt,1 :)); 
       if(ret) {
           write("area "+a_id+" fly and meeting and yizhan added\n");
           AREA_D->set_area(a_id,"fly","tmp");
           AREA_D->set_area(a_id,"meeting","tmp");
       }
	else
           write("area "+a_id+" fly room add failed\n");
}
void main() {
        string *keys;
        string f_name,p_con;
        set_privilege(1);
        keys=AREA_D->list_areas();
        foreach(string a_id in keys)
        {
           AREA_D->set_area(a_id,"area",0);
           AREA_D->set_area(a_id,"map",0);
	   add_path(a_id);
           add_meetflyroom(a_id);
        }
        return;
}
