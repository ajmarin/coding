#include <cstdio>
#include <cstring>

const int TT = 128, WW = 128;
char text[TT], word[WW];
int T[WW];

void build_table(){
	T[0] = -1, T[1] = 0;
	for(int cnd = 0, pos = 2; word[pos]; )
		if(word[pos - 1] == word[cnd]) T[pos++] = ++cnd;
		else if(cnd) cnd = T[cnd];
		else T[pos++] = 0;
}

int kmp(){
	int i = 0, m = 0;
	while(text[m + i]){
		if(word[i] == text[m + i]){
			if(!word[++i]) return m;
		} else {
			m = m + i - T[i];
			i = T[i] + (T[i] == -1);
		}
	}
	return m;
}

int main(void){
	scanf("%*d");
	for(int k, w; scanf("%d %d", &k, &w) == 2; ){
		int ans = k * w;
		scanf("%s", text);
		for(int i = 1; i < w; ++i){
			scanf("%s", word);
			build_table();
			ans -= k - kmp();
			strcpy(text, word);
		}
		printf("%d\n", ans);
	}
	return 0;
}

