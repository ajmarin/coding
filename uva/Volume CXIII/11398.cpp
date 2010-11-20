#include <cstdio>
#include <cstring>

int masks[32], keep[2];
char word[32];
int main(void){
	masks[0] = 0;
	keep[0] = 0; keep[1] = 0xffffffff;
	for(int i = 1; i < 32; ++i) masks[i] = 1 + (masks[i - 1] << 1);
	while(scanf("%s", word) == 1 && word[0] != '~'){
		int L, v = 0; bool flag = 0;
		while(word[0] != '#'){
			L = strlen(word) - 2;
			if(L > 0) v = (v << L) + (masks[L] & keep[flag]);
			else flag = L & 1;
			scanf("%s", word);
		}
		printf("%d\n", v);
	}
	return 0;
}

