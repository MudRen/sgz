inherit ROOM;
void setup(){
    string st1,st2,st3;
    set_area("fire_home");
    set_light(50);
    set_brief("--����--");
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
/*����̫���ˣ����������ң��㿴ʲô��Ҫ�ã��Ͷ��˰ɡ�*/
string query_board()
{
}
mixed can_go_bedroom() {
	string p_id;
	p_id=this_body()->query_id()[0];
	if((p_id!="fire")&&(p_id!="lili")&&(p_id!="benben"))
		return "����˯���������ҽ���\n";
	return 1;
}
