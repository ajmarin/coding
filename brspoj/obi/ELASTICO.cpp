#include <cstdio>
#include <algorithm>
struct P {
	int x, y;
	P(int a, int b): x(a), y(b) {}
	P(): x(0),y(0) {}
	int operator*(P a){
		return x*a.y-y*a.x;
	}
	P operator-(P a){
		return P(x-a.x,y-a.y);
	}
} pts[256];
bool ord(P a, P b){
	return (a.x * b.y - a.y * b.x)<0;
}
int main(void){
	int i, j, k, max, n, v[256][256];
	
	for(int t = 1; scanf("%d",&n) && n++; t++){
		pts[0].x = pts[0].y = 0;
		v[0][0] = 1; max = 0;
		for(i = 1; i < n; i++)	scanf("%d%d",&pts[i].x,&pts[i].y);
		std::sort(&pts[1],&pts[n],ord);
		for(i = 1; i < n; i++){
			v[i][0] = 2; // Conecta cada ponto com a origem.
			for(j = 1; j < i; j++){
				v[i][j] = 0; // Ainda nao existe conexao entre o ponto i e os anteriores.
				for(k = 0; k < j; k++)
					if(v[i][j] < v[j][k] && ((pts[j]-pts[k])*(pts[i]-pts[j])) < 0)
						v[i][j] = v[j][k];
				if(++v[i][j] > max) max = v[i][j];
			}
		}
		printf("Teste %d\n%d\n\n",t,max);
	}
	return 0;
}
