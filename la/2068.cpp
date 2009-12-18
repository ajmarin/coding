#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int PP = 12;
const int NN = 10;
const int TT = 300;
const int RR = 1000;
int pv[PP];
bool solved[TT][PP];

struct team{
	int n, s;
	bool operator<(const team x) const {
		return s > x.s || (s == x.s && n < x.n);
	}
} t[TT];
int main(void){
	int N, P, R, T;
	while(scanf("%d %d %d %d", &N, &P, &T, &R) && N){
		memset(solved,0,sizeof(solved));
		for(int i = 0; i < T; ++i){
			t[i].n = i + 1;
			t[i].s = 0;
		}
		for(int i = 0; i < P; ++i)
			scanf("%d", &pv[i]);
		for(int i = 0; i < R; ++i){
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			--a, --b;
			if(d == 0 && !solved[a][b]){
				t[a].s += pv[b];
				solved[a][b] = 1;
			}
		}
		sort(t, t + T);
		int max_s = t[0].s;
		printf("Contest %d Winner: Team %d", N, t[0].n);
		for(int i = 1; i < T && t[i].s == max_s; ++i)
			printf(" and Team %d", t[i].n);
		putc(10, stdout);
	}
	return 0;
}
