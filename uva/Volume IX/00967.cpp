#include <cstdio>

#define MAX 1000001
#define RT 1001
bool prime[MAX];
int c[20000], cc = 0;

bool circular_prime(int k){
	int d[10], dc = 0;
	while(k){
		d[dc] = k % 10;
		if(!(d[dc] & 1) || d[dc] == 5) return 0;
		dc++;
		k /= 10;
	}
	for(int pos = dc - 1; pos--; ){
		int number = 0;
		for(int c = 0; c < dc; ++c)
			number = number * 10 + d[(pos - c + dc) % dc];
		if(!prime[number]) return 0;
	}
	return 1;
}

int main(void){
	for(int i = 0; i < MAX; ++i) prime[i] = 1;
	prime[0] = prime[1] = 0;
	for(int i = 4; i < MAX; i += 2) prime[i] = 0;
	for(int i = 3; i < RT; i += 2)
		if(prime[i]) for(int j = i * i; j < MAX; j += i) prime[j] = 0;
	for(int i = 3; i < MAX; i += 2) if(prime[i] && circular_prime(i)) c[cc++] = i;
	for(int a, b; scanf("%d %d", &a, &b) == 2; ){
		int cnt = 0;
		for(int i = 0; i < cc; ++i) cnt += c[i] >= a && c[i] <= b;
		if(!cnt) puts("No Circular Primes.");
		else if(cnt == 1) printf("1 Circular Prime.\n");
		else printf("%d Circular Primes.\n", cnt);
	}
	return 0;
}
