#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
int map[128], total[128], wins[128];
char m1[16], m2[16];
bool beat[3][3];

bool beats(char a, char b){ return beat[map[a]][map[b]]; }

int main(void){
	bool first = true;
	map['p'] = 0; map['r'] = 1; map['s'] = 2;
	FOR(i, 3) FOR(j, 3) beat[i][j] = false;
	beat[0][1] = beat[1][2] = beat[2][0] = true;
	for(int p1, p2, n, m; scanf("%d%d", &n, &m) == 2; first = false){
		if(!first) puts("");
		FOR(i, n) wins[i] = total[i] = 0;
		m = m * n * (n - 1) / 2;
		FOR(i, m){
			scanf("%d %s %d %s", &p1, m1, &p2, m2);
			--p1;
			--p2;
			wins[p1] += beats(*m1, *m2);
			wins[p2] += beats(*m2, *m1);
			total[p1] += *m1 != *m2;
			total[p2] += *m1 != *m2;
		}
		FOR(i, n)
			if(total[i]) printf("%.3lf\n", wins[i] / double(total[i]));
			else puts("-");
	}
	return 0;
}

