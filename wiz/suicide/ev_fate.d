void start(string season)
{ array tz_info;
  string filename;
  int adjust;
 tz_info = FATE_D->query_tz_info(season);
  if (!sizeof(tz_info)) SGSYS("������Ϣ��ʧ!\n");
  foreach(array info in tz_info){
        filename = "/wiz/suicide/ev_fate/ev_"+info[1];
        //SGSYS(filename);
        
        if (adjust=(filename)->can_do_fate(info[0]))
           (filename)->do_fate(info[0],adjust);
        else
           SGSYS(sprintf("%s�����%s��fate\n",info[0],info[1]));
 }   
}
 
