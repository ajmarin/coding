#include <cstdio>

char line[1024];
int main(void){
	while(fgets(line, 1024, stdin)){
		printf("%s", line);
	}
	return 0;
}

