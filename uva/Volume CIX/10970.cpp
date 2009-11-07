/////////////////////////////////
// 10970 - Big Chocolate
/////////////////////////////////
#include<cstdio>
#include<cctype>
int main(void){
	register unsigned short int a,b,i;
	register char line[100];
	while(gets(line)){
		a = b = i = 0;
		for(i = 0; !isspace(line[i]); i++) a *= 10, a += line[i]-'0';
		while(line[++i]) b *= 10, b+=line[i]-'0';
		printf("%u\n",a*b-1);
	}
	return 0;
}
