// queitem.c by fire@lima in Nov 1998
// this is used to test if this is a robot by item test
string q1(string p_id)
{
   string a,ta;
   string *as,*al;
   int *ds,td;
   int ismin,md,i;
   string question,ret;

   al=AREA_D->list_areas();

   as=({});
   a=al[random(sizeof(al))];
   al-=({a});
   	/*printf("al = ");
	foreach(string temp in al)
		printf("%s ", temp);
	printf("\n");*/
   
   ds=({});

   while(sizeof(as)<4) {
	ta=al[random(sizeof(al))];
	td=AREA_D->get_distance(a,ta);
	al-=({ta});
	if(td<=1) continue;
	if(td>5) continue;
	if(member_array(td,ds)==-1) {
		as+=({ta});
		ds+=({td});
	}
   }

   ismin=random(2); // 1 min, 0 max

   ismin=1;
   question="���е����У�����"+HZK2ASC_D->hzk2asc(AREA_D->get_area(a,"name"))+
    "��"+ (ismin==1 ? "��" : "Զ" )+"���ǵڼ���������\n";
   md=ds[0];
   ret="1";
   question+="1 "+AREA_D->get_area(as[0],"name")+"  ";

   for(i=1;i<4;++i) {
      question+=(i+1)+" "+AREA_D->get_area(as[i],"name")+"  ";

      if((ds[i]<md)&&(ismin==1)) {
	ret=""+(i+1);
	md=ds[i];
      }
      if((ds[i]>md)&&(ismin==0)) {
	ret=""+(i+1);
	md=ds[i];
      }
   }
//   question+="��֪������ <%^RED%^ !map northwest, map southwest, map northeast or map southeast %^RESET%^ >��ѯ\n����ZMUD��������Ctrl-R�ر�parse\n";
	question+="\n��ʾ����׼��Ϊ"+HZK2ASC_D->hzk2asc(AREA_D->get_area(as[(to_int(ret)-1)],"name"));
   tell_user(p_id,question);
   return ret;
}

string test(string p_id)
{
   string ret;
   switch(random(2))
   {
      case 0:  // ��һ��
        ret=q1(p_id);
        return ret;
      case 1: 
        ret=q1(p_id);
        return ret;
   }
}
