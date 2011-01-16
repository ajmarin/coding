#include<cstdio>
char num[1005];
unsigned short mod11,i;
int main(void){
	while(scanf("%s\n",&num)!=EOF){
		if(num[0] == '0' && !num[1]) return 0;
		for(mod11 = i = 0; num[i]; i++) mod11 = (mod11*10+num[i]-'0')%11;
		if(mod11) printf("%s is not a multiple of 11.\n");
		else printf("%s is a multiple of 11.\n");
	}
}
