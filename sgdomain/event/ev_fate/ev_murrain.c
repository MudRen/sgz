int can_do_fate(string city)
{
 mapping cond = ([
                  "safe":160
                  ]);
 return FATE_D->get_damage_level(city,cond,0);
}
void do_fate(string city,int r)
{
 string msg;
 mapping effect = ([
                    "population" :-20,
                    "industry"   :-20,
                    "agriculture":-20,
                    "business"   :-20,
                  ]);
FATE_D->area_effect(city,effect,r);
  msg = "%^B_RED%^%^H_YELLOW%^�������"+AREA_D->get_area(city,"name")+
               "�������ߣ�����Ϊ"+chinese_number(r)+"��һʱ���Ļ̻̣����շ׷�Ǩ�롣%^RESET%^\n";
 tell(users(),msg);
 //SGSYS(msg);
}
