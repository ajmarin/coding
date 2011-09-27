#include <cstdio>
#include <cstdlib>
#define FORI(i,s,n) for(int i = s; i < n; ++i)
#define FOR(i,n)	FORI(i,0,n)

int ans[8], p[32][3], v[8][2];
int min_sum, n;

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int min(int a, int b){ return a < b ? a : b; }

void bt(int x, int cnt){
	if(cnt == 5){
		int sum = 0;
		FOR(i, n){
			int md = 1 << 30;
			FOR(j, 5) md = min(md, dist(v[j][0], v[j][1], p[i][0], p[i][1]));
			sum += md * p[i][2];
		}
		if(sum < min_sum){
			min_sum = sum;
			FOR(i, 5) ans[i] = v[i][0]*5 + v[i][1];
		}
		return;
	}
	FORI(i, x, 25){
		v[cnt][0] = i / 5;
		v[cnt][1] = i % 5;
		bt(i + 1, cnt + 1);
	}
}

int main(void){
	int t; scanf("%d", &t);
	while(t-- && scanf("%d", &n) == 1){
		FOR(i, n) scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
		min_sum = 1 << 30;
		bt(0, 0);
		FOR(i, 5) printf("%d%c", ans[i], i == 4 ? '\n' : ' ');
	}
	return 0;
}

