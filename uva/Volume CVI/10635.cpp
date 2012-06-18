#include <algorithm>
#include <cstdio>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)
#define FORI(i,s,n) for(int i = s; i < n; ++i)

const int NN = 1 << 16;
int n, p, q;
int index[NN], x[NN], y[NN], z[NN];

int main(void){
	int t; scanf("%d", &t);
	for(int c = 0; c++ < t; ){
		scanf("%d %d %d", &n, &p, &q);
		++p; ++q;
		FOR(i, n*n) index[i + 1] = -1;
		FOR(i, p){
			scanf("%d", x + i);
			index[x[i]] = i;
		}
		FOR(j, q){
			scanf("%d", y + j);
			y[j] = index[y[j]];
		}
		int top = 0;
		FOR(j, q){
			if(top == -1 || y[j] > z[top]){
				z[++top] = y[j];
			} else {
				int low = 0, high = top, mid;
				while(low < high){
					mid = (low + high) >> 1;
					if(y[j] > z[mid]) low = mid + 1;
					else high = mid;
				}
				if(y[j] < z[low]) z[low] = y[j];
			}
		}
		printf("Case %d: %d\n", c, top + 1);
	}
	return 0;
}

