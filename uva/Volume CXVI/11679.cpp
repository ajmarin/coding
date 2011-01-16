#include <cstdio>

#define NN 32

int b, n;
int v[NN];

int main(void){
	int i;
	while(scanf("%d %d", &b, &n) && (b || n)){
		for(i = 0; i < b; i++) scanf("%d",&v[i]);
		for(i = 0; i < n; i++) {
			int d, c, val;
			scanf("%d %d %d", &d, &c, &val), d--, c--;
			v[d] -= val;
			v[c] += val;
		}
		for(i = 0; i < b; i++) if(v[i] < 0) break;
		printf("%c\n", i == b ? 'S': 'N');
	}
	return 0;
}
