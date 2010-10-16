#include <cstdio>

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FORD(a,b,c)	for(int a = b; a > c; --a)
#define NN 32
char l[NN][NN];
int c[NN][NN], m[NN][NN], r[NN][NN];
int max(int x, int y){ return x > y ? x : y; }
int main(void){
	int t; scanf("%d", &t);
	FOR(i, NN) FOR(j, NN) c[i][j] = m[i][j] = r[i][j] = 0;
	while(t--){
		int maxsum = 0, n = 25; char *p;
		FOR(i, n){
			scanf("%s", l[i + 1] + 1);
			int j;
			for(j = 0, p = l[i + 1] + 1; *p; p++, ++j)
				c[j + 1][i + 1] = r[i + 1][j + 1] = m[i + 1][j + 1] = *p - '0';
			n = p - l[i + 1] - 1;
		}
		++n;
		FORI(i, 1, n){
			FORI(j, 1, n){
				m[i][j] += m[i - 1][j - 1] + r[i][j - 1] + c[j][i - 1];
				r[i][j] += r[i][j - 1];
				c[j][i] += c[j][i - 1];
			}
		}
		FORI(rt, 1, n) FORI(rb, rt, n) FORI(cl, 1, n) FORI(cr, cl, n){
			int sum = m[rt - 1][cl - 1] + m[rb][cr] - m[rt - 1][cr] - m[rb][cl - 1];
			if(sum == (rb - rt + 1) * (cr - cl + 1)) maxsum = max(sum, maxsum);
		}
		printf("%d\n", maxsum);
		if(t) putc(10, stdout);
	}
	return 0;
}

