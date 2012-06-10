#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)

struct s {
	char word[128];
	int c[128];
	void cnt(){
		FOR(i, 128) c[i] = 0;
		for(int i = 0; word[i]; ++i) if(isalpha(word[i])) ++c[word[i]];
	}
	bool operator==(const s& z) const {
		FOR(i, 128) if(c[i] != z.c[i]) return false;
		return true;
	}
	bool operator<(const s& z) const { return strcmp(word, z.word) < 0; }
} z[128];


char line[1024];
int main(void){
	int t; scanf("%d", &t); gets(line);
	gets(line);
	while(t--){
		int n;
		for(n = 0; gets(z[n].word) && z[n++].word[0]; );
		sort(z, z + n);
		FOR(i, n) z[i].cnt();
		FOR(i, n) FOR(j, n) if(j > i && z[i] == z[j]){
			printf("%s = %s\n", z[i].word, z[j].word);
		}
		if(t) puts("");
	}
	return 0;
}

