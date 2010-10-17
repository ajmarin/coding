#include <algorithm>
#include <cstdio>
using namespace std;
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b)	FORI(a,0,b)
char m[128];
int main(void){
	int f, i, inv, t, z;
	long long v;
	char n[16], nb[64];
	FORI(i, '0', '9' + 1) m[i] = i - '0', m[i - '0'] = i;
	FORI(i, 'A', 'F' + 1) m[i] = i + 10 - 'A', m[i + 10 - 'A'] = i;
	while(scanf("%d %d %s", &f, &t, n) == 3){
		z = 1; inv = v = 0;
		for(char *p = n; *p; ++p){
			int x = m[*p];
			if(x >= f){ inv = 1; break; }
			v = v * f + x;
		}
		if(inv) printf("%s is an illegal base %d number\n", n, f);
		else {
			for(i = 0; v; ++i, v /= t) nb[i] = m[v % t];
			if(!i) nb[i++] = '0';
			nb[i] = 0;
			reverse(nb, nb + i);
			printf("%s base %d = %s base %d\n", n, f, nb, t);
		}
	}
	return 0;
}

