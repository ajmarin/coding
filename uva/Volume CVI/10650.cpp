#include <cstdio>

const int MAXN = 1<<16, ROOT = 1<<8;
bool prime[MAXN];
int p[MAXN/5], pc = 0;
int main(void){
//	setvbuf(stdout, NULL, _IONBF, NULL);
	p[pc++] = 2;
	for(int i = 0; i < MAXN; ++i) prime[i] = i & 1;
	for(int i = 3; i < ROOT; i += 2)
		if(prime[i])
			for(int j = i*i, k = 2*i; j < MAXN; j += k) prime[j] = false;
	for(int i = 3; i < MAXN; i += 2) if(prime[i]) p[pc++] = i;
	//for(int i = 0; i < pc; ++i) printf("%d\n", p[i]);
	for(int x, y; scanf("%d %d", &x, &y) == 2 && (x || y); ){
		if(x > y) x ^= y ^= x ^= y;
		for(int i = 0, j; p[i] <= y && i < pc - 1; ){
			int d = p[i+1] - p[i];
			for(j = i+1; j < pc && p[j] - p[j - 1] == d; ++j);
			if(j - i >= 3 && p[i] >= x && p[j-1] <= y)
				for(int k = i; k < j; ++k)
					printf("%d%c", p[k], k == j - 1 ? '\n' : ' ');
//			printf("Range (%d, %d)\n", p[i], p[j - 1]);
			i = j - 1;
		}
	}
	return 0;
}

