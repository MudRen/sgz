
#include <menu.h>
#include <mudlib.h>
#include <verb.h>

#define _DEBUG_ID   "xiaobai"

#define MAIN_TITLE       "\n��������ѡ��"
#define HEADER "������������������������������������������������������������������������\n"

inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_OUT;
inherit M_GLOB;

private MENU p_mnMain;
private MENU_ITEM p_quit_item;
private MENU_ITEM p_seperator;

private void show_nation();
private void reserve_nation();
private void remove_nation();

private void confirm( string par_strPara );
private void action( string par_strPara );
private void action_reserve( string par_strNation );
private void action_remove( string par_strNation );

private string m_strReserveNation = "";

private void quit()
{
    quit_menu_application();    
             
}  // end quit

void start_menu()
{
    init_menu_application( p_mnMain );
}

void create()
{
    set_privilege(1);

    p_mnMain = new_menu( MAIN_TITLE );

    p_quit_item = new_menu_item( "�˳�", (: quit :), "q" );
    p_seperator = new_seperator("-------------------------------------------------------------------------");
    add_menu_item( p_mnMain, p_seperator);
    add_menu_item( p_mnMain, new_menu_item("��������(reServe nation)", (: reserve_nation :) ,"s"));
    add_menu_item( p_mnMain, new_menu_item("�������(Remove nation)", (: remove_nation :) ,"r"));
    add_menu_item( p_mnMain, p_quit_item);
   
    set_menu_prompt ( p_mnMain, "����ָ��[srq]: ");
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, "exiting create()" );
#endif  // _DEBUG_ID
    
}  // end create

private void show_nation()
{
    string array keys, dis;

    keys = sort_array(COUNTRY_D->list_countries(),1);

    keys -= ({ m_strReserveNation });
    
    dis = map_array(keys, (: COUNTRY_D->get_country(($1),"name")+"("+($1)
    +")" :));

    printf("����־�����б�\n");
    printf(HEADER + sprintf("%-#79s\n", implode(dis, "\n")));
    printf("%s��ѡ��Ĺ���������%d����\n",HEADER,sizeof(dis));

    return;

}  // end show_nation

private void reserve_nation()
{
    show_nation();
    
    if ( m_strReserveNation != "" )
        write( sprintf( "ĿǰҪ�����Ĺ����� %s(%s)\n", COUNTRY_D->get_country( m_strReserveNation, "name" ), 
            m_strReserveNation ) );
    
    get_input_then_call( (: action_reserve :), "Ҫ�����ĸ����ң�" );

}  // end reserve_nation

private void remove_nation()
{
    show_nation();
    
    if ( m_strReserveNation != "" )
    {
        write( sprintf( "ĿǰҪ�����Ĺ����� %s(%s)\n", COUNTRY_D->get_country( m_strReserveNation, "name" ), 
            m_strReserveNation ) );
    }
    else
        write( "Ŀǰû�б�������\n" );

    get_input_then_call( (: confirm :), "Ҫ�����ĸ����ң�" );
    
}  // end remove_nation

private void confirm( string par_strPara )
{
    if ( par_strPara == m_strReserveNation )
    {
        printf( "\n%s ���Ǳ������ң���ѡ���Ĺ��ҡ�\n\n", par_strPara );
        return;
    }
    else if ( COUNTRY_D->nation_exist( par_strPara ) )
    {
        printf( "\nҪ�� %s(%s) ������\n\n", COUNTRY_D->get_country( par_strPara, "name" ),
            par_strPara  );      
    }
    else
    {
        write( "\n��Ǹ��û���������\n\n" );
        return;
    }

    get_input_then_call( (: action, par_strPara :), "ȷ����( yES / nO ): " );
}

private void action( string par_strPara, string par_strFlag )
{
    if ( par_strFlag != "y" )
    {
        write( "ȡ������\n" );
        return;
    }
    
    action_remove( par_strPara );        
    
}  // end action

private void action_reserve( string par_strNation )
{
    if ( COUNTRY_D->nation_exist( par_strNation ) )
    {
        m_strReserveNation = par_strNation;
        write( "\n���óɹ���\n\n" );      
    }
    else
        write( "\n��Ǹ��û���������\n\n" );
        
}  // end action_reserve

private void action_remove( string par_strNation )
{
    COUNTRY_D->do_dieout( par_strNation );
}
