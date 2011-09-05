#include <cctype>
#include <cstdio>
#include <cstring>
//#define DBG
char line[10000];
int stack[100000];
int main(void){
	gets(line);
	while(strcmp(line, "#")){
		int top = 0;
		bool valid = true;
		while(true){
			char *p;
			for(p = line; *p; p++){
				if(*p == '#') break;
				if(!valid) continue;
				if(p[0] == '<' && isupper(p[1]) && p[2] == '>')
					stack[top++] = p[1];
				else if(p[0] == '<' && p[1] == '/' && isupper(p[2]) && p[3] == '>'){
					if(top){
						if(stack[top - 1] == p[2]) --top;
						else{
							valid = false;
							printf("Expected </%c> found </%c>\n", stack[top - 1], p[2]);
						}
					}
					else {
						printf("Expected # found </%c>\n", p[2]);
						valid = false;
					}
				}
			}
			if(*p == '#') break;
			gets(line);
		}
		if(valid){
			if(top) printf("Expected </%c> found #\n", stack[top - 1]);
			else printf("Correctly tagged paragraph\n");
		}
		gets(line);
	}
	return 0;
}

