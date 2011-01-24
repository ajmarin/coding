#include <cmath>
#include <cstdio>
#include <ctime>

bool seen[1024];
int s[7], found = 0;
int sum(int mask, int &ones){
	int r = 0;
	for(int i = 0; (1 << i) <= mask; ++i)
		if(mask & (1 << i)){
			++ones;
			r += s[i];
		}
	return r;
}
void bt(int k, int low, int high){
	if(k == 7){
		int L = 1 << 7;	
		bool valid = true;
		for(int m1 = 1; valid && m1 < L; ++m1){
			int o1 = 0, s1 = sum(m1, o1);
			for(int m2 = m1 + 1; m2 < L; ++m2){
				if(m1 & m2) continue;
				int o2 = 0, s2 = sum(m2, o2);
				if(s1 == s2 || (o1 > o2 && s1 < s2) || (o2 > o1 && s2 < s1)){
					valid = false;
					break;
				}
			}
		}
		if(valid) {
			++found;
			long long r = 0; int kk = 0;
			for(int i = 0; i < 7; ++i) r = r * 100 + s[i];
			printf("%lld -> %d\n", r, sum(L - 1, kk));
		}
		return;
	}
	for(int x = low; x < high; ++x){
		if(seen[x]) continue;
		bool valid = !seen[x];
		for(int i = 0; valid && i < k; ++i)
			valid &= !seen[s[i] + x];
		if(valid){
			for(int i = 0; i < k; ++i) seen[s[i] + x] = 1;
			seen[x] = 1;
			s[k] = x;
			bt(k + 1, x + 1, high + 1);
			seen[x] = 0;
			for(int i = 0; i < k; ++i) seen[s[i] + x] = 0;
		}
	}
}
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 0; i < 1024; ++i) seen[i] = 0;
	for(int a = 12; a < 30; ++a){
		if(found >= 10) break;
		for(int b = max(a + 1, 19); b < 40; ++b){
			int cap = a + b;
			seen[a] = seen[b] = seen[a + b] = 1;
			s[0] = a; s[1] = b;
			bt(2, b + 1, cap - 4);
			seen[a] = seen[b] = seen[a + b] = 0;
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
