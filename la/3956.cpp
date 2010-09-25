#include <cctype>
#include <cstdio>
#define TT 10000
#define NN 160000
bool vis[NN], gg, infeasible;
int d[NN];
int q[NN], h, t;
char b[TT];
char map[128];

int LIM_POS;
void doit(int pos, int keys, int s){
	if((pos << 4) > LIM_POS || pos < 0) return;
	int abspos = (pos << 4) | keys, st;
	if(vis[abspos]) return;
	char x = *(b + pos);
	if(x == 'X'){ gg = 1; return; }
	if(x == '#' || (isupper(x) && !(keys & (1 << map[x])))) return;
	if(islower(x)) keys |= (1 << map[x]);
	q[t] = (pos << 4) | keys;
	vis[q[t]] = 1;
	d[t++] = s + 1;
	
}
int main(void){
	int C, R;
	int begin, end;
	char c, *p;
	map['b'] = map['B'] = 0; map['g'] = map['G'] = 1;
	map['r'] = map['R'] = 2; map['y'] = map['Y'] = 3;
	while(scanf("%d %d\n", &R, &C) && R){
		LIM_POS = R * C * 16;
#ifdef DBG
		printf("(R, C) -> (%d, %d)\n", R, C);
#endif
		end = -1;
		for(int i = 0; i < LIM_POS; ++i) vis[i] = 0;
		p = b;
		for(int i = 0; i < R; ++i){
			c = getc(stdin);
			for(int j = 0; j < C; ++j){
				*p = c;
				if(*p == '*') begin = (p - b) << 4;
				else if(*p == 'X') end = (p - b) << 4;
#ifdef DBG
				putc(*p, stdout);
#endif
				++p;
				c = getc(stdin);
			}
#ifdef DBG
			putc(10, stdout);
#endif
			while(isspace(c)) c = getc(stdin);
			ungetc(c, stdin);
		}
		h = t = gg = 0;
		infeasible = end == -1;
		if(!infeasible)
			for(q[t] = begin, d[t++] = 0, vis[begin] = 1; !gg && h != t; ++h){
				int s = q[h], keys = s % 16, pos = s >> 4, steps = d[h], c = pos % C, r = pos / C;
#ifdef DBG
				printf("yrgb [%d] pos(%d) -> (%d, %d), steps(%d)\n", keys, pos, pos / C, pos % C, steps);
#endif
				if(r) doit(pos - C, keys, steps);
				if(r < R - 1) doit(pos + C, keys, steps);
				if(c) doit(pos - 1, keys, steps);
				if(c < C - 1) doit(pos + 1, keys, steps);
				if(gg) printf("Escape possible in %d steps.\n", steps + 1);
			}
		if((!gg) || (infeasible)) puts("The poor student is trapped!");
	}
	return 0;
}

