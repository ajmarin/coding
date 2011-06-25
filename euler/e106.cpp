#include <cstdio>
#include <ctime>

const int N = 12;

bool test(int mask1, int mask2, int pop){
	int v1 = 0, v2 = 0, bal = 0;
	bool r = false;
	for(int i = 0; i < 13; ++i){
		if((1 << i) & mask1){
			if(!v1) v1 = 1, v2 = -1;
			bal += v1;
			r |= bal < 0;
		}
		if((1 << i) & mask2){
			if(!v2) v1 = -1, v2 = 1;
			bal += v2;
			r |= bal < 0;
		}
	}
	return r;
}

int popcnt(int x){
	for(int r = 0; ; x >>= 1){
		if(!x) return r;
		r += x & 1;
	}
}

int main(void){
	clock_t begin = clock();
	int ans = 0, cnt = 0;
	int LIM = 1 << N;
	for(int i = 2; 2*i <= N; ++i){
		for(int m1 = 0; m1 < LIM; ++m1){
			if(popcnt(m1) == i)
				for(int m2 = 0; m2 < LIM; ++m2){
					if(m1 & m2 || m2 < m1) continue;
					if(popcnt(m2) == i){
						ans += test(m1, m2, i);
						++cnt;
					}
				}
		}
	}
	printf("Answer: %d\n", ans);
	printf("Time spent: %.3lfs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
	return 0;
}

