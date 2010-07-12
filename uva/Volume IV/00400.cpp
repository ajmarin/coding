/////////////////////////////////
// 00400 - Unix ls
/////////////////////////////////
#include<algorithm>
#include<cstdio>
#include<cstring>
struct word{
	char w[61];
	unsigned int len;
	bool operator()(word a, word b){
		return (strcmp(a.w,b.w)<0);
	}
}words[100];
const char *dash = "------------------------------------------------------------";
char col[20];
unsigned int c,ccol,columns,i,j,k,max,wnum,wpc;
int main(void){
	while(scanf("%u\n",&wnum)!=EOF){
		max = 0;
		for(i = 0; i < wnum; i++){
			gets(words[i].w),
			words[i].len = strlen(words[i].w);
			if(words[i].len > max) max = words[i].len;
		}
		std::sort(words,words+wnum,word());
		for(columns = 0, c = 60; (max+1)<<1 <= c; columns++)
			col[columns] = max+2,	c -= (max+2);
		col[columns++] = max;
		wpc = wnum/columns;
		if(wpc*columns < wnum) wpc++;
		/* Fills with blanks */
		for(i = 0; i < wnum; i++){
			ccol = i/wpc;
			for(j = words[i].len; j < col[ccol]; j++)
				words[i].w[j] = ' ';
			words[i].w[j] = 0;
		}
		/* show words */
		puts(dash);
		
		for(i = 0; i < wpc; putchar('\n'),i++)
			for(j = 0; j < columns; j++){
				k = i+j*wpc;
				if(k < wnum) printf("%s",words[k].w); else break;
			}
	}
	return 0;
}
