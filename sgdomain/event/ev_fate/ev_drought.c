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
                    "population" :-10,
                    "st"         :-10,
                    "agriculture":-10
                  ]);
FATE_D->area_effect(city,effect,r);
  msg = "%^B_RED%^%^H_YELLOW%^�������"+AREA_D->get_area(city,"name")+
                 "�ú����꣬����Ϊ"+chinese_number(r)+"�����ذ��սп����졣%^RESET%^\n";
 tell(users(),msg);
 //SGSYS(msg);
}
