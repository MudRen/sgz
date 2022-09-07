// web_d.c by fire on May 1999
// this daemons holds most common used web functions

// get a groups chinese name if return "" can't show on the web
string get_group_name(string gid) {
	string n_id;

	if(gid[0..6]=="nation.") {
		n_id=gid[7..<1];
		if(!COUNTRY_D->nation_exist(n_id))
			return "";
		return COUNTRY_D->get_country(n_id,"name")+"����";
	}

	if(gid=="caolu") return mud_name()+"���԰�"; 
	if(gid=="marriage") return "ϲ����Ե";
	if(gid=="newbie") return "���ְ���"; 
	if(gid=="ranks") return "��������"; 
	if(gid=="war") return "����ս��"; 
	if(gid=="progress") return "��ʦͨ��"; 
	return "";
}

int valid_group(string gid) {
	return sizeof(get_group_name(gid));
}
string url_encode(string inp) {
	return replace_string(inp," ","+");	
}
string url_decode(string inp) {
	return replace_string(inp,"+"," ");	
}
