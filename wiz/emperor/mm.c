
#define FLUBS ({ "�h", "��", "�", "��", "��", "�O",\
"��", "�", "��", "��", "��", "�`",\
"�", "��", "��", "�H", "��", "��", "��",\
"��", "��", "�", "��", "��","��","��","��","��","��","��","��","��","��",\
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
                                                str[i..(i+1)] = "��";//FLUBS[random(fs)];
                                                j=0;
                                        }
                                        else j++;
                                }
                                i++;
                        }
                        else if (random(100) >= prof){
                                if(j == xishu) {
                                        str[i]='.';//33+random(94);//33----126֮���ASCII��Ϊ�ɼ��ַ���
                                        j=0;
                                }
                                else j++;
                        }
                }
                return str;
        }
}

