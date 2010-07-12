#include <cstdio>

inline char abs(char x){ return x < 0? -x : x; }
char cst[20][3], p[8], r[8][20], rc[8], s[8];
char n, m;
int arrangements;
int bt(int k){
	if(k == n) return ++arrangements;
	bool go;
	for(int i = 0; i < n; ++i){
		if(s[i]) continue;
		p[i] = k;
		s[i] = 1;
		go = 1;
		for(int j = 0; j < rc[i]; ++j){
			char * v = cst[r[i][j]];
			if(s[v[0]] && s[v[1]]){
				int dist = abs(p[v[0]] - p[v[1]]);
				if(v[2] >= 0 && dist > v[2]){ go = 0; break; }
				if(v[2] < 0 && dist < -v[2]){ go = 0; break; }
			}
		}
		if(go) bt(k + 1);
		s[i] = 0;
	}
}

int main(void){
	while(scanf("%d %d", &n, &m) && n){
		arrangements = 0;
		for(int i = 0; i < n; ++i)
			s[i] = rc[i] = 0;
		for(int i = 0; i < m; ++i){
			char * v = cst[i];
			scanf("%d %d %d", &v[0], &v[1], &v[2]);
			r[v[0]][rc[v[0]]++] = r[v[1]][rc[v[1]]++] = i;
		}
		bt(0);
		printf("%d\n", arrangements);
	}
	return 0;
}
