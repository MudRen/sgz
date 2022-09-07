// Updated by stefan 10 Jan 1997
// added s_digit by tset 30 Nov 1998
// chinese_d.c
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
// adapted for ES2-lib 01-18-95

#include <localtime.h>
#include <log.h>

inherit M_DAEMON_DATA;

static string *c_digit = ({ "��","ʮ","��","ǧ","��","��","��" });
static string *c_num = ({"��","һ","��","��","��","��","��","��","��","��","ʮ"});
static string *s_digit = ({"��","��","��","��","��","��","��","��","��","��"});
static string *k_digit = ({"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"});
static string *sym_tien = ({ "��","��","��","��","��","��","��","��","��","��" });
static string *sym_dee = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });


mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );

void create()
{
    ::create();
}

string * s_array() { return s_digit; }

string chinese_number2(int i) {
    if( i < 1 || i > 10 ) return "��";
    else return(s_digit[i-1]);
}

string chinese_number3(int i)
{
    if( i < 0 || i > 20 ) return "��";
    else return(k_digit[i]);
}

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
            return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i%100);
        else if( i%100 < 20 )
            return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i%100);
        else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
    }
    if( i<10000 ) {
        if( i%1000==0 )
            return c_num[i/1000] + c_digit[3];
        else if( i%1000 < 100 )
            return c_num[i/1000] + c_digit[3] + c_digit[0] + chinese_number(i%1000);
        else
            return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
    }
    if( i<100000000 ) {
        if( i%10000==0 )
            return chinese_number(i/10000) + c_digit[4];
        else if( i%10000 < 1000 )
            return chinese_number(i/10000) + c_digit[4] + c_digit[0] + chinese_number(i%10000);
        else
            return chinese_number(i/10000) + c_digit[4] + chinese_number(i%10000);
    }
    if( i<1000000000000 ) {
        if( i%100000000==0 )
            return chinese_number(i/100000000) + c_digit[5];
        else if( i%100000000 < 10000000 )
            return chinese_number(i/100000000) + c_digit[5] + c_digit[0] + chinese_number(i%100000000);
        else
            return chinese_number(i/100000000) + c_digit[5] + chinese_number(i%100000000);
    }
        if( i%1000000000000==0 )
            return chinese_number(i/1000000000000) + c_digit[6];
        else if( i%1000000000000 < 100000000000 )
            return chinese_number(i/1000000000000) + c_digit[6] + c_digit[0] + chinese_number(i%1000000000000);
        else
            return chinese_number(i/1000000000000) + c_digit[6] + chinese_number(i%1000000000000);
}


// This is called by to_chinese() simul_efun
private string chinese(string str)
{
    if( !undefinedp( dict[str] ) ) return dict[str];
    else return str;
}

void remove_translate( string key )
{
  map_delete( dict, key );

  LOG_D->log(LOG_FILE_CHINESE, sprintf("%sɾ�����Ķ�Ӧ %s ��%s\n",
    this_player()->short(), key, CHINESE_D->chinese_time(time()))
  );
  save_me();
}

void add_translate( string key, string chinz )
{
    dict[key] = chinz;

    LOG_D->log(LOG_FILE_CHINESE, sprintf("%s�趨 %s ��Ӧ������ %s ��%s\n",
      this_user()->short(), key, chinz, CHINESE_D->chinese_time(time()))
    );
   save_me();
}

mapping query_translate()
{
  if( !undefinedp( dict )) return dict;
  else return ([]);
}

// ��ʽ��ʱ��
string chinese_date(int date)
{
    mixed *local;

    local = localtime(date);

    return sprintf("%s%s��%s��%s��%sʱ",
        sym_tien[local[LT_YEAR]%10], sym_dee[local[LT_YEAR]%12],
        chinese_number(local[LT_MON]+1),
        chinese_number(local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0)),
        sym_dee[local[LT_HOUR]/2]);
        // chinese_number((local[LT_MIN]+1)%2 * 2 + local[LT_MIN]/30 + 1));
}

// ���ĵ�ʱ��
string chinese_time(int date)
{
        mixed *local;
    int   hour, min;
    string  msg;

        local = localtime(date);
        hour  = local[LT_HOUR];
    min = local[LT_MIN];

        msg = sprintf("%s��%s��%s��",
                chinese_number(local[LT_YEAR]),
                chinese_number(local[LT_MON]+1),
                chinese_number(local[LT_MDAY])
          );
    if ( (hour>12) )
      msg += "����"+chinese_number(hour-12)+"ʱ";
        else msg += "����"+chinese_number(hour)+"ʱ";
        if (min==0)
      msg += "��";
    else
      msg += chinese_number(min)+"��";

    return msg;
}

// ת��ʱ������Ϊ���켸Сʱ���ּ���
string chinese_period(int sec)
{
  mixed *local;
  string msg;
  int    day, hour, min;

  if(sec==0) return c_digit[0];
  day = sec/86400;
  sec = sec % 86400;
  hour = sec/3600;
  sec = sec % 3600;
  min = sec / 60;
  sec = sec % 60;
  msg = "";
  if (day>0) msg += chinese_number(day)+"��";
  if (hour>0) msg += chinese_number(hour)+"Сʱ";
  if (min>0) msg += chinese_number(min)+"��";
  if (sec>0) msg += chinese_number(sec)+"��";

  if ((msg != "")&&(min||sec)) msg += "��";
  return msg;
}

string chinese_value (int value)
{
        int gold, silver, coin;

        if( !value )
                return sprintf("һ�Ĳ�ֵ");
        else
        {
          gold = value/10000;
          silver = (value%10000)/100;
          coin = value%10000%100;

          if (coin)
              return sprintf("%s%s%s��Ǯ",
                gold?chinese_number(gold)+"����":"",
                silver?chinese_number(silver)+"����":"",
                chinese_number(coin));
          else if (silver)
              return sprintf("%s%s������",
                gold?chinese_number(gold)+"����":"",
                chinese_number(silver));
          else
              return sprintf("%s������",
                chinese_number(gold));
        }
}
