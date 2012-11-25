#include <cstdio>
#include <cstring>

char ans[100048], text[100048];
bool valid[256];
int main(void){
	for(int i = 0; i < 256; ++i) valid[i] = false;
	for(int c = 'a'; c <= 'z'; ++c) valid[c] = true; 
	for(int c = 'A'; c <= 'Z'; ++c) valid[c] = true; 
	valid['-'] = true;

	int max_len = 0;
	for(int i, j, len; fgets(text, 100048, stdin); ){
		for(i = 0; text[i]; i = j + 1){
			for(j = i; valid[text[j]]; ++j);
			text[j] = 0;
			if((len = j - i) > max_len){
				strcpy(ans, text + i);
				max_len = len;
			}
			if(!strcmp(text + i, "E-N-D")) break;
		}
		if(!strcmp(text + i, "E-N-D")) break;
	}
	for(int i = 0; i < max_len; ++i) ans[i] |= (ans[i] != '-') << 5;
	puts(ans);

	return 0;
}

