#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int z[26][26];

int main(void){
	char word[16];
	for(int n; scanf("%d", &n) == 1 && n; ){
		char b, e;
		for(int i = 0; i < 26; ++i){
			for(int j = 0; j < 26; ++j){
				z[i][j] = 1<<31;
			}
		}
		for(int i = 0, l; i < n; ++i){
			scanf("%s", word);
			l = strlen(word);
			b = word[0] - 'a';
			e = word[l - 1] - 'a';
			for(int j = 0; j < 26; ++j) z[j][e] = max(z[j][e], z[j][b] + l);
			z[b][e] = max(z[b][e], l);
		}
		int ans = 0;
		for(int i = 0; i < 26; ++i)
			ans = max(ans, z[i][i]);
		printf("%d\n", ans);
	}
	return 0;
}

