#include <cstdio>

#define NN 10032

int v[NN];
int main(void){
	int menor, H, L;
	int s, i;
	while(scanf("%d%d",&H,&L) && (H||L)){
		s =0;
		for(i = 0; i < L; i++){
			scanf("%d",&v[i]);
			if(i && v[i] == v[i-1]) i--, L--;
		}
		v[L] = H;
		menor = v[0];
		for(i = 1; i < L; i++)
			if(v[i] > v[i-1] && v[i] > v[i+1]){
				s += v[i] - menor;
				menor = H;
			} else if(v[i] < menor) menor = v[i];
		printf("%d\n",s+H-menor);
	}
	return 0;
}
