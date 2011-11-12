#include <cstdio>

#define LEFT(x) (2 * (x - d) + d + 1)
#define RIGHT(x) (2 * (x - d) + d + 2)
const int NN = 100048;
struct node {
	int left, right;
	long long hash;
} d[5 * NN];
long long bmodp[NN];
long long B, P;

int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }

void init_node(int left, int right, node* n = d){
	n -> left = left;
	n -> right = right;
	n -> hash = 0;
	if(left < right){
		int mid = (left + right) >> 1;
		init_node(left, mid, LEFT(n));
		init_node(mid+1, right, RIGHT(n));
	}
}

long long update(int pos, int val, node *n = d){
	if(pos < n -> left || pos > n -> right) return n -> hash;
	if(n -> left == pos && n -> right == pos) return n -> hash = val;
	long long hright = update(pos, val, RIGHT(n));
	long long hleft = update(pos, val, LEFT(n));
	int mid = (n -> left + n -> right) >> 1;
	int bpow = n -> right - mid;
	n -> hash = (hright + (bmodp[bpow] * hleft) % P) % P;
	return n -> hash;

}

long long query(int left, int right, node *n = d){
	if(right < n -> left || left > n -> right) return 0;
	if(left <= n -> left && right >= n -> right) return n -> hash;
	long long hright = query(left, right, RIGHT(n));
	long long hleft = query(left, right, LEFT(n));
	int mid = (n -> left + n -> right) >> 1;
	int bpow = max(min(right, n -> right) - mid, 0);
	long long r = (hright + (bmodp[bpow] * hleft) % P) % P;
	return r;
}

int main(void){
	char cmd[16];
	for(int L, N; scanf("%lld %lld %d %d", &B, &P, &L, &N) == 4 && B; ){
		init_node(1, L);
		bmodp[0] = 1;
		for(int i = 1; i <= L; ++i) bmodp[i] = (bmodp[i - 1] * B) % P;
		for(int a, b, i = 0; i < N; ++i){
			scanf("%s %d %d", cmd, &a, &b);
			if(cmd[0] == 'E') update(a, b);
			else printf("%lld\n", query(a, b));
		}
		puts("-");
	}
	return 0;
}

