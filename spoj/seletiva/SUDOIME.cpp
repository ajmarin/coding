#include <cstdio>
int main(void){
	int i, inst, j, NO, t, s, sq1, v;
	bool hl[9][10], hc[9][10], hs[9][10];
	scanf("%d",&t);
	for(inst = 1; inst <= t; inst++){
		printf("Instancia %d\n",inst);
		for(i = 0; i < 9; i++)
			for(j = 0; j < 9; j++)
				hl[i][j] = hc[i][j] = hs[i][j] = 0;
		for(i = 0; i < 9; i++){
			sq1 = 3*(i/3);
			for(j = 0; j < 9; j++){
				s = sq1 + j/3;
				scanf("%d",&v);
				if(v > 9) continue;
				hl[i][v] = 1;
				hc[j][v] = 1;
				hs[s][v] = 1;
			}
		}
		for(NO = i =0; !NO && i < 9; i++)
			for(j = 1; j < 10; j++)
				if(!hl[i][j] || !hc[i][j] || !hs[i][j]){
					NO = 1;
					break;
				}
		if(NO) puts("NAO\n");
		else puts("SIM\n");
	}
	return 0;
}
