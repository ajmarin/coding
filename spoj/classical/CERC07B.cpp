#include <cassert>
#include <cstdio>
int s, pmax, C, R;
int min(int a, int b){ return ((a) < (b)) ? (a):(b); }
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, -1, 0, 1 };
bool m[32][32];
bool t[32][32];
void doit(int x, int y){
	for(int i = 0; i < 5; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		t[nx][ny] = 1 - t[nx][ny];
	}
}
int test(int mask){
	int fc = 0;
	for(int x = 1; x <= R; ++x)
		for(int y = 1; y <= C; ++y)
			t[x][y] = m[x][y];
	for(int y = 1; y <= C; ++y)
		if((1 << (y - 1)) & mask){
			if(++fc >= s) return pmax;
			doit(1, y);
		}
	for(int x = 2; x <= R; ++x){
		int fr = 0;
		for(int y = 1; y <= C; ++ y)
			if(t[x - 1][y]){
				if(++fc >= s) return pmax;
				fr++;
				doit(x, y);
			}
	}
	for(int y = 1; y <= C; ++y)
		if(t[R][y]) return pmax;
	return fc;
}
int main(void){
	char c;
	while(scanf("%d %d\n",&R, &C) && R){
		s = pmax = C * R + 1;
		for(int i = 1; i <= R; ++i){
			for(int j = 1; j <= C; ++j){
				c = getc(stdin);
				assert(c == '.' || c == 'X');
				m[i][j] = c == 'X';
			}
			while(c != 10) c = getc(stdin);
		}
		for(int i = 0; i < (1 << C); ++i) s = min(s, test(i));
		if(s == pmax) printf("Damaged billboard.\n");
		else printf("You have to tap %d tiles.\n", s);
	}
	return 0;
}

