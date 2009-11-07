#include <cstdio>

#define MAXN 44722
#define SQMN 213

bool p[MAXN];
int ds[10000], pp[10000], ps = 1;

int dsum(int k){
	int s = 0;
	while(k) s += k % 10, k /= 10;
	return s;
}

int main(void){
	ds[0] = pp[0] = 2;
	for(int i = 1; i < MAXN; i += 2) p[i] = 1;
	for(int i = 3; i < SQMN; i += 2)
		if(p[i]){
			ds[ps] = dsum(i);
			pp[ps++] = i;
			for(int j = i * i, k = i<<1; j < MAXN; j += k)
				p[j] = 0;
		}
	for(int i = SQMN; i < MAXN; i += 2)
		if(p[i]){
			ds[ps] = dsum(i);
			pp[ps++] = i;
		}
	int N, T;
	scanf("%d",&T);
	while(T--){
		scanf("%d", &N);
		int a, b, f, i, x, y;
		for(x = N + 1; ; x++){
			a = dsum(x); y = x; b = f = 0;
			for(i = 0; i < ps; i++){
				if(!(y % pp[i])){
					do {
						f++;
						b += ds[i];
						y /= pp[i];
					} while(!(y % pp[i]));
					if(b > a || (y == 1)) break;
				}
			}
			if((b > a) || (f == 0) || (f < 2 && y < MAXN)) continue;
			if(y != 1) b += dsum(y);
			if(b == a) break;
		}
		printf("%d\n", x);
	}
	return 0;
}

