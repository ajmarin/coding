#include <cmath>
#include <cstdio>
typedef long long LL;
bool cando(LL x){
	bool can = true;
	int cnt;
	while(!(x & 1)) x >>= 1;
	for(cnt = 0; !(x % 3); ++cnt, x /= 3);
	can &= !(cnt & 1);
	for(LL i = 6; can; i += 6){
		LL t1 = i - 1, t2 = i + 1;
		for(cnt = 0; !(x % t1); ++cnt, x /= t1);
		can &= (t1 & 3) != 3 || !(cnt & 1);
		for(cnt = 0; !(x % t2); ++cnt, x /= t2);
		can &= (t2 & 3) != 3 || !(cnt & 1);
		if(t2 * t2 > x) break;
	}
	return can &= x == 1 || (x & 3) != 3;
}
int main(void){
	int t; scanf("%d", &t); LL x;
	while(t--){
		scanf("%lld", &x);
		puts(cando(x) ? "Yes" : "No");
	}
	return 0;
}

