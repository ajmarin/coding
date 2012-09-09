#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct word {
	char c[16];
	bool operator<(const word w) const {
		return strcmp(c, w.c) < 0;
	}
	bool is_prefix(const word w) const {
		for(int i = 0; c[i]; ++i)
			if(c[i] != w.c[i]) return false;
		return true;
	}
} w[10048];

int main(void){
	int t; scanf("%d", &t);
	for(int n; scanf("%d", &n) == 1; ){
		for(int i = 0; i < n; ++i)
			scanf("%s", w[i].c);
		sort(w, w + n);
		bool proper = true;
		for(int i = 1; proper && i < n; ++i)
			proper &= !(w[i - 1].is_prefix(w[i]));
		puts(proper ? "YES" : "NO");
	}
	return 0;
}

