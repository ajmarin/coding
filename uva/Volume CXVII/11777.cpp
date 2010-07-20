#include <algorithm>
#include <cstdio>
using namespace std;
int main(void){
	int t, t1, t2, f, a, ct1, ct2, ct3;
	scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		scanf("%d %d %d %d %d %d %d", &t1, &t2, &f, &a, &ct1, &ct2, &ct3);
		float n = t1 + t2 + f + a + (ct1 + ct2 + ct3 - min(ct1, min(ct2, ct3)))/2.;
		printf("Case %d: ", cnum);
		if(n >= 90) puts("A");
		else if(n >= 80) puts("B");
		else if(n >= 70) puts("C");
		else if(n >= 60) puts("D");
		else puts("F");
	}
	return 0;
}
