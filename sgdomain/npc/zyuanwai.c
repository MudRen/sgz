// by fire@sgz on 27 May 1999
// zyuanwai.c  ��Ա��
inherit LIVING;
int learn_wxxy(object who)  //��ѧ����
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("sk_wuli",30);
  switch(p_res)
  {
	case LESS_EXP:
	this_object()->targetted_action("$N��$TЦ�������㾭�鲻�㣬ѧ��������\n",who);
		return;
        case TOO_TIRED:
                this_object()->targetted_action
          ("$N��$TЦ��������̫���ˣ���Ϣ�������ѧ�ɡ���\n",who);
                return 0;
        case TOO_EASY:
                this_object()->targetted_action
          ("$N��$TЦ����������Ҹ�����������ʦ�ˡ���\n",who);
                return 0;
                case LESS_LITERATE:
                        this_object()->targetted_action("$N��$T���������ѧ̫���������Щ��\n",this_body());
                        return 0;
        case CAN_LEARN:
           this_object()->targetted_action("$N��$T������һЩ������ѧ������\n",who);
           p_st=SG_SKILL_D->query_get("sk_wuli");
           who->simple_action(p_st);
           return 1;
        default :
            write("��֪Ϊʲô�������㣬������ʦ�ɡ�\n");
  }
  return 0;
}
void setup()
{
    set_name("zhang yuanwai", "��Ա��");
    set_proper_name("��Ա��");
    set_in_room_desc("���������󸻺�����Ա��(zhang yuanwai)");
    set_gender(1);
    add_id("zhang");
    set_age(50);
    add_question("rumors","rumors");
    add_question("wxxy","wxxy");
    set_sg_rongmao(-1);
}
string long() {
    return "��Ա�⣬��ͷ���ߣ���ȴ����һЩ���ϡ�\n";
}
void special_answer(object who, string matt)
{
     string p_id;
     object ob;
     string s_tmp;
     switch(matt)
     {
         case "rumors":
             this_object()->targetted_action
              ("$N��$T�����������ҵģ���ѧ����ȭ�ŷ�����ô���С�\n",who);
             break;
         case "wxxy" :
             ob=present("zhan_jishaoxin",who);
             if(!objectp(ob)) {
                 this_object()->targetted_action
                  ("$N��$T����$S��㹦����Ȼ��ǳ����Ҳֻ�����ˡ�\n",who);
                 break;
             }
             else {
                 this_object()->targetted_action
                  ("$N��$T����$R��$s���������࣬����ǳ��������$R�պ����õ��ϡ�\n",who);
                 if(learn_wxxy(who))
                     destruct(ob);
                 break;
             }
     }
}
