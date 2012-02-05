#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef unsigned int UI;

vector<UI> sieve(UI limit){
	UI root = (UI) floor(sqrt(limit) + .5);
	vector <bool> is_prime(limit, true);
	vector <UI> primes;
	primes.push_back(2);
	for(UI i = 4; i < limit; i += 2) is_prime[i] = false;
	for(UI i = 3; i < root; i += 2){
		if(is_prime[i]) for(UI j = i * i, k = i<<1; j < limit; j += k) is_prime[j] = false;
	}
	for(UI i = 3; i < limit; i += 2)
		if(is_prime[i]) primes.push_back(i);
	return primes;
}

vector<UI> seg_sieve(UI lower, UI upper, vector<UI>&pl){
	vector<UI> primes;
	vector<bool> is_prime(upper - lower + 1, true);
	UI root = (UI) floor(sqrt(upper) + .5);
	for(UI i = 0; i < (UI)pl.size(); ++i){
		if(pl[i] > root) break;
		UI begin = max(pl[i] * pl[i], lower + (pl[i] - (lower % pl[i])) % pl[i]);
		for(UI j = begin; j <= upper; j += pl[i])
			is_prime[j - lower] = false;
	}
	for(UI i = lower; i <= upper; ++i)
		if(i > 1 && is_prime[i - lower])
			primes.push_back(i);
	return primes;
}
int main(void){
	vector<UI> pl = sieve(1 << 16), primes;
	for(UI L, U; scanf("%d %d", &L, &U) == 2; ){
		primes = seg_sieve(L, U, pl);
		UI sz = (UI) primes.size();
		if(sz > 1){
			UI c1, c2, d1, d2;
			UI cdiff = 1 << 20, diff, ddiff = 0;
			for(UI i = 1; i < sz; ++i){
				diff = primes[i] - primes[i - 1];
				if(diff < cdiff){
					cdiff = diff;
					c1 = primes[i - 1];
					c2 = primes[i];
				}
				if(diff > ddiff){
					ddiff = diff;
					d1 = primes[i - 1];
					d2 = primes[i];
				}
			}
			printf("%d,%d are closest, %d,%d are most distant.\n", c1, c2, d1, d2);
		} else puts("There are no adjacent primes.");
	}
	return 0;
}

