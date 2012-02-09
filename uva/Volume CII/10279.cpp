#include <cstdio>

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

char b[16][16], p[16][16], s[16][16];
int main(void){
	int t; scanf("%d", &t);
	for(int n; t-- && scanf("%d", &n) == 1; ){
		bool reveal = false;
		for(int i = 0; i < n; ++i) scanf("%s", b[i]);
		for(int i = 0; i < n; ++i) scanf("%s", p[i]);
		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
			if(p[i][j] == 'x') reveal |= b[i][j] == '*';
		for(int i = 0; i < n; puts(""), ++i) for(int j = 0; j < n; ++j)
			if(reveal && b[i][j] == '*') putc('*', stdout);
			else if(p[i][j] == 'x'){
				int cnt = 0;
				for(int d = 0; d < 8; ++d){
					int ni = i + dx[d], nj = j + dy[d];
					cnt += (ni >= 0 && nj >= 0 && ni < 8 && nj < 8 && b[ni][nj] == '*');
				}
				putc('0' + cnt, stdout);
			} else putc('.', stdout);
		if(t) puts("");
	}
	return 0;
}

