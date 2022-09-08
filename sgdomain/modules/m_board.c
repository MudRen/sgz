/* Do not remove the headers from this file! see /USAGE for more info. */
// modified by fire on Jan 15 1998
// BOARD.C    970408 Fritti
// modified by fire on Jan 16 1998
// Generic bulletin board.
//
// Public interface (aka how to use this thing):
//   object ob = new(BOARD, "Your board's name", "linked.newsgroup");
//   ob->move(where_ever_you_want);
// Modified for ���ǻ���   by suicide in 2000.08.06
inherit OBJ;
inherit M_READABLE;
inherit CLASS_NEWSMSG;
// The group to which this board is linked. Set by setup().
private string linked_group;
private mixed my_nation;  // for national board
// The name of this board. Set by setup().
private string board_name;
// Function prototypes.
void set_group(string new_group);
private nomask string list_headers();
string do_desc();
int get_group_last_id(string group);

// Filter removed messages from ids array.
private nomask int filter_removed(int elem) {
    class news_msg msg = NEWS_D->get_message(linked_group, elem);

    if (!msg || !msg->body)
        return 0;
    return 1;
}
int query_logical_id(int p_id)
{
    int array ids = sort_array(filter_array(
      NEWS_D->get_messages(linked_group), (: filter_removed :)), 1);
    int i;
    for (i = 1; i < sizeof(ids) + 1; i++)
        if(p_id==ids[i-1])
			return i;
	return 0;
}
// Create a new board.
nomask void create(string name, string group) {
    ::create();
    if (!clonep(this_object()))
        return;
    if (!group || group == "")
        error("No linked newsgroup in board.\n");
    set_group(group);
    board_name = name;
    set_id("board", "���԰�");
    add_id("news board");
    set_in_room_desc( (: do_desc :) );
    set_long( (: list_headers :) );
}
// Set and query functions.
private nomask void set_group(string new_group)
{
    if (new_group != "wiz.com" && member_array(new_group, NEWS_D->get_groups()) == -1)
        error("Invalid groupname <" + new_group + "> in set_group()\n");
    linked_group = new_group;
    if (new_group[0..6] == "nation.")
        my_nation = new_group[7.. < 1];
    else
        my_nation = 0;
}

nomask string query_group() {
    return linked_group;
}
// Format one message line
private nomask varargs string format_message_line(int id) {
    class news_msg msg;
    string subject;
    msg = NEWS_D->get_message(linked_group, id);
    if (!msg || !msg->body)
        return 0;                      // Do not display removed messages.
    else
        subject = msg->subject;
    return sprintf( "%-35s ��%-10s %s��",
      subject[0..34],
      msg->poster,
      intp(msg->time) ? ctime(msg->time)[4..9] : msg->time);
}
// Format all message lines.
private nomask string array query_message_lines() {
    int array ids = sort_array(filter_array(
      NEWS_D->get_messages(linked_group), (: filter_removed :)), -1);
    int i,j;
    string array tmp;
    tmp = map_array(ids, (: format_message_line($1) :));
    j=sizeof(tmp);
    for (i = 1; i < sizeof(tmp) + 1; i++)
        tmp[i-1] = sprintf("%4d��", j--) + tmp[i-1];
    return tmp;
}
// Make the long description.
private nomask string list_headers() {
    return "  ���   ����                               ������      ����\n" +
      repeat_string("��", 34) + "\n" + implode(query_message_lines(), "\n");
}
// Needed for M_READABLE
nomask int has_entries() {
    return 1;
}
string org_string(string str,string w_id) {
   string m_nation,w_area,m_area;
   string p_id;
   int sec_level;
   if(!my_nation) return str;
   p_id=this_body()->query_primary_id();
   m_nation=CHAR_D->get_char(p_id,"nation");
   m_area = CHAR_D->get_char(p_id,"area");
   w_area = CHAR_D->get_char(w_id,"area");
   if(m_nation!=my_nation)
      return "���������Ĺ��һ��� ���޷���ѯ��\n";
   if (str[0]=='@')
    {if (m_area!=w_area)       //����ͬ��
       return "����"+AREA_D->get_area(w_area,"name")+"�ĵ������ܣ����޷���ѯ��\n";
     if (str[1]=='@')
       {if(CHAR_D->get_char(p_id,"level")<2)
		return "������ʱ���Ǿ����ļ�������Ȩ��ѯ��\n";
        str="�����Ǿ��ܡ�\n"+str[2..<1];
       }
     else
        str="�����ǻ��ܡ�\n"+str[1..<1];
     return str;
    }

   if(str[0]!='*') return str; // not secret
   sec_level=1; str=str[1..<1];
   if(str[0]=='*') {
	sec_level++;
	str=str[1..<1];
	if(str[0]=='*') {
		sec_level++;
		str=str[1..<1];
	}
   }

   switch(sec_level) {
      case 1: // nomal secret
         return "�����ܡ�\n"+str;
      case 2: //
         if(CHAR_D->get_char(p_id,"level")<2)
		return "���ǻ����ļ�������Ȩ��ѯ��\n";
	return "�����ܡ�\n"+str;
      case 3:
         if((CHAR_D->get_char(p_id,"ranknation"))||
		( AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"leader")==p_id  ))
		return "�����ܡ�\n"+str;
	return "���Ǿ����ļ�������Ȩ��ѯ��\n";

   }
}


// Read about an entry.
nomask mixed read_entry(string str) {
    class news_msg msg;
    int id;
    int p_id=0;
    int array ids = sort_array(filter_array(NEWS_D->get_messages(linked_group),
      (: filter_removed :)), 1);
    if ((str == "next")||(str=="new"))
    {
        int i=0;
	id = this_body()->get_news_group_id(linked_group);
	for(i=0;i<sizeof(ids);++i)
	{
		if (ids[i]>=id)
		{
			p_id=ids[i];
			break;
		}
	}
	if(!p_id)
            return "û���µ������ˡ�\n";
    }
    else
    {
        if (sscanf(str, "%d", id) != 1)
            return "��Ҫ�Ķ��ڼ������ԣ�\n";
        if (id <= 0 || id > sizeof(ids))
            return "���԰���û���������ԡ�\n";
	p_id=ids[id-1];
    }
    msg = NEWS_D->get_message(linked_group, p_id);
    this_body()->set_news_group_id(linked_group, p_id+1);
    return query_logical_id(p_id)+"��"+
		format_message_line(p_id) + "\n"+
		repeat_string("��", 34)+"\n" + org_string(msg->body,msg->userid);
}
// Helpful text for those used to type 'read 1'.
nomask mixed direct_read_obj(object ob) {
    return "�÷���read about <number> �����ڼ������ԣ�\n
read about next ������һ�����ԡ�\n";
}
// Short description.
private nomask string do_desc() {
    string tmp;
    int array a_id=sort_array(NEWS_D->get_messages(linked_group),1);
    int array a_idleft=sort_array(filter_array(NEWS_D->get_messages(linked_group),
      (: filter_removed :)), 1);
    int array a_idneedread;
    int curr_id = this_body()->get_news_group_id(linked_group);
    int all_news,left_news;
    if(sizeof(a_id)==0) a_id=0;
    else
    all_news=(a_id[sizeof(a_id)-1]);
    if(curr_id<=0)
    {
        curr_id=1;

        this_body()->set_news_group_id(linked_group, curr_id);
    }
    if(curr_id>all_news+1)
    {
 	curr_id=all_news;
        this_body()->set_news_group_id(linked_group, curr_id+1);
    }
    a_idneedread=filter_array(a_idleft, (: $1 >= $(curr_id):));
    left_news=sizeof(a_idneedread);
    all_news=sizeof(a_idleft);
    if(left_news==0)
	tmp=sprintf("������%d�����ԡ�",all_news);
    else
        tmp=sprintf("������%d�����ԣ�����%d��δ����",all_news,left_news);
    return board_name + tmp+"(board)";
}
// For board commands like post etc.
nomask int is_bulletin_board() {
    return 1;
}
