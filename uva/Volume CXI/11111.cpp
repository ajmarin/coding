#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 1048576;
int q[N];
char line[N];
int main(void){
	while(fgets(line, N, stdin)){
		int nested, top = 0, valid = 1, z;
		for(char *ptr = strtok(line, " "); ptr != NULL; ptr = strtok(NULL, " ")){
			z = atoi(ptr);
			if(z > 0){
				for(nested = 0; top > 0 && q[--top] != -z; nested += q[top]) valid &= q[top] > 0;
				valid &= q[top] == -z && nested < z;
			}
			if(!valid) break;
			q[top++] = z;
		}
		while(top > 0 && q[--top] > 0);
		valid &= !top && q[top] > 0;
		puts(valid ? ":-) Matrioshka!" : ":-( Try again.");
	}
	return 0;
}

