#include <cstdio>
#include <cctype>
#include <cstring>

#define NN 10058
#define FOR(a,b) for(int a = 0; a < b; ++a)
#define IN getc( stdin )

int c[NN], p[NN], q[NN], s[NN], x[NN], y[NN], C, N;
bool v[NN];
void fastint( register int *n ){
	register char c;
	*n = 0;
	while(!isdigit((c = IN)));
	ungetc(c, stdin);
	while(c = IN){
		switch( c ){
			case ' ': return;
			case '\n': return;
			default: (*n) *= 10; (*n) += ( c - '0' ); 
		}
	}
}
inline int sqr(int x){ return (x*x); }
inline int d2(int a, int b){ return sqr(x[b]-x[a])+sqr(y[b]-y[a]);}
void reverse(int k, int cap);
int main(void){
	while(scanf("%d %d",&N,&C) && N){
		memset(p, -1, N<<2);
		memset(s, 0, N<<2);
		memset(v, 0, N);
		FOR(i, N) {
			fastint(&x[i]); fastint(&y[i]); fastint(&c[i]);
			int min = 1<<25;
			FOR(j, i){
				int d = d2(i,j);
				if(d < min) min = d, p[i] = j;
			}
			if(i) s[p[i]]++;
		}
		int power_plants = 0;
		int h, t;
		h = t = 0;
		FOR(i, N) if(s[i] == 0) q[t++] = i;
		while(h != t){
			int k = q[h++];
			v[k] = 1;
			if(c[k] >= C) power_plants++;
			else if(p[k] != -1)	c[p[k]] += c[k];
			if(p[k] != -1 && --s[p[k]] == 0) q[t++] = p[k];
		}
		FOR(i, N) if(!v[i] && c[i] >= C) power_plants++;
		printf("%d\n",power_plants);
	}
	return 0;
}

