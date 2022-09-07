/* rmarea.c by fire on 16/06/98
this cmd is used to remove an area
in the sg system, this cmmond should
set some priviliage in case careless
wiz may delete data just by testing
usage: rmarea <area_id>
example: rmarea luoyang
*/
// last modified by xiaobai at Oct. 22, 2001
//      ��������е�Σ�գ�Ϊ�˷�ֹ�����������Щ�Ķ�
//          1��admin ����ִ��Ȩ��
//          2������ȷ�ϲ�ִ��
//

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

//! ����ʹ����ȷ����ֻ������ "y" ʱ�� ��ִ�в���
private int confirm( string par_strId, string par_strInput );
//! ��ȷ�Ϻ�ִ�в���
private void execute( string par_strCityId );
//����ֹ����
private void abort();

nomask private void main(string str)
{
	string p_id=str;
    string extra = 0;
    
    if ( !adminp(this_body()) )
    // ֻ�� admin ����Ȩ��
    {
        write( "��Ǹ��ֻ�� admin ����Ȩִ��������\n" );
        return;
    }
 
    if (!str)
    {
        write("�÷���rmarea <area_id>\n");
        return;
    }
    
    sscanf(p_id, "%s %s", p_id, extra);
    
    if ( extra )
    {
        write("������֮�䲻���пո�\n");
		return;
	}

    write( "\n�����������ɾ��ĳһ���������У�����ִ�к󣬸ó��е��������ݽ��ᶪʧ��\n\n" );
    
    this_body()->modal_push((: confirm, p_id :),"Ҫ�����Ļ��������� ��y�������������롰n����");
    call_out( "abort", 60 );

}

//! ����ʹ����ȷ����ֻ������ "y" ʱ�� ��ִ�в���
private int confirm( string par_strId, string par_strInput )
{
    if ( par_strInput == "y" )
    {
        this_body()->modal_pop();
        execute( par_strId );        
    }
    else
        abort();
    
}

//! ��ȷ�Ϻ�ִ�в���
private void execute( string par_strCityId )
{
    string extra = 0;
	
	write( "���ִ�С�\n" );
//	extra=AREA_D->remove_area( par_strCityId );
//	write( extra );
}

//����ֹ����
private void abort()
{
    remove_call_out("abort");
    write( "������ֹ��С�Ľ�����һ�����õ�ϰ�ߡ�\n" );
    this_body()->modal_pop();
}
