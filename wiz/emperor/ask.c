///**************************************************************
// Updated by stefan on 10 Jan 1997 and fire on 23 Dec 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// ok
//emperor add sleep on 2000.2.28
#include <verb.h>
inherit VERB_OB;
void bkiss(object liv1, object liv2)
{
        liv1->simple_action("$N˵��������ѽ����\n");
        liv1->simple_action("$N������ס�һ����������һ��������ǡ�\n");
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
"$N��$t�ʵ���������������մ�������\n",liv);
                        break;
                case "here":
                        this_body()->targetted_action(
"$N��$t�ʵ��������³����󱦵أ���֪������Щʲô�������飿\n",liv);
                        break;
                case "rumors":
                       this_body()->targetted_action(
"$N��$t�ʵ�������֪�����û����˵ʲô��Ϣ��\n",liv);
                        break;
                case "bkiss" :
                       this_body()->targetted_action(
"$N��$T�ʵ�����$mС�㣬���������𣿡�\n",liv);
                        call_out((: bkiss , liv, this_object() :), 3);
                        return;
/* emperor add */
                case "sleep" :
                       this_body()->targetted_action(
"$N����ض�$T����$c�������з���Σ�\n",liv);
                       break;
/* emperor add over */
                case "all" :
                       this_body()->targetted_action(
"$N��$T����$s������³����$R���ߴͽ̡�\n",liv);
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
     return ({ ({"STR about WRD","STR to WRD", "STR for WRD" }) });
}

/*
** emperor add 2002.8.15
*/
#if 0
static void create() {
    verb::create();
    SetVerb("ask");
    SetRules("LIV STR", "STR", "LIV to STR", "LIV for STR");
    SetErrorMessage("Ask what?  Or ask whom to do what?");
    SetHelp("Syntax: <ask LIVING SOMETHING>\n"
	    "        <ask SOMETHING>\n"
	    "        <ask LIVING to DO SOMETHING>\n"
	    "        <ask LIVING for SOMTHING>\n\n"
            "Some npcs and perhaps some inanimate objects will respond "
            "when you query the target with a specific question.\n\n"
            "See also: reply, say, shout, speak, tell, whisper, yell");
}
#endif

mixed can_ask_liv_to_str(string str) { return 1; }
 
mixed can_ask_liv_for_str(string str) { return 1; }

#if 0
mixed can_ask_liv_str(string str) {
    string tmp;

    if( !str ) {
	str = "";
    }
    if( sscanf(str, "to %s", tmp) ) return 1;
    else if( sscanf(str, "for %s", tmp) ) return 1;
    else if( sscanf(str, "about %s", tmp) ) return 1;
    else return (mixed)this_body()->CanSpeak(/* ob */0, TALK_LOCAL, str);
}
 
mixed can_ask_str(string str) {
    return (mixed)this_body()->CanSpeak(0, TALK_LOCAL, str);;
}
#endif

mixed do_ask_liv_to_wrd(object ob, string str) {
/*
    message("my_action", "You ask "+(string)ob->GetName()+" to "+str+".",
            this_player() );
    message("other_action", (string)this_player()->GetName()+" asks "
            "you to "+str+".", ob);
    message("other_action", (string)this_player()->GetName()+" asks "+
            (string)ob->GetName()+" to "+str+".",
            environment(ob), ({ ob, this_player() }) );
*/
    if(!ob->eventAsk(this_body(), str)) this_body()->my_action("û�п��ʵġ�");
	this_body()->target_action("$N��$T�ʵ�����" + str + "��\n", ob);
    return 1;
}

mixed do_ask_str_to_wrd(string str, string wrd) {
	object o;
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	do_ask_liv_to_wrd(o,wrd);
}

mixed do_ask_str_for_wrd(string str, string wrd) {
/*
    message("my_action", "You ask "+(string)ob->GetName()+" for "+str+".",
            this_player() );
    message("other_action", (string)this_player()->GetName()+" asks "+
            (string)ob->GetName()+" for "+str+".",
            environment(ob), ({ ob, this_player() }) );
    if( !((int)ob->eventRequest(this_player(), str)) )
      message("other_action", (string)this_player()->GetName()+" asks "
	      "you for "+str+".", ob);
*/
    return 1;
}
/*
mixed do_ask_liv_str(object ob, string str) {
    mixed tmp;

    if( sscanf(str, "to %s", tmp) ) return do_ask_liv_to_str(ob, tmp);
    if( sscanf(str, "for %s", tmp) ) return do_ask_liv_for_str(ob, tmp);
    if( str[<1] != '?'||str[<2..<1] != "��" ) str = str + "?";
//    else str = capitalize(str);
    return (mixed)this_body()->eventSpeak(ob, TALK_LOCAL, str);
}
 
mixed do_ask_str(string str) {
    if( str[<1] != '?'||str[<2..<1] != "��" ) str = str + "?";
//    else str = capitalize(str);
    return (mixed)this_body()->eventSpeak(0, TALK_LOCAL, str);
    return 1;
}
*/
