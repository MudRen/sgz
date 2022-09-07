// base.c  by fire on Nov 1998
// this is used for ev_mechant.c to inherit
// hold all the base informtion of the good
mixed query_goods(string p_name,string p_para)
{
mapping goods=
([
"food":(["name":"��ʳ","price":10,"quantity":10000]),
"stuff":(["name":"����","price":200,"quantity":100]),
"horse":(["name":"ս��","price":10000,"quantity":200]),
"bow":(["name":"����","price":10000,"quantity":200]),
"tie jia":(["name":"����","price":10000,"quantity":200]),
"water suit":(["name":"ˮ��","price":10000,"quantity":200]),
"dagger":(["name":"����","price":10000,"quantity":200]),
"chang qiang":(["name":"��ǹ","price":25000,"quantity":100]),
"blade":(["name":"��","price":25000,"quantity":100]),
"teng pai":(["name":"����","price":25000,"quantity":100]),
"chang qiang":(["name":"��ǹ","price":25000,"quantity":100]),
"saddle":(["name":"��","price":25000,"quantity":100]),
"zhong jia":(["name":"�ؼ�","price":25000,"quantity":100]),
"gong ma":(["name":"����","price":25000,"quantity":100]),
"hard bow":(["name":"ǿ��","price":25000,"quantity":100]),
"pi jia":(["name":"Ƥ��","price":25000,"quantity":100]),
"zhan chuan":(["name":"ս��","price":25000,"quantity":100]),
"goulian qiang":(["name":"����ǹ","price":200000,"quantity":20]),
"teng jia":(["name":"�ټ�","price":200000,"quantity":20]),
"hongyin qiang":(["name":"��ӧǹ","price":200000,"quantity":20]),
"lianhuan jia":(["name":"������","price":200000,"quantity":20]),
"heavy nu":(["name":"����","price":200000,"quantity":20]),
"toushi che":(["name":"Ͷʯ��","price":200000,"quantity":20]),
"lian nu":(["name":"����","price":200000,"quantity":20]),
"lou chuan":(["name":"¥��","price":200000,"quantity":20]),
"mengchong jian":(["name":"�ɳ形","price":200000,"quantity":20]),
"yu dai":(["name":"���","price":200000,"quantity":20]),
"yin shou":(["name":"ӡ�","price":25000,"quantity":100]),
]);
   switch(p_name)
   {
        case "":
           return goods;
        case "list":
           return keys(goods);
   }
   if(!goods[p_name]) return 0;
   switch(p_para)
   {
       case "":
         return goods[p_name];
       default:
         return goods[p_name][p_para];
   }
}
mixed init_good()
{
   string* lis;
   mapping ret=([]);
   int i,sum,item,j;
   lis=COUNTRY_D->list_countries();
   sum=bmin(sizeof(lis),7);
   for(i=0;i<sum;++i)
   {
      string p_country;
      string *goods=query_goods("list","");
      mapping m_tmp=([]);
      p_country=lis[random(sizeof(lis))];
      lis-=({p_country});
      ret[p_country]=([]);
      item=random(5)+1;
      for(j=0;j<item;++j)
      {
         string my_item;
         my_item=goods[random(sizeof(goods))];
         goods-=({my_item});
         m_tmp[my_item]=([]);
         m_tmp[my_item]["name"]=query_goods(my_item,"name");
m_tmp[my_item]["price"]=query_goods(my_item,"price")*(random(10)+10)/20;
m_tmp[my_item]["quantity"]=query_goods(my_item,"quantity")*(random(8)+2)/3;
      }
      ret[p_country]=m_tmp;
   }
   return ret;
}
