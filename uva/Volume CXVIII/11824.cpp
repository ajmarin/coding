#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int v[128];
int main(void){
	int n, t; scanf("%d", &t);
	while(t--){
		double s = 0;
		for(n = 0; scanf("%d", &v[n]) == 1 && v[n]; ++n);
		sort(v, v + n);
		for(int i = n; i--; ){
			s += pow((double)v[i], (double)n - i);
			if(s > 2500000) break;
		}
		if(s > 2500000) puts("Too expensive");
		else printf("%.0lf\n", 2 * s);
	}
	return 0;
}

