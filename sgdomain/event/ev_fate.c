#define LOG  "/wiz/suicide/fate.log"
inherit M_ACCESS;
void start()
{ array tz_info;
  string filename,season,msg;
  int adjust;
  array p_date;
  p_date = DAY_D->query_date(); 
if (p_date[3]!=FATE_D->get_create_year())
FATE_D->create_tz_table(p_date[3]);
  switch (p_date[2]) 
  {
   case 1:
   case 2:
   case 3:
        season="spring";
        break;
   case 4:
   case 5:
   case 6:
        season="summer";
        break;
   case 7:
   case 8:
   case 9:
        season="autumn";
        break;
   case 10:
   case 11:
   case 12:
        season="winter";
        break;
  }
   
    
tz_info = FATE_D->query_tz_info(season);
  if (!sizeof(tz_info)) SGSYS("������Ϣ��ʧ!\n");
  foreach(array info in tz_info){
 filename = "/sgdomain/event/ev_fate/ev_"+info[1];
        //SGSYS(filename);
        
        if (adjust=(filename)->can_do_fate(info[0]))
          {
           (filename)->do_fate(info[0],adjust);
   msg = sprintf("%s ���� %s ���� %d at %s \n",info[0],info[1],adjust, ctime(time()));
FATE_D->log(msg);
          }
        else
           {SGSYS(sprintf("%s�����%s��fate\n",info[0],info[1]));
 msg = sprintf("%s ��� %s at %s\n",info[0],info[1],ctime(time()));
FATE_D->log(msg);
            }
 }   
}
 
