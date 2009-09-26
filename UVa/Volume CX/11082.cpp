/////////////////////////////////
// 11082 - Matrix Decompressing
/////////////////////////////////
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a<b)?(a):(b))
int cnum =0, cs, i, j, n, C, R;
int SL[50], m[50][50];
struct COL{
	int cap, cn;
} ;
COL SC[50];
bool ord(COL a, COL b){
	return (a.cap > b.cap);
}
void fill(int x, int y){
	m[x][SC[y].cn] = min(20,min(SL[x],SC[y].cap));
	SL[x] -= (m[x][SC[y].cn]-1);
	SC[y].cap -= (m[x][SC[y].cn]-1);
}
int main(void){
	scanf("%d",&cs);
	while(cs--){
		scanf("%d %d",&R,&C);
		/* INPUT */
		for(i = 0; i < R; i++) scanf("%d",&SL[i]);
		for(j = 0; j < C; j++) scanf("%d",&SC[j].cap), SC[j].cn = j;
		for(i = R; --i; ) SL[i] -= SL[i-1];
		for(j = C; --j; ) SC[j].cap -= SC[j-1].cap;
		for(i = 0; i < R; i++) SL[i] -= (C-1);
		for(j = 0; j < C; j++) SC[j].cap -= (R-1);
		/* ALGORITMO */
		for(i = 0; i < (R-1); i++){
			std::sort(SC,SC+C,ord);			
			for(j = 0; j < C; j++)
				fill(i,j);				
		}
		for(j = 0; j < C; j++){
			int k = SC[j].cn, L = 1;
			m[R-1][k] = SC[j].cap;
			if(m[R-1][k] > 20){
				int remain = m[R-1][k] - 20;
				while(m[R-1-L][k] > 20-remain) L++;
				m[R-1-L][k] += remain;
				m[R-1][k] -= remain;
				for(int A = 0; A < C; A++)
					if(A != k && m[R-1-L][A] > remain && m[R-1][A] < 21 - remain){
						m[R-1-L][A] -= remain;
						m[R-1][A] += remain;
						break;
					}
			}
		}
		/* OUTPUT */
		printf("Matrix %d\n",++cnum);
		for(i = 0; i < R; putchar('\n'),i++){
			printf("%d",m[i][0]);
			for(j = 1; j < C; j++) printf(" %d",m[i][j]);
		}
		putchar('\n');
	}
	return 0;
}