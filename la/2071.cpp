#include <cstdio>
#include <algorithm>

using namespace std;

int F, S, W;

int f[100];
int p[1000];

int main(void){
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; f[i - 1] < 100000000; ++i) f[i] = f[i - 1] + f[i - 2];
	while(scanf("%d %d %d", &W, &F, &S) && W){
		for(int i = 0; i < W; ++i){
			scanf("%d", &p[i]);
			int j;
			for(j = 0; f[j] < p[i]; ++j);
			p[i] = f[j] - p[i];
		}
		sort(p, p + W);
		int k, x;
		for(k = x = 0; k < F && x < W; ++x){
			k += p[x];
		}
		x -= k > F;
		printf("%d\n",x);
	}

	return 0;
}

