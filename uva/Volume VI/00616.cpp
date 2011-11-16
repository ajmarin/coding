#include <cmath>
#include <cstdio>

int main() {
	for(int i, n, p, z; scanf("%d", &n) == 1 && n >= 0; ){
		for(p = 9; p >= 2; --p){
			z = n;
			for(i = 0; i < p && z % p == 1; ++i)
				z = z - z/p - 1;
			if(i == p && z % p == 0) break;
		}
		printf("%d coconuts, ", n);
		if(p > 1) printf("%d people and 1 monkey\n", p);
		else puts("no solution");
	}
	return 0;
}

