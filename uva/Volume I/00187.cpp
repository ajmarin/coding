/////////////////////////////////
// 00187 - Transaction Processing
/////////////////////////////////
#include<cstdio>
#include<cmath>
unsigned int current,i,j,n,tnum,trans[10];
int val[10],bal;
char acc[1000][35], dummy[35];
const char *ob = "Out of Balance";
int main(void){
	while(scanf("%u",&n) && n) gets(acc[n]);
	gets(dummy);
	scanf("%3u",&tnum);
	current = tnum;
	while(tnum){
		current = tnum; bal = 0;
		for(i = 0; current == tnum; i++){
			scanf("%3u%d",&trans[i],&val[i]);
			bal += val[i];
			scanf("%3u",&tnum);
		}
		if(bal){
			printf("*** Transaction %3u is out of balance ***\n",current);
			for(j = 0; j < i; j++)
				printf("%3u %-33s %7.2f\n"
				,trans[j],acc[trans[j]],val[j]/100.00);
			printf("999 %-33s %7.2f\n",ob,(-bal)/100.00);
			putchar('\n');
		}			
	}
	return 0;
}
