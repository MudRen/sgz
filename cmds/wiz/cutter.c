// cutter.c by fire ��������
// this cmd is used create quick char
inherit CMD;
void main()
{
   object o;
   o=new("/sgdomain/menu/cutter");
   write("now cutter is disabled\n");
//   return;
   o->main(this_user());
}
