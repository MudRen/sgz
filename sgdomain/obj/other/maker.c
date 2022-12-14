// maker.c the maker could be able to make weapon, cloth or armor
#define FIXVAL 2
#include <move.h>
inherit PMODULES+"m_charnpc";
inherit M_ANSI;
private string m_id;
void my_select(string str);
void input_name(string str);
void answer_somebody(object who);
void prepare_answer();
void my_select(string str);
void no_answer();
void fail_answer();
void succ_answer();

void setup()
{  call_out("my_heart",5);
   add_question("list","list");
   add_question("buy","buy");

}
void extra_init()
{
        string ask_list,ask_order,ask_fix,ask_buy,ask_good;
        m_id=this_object()->query_id()[0];
        CHAR_D->set_char(m_id,"is_maker",1);
        CHAR_D->set_char(m_id,"is_tmp",1);
        if(!CHAR_D->get_char(m_id,"just_sell")) {
                add_question("order","order");
                add_question("fix","fix");
                add_question("good","good");

                ask_order=CHAR_D->get_char(m_id,"ask_order");
                if(!ask_order) 
                        ask_order="$N对$T招了招手：$m，$S想定点儿东西。\n";
                add_ask_str("order",ask_order);

                ask_fix=CHAR_D->get_char(m_id,"ask_fix");
                if(!ask_fix) 
                        ask_fix="$N对$T招了招手：$m，$S有点儿东西，你能不能帮忙改一改？\n";
                add_ask_str("fix",ask_fix);

                ask_good=CHAR_D->get_char(m_id,"ask_good");
                if(!ask_good) 
                        ask_good="$N对$T招了招手：$m，$S的东西准备好了吗？\n";
                add_ask_str("good",ask_good);

        
        }

        ask_list=CHAR_D->get_char(m_id,"ask_list");
        if(!ask_list) 
                ask_list="$N对$T招了招手：$m，让$S看看你这儿都有些什么货。\n";
        add_ask_str("list",ask_list);

        ask_buy=CHAR_D->get_char(m_id,"ask_buy");
        if(!ask_buy) 
                ask_buy="$N对$T招了招手：$m，$S想买点东西。\n";
        add_ask_str("buy",ask_buy);

        add_id("maker");
}
string long(){  
        string p_long;
        p_long=CHAR_D->get_char(m_id,"long");
        if(!p_long) p_long="一个正忙得团团转的工匠。\n";
        return p_long;
}
void check_order() {
        mixed orders;
        string *ids,name;
        orders=CHAR_D->get_char(m_id,"orders");
        if(!sizeof(orders)) return;
        ids=keys(orders);
        foreach(string id in ids) {
                if(orders[id]["time"]<time())
                {
                        if(find_user(id))
                        {
                                name=OBJ_D->get_obj(orders[id]["item"],"name");
                                responda("hi "+id);
                                responda("tell "+id+" 你定的"+name+"已经准备好了，请速来验取。\n");
                        }
                }
        }
}
void do_my_speak(){  
        string act;
        mixed m_act;
        m_act=CHAR_D->get_char(m_id,"m_act");
        if(sizeof(m_act)){
                act=m_act[random(sizeof(m_act))];
        }
        else act="$N呵呵地笑了几声，道：欢迎光临。\n";
        if(act[<1]!=10) act+="\n";
        this_object()->simple_action(act);
        return;
}
void check_myroom()
{
        string m_room,m_shd_room;
        m_room=CHAR_D->get_char(m_id,"room");
        m_shd_room=CHAR_D->get_char(m_id,"shd_room");
        if((m_shd_room)&&(m_room!=m_shd_room))
                CHAR_D->put_char(m_id,m_shd_room); // in case it run
}
void my_charaction(){
        check_myroom();
        check_order();
    do_my_speak();
}

void answer_list(object who){
        array goods;
        string tmp,name;
        string bar="                                 ";
        int val,len;
        goods=CHAR_D->get_char(m_id,"goods");
        if(!goods) goods=({});
        CHAR_D->set_char(m_id,"goods",goods);
        if(!sizeof(goods)){
                this_object()->simple_action(
                        "$N笑道：不好意思，小铺还没开张呢。\n");
                return; 
        }
        this_object()->targetted_action(
                "$N道：不知$R需要些什么？\n",who);
        write(
"物品名称             购买价               定做价               等级\n");
        write(
"--------------------------------------------------------------------\n");

        foreach(string g in goods)      {
                int reusetype=1;
                string type;
                name=OBJ_D->get_obj(g,"name");
                if(!name) // no such things
                {
                        goods-=({g});
                        CHAR_D->set_char(m_id,"goods",goods);
                        continue;
                }
                name=name+"("+g+")";
                len=colour_strlen(name);
                val=OBJ_D->get_obj(g,"value");
        tmp=" ";
        if( len <20)
            tmp=bar[0..(20-len)];
                type=OBJ_D->get_obj(g,"type");
                if((type=="food") || ( type=="drink")) reusetype=0;
        printf("%s%s%-18s   %-18s   %s\n",name,tmp,
           CHINESE_D->chinese_value(val),
                   (reusetype ? CHINESE_D->chinese_value(to_int(val*(1+FIXVAL))):"------
--"),
//                 (reusetype ? CHINESE_D->chinese_value(to_int(val*(FIXVAL))):"---
-----")
                chinese_number(OBJ_D->get_obj(g,"level"))
);
        }

}
mixed check_order_posible(object maker,object me,string ans) {
        array goods;
    int p_buyersmoney;
    int p_itemvalue;
        int p_level,l_n,l_l,m_l;
        mixed orders;
        string p_id,name;
        goods=CHAR_D->get_char(m_id,"goods");
        if(member_array(ans,goods)==-1)
                return "$N对$T摇摇头，道：$R要的东西我这儿没法儿做。\n";
        if(OBJ_D->get_obj(ans,"type")=="food")
                return "$N对$T摇摇头，道：$R要的东西我不能定做。\n";
        if(OBJ_D->get_obj(ans,"type")=="drink")
                return "$N对$T摇摇头，道：$R要的东西我不能定做。\n";

    maker->clear_answer();
    p_buyersmoney=me->query_all_con_money();
        p_itemvalue=OBJ_D->get_obj(ans,"value")*(1+FIXVAL);
        if(p_itemvalue>p_buyersmoney) 
                {
           this_object()->simple_action("$N奇怪地看了$T一眼，道：$R的钱好像没带够。\n$N皱了皱眉头，低声说道：既然$R如此急切，我倒有个办法。。。\n$N继续道：我可以叫人到$R钱庄帐户里取钱，不过要加百分之十的手续费，$R意下如何？\n")
           usr->modal_push((: input_way:),"请输入你的选择(yes/no)：");
           return;
               }

        p_id=me->query_id()[0];
        if(!CHAR_D->char_exist(p_id))
                return "$N对$T摇摇头，道：$R非世俗之人，这些东西我看就不要了吧。\n"
                +"如非要不可，得先找个地方定居下来(help settle)。\n";
        l_n=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranknation"));
    l_l=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranklocal"));
    m_l=bmax(l_n,l_l);
    m_l=(m_l+1)/2;      p_level=OBJ_D->get_obj(ans,"level");
    name=OBJ_D->get_obj(ans,"name");
        if(m_l>p_level){
                if(p_level==0)
                        return "$N对$T摇摇头，道："+name+"乃平民百姓所用之物，不适合$R。\n";
                else
                        return "$N对$T摇摇头，道："+name+"乃下级官员所用之物，不适合$R。\n";
        }
        if(m_l<p_level) {
                if(p_level==5)
                        return "$N对$T摇摇头，道：开玩笑！"+name+"乃万岁御用之物，$R岂能。。。
？！\n";
                else
                        return "$N对$T摇摇头，道：不行，"+name+"乃高级官员所用之物，$R还是升官
后再来吧。\n";
        }
        me->set_all_con_money(p_buyersmoney - p_itemvalue);
        orders=CHAR_D->get_char(m_id,"orders");
        if(!orders) orders=([]);
        orders[p_id]=([]);
        orders[p_id]["item"]=ans;
        orders[p_id]["time"]=time()+(60+random(60))*(p_level+1);
        CHAR_D->set_char(m_id,"orders",orders);
        return "$N对$T点点头，道：活儿我已经接下，待"+name+"完成后即刻通知$R验取
。\n";
}
void to_order(object maker,object me,string ans){
        mixed ret;
        ret=check_order_posible(maker,me,ans);
        if(stringp(ret)){
                maker->targetted_action(ret,me);
                return;
        }

}
void to_fix(object maker,object me,string ans){
        write("改造还没完成，直接定做吧。\n");
}

void to_buy(object maker,object me,string ans)
{
        array goods;
    int p_buyersmoney;
    int p_itemvalue;
    object ob;
        goods=CHAR_D->get_char(m_id,"goods");
        if(member_array(ans,goods)==-1){
                maker->targetted_action("$N对$T摇摇头，道：$R要的东西我这儿没法做。\n",m
e);
                return;
        }
    maker->clear_answer();

    p_buyersmoney=me->query_all_con_money();
        p_itemvalue=OBJ_D->get_obj(ans,"value");

        if(p_itemvalue>p_buyersmoney) {
                maker->targetted_action("$N奇怪地看了$T一眼，道：$R的钱好像没带够。\n",m
e);
                return;
        }
        ob=OBJ_D->clone_obj(ans);
        if(!objectp(ob)) {
                maker->targetted_action("$N对$T不好意思的说：东西拿不到，好像有BUG，报告
巫师吧。\n",me);
                return;
        }

    if((ob->move(me)) == MOVE_OK) {             
                me->simple_action("$N在此买下了一"+
            ob->query_unit()+ob->short()+"。\n"); 
        me->set_all_con_money(p_buyersmoney - p_itemvalue);
        return;
     }
    else
    {
                maker->targetted_action("$N对$T摇摇头，道：$R身上东西太多，扔掉些再来买
吧。\n",me);
                destruct(ob);
                return;
    }
}
void answers(object who,string what) {
        array goods;
        string p_id,name;
        p_id=who->query_id()[0];
        goods=CHAR_D->get_char(m_id,"goods");
        if(!goods) goods=({});
        CHAR_D->set_char(m_id,"goods",goods);
        if(!sizeof(goods)){
                this_object()->simple_action(
                        "$N笑道：不好意思，小铺还没开张呢。\n");
                return; 
        }
        if((what=="order")||(what=="fix"))
        {
                goods=filter(goods,(:(OBJ_D->get_obj($1,"type")
                        !="food") && (OBJ_D->get_obj($1,"type")
                        !="drink") :));
        }
        switch(what)
        {
        case "buy":
                this_object()->set_answer(p_id, (: to_buy :) );
                this_object()->targetted_action(
                        "$N对$T笑道：$R想买些什么？\n",who);
                break;
        case "order":
                if(!sizeof(goods)) {
                        this_object()->simple_action(
                                "$N笑道：不好意思，小铺没东西可定。\n");
                        return; 
                }
                this_object()->set_answer(p_id, (: to_order :) );
                this_object()->targetted_action(
                        "$N对$T道：$R想定做些什么？\n",who);
                break;
        case "fix":
                if(!sizeof(goods)) {
                        this_object()->simple_action(
                                "$N笑道：不好意思，小铺没东西可改。\n");
                        return; 
                }
                this_object()->set_answer(p_id, (: to_fix :) );
                this_object()->targetted_action(
                        "$N对$T道：$R想改什么？\n",who);
                break;
        }

        foreach(string g in goods)      {
                name=OBJ_D->get_obj(g,"name");
                if(!name) // no such things
                {
                        goods-=({g});
                        CHAR_D->set_char(m_id,"goods",goods);
                        continue;
                }
                name=name+"("+g+")";
                write(name+"\n");
        }
        write("想好了就输入\n%^H_WHITE%^answer <物品代号> to "+m_id+"%^RESET%^\n"
);

}
void answer_good(object who){
        mixed orders;
        string name;
        string p_id;
        string item;
        object ob,maker,me;
        maker=this_object();
        me=who;
        orders=CHAR_D->get_char(m_id,"orders");
        p_id=me->query_id()[0];
        if(!orders) orders=([]);
        if(!orders[p_id]){
      maker->targetted_action(
                "$N对$T摇摇头，道：$R没在这儿定过东西吧？\n",me);
                        return;
        }
        item=orders[p_id]["item"];
        name=OBJ_D->get_obj(item,"name");
        if(orders[p_id]["time"]>time())
        {       maker->targetted_action(
                        "$N对$T道：$R的"+name+"还没准备好，请再稍等片刻。\n",me);
                        return;
        }
        maker->targetted_action(
                        "$N对$T道：$R的"+name+"已经准备好了，这给您取来。\n",me);

        ob=OBJ_D->clone_obj(item);
        if(!objectp(ob)) {
                maker->targetted_action("$N对$T不好意思的说：东西拿不到，好像有BUG，报告
巫师吧。\n",me);
                return;
        }
        if(ob->is_horse())
        {
                ob->move(environment(me)); // should no problem
                me->simple_action("$N领到专门为$n专门准备的"+ob->short()+"\n");
                map_delete(orders,p_id);
                CHAR_D->add_char_wear(p_id,item);
                ob->set_owner(p_id);
        }
        else
        {
                if((ob->move(me)) == MOVE_OK) { 
                        me->simple_action("$N在此提到了所定的"+
                                ob->query_unit()+ob->short()+"。\n"); 
                        CHAR_D->add_char_wear(p_id,item);
        //              CHAR_D->put_on_cloth(p_id);
                        map_delete(orders,p_id);
                        ob->set_owner(p_id);
                        return;
                 }
                else
                {
                        maker->targetted_action("$N对$T摇摇头，道：$R身上东西太多，扔掉些再来取
货吧。\n",me);
                                destruct(ob);
                        return;
                }
        }

}

void special_answer(object who, string matt)
{
  switch(matt)
  {
      case "list" :
         answer_list(who);
                return;
      case "buy" :
         answers(who,"buy");
                return;
      case "order" :
         answers(who,"order");
                return;
      case "fix" :
         answers(who,"fix");
                return;
      case "good" :
         answer_good(who);
       return;
  }
}

void input_way(string arg)
{
array goods;
int n_bank;
int p_itemvalue;
string p_id,name;
mixed orders;

goods=CHAR_D->get_char(m_id,"goods");
p_itemvalue=OBJ_D->get_obj(ans,"value")*(1+FIXVAL);
n_bank=this_body()->query_amt_money("bank");
p_id=me->query_id()[0];
name=OBJ_D->get_obj(ans,"name");

if (arg=="yes")
  {       

if ((p_itemvalue*1.1)<n_bank)
        {       
        n_bank=(n_bank-(p_itemvalue*1.1)); 
        orders=CHAR_D->get_char(m_id,"orders");
        if(!orders) orders=([]);
        orders[p_id]=([]);
        orders[p_id]["item"]=ans;
        orders[p_id]["time"]=time()+(60+random(60))*(p_level+1);
        CHAR_D->set_char(m_id,"orders",orders);
        this_object()->simple_action("$N从$T的帐上划走了"+chinese_number(p_itemvalue*1.1)"。\n$N对$T点点头，道：活儿我已经接下，待"+name+"完成后即刻通知$R验取\n");        
        return;
        }

else{
if ((p_itenvalue*1.1)>n_bank)
        {
this_object()->simple_action("$N「嗯」了一声说道：$T$R帐上的钱好像也不够呀。。。");
return;
        }
    }
  }

else{ 
        if (arg=="no")
  {
        this_object()->simple_action("$N无奈地耸了耸肩：既然$T$R不急，那还是改天再来吧。");
        return;
  }
  else return;
    }
}

int is_maker() {
        return 1;
}
