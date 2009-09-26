/////////////////////////////////
// 00621 - Secret Research
/////////////////////////////////
#include<cstdio>
#include<cstring>
char line[1500];
unsigned int cnum,len;
const char *pos = "+",*neg = "-",*fail = "*", *inc = "?";
int main(void){
	scanf("%u\n",&cnum);
	while(cnum--){
		gets(line);
		len = strlen(line);
		if(len < 3) puts(pos);
		else if(line[0] == '9' && line[len-1] == '4') puts(fail);
		else if(line[len-1] == '5' && line[len-2] == '3') puts(neg);
		else puts(inc);
	}
	return 0;
}
	
