#include <cstdio>

int f[16], cnt[16], fc;
int fl[1024], flc;
void build_factors(int cf, int pp){
	if(cf == fc){
		fl[flc++] = pp;
		return;
	}
	for(int i = 0, r = 1; i <= cnt[cf]; r *= f[cf], ++i)
		build_factors(cf + 1, pp * r);
}
void try_factor(int &x, int z){
	if(!(x % z)){
		int c = 0;
		do { x /= z; ++c; } while(!(x % z));
		f[fc] = z;
		cnt[fc++] = c;
	}
}
void factor(int x){
	fc = 0;
	try_factor(x, 2);
	try_factor(x, 3);
	for(int i = 6; ; i += 6){
		int f1 = i - 1, f2 = i + 1;
		if(f1 * f1 > x) break;
		try_factor(x, f1);
		try_factor(x, f2);
	}
	if(x != 1) try_factor(x, x);
}
int main(void){
	for(int n; scanf("%d", &n) && n != -1; ){
		int a, b, i, maxdiff = -1, ta, tb, x, y;
		factor(n << 1);
		flc = 0;
		build_factors(0, 1);
		for(i = 0; i < flc; ++i){
			x = fl[i], y = (n<<1)/x;
			if(y > x && (x + y) & 1){
				ta = (y - x - 1) >> 1;
				tb = (y + x - 1) >> 1;
				if(tb - ta > maxdiff){
					a = ta;
					b = tb;
					maxdiff = b - a;
				}
			}

		}
		printf("%d = %d + ... + %d\n", n, a + 1, b);
	}
	return 0;
}

