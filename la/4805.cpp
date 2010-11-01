#include <cctype>
#include <cstdio>
#define NN 100048
int P[NN][17], L[NN];
long long W[NN];
#define MAX 1048576
char buf[MAX], *lim = buf + MAX, *now = lim;
void adapt(){
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
}
void readint(int &n){	
	adapt();
	n = 0;	
	while(isdigit(*now)) n = n * 10 + *now++ - '0';
}
void readll(long long int &n){
	adapt();
	n = 0;	
	while(isdigit(*now)) n = n * 10 + *now++ - '0';
}
int query(int p, int q) {
	int log, i;
	if (L[p] < L[q]) p ^= q ^= p ^= q;
	for (log = 1; 1 << log <= L[p]; log++);
	log--;
	for (i = log; i >= 0; i--)
		if (L[p] - (1 << i) >= L[q])
			p = P[p][i];
	if (p == q) return p;
	for (i = log; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];

	return P[p][0];
}
int main(void){
	int a, b, N, q;
	for(readint(N); N; readint(N)){
		long long w;
		P[0][0] = -1; L[0] = W[0] = 0;
		for(int i = 1; i < N; ++i){
			readint(a), readll(w);
			for(int j = 0; (1 << j) < N; ++j) P[i][j] = -1;
			P[i][0] = a;
			L[i] = L[a] + 1;
			W[i] = W[a] + w;
		}
		for(int j = 1; (1 << j) < N; ++j)
			for(int i = 0; i < N; ++i)
				if(P[i][j - 1] != -1)
					P[i][j] = P[P[i][j - 1]][j - 1];
		readint(q);
		while(q--){
			readint(a), readint(b);
			printf("%lld", W[a] + W[b] - (W[query(a, b)] << 1));
			if(q) putc(32, stdout);
		}
		putc(10, stdout);
	}
	return 0;
}

