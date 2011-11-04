#include <cstdio>

const int MVAL = 32000;
char operators[4] = {'+', '-', '*', '/'};
int o[101], v[101][64001], z[101];
int cnum, p;
bool found;

int abs(int a){ return a < 0 ? -a : a; }

int calc(int x, int y, char op){
	switch(op){
		case '+': return x + y; break;
		case '-': return x - y; break;
		case '*': return x * y; break;
		case '/': return !(x % y) ? x / y : 32001; break;
	}
	return 1<<15;
}

void dfs(int i, int r){
	if(found || v[i][r + MVAL] == cnum) return;
	int temp;
	v[i][r + MVAL] = cnum;
	if(i == p){
		if(r == z[p]){
			found = true;
			for(int j = 0; j < p; ++j) printf("%d%c", z[j], o[j]);
			printf("%d\n", z[p]);
		}
		return;
	}
	for(char *op = operators; !found && *op; ++op)
		if(abs(temp = calc(r, z[i], *op)) <= MVAL){
			o[i - 1] = *op;
			dfs(i + 1, temp);
		}
}

int main(void){
	int t; scanf("%d", &t);
	for(int i = 0; i < 101; ++i) for(int j = 0; j < 64001; ++j) v[i][j] = -1;
	for(cnum = 0; cnum++ < t; ){
		if(scanf("%d", &p) != 1) break;
		for(int i = 0; i <= p; ++i) scanf("%d", z + i);
		o[p - 1] = '=';
		found = false;
		dfs(1, z[0]);
		if(!found) puts("NO EXPRESSION");
	}
	return 0;
}

