#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int x[128], y[128];
double s[128];
int main(void){
	int dset = 1, lx, ly, n, rx, ry, t;
	for(scanf("%d", &t); t--; dset++){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d.%d %d.%d", &lx, &rx, &ly, &ry);
			x[i] = 100 * lx + rx;
			y[i] = 100 * ly + ry;
			for(int j = 0; j < i; ++j)
				if(x[j] == x[i] && y[j] == y[i]){ i--; n--; break; }
		}
		int maxaligned = 0;
		for(int i = 0; i < n; ++i){
			int c = 0, sc = 0;
			for(int j = i + 1; j < n; ++j){
				if(x[j] - x[i]) s[sc++] = (y[j] - y[i])/(double)(x[j] - x[i]);
				else c++;
			}
			sort(s, s + sc);
			for(int j = 0, k = 0; j < sc && k < sc; ){
				while(k < sc && fabs(s[k] - s[j]) < 1e-9) k++;
				if(k - j > maxaligned) maxaligned = k - j;
				j = k;
			}
			if(c > maxaligned) maxaligned = c;
		}
		printf("Data set #%d contains ", dset);
		if(n == 1) printf("a single gnu.\n", dset);
		else printf("%d gnus, out of which a maximum of %d are aligned.\n", n, maxaligned + 1);
	}
	return 0;
}

