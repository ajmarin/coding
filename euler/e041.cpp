#include <cmath>
#include <cstdio>
#include <ctime>

int ans = 0, pan;
bool used[10];
bool prime(int k){
	if(!(k & 1)) return 0;
	for(int i = 3; i < k; i += 2){
		if(i * i > k) return 1;
		if(!(k % i)) return 0;
	}
}
void b(int u, int n){
	if(u == pan && prime(n)){ ans = n; return; }
	for(int i = pan; i; i--){
		if(!used[i]){
			used[i] = 1;
			b(u + 1, n * 10 + i);
			if(ans) return;
			used[i] = 0;
		}
	}
}
int main(void){
	clock_t ini = clock();
	for(int i = 9; !ans && i > 1; --i) pan = i, b(0, 0);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

