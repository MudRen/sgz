// def_input.c by fire 
// tired tired tired
// modified by edc at 08/04/2001

string def_get_position(string p_area,string p_dir);
array make_unique(array inp);
mixed get_def_val(int task_id);
mixed valid_start_point(string p_area,string p_side,int x,int y);
void put_def_troop(int task_id);

int can_have_new_def_troop(int task_id)
{
   	int ret=0;
	mixed tmp;

   	tmp=TASK_D->get_task(task_id,"def_general_left");
   	if( !sizeof(tmp) ) return 0;

	tmp = TASK_D->get_task(task_id,"def_troop_left");

	foreach( string tt in keys(tmp) )ret = ret + tmp[tt];
   	if( ret ) return 1;
   	else return 0;   
}
string get_valid_def(int task_id)
{
   	int p_troop,n_tmp;
   	string p_stage, p_area;
   	mixed tmp;
   	int i; // added by edc
   	string ret; // added by edc

   	p_troop=TASK_D->get_task(task_id,"def_arrange_troop");
   	p_stage=TASK_D->get_task(task_id,"def_arrange_step");
   	p_area=TASK_D->get_task(task_id,"def_area");

   	switch(p_stage){
   		case "general":
        		tmp = TASK_D->get_task(task_id,"def_general_left");
        		if(!sizeof(tmp)) return ""; // impossible now it is possible
        		return implode(tmp,",");
	      	case "position":
        		return "�Ƕ���e ������w �Ǳ���n ���ϣ�s ���У�c";
      		case "newtroop":
        		return "Yes|No";
// edc  08/04/2001
        	case "troopIdx":
        		//return implode( keys(TASK_D->get_task(task_id, "def_troop_left") ), ",");
        		ret="";
			i = 0;
			foreach( string ss in keys(TASK_D->get_task(task_id,"def_troop_left")) )
			{
				ret += ss;
				ret += ": ";
				ret += (string)i;
				ret += "  ";
				i++;
			}
			return ret;
////        		
		default:
			tmp=TASK_D->get_task(task_id,"def_curent_arrange_troop");
			n_tmp=tmp["max_av_soldier"];
			tmp=TASK_D->get_task(task_id,"def_troop_left")[p_stage];
                        	return "0--"+bmin(tmp,n_tmp);
   	}
}
string get_def_val_str(int task_id)
{
   	string p_stage;
   	mixed ret;

   	ret = get_def_val(task_id);
  	p_stage = TASK_D->get_task(task_id,"def_arrange_step");

   	switch(p_stage){
       		case "position":
          		return "c";
       		case "newtroop": 
			return (( ret >0 ) ? "Yes" :"No");
// edc  08/01/2001
		case "troopIdx":
			// return 0;   cancel this 0, 08/03/2001
			return ret;
////						
	  	default: return ret;
   	}
}
string def_prompt(int task_id)
{
   	string def_val, p_stage, p_valid;
   	string ret="";

   	def_val = get_def_val_str(task_id);
   	p_valid = get_valid_def(task_id);
   	p_stage = TASK_D->get_task(task_id,"def_arrange_step");

   	switch(p_stage){
       		case "general":
          		ret="����¾��š�������þ��Ž�����\n";
          		ret+="��Чֵ�У���"+p_valid+"��\n";
          		ret+="ȱʡֵ�ǣ���"+def_val+"��\n";
          		return ret;
       		case "position":
          		ret+="�����벿��פ��λ�á�\n";
          		ret+="��Чֵ�У���"+p_valid+"��\n";
          		ret+="ȱʡֵ�ǣ���"+def_val+"��\n";
          		return ret;
       		case "newtroop":
          		ret+="�Ƿ�����±��ţ�\n";
          		ret+="��Чֵ�У���"+p_valid+"��\n";
          		ret+="ȱʡֵ�ǣ���"+def_val+"��\n";
          		return ret;
// edc   08/01/2001
       		case "troopIdx":
          		ret+="��ѡ����֡�\n";
          		ret+="��Чֵ�У���"+p_valid+"��\n";
          		ret+="ȱʡֵ�ǣ���"+def_val+"��\n";
          		return ret;
////
		
		default:
			ret+="������"+WARAI_D->get_soldier_name(p_stage)+"������\n";
                        ret+="��Ч��Χ����"+p_valid+"��\n";
                        ret+="ȱʡֵ�ǣ���"+def_val+"��\n";
                        return ret;
    	}
}
mixed check_def_answer(int task_id,string str)
{
   	string p_stage, p_area;
   	mixed  tmp, tmp2;

   	p_area  = TASK_D->get_task(task_id,"def_area");
   	p_stage = TASK_D->get_task(task_id,"def_arrange_step");
   	if( (!str)||(str=="") ) str = get_def_val_str(task_id);

  	switch(p_stage){
		case "general":
          		tmp = TASK_D->get_task(task_id,"def_general_left");

			if(!sizeof(tmp)) return 1; // no general left
          		tmp2 = explode(str,",");
          		if( !sizeof(tmp2) ) return "��ô�ᵽ�����\n";
			if(sizeof(tmp2)>3) return "��������λ������\n";
          		foreach (string t in tmp2){
             			if( member_array(t,tmp) ==-1 ) return "û��"+t+"��λ������\n";
          		}
          		return 1;
       		case "position":
         		 return 1;
       		case "newtroop": 
          		str = lower_case(str);
          		if( (str=="yes")||(str=="y")||(str=="n")||(str=="no") )return 1;
          		else return "������Yes��No��\n";
// edc  08/01/2001
		case "troopIdx":
			return 1;
////
		default:
			tmp = TASK_D->get_task(task_id,"def_troop_left")[p_stage];
                        tmp2 = to_int(str);
                	if( tmp2 > tmp ) return "��û����ô�����\n";
                	if( tmp2 < 0 ) return "����\n";
			tmp=TASK_D->get_task(task_id,"def_curent_arrange_troop");
			if(tmp2>tmp["max_av_soldier"])
				return "��������ô�����\n";
                	return 1;
   	}
}
int input_arrange_def(int task_id,string str)
{
  	int def_arrange_troop;
  	string p_stage, p_area;
  	string *troop_types; //added by suicide
  	mixed def_val, tmp;
  	mixed def_curent_arrange_troop;
	int troop_idx, i, tmpNumber=0; // added by edc
	
  	p_area = TASK_D->get_task(task_id,"def_area");
  	def_curent_arrange_troop = TASK_D->get_task(task_id, "def_curent_arrange_troop");
  	def_arrange_troop = TASK_D->get_task(task_id,"def_arrange_troop");
  	p_stage = TASK_D->get_task(task_id,"def_arrange_step");

  	switch(p_stage){
		case "general":
                        if(TASK_D->get_task(task_id, "leader_out") == 1)
				def_curent_arrange_troop["general"]=explode(str,",");
                        else {
                                TASK_D->set_task(task_id, "leader_out", 1);
        	  		tmp = TASK_D->get_task(task_id,"def_general_left");
				if(sizeof(tmp)) // has general
                                def_curent_arrange_troop["general"]=
                			({TASK_D->get_task(task_id,"def_leader")})+explode(str,",");
				else
                                def_curent_arrange_troop["general"]=
                			({TASK_D->get_task(task_id,"def_leader")});

                        };
			// this is used to set the maximum number of soidliers in this troop
                        def_curent_arrange_troop["general"]=make_unique(def_curent_arrange_troop["general"]);
			def_curent_arrange_troop["max_av_soldier"]=
				WARAI_D->get_max_soldier(def_curent_arrange_troop["general"]);
			// soldier type index begin from 0;
			def_curent_arrange_troop["sd_idx"]=0;

                	TASK_D->set_task(task_id,"def_curent_arrange_troop",
            			def_curent_arrange_troop);


// edc  08/01/2001
			TASK_D->set_task(task_id,"def_arrange_step","troopIdx");


/*  edc
			tmp = TASK_D->get_task(task_id, "att_troop_left");


			//added by suicide 2000.11.08 for sort troop types
			//to ensure commando is the first arranged than footman
			troop_types = sort_array(keys(tmp),1);
			TASK_D->set_task(task_id,"def_arrange_step",troop_types[0]);
			//added end
			//TASK_D->set_task(task_id,"def_arrange_step",keys(tmp)[0]);
*/
////			
         		return 1;
       		case "position":
          		def_val = def_get_position(p_area,str);
          		def_curent_arrange_troop[p_stage] = def_val;
          		TASK_D->set_task(task_id,"def_curent_arrange_troop",
            			def_curent_arrange_troop);
          		TASK_D->set_task(task_id,"def_arrange_step","newtroop");

          		put_def_troop(task_id);
          		return can_have_new_def_troop(task_id);
       		case "newtroop":
         		str = lower_case(str);
         		if((str=="n")||(str=="no")) return 0;
   			tmp=TASK_D->get_task(task_id,"def_general_left");
   			if(!sizeof(tmp)) return 0;
         		def_arrange_troop++;
         		TASK_D->set_task(task_id,"def_arrange_troop", def_arrange_troop);
         		def_curent_arrange_troop = ([]);
         		TASK_D->set_task(task_id,"def_curent_arrange_troop",
            			def_curent_arrange_troop);
         		TASK_D->set_task(task_id,"def_arrange_step","general");
         		return 1;
// edc  08/01/2001
		case "troopIdx":
			troop_idx = to_int(str);

			// need some range protection for str
			tmp = TASK_D->get_task(task_id, "def_troop_left");
			if ( troop_idx >= sizeof(tmp) )
				troop_idx = 0;
/*
			// npc auto arrange... check out which troop should be arranged
			// say, always picks the biggest troop type
			// need check whether it is auto npc def or ppl def here!
			for( i=0; i<sizeof(tmp); i++)
			{
				if (tempNumber < values(tmp)[i])
					continue;
				tempNumber = values(tmp)[i];
				troop_idx = i;
			}
*/

			
			def_curent_arrange_troop["sd_idx"]=troop_idx;

	
                	TASK_D->set_task(task_id,"def_curent_arrange_troop",
            			def_curent_arrange_troop);
			tmp = TASK_D->get_task(task_id, "def_troop_left");
        		TASK_D->set_task(task_id,"def_arrange_step", keys(tmp)[troop_idx]);
			
			return 1;
////
		default:
			tmp = def_curent_arrange_troop["troop"];
/* edc
			def_curent_arrange_troop["sd_idx"]++;
*/  ////

                        if( !mapp(tmp) )tmp = ([ ]);
			if(to_int(str)>0) {
	                        tmp[p_stage] = to_int(str);
				def_curent_arrange_troop["max_av_soldier"]-=tmp[p_stage];
			}
                        def_curent_arrange_troop["troop"] = tmp;
                        TASK_D->set_task(task_id,"def_curent_arrange_troop",
                                def_curent_arrange_troop);
/* edc
                        tmp = TASK_D->get_task(task_id, "def_troop_left");

			if(def_curent_arrange_troop["sd_idx"]>=sizeof(tmp)) {
				TASK_D->set_task(task_id,"def_arrange_step","position");
				return 1;
			}
			if(def_curent_arrange_troop["max_av_soldier"]<=0) {
				TASK_D->set_task(task_id,"def_arrange_step","position");
				return 1;
			}

			if(sizeof(def_curent_arrange_troop["troop"])>=4) {
				TASK_D->set_task(task_id,"def_arrange_step","position");
				return 1;
			}

			troop_types = sort_array(keys(tmp),1);
			TASK_D->set_task(task_id,"def_arrange_step",troop_types[def_curent_arrange_troop["sd_idx"]]);
*/

			TASK_D->set_task(task_id,"def_arrange_step","position");
////

                        return 1;
      	}
}
