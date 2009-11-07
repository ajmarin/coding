#include <cstdio>

int t[1001];
int main(void){
	for(int i = 1; i < 1001; ++i) t[i] = 1;
	for(int i = 2; i < 1001; ++i){
		if(t[i] == 1){
			int k, x = i - 1;
			for(int j = i; j < 1001; j+=i){
				t[j] *= x;
				k = j / i;
				while(!(k % i)) t[j] *= i, k /= i;
			}
		}
		t[i] += t[i-1];
	}
	int T, N;
	scanf("%d",&T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d",&N);
		printf("%d %d %d\n",++cnum,N,(t[N] << 1) + 1);
	}
	return 0;
}

	

