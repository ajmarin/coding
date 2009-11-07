/////////////////////////////////
// 10424 - Love Calculator
/////////////////////////////////
#include<cstdio>
#include<cstring>
char first[26],second[26];
unsigned short int a,b,suma,sumb;
char value[127],i;
int main(void){
	memset(value,0,sizeof(value));
	for(i = 'a'; i < 'z'+1; i++) value[i] = value[i-32] = i-'a'+1;
	while(gets(first)){
		gets(second);
		for(a = i = 0; first[i]; i++) a+=value[first[i]];
		for(b = i = 0; second[i]; i++) b+=value[second[i]];
		while(a>9){
			suma = 0;
			while(a){suma += a%10;a/=10;}
			a = suma;
		}
		while(b>9){
			sumb = 0;
			while(b){sumb += b%10;b/=10;}
			b = sumb;
		}
		if(a>b) printf("%.2lf %%\n",b/(a*1.00)*100);
		else printf("%.2lf %%\n",a/(b*1.00)*100);
	}
	return 0;
}