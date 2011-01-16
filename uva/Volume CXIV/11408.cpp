/////////////////////////////////
// 11408 - Count DePrimes
/////////////////////////////////
#include<cstdio>
#define MAX 5000001
int a,b,i,j,tot = 0,answer;
int deprime[MAX];
int totdeprimes[MAX];
int main(void){	
	for(i = 4; i < MAX; i+=2) deprime[i] = 2;
	for(i = 3; i < MAX; i+=2)
		if(!deprime[i])
			for(j = 2*i; j < MAX; j+=i) deprime[j] += i;
	for(i = 2; i < MAX; i++) if(!deprime[deprime[i]]) totdeprimes[i] = ++tot; else totdeprimes[i] = tot;
	scanf("%d",&a);
	while(a){
		scanf("%d",&b);
		answer = totdeprimes[b]-totdeprimes[a];
		if(totdeprimes[a] > totdeprimes[a-1]) answer++;
		printf("%d\n",answer);
		scanf("%d",&a);
	}
}
		
