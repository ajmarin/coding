#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
bool cr[10][26], solved;
char ans[16];
int c[26];

void bt(int k, int n){
	if(!n){ solved = true; return; }
	if(solved || k >= 10) return;
//	printf("Status (%d, %d) -> %s\n", k, n, ans);
	FOR(i, 26) if(c[i] && cr[k][i]){
		--c[i];
		ans[k] = i + 'A';
		bt(k + 1, n - 1);
		if(solved) return;
		ans[k] = '_';
		++c[i];
	}
	bt(k + 1, n);
}

int main(void){
	for(char app[1024], m[1024]; ; ){
		char x; int app_cnt, n, t = 0;
		FOR(i, 10) ans[i] = '_'; ans[10] = 0;
		FOR(i, 26) c[i] = 0;
		FOR(i, 10) FOR(j, 26) cr[i][j] = false;
		solved = false;
		for(app_cnt = 0; gets(app) && *app; ++app_cnt){
			sscanf(app, " %c%d %s", &x, &n, m);
			t += c[x -= 'A'] = n;
			for(int i = 0; m[i] != ';'; ++i) cr[m[i] - '0'][x] = true;
		}
		if(!app_cnt) break;
		solved = false;
		bt(0, t);
		if(solved) puts(ans);
		else puts("!");
	}
	return 0;
}

