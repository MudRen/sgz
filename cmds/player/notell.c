// notell.c
/* Do not remove the headers from this file! see /USAGE for more info. */
// �Ӽ������� tell ������ϵ����� id, ��������Է���ͼ tell ʱ��������Ϣ
// by xiaobai, Sep. 2001

#include <mudlib.h>
#include <commands.h>

inherit CMD;
inherit M_GRAMMAR;
inherit M_COMPLETE;
inherit M_ANSI;

#define MAX_NOTELL  10

//! check whether an id is a player
private int is_player( string par_strId );

//! show the help and the current settings
private void show_message();

void create()
{
    ::create();
    no_redirection();
}

private void main( string arg )
{
    string strSetting;
    string* strNotellIds;
    string strMessage = "";
    int nTest = 0;
    
    if( !arg || arg == "" )
    {
        show_message();                
        return;
    }
    
    strMessage = this_body()->query_notell();

    // want to change ids    
    if ( arg[0] == '+' || arg[0] == '-' )
    {
        strSetting = trim_spaces( arg[1..<1] );
        // the old settings
        strNotellIds = this_body()->query("notell_ids");
        
        if ( !strNotellIds )
            strNotellIds = ({});
                
        if ( arg[0] == '+' )
        {
            nTest = is_player( strSetting );
            
            if ( !nTest )
                return;            
            // add id to the notell string
            else 
            {
                if ( sizeof( strNotellIds ) >= MAX_NOTELL )
                {
                    outf( "���ֻ������%d����ҡ�\n", MAX_NOTELL );
                }
                else if ( member_array( strSetting, strNotellIds ) != -1 )
                {
                    outf( "���%s�Ѿ����������ˡ�\n", strSetting );
                }                
                else
                {
                    // add an id to the list
                    strNotellIds += ({strSetting});
                    out( "��ɡ�\n" );
                }               
            }
        }
        else if ( arg[0] == '-' )
        {
            if ( lower_case( strSetting ) == "$all" )
            // clear the id list
            {
                strNotellIds = ({});
            }
            else
            {
                nTest = is_player( strSetting );
                if ( !nTest )
                    return;
                else
                // remove an id from the id list
                {
                    strNotellIds -= ({strSetting});
                    out( "��ɡ�\n" );                    
                }
            }
        }
        
        // save the notell id list
        this_body()->set( "notell_ids", strNotellIds );

    }
    else
    {
        strMessage = arg;    
        this_body()->set_notell( strMessage );
        out( "��ɡ�\n" );
    }
    
    if ( !strMessage || strMessage == "" )
    // if the notell message is not set, set a default message
    {
        strMessage = "�Է��������㡣\n";
        this_body()->set_notell( strMessage );
    }
    
    show_message();
            
}

private void show_message()
{
    string strIds = "";
    string* strArr = ({});
    
    out("notell ���÷�: \n\t���㲻Ը������ĳ�˿����㣺notell +<user>\n");
    out("\t��������һ������������úܷ����ˣ�notell -<user>\n");
    out("\t�������¾��������˶���Щ�ɰ���notell -$all\n");
    out("\t�����뻻һ�־ܾ��˵Ľ�ڣ�notell <message>\n");
    out("\t���磺notell С������û�п�\n");

    // ��ʾ��ǰ������
    out( "\n" );
    out( "Ŀǰ�� notell ���ţ�\n" );
    outf( "\t%s\n", this_body()->query_notell() );
    out( "Ŀǰ�㲻�������� ��\n" );
    // �ں����� id Ϊһ���ַ���
    strArr = this_body()->query("notell_ids");
    if ( !strArr )
        strArr = ({});
    strIds = implode( strArr, "," );
    outf( "\t%s", strIds  );
    
}  // end show_message

// check whether an id is a player
private int is_player( string par_strId )
{
/* ����������� 
    object obj = find_body( par_strId );
        
    if ( !obj )
    {
        write( sprintf( "%s����������ң�������ɧ���㡣\n", par_strId ) );
        show_message();
        return 0;
    }    
*/
    return 1;

}  // end is_player

///////////////////// EOF ////////////////////////////////
