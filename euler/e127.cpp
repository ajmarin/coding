#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
typedef long long LL;
const int LRT = 347, MAX = 120000;
int r[MAX], p[MAX], pc = 0;
int io[MAX];
void eratosthenes(){
	for(int i = 0; i < MAX; ++i) r[i] = 1, io[i] = i;
	r[0] = 1<<30; r[1] = 1; p[pc++] = 2;
	for(int i = 2; i < MAX; i += 2)	r[i] <<= 1;
	for(int i = 3; i < MAX; i += 2)
		if(r[i] == 1){
			//printf("%d is prime\n", i);
			p[pc++] = i;
			for(int j = i; j < MAX; j += i) r[j] *= i;
		}
}
bool cmp(int a, int b){ return r[a] < r[b] || (r[a] == r[b] && a < b);}
uint gcd(uint a, uint b){ return b ? gcd(b, a % b) : a; }
int main(void){
	clock_t ini = clock();
	LL ans = 0;
	eratosthenes();
	printf("Sieve time: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	const int LM = MAX;
	std::sort(io + 1, io + LM, cmp);
	for(int i = 1; i < LM; ++i){
		int a = io[i], ra = r[a];
		for(int j = i + 1; j < LM; ++j){
			int b = io[j], rb = r[b];
			if(rb > (LM >> 1) / ra) break;
			if(a + b >= LM) continue;
			int c = a + b;
			if(c / r[c] > ra * rb && gcd(ra, rb) == 1) ans += c;
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
