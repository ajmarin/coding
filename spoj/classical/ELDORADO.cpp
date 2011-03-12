#include <algorithm>
#include <cstdio>
typedef long long LL;
const int K = 128, MAXVAL = 20048, N = 128;
long long f[K][N], LIM = 0;
int map[MAXVAL], seq[N], v[N];
LL read(LL *b, int x){
	LL sum = 0;
	for(; x; x -= (x & -x)) sum += b[x];
	return sum;
}
void update(LL *b, int x, LL v){
	for(; x < N; x += (x & -x)) b[x] += v;
}
int main(void){
	for(int k, n, z; scanf("%d %d", &n, &k) && (n || k); ){
		LL t;
		for(int i = 0; i <= k; ++i)
			for(int j = 0; j <= N; ++j)
				f[i][j] = 0;
		/* Read all numbers in the sequence, then sort */
		for(int i = 0; i < n; ++i) scanf("%d", seq + i), seq[i] += 10001, v[i] = seq[i];
		std::sort(seq, seq + n);
		/* Remap numbers to a smaller range (1..100) */
		LIM = 0;
		map[seq[0]] = ++LIM;
		for(int i = 1; i < n; ++i)
			if(seq[i] == seq[i - 1]) map[seq[i]] = LIM;
			else map[seq[i]] = ++LIM;
		/* Run the algorithm O(N*K*log(N)) */
		for(int i = 0; i < n; ++i){
			z = map[v[i]];
			/* Any number can start an increasing sequence */
			update(f[1], z, 1);
			for(int L = 2; L <= k; ++L)
				/* 
				** Any increasing sequence of size L - 1 with last number
				** smaller than z can be extended to a sequence of size L
				**/
				if(t = read(f[L - 1], z - 1)) update(f[L], z, t);
		}
		printf("%lld\n", read(f[k], N - 1));
	}
	return 0;
}

