int can_do_fate(string city)
{mapping cond = ([
                  "safe":160
                  ]);
 return FATE_D->get_damage_level(city,cond,1);
}
void do_fate(string city,int r)
{
 string msg;
 array objname=({"����","��","����","ͭ��","ͭȸ",
 "ͭ��","����","��ӡ","�����","����"}) ;
 mapping effect = ([
                    "agriculture":10,
                    "industry"   :10,
                    "business"   :10,
                    "population" :20
                   ]);
FATE_D->area_effect(city,effect,r);
  msg = "%^B_MAGENTA%^%^H_CYAN%^��ҥ�ԡ�ĳ�ˣ�"+AREA_D->get_area(city,"name")+
 "�����ڳ�ǰ����"+ chinese_number(r)+"������"+objname[r-1]+
        "�׷���Ϊ�������ʵ������\n%^RESET%^";
 tell(users(),msg);
 //SGSYS(msg);
}
