/////////////////////////////////
// 10878 - Decode the tape
/////////////////////////////////
#include<cstdio>
char i,line[12],val;
char w[] = {64,32,16,8,4,2,1};
int main(void){
	gets(line);
	while(gets(line) && line[2] != '_'){
		val = 0;
		for(i = 2; i < 6; i++)
			if(line[i] == 'o') val += w[i-2];
		for(i = 7; i < 10; i++)
			if(line[i] == 'o') val += w[i-3];
		putchar(val);
	}
	return 0;
}
