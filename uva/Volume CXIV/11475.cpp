#include <cstdio>
#include <cstring>

const int TT = 1 << 18, WW = TT;
char text[TT], word[WW];
int T[WW], len;

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
	// {{{ modified part
	while(m--) text[len++] = text[m];
	text[len] = 0;
	// }}} 
	return m + i;
}

int main(void){
	while(scanf("%s", text) == 1){
		len = strlen(text);
		for(int i = 0; i < len; ++i)
			word[len - i - 1] = text[i];
		word[len] = 0;
		build_table();
		kmp();
		puts(text);
	}
}

