inherit ROOM;
void setup(){
    string st1,st2,st3;
    set_area("fire_home");
    set_light(50);
    set_brief("--客厅--");
st1=
"  _______     
 /  12   \\
|    |    |                          ____
|9   |   3|                         /    \\
|     \\   |                        /______\\
 \\___6___/                            ||
                                      ||
                          /------\\    ||    /~~~~~~~~~~~~~~~\\
                        /~ ( )( ) ~\\  ||  /~ ( )( )( )( )( ) ~\\\n";
st2=
"                        (_)======(_)  ||  (_)===============(_)
               _______   |________|  _||_  |_________________|
              (_)^_^(_)
               / (_) \\
||             \\_____/             ||
||       ====================      ||\n";
st3=
"||          ||          ||         ||
||=====     ||          ||     ====||
||   ||     ||          ||     ||  ||
||   ||     ||          ||     ||  ||
\n\n";
	set_long(st1+st2+st3);
    set_exits( ([
        "out" :  __DIR__+"room/mainent.c",
        "bedroom" :  __DIR__+"room/bedroom.c",
        "kitchen" :  __DIR__+"room/kitchen.c",
        "studyroom" :  __DIR__+"room/study.c"
            ]) );
}                
/*东西太多了，看起来很乱，你看什么不要得，就丢了吧。*/
string query_board()
{
}
mixed can_go_bedroom() {
	string p_id;
	p_id=this_body()->query_id()[0];
	if((p_id!="fire")&&(p_id!="lili")&&(p_id!="benben"))
		return "主人睡房，不能乱进。\n";
	return 1;
}
