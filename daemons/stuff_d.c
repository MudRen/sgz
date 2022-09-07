/* stuff_d.c by fire on 19/06/99
** This is used to handle the base (factory, farm and so on)
*/
#include <mudlib.h>
#include <security.h>
#define SAVE_FILE "/data/daemons/stuffs"

inherit M_ACCESS;

private mapping bases;

/* Data structure
**	bases = ([ "farm" : 
**			([ "area":(["changan":1, "luoyang":2]),
**			   "level1":(["safe":100,"gold":1000,]),
**			   "pro1":(["food":100]);
**			   "con1":(["gold":30]);
**			   "level2":(["safe":200,"gold":10000,]),
**			])
**		])	
*/

void save_data()
{  
   	unguarded(1, (: save_object, SAVE_FILE :));
}
void create()
{
   	unguarded(1, (: restore_object, SAVE_FILE, 1 :));
   	return;
}
string add_base(string p_id)
{   
    	if( !sizeof(bases) ) bases=([]);
    	if( !bases[p_id] ){   
		bases[p_id] = ([]);
        	save_data();
        	return "new base type added\n";
    	} else return "base already exist\n";
}
string remove_base(string p_id) 
{  
	if ( !bases[p_id] ) return "no such base\n";
   	map_delete(bases, p_id);
   	save_data();
   	return "base removed\n";
}
string add_base_area(string p_id, string p_area) 
{
    	if( !sizeof(bases[p_id]["area"]) ) bases[p_id]["area"] = ([]);
    	if( !AREA_D->area_exist(p_area) ) return "no such area exits\n";
	if( member_array(p_area,keys(bases[p_id]["area"]))!=-1 ) return "base already exits\n";
    	bases[p_id]["area"][p_area] = 1;
	CHANNEL_D->deliver_tell("rumor","system",AREA_D->get_area(p_area,"name")+"�������µ�"+bases[p_id]["name"]+"��");
	save_data();
    	return "OK, added\n";
}
string sub_base_area(string p_id,string p_area) 
{
    	if( !sizeof(bases[p_id]["area"]) ) bases[p_id]["area"] = ([]);
	if( member_array(p_area,keys(bases[p_id]["area"]))==-1 ) return "no such area\n";
    	map_delete(bases[p_id]["area"], p_area);
    	if( !sizeof(bases[p_id]["area"]) ) map_delete(bases[p_id],"area");
	CHANNEL_D->deliver_tell("rumor","system","��Ϊ��Ӫ���ƣ�"+AREA_D->get_area(p_area,"name")+"��"+bases[p_id]["name"]+"�����ˡ�");
	save_data();
    	return "OK, deleted\n";
}
string set_base(string p_id,string para_name,mixed para_value)
{   
    	string p_ret;

    	if( !bases[p_id] ) return "no such base\n";
    	if( intp(para_value)&&(para_value<0) ) para_value=0;

    	switch (para_name){
    		case "add_area":
         		add_base_area(p_id,para_value);
         		break;
   	 	case "sub_area":
         		sub_base_area(p_id,para_value);
         		break;
    		default:
           		if(para_value==0) map_delete(bases[p_id],para_name);
           		else bases[p_id][para_name]=para_value;
      	 		break;
    	}

    	save_data();
    	return "parameter setted\n";
}
mixed get_base(string p_id,string para_name)
{
   	if( p_id=="list" ) return keys(bases);
   	if( (!p_id)||(p_id=="") ) return bases; 
   	if( !bases[p_id] ) return "no such type of base\n";
   	if( (!para_name)||(para_name=="") ) return bases[p_id];

   	switch(para_name) {
     		default:
           		return bases[p_id][para_name];
    	}
}
string stat_me_base(string p_id)
{
   	string p_ret="";
   	mixed c;
   	array ks;
   	int i;

   	if( (!p_id)||(p_id=="") ) p_id="list";
   	if(p_id=="list") {
      		p_ret= "���������嵥��\n";
      		p_ret+="��������������������������������������������������������������������������\n";
      		c=keys(bases);
      		ks=({});
      		for(i=0;i<sizeof(c);++i) ks+=({bases[c[i]]["name"]+"("+c[i]+")"});
      		p_ret+=sprintf("%-#79s\n", implode(ks, "\n"));
   	} else {
       		if( !mapp(bases[p_id]) ){
          		p_ret="û�������������ء�\n";
       		} else {
          		p_ret="����ID��"+p_id+"   �������ƣ�"+bases[p_id]["name"]+"\n";
			p_ret+="�������������а����ȣ�"+bases[p_id]["level1"]["safe"]+"    �ƽ�"+bases[p_id]["level1"]["gold"]+"    ��ʳ��"+bases[p_id]["level1"]["food"]+"\n";
			p_ret+="���������ʣ�"+bases[p_id]["c_name"]+"\n";
			p_ret+="ÿ�����ģ��ƽ�"+bases[p_id]["level1"]["gold"]+"    ��ʳ��"+bases[p_id]["level1"]["food"]+"\n";

			p_ret+="�����������������а����ȣ�"+bases[p_id]["level2"]["safe"]+"    �ƽ�"+bases[p_id]["level2"]["gold"]+"    ��ʳ��"+bases[p_id]["level2"]["food"]+"\n";
			p_ret+="���������ʣ�"+bases[p_id]["c_name"]+"\n";
			p_ret+="ÿ�����ģ��ƽ�"+bases[p_id]["level2"]["gold"]+"    ��ʳ��"+bases[p_id]["level2"]["food"]+"\n";

			p_ret+="�����������������а����ȣ�"+bases[p_id]["level3"]["safe"]+"    �ƽ�"+bases[p_id]["level3"]["gold"]+"    ��ʳ��"+bases[p_id]["level3"]["food"]+"\n";
			p_ret+="���������ʣ�"+bases[p_id]["c_name"]+"\n";
			p_ret+="ÿ�����ģ��ƽ�"+bases[p_id]["level3"]["gold"]+"    ��ʳ��"+bases[p_id]["level3"]["food"]+"\n";
       		}
   	}
   	
	return p_ret;
}
