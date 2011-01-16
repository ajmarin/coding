/////////////////////////////////
// 10070 - Leap Year or Not Leap Year and ...
/////////////////////////////////
#include <cstdio>
#include <cstring>
char a[10000000];
const char *leap = "This is leap year.";
const char *hulu = "This is huluculu festival year.";
const char *bulu = "This is bulukulu festival year.";
const char *ordi = "This is an ordinary year.";
unsigned short int mod5,mod4,mod100,mod400,mod15,mod55,lp,ord,f=1;
unsigned int mod3;
unsigned int i,len;
int main(void){
	gets(a);
	while (1){		
		mod3=mod4=mod5=mod100=mod400=mod55=0;
		ord=1;lp=0;
		len = strlen(a);
		mod5 = !(a[len-1]-'0'==0 || a[len-1]-'0'==5);
		if((a[len-1]-'0')&1) {			
			for (i=0;a[i];i++) mod3+=a[i]-'0';
			mod4=mod100=mod400=mod55=1;
		}
		else {
			for (i=0;a[i];i++){
				mod4=(mod4*10+a[i]-'0')%4;
				mod100=(mod100*10+a[i]-'0')%100;
				mod400=(mod400*10+a[i]-'0')%400;
				mod3+=a[i]-'0';
				mod55=(mod55*10+a[i]-'0')%55;
			}
		}
		mod3%=3;
		if ((!mod4 && mod100) || !mod400){
			ord=0; lp = 1;
			puts(leap);			
		}
		if (!mod5 && !mod3){
			ord=0;
			puts(hulu);
		}
		if(lp && !mod55) puts(bulu);
		if (ord)	puts(ordi);
		if(gets(a)) putchar('\n');
		else break;
	}
	return 0;
}

