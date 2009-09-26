#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

struct city {
	int x, y, cmed;
}c[1000];
bool ord(city a, city b){
	return (a.cmed < b.cmed);
}
int main(void){
	int i, N, tp, tx, ty;
	bool first; 
	for(int cnum = 1; scanf("%d",&N) && N != 0; cnum++){
		for(i = tx = ty = 0; i < N; i++){
			scanf("%d%d",&c[i].x,&c[i].y);
			c[i].cmed = c[i].y/c[i].x;
			tx += c[i].x;
			ty += c[i].y;
		}
		sort(c,c+N,ord);
		printf("Cidade# %d:\n",cnum);
		first = true;
		for(i = 0; i < N; i++){
			tp = 0;
			while(i < N-1 && c[i+1].cmed == c[i].cmed){
				tp += c[i].x;
				i++;				
			}
			tp += c[i].x;
			if(!first) putchar(' ');
			printf("%d-%d",tp,c[i].cmed);
			first = false;
		}
		putchar('\n');
		double k = floor(100*ty/((double)tx))/100.;
		printf("Consumo medio: %.2lf m3.\n", k);
		putchar('\n');
	}
	return 0;
}

