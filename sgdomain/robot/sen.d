// sen.c by fire@lima in Nov 1998
// this is used to test if this is a robot by item test
#define SEN_PATH "/sgdomain/robot/sentence/"
string getins() {
	int c1,c2;
	c1=random(40)+176;
	c2=random(40)+176;
	return sprintf("%c%c",c1,c2);
}
string getst() {
   string *fs,fn;
   string st,*sts;	

   fs=get_dir(SEN_PATH+"*.txt");
   fn=fs[random(sizeof(fn))];
   fn=SEN_PATH+fn;
   st=read_file(fn,random(10)+1,1);
   sts=explode(st,"��");
   if(!sizeof(sts)) return "";
   st=sts[random(sizeof(sts))];
   if(strlen(st)<8) return "";
   if(st[<1]=='\n')
	   return st[0..<2];
   return st;

}
string q(string p_id)
{
   string st;	
   string ins,question;
   int len,*ps,i,*rs,tmp,r;

   st="";
   while(sizeof(st)==0)
	st=getst();
   len=strlen(st)/2;
   ps=({});
   for(i=0;i<=len;++i)
	ps+=({i});

   rs=({});
   for(i=0;i<4;++i) {
	tmp=ps[random(sizeof(ps))];
	ps-=({tmp});
	rs+=({tmp});
   }	

   r=random(4);

   ins=getins();

   if(rs[r]==0) 
	st=ins+st;
   else if(rs[r]==len)
	 st=st+ins;
   else st=st[0..(rs[r]*2-1)]+ins+st[rs[r]*2..<1];



   question="������仰�У��ڼ�����(������Ҳ����)����������ࡣ\n"+st+"\n";
   for(i=0;i<4;++i)
     question+="��"+chinese_number(rs[i]+1)+"����\n";
   tell_user(p_id,question);
   return ""+(r+1);
}

string test(string p_id)
{
   string ret;
   ret=q(p_id);
   return ret;
}
