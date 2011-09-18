#include <cstdio>
#include <cstring>
char w[32];
const char* lang(const char* word){
	if(!strcmp(word, "HELLO")) return "ENGLISH";
	if(!strcmp(word, "BONJOUR")) return "FRENCH";
	if(!strcmp(word, "HALLO")) return "GERMAN";
	if(!strcmp(word, "CIAO")) return "ITALIAN";
	if(!strcmp(word, "ZDRAVSTVUJTE")) return "RUSSIAN";
	if(!strcmp(word, "HOLA")) return "SPANISH";
	return "UNKNOWN";
}
int main(void){
	for(int c(0); scanf("%s", w) && *w != '#'; printf("Case %d: %s\n", ++c, lang(w)));
	return 0;
}

