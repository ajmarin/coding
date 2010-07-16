#include <cstdio>

#define FOR(a, b) for(int a = 0; a < b; ++a)
struct coord {
	int C, L, R, S;
	coord(int _L = 0, int _R = 0, int _C = 0, int _S = 0){
		L = _L, R = _R, C = _C, S = _S;
	}
};
coord q[27000];
char dg[30][30][30];
bool v[30][30][30];
int qh, qs;
int dir[][3] = {{1, 0, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
void push(int r, int l, int c, int s){
	q[qs++] = coord(r, l, c, s);
}
int main(void){
	bool exit;
	int ans, C, L, R, SC, SL, SR;
	while(scanf("%d %d %d", &L, &R, &C) && (L || R || C)){
		exit = qh = qs = 0;
		FOR(i, L) FOR(j, R){
			scanf("%s", dg[i][j]);
			FOR(k, C) {
				v[i][j][k] = 0;
				if(dg[i][j][k] == 'S') SL = i, SR = j, SC = k;
			}
		}
		push(SL, SR, SC, 0);
		v[SL][SR][SC] = 1;
		while(!exit && qh != qs){
			coord *c = q + qh++;
			int CL = c->L, CR = c->R, CC = c->C;
			int nS = c->S + 1;
			for(int d = 0; d < 6; ++d){
				int nL = CL + dir[d][0], nR = CR + dir[d][1], nC = CC + dir[d][2];
				if(nL < 0 || nR < 0 || nC < 0) continue;
				if(nL >= L || nR >= R || nC >= C) continue;
				char next = dg[nL][nR][nC];
				if(v[nL][nR][nC] || next == '#') continue;
				if(next == '.') v[nL][nR][nC] = 1, push(nL, nR, nC, nS);
				else {ans = nS, exit = 1; break; }
			}
		}
		if(exit) printf("Escaped in %d minute(s).\n", ans);
		else printf("Trapped!\n");
		
	}
	return 0;
}