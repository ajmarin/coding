#include <cstdio>
const int N = 10000;
int h[N], w[N];
int abs(int a){ return a < 0 ? -a : a; }
int main(void){	
	for(int cnum = 1, n; scanf("%d", &n) == 1; ++cnum){
		int a, b, d1, d2, min = 100000, no = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &a, &b);
			d1 = abs(a - b);
			if(a == b) no = 1;
			if(d1 < min) min = d1;
			for(int j = 0; j < i; ++j){
				d1 = abs(a - h[j]);
				d2 = abs(b - w[j]);
				if(d1 < min) min = d1;
				if(d2 < min) min = d2;
			}
			w[i] = a;
			h[i] = b;
		}
		if(!no) min += min == 0;
		printf("Case %d : %d\n", cnum, (min + 1) >> 1);
	}
	return 0;
}
