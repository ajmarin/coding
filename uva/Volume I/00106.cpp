/////////////////////////////////
// 00106 - Fermat vs. Pythagoras
/////////////////////////////////
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define LIM 1000050
using namespace std;
typedef unsigned int UI;
struct triple{
	UI a,b,c;
	triple(){}
	triple(UI x, UI y, UI z): a(x),b(y),c(z){}
};
UI A,B,C,didnt,first[LIM],i,kA,kB,kC,m,n,sqm,sqn;
vector<triple> prim;
vector<triple>::iterator it;
UI gcd(UI a, UI b){
	if(a) return gcd(b%a,a); 
	else return b;
}
bool ord(triple a, triple b){
	return (a.c < b.c);
}
void show(triple x){
	printf("{ %u, %u, %u }\n",x.a,x.b,x.c);
}
int main(void){
	triple last;
	memset(first,1000001,sizeof(first));
	for(m = 1; m < 710; m++){
		sqm = m*m;
		for(n = m+1; sqm + (sqn = n*n) < LIM; n+=2){
			if(gcd(m,n)==1){
				prim.push_back(triple(2*m*n,sqn-sqm,sqm+sqn));
				last = prim.back();
				A = last.a; B = last.b; C = last.c;
				for(i = 1; i*C < 1000001; i++){
					kA = i*A; kB = i*B; kC = i*C;
					if(first[kA] > kC) first[kA] = kC;
					if(first[kB] > kC) first[kB] = kC;
					first[kC] = kC;
				}
			}
		}
	}
	std::sort(prim.begin(),prim.end(),ord);
	while(scanf("%u",&n) != EOF){
		didnt = n;
		for(n = n+1, it = prim.begin(); (*it).c < n; it++);
		for(i = 1; i < n; i++) if(first[i] < n) didnt--;
		printf("%u %u\n",it-prim.begin(),didnt);
	}
	return 0;
}
