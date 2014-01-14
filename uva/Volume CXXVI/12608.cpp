#include <cstdio>

const int NN = 1024;
int d[NN], w[NN];

int main(void){
	int n; scanf("%d", &n);
	int at, cp, cw, td;
	for(int i = 0; i < n; ++i){
		int W, N; scanf("%d %d", &W, &N);
		for(int j = 0; j < N; ++j) scanf("%d %d", d + j, w + j);
		for(at = cp = cw = td = 0; cp < N; ){
			td += d[cp] - at; // move to next collection point
			at = d[cp]; // at collection point
			if(cw + w[cp] <= W){ // Truck can load weight at collection point
				cw = cw + w[cp++];
				if(cw == W){ td += at; at = 0; cw = 0; } // Rule #1: Truck is full, return
			} else { // Rule #2: Cannot load, return
				td += at; // Return to the dump
				at = 0; // at the dump
				cw = 0; // unload truck
			}
		}
		printf("%d\n", td + at);
	}
	return 0;
}

