#include <cstdio>
const int MAX = 1000000, RTM = 1000;
bool prime[MAX];
int pl[15001], pc = 1;
int main(void){
	pl[pc++] = 2;
	for(int i = 0; i < MAX; ++i) prime[i] = 1;
	for(int i = 4; i < MAX; i += 2) prime[i] = 0;
	for(int i = 3; i < MAX; i += 2)
		if(prime[i]) {
			pl[pc++] = i;
			if(pc == 15001) break;
			if(i > RTM) continue;
			for(int j = i*i, k = i<<1; j < MAX; j += k) prime[j] = 0;
		}
	for(int k, n; scanf("%d", &k) == 1; )
		while(k--){
			scanf("%d", &n);
			printf("%d\n", pl[n]);
		}
	return 0;
}

