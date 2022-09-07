// Updated by stefan 10 Jan 1997
// chinese_da.c modified by fire 11 Dec 1997
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
// adapted for ES2-lib 01-18-95
static string *c_digit = ({ "��","ʮ","��","ǧ","��","��","��" });
static string *c_num = ({"��","һ","��","��","��","��","��","��","��","��"
,"ʮ"});
static string *sym_tien = ({ "��","��","��","��","��","��","��","��","��",
"��" });
static string *sym_dee = ({ "��","��","��","î","��","��","��","δ","��","
��","��","��" });
mapping dict = ([]);
void add_translate( string key, string chinz );
void remove_translate( string key );
//void create()
//{
//    ::create();
//}                  // deleted by fire
string chinese_number(int i)
{
    if( i<0 ) return "��" + chinese_number(-i);
    if( i<11 ) return c_num[i];
    if( i<20 ) return c_num[10] + c_num[i-10];
    if( i<100 ) {
        if( i%10 ) return c_num[i/10] + c_digit[1] + c_num[i%10];
        else return c_num[i/10] + c_digit[1];
    }
    if( i<1000 ) {
        if( i%100==0 )
            return c_num[i/100] + c_digit[2];
        else if( i%100 < 10 )
            return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i
%100);
        else if( i%100 < 20 )
            return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i
%100);
        else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
    }
    if( i<10000 ) {
        if( i%1000==0 )
            return c_num[i/1000] + c_digit[3];
        else if( i%1000 < 100 )
            return c_num[i/1000] + c_digit[3] + c_digit[0] +
chinese_number(i%1000);
        else
            return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
    }
    if( i<100000000 ) {
        if( i%10000==0 )
            return chinese_number(i/10000) + c_digit[4];
        else if( i%10000 < 1000 )
            return chinese_number(i/10000) + c_digit[4] + c_digit[0] +
chinese_number(i%10000);
        else
            return chinese_number(i/10000) + c_digit[4] + chinese_number(i
%10000);
    }
    if( i<1000000000000 ) {
        if( i%100000000==0 )
            return chinese_number(i/100000000) + c_digit[5];
        else if( i%100000000 < 10000000 )
            return chinese_number(i/100000000) + c_digit[5] + c_digit[0] +
chinese_number(i%100000000);
        else
            return chinese_number(i/100000000) + c_digit[5] +
chinese_number(i%100000000);
    }
        if( i%1000000000000==0 )
            return chinese_number(i/1000000000000) + c_digit[6];
        else if( i%1000000000000 < 100000000000 )
            return chinese_number(i/1000000000000) + c_digit[6] +
c_digit[0] + chinese_number(i%1000000000000);
        else
            return chinese_number(i/1000000000000) + c_digit[6] +
chinese_number(i%1000000000000);
}
string chinese_value (int value)
{
        int gold, silver, coin;
        if( !value )
                return sprintf("һ�Ĳ�ֵ��\n");
        else
        {
          gold = value/10000;
          silver = (value%10000)/100;
          coin = value%10000%100;
          if (coin)
              return sprintf("%s%s%s��Ǯ��\n",
                gold?chinese_number(gold)+"����":"",
                silver?chinese_number(silver)+"����":"",
                chinese_number(coin));
          else if (silver)
              return sprintf("%s%s�����ӡ�\n",
                gold?chinese_number(gold)+"����":"",
                chinese_number(silver));
          else
              return sprintf("%s�����ӡ�\n",
                chinese_number(gold));
        }
}
