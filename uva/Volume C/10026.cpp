#include <algorithm>
#include <cstdio>

struct task {
	int a, b, n;
	bool operator<(const task x) const {
		int v1 = a * x.b, v2 = b * x.a;
		return (v1 < v2) || (v1 == v2 && n < x.n);
	}
} t[1000];

int main(void){
	int N, T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 0; i < N; ++i){
			t[i].n = i + 1;
			scanf("%d%d",&t[i].a,&t[i].b);
		}
		std::sort(t, t + N);
		for(int i = 0; i < N; ++i){
			if(i) putc(32, stdout);
			printf("%d",t[i].n);
		}
		putc(10, stdout);
		if(T) putc(10, stdout);
	}
	return 0;
}

