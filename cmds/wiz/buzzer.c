// buzzer.c by fire ����������
// modified by row
// this cmd is used create quick room
inherit CMD;
void main()
{
   object o;
   o=new("/sgdomain/menu/buzzer");
   o->main(this_user());
}
