// sg_skill_class.c
// by fire on Dec 26 1997
// SK_NOR normal skills such as the wuli weili and zhimou 1
// SK_FIGHT skills used in fight such as ����ǹ 2
// SK_ZHENG skills for �� 3
// SK_JI skills of �� 
class sg_skill_reg    // this class is used for register dif skills
{
    string sk_name;   // the chinese name for a skill
    int sk_type; // 
    string sk_get; // when this skill get, what will display
    string sk_use; // when this skill used what will display
    string sk_succ; // when this skill succedd what will display
    string sk_fail; // when this skill fail what will display
}
class sg_skill
{
	int sk_level; // curent level
	int sk_exp; // curent experence 
}
