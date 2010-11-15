#include <cstdio>
const int NN = 10048;
int beer[NN], burger[NN];
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	for(int m, n, t; scanf("%d %d %d", &m, &n, &t) == 3; ){
		burger[0] = beer[0] = 0;
		for(int i = 1; i <= t; ++i){
			int opt1, opt2;
			opt1 = opt2 = 1 << 20;
			if(i < m && i < n){
				burger[i] = burger[i - 1];
				beer[i] = beer[i - 1] + 1;
				continue;
			}
			if(i >= m) opt1 = beer[i - m];
			if(i >= n) opt2 = beer[i - n];
			beer[i] = min(opt1, opt2);
			if(opt1 == opt2) burger[i] = max(burger[i - m], burger[i - n]) + 1;
			else if(opt1 < opt2) burger[i] = burger[i - m] + 1;
			else burger[i] = burger[i - n] + 1;
		}
		printf("%d", burger[t]);
		if(beer[t]) printf(" %d\n", beer[t]);
		else putc(10, stdout);
	}
	return 0;
}

