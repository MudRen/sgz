mixed get_base(string b_id,string wat);
string stat_me(string p_id)
{
	string p_ret="";
   	mixed c;
   	array ks;
   	int i;

   	if( (!p_id)||(p_id=="") ) p_id="list";
   	if(p_id=="list") {
    	p_ret= "���������嵥��\n";
      	p_ret+="��������������������������������������������������������������������������\n";
      	c=get_base("list","");
      	ks=({});
      	for(i=0;i<sizeof(c);++i) ks+=({get_base(c[i],"name")+"("+c[i]+")"});
      	p_ret+=sprintf("%-#79s\n", implode(ks, "\n"));
   	} else {
		c=get_base(p_id,"");
       		if( !mapp(c) ){
          		p_ret="û�������������ء�\n";
       		} else {
          	p_ret="����ID��"+p_id+"   �������ƣ�"+c["name"]+"\n";
			p_ret+="����Ҫ��"+c["safe"]+"\n";
			p_ret+="�˿�Ҫ��"+c["pop"]+"\n";
			p_ret+="���"+c["gold"]+"\n";
			p_ret+="�����������ƣ�"+c["roomname"]+"\n";
			p_ret+="�������ƣ�"+c["workername"]+"\n";
			p_ret+="��ͷ���ƣ�"+c["headname"]+"\n";
			p_ret+="����ϵ����\n";
			p_ret+="��ҵ��"+c["si"]+" ũҵ��"+c["sa"]+" ��ҵ��"+c["sb"]+"\n";
			p_ret+="������"+c["ss"]+" ������"+c["sp"]+" �ǻۣ�"+c["sw"]+"\n";
			p_ret+="ȱʡ��Ʒ��"+BASE_D->get_stuff(c["defproduct"],"name")+"\n";
			if(sizeof(c["products"])) {
				p_ret+="������Ʒ�б�";
				foreach (string pn,int pl in c["products"]) {
					p_ret+=BASE_D->get_stuff(pn,"name")+"("+pl+") " ;
				}
				p_ret+="\n";
			}
			if(sizeof(c["area"])) {
				p_ret+="�޶�������\n";
				foreach(string a in c["area"]) {
					p_ret+=AREA_D->get_area(a,"name")+"  ";
				}
				p_ret+="\n";
			}
		}
   	}
	return p_ret;
}
string show_balance(int t) {
	string *list;
	string ret;
	list=BASE_D->get_stuff("list");
	list=filter_array(list,(: BASE_D->get_stuff($1, "type")==$(t) :));
	switch(t) {
	case 1:
		ret="����ԭ�������ࣺ------------------------------------------------------------\n";
		break;
	case 2:
		ret="���Ʒ�ࣺ------------------------------------------------------------------\n";
		break;
	case 3:
		ret="�������������ࣺ------------------------------------------------------------\n";
		break;
	case 4:
		ret="���������ࣺ----------------------------------------------------------------\n";
		break;
	case 0:
		ret="δ�������ʣ�----------------------------------------------------------------\n";
		break;
	}
	if(sizeof(list)) {
		foreach(string l in list) {
			ret+=sprintf("%-25s %5d  %5d%s  %.2f\n",BASE_D->get_stuff(l,"name")+"("+l+") ",
				BASE_D->get_stuff(l,"work"),BASE_D->get_stuff(l,"quantity"),
				BASE_D->get_stuff(l,"unit"),BASE_D->get_stuff(l,"real_work")*1.0/BASE_D->get_stuff(l,"quantity"));
		}
		ret+="\n";

	}
	return ret;
}
string show_group_list(int t) {
	string *list;
	string ret;
	list=BASE_D->get_stuff("list");
	list=filter_array(list,(: BASE_D->get_stuff($1, "type")==$(t) :));
	switch(t) {
	case 1:
		ret="����ԭ�������ࣺ------------------------------------------------------------\n";
		break;
	case 2:
		ret="���Ʒ�ࣺ------------------------------------------------------------------\n";
		break;
	case 3:
		ret="�������������ࣺ------------------------------------------------------------\n";
		break;
	case 4:
		ret="���������ࣺ----------------------------------------------------------------\n";
		break;
	case 0:
		ret="δ�������ʣ�----------------------------------------------------------------\n";
		break;
	}
	if(sizeof(list)) {
		int k=0;
		foreach(string l in list) {
			ret+=sprintf("%-25s",BASE_D->get_stuff(l,"name")+"("+l+") ");
			k++;
			if(k%3==0)
				ret+="\n";
		}
		ret+="\n";

	}
	return ret;
}
string show_stuff_list() {
	string ret;
	int i;
	ret="���������嵥��\n";
	ret+=show_group_list(1);
	ret+=show_group_list(2);
	ret+=show_group_list(3);
	ret+=show_group_list(4);
	ret+=show_group_list(0);
	return ret;
}
string show_stuff(string stf) {
	string ret;
	mapping consume,bs;
	string *src;
	if(!BASE_D->stuff_exist(stf)) return "û���������ʡ�\n";
	ret="ID: "+stf+"\n";
	ret+="���ƣ�"+BASE_D->get_stuff(stf,"name")+"\n";
	ret+="һ��������λ��"+BASE_D->get_stuff(stf,"quantity")+
		BASE_D->get_stuff(stf,"unit")+"\n";
	ret+="ֱ�����������ģ�"+BASE_D->get_stuff(stf,"work")+"\n";
	consume=BASE_D->get_stuff(stf,"consume");
	if(mapp(consume)&&sizeof(consume)) {
		ret+="��Ҫԭ�ϣ�";
		foreach(string s,int v in consume)
			ret+=BASE_D->get_stuff(s,"name")+"("+v+") ";
		ret+="\n";
		ret+="�����������ģ�"+BASE_D->get_stuff(stf,"real_work")+"\n";
	}
	src=BASE_D->get_stuff(stf,"src");
	if(sizeof(src)) {
		ret+="�������������ʵ�ԭ�ϣ�\n ";
		foreach(string s in src) {
			ret+=BASE_D->get_stuff(s,"name")+"("+s+") ";
		}
		ret+="\n";
	}
	bs=BASE_D->get_stuff(stf,"base");
	ret+="�����������أ�\n";
	if(sizeof(bs)) {
		foreach(string b,int lv in bs)
			ret+=BASE_D->get_base(b,"name")+"("+b+") "+ "����"+lv+"\n";
	}
	ret+="��λ��Ʒ������������"+sprintf("%.2f\n",
		BASE_D->get_stuff(stf,"real_work")*1.0/BASE_D->get_stuff(stf,"quantity"));
	ret+="��ע��"+BASE_D->get_stuff(stf,"comment");
	return ret;
}
