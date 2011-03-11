#include <algorithm>
#include <cstdio>
const int N = 500530;
int pwr[N], pl[1024], pls = 0;
bool can[1024], r[N];
int list[N], ls, seq[N], ss;
int search(int v){
	int l = 0, m, r = pls;
	while(l < r){
		m  = (l + r) >> 1;
		if(pl[m] <= v) l = m + 1;
		else r = m;
	}
	return l;
}
int main(void){
	for(int i = 0; i < N; ++i) pwr[i] = r[i] = 0;
	for(int i = 2; i < 1000; ++i)
		for(int j = i * i; j < N; j *= i) pwr[j] = 1, pl[pls++] = j;
	std::sort(pl, pl + pls);
	for(int a, b, i, j, k, t; scanf("%d %d", &a, &b) == 2; ){
		ls = ss = 0;
		for(i = a; i <= b; ++i) can[i] = 1;
		for(i = a; i <= b; ++i){
			if(pwr[i] || !can[i]) continue;
			for(j = 0, k = ls; j < k; ++j)
				if(!r[(t = i + list[j])]) r[t] = 1, list[ls++] = t;
			if(!r[i]) r[i] = 1, list[ls++] = i;
			seq[ss++] = i;
			for(j = k; j < ls; ++j){
				int x = list[j];
				for(k = search(x + i); pl[k] - x <= b; ++k) can[pl[k] - x] = 0;
			}
		}
		for(i = 0; i < ss; ++i) printf("%d%c", seq[i], i == ss-1 ? '\n' : ' ');
		while(ls--) r[list[ls]] = 0;
	}
	return 0;
}

