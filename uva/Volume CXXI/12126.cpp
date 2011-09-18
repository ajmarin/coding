#include <algorithm>
#include <cassert>
#include <cstdio>
using namespace std;
#define LEN(x)	(10*x+2)
#define WID(x)	(44*x+4)
long long L, W, area;
void test(long long a, long long b){
	a = LEN(a), b = WID(b);
	if(a * b < area){
		L = a;
		W = b;
		area = a * b;
	} else if(a * b == area && abs(a - b) < abs(L - W)){
		L = a;
		W = b;
	}
}
int main(void){
	int T; scanf("%d", &T);
	while(T--){
		long long stacks;
		scanf("%lld", &stacks);
		stacks = (stacks + 4) / 5;
		L = W = -1;
		area = 1LL << 60;
		for(long long i = 1; i * i <= stacks; ++i){
			long long tL = (stacks + i - 1)/ i, tW = i;
			test(tL, tW);
			test(tW, tL);
		}
		if(L < W) swap(L, W);
		printf("%lld X %lld = %lld\n", L, W, L * W);
	}
	return 0;
}

