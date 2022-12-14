/*    /verbs/players/speak.c
 *    from the Dead Soulsr2 Object Library
 *    speak
 *    speak STR
 *    speak in WRD STR
 */

#pragma save_binary

//#include <lib.h>
//#include "/c/include/talk_type.h"
//#include "include/speak.h"
#include <verb.h>
//#include "/c/include/talk_type.h"
inherit VERB_OB;
#define TALK_LOCAL 1
//inherit LIB_DAEMON;
/*
static void create() {
    parse_init();
    parse_add_rule("speak", "");
    parse_add_rule("speak", "in WRD");
    parse_add_rule("speak", "in WRD STR");
    parse_add_rule("speak", "STR");
}
*/
#define CITY_D "/initcity.c"
array query_verb_info()
{
     return ({ ({"in STR","in STR about STR", "STR" }) });
}

mixed can_speak() { return "说什么? 用什么方言?\n"; }

mixed can_speak_in_str(string str) {
    if( str ) return "你想说些什么?\n";
    else return 0;
}

mixed can_speak_str(string str) {
    int lang;

	return 1;
    
    if( !str ) return 0;
    if( strlen(str) > 3 && str[0..2] == "in " ) return 0;
    lang = (int)this_body()->GetNativeLanguage() ;
    return (mixed)this_body()->CanSpeak(0, TALK_LOCAL, str, lang);
}

mixed can_speak_in_str_about_str(string lang, string str) {
	int l,z,j;
	return 1;
	tell_user("emperor",sprintf("lang=%s,str=%s\n",lang,str));
    if( !lang || !str ) return 0;
    if(sscanf(lang,"%s.%s",z,j)!=2) return "你用什么方言说？ 格式：speak in <州.郡> about <str>.\n";
	
	l = CITY_D->GetJun("id",z,j);
	if(stringp(l)) return "没有这种方言耶！\n";
	if(this_body()->GetLanguageLevel(l)<100) return "很抱歉，目前你还不会说这种方言！\n";
	
    if( !environment(this_body()) ) return "You are nowhere right now.\n";
//    if(sscanf(lang,"%d",l)==1)
    return (mixed)this_body()->CanSpeak(0, TALK_LOCAL, str, l);
}

mixed do_speak() { return 1; }

mixed do_speak_in_str(string str) { return 1; }
mixed do_speak_in_str_about_str(string lang, string str);
mixed do_speak_str(string str) {
    mixed zjx;
//    lang = (int)this_body()->GetLanguageLevel((int)this_body()->GetNative("JunId"));
    zjx = (int)this_body()->GetNative("zjx");
    return do_speak_in_str_about_str(zjx[0]+"."+zjx[1], str);
}

mixed do_speak_in_str_about_str(string lang, string str) {
	int z,j;
	mixed l;
	tell_user("emperor",sprintf("str1 = %s str2= %s.\n", lang, str));
	return 1;
//    if( str[<1] != '.' && str[<1] != '?' && str[<1] != '!' )
//    str = capitalize(str) + ".";
//    else str = capitalize(str);
	if(sscanf(lang,"%s.%s",z,j)==2){
		l = CITY_D->GetJun("id",z,j);
		if(stringp(l)) return "没有这种方言耶！\n";
		if(this_body()->GetLanguageLevel(l)<100) return "很抱歉，目前你还不会说这种方言！\n";
	}
	
//    if(sscanf(lang,"%d",l)==1)
	tell_user("emperor",sprintf("l = %d\n",l));
    return (mixed)this_body()->eventSpeak(0, TALK_LOCAL, str, "说道", l);
}

string GetHelp(string str) {
    return ("Syntax: <speak MESSAGE>\n"
	    "        <speak in LANGUAGE MESSAGE>\n\n"
	    "Sends the message you specify to all people in the same room "
	    "as you.  If you are an avatar, you have the ability to customize "
	    "the way these messages come out through the \"message\" "
	    "command.  If you fail to specify a language, your native "
	    "language will be used.\n\n"
	    "See also: message, say, shout, speak, tell");
}

