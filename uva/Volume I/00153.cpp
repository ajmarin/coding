#include <algorithm>
#include <cassert>
#include <cstdio>
using namespace std;

int mul[32], occ[128];
char line[1024], word[32];

int permutations(int n){
	int r = 1;
	for(int i = 1; i <= n; ++i) mul[i] = i;
	for(int z = 'a'; z <= 'z'; ++z){
		for(int k, x = occ[z]; x > 1; --x){
			int g, y = x;
			for(k = 1; k <= n; ++k){
				g = __gcd(mul[k], y);
				if(g != 1){
					mul[k] /= g;
					y /= g;
					if(y == 1) break;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) r *= mul[i];
	return r;
}
int main(void){
	for(int i, len, r = 1, z; scanf("%s", word) && *word != '#'; r = 1){
		for(i = 'a'; i <= 'z'; ++i) occ[i] = 0;
		for(len = 0; word[len]; ++len) ++occ[word[len]];
		for(i = 0; word[i]; ++i){
			for(z = 'a'; z < word[i]; ++z){
				if(occ[z]){
					--occ[z];
					r += permutations(len - i - 1);
					++occ[z];
				}
			}
			--occ[word[i]];
		}
		printf("%10d\n", r);
	}
	return 0;
}

