// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit OBJ;

void setup()
{
  set_attached(1);
  set_unit("Ƭ");
  set_id("ocean","��", "water","surf","waves");
  set_long("��û��ʲô�ر�ĵط���");
}


int wade(string s)
{
  return environment(this_object())->wade(s);
}
