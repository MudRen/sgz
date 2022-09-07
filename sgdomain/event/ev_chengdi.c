// ev_chengdi.c
// 
void final_announce(string p_nation);
mixed can_chengdi(string p_nation) {
	int pop;
	string *list;
	pop = COUNTRY_D->get_country(p_nation,"population");
	if(pop<1000000) return "ȫ���˿ڲ��㡣\n";
	pop = COUNTRY_D->get_country(p_nation,"soldier");
	if(pop<100000) return "ȫ���������㡣\n";
	pop = COUNTRY_D->get_country(p_nation,"gold");
	if(pop<100000) return "������㡣\n";
	if(CHAR_D->get_char(p_nation,"ju")<7)
		return "������λ̫�͡�\n";

	if(COUNTRY_D->get_country(p_nation,"level")==1) return "����Ѿ��ǵ۹��ˡ�\n";

//  5  �����Ǹ�ӹ��	this will be consider later
	list=CHAR_D->check_char("nation",p_nation);
	list=filter_array(list,(:CHAR_D->get_char($1,"type")==0:));
	if(sizeof(list)<100) 
		return "����(�����е���ʵ����)����������\n";
	return 1;
}


void chengdi_announce(string s) {
	replace_string( s, "%^RESET%^", "%^RESET%^%^H_GREEN%^");
	tell(users(),"%^H_GREEN%^���Ƶۡ�"+s+"%^RESET%^");
}
void clear_nation_position(string p_nation) {
	string *list,area;

	area=CHAR_D->get_char(p_nation,"area");
	chengdi_announce("�ϻ����ɣ�����ҹ�����࣬"+AREA_D->get_area(area,"name")+
       "�Ͽյ��ǲ��ã������������ӽ��١�\n");


	area=AREA_D->get_area(p_nation,"area");
	list=CHAR_D->check_char("nation",p_nation);
	list=filter_array(list,(:CHAR_D->get_char($1,"ranknation")>1:));
	foreach (string id in list) {
		CHAR_D->set_char(id,"ranknation",0);
	}
	return;
}
void increase_safe(string p_nation) {
	string *list,a;
	int safe;
	a=CHAR_D->get_char(p_nation,"area");

	chengdi_announce("���׵ۣ���ҹ�μ�һ���ߴ�"+AREA_D->get_area(a,"name")+
		"�������º����֮���㡣\n");


	chengdi_announce("���˶��У��˲���֮�ף�ֻ��"+AREA_D->get_area(a,"name")+
		CHAR_D->get_char(p_nation,"name")+"�����ġ�\n");
	chengdi_announce("���׵ۣ�����\n");

	list=AREA_D->check_area("nation",p_nation);
	foreach(string s in list) {
		AREA_D->set_area(s,"safe",AREA_D->get_area(s,"safe")+10);
	}


}
void increase_loyalty (string p_nation) {
	string *list,a;
	int loy;
	a=CHAR_D->get_char(p_nation,"area");
	if(a=="changan") 
		chengdi_announce("����ͯҥ��������˫������������ʢ������\n");
	else
		chengdi_announce(AREA_D->get_area(a,"name")+"ͯҥ������һ������"+
			AREA_D->get_area(a,"name")+"һ��������������ʢ������\n");

	list=CHAR_D->check_char("nation",p_nation);
	foreach(string s in list) {
		CHAR_D->set_char(s,"loyalty",CHAR_D->get_char(s,"loyalty")+10);
	}
}
void refuse (string p_nation,int ts) {
	string nm=CHAR_D->get_char(p_nation,"name");
	if(ts==1) {
		chengdi_announce(nm+"�����ǲ����ҽ�������Ϊ������������˲���֮�¡�\n");
		return;
	}
	else
		chengdi_announce(nm+"��������ˣ�������޳������ɾ��š�\n");
}
void pleed(string p_nation,int ts) {
	string *list;
	string id1,id2,id3;
	string name,nm;
	list=CHAR_D->check_char("nation",p_nation);
	list-=({p_nation});
	id1=list[random(sizeof(list))];
	list-=({id1});
	id2=list[random(sizeof(list))];
	list-=({id2});
	id3=list[random(sizeof(list))];

	nm=CHAR_D->get_char(p_nation,"name");
	if(ts==1) {
		name=CHAR_D->get_char(id1,"name");
		chengdi_announce(name+"���������꣬����һ�仰��֪������������\n");
		chengdi_announce(nm+"���뽲��\n");
		chengdi_announce(name+"������Ӣ�����䣬��Ң˴������ˣ����������ֹ�֮�ж����β����ۼ�. . .\n");
		return;
	}
	if(ts==2) {
		name=CHAR_D->get_char(id1,"name")+"��"+
		CHAR_D->get_char(id2,"name")+"��"+
		CHAR_D->get_char(id3,"name");
		chengdi_announce(name+"���������ع��ǣ�������ͯҥ��Ӧ���£���������������¡�\n");
		return;
	}
	chengdi_announce("��"+COUNTRY_D->get_country(p_nation,"name")+"�������������񺺳��������������ܣ���ʹ���²�ƽ��������ս����������\n");
	chengdi_announce("������Ӧ���⣬��˳���ģ�ƽ���ĺ����Ȱ�����ˮ�𣬴������Ҳ��\n");
	chengdi_announce(nm+"�������\n");
	return;
}
void agree(string p_id,int ts) {
	string dis;
	string ns=CHAR_D->get_char(p_id,"name");
	switch(ts) {
		case 1:
		dis=ns+"�������Σ���Ȼ̧ͷ�����ðɾ������ǵġ�
        ˵�մӿڴ����ͳ�һ�������Ͱ͵�ֽ������ɤ�ӣ�����������";
		break;
		case 2:
		dis="    �������ߵ�Ң��λ���ݡ�˴��˴���������ܵ²��ˣ����Ի����֮��
        ������Ű��������ն����������ˮ�����к��ҡ����������ڳ���Ω��";
		break;
		case 3:
		dis="�е¡��񺺵���٣���ʧ�����������㣬����������Я������ɽҰ��
        �������ڹ��֣��˹������̾������İ�����飬�������࣬�������ӡ�";
		break;
		case 4:
		dis="    �����Ȼ裬�������Ⱥ�����棬���ڵ߸��������ٺ٣�ƥ�������
        �в�¢�塣�Ծ�۫�����ֶᾣ�棬�۵��������ţ�ı�����¡�����������";
		break;
		case 5:
		dis="    ӵ�ױ��ںӺ���������ԭ���������߷��ƣ�־����𢣬��Ϊ���³��ѣ���
        �����졣";
		break;
		case 6:
    		dis="    ���ȿ����ң�������������齵�𣬵�ά���ʣ�������֮ʧ����˳��
        ��֮���ģ�뼾����죬��������������������֮�ʣ������𾪣�����Ԭ�ܣ�";
		break;
		case 7:
		dis="�ϵ���ᣬ��ƽ��ǫ������ܲ١������ָ���޲����ң���ì֮������Ϊ
        ��촡�������Խ���������ӣ������Ⱥ��������ӡ�������ڣ��ִ�֮��";
		break;
		case 8:
		dis="������ֻ��죬��ƽ֮����Զ���������������𣬽�������϶�ƽ�����
        ��ɽ�����ǣ�߳������Ʊ�ɫ��";
		break;
		case 9:
		dis= "   ���ܵ��������������¡��������������Բ�����ҵ�����Ծ��棬�ĺ�
        ����������������ʽ��������һ�ˡ�"+ns+"η���������ֹֿ������ڵأ���

        ��Ԫ�գ����張�̳�ܻʵ���緣�����������Ω��������"+
		AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name")+"�������ĺ���";
		break;
		case 10:
		dis=ns+"���ϣ����ֶ���������Զɽ��ֻ��������Ӣ��������˭��";
		break;
		case 11:
		dis="���׵��űϴ�ޣ����һ����������Ҳ�����Բ���������";
		break;
	}
	chengdi_announce(dis+"\n");

}
void chengdi_step(string p_nation,int step) {
	switch(step) {
		case 1:	clear_nation_position(p_nation);break;
		case 2:	increase_loyalty(p_nation);	break;
		case 3: increase_safe(p_nation); break;
		case 4: pleed(p_nation,1); break;
		case 5: refuse(p_nation,1); break;
		case 6: pleed(p_nation,2); break;
		case 7: refuse(p_nation,2); break;
		case 8: pleed(p_nation,3); break;
		case 9: agree(p_nation,1); break;
		case 10: agree(p_nation,2); break;
		case 11: agree(p_nation,3); break;
		case 12: agree(p_nation,4); break;
		case 13: agree(p_nation,5); break;
		case 14: agree(p_nation,6); break;
		case 15: agree(p_nation,7); break;
		case 16: agree(p_nation,8); break;
		case 17: agree(p_nation,9); break;
		case 18: agree(p_nation,10); break;
		case 19: agree(p_nation,11); break;
		case 20: break;
		case 21: final_announce(p_nation); break;
		default:
			return;
	}
	step++;
	call_out("chengdi_step",4,p_nation,step);
}
void final_announce(string p_nation) {
	string dis;
	dis=CHAR_D->get_char(p_nation,"name");
	dis+="��"+DAY_D->query_chinese_day()+"�Ƶۡ�\n";
	chengdi_announce(dis);
	HIS(dis);
	
}
mixed do_chengdi(string p_nation) {
	int pop;
	pop=COUNTRY_D->get_country(p_nation,"gold");
	COUNTRY_D->set_country(p_nation,"gold",pop-100000);
	pop=CHAR_D->get_char(p_nation,"reputation"); // p_nation is the king's id
	CHAR_D->set_char(p_nation,"reputation",pop*2);
	COUNTRY_D->set_country(p_nation,"level",1);
	call_out("chengdi_step",1,p_nation,1);
}

