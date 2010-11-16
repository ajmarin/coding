#include <cstdio>
#include <cstring>

const int NN = 10;
int hd[NN][NN], ss[NN], vd[NN][NN];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	bool any;
	int line, col;
	char type[16];
	for(int m, n, p = 0; scanf("%d %d", &n, &m) == 2; ){
		any = 0;
		for(int i = 0; i < NN; ++i){
			ss[i] = 0;
			for(int j = 0; j < NN; ++j) hd[i][j] = vd[i][j] = 0;
		}
		for(int i = 0; i < m; ++i){
			scanf("%s %d %d", type, &line, &col);
			--line; --col;
			if(type[0] == 'H') hd[line][col] = 1;
			else vd[col][line] = 1;
		}
		for(int i = n; i--; )
			for(int j = n; j--; ){
				if(hd[i][j]) hd[i][j] += hd[i][j + 1];
				if(vd[i][j]) vd[i][j] += vd[i + 1][j];
			}
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				int lim = min(hd[i][j], vd[i][j]);
				for(int k = 1; k <= lim; ++k)
					ss[k] += hd[i + k][j] >= k && vd[i][j + k] >= k;
			}
		if(p) puts("\n**********************************\n");
		printf("Problem #%d\n\n", ++p);
		for(int i = 1; i <= n; ++i)
			if(ss[i]){
				printf("%d square (s) of size %d\n", ss[i], i);
				any = 1;
			}
		if(!any) puts("No completed squares can be found.");
	}
	return 0;
}

