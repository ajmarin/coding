#include <cstdio>

const int LIM = 1048576, ROOT = 1024;
bool p[LIM];
int pL[LIM >> 3], pLC = 0;
int fL[16][2], fC;

int main(void){
	for(int i = 2; i < LIM; ++i) p[i] = i & 1;
	p[2] = true;
	for(int i = 3; i < ROOT; ++i) if(p[i]){
		for(int j = i * i, k = i << 1; j < LIM; j += k)
			p[j] = false;
	}
	for(int i = 2; i < LIM; ++i) if(p[i]) pL[pLC++] = i;
	for(int n, z; scanf("%d", &n) == 1 && n; ){
		int ans = fC = 0;
		z = n;
		for(int i = 0; i < pLC && pL[i] <= n / pL[i]; ++i) if(!(n % pL[i])){
			fL[fC][0] = pL[i];
			fL[fC][1] = 0;
			do { n /= pL[i]; fL[fC][1]++; } while(!(n % pL[i]));
			fC++;
		}
		if(n != 1) fL[fC][0] = n, fL[fC++][1] = 1;
		for(int i = 0; i < fC; ++i){
			int tmp = fL[i][1];
			for(int j = i + 1; j < fC; ++j)
				tmp *= (fL[j][1] << 1) + 1;
			ans += tmp;
		}
		printf("%d %d\n", z, ++ans);
	}

	return 0;
}

