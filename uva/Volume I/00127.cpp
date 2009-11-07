#include <cctype>
#include <cstdio>

#define IN getc( stdin )
struct card {
	char s, u, v;
	bool match(card x){ return v == x.v || s == x.s; }
}c[52];
const char *rem[2] = {"pile remaining:","piles remaining:"};
char a, ct, ps[52], top[52], x;
char stk[3], ans[256];
void mL(char p){
	for(char y = p, z = p+1; z <= ct; ++z, ++y){
		top[y] = top[z];
		ps[y] = ps[z];
	}
	top[ct] = -1;
	ps[ct] = 0;
}
void move(char p1, char p2){
	char a = top[p1], b = top[p2];
	char k = top[p1];
	top[p1] = c[k].u;
	c[k].u = top[p2];
	top[p2] = k;
	if(!--ps[p1]) mL(p1), --ct;
	ps[p2]++;
}
void tryMove(char t){
	if(!ps[t]) return;
	if(t > 2 && c[top[t]].match(c[top[t-3]])){
		move(t, t-3);
		for(char z = t-3; z <= ct; ++z)
			if(top[z] != -1) tryMove(z);
	} else if(t && c[top[t]].match(c[top[t-1]])){
		move(t, t-1);
		for(char z = t-1; z <= ct; ++z)
			if(top[z] != -1) tryMove(z);
	}
}
int main(void){
	register char h;
	while((h = IN) != '#'){
		for(a = 0; a < 52; ++a) top[a] = -1, ps[a] = 0;
		for(a = ct = 0; a < 52; ++a, ++ct){
			while(isspace(h)) h = IN;
			c[a].v = h; c[a].s = IN;
			c[a].u = top[ct];
			top[ct] = a;
			ps[ct]++;
			tryMove(ct);
			h = IN;
		}
		printf("%d ", ct);
		fputs(rem[ct!=1], stdout);
		register char *out = ans, *s, k;
		for(x = 0; x < ct; ++x) {
			*out++ = ' '; s = stk; k = ps[x];
			while(k) *s++ = k % 10 + '0', k /= 10;
			while(s > stk) *out++ = *--s;
		}
		*out = 0;
		puts(ans);
	}
}

