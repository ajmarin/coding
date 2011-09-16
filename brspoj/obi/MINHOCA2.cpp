#include <cstdio>
#define max(a,b) ((a<b)?(b):(a))
int m[1000][4];
int main(void){
	int c, i, j, r;
	for(int t = 1; scanf("%d%d",&r,&c) && r; t++){
		for(i = 0; i < c; i++){
			scanf("%d",&m[i][0]);
			if(i) m[i][1] = m[i-1][1] + m[i][0];
			else m[i][1] = m[i][0];
		}
		for(i = 1; i < r; i++){
			for(j = 0; j < c; j++)	scanf("%d",&m[j][0]);		
			m[0][2] = m[0][1] + m[0][0];
			for(j = 1; j < c; j++)
				m[j][2] = max(m[j][1],m[j-1][2]) + m[j][0];
			m[c-1][3] = m[c-1][1] + m[c-1][0];
			for(j = c-1; j--; )
				m[j][3] = max(m[j][1],m[j+1][3]) + m[j][0];
			for(j = 0; j < c; j++)
				m[j][1] = max(m[j][2],m[j][3]);
		}
		printf("Teste %d\n%d\n\n",t,m[c-1][1]);
	}
	return 0;
}
