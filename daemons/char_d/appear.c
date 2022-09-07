// for npc appear
//:FUNCTION appear
//This is a very useful function for put chars
//useage: CHAR_D->appear(string char_id,string area_id,string where,string action)
//the char_id is the must parameters, if no area_id or area_id==""
//the system will select randomly an area
//where means where to put this char if "fly" in the fly room
//if "meeting" in the meeting room otherwise random room in the area
//the action used to show what the char do when he appear in that
//room, if let it blank then system will use default action
//to announce his appearance
//example: CHAR_D->appear("zhang fei") means put zhang fei in whatever
// place
// CHAR_D->appear("zhang fei","huayin","meeting") means zhang fei
//will appear in the meeting room in huayin
//
int put_char(string c_id,string r_id);
mixed appear(string p_id,string p_area,string p_room,string p_action) // this is
{
   mixed tmp;
   object o;
   string p_path;
   if(!CHAR_D->char_exist(p_id)) return;
   if((p_area=="")||(!p_area))
   {
       tmp=AREA_D->list_areas();
       p_area=tmp[random(sizeof(tmp))];
   }
   p_path=AREA_D->get_area(p_area,"path");
   if(!p_room)
     p_room=""; 
  switch(p_room)
  {
     case "fly":
       p_room=AREA_D->get_area(p_area,"fly");
       break;
     case "meeting":
       p_room=AREA_D->get_area(p_area,"meeting");
       break;
    
     case "":
//       tmp=get_dir(p_path+"*.c");
//       tmp-=({"warroom.c"});
	tmp=AREA(p_area)->get_room("list");
       if(!sizeof(tmp)) return;
       p_room=tmp[random(sizeof(tmp))];
//       p_room=p_room[0..<3];
       break;
      default :
       break;
   }
   p_room=p_path+p_room;

   put_char(p_id,p_room);
   o=CHAR_D->find_char(p_id);

   if(objectp(o))
   {
       if(sizeof(p_action))
       { o->simple_action(p_action);
       }
      else
       o->simple_action("$N���˹�����\n");
   } else {
     SGSYS("ERROR: can't find char of " + p_id +" after appear");
   }
  return o;
}
//:FUNCTION put_prison
// put a char to prison, 
// para p_id the id of the prisoner, it must be given
// p_time how long in jail, default is 5
// p_area in which jail, default is the area of current room of the char
// p_msg the message to put in jail has default value
// so the easiest way to send a char to prison is 
// CHAR_D->put_prison(p_id);
void put_prison(string p_id,int p_time,string p_area, string p_msg) 
{
    object o;
    string p_prison;
    o=CHAR_D->find_char(p_id);
    if(!objectp(o)) return;     
    if(!p_time) p_time=5;
    CHAR_D->set_char(p_id,"in_prison",p_time);
    CHAR_D->set_char(p_id,"be_caught",time());
    if((!p_area)||(p_area=="")) {
         p_area=o->query_room()->get_area();
    }
    CHAR_D->set_char(p_id,"caught_area",p_area);
    p_prison=AREA_D->get_area(p_area,"prison");
    if((!p_msg)||(p_msg==""))
      p_msg="$N����һ������ز��ˡ�����\n";
    appear(p_id,p_area,p_prison,p_msg);
}
