// sg_skilllearn_d.c write by fire on 26 Dec. 1997
// modified by fire on June 02, 1999
// daemons LEARNCHECK_D

#include <sanguo.h>

#define TOO_MANY_SKILLS 15
#define CAST_D "/daemons/cast_d.c"

inherit M_DAEMON_DATA;

int level_to_exp( int par_nLevel, int par_nGift );
int exp_to_level( int par_nExp, int par_nGift );

int literate_to_skill(int lit)
{
    	int ret=15;
    	while(lit>0) {
      		if(lit>10) ret+=10;
      		else ret+=lit;
      		lit-=10;
      		lit/=2;
    	}
    	return ret;
}
string get_need_gift(string p_sk)
{
	int basej;
	switch( SG_SKILL_D->query_type(p_sk) ) {
                case 2  : return "meili";       // �����з�
                case 3  : return "wuli";        // ��ѧ��
                case 4  : 
			switch(CAST_D->get_cast(p_sk)["base"])
			{ case 1: return "wuli";
			  case 2: return "zhimou";
			  case 3: return "meili";
		   	  default : return "zhimou"; 
			}			// ��ѧ��ı
                case 5  : return "wuli";        // �����书
    		default : switch(p_sk) {
      			case "sk_meili": 	return "meili";
      			case "sk_wuli":  	return "wuli";
      			default :		return "zhimou";
		}
    	}
}
int get_exp_need(int lev,int gift)
{
   	if( lev<30 ) return 0;
   	return lev*lev*20/(gift+1);
}
int check_number_of_skills(string sk, object who)
{
	int type, lvl, num;
	string *skills;
	mapping sks;

	sks  = who->get_sg_skills();
	type = SG_SKILL_D->query_type(sk);

	if( !mapp(sks)||!sizeof(sks) ) return 0;
	if( !(type==2||type==3||type==4) ) return 1;

	if( type==2 ) lvl = who->query_sk_level("sk_meili");
	if( type==3 ) lvl = who->query_sk_level("sk_wuli");
	if( type==4 ) lvl = who->query_sk_level("sk_zhimou");
	
	num = 1+lvl/20;
	skills = keys(sks);
	skills = filter_array(skills, (: SG_SKILL_D->query_type($1)==$(type) :));

	if( sizeof(skills)>num ) return 0;
	else return 1;
}
int check_learn(int mas_level,string sk,string gft) // ��������
{
  	int p_hp,p_sjlev,p_sjexp,p_expneed;
  	int p_gift, p_literate, l_level;
  	object who; 

  	who=this_body();
  	p_hp=who-> query_cur_hp();
  	p_sjlev=who->query_sk_level(sk);
  	p_sjexp=who->query_sk_exp(sk);
  	p_literate=who->query_literate();
  	l_level=literate_to_skill(p_literate);

  	if( p_sjlev>=l_level ) return LESS_LITERATE;
   	if( p_hp<20 ) return TOO_TIRED;
   	if(p_sjlev>mas_level) return TOO_EASY;
   	if( (mas_level-p_sjlev)>30 ) return TOO_DIFFICULT;

  	switch (gft) {
    		case "zhimou":
       			p_gift=who->query_zhimou_pure();
       			break;
    		case "meili":
       			p_gift=who->query_meili_pure();
       			break;
    		case "wuli":
       			p_gift=who->query_wuli_pure();
       			break;
   	}
   	p_expneed=get_exp_need(p_sjlev,p_gift);
   	if(p_expneed>p_sjexp) return LESS_EXP;
  
  	if((p_gift*2+40)<=p_sjlev) return LESS_GIFT;
	
	if( check_number_of_skills(sk,who)!=1 ) return TOO_MANY_SKILLS;
 
  	who->set_sg_skill(sk, p_sjlev+1, p_sjexp-p_expneed);
  	who->set_cur_hp(p_hp-19);

  	return CAN_LEARN;
}
int check_can_learn_skills(string p_sk,int mas_level)
{
        string gft;

        gft=get_need_gift(p_sk);
        return check_learn(mas_level,p_sk,gft);
}

int level_to_exp( int par_nLevel, int par_nGift )
{
    int nSumme = 0;
    
    if ( par_nGift <= 0 || par_nGift > 30 )
    {
        write( "�츳��ֵ����������Χ��\n" );
        return 0;
    }
    
    if ( par_nLevel < 31 )
    {
        return 0;
    }
    else
    {
        int i = 0;
        
        for ( i = 30; i < par_nLevel; i++ )
        {
            nSumme += i*i*20 / par_nGift;
        }
        
    }
    
    return nSumme;
    
}  // end level_to_exp

int exp_to_level( int par_nExp, int par_nGift )
{
    int nLevel = 30;
    int nNeed = 0;
    
    if ( par_nGift <= 0 || par_nGift > 30 )
    {
        write( "�츳��ֵ����������Χ��\n" );
        return 0;
    }
    
    if ( par_nExp <= 0 )
    {
        return 0;
    }
    else
    {
        // �� 31 ����ʼ��Ҫ����
        nNeed = nLevel * nLevel * 20 / par_nGift;
        
        while ( par_nExp >= nNeed )
        {
            par_nExp -= nNeed;
            nLevel++;
            nNeed = nLevel * nLevel * 20 / par_nGift;
        }
        
    }
    
    return nLevel;

}  // end exp_to_level

