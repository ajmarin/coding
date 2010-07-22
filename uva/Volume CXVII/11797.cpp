#include <cstdio>

const char *s[5] = {"Ja", "Sam", "Sha", "Sid", "Tan"};
char name[12];
int l[5][20], time[5], ls[5], lp[5];
char map[128];
inline int min(int a, int b){ return a < b ? a : b; }
int main(void){
	int c, ct, m, n, next, t;
	map[0] = 0; map['m'] = 1; map['a'] = 2; map['d'] = 3; map['n'] = 4;
	scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		scanf("%d %d %s", &m, &n, name);
		c =  *(map + *(name + 2));
		for(int i = 0; i < 5; ++i){
			scanf("%d", &ls[i]);
			lp[i] = time[i] = 0;
			for(int j = 0; j < ls[i]; ++j){
				scanf("%s", name);
				l[i][j] = *(map + *(name + 2));
			}
		}		
		for(ct = 0; ct < n; ct += m + 2){
			time[c] += min(n - ct, m);
			next = l[c][lp[c]];
			lp[c] = (lp[c] + 1) % ls[c];
			c = next;
		}
		printf("Case %d:\n", cnum);
		for(int i = 0; i < 5; ++i) printf("%s %d\n", s[i], time[i]);
	}
	return 0;
}
