// the job of bugao
// by fire on March 1999
#define BUGAO "/sgdomain/obj/other/sdpk"
#include <move.h>
mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string m_nation=CHAR_D->get_char(officer_id,"nation");

   string *mlist,target,*tmp,st,rmnam;
   mapping a_d;
   string p_path;

   object o=find_body(m_id);
   object env,*obs,obg;
   if(!objectp(o)) return 0;

   mlist=AREA_D->list_areas();
   mlist=filter_array(mlist,(:AREA_D->get_area($1,"nation")!=$(m_nation):));


   if(!sizeof(mlist)){
	   o->add_job("bugao");
		o->finish_job("bugao");
		return "$N��$T��������ûʲô�ط�����������ġ�\n";
   }
   a_d=AREA_D->get_all_distance(m_area);
   mlist=sort_array(mlist,(: $(a_d)[$1] > $(a_d)[$2] ? 1 : -1 :));

	if((sizeof(mlist)>5)&&random(2)) 
		target=mlist[random(5)];
	else
        target=mlist[random(sizeof(mlist))];

	p_path=AREA_D->get_area(target,"path");
	mlist=AREA(target)->get_room("list");
	tell_user("huaer",sprintf("�ڲ�������bugao.c��target = %s\n",target));
	//rmnam=AREA(target)->get_room(mlist[random(sizeof(mlist))],"b"); 	Ϊ�˼�city.o,ȥ��ԭ������"b"�ֶ�.
	rmnam=mlist[random(sizeof(mlist))];
	rmnam = (AREA_D->get_area(target,"path") + rmnam)->short();
	tell_user("huaer",sprintf("rmnam = %s\n",rmnam));
   
   obg=new(BUGAO);

   obg->set_area(target);
   obg->set_roomname(rmnam);

   if((obg->move(o))!=MOVE_OK) {
	destruct(obg);
      return "$N��$T���������϶���̫���ˣ��ò�����Щ���档\n";
   }

   o->add_job("bugao");
   o->set_job("bugao","status","begin");
   o->set_job("bugao","memo",AREA_D->get_area(target,"name")+"��"+rmnam);
   
   return "$N�ٺ�һЦ����$T�����Ǿ��鷳$R�����Ų�������"+AREA_D->get_area(target,"name")+
	   "��"+rmnam+"��"
	   "\n��������� %^H_BLUE%^drop bugao%^RESET%^�����ˡ�\n";
}

void bugao_catch(string o_id,string p_id,object o_bugao)
{
        object o_o,o_p;
	o_o=CHAR_D->find_char(o_id);
	o_p=CHAR_D->find_char(p_id);
	if((!objectp(o_o))&&(!objectp(o_p)))
		return;

        o_o->targetted_action(
                "$N��$T���һ������$r����Ȼ�ڴ��������棬��������£�\n",o_p);
        o_p->simple_action(
                "�ڹٱ�һӵ���ϣ���$N���ý��ʵʵ��\n");
        o_o->simple_action(
                "$Nһ���ֵ������Ҵ��ߡ�\n");
        o_p->simple_action(
                "�ڹٱ���$NѺ����ȥ��\n");

        CHANNEL_D->deliver_tell("rumor","system",
                CHAR_D->get_char(p_id,"name")+
                "��"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
                "�������棬������Ѳ�ߵ�"+CHAR_D->get_char(o_id,"name")+
                "����ץ��");
        (PCMD+"catch")->catch_award(o_id,p_id);
	if(objectp(o_bugao)) destruct(o_bugao);
}
