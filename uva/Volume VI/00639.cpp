#include <cstdio>

char b[32][32], bm[32], maxr, n, n2p;
char count[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
void dorow(char r, char cm, char c){
	char ncm = cm & bm[r];
	if(r == n){
		if(c > maxr) maxr = c;
		return;
	}
	for(char m = 0; m < n2p; ++m){
		if(m & cm) continue;
		bool ok = 1; char s = 0;
		for(char j = 0; ok && j < n; ++j){
			bool pc = ((1 << j) & m);
			ok &= !(pc & b[r][j]);
			s += pc;
			s -= b[r][j];
			ok &= (s < 2);
		}
		if(ok && s < 2) dorow(r + 1, ncm | m, c + count[m]);
	}
}
int main(void){
	for( ; scanf("%d\n", &n) && n; ++n){
		n2p = 1 << n; maxr = 0;
		for(char i = 0; i < n; ++i){
			bm[i] = 0;
			for(char j = n; j--; ){
				b[i][j] = getc( stdin ) == 'X';
				bm[i] |= (!b[i][j] << j);
			}
			getc( stdin );
		}
		dorow(0, 0, 0);
		printf("%d\n", maxr);
	}
	return 0;
}

