#include <cstdio>
#include <algorithm>

using namespace std;

#define NN 1024

int n;

struct T {
	int v;
	long long d;
};
long long d[NN][NN];
T t[NN][NN];
int nt[NN];
long long x[NN], y[NN];
bool comp(T a, T b){
	return a.d < b.d;
}
long long sqr(long long k){
	return (k * k);
}
int main(void){
	int i, j, k;
	while(scanf("%d",&n) && n){
		for(i = 0; i < n; ++i){
			scanf("%lld %lld", &x[i], &y[i]);
			nt[i] = 0;
		}
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				long long dist = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
				d[i][j] = d[j][i] = dist;
				t[i][nt[i]].v = j;
				t[i][nt[i]++].d = dist;
			}
			sort(t[i], t[i] + nt[i], comp);
		}
		int ans = 0;
		for(i = 0; i < n; ++i){
			for(j = 0; j < nt[i]; ++j){
				long long dist = t[i][j].d;
				for(k = j + 1; dist == t[i][k].d && k < nt[i]; ++k)
					if(d[t[i][j].v][t[i][k].v] != dist) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

