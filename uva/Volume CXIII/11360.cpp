#include <cstdio>

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TRIM while(getc(stdin) != 10)
char cmd[16], line[256];
int m[16][16];
int next[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int prev[10] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8};

void swap(int &a, int& b){ int t = a; a = b; b = t; }
void trim(){ while(getc(stdin) != 10); }
int main(void){
	int a, b, cn = 0, n, t, z; scanf("%d", &t);
	while(t-- && scanf("%d", &n) == 1){
		FOR(i, n) FOR(j, n) scanf("%1d", &m[i][j]);
		scanf("%d", &z);
		TRIM;
		while(z-- && gets(line)){
			if(sscanf(line, "%s %d %d", cmd, &a, &b) == 3){
				--a; --b;
				if(cmd[0] == 'r') // swap rows
					FOR(j, n) swap(m[a][j], m[b][j]);
				else if(cmd[0] == 'c') // swap columns
					FOR(i, n) swap(m[i][a], m[i][b]);
			} else if(sscanf(line, "%s", cmd) == 1){
				if(cmd[0] == 'i') // inc
					FOR(i, n) FOR(j, n) m[i][j] = next[m[i][j]];
				else if(cmd[0] == 'd') // dec
					FOR(i, n) FOR(j, n) m[i][j] = prev[m[i][j]];
				else if(cmd[0] == 't') // transpose
					FOR(i, n) for(int j = i + 1; j < n; ++j)
						swap(m[i][j], m[j][i]);
			}
		}
		printf("Case #%d\n", ++cn);
		FOR(i, n){ FOR(j, n) putc(m[i][j] + '0', stdout); puts(""); }
		puts("");
	}
	return 0;
}

