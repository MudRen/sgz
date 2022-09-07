// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// More Crypic #@$t from Belboz
//

#include <mudlib.h>
inherit CMD;



#define SYNTAX "�÷�: groups [-a | -d] [groupname] [name 1] [name 2] ... \n"

private string banner =
"==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==\n";

private nomask void print_groups(mapping groups);


private void main( string arg )
{
    mapping     groups;
    string      this_group;
    mixed       valid;
    mixed       not;
    string *    arglist;


    groups = this_body()->query_perm( "groups" );
    if(!groups)  
        groups = ([]);

    if( !arg || arg == "" )
    {
        out( banner );
        outf( "%s���е�С���Լ����ǵĳ�Ա��\n\n",mud_name() );
        print_groups(GROUP_D->get_group_data());
        out( banner );


        if( !mapp( groups ) || !sizeof( groups ) ) {
            out( "�����ڲ�δ�μ��κ�С�顣\n" );
            return;
        }

        outf( "%s����ĸ���С���ǣ�\n\n", 
          this_body()->query_name() );

        print_groups(groups);

        out(banner);
        return;
    }

    arglist = explode( arg, " " );

    if( sizeof(arglist) <2 || (arglist[0] != "-a" && arglist[0] != "-d") ) {
        out( SYNTAX );
        return;
    }

    this_group = arglist[1];

    if( arglist[0] == "-a" )
    {
        if( sizeof(arglist) <3 ) {
            out(SYNTAX);
        }

        arglist = filter_array(arglist[2..],
          function(string x, string this_group, string *grp_members)
          {
              if ( pointerp(grp_members) &&
                member_array(grp_members, x) != -1 )
              {
                  outf("%s�Ѿ���(%s)С�����ˡ�\n",
                    x, this_group);
                  return;
              }
              else
              {
                  outf("%s������(%s)С�顣\n",
                    x, this_group);
                  return 1;
              }
          },
          this_group);

        arglist = clean_array( arglist );

        this_body()->set_perm( "groups", groups +
          ([ this_group : arglist ? (mixed)arglist : (mixed)(([]) + groups[this_group]) ]) );
    return;
}

if( sizeof(arglist) == 2 )
{
    if(groups[arglist[1]])
    {
        map_delete(groups,arglist[1]);
        outf("С��(%s)��ɾ���ˡ�\n", arglist[1]);
        return;
    }
    outf("û����'%s'Ϊ���ֵ�С�飡\n", arglist[1]);
    return;
}
arglist = arglist[2..];
valid = filter_array(arglist,
  (: member_array($(groups[this_group]), $1) != -1 :));

not = clean_array( arglist - valid );
valid = clean_array( valid );

if( sizeof( not ) )
    out(sprintf("�޷�ɾ�� %s.\n", implode( not, ", ")));

if( sizeof( valid ) )
{
    out(sprintf("ɾ�� %s.\n", implode( valid, ", " )));
    groups[this_group] -= valid;
    if( !sizeof( groups[this_group] ) )
        map_delete(groups, this_group);
    this_body()->set_perm( "groups", groups );
}
return;
}


private nomask void print_groups(mapping groups)
{
    map_array(sort_array(keys(groups), 1),
      (: out(sprintf("%s: %s\n", $1,
              implode(sort_array($2[$1], 1), ", "))) :),
      groups);

    out("\n");
}

