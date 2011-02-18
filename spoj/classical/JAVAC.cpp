#include <cstdio>

bool up(char x){ return x >= 'A' && x <= 'Z'; }
bool low(char x){ return x >= 'a' && x <= 'z'; }
int main(void){
	bool cpp, java;
	for(char var[128]; scanf("%s", var) == 1; ){
		cpp = java = !up(*var) && *var != '_';
		for(int i = 0; (cpp | java) && var[i]; ++i){
			cpp &= low(var[i]) || (var[i] == '_' && low(var[i + 1]));
			java &= var[i] != '_';
		}
		if(cpp){
			for(int i = 0; var[i]; ++i){
				if(var[i] != '_') putc(var[i], stdout);
				else var[i + 1] -= 32;
			}
		} else if(java){
			for(int i = 0; var[i]; ++i){
				if(up(var[i])) putc('_', stdout), var[i] += 32;
				putc(var[i], stdout);
			}
		} else printf("Error!");
		putc(10, stdout);
	}
	return 0;
}

