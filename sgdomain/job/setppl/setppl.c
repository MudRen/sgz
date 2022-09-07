// the job of setppl
// by Listen on July 2001
//this file should be in /sgdomain/job/setppl/setppl.c
// purpose of this file is to assign the setppl job to a player
mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area"); //get the officer(taishou)'s city
   string m_nation=CHAR_D->get_char(officer_id,"nation");//get the officer's nation

	object o=find_body(m_id);
	if(!objectp(o)) return "$N��$T�����ڲ�ϵͳ����\n";
	
	if(CHAR_D->get_char(m_id,"level")<4 || CHAR_D->get_char(m_id,"ranknation")==0)
		return "$N��$T����$R��ǰ�Ĺ�ְ�޷��������ü���Ĺ����� \n";
		
	if(o->query_job("setppl","status")=="begin")
		return "$N��$T����������ļ������û������ء�\n";
//fobidden from NPC country
	if (CHAR_D->get_char(m_nation,"type")==TYPE_NPC) //king is a npc
		return "$N��$T��������������ִֹ�����ü������\n";
//try to reduce 50 soldier from the city
	if(!AREA_D->reduce_soldier(m_area,"sum",50))
		return "$N��$T��������û���㹻��ʿ��ȥִ�����ü������\n";

//assign the job to the player
	o->add_job("setppl");
	o->set_job("setppl","status","begin");
	o->set_job("setppl","memo","���ü��");

	return "$N��$T�����Ǿ��鷳$Rȥִ�����ü��������\n�����Ѿ��� help setppl��\n";
}
	


