#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#define COL(x)		(3 * (x % 3))
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
#define PO2(x) 		!((x) & ((x) - 1))
#define ROW(x)		(3 * (x / 3))
const int ANY = 0x3FE; /* ANY = 11.1111.1110 */
/* Masks for column, line, square, puzzle board, square index for given (i, j) */
int mask[9][9];
int p[9][9], sqr[9][9];
/* Number of blanks */
int blank;
bool show_solution = true;
int log2(int x){ for(int r = 0; ; ++r) if(!(x>>=1)) return r; }
void CLRBIT(int &x, int bit){	x &= (ANY - (1 << bit));	}
void SETBIT(int &x, int bit){	x |= (1 << bit);					}
void CLRROW(int R, int bit)	{ 	FOR(c, 9) CLRBIT(mask[R][c], bit);	}
void SETROW(int R, int bit)	{	FOR(c, 9) SETBIT(mask[R][c], bit);	}
void CLRCOL(int C, int bit)	{	FOR(r, 9) CLRBIT(mask[r][C], bit);	}
void SETCOL(int C, int bit)	{	FOR(r, 9) SETBIT(mask[r][C], bit);	}
void CLRSQR(int S, int bit)	{
	FORI(i, ROW(S), ROW(S) + 3) FORI(j, COL(S), COL(S) + 3)
		CLRBIT(mask[i][j], bit);
}
void SETSQR(int S, int bit)	{
	FORI(i, ROW(S), ROW(S) + 3) FORI(j, COL(S), COL(S) + 3)
		SETBIT(mask[i][j], bit);
}
void SETCELL(int i, int j, int bit){
	p[i][j] = bit;
	if(!bit) return;
	--blank;
	mask[i][j] = 0;
	CLRROW(i, bit);
	CLRCOL(j, bit);
	CLRSQR(sqr[i][j], bit);
}
void CHKROW(int &r, int &c, int &v){
	int count[10];
	FOR(i, 9){
		FOR(z, 10) count[z] = 0;
		FOR(j, 9) FORI(k, 1, 10) count[k] += (mask[i][j] & (1 << k)) != 0;
		FORI(k, 1, 10) if(count[k] == 1)
			FOR(j, 9) if(mask[i][j] & (1 << k)){
				r = i, c = j, v = k;
				return;
			}
	}
	v = -1;
	return;
}
void CHKCOL(int &r, int &c, int &v){
	int count[10];
	FOR(j, 9){
		FOR(z, 10) count[z] = 0;
		FOR(i, 9) FORI(k, 1, 10) count[k] += (mask[i][j] & (1 << k)) != 0;
		FORI(k, 1, 10) if(count[k] == 1)
			FOR(i, 9) if(mask[i][j] & (1 << k)){
				r = i, c = j, v = k;
				return;
			}
	}
	v = -1;
	return;
}
void CHKSQR(int &r, int &c, int &v){
	int count[10];
	FOR(S, 9){
		FOR(z, 10) count[z] = 0;
		FORI(i, ROW(S), ROW(S) + 3) FORI(j, COL(S), COL(S) + 3) FORI(k, 1, 10)
			count[k] += (mask[i][j] & (1 << k)) != 0;
		FORI(k, 1, 10) if(count[k] == 1)
			FORI(i, ROW(S), ROW(S) + 3) FORI(j, COL(S), COL(S) + 3)
				if(mask[i][j] & (1 << k)){
					r = i, c = j, v = k;
					return;
				}
	}
	v = -1;
	return;
}
/* Guess and check */
void guess(){
	if(!blank) return;
	int minp = 1 << 30, x, y;
	int bkp[9][9];
	FOR(i, 9) FOR(j, 9){
		if(p[i][j]) continue;
		int cnt = 0;
		FORI(k, 1, 10) cnt += mask[i][j] & (1 << k);
		if(cnt < minp) minp = cnt, x = i, y = j;
	}
	if(minp){
		FORI(k, 1, 10) if(mask[x][y] & (1 << k)){
			memcpy(bkp, mask, sizeof(bkp));
			SETCELL(x, y, k);
			guess();
			if(!blank) return;
			p[x][y] = 0;
			++blank;
			memcpy(mask, bkp, sizeof(bkp));
		}	
	}
}
void show(){
	static int gc = 0;
	printf("Grid %d:\n", ++gc);
	FOR(i, 9){
		if(!(i % 3)) printf("%c-----------------------%c\n", i?'|':' ', i?'|':' ');
		FOR(j, 9){
			if(!j) printf("|");
			if(j && !(j % 3)) printf(" |");
			printf(" %c", p[i][j] ? p[i][j] + '0' : ' ');
		}
		printf(" |\n");
	}
	printf(" ----------------------- \n");
}		
int solve(){
	for(bool diff = true; diff; ){
		diff = false;
		/* Fill already defined cell */
		FOR(i, 9) FOR(j, 9){
			if(p[i][j]) continue;
			if(PO2(mask[i][j])){
				SETCELL(i, j, log2(mask[i][j]));
				diff = true;
			}				
		}
		/* Look for a cell which is the only one containing a
		** certain number in a line, column or box
		*/
		int x, y, z;
		CHKROW(x, y, z);
		if(z != -1){ diff = true, SETCELL(x, y, z); }
		CHKCOL(x, y, z);
		if(z != -1){ diff = true, SETCELL(x, y, z); }
		CHKSQR(x, y, z);
		if(z != -1){ diff = true, SETCELL(x, y, z); }
		done:
		if(!diff) break;
	}
	guess();
	if(show_solution) show();
	return 100 * p[0][0] + 10 * p[0][1] + p[0][2];
}
int main(void){
	clock_t ini = clock();
	int ans = 0, temp;
	freopen("sudoku.txt", "r", stdin);
	freopen("sudoku_solutions.txt", "w", stdout);
	FOR(i, 9) FOR(j, 9) sqr[i][j] = 3 * (i / 3) + j / 3;
	FOR(n, 50){		
		/* Initially, any cell can be any number */
		FOR(i, 9) FOR(j, 9) mask[i][j] = ANY;
		/* Read puzzle, count blank cells */
		blank = 81;
		scanf("%*[^\n]\n");
		FOR(i, 9) FOR(j, 9){				
			scanf("%1d", &temp);
			SETCELL(i, j, temp);
		}
		scanf("%*[^\n]\n");		
		/* Solve puzzle, add number formed by three top-left cells */
		ans += solve();
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
