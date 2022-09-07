// cutter.c by fire ��������
// this cmd is used create quick char
inherit CMD;
   
string p_area,p_id,p_name,p_zi;
int p_age,p_wuli,p_meili,p_zhimou;
int p_gender,p_rongmao;
object p_usr;


void over() {
   this_object()->remove();
   return;
}
void create_char() {
   CHAR_D->add_char(p_id);
   CHAR_D->set_char(p_id,"name",p_name);
   CHAR_D->set_char(p_id,"zi",p_zi);
   if(!sizeof(p_zi)) CHAR_D->set_char(p_id,"zi",0);
   CHAR_D->set_char(p_id,"age",p_age);
   CHAR_D->set_char(p_id,"gender",p_gender);

   CHAR_D->set_char(p_id,"rongmao",p_rongmao);
   CHAR_D->set_char(p_id,"wuli",p_wuli);
   CHAR_D->set_char(p_id,"zhimou",p_zhimou);
   CHAR_D->set_char(p_id,"meili",p_meili);

   CHAR_D->set_char(p_id,"area",p_area);
   CHANNEL_D->deliver_tell("rumor","system",
   p_name+"��"+AREA_D->get_area(p_area,"name")+"������");

}
void input_area(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   if(!AREA_D->area_exist(s)) {
      string *ars;
      ars=AREA_D->list_areas();
      s=ars[random(sizeof(ars))];
   }
   p_area=s;
   write("ID�ǣ�"+p_id+"\n");
   write("�����ǣ�"+p_name+"\n");
   write("�����ǣ�"+p_age+"\n");
   write("�Ա��ǣ�"+(p_gender==1 ? "��": "Ů")+"\n");
   write("��ò�ǣ�"+p_rongmao+"\n");
   write("���ǣ�"+ p_zi+"\n");
   write("������"+p_wuli+"\n");
   write("��ı��"+p_zhimou+"\n");
   write("������"+p_meili+"\n");
   write("������"+p_area+"\n");
   create_char();  
   over();
}

void input_meili(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_meili=to_int(s);
   if((p_meili<1)||(p_meili>30))
     p_meili=10+random(20);
   write("�����ɫ�ĵ�����ȱʡΪ�����\n");
   p_usr->modal_push((:input_area:),"",0,0);
}

void input_zhimou(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_zhimou=to_int(s);
   if((p_zhimou<1)||(p_zhimou>30))
     p_zhimou=10+random(20);
   write("�����ɫ��������[1-30]��ȱʡΪ�����\n");
   p_usr->modal_push((:input_meili:),"",0,0);
}

void input_wuli(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_wuli=to_int(s);
   if((p_wuli<1)||(p_wuli>30))
     p_wuli=10+random(20);
   write("�����ɫ����ı��[1-30]��ȱʡΪ�����\n");
   p_usr->modal_push((:input_zhimou:),"",0,0);
}

void input_rongmao(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_rongmao=to_int(s);
   if((p_rongmao<10)||(p_rongmao>30))
     p_rongmao=10+random(20);
   write("�����ɫ��������[1-30]��ȱʡΪ�����\n");
   p_usr->modal_push((:input_wuli:),"",0,0);
}

void input_zi(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_zi=s;
   write("�����ɫ����ò��[10-30]:ȱʡΪ�����\n");
   p_usr->modal_push((:input_rongmao:),"",0,0);
}

void input_gender(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   if(!sizeof(s)) {
     s="1";
   }
   p_gender=to_int(s);
   if(p_gender!=2) p_gender=1;
   write("�����ɫ���֣�����ȱʡ��\n");
   p_usr->modal_push((:input_zi:),"",0,0);
}

void input_age(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_age=to_int(s);

   if((p_age>70)||(p_age<10)) p_age=random(50)+10;
   write("�����ɫ�Ա�[1 ��|2 Ů]��ȱʡ�С�\n");
   p_usr->modal_push((:input_gender:),"",0,0);
}

void input_name(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //
   if(!sizeof(s)) {
     write("û�н�ɫ������\n");
     over();
     return;
   }
   p_name=s;
     write("�����ɫ����[10-70],ȱʡΪ�����\n");
   p_usr->modal_push((:input_age:),"",0,0);
}

void input_id(string s) {
   string fn,sn;
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //
   if(!sizeof(s)) {
     write("û�н�ɫID��\n");
	over();
     return;
   }
   if(sscanf(s, "%s %s", fn,sn)!=2) {
     write("��ɫID������һ�ո�\n");
	over();
     return;
   }
   if(CHAR_D->char_exist(s)) {
     write("�ý�ɫ�Ѿ����ڡ�\n");
	over();
     return;
   }
   p_id=s;
   write("�������ɫ���ƣ�\n");
   p_usr->modal_push((:input_name:),"",0,0);
}

void main(object usr)
{
   object o;
   p_usr=usr;
   CHANNEL_D->deliver_tell("rumor","system",
   usr->query_body()->short()+"�ֳ�LIMA�������꣬������������");
   write("�������ɫID��\n");
   p_usr->modal_push((:input_id:),"",0,0);
}

