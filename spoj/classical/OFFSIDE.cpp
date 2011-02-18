#include <cstdio>

int main(void){
	for(int a, d; scanf("%d %d", &a, &d) == 2 && (a || d); ){
		int atk, m, n, o;
		atk = m = n = 1 << 15;
		for(int i = 0; i < a; ++i){
			scanf("%d", &o);
			if(o < atk) atk = o;
		}
		for(int i = 0; i < d; ++i){
			scanf("%d", &o);
			if(o < m) n = m, m = o;
			else if(o < n) n = o;
		}
		puts(atk < n ? "Y" : "N");
	}
	return 0;
}

