#include <algorithm>
#include <cstdio>
using namespace std;

int v[2048];
int process(int n, bool show = false){
	int cost = 0, l;
	for(l = 0; l < n - 3; l += 2){
		if(v[0] + v[n - l - 2] < 2 * v[1]){
			if(show) 
				printf("%d %d\n%d\n%d %d\n%d\n", v[0], v[n-l-1], 
						v[0], v[0], v[n-l-2], v[0]);
			cost += 2*v[0] + v[n-l-1] + v[n-l-2];
		} else {
			if(show)
				printf("%d %d\n%d\n%d %d\n%d\n", v[0], v[1], v[0],
						v[n-l-2], v[n-l-1], v[1]);
			cost += 2*v[1] + v[0] + v[n-l-1];
		}
	}
	if(n - l == 1){
		if(show) printf("%d\n", v[0]);
		cost += v[0];
	} else if(n - l == 2){
		if(show) printf("%d %d\n", v[0], v[1]);
		cost += v[1];
	} else if(n - l == 3){
		if(show) printf("%d %d\n%d\n%d %d\n", v[0], v[2], v[0], v[0], v[1]);
		cost += v[0] + v[1] + v[2];
	}
	return cost;
}
int main(void){
	int T; scanf("%d", &T);
	for(int c = 0, n; c < T && scanf("%d", &n) == 1; c++){
		if(c) puts("");
		for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
		sort(v, v + n);
		printf("%d\n", process(n));
		process(n, true);
	}
	return 0;
}

