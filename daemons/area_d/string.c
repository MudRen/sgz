// string.c by fire on Dec. 20 1998
string get_area_importancestr(string p_id)
{
   int i=AREA_D->get_area(p_id,"importance");
   switch(i)
   {
    case AI_INDUSTRY:
       return "��ҵ";
    case AI_AGRICULTURE:
       return "ũҵ";
    case AI_BUSINESS:
       return "��ҵ";
    case AI_SAFE:
       return "����";
    case AI_MILITARY:
       return "����";
    default:
       return "����";
   }
}
string get_area_statusstr(string p_id)
{
        int p_st;
        p_st=AREA_D->get_area(p_id,"status");
        switch(p_st)
        {
        case ST_NOOFFICER:
                return "�հ�";
        case ST_NORMAL:
                return "����";
        case ST_WAR:
                return "ս��";
        case ST_MEETING:
                return "����";
       case ST_TRAIN:
              return "����";
        }
        return "δ֪";
}
