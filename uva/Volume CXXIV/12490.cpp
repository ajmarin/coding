#include <algorithm>
#include <cstdio>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)
#define FORI(i,s,n) for(int i = s; i < n; ++i)
const int N = 1048576;
int v[N], z[N];

int main(void){
	for(int n, m, s; scanf("%d %d %d", &n, &m, &s) == 3; ){
		double min_area = 0, max_area = 0;
		double dist;
		int x, f;
		FOR(i, m){
			scanf("%d %d", &x, &f);
			v[z[i] = x] = f;
		}
		sort(z, z + m);
		FORI(i, 1, m){
			dist = abs(v[z[i]] - v[z[i - 1]]);
			double x = min(v[z[i - 1]], v[z[i]]) * double(z[i] - z[i - 1]) + dist * .5;
			min_area += x;
			max_area += x + dist * (z[i] - z[i - 1] - 1);
		}
		if(int(min_area) == min_area && min_area <= s && s <= max_area){
			int d, mod, r = s - min_area, up;
			for(int i = m - 2; i >= 0 && r >= 0; --i){
				if(z[i + 1] == z[i] + 1) continue;
				if(v[z[i + 1]] >= v[z[i]]){
					d = v[z[i + 1]] - v[z[i]]; 
					for(int j = z[i + 1] - 1; j > z[i]; --j){
						up = min(d, r);
						v[j] = v[z[i]] + up;
						r -= up;
					}
				} else {
					d = v[z[i]] - v[z[i + 1]];
					up = min(r / (z[i + 1] - z[i] - 1), d);
					mod = r % (z[i + 1] - z[i] - 1);
					FORI(j, z[i] + 1, z[i + 1]){
						v[j] = v[z[i + 1]] + up;
						r -= up;
						if(up < d && (j - z[i] - 1) < mod) ++v[j], --r;
					}
				}
			}
			printf("S");
			FOR(i, m - 1) FORI(j, z[i] + 1, z[i + 1]) printf(" %d", v[j]);
			puts("");
		} else puts("N");

	}
	return 0;
}

