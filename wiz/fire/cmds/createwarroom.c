// create warroom.c
inherit CMD;
// inherit M_ACCESS;
string get_content(string a_id);
void main() {
	string *keys;
	string f_name,p_con;
//        set_privilege(1);
	keys=AREA_D->list_areas();
	foreach(string a_id in keys)
	{
		f_name=AREA_D->get_area(a_id,"path")+"warroom.c";
		p_con=get_content(a_id);
tell_user("fire","name"+f_name+" con "+p_con);
                unguarded(1, (: write_file, f_name,p_con,1 :));	}
        return;
}
string get_content(string a_id)
{
	string ret="";
	ret+="inherit WAR_GRID;\n";
	ret+="void create(){\n";
        ret+="use_data_file(\""+a_id+"\");\n}\n";
	return ret;
}
