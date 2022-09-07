// create arearooms.c
inherit CMD;
// inherit M_ACCESS;
string get_content(string a_id);
void main() {
        string *keys;
        string f_name,p_con;
        keys=AREA_D->list_areas();
        foreach(string a_id in keys)
        {
                f_name="/a/"+a_id+".c";
                p_con=get_content(a_id);

                unguarded(1, (: write_file, f_name,p_con,1 :)); }
        return;
}
string get_content(string a_id)
{
        string ret="";
        ret+="inherit __DIR__ + \"area_server.c\";\n";
        ret+="void create() {\n";
        ret+="set_area(\""+a_id+"\");\n}\n";
        return ret;
}
