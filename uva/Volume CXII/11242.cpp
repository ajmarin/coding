#include <algorithm>
#include <cstdio>
using namespace std;

int g[128], rg;
double v[1024];
int main(void){
	for(int f, r; scanf("%d %d", &f, &r) == 2; ){
		int vc = 0;
		double maxspread = 0;
		for(int i = 0; i < f; ++i) scanf("%d", &g[i]);
		for(int i = 0; i < r; ++i){
			scanf("%d", &rg);
			for(int j = 0; j < f; ++j) v[vc++] = rg / (double)g[j];
		}
		sort(v, v + vc);
		for(int i = 1; i < vc; ++i){
			double spread = v[i] / v[i - 1];
			if(spread > maxspread) maxspread = spread;
		}
		printf("%.2lf\n", maxspread);
	}
	return 0;
}

