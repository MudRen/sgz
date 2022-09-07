// horse_attack.c by fire on Nov 1998
// this is inherited by warai_d.c
void horse_attack_kill(int p_id, string dir);
string get_horse_attack_infomation_b(int p_id,string dir);
string get_horse_attack_infomation(int p_id,string dir);
int kill_troops(mixed t,int p_kill);
void clear_empty_troop(int* t);
int get_neighbor_distance(int p_id,string direction);
mixed get_neighbor_side(int t_id,string direction);
void war_inf(int t_id,string mess,string side);
void info_troop(int p_id,string mess);
void add_war_lose(int t_id,string p_side,string wat,int num);
mixed get_neighbor_defence_rate(int t_id,string direction);
mixed get_neighbor_troops(int t_id,string direction);
void general_attack_kill_back(int p_id,string dir);

mixed can_horse_attack(int p_id,string direction)
{
        int *pos;
        int x,y;
        string p_side;
        mixed p_otherside;
        int dis;
        int tmp;
        
	if (TROOP_D->get_troops(p_id,"qibing") )
	TROOP_D->set_troops(p_id,"qibing",0);
                
	if (TROOP_D->get_troops(p_id,"maifu") )
         TROOP_D->set_troops(p_id,"maifu",0);  	
	
	tmp=TROOP_D->get_horse_kills(p_id);
        if(tmp==0) // no bowman
            return "��û�������\n";
        if(tmp==-1) // two tired
            return "���̫���ˡ�\n";
        if((!direction)||(direction==""))
            return "���ĳ��\n";
        dis=get_neighbor_distance(p_id,direction);
        if(dis>1)
                return "��治���Ƕ���";
        p_side=TROOP_D->get_troops(p_id,"side");
        p_otherside=get_neighbor_side(p_id, direction);
        if(!p_otherside)
                return "����û�ео���\n";
        if(p_side==p_otherside)
                return "��ô�����Ѿ���棿\n";
        if (TROOP_D->get_troops(p_id, "conds"))
        { if (TROOP_D->get_troops(p_id, "conds")["confuse"])
        return "�����У��޷�������\n";
        }
	return 1;
}
mixed do_horse_attack(int p_id,string dir)
{
    string gernal_inf;
    int t_id;
    gernal_inf=get_horse_attack_infomation(p_id,dir);
    t_id=TROOP_D->get_troops(p_id,"task_id");   
    war_inf(t_id,gernal_inf,"b"); // both side
    horse_attack_kill(p_id, dir);
    TROOP_D->horse_attack_consume(p_id);
	general_attack_kill_back(p_id,dir);

}
void horse_attack_kill(int p_id, string dir)
{
    string mess;
    int p_kill,p_defrate;
    int *t;
	p_kill=TROOP_D->get_attack_rate(p_id,"horse");
    t=get_neighbor_troops(p_id,dir);
    
    // xiaobai: increase the horse power
//    p_kill *= 1.1;
    
	p_kill=TROOP_D->attack_troops(t,p_kill,"horse");

    mess=get_horse_attack_infomation(p_id,dir);
    info_troop(p_id,mess);
        info_troop(p_id,"%^H_GREEN%^����о�"+
    CHINESE_D->chinese_number(p_kill)+"�ˣ�%^RESET%^\n");
    mess=get_horse_attack_infomation_b(p_id,dir);
    info_troop(t[0],mess);
    info_troop(t[0],"%^H_RED%^�ҷ���ʧ"+
      CHINESE_D->chinese_number(p_kill)+"�ˣ�%^RESET%^\n");
    clear_empty_troop(t);

}
