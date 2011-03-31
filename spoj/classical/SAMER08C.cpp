#include <cstdio>

const int MAX = 4096;
char buf[MAX], *lim = buf + MAX, *now = lim;
bool isdigit(char c){ return c >= '0' && c <= '9'; }
void readint(int &n){   
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	for(n = 0; isdigit(*now); n = (n << 1) + (n << 3) + *now++ - '0');
}
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	int r, c;
	while(1){
		int ppc, pc, ppl, pl, v;
		readint(r); readint(c);
		if(!(r || c)) break;
		ppl = pl = 0;
		for(int i = 0; i < r; ++i){
			ppc = pc = 0;
			for(int j = 0; j < c; ++j){
				readint(v);
				v = max(v + ppc, pc);
				ppc = pc;
				pc = v;
			}
			v = pl;
			pl = max(pl, ppl + pc);
			ppl = v;
		}
		printf("%d\n", pl);
	}
	return 0;
} 

