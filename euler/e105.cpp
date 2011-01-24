#include <cmath>
#include <cstdio>
#include <ctime>

int v[16];
int sum[4096], ones[4096];
void s(int mask){
	int r = 0, o = 0;
	for(int i = 0; (1 << i) <= mask; ++i)
		if(mask & (1 << i)){
			++o;
			r += v[i];
		}
	ones[mask] = o;
	sum[mask] = r;
}
int main(void){
	clock_t ini = clock();
	int ans = 0; char c;	
	freopen("sets.txt", "r", stdin);
	while(scanf("%d%c", &v[0], &c) == 2){
		int n = 1;
		while(scanf("%d%c", &v[n++], &c) == 2 && c != 10);
		int L = 1 << n;
		for(int i = 1; i < L; ++i) s(i);	
		bool valid = true;
		for(int m1 = 1; valid && m1 < L; ++m1){
			int o1 = ones[m1], s1 = sum[m1];
			for(int m2 = m1 + 1; m2 < L; ++m2){
				if(m1 & m2) continue;
				int o2 = ones[m2], s2 = sum[m2];
				if(s1 == s2 || (o1 > o2 && s1 < s2) || (o2 > o1 && s2 < s1)){
					valid = false;
					break;
				}
			}
		}
		if(valid) ans += sum[L - 1];
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
