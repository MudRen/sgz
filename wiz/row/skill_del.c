// skill_del.c write by fire on Dec 26 
#include <mudlib.h>
#include <config.h>
#include <classes.h>
#include <ansi.h>
#include <sanguo.h>
inherit CMD;
private void main(string arg)
{
    string skill;
    skill=arg;  // ��ѧ����
    SG_SKILL_D->remove_skill(skill);
}
