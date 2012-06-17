#include <cstdio>
#include <cstdlib>
#include <ctime>

#define FOR(i,n) for(int i = 0; i < n; ++i)
int x[128], y[128];
int main(void){
	srand(time(NULL));
	for(int A, B, n; scanf("%d", &n) == 1 &&  n; ){
		FOR(i, n<<1) scanf("%d %d", x + i, y + i);
		for(int a = -1, b = 0, val; a != b || a != n; ){
			a = b = 0;
			A = -500 + (rand() % 1001);
			B = -500 + (rand() % 1001);
			FOR(i, n<<1){
				val = A * x[i] + B * y[i];
				a += val > 0;
				b += val < 0;
				if(!val) break;
			}
		}
		printf("%d %d\n", A, B);
	}
	return 0;
}

