// queitem.c by fire@lima in Nov 1998
// this is used to test if this is a robot by item test
private mapping m_class;
int init_class();
string q1(string p_id)
{
   string p_c;
   string p_s,p_ss,ret,question;
   string *c_id;
   int classes;
   ret="";
   c_id=keys(m_class);
   classes=sizeof(c_id);
   p_c=c_id[random(classes)];
   p_s=m_class[p_c][random(sizeof(m_class[p_c]))];
   question=HZK2ASC_D->hzk2asc(p_s)+"����:\n";
   p_ss=c_id[random(classes)];
   if(p_c==p_ss) ret="1";
   question+="1. "+p_ss+"\n";
   c_id-=({p_ss});classes--;
   p_ss=c_id[random(classes)];
   if(p_c==p_ss) ret="2";
   question+="2. "+p_ss+"\n";
   c_id-=({p_ss});classes--;
    
   p_ss=c_id[random(classes)];
   if(p_c==p_ss) ret="3";
   question+="3. "+p_ss+"\n";
   c_id-=({p_ss});classes--;
        
   if(ret=="") ret="4";
   question+="4. ����ѡ�񶼲���.\n";
   tell_user(p_id,question);
   return ret;
}
string q2(string p_id)
{
   string p_c;
   string p_s,p_ss,ret,question;
   string *c_id;
   string *m_c;
   string s1,s2,s3,o;
   int classes;
   ret="";
   c_id=keys(m_class);
   
   classes=sizeof(c_id);
   p_c=c_id[random(classes)];
   c_id-=({p_c});
   m_c=m_class[p_c];
   s1=m_c[random(sizeof(m_c))];
   m_c-=({s1});
   s2=m_c[random(sizeof(m_c))];
   m_c-=({s2});
      
   s3=m_c[random(sizeof(m_c))];
   m_c-=({s3});
   p_c=c_id[random(classes-1)];
   o=m_class[p_c][random(sizeof(m_class[p_c]))];
   s1=HZK2ASC_D->hzk2asc(s1);
   o=HZK2ASC_D->hzk2asc(o);
   switch(random(4))
   {  case 0:
        question=o+s1+s2+s3+"\n";
        ret="1";
        break;
      case 1:
        question=s1+o+s2+s3+"\n";
        ret="2";
     break;
      case 2:
        question=s1+s2+o+s3+"\n";
        ret="3";
       break;
      case 3:
        question=s1+s2+s3+o+"\n";
        ret="4";
   }
   question+="�������ֶ�����,��������������һ�����:\n";
   question+="1. ��һ������\n";
   question+="2. �ڶ�������\n";
   question+="3. ����������\n";
   question+="4. ���ĸ�����\n";
   tell_user(p_id,question);
   return ret;
}
string test(string p_id)
{
   int classes;
   string ret;
   init_class();
   switch(random(2))
   {
      case 0:  // ��һ��
        ret=q1(p_id);
        return ret;
      case 1: 
        ret=q2(p_id);
        return ret;
   }
}
int init_class()
{
   m_class=([]);
   m_class["���鶯��"]=({"è","��","ɽ��","�ϻ�","ʨ��","����","��",
"Ұè","����","�Ա�","��","¹","����","Ϭţ","ţ","��","����¹",
"��è","����","����","����","����","����","����","����","����",
"���"});
   m_class["����"]=({"��","��Ӭ","�۷�","���","����","����","���",
"����","����","����","��","�׳�","��ƨ��","ө���","�ȳ�","��Ӭ",
"ëë��","ţ�","����","ư��","��","����","���"});
   m_class["����"]=({"��Ÿ","����","����","��ȸ","��ľ��","������",
"����","����","��","Ѽ��","��","���","��ӥ","èͷӥ","���","��˿ȸ",
"����","����","����","��ѻ","ϲȵ","ҹݺ","�˸�","��ü","��ȸ","����",
"���"});
   m_class["ˮ��"]=({"ƻ��","��","�㽶","����","����","ӣ��","�޻���",
"����","ʯ��","����","â��","����","���۹�","���","���","����","����",
"��ݮ","��"});
   m_class["�߲�"]=({"����","����","����","������","���","�²�","���",
"���ܲ�","�۲�","����","��","��","����","�ƹ�","Ģ��","����«","����",
"����"});
   return sizeof(m_class);
}
