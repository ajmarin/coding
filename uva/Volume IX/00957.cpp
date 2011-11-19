#include <cstdio>

const int NN = 100048;
int p[NN];

int main(void){
	for(int b, n, y, z; scanf("%d %d", &y, &n) == 2; ){
		for(int i = 0, l = z = 0; i < n; ++i){
			scanf("%d", p + i);
			while(p[i] - p[l] >= y) ++l;
			if(i - l > z){
				z = i - l;
				b = l;
			}
		}
		printf("%d %d %d\n", z + 1, p[b], p[b + z]);
	}
	return 0;
}

