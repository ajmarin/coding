#include <cstdio>
bool prime[1024];
int p[100], pc = 0;
int main(void){
	setvbuf(stdin, NULL, _IONBF, NULL);
	for(int i = 0; i < 1024; ++i) prime[i] = 1; p[pc++] = 2;
	for(int i = 4; i < 1024; i += 2) prime[i] = 0;
	for(int i = 3; i < 33; i += 2)
		if(prime[i]){
			p[pc++] = i;
			for(int j = i * i; j < 1024; j += i) prime[j] = 0;
		}
	for(int i = 33; i < 1024; i += 2) if(prime[i]) p[pc++] = i;
	int c, i, k, n; scanf("%d %d", &n, &k);
	for(c = i = 0; p[i] + p[i + 1] < n; ++i) c += prime[p[i] + p[i + 1] + 1];
	puts(c < k ? "NO" : "YES");
	return 0;
}
