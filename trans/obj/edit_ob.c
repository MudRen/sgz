// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** edit_ob.c
**
** Based on a text-entry facility by Rust.  
** Transformed and rewritten by Deathblade on 8/23/94 to use the
** new input system facilities.
**
** Usage:
**     new(EDIT_OB, EDIT_FILE, fname, func)
** or  new(EDIT_OB, EDIT_TEXT, text, func)
**
** "func" will be evaluated when the editing is complete.  One
** parameter will be passed, which will be zero if the editing
** was aborted for some reason.  Otherwise, it will be a single
** string specifying the file name, or an array of strings
** holding the lines of text.
*/

#include <mudlib.h>
#include <playerflags.h>
#include <edit.h>

inherit M_ACCESS;
inherit M_INPUT;

#define HEADER \
"��ʼ�༭���� . �����༭���� ~q �жϣ��� ~h ȡ�ð�����\n"+\
"���������󩤩����������������󩤩����������������󩤩�����\n"

private string* buf;
private int already_editing;
private string client_fname;
private function client_func;


private string tmp_fname()
{
    return "/tmp/edit_ob." + this_user()->query_userid();
}

private string * read_strings(string fname, int messages)
{
    int size;

    size = file_size(fname);
    if ( messages )
    {
        if ( size == -2 )
            //write("File is a directory. Ignoring.\n");
            write("��Ŀ¼�ļ������ء�\n");
        else if ( size == -1 )
            //write("File not found.\n");
            write("�޴��ļ���\n");
        else if ( size == 0 )
            //write("File is empty.\n");
            write("���ļ���\n");
        else
            write("Ok.\n");
    }
    if ( size <= 0 )
        return ({ });

    return explode(read_file(fname), "\n");
}

varargs private string build_string(int flag)
{
    switch (sizeof(buf)) {
    case 0:
        return (flag & 1) ? //"**No text!\n"
                            "** û���ı���\n" : "";
    default:
        if (flag & 2)
            return "[" + (sizeof(buf)-15) + //" lines not displayed, please trim (~e)]\n"
                                            " ��û����ʾ���������޸� (~e)]\n" + implode(buf[<15..], "\n") + "\n";
        /* WARNING - falls through */
    case 1..15:
        return implode(buf, "\n") + "\n";
    }
}

private void end_edit(int aborted)
{
    mixed arg;

    if ( client_fname )
    {
        rm(client_fname);

        if ( !aborted )
        {
            write_file(client_fname, build_string(1));
            arg = client_fname;
        }
    }
    else if ( !aborted )
        arg = buf;

    /*
    ** Clear up this information before dispatching the callback.  The
    ** callback may want to push new modal handlers or something.
    */
    if( !already_editing )                        
        this_body()->clear_flag(F_IN_EDIT);
    modal_pop();

    evaluate(client_func, arg);

    destruct();
}

private nomask void end_ed()
{
    string tmp_file;

    tmp_file = tmp_fname();
    buf = read_strings(tmp_file, 0);
    rm(tmp_file);

    //write("Continue editing file.\n");
    write("�����༭�ļ���\n");

}

private void handle_escape(string str)
{
    string tmp;
    string tmp_file;

    switch ( str[1] )
    {
    case 'q':
        //write("Edit aborted.\n");
        write("�༭��ֹ��\n");
        end_edit(1);
        return;

    case 'r':
        if(wizardp(this_user()))
            buf += read_strings(evaluate_path(str[3..]), 1);
        return;

    case 'w':
        if(wizardp(this_user()))
        {
            tmp = build_string();
            if(!write_file(evaluate_path(str[3..]),tmp))
                //write("Unable to write to file.\n");
                write("�޷�д���ļ���\n");
            else
                write("Ok.\n");
        }
        return;

    case 'h':
        //write(
        //  "Help for editor:\n. or **\t\texit editor\n~q\t\tabort edit.\n~h\t\tthis help.\n"+
        //  "~e\t\tenter line by line editor.\n~p\t\tdisplay edit buffer.\n");
        write("�༭������\n"
              "  . �� **                 �����༭���˳��༭����\n"
              "  ~q                      �жϱ༭���˳��༭����\n"
              "  ~h                      ��ʾ��������\n"
              "  ~e                      �������б༭����\n"
              "  ~p                      ��ʾ�༭����������\n");
        if(wizardp(this_user()))           
            //write("~w <file>\twrite buffer to specified file.\n~r <file>\tread file into buffer.\n");
            write("  ~w <�ļ���>             �ѻ�����д��ָ���ļ���\n"
                  "  ~r <�ļ���>             ���ļ����ݶ��뻺������\n");           
        write("\n\n");
        return;

    case 'p':
        write(build_string() + "\n");
        return;

    case 'e':
        tmp_file = tmp_fname();
        write_file(tmp_file, build_string());
        new(ED_SESSION)->begin_editing(tmp_file, 0, (: end_ed :));
        return;
    }
}

private nomask void parse_edit(mixed str)
{
    if(str == -1)
      destruct(this_object());
    if ( str[0] == '~' )
    {
        handle_escape(str);
        return;
    }

    if ( str == "." || str == "**" )
    {
        end_edit(0);
        return;
    }

    buf += ({ str });
}

private void begin_edit(string *text, function continuation)
{
    if ( this_body()->test_flag(F_IN_EDIT) ) {
        //write("Warning! You are already marked as editing.\n");
        already_editing = 1;
        write("���棡�����Ѵ��ڱ༭״̬�ˣ�\n");
    }
    else this_body()->set_flag(F_IN_EDIT);

    buf = text ? text : ({ });
    client_func = continuation;

    write(HEADER + build_string(2));
    modal_push((: parse_edit :), "");   /* empty prompt */
}


void create(int kind, mixed text, function continuation)
{
    set_privilege(1);
    switch ( kind )
    {
    case 0:     // blueprint
        return;

    case EDIT_TEXT:
        if ( stringp(text) )
            text = explode(text, "\n");
        break;

    case EDIT_FILE:
        client_fname = text;
        text = read_strings(text, 0);
        break;

    default:
        error("Bad argument 2 to new(EDIT_OB, ...)\n");
    }

    begin_edit(text, continuation);
}