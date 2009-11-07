/////////////////////////////////
// 10473 - Simple Base Conversion
/////////////////////////////////
#include<cstdio>
char line[30];
unsigned int n;
int main(void){
	while(fgets(line,30,stdin)){
		if(line[0]=='-') return 0;
		if(line[1]!='x') sscanf(line,"%u",&n), printf("0x%X\n",n);
		else sscanf(line+2,"%X",&n), printf("%u\n",n);
	}
}
