// troop_d.c
// this is used to handle the troops
// because the troop are so complex therefore need a file to contorl them
// by fire on September 17, 1998
//
// modified by xiaobai, August 2001
//

#define STAGE_NEW 0

#include <sgarmy.h>
#include <sgtroop.h>
#include <mudlib.h>
#include <security.h>

inherit M_ACCESS;

inherit __DIR__+"troop_d/troop_attack";
inherit __DIR__+"troop_d/consume";
inherit __DIR__+"troop_d/array";
inherit __DIR__+"troop_d/horse";
inherit __DIR__+"troop_d/number";

private mapping p_troops=([]);
private SGtroop p_trp;
private int p_maxid=1;
static int save_mark;

#define SAVE_FILE "/data/daemons/sgtroop"
#define TROOP_TYPE(x) "/sgdomain/troops/"+x+".c"

// whether an id is valid, 1 for yes, 0 for no
int id_valid( int par_nId );

// check whether the troop is in certain status
int check_status( int par_nId, string par_strStatus );

mixed find_troop(int p_id);
int put_troop(int p_id,string r_id);
int illegal_troop(int t_id);
// Add new function recover energy instead of WARAI_D
void recover_energy(int p_id);
void recover_troop(int p_id);
void add_morale(mixed p_id, int va);
string get_troop_side(int p_id);

// whether an id is valid, 1 for yes, 0 for no
int id_valid( int par_nId )
{
    int* keys;
    
    if ( !p_troops )
        return 0;
    
    keys = keys( p_troops );
    
    if ( member_array( par_nId, keys ) < 0 )
        return 0;
    else
        return 1;
    
}  // end id_valid

void save_data()
{
    save_mark++;
    if((save_mark<0)||(save_mark>20))
    {
            save_mark=0;
            unguarded(1, (: save_object, SAVE_FILE :));
    }
}  // end save_data

int new_troop_id( int par_nArmyId )
{
    int *list;
    int p_id = 1;
    int i;
    string strNation;
    class SGtroop trpNew;
    
    if( !p_troops )
        p_troops = ([]);
    
    list=keys( p_troops );
    
    p_maxid++;
    
    if( p_maxid > 1000 )
        p_maxid=1;
    
    while( member_array(p_maxid,list)!= -1 )
        p_maxid++;
    
    p_id = p_maxid;
    
    trpNew = new(class SGtroop);
    
    trpNew->m_nArmyId = par_nArmyId;
    trpNew->m_nTrpId = p_id;
    
    p_troops[p_id] = trpNew;
        
    return p_id;

}  // end new_troop_id 

// initialize the troop data ( must do before building the troop object )
int init_troop_data( int par_nId, class SGtroop par_trpPlan )
{
    string strArea;
    
    if( !id_valid( par_nId ) )
        return 0;
    
    p_trp = p_troops[par_nId];
    
    p_trp->m_strLeaders = par_strPlan->m_strLeaders;
    
    p_trp->m_strLanding = par_strPlan->m_strLanding;
    
    // xiaobai: landing position will be selected before troop object being put in the grid room
    
    // status
    strArea = SGARMY->get_city( p_trp->m_nArmyId );

    p_trp->m_nSoldierNum = par_strPlan->m_nSoldierNum;    
    // xiaobai: remove the soldier number from the city here?
    
    p_trp->m_nTrain = AREA_D->get_area( strArea, "train" );
    p_trp->m_nMorale = AREA_D->get_area( strArea, "train" );
    p_trp->m_nEnergy = 0;
    
    p_trp->m_strRighthandItem = par_trpPlan->m_strRighthandItem;
    p_trp->m_strLefthandItem = par_trpPlan->m_strLefthandItem;
    p_trp->m_strArmor = par_trpPlan->m_strArmor;
    p_trp->m_strHorse = par_trpPlan->m_strHorse;
    p_trp->m_strCraft = par_trpPlan->m_strCraft;
    
    return 1;
    
}  // end init_troop_data


// return array of position x, y
int* get_troop_position( int par_nId )
{
    if( !id_valid( par_nId ) )
        return NULL;
    
    p_trp = p_troops[par_nId];
    
    return ({p_trp->m_nPosX, p_trp->m_nPosY});

}  // end get_troop_position

string get_troop_name( int par_nId )
{
    string strRet;
    string strArmyName;
    string* strArr;
    string strLeader;
    
    if ( !id_valid( par_nId ) )
        return "";
        
    p_trp = p_troops[par_nId];
        
    strArmyName = SGARMY_D->get_name_prefix( p_trp->m_nArmyId );
    
    if ( strArmyName == "" )
        return "";
    
    strArr = explode( p_trp->m_strLeaders, "," );
    strLeader = strArr[0];
        
    strRet = sprintf( "%s%s%s", strArmyName, strLeader, "��" );
    
    return strRet;
    
}  // get_troop_name

// check whether the troop is in certain status
int check_status( int par_nId, string par_strStatus )
{
    string* strArr;
    
    if ( !id_valid( par_nId ) )
        return 0;
        
    p_trp = p_troops[par_nId];
    
    // split the status line into key words array
    strArr = explode( p_trp->m_strStatus, "," );
    
    if ( member_array( par_strStatus, strArr ) < 0 )
    // not found the key word
        return 0;
    else
        return 1;
    
}  // end check_status

// mark a status to the troop
int mark_status( int par_nId, string par_strStatus )
{
    string* strArr;
    
    if ( !id_valid( par_nId ) )
        return 0;
        
    p_trp = p_troops[par_nId];
    
    // check whether the mark is already there
    if ( !check_status( par_nId, par_strStatus ) )
    {
        p_trp->m_strStatus += sprintf( ",%s", par_strStatus );
        return 1;
    }
    else
        return 0;
    
}  // end mark_status

// remove a status mark from the troop
int remove_status( int par_nId, string par_strStatus )
{
    string* strArr;
    
    if ( !id_valid( par_nId ) )
        return 0;
        
    p_trp = p_troops[par_nId];
    
    strArr = explode( p_trp->m_strStatus, "," );
    
    // check whether the mark is there
    if ( member_array( par_strStatus, strArr ) < 0 )
    {
        return 0;
    }
    else
    {
        strArr -= ({par_strStatus});
        
        p_trp->m_strStatus = implode( strArr, "," );

    }
    
    return 1;
    
}  // end remove_status

// whether the troop can be seen by the enemy
int get_troop_canbeseen( int par_nId )
{
	string strSide;
	int x,y;
    int *trpArr;
	string strM;
	string strArea;
	SGtroop trpNear;
	int nNearId;
	
	if ( !id_valid( par_nId ) )
	    return 0;
	
	p_trp = p_troops[par_nId];

	strArea = SGARMY_D->get_wararea( p_trp->m_nArmyId );
	strSide = SGARMY_D->get_side( p_trp->m_nArmyId );
	
	for( x = p_trp->m_nPosX - 3; x <= p_trp->m_nPosX; ++x )
	{
        for( y = p_trp->m_nPosY - 3; y <= p_trp->m_nPosY+3; ++y )
    	{
    	    // get the troop ids of the map cell
    		trpArr = MAP_D->get_map_cell( p_area, y, x, "t" );
            
            if( sizeof(trpArr) )
    		{
    		    nNearId = trpArr[0];
    		    
    		    if ( !id_valid( nNearId ) )
    		        return 0;
    		        
    		    trpNear = p_troops[nNearId];
    		    
    		    if( SGARMY_D->get_side( trpNear->m_nArmyId ) != strSide &&
    				!TROOP_D->check_status( nNearId, SGTRP_QIBING ) && 
    				!TROOP_D->check_status( nNearId, SGTRP_MAIFU ))
    			{
    			    return 1;
    			}
    			
                if( TROOP_D->check_status( nNearId, SGTRP_APPEAR ) )
                      return 1;
    		}
    		
    		if( strSide == "a" )
    		{
    			strM = MAP_D->get_map_cell( p_area, y, x, "m" );
    			
    			if( MAP_D->is_wall( strM ) )
    				return 1;
    		}
	    }
    }

	return 0;
}

int get_soldier_total_number(int p_id)
{
	if ( !id_valid( par_nId ) )
	    return 0;
	
	p_trp = p_troops[par_nId];
	
	return p_trp->m_nSoldierNum;
}

SGtroop get_troop( int par_nId )
{
	if ( !id_valid( par_nId ) )
	    return NULL;
	
	return p_troops[par_nId];

}  // end get_troop

int* list_troops()
{
    return keys(troops);
}

void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));

    return;
}

object get_troop_object( int par_nId ) 
{
	return SGTROOP( par_nId );  // load_object(TROOP+"/"+par_nId), see sanguo.h
}

// create the troop object and put it in the field, 1 for success, 0 for failure
object put_troop( int par_nId )
{
    object o_trp;
    object o_room;
    string strArea;
    string strRoom;

	if ( !id_valid( par_nId ) )
	    return NULL;
	
	p_trp = p_troops[par_nId];

    strRoom = p_trp->m_strRoom;

	if( strRoom[0..10] != "/a/warroom/" )
	{
		string *rs,r_tmp;
		rs=explode( strRoom, "/" );
		rs[2] = rs[1];
		rs[1] = "warroom";
		strRoom = implode(rs,"/");
		p_trp->m_strRoom = strRoom;
	}
	
	o_trp = get_troop_object( par_nId );
	
	if( !o_trp )
		return NULL;
		
    o_room = load_object( strRoom );

    if( !objectp( o_room ) )
		return NULL;
	
	// put the troop in the war grid room	
    o_trp->move( o_room );
    
    strArea = SGARMY_D->get_wararea( p_trp->m_nArmyId );
    
	MAP_D->set_map_cell( strArea, p_trp->m_nPosY, p_trp->m_nPosX, "addtroop" , par_nId );

    return o_trp;
}

object new_troop( int par_nArmyId, class SGtroop par_trpPlan )
{
	int nId;
	nId = new_troop_id( par_nArmyId );
	init_troop_data( nId, par_strPlan );
	
	return put_troop( nId );
}

void remove_troop( int par_nId )
{
    object o_trp,o_char;
    object o_room;
    string strCity;
    string strCharCity;
    string strWarArea;
    string *chars;
    object* objArr;
    
	if ( !id_valid( par_nId ) )
	    return NULL;
	
	p_trp = p_troops[par_nId];
  
    chars = explode( p_trp->m_strLeaders, "," );
  
    // �� chars �Żػ���ĵط�
    if( sizeof(chars) )
    {
        foreach( string strId in chars )
        {
            if(CHAR_D->get_char( strId, "is_tmp" ))
                CHAR_D->remove_char( strId );
            else
            {
                strCharCiy = CHAR_D->get_char( strId, "area" );

                // put the char to the meeting room
                CHAR_D->put_char( strId, AREA_D->get_area( strCharCity, "path" )+
                	  AREA_D->get_area( strCharCity, "meeting" ) );

                o_char = CHAR_D->find_char( strId );
                if( objectp(o_char) )
                    o_char->simple_action("$N��ս���ϳ���������\n");
            }
        }
    }

    if( o_trp && objectp( o_trp ) )
    {
        // the war grid room
         o_room = environment( o_trp );
         
         if( objectp( o_room ) )
         {
        //        p_area=AREA_D->check_area("area",o_room->get_area())[0];
        	strWarArea = o_room->query_aid();
            MAP_D->set_map_cell( strWarArea, p_trp->m_nPosY, p_trp->m_nPosX, "subtroop", par_nId );
         }

        objArr = all_inventory( o_trp );

        if( sizeof(objArr) )
        {
        	foreach ( object o in objArr )
        	{
        		if(o->is_living())
        		{
        			o->move(VOID_ROOM); // should be wiz
        			o->simple_action("$N��һ���ߵ������ޡ�\n");
        		}
        		else
        			o->remove();
        	}
        }
        
        o_trp->remove();
    }

	strCity = SGARMY->get_city( p_trp->m_nArmyId );
    
    // add the soldiers to the city
	if( AREA_D->area_exist(strCity) )
	{
		int nOldNum;
		int nNewNum; 
		int nTmp;

		nOldNum = AREA_D->get_area( strCity, "soldier" );
// adding       
                //SUBUG(sprintf("troop %d type %s number %d area %s\n",p_id,t,p_num,s_area));
		if( check_status( par_nId, SGTRP_COMMANDO )
		{
            AREA_D->set_area( strCity, "population",
                AREA_D->get_area( strCity, "population" ) + p_trp->m_nSoldierNum );
        }
		else 
		{
		    nNewNum = nOldNum + p_trp->m_nSoldierNum;
            AREA_D->set_area( strCity, "soldier", nNewNum );

			nTmp = AREA_D->get_area( strCity, "train" );
           	nTmp = ( nTmp * nOldNum + p_trp->m_nTrain * (p_trp->m_nSoldierNum+1)) /
                        	( nNewNum + 1 ); // incase divide by zero
			AREA_D->set_area( strCity, "train", nTmp );

			nTmp = AREA_D->get_area( strCity, "morale" );
           	nTmp = ( nTmp * nOldNum + p_trp->m_nMorale * (p_trp->m_nSoldierNum+1)) /
                        	( nNewNum + 1 ); // incase divide by zero
			AREA_D->set_area( strCity, "morale", nTmp );
		}
// end
/*					if(t!="commando") {
						p_morale=AREA_D->get_area(s_area,"morale");
						p_morale=(p_morale*p_oldsoldier+p_s[t]["morale"]*p_num)/
						(p_oldsoldier+p_num+1); // incase divide by zero
						AREA_D->set_area(s_area,"morale",p_morale);

						p_morale=AREA_D->get_area(s_area,"train");
						p_morale=(p_morale*p_oldsoldier+p_s[t]["train"]*p_num)/
						(p_oldsoldier+p_num+1); // incase divide by zero
						AREA_D->set_area(s_area,"train",p_morale);
					}


					switch(t) {
					case "infantry": 
						AREA_D->set_area(s_area,"soldier",
							AREA_D->get_area(s_area,"soldier")+p_num);
						break;
					case "cavalry" :
						AREA_D->set_area(s_area,"soldier",
							AREA_D->get_area(s_area,"soldier")+p_num);
						AREA_D->set_area(s_area,"horse",
							AREA_D->get_area(s_area,"horse")+p_num);
						break;
						
					case "bowman"  : 
						AREA_D->set_area(s_area,"soldier",
							AREA_D->get_area(s_area,"soldier")+p_num);
						AREA_D->set_area(s_area,"bow",
							AREA_D->get_area(s_area,"bow")+p_num);
						break;
					case "commando"  :
						AREA_D->set_area(s_area,"population",
						AREA_D->get_area(s_area,"population")+p_num);
						break;
					}
*/
				}
			}
		
		}
	}
	map_delete( p_troops, par_nId );

}  // end remove_troop

void clear_all()
{
	mixed keys;
	int i,sum;
	keys=keys(troops);
	sum = sizeof(keys);
	for( i=0; i<sum; ++i )
	{
		remove_troop(keys[i]);
	}	
}

int get_char_troopid( string id ) 
{
	int *t;
	string *cs; //chars
	
	t=keys(troops);
	
	if(!sizeof(t))
	    return 0; // no troop
	
	foreach(int mt in t) 
	{
	    if ( id_valid( mt ) )
	    {
	        p_trp = p_troops[mt];
	        
    		cs = explode( p_trp->m_strLeaders, "," );
    		
    		if(!sizeof(cs))
    		    continue;
    		
    		if( member_array( id, cs ) != -1 )
    		    return mt;
	    }
	    else
	        continue;
	}
	
	return 0;
}

// New function recover energy
private void recover_energy(int p_id)
{
        int i, x, y, weather;
        mapping sol;
        string area, *list, envir, type;
        object ob, env;

	int task_id=troops[p_id]["task_id"];
	if(TASK_D->get_task(task_id,"start_war")!="yes")
		return;

	if((troops[p_id]["side"]=="a")&&(random(2)==0))
		add_morale(p_id,-1);
        ob = find_troop(p_id);
        env = environment(ob);
        area = env->query_aid();
        weather = AREA_D->get_area(area, "weather");

        x = env->query_pos()[0];
        y = env->query_pos()[1];
        envir = MAP_D->get_map_cell(area, x, y, "m");

        sol = troops[p_id]["soldier"];
        list = keys(sol);
        for( i = 0; i < sizeof(list); i++){
                type = list[i];
                if( file_size(TROOP_TYPE(type)) != -1 )
                        sol[type]["energy"] = sol[type]["energy"] +
				load_object(TROOP_TYPE(type))->query_energy_recover(envir, weather,ob->query("zhenfa"))
				*((sol[type]["morale"]+sol[type]["train"])/8+5)/10;
                else sol[type]["energy"] = sol[type]["energy"] +load_object(TROOP_TYPE("commando"))->query_energy_recover(envir,weather,ob->query("zhenfa"))
			*((sol[type]["morale"]+sol[type]["train"])/8+5)/10;
		if( sol[type]["energy"] > 30 ) sol[type]["energy"] = 30;
        };
}

void recover_troop( int par_nId )
{   
   put_troop( par_nId );   
}

void remove()
{
	save_mark=20;
	save_data();
}

int clean_up()
{
   return 0; // means never_again
}

void add_morale( int par_nId, int par_nVal )
{
	if ( !id_valid( par_nId ) )
	    return;
	
	p_trp = p_troops[par_nId];
	
	p_trp->m_nMorale += par_nVal;
	
	if ( p_trp < 0 )
	    p_trp->m_nMorale = 0;
	    
}

void add_train( int par_nId, int par_nVal )
{
	if ( !id_valid( par_nId ) )
	    return;
	
	p_trp = p_troops[par_nId];
	
	p_trp->m_nMorale += par_nVal;
	
	if ( p_trp < 0 )
	    p_trp->m_nMorale = 0;
}

// don't call this until you know what you are going to do
int force_clear() {
	troops=([]);
	save_data();
	return 1;
}
