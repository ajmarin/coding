#include <cstdio>
#include <cstdlib>
#include <cstring>

#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) for(int a = 0; a < b; ++a)

struct word {
	char s[1024];
	word *n;
} words[4096];
long long bucket(word *w, int x){
	long long r = 0;
	int bs[128], counter = 0;
	word *b[128], *l[128];
	FOR(i, 128) b[i] = l[i] = NULL, bs[i] = 0;
	/* Distribui as palavras nos baldes */
	while(w != NULL){
		char c = w->s[x];
		if(b[c] == NULL) b[c] = l[c] = w;
		else l[c] = l[c]->n = w;
		w = w->n;
		l[c]->n = NULL;
		r = r + counter++ + bs[c]++;
	}
	/* Redistribui pela proxima letra */
	FORI(i, '0', 128) if(bs[i] > 1) r += bucket(b[i], x + 1);
	return r;
}
int main(void){
	int cnum = 0, n;
	while(scanf("%d", &n) && n){
		FOR(i, n){
			scanf("%s", words[i].s);
			words[i].n = NULL;
			if(i < n-1) words[i].n = &words[i + 1];
		}
		printf("Case %d: %lld\n", ++cnum, bucket(words, 0));
	}
}

