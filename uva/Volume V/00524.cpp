#include <cstdio>

bool prime[32] = {0, 0, 1, 1, 0, 1, 0, 1,
				  0, 0, 0, 1, 0, 1, 0, 0,
				  0, 1, 0, 1, 0, 0, 0, 1,
				  0, 0, 0, 0, 0, 1, 0, 1};
bool used[17] = {0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0};
int n, v[16];
void bt(int k){
	if(k == n){
		if(!prime[v[0] + v[n - 1]]) return;
		putc('1', stdout);
		for(int i = 1; i < n; ++i) printf(" %d", v[i]);
		putc(10, stdout);
		return;
	}
	for(int i = 2 + !(k & 1); i <= n; i += 2){
		if(used[i] || !prime[i + v[k - 1]]) continue;
		used[i] = 1;
		v[k] = i;
		bt(k + 1);
		used[i] = 0;
	}
}

int main(void){
	v[0] = 1;
	for(int c = 0; scanf("%d", &n) == 1; ){
		if(c) putc(10, stdout);
		printf("Case %d:\n", ++c);
		bt(1);
	}
	return 0;
}

