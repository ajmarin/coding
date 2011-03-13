#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int K = 52, M = 5000000, N = 10001;
int f[K][N], r[K][N], LIM = 0;
int seq[N], v[N];
bool seen[N];
map < int, int > m;
int read(int *b, int x){
	if(b == f[0]) return 1;
	int sum = 0;
	for(; x; x -= (x & -x)) if((sum += b[x]) >= M) sum -= M;
	return sum;
}
void update(int *b, int x, int v){
	for(; x < N; x += (x & -x)) if((b[x] += v) >= M) b[x] -= M;
}
int main(void){
	int k, n, t, z;
	scanf("%d %d", &n, &k);
	memset(seen, 0, sizeof(seen));
	/* Read all numbers in the sequence, then sort */
	for(int i = 0; i < n; ++i) scanf("%d", seq + i), v[i] = seq[i];
	std::sort(seq, seq + n);
	/* Remap numbers to a smaller range (1..10k) */
	for(int i = 0; i < n; ++i) if(!m.count(seq[i])) m[seq[i]] = ++LIM;
	/* Run the algorithm O(N*K*log(N)) */
	for(int i = 0; i < n; ++i){
		z = m[v[i]];
		for(int L = 1; L <= k; ++L){
			int &x = r[L - 1][z - 1];
			t = read(f[L - 1], z - 1);
			if(t != x){
				int temp = t;
				if((t -= x) < 0) t += M;
				x = temp;
				update(f[L], z, t);
			}
		}
	}
	printf("%d\n", read(f[k], N));
	return 0;
}

