inherit ROOM;
void setup(){
    string st1,st2,st3;
    set_light(50);
    set_brief("--�Է�--");
st1=
"
 {}                                            __________.
 ||                                           /_/-----/_/|   __ 
 ||--,,..                                     ( ( ' ' ( (| /'--'\\
 ||      `  _ _ _ _ _ _ _ _ _                 (_( ' ' (_(|/.    .\\\n";
st2=
" ||      ,` -  -    -    -  ` `.              / /=====/ /|  '||'
 ||      :                      `.           /_//____/_/ |   || 
 ||_ _ _ >_ _ _ _ _ _ _ _ _ _ _ ,;          (o|:.....|o) |   || 
_||__________________________||___________  |_|:_____|_|/'  _||_   ________\n";
st3=
" \"\"                          \"\"                            /____\\
\n\n";
    set_long(st1+st2+st3);
    set_exits( ([
        "out" :  "/wiz/fire/workroom.c"
            ]) );
    set_objects( ([POBJ+"other/bed" : 1 ]) );
}                
void init() {
	tell_from_inside(this_object(),"hohohoho\n");
}