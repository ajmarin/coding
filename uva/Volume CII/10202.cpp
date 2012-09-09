#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)
int v[128];
int a[16];

bool test(int first, multiset<int> s){
	int idx = 0, z;
	multiset<int>::iterator it;
	a[idx++] = first;
	while(!s.empty()){
		z = *s.begin() - first;
		FOR(i, idx){
			if((it = s.find(z + a[i])) == s.end()) return false;
			s.erase(it);
		}
		a[idx++] = z;
	}
	return true;
}

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int read = (n * (n - 1)) >> 1;
		FOR(i, read) scanf("%d", v + i);
		sort(v, v + read);
		multiset<int> sums = multiset<int>(v, v + read);
		bool possible = false;
		for(int i = 2; !possible &&  i < n; ++i) possible |= test((v[0] + v[1] - v[i]) >> 1, sums);
		if(!possible) puts("Impossible");
		else FOR(i, n) printf("%d%c", a[i], i == n - 1 ? 10 : 32);
	}
	return 0;
}

