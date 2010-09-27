#include <algorithm>
#include <cmath>
#include <cstdio>
#define EPS 1e-6
using namespace std;
int x[1024], y[1024];
char line[1024];
double f[1024];
int main(void){
	int a, b, n;
	for(scanf("%d", &n); n--; ){
		int maxinline = 0, pc = 0;
		for(pc = 0; fgets(line, 1024, stdin); ){
			if(sscanf(line, "%d %d", &x[pc], &y[pc]) == 2) pc++;
			else if(pc != 0) break;
		}
		for(int i = 0; i < pc; ++i){
			int fc = 0, c = 0;
			if(pc - i <= maxinline) break;
			for(int j = i + 1; j < pc; ++j)
				if(x[j] - x[i])	f[fc++] = (y[j] - y[i])/(double)(x[j] - x[i]);
				else c++;
			sort(f, f + fc);
			for(int j = 0, k = 0; j < fc && k < fc;){
				while(k < fc && fabs(f[j] - f[k]) < EPS) k++;
				if(k - j > maxinline) maxinline = k - j;
				j = k;
			}
			maxinline = max(maxinline, c);
		}
		printf("%d\n", maxinline + 1);
		if(n) putc(10, stdout);
	}
	return 0;
}

