///**************************************************************
// Updated by stefan on 10 Jan 1997 and fire on 23 Dec 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// ok
#include <verb.h>
inherit VERB_OB;
void bkiss(object liv1, object liv2)
{
        liv1->simple_action("$NЦ������ѽ��\n");
        liv1->simple_action("$N������ס���������������һ��������ǡ�\n",);
}
mixed can_ask_liv_about_wrd(object liv, string str) 
{
        return 1;
}
mixed do_ask_liv_about_wrd(object liv, string item)
{
        string p_act;
        string p_askstr;
		mixed ret;
		ret=this_body()->query_asklist(item,"target");
		if(ret==(liv->query_id()[0]))
		{
			string filename,funname;
			filename=this_body()->query_asklist(item,"filename");
			funname=this_body()->query_asklist(item,"funname");
			call_other(load_object(filename),funname,this_body(),liv);
			return;
		}
        
		p_act=item;
        p_askstr=liv->query_ask_str(item);
	if ( this_body() == liv ) {
		write("���ѵ��Լ�����֪����\n");
		return 1;
	}
        if(stringp(p_askstr))
             this_body()->targetted_action(p_askstr,liv);
        else
        switch(item)
        {
                case "name":
                    this_body()->targetted_action(
"$N��$t�ʵ��������������մ�����\n",liv);
                        break;
                case "here":
                        this_body()->targetted_action(
"$N��$t�ʵ������³����󱦵أ���֪������Щʲô�������飿\n",liv);
                        break;
                case "rumors":
                       this_body()->targetted_action(
"$N��$t�ʵ�����֪�����û����˵ʲô��Ϣ��\n",liv);
                        break;
/*
                case "bkiss" :
                       this_body()->targetted_action(
"$N��$T�ʵ���$mС�㣬����������\n",liv);
                        call_out((: bkiss , liv, this_object() :), 3);
                        return;
*/
                case "all" :
                       this_body()->targetted_action(
"$N�����$T����$s������³����$R���ߴͽ̡�\n",liv);
                       break;
                default :                                               
                        this_body()->targetted_action("$N��$t��������<"+p_act+">����Ϣ��\n",liv);
        }
        liv->be_asked(this_body(), item);
     return 1;
}
mixed do_ask_str_about_wrd(string str, string item)
{
	object o;
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	do_ask_liv_about_wrd(o,item);
}

array query_verb_info()
{
     return ({ ({"STR about WRD" }) });
}
