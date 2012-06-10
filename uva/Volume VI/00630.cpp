#include <cstdio>
#include <cstring>

#define FOR(i,n) for(int i = 0; i < n; ++i)
#define FORW(i,n) for(int i = 0; n[i]; ++i)

bool anagram(char *s, char *t){
	int c[128];
	FOR(i, 128) c[i] = 0;
	FORW(i, s) ++c[s[i]];
	FORW(i, t) --c[t[i]];
	FOR(i, 128) if(c[i]) return false;
	return true;
}

char w[1024][32], z[32];

int main(void){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		FOR(i, n) scanf("%s", w[i]);
		while(scanf("%s", z) && strcmp(z, "END")){
			printf("Anagrams for: %s\n", z);
			int anagrams = 0;
			FOR(i, n) if(anagram(w[i], z)) printf("%3d) %s\n", ++anagrams, w[i]);
			if(!anagrams) printf("No anagrams for: %s\n", z);
		}
		if(t) puts("");
	}
	return 0;
}

