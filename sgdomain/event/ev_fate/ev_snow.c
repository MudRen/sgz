mixed get_alert_msg(string city,int times)
{
return 1; //NO_ALERT
}
int can_do_fate(string city)
{mapping cond = ([
                   "agriculture":120,
                   "safe":140
                  ]);
 return FATE_D->get_damage_level(city,cond,1);
}
void do_fate(string city,int r)
{
 string msg;	
 mapping effect = ([
                    "agriculture":10,
                  ]);
 FATE_D->area_effect(city,effect,r);
  msg = "%^B_MAGENTA%^%^H_CYAN%^���������"+AREA_D->get_area(city,"name")+
               "��������ѩ���ȼ�Ϊ"+chinese_number(r)+"�����ذ��ն��ֳ��졣%^RESET%^\n";
 tell(users(),msg);
 //SGSYS(msg);
}
