#include <cstdio>

bool leap(int x){ return x % 400 == 0 || ((x & 3) && !(x % 100)) || (!(x & 3) && x % 100); }
int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(void){
	int c, d, m, y;
	int nc, nd, nm, ny;
	for(int n; scanf("%d", &n) && n; ){
		int count = 0, sum = 0;
		nc = nd = nm = ny = -1;
		for(int i = 0; i < n; ++i){
			scanf("%d %d %d %d", &d, &m, &y, &c);
			if(d == nd && m == nm && y == ny){ ++count; sum += c - nc; }
			nc = c; nd = d + 1; nm = m; ny = y;
			if(nd > days[m] + (m == 2 && leap(y))){
				nd = 1;
				if(++nm > 12) nm = 1, ++ny;
			}
		}
		printf("%d %d\n", count, sum);
	}
	return 0;
}

