// the job of fan  people
// by fire on March 1999

static private string *sug=({
"$N同情地对众$T道：你们是世界上最勤劳的人，但却吃不饱，穿不暖。",
"$N感慨地对众$T道：你们都太忠厚了，所以尽受当官们的欺压。",
"$N叹了口气，对众$T道：你们的聪明才智远近闻名，只是没遇上明主，可惜呀可惜。",
"$N大方地对众$T道：战争时期，大家生活贫苦，这些钱，拿去买点肉吃吧。",
"$N大方地对众$T道：$s早知大家清苦，我从自己家里拿些粮食，大家分了吧。",
"$N关心地对众$T道：大家最近生活怎么样，一定很苦吧？",
"$N难过地对众$T道：你们生活这么艰难，当地还抽这么重的税，真不知道你们是怎么过日子的。",
"$N忿忿不平地对众$T道：你们主公当真是一个是非不明的大昏君！",
"$N摇摇头，对众$T道：你们太守中饱私囊，老百姓的日子当真是难熬呀。",
"$N对众$T一拱手，道：巡逻的快过来了，我得走了，告辞。",
});

static private string *good_answer=({
"众$N都唉声叹气，道：可不是吗。",
"一个$N忿忿地道：俗话说的好，马善被人骑，人善被人欺！\n众$N都附合道：没错，俺们就是太老实了。",
"众$N都摇摇头，失望地道：悔不当初呀。。。",

"$T给$N们一两金子。\n众$N都高兴地跳了起来。\n众$N纷纷道：本地的官儿从没这么善待过咱们。",
"$T通知家丁为$N们取一百粮食。\n众$N都高兴地跳了起来。\n$N纷纷道：本地的官从没这么善待过咱们。",
"众$N都恨恨地道：最近生活越来越糟糕，就差没嚼树根了。",
"一个$N咬牙切齿道：当官的只知道扒我们的皮，自己却拿俸禄享乐！\n众$N都附合道：就是，这还让不让人活了？！",
"一个$N忍不住高声道：要不是家里有老有小，我早就反了！\n另一个$N赶紧捂他的嘴：小声点，让他们听见就糟了。",
"众$N都无奈地道：唉，不知前生造了什么孽，摊上这么个主。",
"众$N纷纷点头答道：多谢$R的关怀，可别让他们抓住了。",
});

static private string *bad_answer=({
"一个$N答道：谁说的？！我们日子过得蛮不错的嘛。\n众$N纷纷点头：没错。",
"一个$N答道：谁欺负我们来着？我国官员们都在努力保卫国家。\n众$N纷纷点头：对，一致抵御他国侵略。",
"一个$N笑道：我是够聪明的，一看就知道你不怀好意。\n众$N都哈哈大笑起来。",
"$T摸了摸半天口袋，突然道：啊，不好意思，身上没带钱。\n众$N都哈哈大笑起来：蒙谁呀？当官的身上会没钱？",
"$T算计了半天，突然道：啊，不好意思，家里也没多少粮食了。\n众$N哈哈大笑起来：笑话！当官的家里会没粮吃？",
"一个$N摇摇头，道：你别乱说，大家都丰衣足食。\n众$N都纷纷点头：可不是吗。",
"一个$N「哼」了一声道：别信他的，目前税率很公平。",
"一个$N冷笑道：是吗？我看比你的主公强！\n众$N都大笑起来。",
"一个$N「嘿嘿」笑道：你又不是本地人，怎么知道？我看你才是贪污枉法的吧？\n众$N都大笑起来。",
"众$N纷纷答道：快滚吧，再不走就把你抓起来。",
});


void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);

mixed job(string m_id,string officer_id)
{
   //string m_area=CHAR_D->get_char(officer_id,"area");
   string target,mnation;
   string *alst,*alst2;
   array typ;
   object *mlist,ot;
   object o=find_body(m_id);
   
   tell_user("huaer",sprintf("m_id = %s, officer_id = %s\n",m_id,officer_id));
   if(!objectp(o)) return 0; // string

   mnation=CHAR_D->get_char(m_id,"nation");

   alst=AREA_D->list_areas();
   alst2=AREA_D->check_area("nation",mnation);
   tell_user("huaer",sprintf("alst2 = %O\n",alst2));
   alst-=alst2;

	if(!sizeof(alst)){
		o->add_job("fanpeople");
		o->finish_job("fanpeople");
	 	return "$N对$T道：难道统一啦？\n";  
	}
//Modified BY listen to make an additional check for fake guy exist
	do
	{
		target=alst[random(sizeof(alst))];
		alst-=({target});
		typ="/sgdomain/event/ev_guy"->get_array_type();
		tell_user("huaer",sprintf("typ = %O\n",typ));
		for(int i=0;i<3;i++)
		{
			ot=CHAR_D->find_npc_char(target+" "+typ[i]);
			if(!objectp(ot) || !ot->query("is_fake")) 
			{
				if (!objectp(ot))
					"/sgdomain/event/ev_guy"->create_guy(target,typ[i]);
				target=target+" "+typ[i];
				ot=CHAR_D->find_npc_char(target);

				o->set_asklist("fan","target",target);
				o->set_asklist("fan","filename",PJOB+"fanpeople/fanpeople");
				o->set_asklist("fan","funname","ask_fan");

				o->add_job("fanpeople");
				o->set_job("fanpeople","status","begin");
				if(objectp(ot))
				{
					o->set_job("fanpeople","memo","煽动"+ot->short());
					return "$N对$T道：国以民为本，就麻烦$R去煽动一下"+
					ot->short()+"，\n见面就说ask "+target+" about fan 。\n";
				}
				else
				{
					LISBUG("fail to creat!\n");
					return "$N对$T道: 有错误发生，请报告巫师修复!\n";
				}
   
			}
		}
	}while (!sizeof(alst));
	return "$N对$T道：暂时无法申请任务，请稍后再试。\n";  
}
void ask_fan(object me, object target)
{
        string m_area,m_id;
	string m_title;
	string t_area,nat;
	int loy;
	
	if(target->query("is_fake"))
		LISBUG("fake people got faned");
	target->set("is_locked",1);
        m_id=me->query_primary_id();
        m_area=CHAR_D->get_char(m_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
        me->targetted_action(
      "$N对众$T笑着说道：过来，过来：$s有些话和你们讲。\n"
          ,target);
        me->clear_asklist("fan");
        me->set_job("fanpeople","status","done");

        me->set_job("fanpeople","topics",({})); //haven't talk yet                    
             
                                     // within 10 minute
        me->set_job("fanpeople","score",20); // meet is 10
                                              // succ is 50

        if(sizeof(target->query_pure_leader())) {
			target->targetted_action("$N对$T道：我们正忙呢。\n",me);
	       tell_user(m_id,"%^H_GREEN%^任务完成得不错，快去太守处领赏吧。\n%^RESET%^");
			target->check_leader();

			return;
		}
        DELAY_D->delay_targetted_action(
                target,me,"一个$N道：看他贼眉鼠眼的，不象个好人。\n"+
                "另一个$N道：管他谁的，先听听看。\n",1);

        target->set_leader(m_id); // target will not do nonsence

		call_out("select_way",2,({ me, target}));

	t_area=target->query_room()->get_area();

        CHAR_D->set_char(m_id,"catch_time",time()+600);
        CHAR_D->set_char(m_id,"catch_file",PJOB+"fanpeople/fanpeople");
        CHAR_D->set_char(m_id,"catch_function","fan_catch");
        CHAR_D->set_char(m_id,"catch_para",target);
        CHAR_D->set_char(m_id,"catch_area",t_area);

	nat=AREA_D->get_area(t_area,"nation");
	loy=CHAR_D->get_char_loyalty(m_id,nat);
	loy--; loy=bmax(1,loy);
	CHAR_D->set_char_loyalty(m_id,nat,loy);

        return;
}

void recruit_catch(string o_id,string p_id,object o_people)
{
        object o_o,o_p;
        if(objectp(o_people)){
                string pep_id;
                o_people->simple_action(
                        "一个$N大喊：不得了啦，差人抓人来啦。\n众$N一哄而散。\n");
		o_people->do_my_dispear();
        }
        o_p=find_user(p_id);
        if(objectp(o_p))
            o_p->modal_pop();
        o_o=find_body(o_id);
        if(!objectp(o_o)) return;
        o_p=find_body(p_id);
        if(!objectp(o_p)) {
                tell_user(o_id,"晚了一步，"+
                        CHAR_D->get_char(o_id,"name")+"跑了。\n你的工作成绩下降了。\n");
                o_o->set_job("partol","score",
                        o_o->query_job("partol","score")-1);
                return;
        }
        o_o->targetted_action(
                "$N对$T大喝一声：大胆$r，竟然在此征兵，给我拿下！\n",o_p);
        o_p->simple_action(
                "众官兵一拥而上，把$N捆得结结实实。\n");
        o_o->simple_action(
                "$N一挥手道：带走。\n");
        o_p->simple_action(
                "众官兵把$N押了下去。\n");

        CHANNEL_D->deliver_tell("rumor","system",
                CHAR_D->get_char(p_id,"name")+
                "在"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
                "征兵，被正在巡逻的"+CHAR_D->get_char(o_id,"name")+
                "当场抓获。");
        (PCMD+"catch")->catch_award(o_id,p_id);

}

void fan_catch(string o_id,string p_id,object o_people)
{
        object o_o,o_p;
        if(objectp(o_people)){
                string pep_id;
                o_people->simple_action(
                        "一$N大喊：不得了啦，差人抓人来啦。\n众$N一哄而散。\n");
		o_people->do_my_dispare();
        }
        o_p=find_user(p_id);
        if(objectp(o_p))
                o_p->modal_pop();
        o_o=find_body(o_id);
        if(!objectp(o_o)) return;
        o_p=find_body(p_id);
        if(!objectp(o_p)) {
                tell_user(o_id,"晚了一步，"+
                        CHAR_D->get_char(o_id,"name")+"跑了。\n你的工作成绩下降了。\n");
                o_o->set_job("partol","score",
                        o_o->query_job("partol","score")-1);
                return;
        }
        o_o->targetted_action(
                "$N对$T大喝一声：大胆$r，竟然在此煽动百姓闹事，给我拿下！\n",o_p);
        o_p->simple_action(
                "众官兵一拥而上，把$N捆得结结实实。\n");
        o_o->simple_action(
                "$N一挥手道：带走。\n");
        o_p->simple_action(
                "众官兵把$N押了下去。\n");

        CHANNEL_D->deliver_tell("rumor","system",
                CHAR_D->get_char(p_id,"name")+
                "在"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
                "煽动百姓闹事，被正在巡逻的"+CHAR_D->get_char(o_id,"name")+
                "当场抓获。");
        
        (PCMD+"catch")->catch_award(o_id,p_id);

}
void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
        string p_id,t_id,mnation,marea;
        mixed gift;
        int ans=0;
        int safe,score,p_select,meili;

        if(!objectp(me)) return;
        if(!objectp(tar)) { return;}

		me->start_busy(5,"你正在煽动百姓呢。\n");
        p_id=me->query_id()[0];
        t_id=tar->query_id()[0];

        marea=tar->query_room()->get_area();

        
        gift=CHAR_D->get_char(p_id,"gift");
        meili=gift["meili"];

        mnation=CHAR_D->get_char(p_id,"nation");
        safe=AREA_D->get_area(marea,"safe");

        score=me->query_job("fanpeople","score");

        p_select=me->query_job("fanpeople","select");

    switch(p_select)
    {
        case 1:
        case 2:
        case 3:
        case 8:
        case 9:
         if((random(30)>meili)||(random(100)<safe)) 
                         ans=-1;
                 else
                         ans=1;
                 break;
        case 7:
                {
                        int tax=AREA_D->get_area(marea,"taxlocal")+
                                AREA_D->get_area(marea,"taxnation");
                        if(random(20)+20<tax)
                                ans=1;
                        else
                                ans=-1;
                }
                break;

        case 6:
                if(random(100)<safe)
                        ans=-1;
                else
                        ans=1;
                break;
        case 4:
         if(me->query_all_con_money()<10000) 
                         ans=-1;
                 else
                 {
                         ans=1;
                        me->set_all_con_money(
                                me->query_all_con_money() -10000 );
                 }
                 break;
        case 5:
                {
                   mixed my_army;
                   my_army=CHAR_D->get_char(p_id,"myarmy");
                   if(!my_army)
                   {   ans=-1;
                   }
                   else
                   {   if((!my_army["food"])||(my_army["food"]<100))
                                   ans=-1;
                           else
                           {
                                   ans=1;
                                   my_army["food"]-=100;
                                   CHAR_D->set_char(p_id,"myarmy",my_army);
                           }
                   }
                }
                break;
        case 10:
                ans=-1;
                if(score>20)
                        ans=1;
                break;
        default:

                ans=1;
        }
        if(ans==1)
        {
                safe-=2;
                score+=2;
                tar->targetted_action(good_answer[p_select-1]+"\n",me);
        }
        else
        {
                safe++;
                score-=1;
                tar->targetted_action(bad_answer[p_select-1]+"\n",me);
        }
        AREA_D->set_area(marea,"safe",safe);
        me->set_job("fanpeople","score",score);
        if(p_select==10) // leave;
        {
                call_out("talk_over",1, obs);
                return;
        }
        call_out("select_way",1,obs);
}
void input_way(mixed obs,string str)
{   int p_select;
    object me=obs[0],usr,tar;
    string p_id;
    int *topics;
    remove_call_out("no_answer_way");


	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}
	if(!tar->check_leader()) {talk_over(obs); return;}


	p_select=to_int(str); // must have me since after the check_leader

    if((p_select<1)||(p_select>10)) return;
        topics=me->query_job("fanpeople","topics");

	if(member_array(p_select,topics)!=-1)
    {  tell(me,"这个话题已经谈过了，得换一个。\n");
       call_out("no_answer_way",30,obs);
       return;
    }
    p_id=me->query_primary_id();
    usr=find_user(p_id);
    if(objectp(usr)) usr->modal_pop();


    me->targetted_action(sug[p_select-1]+"\n",tar);
        me->set_job("fanpeople","select",p_select);
        topics+=({p_select});
        me->set_job("fanpeople","topics",topics);

    call_out("judge_select",1,obs );
}

void no_answer_way(mixed obs)
{ input_way(obs,"10");
}

void select_way(mixed obs)
{
   object me=obs[0],usr;
   string p_id;
   if(!objectp(me)) return;
   p_id=me->query_id()[0];
   usr=find_user(p_id);
   if(!objectp(usr)) return;
   tell_user(p_id,"你的工作就是让他们不满。\n"+
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+
" 1 称赞勤劳  2 称赞忠厚  3 称赞能干  4 赠送黄金  5 赠送粮食 \n"+
" 6 体察民心  7 抱怨税率  8 诋毁国君  9 诋毁太守 10 告辞     \n"+
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+
"请输入你的话题(1--10)：\n");
   call_out("no_answer_way",30,obs);
   usr->modal_push((: input_way,obs:),
        "请输入你的话题(1--10)：");

}
void talk_over(mixed obs)
{
    object me=obs[0],tar;
    string area,p_id;
    area=me->query_room()->get_area();
    area=AREA_D->get_area(area,"name");

    if(!objectp(me)) return;
    p_id=me->query_id()[0];
    tar=obs[1];
    if(objectp(tar)) {
 
		CHANNEL_D->deliver_tell("rumor","system",
        CHAR_D->get_char(p_id,"name")+
        "到"+area+"煽动百姓不满情绪，当地安定度下降了。");
		tar->do_my_dispear();
    }
    tell_user(p_id,"%^H_GREEN%^任务完成得不错，快去太守处领赏吧。\n%^RESET%^");
}
