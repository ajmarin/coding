/////////////////////////////////
// 10260 - Soundex
/////////////////////////////////
#include<cstdio>
int i,a,prev;
char c[25];
int n[25];
int soundex(int i){
    if(c[i] == 'C'||c[i] ==  'G'|| c[i] =='J'||c[i] == 'K'|| c[i] =='Q'|| c[i] =='S'||c[i] == 'X'||  c[i] == 'Z')
        return 2;
    else if(c[i] == 'B' ||c[i] == 'F'||c[i] == 'P'||c[i] == 'V')
        return 1;
    else if(c[i] == 'D' || c[i] == 'T')
        return 3;
    else if(c[i] == 'M' || c[i] == 'N')
        return 5;
    else if(c[i] == 'L')
        return 4;
    else if(c[i] == 'R')
        return 6;
    return 0;
}
int main(void){
    while(scanf("%s",&c)!=EOF){
        prev = -1;
        for(i = 0; c[i] != '\0';i++){
            a = soundex(i);
            if(a > 0 && a != prev) printf("%d",a);
            prev = a;
        }
        printf("\n");
    }
    return 0;
}
