//������ by row
#include <ansi.h>
#include <mudlib.h>
#define PCHOPPORK PJOB+"choppork"
#define JOBID "choppork"
inherit LIVING;
void ask_job(object usr);
void ask_pay(object usr);
void ask_meat(object usr);
void setup()
{
	set_name("zhang tuhu","������");
	add_id("zhang");
	add_id("tuhu");
	set_in_room_desc("��"+HIC+"������һ�쵶"+NOR+"��������(zhang tuhu)");
	set_gender(1);
	set_age(45);
	add_question("job","job");
	add_question("pay","pay");
	add_question("meat","meat");
	add_question("rumors","rumors");
	add_question("here","here");
	add_question("name","name");
	add_ask_str("meat","$N��$T������ʦ���������ҵ��������ˣ������ܲ����ٸ�Щ��\n");
	add_ask_str("job","$N��$T������λ$R��$s������Щ��ɡ�\n");
	add_ask_str("pay","$N��$T��Ц����$R������������\n");
}
string long() {
	return "һλ�����Բ�����꺺�ӣ�����ֻ����һ�����ͣ�¶�������\n"+
	       "�ؼ��������ϼ�����в���һ��ѩ����ɱ���������ǻ�����\n"+
	       "��������������������׺��������ĵ�����������������һ\n"+
	       "Щ��ɣ��ԽӼ�����(ask zhang about job)��\n";
}
mixed special_answer(object ob, string str)
{
        object player;
        player = this_body();
        switch(str)
        {
        case "job":
                ask_job(player);
                return;
        case "pay":
                ask_pay(player);
                return;
	  case "meat":
                ask_meat(player);
		    return;
        case "rumors":
                this_object()->simple_action("$N���ٺ١�һЦ��¶�����׵����ݣ�"+
"��Ĳ�֪������ֻ���ð��ǻ�����һ�쵶��\n");
                return;
        case "name":
                this_object()->simple_action("$N������ֵص���"+
"������������ר���Ϻõ����⣬�뵱�갳����үүҲ������\n");
                return;
        case "here":
                this_object()->targetted_action("$N��������һָ��"+
"�������Ӱڵ���������������Ϊ�������ºó�����\n",ob);
                return;
        default:
                return;
        }
}
void ask_job(object usr)
{
        string n_id;
        int n_lasttimes,m_lasttimes;
        object ob,oc;
        n_id=usr->query_id()[0];
        if (usr->query_job(JOBID,"beg_time"))
        {
        this_object()->targetted_action(
        "$N��$T������ȥ����Ļ�ɡ�\n",usr);
        return;
        }
        if(CHAR_D->get_char(n_id,"nation"))
        {
        this_object()->targetted_action(
        "$N����������Ц������Ц�ˣ�$m$R����⾡��֨��������͸�����ȥ��\n",usr);
        return;
        }
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
        m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
        if(n_lasttimes>m_lasttimes)
        {
        this_object()->targetted_action(
        "$N��$T�����������ˣ������ɵ�������Ļ����ˣ���Ъ����ˡ�\n",usr);
        return;
        }
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        this_object()->targetted_action(
        "$N��$T�����ţ���ô���ⰳһ�˻���æ��������������Ҫ��ʮ�������ţ�������\n"+
        "������㣬�е�Ҫ���룬���õİ��ɲ��ա�Ҫ�ǲ����������ˣ������ʰ��á�\n"+
	  "(ask zhang about meat)\n",usr);
        this_object()->targetted_action(
        "$N����$Tһ��"+HIC+"�޹ǵ�"+NOR+"��һƬ%^B_WHITE%^%^H_RED%^������%^RESET%^��\n",usr);
        ob=new("/sgdomain/job/choppork/tigudao");
        ob->move(usr);
	  oc=new("/sgdomain/job/choppork/lmeat");
	  ob->move(usr);
}
void award(object usr)
{
        int isrobot;
        object ob;
        isrobot=usr->query_robot();
        if(isrobot)
        {
        this_object()->simple_action(
        "$N���ٺ١�һЦ�����ɰ���û�š�\n");
        this_object()->targetted_action(
        "$N��$Tһ�Ű�ԲֽǮ��\n",usr);
        usr->simple_action("$Nɵɵ��ֱ�֣�������Ǯ�ˣ�\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
        }
        else
        {
        string p_id;
        p_id=usr->query_id()[0];
        CHAR_D->set_char(p_id,"reputation",
        CHAR_D->get_char(p_id,"reputation")+1);
        this_object()->simple_action("$Nü����Ц����������\n");
        this_object()->targetted_action("$N��$Tʮ�������ӡ�\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(15);
        ob->move(usr);
        if(random(2)) {
              ob=new("/sgdomain/obj/other/tiezi");
              ob->move(usr);
             this_object()->targetted_action(
                "$N�ֶ�$T������λ�ɵ������ɫ���ٽ���һ�����ӡ�\n",usr);
        }
        }
}
void ask_pay(object usr)
{
        object ob;
        object tigudao;
        string n_id;
        n_id=usr->query_id()[0];
        if(!usr->query_job(JOBID,"beg_time")) {
           this_object()->targetted_action(
           "$N��һ������$T�����㿪ʲô��Ц��\n",usr);
           return;
        }
        ob=present("pork",usr);
        tigudao=present("tigudao",usr);
        if(!objectp(ob))
        {
           this_object()->targetted_action(
           "$N��һ������$T�����㿪ʲô��Ц��\n",usr);
           return;
        }
        if(ob->query_count()<20)
        {
            this_object()->targetted_action(
            "$N��$T��ҡ��ͷ����������������ȥ��Щ����\n",usr);
           return;
        }
        else
        {
            this_object()->targetted_action(
            "$N�ӹ�$T�ݹ�����%^B_WHITE%^%^H_RED%^������%^RESET%^��\n",usr);
            destruct(ob);
            if(tigudao)
                {
                this_object()->simple_action(
                "$N����Ҫ����"+HIC+"�޹ǵ�"+NOR+"��\n");
                destruct(tigudao);
                }
        this_object()->targetted_action(
        "$N��$T���ͷ�������ܺã�������Ҫ��������⿼���㡣\n",usr);
        usr->finish_job(JOBID);
        ROBOT->robot_test(usr,(:award:));
        }
}
void ask_meat(object usr)
{
        object ob,pork,smeat;
        if(!usr->query_job(JOBID,"beg_time")) {
           this_object()->targetted_action(
           "$N��һ������$T������ƭ�����⣿û��ô���ף�\n",usr);
           return;
        }
        ob=present("lmeat",usr);
        pork=present("pork",usr);
        if(objectp(ob))
        {
           this_object()->targetted_action(
           "$N��һƲ����$T�����ղŸ�����⻹û���꣬��ô����Ҫ�ˣ�\n",usr);
           return;
        }
        if(pork->query_count()>20||pork->query_count()==20)
        {
            this_object()->targetted_action(
            "$N����$T��ͷ�������������Ѿ������ˣ���������Ҫ����(ask zhang about pay)��\n",usr);
           return;
        }
        else
        {
            this_object()->targetted_action(
            "$N��$T���ͷ�������ðɣ��ٸ���һ�飬���ҪС�����ˣ�֪����\n"+
		"$N�ݸ�$Tһ��%^B_WHITE%^%^H_RED%^С����%^RESET%^��\n",usr);
            smeat=new("/sgdomain/job/choppork/smeat");
		smeat->move(usr);
        }
}