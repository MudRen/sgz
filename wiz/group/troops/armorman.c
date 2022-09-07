// Define the attack messages of this type of troop
// and give the basic damage it caused
// $G refers to the general in charge of the troop
// $g refers to the general in charge of the enermy
// $N refers to itself and $n refers to enermy troop
private mapping *do_attack = ({
	(["msg":"$G",
	  "damage": 14,]),
        (["msg":"",
          "damage": 12,]),
        (["msg":"",
          "damage": 16,]),
});
mixed query_attack(string environment)
{ 
        return do_attack;
}
// Obtain the id and chinese of this type of troop
string query_id()
{
	return "armorman";
}
string query_name()
{
	return "�ټױ�";
}
string query_type()
{
	return "armorman";
}
// Attack bonus, when attack some troop
// it is a percentage value and can be positive or negative
mapping query_special_attack()
{	

	return (["seaman":10,"cavalry":-10]);
}
// Defence bonus when attacked by some troop
mapping query_special_defence()
{	
	return (["seaman":10,"cavalry":-10]);
}
// Defence ablility of arrow attack
int query_arrow_defence(string environment, int zhenfa)
{
	return 3;
}
// Get the some basic data for combat, now it includes
// energy recover, energy lost, basic attck ability and
// basic defence ability. all the items are affect by
// three factors, enrionment, weeather and zhenfa
int query_energy_recover(string environment, int weather, int zhenfa)
{
        int cost;

        if( environment == "��" ) cost = 10;
        else if ( environment == "��" ) cost = 4;
        else if ( environment == "��" ) cost = 10;
        else if ( environment == "��" ) cost = 10;
        else cost = 11;

        if( weather == 0 ) cost = cost + 1;
        else if( weather == 7 ) cost = cost - 1;
        else if( weather == 8 ) cost = cost - 2;
        else cost = cost;
	
        if( zhenfa = 0 ) cost = cost - 2;
        else cost = cost - 1;
	if (cost<1) cost=1;
        return cost;
}
int query_energy_cost(string environment, int weather, int zhenfa)
{
	int cost;

	if( environment == "��" ) cost =14;
	else if ( environment == "��" ) cost = 15;
	else if ( environment == "��" ) cost = 14;
	else if ( environment == "��" ) cost = 14;
	else cost = 13;

	if( weather == 0 ) cost = cost - 2;
	else if( weather == 2 ) cost = cost + 1;
	else if( weather == 3 ) cost = cost + 2;
	else cost = cost;

	if( zhenfa = 0 ) cost = cost - 2;
	else cost = cost - 1;
	
	return cost;
}
int query_basic_defence(string environment, int weather, int zhenfa)
{
}
int query_basic_attack(string environment, int weather, int zhenfa)
{
}
// Give types of environments where this type of troop
// can not enter
string *query_forbiden()
{
	return ({"��", });
}
// Special abilily of the troop such as bowman can use
// bow and arrow to attack
void powerup()
{
}
// Can it be upgrated and what are the requirements ?
mapping do_upgrade()
{
	return ([
		
	]);
}
// Troops consume money and food, more powerful
// troop needs more
mapping query_cost()
{
	return ([
		"gold": 0.8,
		"food": 1,
	]);
}
// Some type of troops can only be recruited in
// particular cities, NONE means all cities can
string *get_city()
{
	return ({"yunnan" });
}
// Recruitment cost
mapping query_recruit()
{
	return ([
		"gold": 0.8,
	]);
}

