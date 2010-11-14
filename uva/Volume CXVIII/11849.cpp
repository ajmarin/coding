#include <cctype>
#include <cstdio>
#define RI readint
#define MAX 1048576
char buf[MAX], *lim = buf + MAX, *now = lim;
void adapt(){
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
}
void readint(int &n){	
	adapt();
	n = 0;	
	while(isdigit(*now)) n = n * 10 + *now++ - '0';
}
int v[1000048];
int main(void){
	int m, n, z;
	for(RI(m), RI(n); m || n; RI(m), RI(n)){
		int eq = 0;
		for(int i = 0, *vp = v; i < m; ++i, ++vp) RI(*vp);
		for(int i = 0, j = 0; i < n; ++i){
			RI(z); while(j < m && v[j] < z) ++j;
			eq += v[j] == z;
		}
		printf("%d\n", eq);
	}
	return 0;
}

