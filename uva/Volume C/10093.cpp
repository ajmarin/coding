#include <cassert>
#include <cstdio>

char map[128], s[1024];

bool valid(char& c){
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool read_input(){
	char c;
	int i;
	for(c = 0; c != EOF && !valid(c); c = getc(stdin));
	if(c == EOF) return false;
	for(i = 0; valid(c); c = getc(stdin)) s[i++] = c;
	s[i] = 0;
	return i > 0;
}
int main(void){
	for(int i = 0; i < 128; ++i) map[i] = -1;
	for(char c = '0'; c <= '9'; ++c) map[c] = c - '0';
	for(char c = 'A'; c <= 'Z'; ++c) map[c] = c - 'A' + 10;
	for(char c = 'a'; c <= 'z'; ++c) map[c] = c - 'a' + 36;
	while(read_input()){
		int base = 1, tbase, z;
		for(int i = 0; s[i]; ++i)
			if(map[s[i]] > base) base = map[s[i]];
		for(tbase = base + 1, z = 0; tbase < 63; z = 0, ++tbase){
			for(int i = 0; s[i]; ++i) 
				z = ((z * tbase) + map[s[i]]) % (tbase - 1);
			if(!z) break;
		}
		if(tbase == 63) puts("such number is impossible!");
		else printf("%d\n", tbase);
	}
	return 0;
}

