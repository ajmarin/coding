#include <cstdio>

char pz[16][16];
bool hv[16][16], vv[16][16];
bool eligible(int i, int j){
	return pz[i][j] != '*' && (i == 0 || j == 0 || pz[i - 1][j] == '*' || pz[i][j - 1] == '*');
}
int main(void){
	for(int c, p = 0, r; scanf("%d %d\n", &r, &c) == 2 && (r && c); ){
		for(int i = 0; i < r; ++i){
			fgets(pz[i], 16, stdin);
			for(int j = 0; j < c; ++j) hv[i][j] = vv[i][j] = 0;
		}
		if(p) putc(10, stdout);
		printf("puzzle #%d:\n", ++p);
		printf("Across\n");
		for(int cnt = 0, i = 0; i < r; ++i)
			for(int j = 0, k; j < c; ++j){
				cnt += eligible(i, j);
				if(pz[i][j] == '*' || hv[i][j]) continue;
				printf("%3d.", cnt);
				for(k = j; k < c; ++k){
					if(pz[i][k] == '*'){ putc(10, stdout); break; }
					hv[i][k] = 1;
					putc(pz[i][k], stdout);
				}
				if(k == c) putc(10, stdout);
			}
		printf("Down\n");
		for(int cnt = 0, i = 0; i < r; ++i)
			for(int j = 0, k; j < c; ++j){
				cnt += eligible(i, j);
				if(pz[i][j] == '*' || vv[i][j]) continue;
				printf("%3d.", cnt);
				for(k = i; k < r; ++k){
					vv[k][j] = 1;
					if(pz[k][j] == '*'){ putc(10, stdout); break; }
					putc(pz[k][j], stdout);
				}
				if(k == r) putc(10, stdout);
			}
	}
	return 0;
}

