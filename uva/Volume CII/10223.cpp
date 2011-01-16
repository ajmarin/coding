/////////////////////////////////
// 10223 - How many nodes ?
/////////////////////////////////
#include<cstdio>
unsigned int c[] = {1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};
unsigned int n;
char s,u,v;
int main(void){
	while(scanf("%u",&n)!=EOF){
		for(u = 0, v = 19; u < v; ){
			s = (u+v)/2;
			if(c[s]<n) u = s+1; else v = s;
		}
		printf("%d\n",u+1);
	}
	return 0;
}
