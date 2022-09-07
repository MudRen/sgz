// this is used to handle auto cast
//
// by group on aug 2000
#include <mudlib.h>
#include <daemons.h>

#define __SGJI__ "/sgdomain/jimou/"
int count=0;
void use_jm(string p_id, int t_id);
void cast_jm(string p_id,int t_id,int skill,int type);
int can_fenfa(int p_id);
int can_cast(int p_id);
int can_recover(int p_id);


void start()
{
        int* troops;
        string* chars;
        int sizel, t_id,skills;
int j,k,tp;
        string id,p_id,e_id;
        object ob;


        remove_call_out("start");
        //��ʱ�ر����ģ���NPC jimou������ר��troop_heart������ suicide 20001.4.29
        return; 
        if(!count)
        {
                SGSYS("first time run auto cast.");
        }
        
{
}
                        troops = TROOP_D->list_troops();
        
                sizel = sizeof(troops);

if(DAY_D->get_can_war()==0&&!sizeof(troops))
{
SGSYS("it is not in war time, auto cast terminated.");
}
else
{
tp = 1 + random(3);
for(k=0;k<tp;k++){
        foreach (int i in troops)
        {
                chars = TROOP_D->get_troops(i,"chars");
if(CHAR_D->get_char(chars[0],"taskstr")!="ս��")
                {
                        troops-=({i});
                        continue;
                }
                for(j=0;j<sizeof(chars);j++)
                {
                        id = chars[j];
                if(objectp(find_user(id)))
                        troops -=({i});
                }
        }
        
                        
        count++; 

        if(!sizeof(troops))
        {SGSYS("no NPC troops in the war.");
                
        }
        else{
        t_id = troops[random(sizeof(troops))];
        
        chars = TROOP_D->get_troops(t_id,"chars");

        p_id = chars[random(sizeof(chars))];
                
        SGSYS("choosen npc : "+p_id+".");
        use_jm(p_id,t_id);
        }
        
}
call_out("start",200);
}
}

        
void use_jm(string p_id, int t_id)
{
        int wl, zl, ml;   
        int i,j;
        
        wl = CHAR_D->get_skill(p_id,"sk_wuli");
        zl = CHAR_D->get_skill(p_id,"sk_zhimou");
        ml = CHAR_D->get_skill(p_id,"sk_meili");
        

        i = random(3);
        switch(i)
        {
                case 0: cast_jm(p_id,t_id,wl,0);
                        break;
                case 1: cast_jm(p_id,t_id,zl,1); 
                        break;
                case 2: cast_jm(p_id,t_id,ml,2);
                        break;
                default: break;
        }

        
}
        
                        
void cast_jm(string p_id, int t_id, int skill, int type)
{
        object ob;
        int e_id;
        int i;
        string e_name;
        string* e_chars;
        mapping cond;
        
        ob= CHAR_D->find_char(p_id);

        if(type ==0 )
{

                 if(can_fenfa(t_id))
                {       __SGJI__"fenfa.c"->main(ob);

                        SGSYS("use fenfa skill.");
                        return;
                }
                e_id = can_cast(t_id);

                if(e_id)
                {
               e_chars = TROOP_D->get_troops(e_id,"chars");
                  e_name = e_chars[random(sizeof(e_chars))];
        SGSYS("use jiaoma skill.");
        __SGJI__"jiaoma.c"->show_result(ob,e_name,t_id,e_id);
                        return;
                }
                
                i = random(2);
                if(i)   
                { __SGJI__"qibing.c"->show_result(ob,skill,t_id);
                        SGSYS("use qibing skill.");
                        return;
                }
        
                else
                {
                 __SGJI__"sugong.c"->show_result(ob,skill,t_id);
                        SGSYS("use sugong skill.");
                        return;
                }
        }
                        
        if(type == 1)
        {
                e_id = can_cast(t_id);
                if(e_id)
                {
                i = random(2);
                        
                if(i){
                e_chars = TROOP_D->get_troops(e_id,"chars");
                  e_name = e_chars[random(sizeof(e_chars))];
        SGSYS("use hunluan skill.");
        __SGJI__"hunluan.c"->show_result(ob,e_name,skill,t_id,e_id);
                        return;
        }
        else {   
                e_chars = TROOP_D->get_troops(e_id,"chars");
                  e_name = e_chars[random(sizeof(e_chars))];
        SGSYS("use shidu skill.");
        __SGJI__"shidu.c"->show_result(ob,e_name,skill,t_id,e_id);
                        return;
                }
        }
                SGSYS("no target.");
        }
        
        if(type == 2)
        {
        
          e_id = can_recover(t_id);
                        
          if(e_id)
        { cond = TROOP_D->get_troops(e_id,"conds");
                  if(cond["poison"])
                {
                e_chars = TROOP_D->get_troops(e_id,"chars");
                  e_name = e_chars[random(sizeof(e_chars))];
        SGSYS("use jiedu skill.");
        __SGJI__"jiedu.c"->show_result(ob,e_name,skill,t_id,e_id);
                        return;
                }       
                 if(cond["confuse"])
                {
                e_chars = TROOP_D->get_troops(e_id,"chars");
                  e_name = e_chars[random(sizeof(e_chars))];
        SGSYS("use shoushi skill.");
        __SGJI__"shoushi.c"->show_result(ob,e_name,skill,t_id,e_id);
                        return;   
                }
        }
                        
        else
        {
i = random(4);
if(!i){
                SGSYS("use zhanbu skill.");
        __SGJI__"zhanbu.c"->show_result(ob,skill,t_id,0);
                        return;   
                }
         
                else {  
                 SGSYS("use guwu skill.");
        __SGJI__"guwu.c"->show_result(ob,t_id,skill);
                        return;
                }
                
        }
}
return;
}        
                
                 

                 
int can_fenfa(int p_id)
{
        int* troops;
        string where;
        int i,x,y,xtmp,ytmp,cn,x2,y2,id;
 
         troops = TROOP_D->list_troops();
        troops = troops - ({ p_id });
        if( !sizeof(troops) )return 0;
        where = TROOP_D->get_troop_area(p_id);
        if(sizeof(troops) < 2)return 0;
 
        cn =0;
        xtmp = -1;   
        ytmp= -1;
        x = TROOP_D->get_troop_position(p_id)[0];
        y = TROOP_D->get_troop_position(p_id)[1];
        for( i = 0; i < sizeof(troops); i++ ){
                id = troops[i];
                x2 = TROOP_D->get_troop_position(id)[0];
                y2 = TROOP_D->get_troop_position(id)[1];
 
                if( TROOP_D->get_troop_area(id) != where )continue;
                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 1 ||
        TROOP_D->get_troop_side(id)==TROOP_D->get_troop_side(p_id))continue;
                if(xtmp== -1 || ytmp == -1)
                { xtmp = x2;
                 ytmp = y2;
                                cn =1;
                }
                else {if (xtmp != x2 || ytmp!= y2)
                cn++;
                }
                }
        if(cn<2)return 0;
return 1;
}
                 
int can_cast(int p_id)
{
        int* list;
        int* troops; 
        string where, sid;
        int x,y,x2,y2;

        troops = TROOP_D->list_troops();
        troops -= ({p_id});
        list = troops;

        if( !sizeof(troops) )return 0;
        where = TROOP_D->get_troop_area(p_id);
        sid = TROOP_D->get_troop_side(p_id);
        foreach(int e_id in troops)
        {
        x =TROOP_D->get_troop_position(p_id)[0];
        y = TROOP_D->get_troop_position(p_id)[1];
        
        x2 = TROOP_D->get_troop_position(e_id)[0];
                y2 = TROOP_D->get_troop_position(e_id)[1];
                if( TROOP_D->get_troop_area(e_id) != where )
                {list-=({e_id});
                        continue;
                }
                if(TROOP_D->get_troop_side(e_id) == sid)
                {       list-=({e_id});
                        continue;
                }
                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 9 )
                {list-=({e_id});
                        continue;
                }
        }
                 
        if(sizeof(list))
                return list[random(sizeof(list))];
                        
        return 0;
}

int can_recover(int p_id)
{
         int* list;
         int* troops;
        string where, sid;
        int x,y,x2,y2;
                        
        troops = TROOP_D->list_troops();
        list = troops;

        if( !sizeof(troops) )return 0;
        where = TROOP_D->get_troop_area(p_id);
        sid = TROOP_D->get_troop_side(p_id);
        foreach(int e_id in troops)
        {
        x =TROOP_D->get_troop_position(p_id)[0];
        y = TROOP_D->get_troop_position(p_id)[1];
        
        x2 = TROOP_D->get_troop_position(e_id)[0];
                y2 = TROOP_D->get_troop_position(e_id)[1];
                if( TROOP_D->get_troop_area(e_id) != where )
                                {list-=({e_id});
                        continue;
                }
                if(TROOP_D->get_troop_side(e_id) != sid)
                {       list-=({e_id});
                        continue;
                }
                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 9 )
                {list-=({e_id});
                        continue;
                                }
                if(!TROOP_D->get_troops(e_id,"conds"))
                {list-=({e_id});
                        continue;
                                }
                if(!TROOP_D->get_troops(e_id,"conds")["poison"]   
&&!TROOP_D->get_troops(e_id,"conds")["confuse"])
                {list-=({e_id});
                        continue;
                 }
        }
                
        if(sizeof(list))
                return list[random(sizeof(list))];
                                 
        return 0;
}
                
