#include <cstdio>
#include <cstdlib>

int v[4] = {0, 100, 20100, 2020100};
int k[4] = {2, 3, 5, 7};

int f(int k){
	if(k < 101) return  2 * k;
	if(k < 10001) return 3 * k - 100;
	if(k < 1000001) return 5 * k - 20100;
	return 7 * k - 2020100;
}

int g(int k){
	if(k < 201) return k / 2;
	if(k < 29901) return (k + 100) / 3;
	if(k < 4979901) return (k + 20100) / 5;
	return (k + 2020100) / 7;
}

int main(void){
	int ans, A, B, G;
	bool found;
	while(scanf("%d%d",&A,&B) && A){
		found = 0;
		G = g(A);
		for(int c1 = 0; !found && c1 < 4; ++c1)
			for(int c2 = 4; c2--; ){
				int n = (v[c1] - v[c2] + k[c2] * G - B);
				if(n < 0) continue;
				int d = (k[c1] + k[c2]);
				int c1 = n / d, c2 = G - c1;
				if(abs(f(c1) - f(c2)) == B){
					ans = c1;
					found = 1;
					break;
				}
			}
		printf("%d\n", f(ans));
	}
	return 0;
}

