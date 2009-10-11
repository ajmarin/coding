#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define NN 10032

int v[NN];
int found[NN];

int main(void){
	int cnum = 0, l, r, x, N, Q;
	while(scanf("%d%d",&N,&Q) && N){
		for(int i = 0; i < N; ++i) scanf("%d",&v[i]);
		memset(found, 0, sizeof(found));
		sort(v, v + N);
		printf("CASE# %d:\n",++cnum);
		for(int i = 0; i < Q; ++i){
			scanf("%d",&x);
			if(!found[x]){
				for(l = 0, r = N-1; l < r; ){
					int c = (l + r) >> 1;
					if(v[c] >= x) r = c; else l = c + 1;
				}
				if(v[l] == x){
					found[x] = l+1;
					printf("%d found at %d\n",x,found[x]);
				} else printf("%d not found\n",x);
			} else printf("%d found at %d\n",x,found[x]);
		}
	}
	return 0;
}

