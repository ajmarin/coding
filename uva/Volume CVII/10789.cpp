/////////////////////////////////
// 10789 - Prime Frequency
/////////////////////////////////
#include<cstdio>
#include<cstring>
bool sieve[2005];
unsigned int cnum,i,j,tnum;
unsigned short int oc[128];
char ans[100], line[2005],tail;
int main(void){
	memset(sieve,1,sizeof(sieve));
	sieve[0] = sieve[1] = 0;
	for(i = 4; i < 2005; i+=2) sieve[i] = 0;
	for(i = 3; i < 45; i+=2)
		if(sieve[i]) for(j=i*i;j<2005;j+=i) sieve[j] = 0;
	scanf("%u\n",&cnum);
	while(cnum--){
		tnum++; tail = 0; gets(line);
		memset(oc,0,sizeof(oc));
		for(i = 0; line[i]; i++)
			oc[line[i]]++;
		for(i = 48; i < 123; i++)
			if(sieve[oc[i]]) ans[tail++] = i;
		ans[tail] = 0;
		if(tail) printf("Case %u: %s\n",tnum,ans);
		else printf("Case %u: empty\n",tnum);		
	}
	return 0;
}
