// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Define a function called dig(obj)  for when obj tries to dig you.
// This module requires that M_INPUT also be inherited.
void modal_push(function,mixed);
void modal_pop();
void modal_pass(string);

int is_choppable()
{
  return 1;
}

int direct_chop_in_obj()
{
  return 1;
}

int direct_chop_out_obj()
{
  return 1;
}

int direct_chop_up_obj()
{
  return 1;
}

int direct_chop_obj()
{
  return 1;
}

int direct_chop_obj_with_obj()
{
  return 1;
}

int can_chop_in_obj()
{
  return 1;
}

int can_chop_out_obj()
{
  return 1;
}

int can_chop_up_obj()
{
  return 1;
}

int direct_chop_in_obj_with_obj()
{
  return 1;
}

int direct_chop_out_obj_with_obj()
{
  return 1;
}

int direct_chop_up_obj_with_obj()
{
  return 1;
}

int indirect_chop_with_obj_in_obj()
{
  return 1;
}

private void answer_question(string input)
{
  object o;
  
  if(!stringp(input))
    {
      modal_pop();
      return;
    }
  if(o = present(input, environment(this_body())) || 
     o = present(input, this_body()))
    o->do_chopping(this_object());
  else
    modal_pass(input);
  modal_pop();
}

void complete_chop()
{
  object array obs;

  obs = filter(all_inventory(this_body())+all_inventory(environment(this_body())),
               (: $1->can_chop() :));
  
  switch(sizeof(obs))
    {
    case 0:
      //write("You have nothing with which to chop.\n");   
      write("��û�п����Ĺ��ߡ�\n");
      return;
    case 1:
          printf(//"[with %s]\n"
                 "[���� %s]",obs[0]->short());
          obs[0]->do_chopping(this_object());
          return;
    default:
          modal_push((:answer_question:),
                                  //"What do you want to chop with? "
                                  "��Ҫ��ʲô����ѽ��");
          return;
    }
}