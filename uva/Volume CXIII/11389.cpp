#include <algorithm>
#include <cstdio>
using namespace std;

int y[128], z[128];
int main(void){
	for(int n, d, r; scanf("%d%d%d", &n, &d, &r) == 3 && n; ){
		int extra = 0, i, j, length;
		for(i = 0; i < n; ++i) scanf("%d", z + i);
		for(i = 0; i < n; ++i) scanf("%d", y + i);
		sort(y, y + n);
		sort(z, z + n);
		for(i = 0, j = n; j--; ++i){
			length = y[i] + z[j];
			if(length > d) extra += r * (length - d);
		}
		printf("%d\n", extra);
	}
	return 0;
}

