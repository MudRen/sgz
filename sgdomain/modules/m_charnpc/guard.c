// the body of guard by row May, 1999
#include <ansi.h>
inherit M_BLOCKEXITS;
inherit PMODULES+"m_charnpc";

void answer_enter(object who);
void answer_list(object who);
void set_up();
void my_selection(string str);
void special_answer(object who, string matt);
void input_way(string str);
void consider();
void no_answer();
void catch_player();
 string query_title(string p_id,string c_id);

void add_enter()
{
   string *exits;
   string p_area;
   object room;
   room=environment(this_object());
   if(!objectp(room)) { SGSYS("I have no room !!!"); return;}
   exits=room->query_exit_directions(1);

   if(member_array("enter",exits)!=-1) return; // enter is here
   p_area=room->get_area();
   room->add_exit("enter",AREA_D->get_area(p_area,"path") +
     AREA_D->get_area(p_area,"entry"));
}
private mixed handle_blocks( string dir )
{
    string p_nation,p_area,p_entry;
    object room;
    string p_id,y_nation;
    mixed cn;
    int time;
    time=time();
    room=environment(this_object());
    if(!objectp(room)) {SGSYS("I don't know where am i. "); return;}
    p_area=room->get_area();
    p_nation=AREA_D->get_area(p_area,"nation");
        p_entry=AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"entry");

    p_id=this_body()->query_id()[0];
    y_nation=CHAR_D->get_char(p_id,"nation");
        cn=AREA_D->get_area(p_area,"bn");
    if( !cn || !mapp(cn) ) cn = ([ ]);
        AREA_D->clear_bn(p_area);
    if(environment(this_body())->is_horse())
{this_object()->targetted_action("$Nָ��ָ$T��������֪�����Ǳ���������\n",this_body());
return "��һ˼�����ԣ�������������\n";}
        if( wizardp(this_body()) ){
        return 0;
        }
        if( cn[p_id] > time) return ::handle_blocks(dir);
    if(!y_nation) return 0; // no nation
    if(y_nation==p_nation) return 0;
    return ::handle_blocks(dir);        
}
void setup()
{
    string an_area;
    object p_obj,room;
    p_obj=previous_object();
   // room=environment(p_obj);
   // if(!objectp(room)) {SGSYS("I don't know where am i. "); return;}
   // an_area = room->get_area();
    set_area(p_obj->get_area());
    set_id(p_obj->get_area()+" guard","%^H_CYAN%^����Уξ%^RESET%^"); 
    add_id("guard");
    add_question("enter","enter");
    add_ask_str("enter","$N��$Tһ���֣�����$s��Ҫ����������֪���˿ɷ���У�\n");
    add_question("list","list");
    add_ask_str("list","$N��$Tһ���֣��������ʴ��ˣ���������ֹ���˽��룿\n");
    call_out("add_enter",random(10)+1);   
    add_block("enter");
    set_block_action( "$N����һ�������ţ�$m�������ȥ�����������ҡ�\n");
    set_in_room_desc(query_title("",""));
}
string long()
 {
    string my_area;
    string a_id;
    my_area=this_object()->get_area();
    a_id=AREA_D->get_area(my_area,"name");
    return a_id+"����Уξ��ר�Ÿ�������İ�ȫ�������ˡ�\n"+
"������������̲������һ�����ˡ�\n"+
"����Ҫ���룬�������ʹ������� %^H_CYAN%^ask guard about enter%^RESET%^ ��\n";
 }
 string query_title(string p_id,string c_id)
 {
    string p_nationname;
    string p_areaname,an_area;

    an_area = this_object()->get_area();
    p_areaname=AREA_D->get_area(get_area(),"name");
    p_nationname=COUNTRY_D->get_country(AREA_D->get_area(get_area(),"nation"),"name");
    return ""HIC"��"+p_nationname+"��"HIY"��"+p_areaname+"�����Уξ"NOR"("+an_area+" guard)";
 }
void extra_init()
 {
	add_id("guard");
 }
void do_my_speak()
{
        switch(random(5))
                {
                case 0:
                this_object()->simple_action(
                "$N�������Ŀ��ע���Ź��������ˣ����ﲻ֪������߶ʲô��\n");
                break;
                case 1:
                this_object()->simple_action(
                "$Nһ��һ��ص������Ƕ���ʵ�㣬�������ҿ�û�ù��ӳԡ�����\n");
                break;
                case 2:
                this_object()->responda("beat");
                break;
                case 3:
                this_object()->responda("slap");
                break;
                case 4:
                this_object()->simple_action(
                "$N�����ȵ����㣬����̧��ͷ���������������ģ���\n");
                break;
                default:
                this_object()->simple_action(
                "$N��������������������ã�һ�ж���˵������\n");
                break;
                }
}
void my_charaction()
{
       do_my_speak();
}
void special_answer(object who, string matt)
 {
   switch(matt)   {
       case "enter" :
          answer_enter(who);
                 return;
       case "list" :
	  answer_list(who);
   }
 }
 void answer_enter(object who)
 {
        string p_id,p_area, area;
        string p_entry,p_short,p_fly;
	mixed cn;
        int p_lo;
        int time;
	int p_chance;
	p_chance=random(50);
        time=time();
        p_id=who->query_id()[0];
        area = environment(this_object())->get_area();
        p_lo=CHAR_D->get_char_loyalty(p_id,AREA_D->get_area(area,"nation"));
        p_entry=AREA_D->get_area(area,"path")+AREA_D->get_area(area,"entry");
        //enter the random placeof a city added by suicide in 2001.03.16
       //rem this section for prepare to open in SGZII
        //if (p_entry=AREA(area)->get_random_room())
          //  p_entry=AREA_D->get_area(area,"path")+p_entry;
       // else
           p_entry=AREA_D->get_area(area,"path")+AREA_D->get_area(area,"entry");

        p_fly=AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"path")+
           AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"fly");
        p_short=load_object(p_entry)->short();
        cn=AREA_D->get_area(area,"bn");
    if( !cn || !mapp(cn) ) cn = ([ ]);
        AREA_D->clear_bn(area);
        if( wizardp(who) ){
        this_object()->simple_action("$Næ����ѽ��ԭ������ʦ���ˣ��������롣\n");

        this_object()->responda("bow "+who->query_primary_id());
        this_body()->move(p_entry);
        tell_user(p_id,"���ڳ���Уξ��ָ���£�������"+p_short+"��\n");
        return;
        }
        if( cn[p_id] > time ) 
        {
        this_object()->targetted_action(
"$N��Ǻॡ�һ���γ��ֵ���ָ��$T�����ȵ�����$r�����ѱ������������\n"+
"��������������ǰ��ʧ��Ҫ��Ȼ���ߺߡ�����\n",who);
	this_body()->simple_action("$N��ʧɫ����æ�ӻ���"+COUNTRY_D->get_country(CHAR_D->get_char(p_id,
"nation"),"name")+"��\n");
        this_body()->move(p_fly);
        return;
        }
        if( p_area == area ){
        this_object()->targetted_action("$N����$R�˱�����ʿ��ֱ�ӽ����ɡ�\n",who);
        return;
        }
        if(CHAR_D->get_char(p_id,"nation")==AREA_D->get_area(area,"nation"))
        {
        this_object()->targetted_action(
"$N��������ͬ��Ϊ�٣����ؿ�����$Rֱ�ӽ����ɡ�\n",who);
        return;
        }
        if( !COUNTRY_D->nation_exist(CHAR_D->get_char(p_id,"nation")) ){
                this_object()->targetted_action(
"$N����$Tһ�ۣ�Ŷ��$R�����������ˣ��Լ���ȥ�ɡ�\n",who);
                return;
        }
        if(p_lo>39){
                this_object()->targetted_action(
"$Næ����ԭ����$m$R��ʧ��ʧ������������\n",who);
                tell_user(p_id,"���ڳ���Уξ��ָ���£�������"+p_short+"��\n");
                this_body()->move(p_entry);
                return;
        }
        else if (p_lo == 1 && p_chance == 3) {
			DELAY_D->delay_targetted_action(this_object(),this_body(),
"$N��Ǻॡ�һ���γ��ֵ���ָ��$T�����ȵ�����$r�����в��壬�����ӯ��\n"+
"���ѱ��ҹ���Ӱͨ������������Ͷ���������������ӣ�\n",2);
			call_out("catch_player",2);
		}
		else {
        this_object()->targetted_action(
"$N���´�����$Tһ���������㵽�����ʲô����ʵ������\n",who);
        tell_user(p_id,"�������������׷����ȥ��\n");
        remove_call_out("my_selection");
        call_out("my_selection", 1, p_id);
        return;
        }
}
void my_selection(string str)
{
        object usr;
        usr=CHAR_D->find_char(str);
        if( !objectp(usr) ) return;
        tell_user(str,"�����ȡʲô�Բߣ�\n"+
"������������������������������������������������������������������\n"+
"  1����¸    2������    3��Ȱ��    4����Ū    5������    6������\n"+
"������������������������������������������������������������������\n"+
"���������ѡ��(1--5)��\n");
        call_out("no_answer",30);
        usr->modal_push((: input_way:),"���������ѡ��(1--6)��\n");
}
void input_way(string str)
{
        object me,usr;
        int p_chance,p_chance1,p_select,meili,wuli,zhimou,p_lo,num,p_rep;
        string p_id,p_fly,area,p_prison;
        remove_call_out("no_answer");
        if( !str || !stringp(str) )return;
        me=this_body();
        if(!objectp(me)) return;
        p_id=this_body()->query_id()[0];
        wuli=this_body()->query_sk_level("sk_wuli");
        meili=this_body()->query_sk_level("sk_meili");
        zhimou=this_body()->query_sk_level("sk_zhimou");
	p_rep=CHAR_D->get_char(p_id,"reputation");
        p_chance=random(20);
        p_chance1=random(5);
        area = environment(this_object())->get_area();
        p_lo=CHAR_D->get_char_loyalty(p_id,AREA_D->get_area(area,"nation"));
        p_fly=AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"path")+
           AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"fly");
        p_prison=AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"path")+
           AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"prison");
        usr=find_user(p_id);
        if(!objectp(usr)) return;
        switch(str){
                case "1":
                        this_body()->targetted_action(
"$N������Ц�ض�$T����$s����������˵����ţ���Щ���ӡ�������Ц�ɡ�\n",this_object());
                        if(this_body()->query_all_con_money()<2500){
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nŭ�����㵱����ɵ�ϰ�����������Ǯ����\n",2);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nһ���֣��ȵ��������ţ����Ұ�$m���$rץ������\n",3);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"���߾�ʿһӵ���ϣ���$T���˸����ʵʵ��ֱ�����ζ�ȥ��\n",4);
                                DELAY_D->delay_simple_action(this_body(),
"��$N���ѹ�����ʱ�����$n�Ѿ��ڴ������ˡ�\n",5);
                                this_body()->move(p_prison);
                                if (p_chance<3)
                                {
                                if( p_lo > 20 ){
                                        p_lo=p_lo-1;
                                        CHAR_D->set_char_loyalty(p_id,AREA_D->get_area(area,"nation"),p_lo);
                                        DELAY_D->delay_simple_action(this_body(),
"$T����$n��"+COUNTRY_D->get_country(AREA_D->get_area(area,"nation"),"name")+
"�Ĺ�ϵ�½���һ�㡣\n",8);

                                                }
                                return;
                                }
                                }
                        else{
                                this_body()->targetted_action(
"$N͵͵������ʮ��������������$T��\n",this_object());
                                if (p_chance<5)
                                {
                                if ((p_chance1==1)||(p_chance1==2)||(p_chance1==3))
                                {
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nŭ��������Ϊ�һ��ں���ЩСǮ��̫С�����ˣ�\n$N��Ǯ�ӻ���$T��\n",2);
                                call_out("catch_player",2);
                                }
                                else{
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nŭ��������Ϊ�һ��ں���ЩСǮ��̫С�����ˣ�\n$N��Ǯ�ӻ���$T��\n",2);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nһ���֣��ȵ��������ţ����Ұ�$m���$rץ������\n",3);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"���߾�ʿһӵ���ϣ���Ҫ��$T��������\n",4);
                                DELAY_D->delay_targetted_action(this_body(),this_object(),
"$N�ŵû겻���壬��·�������Ǳ��ӻ���"+COUNTRY_D->get_country(CHAR_D->get_char(p_id,
"nation"),"name")+"��\n",5);
                                this_body()->move(p_fly);
                                if( p_lo > 10 ){
                                        p_lo=p_lo-1;
                                        CHAR_D->set_char_loyalty(p_id,AREA_D->get_area(area,
"nation"),p_lo);
                                        DELAY_D->delay_simple_action(this_body(),
"$N����$n��"+COUNTRY_D->get_country(AREA_D->get_area(area,"nation"),"name")+
"�Ĺ�ϵ�½���һ�㡣\n",8);

                                        }
                                }
                                }
                                if ((p_chance>5)||(p_chance==5))
                                {
                             this_body()->set_all_con_money(this_body()->query_all_con_money()-2500);
                                this_object()->responda("grin");
                                if (p_lo<30){
                                p_lo=p_lo+1;
                                CHAR_D->set_char_loyalty(p_id,AREA_D->get_area(area,"nation"),p_lo);
                                DELAY_D->delay_simple_action(this_body(),"$N����$n��"+
COUNTRY_D->get_country(AREA_D->get_area(area,"nation"),"name")+"�Ĺ�ϵ������һ�㡣\n",8);
                                }
                                this_object()->simple_action(
"$N���İ�Ǯ���£�����������֪��֪����֪����֪��֪����֪��������\n");
                                call_out("consider",3);
                                }
                        }
                        break;
                case "2":
                        this_body()->simple_action(
"$N��һ������������������$M�㶼����ʶ�����ǻ�ɷ���\n�İ��������������㵣�������𣿣�\n");
                        if (wuli+p_chance<55){
                                if ((p_chance1==1)||(p_chance1==2)||(p_chance1==3))
                                {
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$N��Цһ�����ͣ��ҹ�����ʲ�ﶫ����������ͱ����������أ�\n",2);
                                call_out("catch_player",2);
                                }
                                else{
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$N��Цһ�����ͣ��ҹ�����ʲ�ﶫ����������ͱ����������أ�\n",2);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nһ���֣��ȵ��������ţ����Ұ�$m���$rץ������\n",3);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"���߾�ʿһӵ���ϣ���Ҫ��$T��������\n",4);
                                DELAY_D->delay_targetted_action(this_body(),this_object(),
"$N�ŵû겻���壬��·�������Ǳ��ӻ���"+COUNTRY_D->get_country(CHAR_D->get_char(p_id,
"nation"),"name")+"��\n",5);
                                this_body()->move(p_fly);
                                if (p_lo>10){
                                        p_lo=p_lo-1;
                                        CHAR_D->set_char_loyalty(p_id,AREA_D->get_area(area,
"nation"),p_lo);
                                        DELAY_D->delay_simple_action(this_body(),
"$N����$n��"+COUNTRY_D->get_country(AREA_D->get_area(area,"nation"),"name")+
"�Ĺ�ϵ�½���һ�㡣\n",8);

                                }
                                }
                                }
                        else {
                                this_object()->responda("fear");
                                call_out("consider",2);
                        }
                        break;
                case "3":
                        this_body()->targetted_action(
"$N΢Ц�Ŷ�$T����Ϊ��Ӧ�㿪����֮�ţ���������$s��ȥ�����ձ��д�����ĺô���\n",this_object());
                        if (meili+p_chance<55){
                                if ((p_chance1==1)||(p_chance1==2)||(p_chance1==3))
                                {
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nб��$Tһ�ۣ���Ц�����������ƾ�㣿��������Һô����Ҫ�����������ˡ�\n",2);
                                call_out("catch_player",2);
                                }
                                else{
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nб��$Tһ�ۣ���Ц�����������ƾ�㣿��������Һô����Ҫ�����������ˡ�\n",2);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nһ���֣��ȵ��������ţ����Ұ�$m���$rץ������\n",3);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"���߾�ʿһӵ���ϣ���Ҫ��$T��������\n",4);
                                DELAY_D->delay_targetted_action(this_body(),this_object(),
"$N�ŵû겻���壬��·�������Ǳ��ӻ���"+
COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name")+"��\n",5);
                                this_body()->move(p_fly);
                                if (p_lo>10){
                                        p_lo=p_lo-1;
                                        CHAR_D->set_char_loyalty(p_id,
AREA_D->get_area(area,"nation"),p_lo);
                                        DELAY_D->delay_simple_action(this_body(),
"$N����$n��"+COUNTRY_D->get_country(AREA_D->get_area(area,"nation"),"name")+
"�Ĺ�ϵ�½���һ�㡣\n",8);

                                }
                                }
                        }
                        else {
                                this_object()->responda("ok");
                                call_out("consider",2);
                        }
                        break;
                case "4":
                        this_body()->targetted_action(
"$N���صشչ�ȥ��$T�����������������װ��̽����ģ��������\n"+
"��ɣ�����ҽ�ȥ���Ա�������������\n",this_object());
                        if (zhimou+p_chance<55){
                                if ((p_chance1==1)||(p_chance1==2)||(p_chance1==3))
                                {
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nɨ��$T���ۣ���Ц����ƾ����㱾�������ң�������ʮ��ɣ�\n",2);
                                call_out("catch_player",2);
                                }
                                else{
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nɨ��$T���ۣ���Ц����ƾ����㱾�������ң�������ʮ��ɣ�\n",2);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nһ���֣��ȵ��������ţ����Ұ�$m���$r���ȥ��\n",3);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"���߾�ʿһӵ���ϣ����ƴ����������$T��ƨƨ�ϲ���һ�š�\n",4);
                                DELAY_D->delay_targetted_action(this_body(),this_object(),
"$Nֻ���������Ƽ���һ�㣬�ͷɻ�"+
COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name")+"ȥ�ˡ�\n",5);
                                this_body()->move(p_fly);
                                if (p_lo>10){
                                        p_lo=p_lo-1;
                                        CHAR_D->set_char_loyalty(p_id,
AREA_D->get_area(area,"nation"),p_lo);
                                        DELAY_D->delay_simple_action(this_body(),
"$N����$n��"+COUNTRY_D->get_country(AREA_D->get_area(area,"nation"),"name")+
"�Ĺ�ϵ�½���һ�㡣\n",8);

                                }
                                }
                        }
                        else {
                                this_object()->responda("ah");
                                call_out("consider",2);
                        }
                        break;
		case "5":
                        this_body()->targetted_action(
"$Nһ�ѱ�ס$T�Ĵ��ȣ��ü������ʵ������������ˣ�$s�ҹٵ�ְ΢����;������ĬĬ���ţ������и�����ɡ�����\n",this_object());
                        if (p_rep>2000){
			if ((p_chance1==1)||(p_chance1==2)||(p_chance1==3))
				{
				DELAY_D->delay_targetted_action(this_object(),this_body(),
"$N�����һЦ������$m���������������⣬Ϊ�ν�����˵���������������������ͼ������\n",2);
                                call_out("catch_player",2);
                                }
                                else{
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$N�����һЦ������$m���������������⣬Ϊ�ν�����˵���������������������ͼ������\n",2);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"$Nһ���֣��ȵ��������ţ����Ұ�$m���$r���ȥ��\n",3);
                                DELAY_D->delay_targetted_action(this_object(),this_body(),
"���߾�ʿһӵ���ϣ����ƴ����������$T��ƨƨ�ϲ���һ�š�\n",4);
                                DELAY_D->delay_targetted_action(this_body(),this_object(),
"$Nֻ���������Ƽ���һ�㣬�ͷɻ�"+
COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name")+"ȥ�ˡ�\n",5);
                                this_body()->move(p_fly);
                                if (p_lo>10){
                                        p_lo=p_lo-1;
                                        CHAR_D->set_char_loyalty(p_id,
AREA_D->get_area(area,"nation"),p_lo);
                                        DELAY_D->delay_simple_action(this_body(),
"$N����$n��"+COUNTRY_D->get_country(AREA_D->get_area(area,"nation"),"name")+
"�Ĺ�ϵ�½���һ�㡣\n",8);

                                }
                                }
                        }
                        else {
                                this_object()->responda("comfort");
                                call_out("consider",2);
                        }
                        break;			
                default:
                        this_body()->simple_action(
"$Nʧ����̾��һ������������Ȼ��ˣ������˰ɡ�\n");
        }
        this_body()->modal_pop();
        return;
}
void consider()
{
        string p_id,area,p_entry,p_short;
        area = environment(this_object())->get_area();
        p_entry=AREA_D->get_area(area,"path")+AREA_D->get_area(area,"entry");
        // enter the random placeof a city added by suicide in 2001.03.16
        // rem this section for prepare to open in SGZII
     // if (p_entry=AREA(area)->get_random_room())
      //    p_entry=AREA_D->get_area(area,"path")+p_entry;
     // else
        p_entry=AREA_D->get_area(area,"path")+AREA_D->get_area(area,"entry");
        p_short=load_object(p_entry)->short();
        p_id=this_body()->query_id()[0];
        this_object()->targetted_action("$N������Ȼ��ˣ�$m$R������ɡ�\n",this_body());
        tell_user(p_id,"���ڳ���Уξ��ָ���£�������"+p_short+"��\n");
        this_body()->move(p_entry);
        this_body()->responda("hehe");
        return;
}
void catch_player()
{
        int time;
        string p_id,p_prison,area;
        time=time();
        area = environment(this_object())->get_area();
        p_prison=AREA_D->get_area(area,"path")+AREA_D->get_area(area,"prison");
        p_id=this_body()->query_id()[0];
        DELAY_D->delay_targetted_action(this_object(),this_body(),
         "$Nһ���֣��ȵ��������ţ����Ұ�$m���$rץ������\n",3);
        DELAY_D->delay_targetted_action(this_object(),this_body(),
         "���߾�ʿһӵ���ϣ���$T���˸����ʵʵ��ֱ�����ζ�ȥ��\n",4);
        DELAY_D->delay_simple_action(this_body(),
          "��$N���ѹ�����ʱ�����$n�Ѿ��ڴ������ˡ�\n",5);
        CHAR_D->put_prison(p_id,2);
        return;
}
void no_answer()
{
        remove_call_out("no_answer");
        this_body()->responda("sigh");
        this_body()->simple_action("$Nʧ���ص�����Ȼ��ˣ������˰ɡ�����\n");
        this_body()->modal_pop();
        return;
}
void answer_list(object who)
{
	int i;
	string here, out;
	object env;
	mapping bn;

	env = environment(this_object());
	here = env->get_area();
	out = "";
	if( !here||!stringp(here) )
		this_object()->simple_action("$N�������Լ���ͷ�������������Ķ�����\n");
	else if( !(bn=AREA_D->get_area(here,"bn"))||!mapp(bn)||!sizeof(bn) )
		this_object()->simple_action("$Nҡҡͷ������������û�н�ֹ�κ���ͨ�С�\n");
	else {
		foreach( string nn in keys(bn) ){
			i++;
			out = out + sprintf("(%-2d)%-12s%-16s%10s\n", i, COUNTRY_D->get_country(CHAR_D->get_char(nn,"nation"),"name"),CHAR_D->get_char(nn,"name")+"("+nn+")",
				(bn[nn]<time()?"��ʧЧ":"����Ч"));
		};
more(this_object()->short()+"ת���ó�һ��������������������ֹ�����˵�ͨ�У�\n"+out+"\n");
	}
}


