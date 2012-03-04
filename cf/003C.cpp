#include <cstdio>

#define FOR(i,e)		for(int i = 0; i < e; ++i)
#define FORD(i,s,e)		for(int i = s; i > e; --i)
#define FOREACH(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define FORI(i,s,e)		for(int i = s; i < e; ++i)
#define IN(x)			(x = getc(stdin))
#define OUT(x)			putc(x, stdout)
template <class _T> _T max(_T a, _T b){ return a > b ? a : b; }
template <class _T> _T min(_T a, _T b){ return a < b ? a : b; }
char m[3][16];
bool check(char c){
	FOR(i, 3){
		if(m[i][0] == c && m[i][0] == m[i][1] && m[i][1] == m[i][2]) return true;
		if(m[0][i] == c && m[0][i] == m[1][i] && m[1][i] == m[2][i]) return true;
	}
	if(m[0][0] == c && m[0][0] == m[1][1] && m[1][1] == m[2][2]) return true;
	if(m[2][0] == c && m[2][0] == m[1][1] && m[1][1] == m[0][2]) return true;
	return false;
}
int main(void){
	bool cw = false, zw = false;
	int c = 0, z = 0;
	FOR(i, 3) scanf("%s", m[i]);
	FOR(i, 3) FOR(j, 3){
		c += m[i][j] == 'X';
		z += m[i][j] == '0';
	}
	if(c > z + 1 || c < z){ puts("illegal"); return 0; }
	cw = check('X');
	zw = check('0');
	if((cw && zw) || (cw && c != z + 1) || (zw && c != z)) puts("illegal");
	else if(cw) puts("the first player won");
	else if(zw) puts("the second player won");
	else if(c + z == 9) puts("draw");
	else if(c > z) puts("second");
	else puts("first");

	return 0;
}

