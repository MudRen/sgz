// the job of spy certain area
// by fire on March 1999
mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string m_nation=CHAR_D->get_char(officer_id,"nation");

   string *mlist,target,*tmp,st;
   mapping a_d;
   string p_path;

   object o=find_body(m_id);
   object env,*obs;
   if(!objectp(o)) return 0;

   mlist=AREA_D->list_areas();
   mlist=filter_array(mlist,(:AREA_D->get_area($1,"nation")
	   !=$(m_nation):));


   if(!sizeof(mlist)){
   		o->add_job("spy");
	   o->finish_job("spy");
		return "$N��$T��������ûʲô�ط������ѽ��\n";
   }
   a_d=AREA_D->get_all_distance(m_area);
   mlist=sort_array(mlist,(: $(a_d)[$1] > $(a_d)[$2] ? 1 : -1 :));

   if((sizeof(mlist)>5)&&random(2)) 
	target=mlist[random(5)];
   else
        target=mlist[random(sizeof(mlist))];

   p_path=AREA_D->get_area(target,"path");
   mlist=AREA(target)->get_room("list");

   o->add_job("spy");
   o->set_job("spy","status","begin");
   o->set_job("spy","spied",({}));

   o->set_job("spy","area",target);
   
   o->set_job("spy","path",p_path);
/*   tmp=({});
   foreach(string p in mlist)
   {
		st=p_path+p[0..<3];
		tmp+=({st});
   } */
   o->set_job("spy","size",sizeof(mlist));
  
   o->set_job("spy","memo","���"+AREA_D->get_area(target,"name"));
   
   return "$N��$T�����Ǿ��鷳$Rȥ�����һ��"+
	   AREA_D->get_area(target,"name")+
	   "��\n�����Ѿ��� help spy��\n";
}
