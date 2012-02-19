#include <cstdio>

int md[16] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1, -1, -1};

inline int ml(int m, int y){ return md[m] + (m == 2 && (y % 100 || !(y % 400)) && !(y % 4)); }
inline int min(int a, int b){ return a < b ? a : b; }
int main(void){
	for(int add, d, m, y; scanf("%d %d %d %d", &add, &d, &m, &y) == 4 && d; ){
		int to_add = min(add, md[m] - d + 1 + (m == 2 && y % 400 != 0 && y % 4 == 0));
		d += to_add;
		add -= to_add;
		if(d > ml(m, y)) ++m, d = 1;
		if(m > 12) m = 1, ++y;
		while(add > 146097){ y += 400; add -= 146097; }
		while(add > 365){ add -= 365 + ((y % 100 || !(y % 400)) && !(y % 4)); ++y; }
		while(add--){
			if(++d > ml(m, y)) d = 1, ++m;
			if(m > 12) m = 1, ++y;
		}
		printf("%d %d %d\n", d, m, y);
	}
	return 0;
}

