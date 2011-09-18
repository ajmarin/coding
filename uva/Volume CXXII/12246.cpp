#include <algorithm>
#include <cstdio>
using namespace std;
int w[100048];
int main(void){
	for(int Q, T; scanf("%d %d", &T, &Q) == 2 && (Q || T); ){
		for(int i = 0; i < T; ++i) scanf("%d", &w[i]), w[i] <<= 1;
		int r = 0x1fffffff;
		if(T > 1) r = abs(w[1] - w[0]);
		for(int i = 2; i < T; ++i) r = __gcd(r, abs(w[i] - w[0]));
		for(int i = 0; i < Q; ++i){
			int a, b, d, j;
			scanf("%d %d", &a, &b);
			if(i) printf(" ");
			d = abs(b - a);
			a += b;
			if(d & 1) printf("N");
			else if(!(d % r)) printf("Y");
			else {
				for(j = 0; j < T; ++j) if(!((w[j] - a) % r)) break;
				if(j != T) printf("Y"); 
				else printf("N");
			}
		}
		putc(10, stdout);
	}
	return 0;
}

