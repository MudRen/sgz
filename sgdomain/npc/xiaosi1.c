#include <ansi.h>
#include <mudlib.h>
#include <move.h>
inherit LIVING;
string * fooddrink = ({ 
"coke","chocolate","pepsi","qdbeer","birthcake","bjling"
});
//string * fooddrink = ({ 
//"grape","peach","smssj","youji","hmgua","flin","strawberry","youzi",
//"hstibang","yzfz","pumpkin","qzluyu","cphen","baoyu","yeqing","zongzi",
//"wxhuotui","longxia","ybshrimp","wxmeat","gulurou","chunjuan","guozili",
//"xhdoufu","dazhaxie","qzyy","tangyuan","shrimp","yzrice","cpeanut","mango",
//"jbeef","jiangya","shizi","mldoufu","tanghulu","xfish","xihufish","pigleg",
//"shaoe","zcrab","lbgao","bqhen","shaorou","yrpaomo","nbaiye","gqmixian",
//"ctianluo","xrjiao","baozi","bzshrimp","glmifen","mugua","niangao",
//"drunkshrimp","xianggua","ruzhu","mhtao","lizhi","larou","xing","yangtao",
//"lizi","apple","bolo","jchen","ymbing","pear","dsbao","hsliyu","yxpeanut",
//"sjkourou","banana","bjling","kaoji","lbzhou","kaoya","yuchi","orange",
//"nrjiaozi","doufu","mooncake","jmantou","huntun","hsxz","jlxr","zpaigu",
//"wxpeanut","xigua","nverhong","mgsoup","lzgeng","ynpuer","zhuyeqing",
//"maojian","rscha","ldsha","rsdunji","fenjiu","hhdaqu","sdzi","hzlj",
//"hsmj","jztang","coke","dhcha","huadiao","maotai","lsyw","gljiu","yzcha",
//"qingkejiu","hzcha","bzkaocha","guihuajiu","putaojiu","jnchun","molihc",
//"tgy","longjingcha","sssoup","ssjp","bjdw","mijiu","smtang","zscha",
//"txlc","blchun","yanwo","qdbeer","ytdoufu","wyyc","sxhj","pepsi",
//});

void setup()
{
        set_name("may sc","С������С����");
        set_in_room_desc("��"+YEL+"С������רְ"+NOR+"��С����(may sc)");
        set_long("С������רְС���࣬����С�������գ�����ר�����˸����ࡣ\n"+
        "�Ҳ����Ե��𣿽������������ˡ�(ask may sc about food)��\n");
        set_gender(1);
        set_age(14);
//        add_id("waiter");
        set_sg_rongmao(30);
        add_question("here","here");
        add_question("food","food");
        add_question("name","name");
        add_ask_str("food","$N��$T�������֣�$R����ʲô�ԺȵĿ��������ɣ�\n");
}

void ask_food(object usr)
{
        string p_obj;
      object ob;
        p_obj=fooddrink[random(sizeof(fooddrink))];
        ob=OBJ_D->clone_obj(p_obj);
        ob->move(usr);
        this_object()->targetted_action(
                "$N���˵�ͷ����$T˵�����ðɣ����Եȡ�\n$N��"+ob->short()+"���˳�����$T���Ļ�ϲ��һ��������\n",usr);
        usr->responda("pat may sc");
        usr->responda("birthday awhite");
        usr->responda("birthday1 awhite");
        return;
}
mixed special_answer(object ob, string str)
{
        object player;
        player = this_body();
        switch(str)
        {
        case "food":
                ask_food(player);
                return;
        case "name":
                this_object()->targetted_action("$N����Ц�ŵ���"+
"����С�������գ����������ǡ�\n",ob);
                return;
        case "here":
                this_object()->targetted_action("$N˵�����������������ѽ��"+"�������Ϻ��Ǹ�������û��ʲô��ϵ�����ˡ�\n",ob);
                return;
        default:
                return;
        }
}
