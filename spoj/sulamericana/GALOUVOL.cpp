#include <cstdio>

#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)
#define NN 102

char m[NN][NN];
bool v[NN][NN];
char d[2] = { '(', ')' };
int R, C;
int dx[6] = {-1, -1, 0, 1, 1, 0};
int dy[6] = {1, 0, -1, -1, 0, 1};
int qi[10000], qj[10000];

void bdfs(int x, int y){
	if(m[x][y] == 'B') return;
	m[x][y] = 'B';
	FOR(k, 6) {
		int nx = x + dx[k], ny = y + dy[k];
		if(m[nx][ny] != '.') bdfs(nx, ny);
	}
}
void dfs(int x, int y, bool dir){
	if(m[x][y] == 'B') return;
	if(v[x][y]){
		if(m[x][y] == d[opp]) bdfs(x, y);
		return;
	}
	bool opp = 1 - dir;
	v[x][y] = 1;
	m[x][y] = d[dir];
	FOR(k, 6){
		int nx = x + dx[k], ny = y + dy[k];
		if(m[nx][ny] != '.') dfs(nx, ny, opp);
	}
}
int main(void){
	FOR(i, 102) m[i][0] = m[0][i] = '.';
	while(scanf("%d %d\n", &R, &C) && (R || C)){
		int h = 0, t = 0;
		++R; ++C;
		FORI(i, 1, R){
			FORI(j, 1, C){
				v[i][j] = 0;
				m[i][j] = getc(stdin);
				if(m[i][j] == 'I') qi[t] = i, qj[t++] = j;
			}
			getc(stdin);
		}
		FOR(i, R) m[i][C] = '.';
		FOR(j, C) m[R][j] = '.';
		while(h < t){
			int x = qi[h], y = qj[h++];
			if(!v[x][y]) dfs(x, y, 0);
			else if(m[x][y] == ')') bdfs(x,y);
		}
		putc(10, stdout);
		FORI(i, 1, R){
			FORI(j, 1, C){
				if(m[i][j] == '*') putc('F', stdout);
				else putc(m[i][j], stdout);
			}
			putc(10, stdout);
		}
	}
	return 0;
}

