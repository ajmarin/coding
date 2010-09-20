#include <cstdio>

const char *ans[2] = {"N", "S"};
inline int sqr(int x){ return ((x) * (x));}
int main(void){
	bool fit;
	int H, L, R1, R2;
	int S[3];
	while(scanf("%d %d %d %d", &L, &H, &R1, &R2) && L){
		fit = 1;
		S[0] = R1 + R1;
		S[1] = R1 + R2;
		S[2] = R2 + R2;
		for(int i = 0; i < 3; ++i)
			fit &= !(L < S[i] || H < S[i]);
		if(!fit) puts("N");
		else {
			int a = L - S[1], b = H - S[1];
			fit &= sqr(a) + sqr(b) >= sqr(S[1]);
			puts(ans[fit]);
		}
	}
	return 0;
}

