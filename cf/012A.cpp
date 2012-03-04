#include <cstdio>

int dx[4] = {-1, 0, 1, -1};
int dy[4] = {-1, -1, -1, 0};
char s[3][16];
int main(void){
	bool symmetric = true;
	for(int i = 0; i < 3; ++i) scanf("%s", s[i]);
	for(int d = 0; d < 4; ++d)
		symmetric &= s[1 + dx[d]][1 + dy[d]] ==  s[1 - dx[d]][1 - dy[d]];
	puts(symmetric ? "YES" : "NO");
	return 0;
}
