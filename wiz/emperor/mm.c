
#define FLUBS ({ "Êh", "ìÖ", "ó§", "ïÙ", "—…", "‹O",\
"êý", "ê³", "÷…", "×", "ÝÁ", "ê`",\
"å¸", "óè", "õÕ", "íH", "¤Ã", "÷Š", "‡—",\
"æÀ", "Ùè", "å²", "¤½", "¤Æ","¥ñ","¤å","¥ö","¥½","¥Æ","¥½","¥Ì","¥Æ","¥Á",\
})

varargs string ConvertString(string str, int prof, int xishu) {
    if( prof >= 100 ) return str;
    else {
                int fs, i, maxi, j;
                fs = sizeof(FLUBS);
                j = 0;
                for(i=0, maxi = sizeof(str); i < maxi; i++){
                        if( str[i]>128 && str[i]<255 ){
                                if (random(100) >= prof){
                                        if(j == xishu) {
                                                str[i..(i+1)] = "¡õ";//FLUBS[random(fs)];
                                                j=0;
                                        }
                                        else j++;
                                }
                                i++;
                        }
                        else if (random(100) >= prof){
                                if(j == xishu) {
                                        str[i]='.';//33+random(94);//33----126Ö®¼äµÄASCIIÂëÎª¿É¼û×Ö·û¡£
                                        j=0;
                                }
                                else j++;
                        }
                }
                return str;
        }
}

