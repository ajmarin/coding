#include <cstdio>

int cnt[32], v[32];
int main(void){
	int t; scanf("%d", &t);
	for(int n; t-- && scanf("%d", &n) == 1 && n; ){
		int maj = 0, lim = 1 << n;
		for(int i = 0; i < n; ++i){
			scanf("%d", v + i);
			maj += v[i];
			cnt[i] = 0;
		}
		maj = (maj + 1) >> 1;
		for(int i = 0, j, sum; i < lim; ++i){
			for(j = sum = 0; j < n; ++j) if((1 << j) & i) sum += v[j];
			if(sum >= maj) continue;
			for(j = 0; j < n; ++j) 
				if(!((1 << j) & i) && sum+v[j] >= maj) ++cnt[j];
		}
		for(int i = 0; i < n; ++i)
			printf("party %d has power index %d\n", i+1, cnt[i]);
		puts("");
	}
	return 0;
}

