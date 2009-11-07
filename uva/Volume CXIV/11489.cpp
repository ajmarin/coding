/////////////////////////////////
// 11489 - Integer Game
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned short has[3],i,moves,oc[10],sum;
unsigned int cnum,tnum;
char num[1005], winner[] = {'T','S'};
int main(void){
	scanf("%u\n",&cnum);
	while(cnum--){
		gets(num);
		tnum++;
		memset(oc,0,sizeof(oc));
		moves = sum = 0;
		for(i = 0; num[i]; i++) oc[num[i]-'0']++, sum += (num[i]-'0');
		has[0] = oc[3]+oc[6]+oc[9];
		has[1] = oc[1]+oc[4]+oc[7];
		has[2] = oc[2]+oc[5]+oc[8];
		if(has[sum%3]) moves = 1, has[sum%3]--;
		if(moves) moves += has[0];
		if(i - moves == 1) moves++;
		printf("Case %u: %c\n",tnum,winner[moves&1]);
	}
	return 0;
}
	
