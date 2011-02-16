#include <algorithm>
#include <cstdio>
using namespace std;
int x[1024], y[1024];
int main(void){
	int n, t, v; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		v = 0;
		for(int i = 0; i < n; ++i) scanf("%d", x + i);
		for(int i = 0; i < n; ++i) scanf("%d", y + i);
		sort(x, x + n);
		sort(y, y + n);
		for(int i = 0; i < n; ++i) v += x[i] * y[i];
		printf("%d\n", v);
	}
	return 0;
}
