#include <algorithm>
#include <cstdio>
using namespace std;

const int NN = 10048;
int b[NN], s[NN];

int main(void){
	for(int B, S, cnum = 0; scanf("%d %d", &B, &S) == 2 && B; ){
		for(int i = 0; i < B; ++i) scanf("%d", b + i);
		for(int i = 0; i < S; ++i) scanf("%d", s + i);
		sort(b, b + B);
		if(B <= S) printf("Case %d: 0\n", ++cnum);
		else printf("Case %d: %d %d\n", ++cnum, B - S, b[0]);
	}
	return 0;
}

