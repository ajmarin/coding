#include <cstdio>
#include <algorithm>

using namespace std;

struct value {
	int m, v;
	bool operator<(const value k) const{
		if(m == k.m){
			if(v & 1){
				if(k.v & 1) return v > k.v;
				return 1;
			} else if(k.v & 1) return 0;
			return v < k.v;
		}
		return m < k.m;
	}
} v[10098];

int main(void){
	int M, N;
	while(scanf("%d %d", &N, &M) && N){
		for(int i = 0; i < N; ++i) scanf("%d",&v[i].v), v[i].m = v[i].v % M;
		sort(v, v + N);
		printf("%d %d\n", N, M);
		for(int i = 0; i < N; ++i) printf("%d\n", v[i].v);
	}
	puts("0 0");
	return 0;
}

