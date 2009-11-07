#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define NN 10050

int v[NN];
int diff;
int sum[1000];
int main(void){
	int N, K, *s;
	while(scanf("%d",&N) && N){
		memset(sum, 0, sizeof(sum));
		for(int i = 0; i < N; ++i){
			scanf("%d",&K);
			for(int j = 0, *c = v;  j < K; ++j, c++) scanf("%d",c);
			sort(v, v + K);
			v[K] = 1001;
			s = sum;
			for(int j = 0, T = 0; j <= K; ++j){
				int diff = abs(j - (K - j)), x = *(v + j);
				while(T < x) *s++ += diff, T++;
			}
		}
		int k, min = 1 << 25;
		s = sum;
		for(int i = 0; i < 1001; ++i, s++){
			if(*s < min) min = *s;
		}
		printf("%d\n", min);
	}
	return 0;
}

