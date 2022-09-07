// the job ask obj from certain maker
// by fire on July 1999
mixed job(string m_id,string officer_id)
{
   string *mlist,maker_id,obj_id;
   string *oblist;
   string p_area;
   object o=find_body(m_id),o_maker;

   if(!objectp(o)) return 0; // strange
   
   mlist=CHAR_D->check_char("is_maker",1);
   maker_id=mlist[random(sizeof(mlist))];
   oblist=CHAR_D->get_char(maker_id,"goods");
  
   while(!sizeof(oblist)) {
      maker_id=mlist[random(sizeof(mlist))];
      oblist=CHAR_D->get_char(maker_id,"goods");

   }
   obj_id=oblist[random(sizeof(oblist))];

   o_maker=CHAR_D->find_char(maker_id);

   if (o_maker == 0) {
	load_object(CHAR_D->get_char(maker_id,"shd_room"));
	o_maker=CHAR_D->find_char(maker_id);
	if(o_maker==0) return "$N����"+maker_id+"��BUG������WIZ\n";
   }
	
   p_area=o_maker->query_room()->get_area();

   o->set_asklist("kick","target",maker_id);
   o->set_asklist("kick","filename",PJOB+"askobj/askobj");
   o->set_asklist("kick","funname","ask_kick");


  o->add_job("askobj");
  o->set_job("askobj","status","begin");
  o->set_job("askobj","obj_id",obj_id);
  o->set_job("askobj","memo","��"+AREA_D->get_area(p_area,"name")+
       "��"+CHAR_D->get_char(maker_id,"name")+"��"+OBJ_D->get_obj(obj_id,"name"));
   
   return "$N��$T�����Ǿ��鷳$R��"+AREA_D->get_area(p_area,"name")+"��"+
	   CHAR_D->get_char(maker_id,"name")+"��һ���Ҷ���"+OBJ_D->get_obj(obj_id,"name")+
            "��\n�����˵ask "+maker_id+" about kick ��\n";
}
void finish(string m_id) {
	tell_user(m_id,"%^H_GREEN%^������ɣ���ȥ̫�ش����Ͱɡ�\n%^RESET%^");
}
void ask_kick(object me, object target)
{
	string m_id;
	m_id=me->query_primary_id();
	me->targetted_action(
           "$Nһ���ߵ�$T��ƨ���ϵ�������̫��Ҫ��"+
           OBJ_D->get_obj(me->query_job("askobj","obj_id"),"name")+
           "��ô��û�͵���\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N��$T��ͷ��Ц����$s��������͸����ȥ��\n",1);
	DELAY_D->delay_targetted_action(
		me,target,"$N��$T�����ٲ���㣬С������Դ���\n",2);

	me->clear_asklist("kick");
	me->set_job("askobj","status","done");
	call_out("finish",3,m_id);
	return;
}
