#include <cstdio>

bool busy[128];
char b[16][16];
int n;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

void check(int i, int j, bool f){
	for(int d = 0; d < 4; ++d){
		int ni = i + di[d], nj = j + dj[d];
		if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
		busy[b[ni][nj]] = f;
	}
}

int main(void){
	int t; scanf("%d", &t);
	for(int i = 0; i < 128; ++i) busy[i] = 0;
	for(int p = 1; t-- && scanf("%d\n", &n) == 1; ++p){
		for(int i = 0; i < n; ++i) fgets(b[i], 16, stdin);
		printf("Case %d:\n", p);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(b[i][j] == '.'){
					char x;
					check(i, j, 1);
					for(x = 'A'; busy[x]; ++x);
					check(i, j, 0);
					b[i][j] = x;
				}
				putc(b[i][j], stdout);
			}
			putc(10, stdout);
		}
	}
	return 0;
}

