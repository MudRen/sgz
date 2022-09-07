// base.c  by fire on Nov 1998
// this is used for ev_mechant.c to inherit
// hold all the base informtion of the good
mixed query_goods(string p_name,string p_para)
{
mapping goods=
([
"food":(["name":"Á¸Ê³","price":10,"quantity":10000]),
"stuff":(["name":"Îï×Ê","price":200,"quantity":100]),
"horse":(["name":"Õ½Âí","price":10000,"quantity":200]),
"bow":(["name":"¹­¼ý","price":10000,"quantity":200]),
"tie jia":(["name":"Ìú¼×","price":10000,"quantity":200]),
"water suit":(["name":"Ë®¿¿","price":10000,"quantity":200]),
"dagger":(["name":"¶ÌÈÐ","price":10000,"quantity":200]),
"chang qiang":(["name":"³¤Ç¹","price":25000,"quantity":100]),
"blade":(["name":"µ¶","price":25000,"quantity":100]),
"teng pai":(["name":"ÌÙÅÆ","price":25000,"quantity":100]),
"chang qiang":(["name":"³¤Ç¹","price":25000,"quantity":100]),
"saddle":(["name":"Âí°°","price":25000,"quantity":100]),
"zhong jia":(["name":"ÖØ¼×","price":25000,"quantity":100]),
"gong ma":(["name":"¹­Âí","price":25000,"quantity":100]),
"hard bow":(["name":"Ç¿åó","price":25000,"quantity":100]),
"pi jia":(["name":"Æ¤¼×","price":25000,"quantity":100]),
"zhan chuan":(["name":"Õ½´¬","price":25000,"quantity":100]),
"goulian qiang":(["name":"¹³Á­Ç¹","price":200000,"quantity":20]),
"teng jia":(["name":"ÌÙ¼×","price":200000,"quantity":20]),
"hongyin qiang":(["name":"ºìÓ§Ç¹","price":200000,"quantity":20]),
"lianhuan jia":(["name":"Á¬»·¼×","price":200000,"quantity":20]),
"heavy nu":(["name":"ÖØåó","price":200000,"quantity":20]),
"toushi che":(["name":"Í¶Ê¯³µ","price":200000,"quantity":20]),
"lian nu":(["name":"Á¬åó","price":200000,"quantity":20]),
"lou chuan":(["name":"Â¥´¬","price":200000,"quantity":20]),
"mengchong jian":(["name":"ÃÉ³å½¢","price":200000,"quantity":20]),
"yu dai":(["name":"Óñ´ø","price":200000,"quantity":20]),
"yin shou":(["name":"Ó¡ç·","price":25000,"quantity":100]),
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
