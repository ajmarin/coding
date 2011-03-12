#include <algorithm>
#include <cstdio>
const int K = 52, M = 5000000, MAXVAL = 100048, N = 10001;
int f[K][N], LIM = 0;
int map[MAXVAL], seq[N], v[N];
int read(int *b, int x){
	int sum = 0;
	for(; x; x -= (x & -x)) if((sum += b[x]) >= M) sum -= M;
	return sum;
}
void update(int *b, int x, int v){
	for(; x < LIM; x += (x & -x)) if((b[x] += v) >= M) b[x] -= M;
}
int main(void){
	int k, n, t, z;
	scanf("%d %d", &n, &k);
	/* Read all numbers in the sequence, then sort */
	for(int i = 0; i < n; ++i) scanf("%d", seq + i), v[i] = seq[i];
	std::sort(seq, seq + n);
	/* Remap numbers to a smaller range (1..10k) */
	map[seq[0]] = ++LIM;
	for(int i = 1; i < n; ++i)
		if(seq[i] == seq[i - 1]) map[seq[i]] = LIM;
		else map[seq[i]] = ++LIM;
	/* Run the algorithm O(N*K*log(N)) */
	++LIM;
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
	printf("%d\n", read(f[k], LIM - 1));
	return 0;
}

