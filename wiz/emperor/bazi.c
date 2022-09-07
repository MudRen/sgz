
mixed y1 = ({
 0,45,30,15,
 0,45,30,15,
 0,45,30,15,
 0,45,30,({15,5}),
50,34,18, 2,
47,31,15,59,
44,28,12,56,
41,25, 9,53,
38,22, 6,50,
35,19, 3,47,
31,15,59,43,
28,12,56,40,
25, 9,53,37,
});

mixed y2 = ({
 0, 5,10,15,21,26,31,36,42,47,
52,57, 3, 8,13,18,24,29,34,39,
45,50,55, 0, 6,11,16,21,27,32,
37,42,48,53,58, 3, 9,14,19,24,
30,35,40,45,51,56, 1, 6,12,17,
22,27,33,38,43,48,54,59, 4, 9,
15,20,25,30,36,41,46,51,57, 2,
 7,12,18,23,28,33,39,44,49,54,
 0, 5,10,15,21,26,31,36,42,47,
52,57, 3, 8,13,18,24,29,34,39,
});

mixed m = ({
({8,7}),({39,38}),7,38,
8,39,9,40,
11,41,12,42,
});
string *Gan=({"��","��","��","��","��","��","��","��","��","��"});
string *Zhi=({"��","��","��","î","��","��","��","δ","��","��","��","��"});

int runnianp(int y){
	int flag;
	if(y>0&&y<5200){
		if(!(y%4000)){flag =0;}
		else if(!(y%100)){
			if(!(y%400)){
				flag = 1;
			}else flag = 0;
		}else if(!(y%4)){
			flag=1;
		}else flag = 0;
	}//else return "bug\n";
	return flag;
}

mixed get_gz(int y, int mon, int d, int min){
	string gz,ngz,ygz,sgz;
	int a,b,c,flag;
	if( y==1582 && mon==10 && d > 4 && d < 15 ) return "�޴����ڡ�\n";
	if(y<0) {
		b=(100+(y+1)%100)%100;
		if(b!=0) a = 100-y-1; 
		else a = -y-1;
		a =to_int(a/100)%4*15;
		b = y2[b];
	}else if(y<5200){
		a =to_int(y/100);
		if(a==15){
			if((y%100)>82){
				a = 5;
			}
			if((y%100)<82){
				a = 15;
			}
			if((y%100)==82){
				if(mon>10) a = 5;
				if(mon<10) a = 15;
				if(mon==10) {
					if(d<=4)a = 15;
					if(d>=15) a = 5;
				}
			}
		}else a =y1[a];
		b = y2[y%100];
	}
/*
	if(y>0&&y<5200){
		if(!(y%4000)){flag =0;}
		else if(!(y%100)){
			if(!(y%400)){
				flag = 1;
			}else flag = 0;
		}else if(!(y%4)){
			flag=1;
		}else flag = 0;
	}//else return "bug\n";
*/
	flag = runnianp(y);
	mon -= 1;
	if(mon==0||mon==1) c = m[mon][flag];
	else c = m[mon];
	printf("%d year=%d+%d\n",y,a,b);
	
	printf("%d month =%d %d\n",mon,c,d);
	flag =(a+b+c+d);
	a = flag;
	printf("%d\n",flag);
	gz = Gan[(flag-1)%60%10]+Zhi[(flag-1)%60%12];
	if(y>0)b=y-3;else b=y+1-3;
	b=b%60;
	if(b<=0)flag = 60+b;
	else flag = b;
//	if(b==0)flag =
	b = flag;
	ngz = Gan[(flag-1)%60%10]+Zhi[(flag-1)%60%12];
	return ({b,ngz,a,gz});
}

float *nla = ({ 28.5700, 23.2326, 18.8952, 13.5579 });

float *nlb = ({
 0.0000, 10.6329, 21.2659,  2.3682, 14.0012, 24.6341,  5.7365, 16.3694, 28.0024,  9.1047,
19.7377,  0.8400, 12.4730, 23.1059,  4.2083, 14.8412, 26.4742,  7.5765, 18.2095, 28.8424,
10.9448, 21.5777,  2.6801, 13.3130, 24.9460,  6.0483, 16.6813, 27.3142,  9.4166, 20.0495,
 1.1519, 11.7848, 23.4177,  4.5201, 15.1530, 25.7860,  7.8883, 18.5213, 29.1542, 10.2566,
21.8955,  2.9919, 13.6248, 24.2578,  6.3601, 16.9931, 27.6260,  8.7284, 20.3613,  1.4637,
12.0966, 22.7296,  4.8319, 15.4649, 26.0978,  7.2002, 18.8331, 29.4660, 10.5684, 21.2013,
 3.3037, 13.9366, 24.5696,  5.6719, 17.3049, 27.9378,  9.0402, 19.6731,  1.7755, 12.4084,
23.0414,  4.1437, 15.7767, 26.4096,  7.5120, 18.1449,  0.2473, 10.8802, 21.5132,  2.6155,
14.2485, 24.8814,  5.9838, 16.6167, 28.2497,  9.3520, 19.9850,  1.0873, 12.7203, 23.3532,
 4.4556, 15.0885, 26.7214,  7.8238, 18.4567, 29.0897, 11.1920, 21.8250,  2.9273, 13.5603,
});

float *nlc = ({ 
	5.6743,  7.1437,  5.6131,  7.0825,  7.5519,  9.0214,
	9.4908, 10.9602, 12.4296, 12.8990, 14.3684, 14.8378,
});

mixed get_nl(int y, int mon, int d){
	int flag, a;
	float b, c;
	if(y<1800||y>2199) return " No NongLi";
	flag = runnianp(y);
	a = to_int(y/100)-18;
	if(flag){
		if(mon == 1 || mon == 2) b=nlc[mon-1]-1;
		else b=nlc[mon-1];
	} else b=nlc[mon-1];
	c = (d>29?(d-29.5306):d);
	c = nla[a]+nlb[y%100]+b+c;
	while (c>29.5306){
		c -= 29.5306;
	}
	printf("%f\n",c);
	b=to_int(c);
	if(c>b) b+=1;
	return b;
}	


mixed lunarInfo=({
0x04bd8,0x04ae0,0x0a570,0x054d5,0x0d260,0x0d950,0x16554,0x056a0,0x09ad0,0x055d2,
0x04ae0,0x0a5b6,0x0a4d0,0x0d250,0x1d255,0x0b540,0x0d6a0,0x0ada2,0x095b0,0x14977,
0x04970,0x0a4b0,0x0b4b5,0x06a50,0x06d40,0x1ab54,0x02b60,0x09570,0x052f2,0x04970,
0x06566,0x0d4a0,0x0ea50,0x06e95,0x05ad0,0x02b60,0x186e3,0x092e0,0x1c8d7,0x0c950,
0x0d4a0,0x1d8a6,0x0b550,0x056a0,0x1a5b4,0x025d0,0x092d0,0x0d2b2,0x0a950,0x0b557,
0x06ca0,0x0b550,0x15355,0x04da0,0x0a5d0,0x14573,0x052b0,0x0a9a8,0x0e950,0x06aa0,
0x0aea6,0x0ab50,0x04b60,0x0aae4,0x0a570,0x05260,0x0f263,0x0d950,0x05b57,0x056a0,
0x096d0,0x04dd5,0x04ad0,0x0a4d0,0x0d4d4,0x0d250,0x0d558,0x0b540,0x0b5a0,0x195a6,
0x095b0,0x049b0,0x0a974,0x0a4b0,0x0b27a,0x06a50,0x06d40,0x0af46,0x0ab60,0x09570,
0x04af5,0x04970,0x064b0,0x074a3,0x0ea50,0x06b58,0x055c0,0x0ab60,0x096d5,0x092e0,
0x0c960,0x0d954,0x0d4a0,0x0da50,0x07552,0x056a0,0x0abb7,0x025d0,0x092d0,0x0cab5,
0x0a950,0x0b4a0,0x0baa4,0x0ad50,0x055d9,0x04ba0,0x0a5b0,0x15176,0x052b0,0x0a930,
0x07954,0x06aa0,0x0ad50,0x05b52,0x04b60,0x0a6e6,0x0a4e0,0x0d260,0x0ea65,0x0d530,
0x05aa0,0x076a3,0x096d0,0x04bd7,0x04ad0,0x0a4d0,0x1d0b6,0x0d250,0x0d520,0x0dd45,
0x0b5a0,0x056d0,0x055b2,0x049b0,0x0a577,0x0a4b0,0x0aa50,0x1b255,0x06d20,0x0ada0,
0x14b63
});

mixed solarMonth=({31,28,31,30,31,30,31,31,30,31,30,31});
//	Gan=({"��","��","��","��","��","��","��","��","��","��"});
//	Zhi=({"��","��","��","î","��","��","��","δ","��","��","��","��"});

string *Animals=({
	"��","ţ","��","��","��","��",
	"��","��","��","��","��","��",
});

string *solarTerm = ({
	"С��","��","����","��ˮ","����","����",
	"����","����","����","С��","â��","����",
	"С��","����","����","����","��¶","���",
	"��¶","˪��","����","Сѩ","��ѩ","����",
});

string *sTermInfo = ({
	     0, 21208, 42467, 63836, 85337,107014,
	128867,150921,173149,195551,218072,240693,
	263343,285989,308563,331033,353350,375494,
	397447,419210,440795,462224,483532,504758,
});

string *nStr1 = ({"��","һ","��","��","��","��","��","��","��","��","ʮ"});
string *nStr2 = ({"��","ʮ","إ","ئ","��"});
string *monthName = ({"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"});
/*
int UTC(string s){
	int year,month,date,hour,minute,second;
    sscanf(s,"%d-%d-%d %d:%d:%d",year,month,date,hour,minute,second);
    Seconds=31556925.9747*(year-1900)+
    Seconds=31556925.9747*(year-1900) + sTermInfo[n]*60  ) + UTC(1900-1-6 2:5);
}
*/
