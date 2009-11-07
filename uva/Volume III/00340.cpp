#include <cstdio>
#include <cstring>
#include <cctype>

#define MIN(a,b) ((a)<(b)?(a):(b))

char s[2048], g[2048];
short int c[10], cs[10], x[10];
int n;

bool read(char *k){
	register char c = 0;
	for(int i = 0; i < n; i++){
		while(!isdigit((c =getc( stdin ))));
		*k++ = c - '0';
	}
	*k = 0;
	return *(k-1);
}
int main(void){
	int game_num = 0, i, strong, weak;
	char *seq;
	while(scanf("%d\n", &n) && n){
		memset(cs, 0, 20);
		read(s);
		for(char *k = s; *k; *k++) cs[*k]++;
		printf("Game %d:\n",++game_num);
		while(read(g)){
			strong = weak = 0;
			for(char *k = g, *l = s; *k; *k++){
				if(*k == *l++) x[*k]++;
				else		   c[*k]++;
			}
			for(i = 1; i < 10; i++){
				strong += x[i];
				weak += MIN(cs[i]-x[i],c[i]);
				c[i] = x[i] = 0;
			}
			printf("    (%d,%d)\n",strong,weak);
		}
	}
	return 0;
}

