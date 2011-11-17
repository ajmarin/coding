#include <cstdio>
#include <cstdlib>
#include <cstring>

#define FOR(i, n) for(int i = 0; i < n; ++i)

const int INF = 1 << 20, NN = 128;
int m1[NN][NN], m2[NN][NN];
char line[65536];

int min(int a, int b){
	return a < b ? a : b;
}

void read_graph(int m[128][128], int n){
	FOR(i, n){
		gets(line);
		for(char *z = strtok(line, " "); z != NULL; z = strtok(NULL, " "))
			m[i][atoi(z) - 1] = 1;
	}
	FOR(k, n) FOR(i, n) FOR(j, n) m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
}

int main(void){
	for(int A, B, n; scanf("%d\n", &n) == 1 && n; ){
		FOR(i, n) FOR(j, n) m1[i][j] = m2[i][j] = INF;
		read_graph(m1, n);
		read_graph(m2, n);
		scanf("%d %d", &A, &B);
		bool valid = true;
		FOR(i, n) FOR(j, n) valid &= m2[i][j] <= A * m1[i][j] + B;
		puts(valid ? "Yes" : "No");
	}
	return 0;
}

