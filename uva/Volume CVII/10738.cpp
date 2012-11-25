#include <cstdio>

const int MAX = 1048576, ROOT = 1024;
bool p[MAX], sqf[MAX];
int pfc[MAX], mu[MAX], M[MAX];

int main(void){
	for(int i = 0; i < MAX; ++i){
		p[i] = sqf[i] = true;
		pfc[i] = 0;
	} 
	for(int i = 2; i < MAX; i += 2){
		p[i] = false;
		++pfc[i];
		sqf[i] = !!(i & 3);
	}
	for(int i = 3; i < MAX; i += 2) if(p[i]){
		if(i < ROOT) for(int j = i * i, k = j; j < MAX; j += k) sqf[j] = false;
		for(int j = i; j < MAX; j += i){
			p[j] = false;
			++pfc[j];
		}
	}
	M[1] = pfc[1] = mu[1] = 1;
	for(int i = 2; i < MAX; ++i){
		mu[i] = sqf[i] ? !(pfc[i] & 1) - (pfc[i] & 1) : 0;
		M[i] = M[i - 1] + mu[i];
	}

	for(int n; scanf("%d", &n) == 1 && n; printf("%8d%8d%8d\n", n, mu[n], M[n]));

	return 0;
}

