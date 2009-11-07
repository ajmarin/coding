#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define FOR(a,b) for(int a = 0; a < b; ++a)
#define FORI(a, b, c) for(int a = b; a < c; ++a)

int p[20];
char m[(1<<20)][8];
int A, pot2[25];
int main(void){
	int sum, a, max, N;
	scanf("%d",&N);
	pot2[0] = 1;
	FORI(i, 1, 25) pot2[i] = pot2[i-1]<<1;
	while(N--){
		scanf("%d",&A);
		memset(m, 0x6f, sizeof(m));
		FOR(i, A) scanf("%d",&p[i]);
		m[0][0] = 0;
		int LS = 1 << A;
		FORI(i, 1, LS){
			int x = i, pill_idx = 0;
			while(x){
				if(x&1){
					int wopill = i ^ pot2[pill_idx];
					FORI(old, 0, 8){
						int stub = MAX(p[pill_idx] - old - 1, 0);
						m[i][stub] = MIN(m[i][stub], m[wopill][old] + stub + 1);
					}
				}
				x = x >> 1;
				pill_idx++;
			}
		}
		int ans = 90;
		FORI(i, 0, 8) ans = MIN(ans, m[LS-1][i]);
		printf("%d\n", ans);
	}
}

