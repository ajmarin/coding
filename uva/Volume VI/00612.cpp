#include <cstdio>
#include <algorithm>

using namespace std;

struct DNA { 
	int n, s; char c[256];
	bool operator<(const DNA x) const { 
		return (s < x.s) || (s == x.s && n < x.n);
	}
} dna[100];
int oc[4][55];
char map[128];

int main(void){
	int K, N, T;
	scanf("%d",&T);
	map['A'] = 0; map['C'] = 1; map['G'] = 2; map['T'] = 3;
	while(T--){
		scanf("%d%d\n",&K,&N);
		for(int i = 0; i < N; ++i){
			oc[0][K] = oc[1][K] = oc[2][K] = 0;
			fgets(dna[i].c, 256, stdin);
			for(int j = K, k = K; j--; k--){
				oc[0][j] = oc[0][k];
				oc[1][j] = oc[1][k];
				oc[2][j] = oc[2][k];
				++oc[map[dna[i].c[j]]][j];
			}
			dna[i].s = 0;
			dna[i].n = i;
			for(int j = 0; j < K; ++j)
				for(int k = 0; k < map[dna[i].c[j]]; ++k)
					dna[i].s += oc[k][j];
		}
		sort(dna, dna + N);
		for(int i = 0; i < N; ++i) fputs(dna[i].c, stdout);
		if(T) putc(10, stdout);
	}
	return 0;
}

