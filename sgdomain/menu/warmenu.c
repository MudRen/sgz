// War menu for commands in the battlefield
// By flee on 27 Oct, 1998
#include <mudlib.h>
#define MAP_CMD "/sgdomain/cmd/warmap.c"
#define ATT_CMD "/sgdomain/cmd/attack.c"

inherit M_INPUT;

void get_input_from_main(string arg);
string get_main_prompt();
void do_move(string str);
void show_help();
void show_troop();
void show_map();

void start_menu()
{
	modal_push( (: get_input_from_main :), (: get_main_prompt :) );
	show_help();
	return;
}
string get_main_prompt()
{
	return "[ewsn;m;t;h;q] >";
}
void quit_warmenu()
{
	modal_pop();
	destruct( this_object() );
	return;
}
void get_input_from_main(string arg)
{
	if( !arg || arg == "" || arg == "t") show_troop();
	else if( arg == "e" ) do_move("east");
	else if( arg == "w" ) do_move("west");
	else if( arg == "n" ) do_move("north");
	else if( arg == "s" ) do_move("south");	
	else if( arg == "h" ) show_help();
	else if( arg == "q" ) quit_warmenu();
	else if( arg == "m" ) show_map();
	else write("�Ƿ����\n");

	return;
}	
void show_troop()
{
	int i;
	object troop;
	mixed solider;
	string *types;
	string result;

	troop = environment( this_body() );
	result = "";

	if( !troop->is_troop() ){
		write("�����ڲ�û��ָ���κβ��Ӱ��� \n");
		return;
	} else {
		solider = TROOP_D->get_troops( troop->get_id(), "solider" );
		types = keys( solider );
		result = result + " ���֡�  ������ ѵ��  ʿ����������\n";
		for( i = 0; i < sizeof(solider); i++){
			result = result +
				sprintf(" %s  %6d %s %4d %s %4d %s %4d %s\n",
                        WARAI_D->get_solider(types[i],"name"),
                        solider[types[i]]["number"],
                        M_OUT->get_disp_color(solider[types[i]]["train"]),
                        solider[types[i]]["train"],
                        M_OUT->get_disp_color(solider[types[i]]["moral"]),
                        solider[types[i]]["moral"],
			M_OUT->get_disp_color(solider[types[i]]["energy"]*5),
                        solider[types[i]]["energy"],"%^RESET%^");
                }		
	};
	write( result );
	return;
}
void show_map()
{
	MAP_CMD->start("here");	
}
void do_move(string str)
{
	mixed result;
	object troop, env;

	troop = environment( this_body() );
	if( !troop->is_troop() ){
                write("�����ڲ�û��ָ���κβ��Ӱ��� \n");
                return;
        };
	env = environment( troop );

	if( !env->query_exit_value(str) ){
		write("�ƺ���̫���ܳ��Ǹ������ߡ�\n");
		return;
	};
	result = WARAI_D->check_move( troop, env->query_exit_value(str) );
	if( result == "�еб�������ͨ�С�\n" ) ATT_CMD->start( str );
	else this_body()->do_game_command( "go " + str );

	return;
}
void show_help()
{
	printf("\n����ָ��\n\n");
	printf("ewsn	move	���Ӧ�ķ����ƶ���\n");
	printf("		���Ŀ�ĵ��еб����򹥻��б���\n");
	printf("m       map	��ʾ���ڵص�ս����ͼ��\n");
	printf("t	troop	��ʾ������ӵ���ϸ���ϣ�\n");
	printf("		ֱ�ӻس���ͬ�� t \n");
	printf("h	help 	��ʾ��������\n");
	printf("q	quit	�뿪���˵���\n\n");		
	return;
}	
