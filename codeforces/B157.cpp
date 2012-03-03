#include <algorithm>
#include <cstdio>
#include <cmath>

const double pi = acos(-1);

int v[128];

int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		int area = 0;
		for(int i = 0; i < n; scanf("%d", v + i++));
		std::sort(v, v + n);
		for(int i = n, add = 1; i--; add = 1 - add){
			if(add) area += v[i] * v[i];
			else area -= v[i] * v[i];
		}
		printf("%.8lf\n", pi * area);
	}
	return 0;
}

