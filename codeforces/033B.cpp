#include <algorithm>
#include <cstdio>
using namespace std;
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b)	FORI(a,0,b)
#define NN 100048
int z[26][26];
char ans[NN], w1[NN], w2[NN];
int main(void){
	int c, cost = 0, l1, l2, minc, t, temp;
	char *p, *q;
	char x[3], y[3];
	scanf("%s %s %d\n", w1, w2, &t);
	for(p = w1; *p; p++); for(q = w2; *q; q++);
	l1 = p - w1; l2 = q - w2;
	if(l1 != l2){ puts("-1"); return 0; }
	FOR(i, 26) FOR(j, 26) z[i][j] = 5000000;
	while(t--){
		scanf("%s %s %d", &x, &y, &c);
		*x -= 'a'; *y -= 'a';
		if(c < z[*x][*y]) z[*x][*y] = c;
	}
	FOR(k, 26) FOR(i, 26) FOR(j, 26) z[i][j] = min(z[i][j], z[i][k] + z[k][j]);
	FOR(i, 26) z[i][i] = 0;
	FOR(i, l1){
		minc = 5000000;
		if(w1[i] == w2[i]){ ans[i] = w1[i]; continue; }
		FOR(j, 26){
			temp = z[w1[i] - 'a'][j] + z[w2[i] - 'a'][j];
			if(temp < minc) minc = temp, ans[i] = j + 'a';
			//	printf("Change %c and %c to %c = %d\n", w1[i], w2[i], j + 'a', temp);
		}
		if(minc == 5000000){ puts("-1"); return 0; }
		cost += minc;
	}
	ans[l1] = 0;
	printf("%d\n%s\n", cost, ans);
	return 0;
}

