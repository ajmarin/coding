#include <cstdio>
#include <cstring>

#define REAL(x) (x < 'A'? x - '0': x - 'A' + 10)
#define MAX(a,b) ((a)>(b)? (a) : (b))

char d1[32], d2[32], o1[32], o2[32];

int b10(char *k, int l, int base){
	int m = 1, r = 0;
	while(l--) r += k[l] * m, m *= base;
	return r;
}

int main(void){
	int b1, b2, l1, l2;
	bool s;

	while(scanf("%s %s", o1, o2) == 2){
		register char *p;
		strcpy(d1, o1);
		strcpy(d2, o2);
		b1 = b2 = 1;
		for(p = d1; *p; ++p) *p = REAL(*p), b1 = MAX(b1, *p);
		l1 = p - d1; ++b1;
		for(p = d2; *p; ++p) *p = REAL(*p), b2 = MAX(b2, *p);
		l2 = p - d2; ++b2;
		int i, j;
		for(i = b1, s = 0; !s && i < 37; ++i){
			int x = b10(d1, l1, i);
			for(j = b2; !s && j < 37; ++j){
				int y = b10(d2, l2, j);
				s = x == y;
			}
		}
		if(s) printf("%s (base %d) = %s (base %d)\n", o1, --i, o2, --j);
		else printf("%s is not equal to %s in any base 2..36\n", o1, o2);
	}
	return 0;
}

