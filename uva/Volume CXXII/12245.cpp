#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 100000000;
const int NN = 100;
struct interval {
	int b, e;
	bool operator<(const interval x) const {
		return b < x.b || (b == x.b && e < x.e);
	}
} t[NN];
int ans, r[NN][NN];
int main(void){
	for(int m, n; scanf("%d %d", &m, &n) == 2 && (m || n); ){
		ans = 0;
		for(int i = 0; i < n; ++i){
			memset(r[i], 0, n << 2);
			scanf("%d %d", &t[i].b, &t[i].e); 
		}
		sort(t, t + n);
		for(int i = 0; i < n; ++i){
			r[i][i] = t[i].b == 0;
			if(t[i].e != m){
				for(int j = i + 1; j < n; ++j)
					if(t[j].b > t[i].b && t[j].b <= t[i].e && t[j].e > t[i].e){
						for(int k = 0; k <= i; ++k)
							if(r[i][k] && !r[j][k]) r[j][i] = (r[j][i] + r[i][k]) % MOD;
					}
			} else for(int j = 0; j <= i; ++j)
				if(r[i][j]) ans = (ans + r[i][j]) % MOD;
		}
		printf("%d\n", ans);
	}
}

