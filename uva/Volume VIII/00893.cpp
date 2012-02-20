#include <cstdio>

int md[16] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1, -1, -1};

inline int ml(int m, int y){ return md[m] + (m == 2 && (y % 100 || !(y % 400)) && !(y % 4)); }
int main(void){
	for(int add, d, m, y; scanf("%d %d %d %d", &add, &d, &m, &y) == 4 && d; ){
		int y400 = 400 * 365 + 97;
		while(add >= y400){ y += 400; add -= y400; }
		while(add--){
			if(++d > ml(m, y)) d = 1, ++m;
			if(m > 12) m = 1, ++y;
		}
		printf("%d %d %d\n", d, m, y);
	}
	return 0;
}

