/////////////////////////////////
// 11452 - Dancing the Cheeky-Cheeky
/////////////////////////////////
#include<cstdio>
#include<cstring>
char steps[2005];
int i,match,len,tlen;
int main(void){
	gets(steps);
	while(gets(steps)){
		match = 0;
		tlen = strlen(steps);
		for(len = tlen/3+1; !match; len++){
			for(match = 1,i = len; i < 2*len && match; i++)				
				if(steps[i] != steps[i-len]) match = 0;			
			if(match) break;
		}			
		for(i = tlen; i < tlen+8; i++) putchar(steps[i%len]);
		printf("...\n");
	}
	return 0;
}