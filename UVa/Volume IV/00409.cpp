#include <cctype>
#include <cstdio>
#include <set>
#include <string>

#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)
#define IN getc( stdin )
#define TOLOWER(k) (k <= 'Z' ? k +  32 : k)

using namespace std;


set < string > xc;
char e[32][128], test[128];
int K, E, maxXC, n[32], xset = 0;

void get_excuses(){
	register char c, *w;
	FOR(i, K){
		w = test;
		while((c = IN) != '\n') *w++ = TOLOWER(c);
		*w = 0;
		xc.insert(string(test));
	}
}
void read_phrases(){
	register char c, *pp, *ss;
	maxXC = 0;
	FOR(i, E){
		pp = e[i];
		while(isprint(c = IN)) *pp++ = c;
		*pp = 0;
		for(pp = e[i], n[i] = 0; *pp; ){
			while(*pp && !isalpha(*pp)) *pp++;
			ss = test;
			while(*pp && isalpha(*pp)) *ss++ = TOLOWER(*pp), pp++;
			*ss = 0;
			n[i] += (xc.find(string(test)) != xc.end());
		}
		if(n[i] > maxXC) maxXC = n[i];
	}
}
int main(void){
	while(scanf("%d %d\n",&K,&E)==2){
		printf("Excuse Set #%d\n",++xset);
		xc.clear();
		get_excuses();
		read_phrases();
		FOR(i, E) if(n[i] == maxXC) puts(e[i]);
		putc(10, stdout);
	}
	return 0;
}

