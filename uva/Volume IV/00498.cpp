#include <cstdio>
#include <cstdlib>
#include <cstring>

int c[32], x[1024];
char line[1024];
void parse(char *in, int *v, int *vs){
	char *p = strtok(in, " \r\n");
	while(p != NULL){
		v[(*vs)++] = atoi(p);
		p = strtok(NULL, " \r\n");
	}
}
int main(void){
	int cs, xs;
	while(fgets(line, 1024, stdin)){
		cs = xs = 0;
		parse(line, c, &cs);
		fgets(line, 1024, stdin), parse(line, x, &xs);
		for(int i = 0; i < xs; ++i){
			int v = 1, r = 0;
			for(int j = cs; j--; ){				
				r += v * c[j];
				v *= x[i];
			}
			if(i) putc(32, stdout);
			printf("%d", r);
		}
		putc(10, stdout);
	}
	return 0;
}
