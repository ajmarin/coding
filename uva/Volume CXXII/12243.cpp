#include <cctype>
#include <cstdio>
#include <cstring>

char line[2048];
int main(void){
	while(fgets(line, 2048, stdin) && line[0] != '*'){
		char *p = strtok(line, " ");
		char letter = tolower(line[0]);
		while(p != NULL){
			if(tolower(*p) != letter) break;
			p = strtok(NULL, " ");
		}
		if(p == NULL) puts("Y");
		else puts("N");
	}
	return 0;
}

