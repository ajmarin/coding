#include <cstdio>
#define FOR(i,n) for(int i = 1; i <= n; ++i)
template <typename _T> _T GCD(_T a, _T b) { return b ? GCD(b, a %b) : a;	}

int z[64];
bool v[64];

void r(int a, int b, int c, int d){
	int t = z[d];
	z[d] = z[c];
	z[c] = z[b];
	z[b] = z[a];
	z[a] = t;
}

void U(){
	r(1, 3, 9, 7);
	r(2, 6, 8, 4);
	r(34, 48, 12, 39);
	r(35, 47, 11, 38);
	r(36, 46, 10, 37);
}

void F(){
	r(10, 12, 18, 16);
	r(11, 15, 17, 13);
	r(7, 46, 21, 45);
	r(8, 49, 20, 42);
	r(9, 52, 19, 39);
}

void D(){
	r(19, 21, 27, 25);
	r(20, 24, 26, 22);
	r(16, 52, 30, 43);
	r(17, 53, 29, 44);
	r(18, 54, 28, 45);
}

void R(){
	r(46, 48, 54, 52);
	r(47, 51, 53, 49);
	r(9, 36, 27, 18);
	r(6, 33, 24, 15);
	r(3, 30, 21, 12);
}

void L(){
	r(37, 39, 45, 43);
	r(38, 42, 44, 40);
	r(1, 10, 19, 28);
	r(4, 13, 22, 31);
	r(7, 16, 25, 34);
}

void B(){
	r(28, 30, 36, 34);
	r(29, 33, 35, 31);
	r(25, 54, 3, 37);
	r(26, 51, 2, 40);
	r(27, 48, 1, 43);
}

int main(void){
	void (*m[128])();
	m['B'] = B; m['D'] = D; m['F'] = F;
 	m['L'] = L; m['R'] = R; m['U'] = U;
	for(char rot[128]; scanf("%s", rot) == 1; ){
		int ans = 1, c, j;
		FOR(i, 54) z[i] = i, v[i] = false;
		for(int i = 0; rot[i]; ++i) FOR(j, 1 + ((rot[i] & 32) >> 4)) m[rot[i] & ~32]();
		FOR(i, 54){
			if(v[i]) continue;
			for(c = 1, j = z[i]; j != i; v[j] = true, ++c, j = z[j]);
			if(c == 1) continue;
			ans *= c / GCD(ans, c);
		}
		printf("%d\n", ans);
	}
	return 0;
}

