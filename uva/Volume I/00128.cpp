/////////////////////////////////
// 00128 - Software CRC
/////////////////////////////////
#include<cstdio>
#define g 34943
char line[1050];
unsigned int crc,i,val,show;
int main(void){
	while(gets(line)){
		if(line[0] == '#') return 0;
		val = i = 0;
		while(line[i]) val = ((val<<8) + line[i++])%g;
		val = (val<<16)%g;
		crc = (val ? g-val: 0);
		printf("%02X %02X\n", crc>>8, crc&255);
	}
}