//by ljty.

private int num_uses;

string short();

void set_num_uses(int num) {
    num_uses = num;
}

void num_decrease()
{
  if(num_uses > 1)  num_uses --;
  else 
    {
      write(short()+"ֻʣ���һЩ�ˡ�\n");
      destruct();
    }
}
