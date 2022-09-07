mixed get_suggest(string n_id,string what);
mixed set_suggest(string n_id, string what, mixed val);
void discuss_suggest(string n_id);
void announce_suggest(string n_id);
void add_suggest(string n_id,string topic,mixed para,string who,string *areas);
mixed sug_nationtax(string who,string n_id, string city,int tax);
mixed do_check_can_nationtax(string who);
mixed do_check_nationtax_para(string *para, string who);

mixed do_check_can_nationtax(string who)
{
        object ply;

        ply = find_body(who);
	if( ply->query_sk_level("sk_meili")<=50 )
		return "���ι�����̫�ͣ����ܶԹ���˰��ָ�ֻ��ţ�\n";
	else return 1;
}
mixed do_check_nationtax_para(string *para, string who)
{
	string city, n_id;
	int tax;

	para = para[1..];
	n_id = CHAR_D->get_char(who, "nation");
	if( sizeof(para)==1 ){
		city = CHAR_D->get_char(who, "area");
		tax = to_int(para[0]);
	} else if( sizeof(para)==2 ){
		city = para[0];
		tax = to_int(para[1]);
	} else return "Ҫ����һ���еĹ�˰���鵽���٣�\n";
	
	if( tax>20 ) return "����˰�ʲ��ܳ���20��\n";
	if( tax<0  ) return "��ô���и�˰�ʡ�\n";
	if( AREA_D->get_area(city,"nation")!=n_id ) return "���˵ĵ��̣����ʲô�ġ�\n";
	if( !CHAR_D->get_char(who,"ranknation")&&(CHAR_D->get_char(who,"area") != city) )
                return "���˵ĵ��̣����ʲô�ġ�\n";
        if (CHAR_D->get_char(n_id,"type")==TYPE_NPC)
        if (AREA_D->get_area(city,"leader")!=who)  //Added by suicide for only local
                return "���ֲ��ǵ���̫�أ���ʲô�ġ�\n";//taishou can suggest tax

	sug_nationtax(who,n_id,city,tax);
}
mixed sug_nationtax(string who,string n_id, string city,int tax)
{
	int o_tax;

	o_tax=AREA_D->get_area(city,"taxnation");	
        if(o_tax==tax) {
		write("Ŀǰ˰������"+chinese_number(tax)+"��\n");
		return;
	};
        add_suggest(n_id,"nationtax",({city,o_tax,tax}), who, ({city}));

        if(tax>o_tax) {
		set_suggest(n_id, "str", "��"+AREA_D->get_area(city,"name")+
			"�Ĺ���˰����"+chinese_number(o_tax)+"���ӵ�"+chinese_number(tax));
          	set_suggest(n_id,"reason","Ŀǰ�������");
        } else {
          	set_suggest(n_id, "str", "��"+AREA_D->get_area(city,"name")+
			"�Ĺ���˰����"+chinese_number(o_tax)+"���͵�"+chinese_number(tax));
          	set_suggest(n_id, "reason", "Ŀǰ�����ӯ");
        }

	announce_suggest(n_id);
	call_out("discuss_suggest",2,n_id);

        return 1;
}
void do_nationtax(string n_id)
{
	string p_a;
	int o_t,n_t, safe;
	mixed para;

	para = get_suggest(n_id, "para");
	p_a  = para[0];
	o_t  = para[1];
	n_t  = para[2];

	if(n_t>o_t) {
		safe=AREA_D->get_area(p_a,"safe")-(n_t-o_t);
		if(safe<0) safe=0;
		AREA_D->set_area(p_a,"safe",safe);
	};
	AREA_D->set_area(p_a,"taxnation",n_t);
}
