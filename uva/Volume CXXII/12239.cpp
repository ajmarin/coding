#include <cstdio>

bool cando[128];
int b[128];
int abs(int x){ return x < 0 ? -x : x; }
int main(void){
	for(int B, N; scanf("%d %d", &N, &B) == 2 && (N || B); ){
		int s = 1;
		for(int i = 0; i <= N; ++i) cando[i] = 0;
		for(int i = 0; i < B; ++i){
			scanf("%d", &b[i]);
			for(int j = 0; j < i; ++j){
				int diff = abs(b[i] - b[j]);
				s += !cando[diff];
				cando[diff] |= 1;
			}
		}
		if(s == N + 1) puts("Y");
		else puts("N");
	}
	return 0;
}

