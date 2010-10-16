#include <cstdio>

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FORD(a,b,c)	for(int a = b; a > c; --a)
#define NN			528	
#define OPP(x)		(((x >> 1) << 1) + !(x & 1))
int c[NN][6];
int LIS[NN][6], p[NN][6], f[NN][6];

const char *face[6] = {"front", "back", "left",
					   "right", "top", "bottom"};
void batraque(int i, int j){
	if(i == -1) return;
	batraque(p[i][j], f[i][j]);
	printf("%d %s\n", i + 1, face[j]);
}
int main(void){
	for(int cn = 0, n; scanf("%d", &n) == 1 && n; ){
		FOR(i, n) FOR(j, 6) scanf("%d",&c[i][j]);
		FOR(i, n) FOR(o1, 6){
			LIS[i][o1] = 0;
			FOR(j, i) FOR(o2, 6)
				if(c[i][o1] == c[j][o2]){
					int k = OPP(o2);
					if(LIS[j][k] > LIS[i][o1]){
						LIS[i][o1] = LIS[j][k];
						p[i][o1] = j;
						f[i][o1] = k;
					}
				}
			if(!LIS[i][o1]) p[i][o1] = f[i][o1] = -1;
			++LIS[i][o1];
		}
		int idxi = -1, idxj, max = 0;
		FOR(i, n) FOR(j, 6)
			if(LIS[i][j] > max){
				max = LIS[i][j];
				idxi = i;
				idxj = j;
			}
		if(cn) putc(10, stdout);
		printf("Case #%d\n%d\n", ++cn, max);
		batraque(idxi, idxj);
	}
	return 0;
}

