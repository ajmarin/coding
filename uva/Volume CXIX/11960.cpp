#include <cstdio>

const int MAXP = 1024, N = 1048576;
int ans[N], div[N];
int pl[N / 10], plc = 1;
bool prime[1024];

void calculate_divs(int idx, int num, int divs){
	div[num] = divs;
	for(int i = idx; i < plc; ++i)
		for(int mul = pl[i], j = 1; mul <= N / num; mul *= pl[i], ++j)
			calculate_divs(i + 1, num * mul, divs * (1 + j));
}
		
int main(void){
	pl[0] = 2;
	prime[0] = prime[1] = false;
	prime[2] = true;
	for(int i = 3; i < MAXP; ++i) prime[i] = i & 1;
	for(int i = 3; i < 32; i += 2) if(prime[i]) 
		for(int j = i * i, k = 2 * i; j < MAXP; j += k) prime[j] = false;
	for(int i = 3; i < MAXP; i += 2) {
		if(prime[i]) pl[plc++] = i;
		div[i] = 2;
	}
	calculate_divs(0, 1, 1);
	int maxd = -1, cans;
	for(int i = 0; i < N; ++i){
		if(div[i] >= maxd){
			maxd = div[i];
			cans = i;
		}
		ans[i] = cans;
	}
	scanf("%*d");
	for(int n; scanf("%d", &n) == 1; ) printf("%d\n", ans[n]);
		
	return 0;
}

