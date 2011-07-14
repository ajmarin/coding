#include <cstdio>
#include <set>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; ++i)
multiset < int > ms;
multiset < int > :: iterator it;

int main(void){
	int t; scanf("%d", &t);
	for(int m, n, z; t-- && scanf("%d %d", &m, &n); ){
		int ans = 0;
		ms.clear();
		FOR(i, m) scanf("%d", &z), ms.insert(z);
		FOR(i, n){
			scanf("%d", &z);
			it = ms.find(z);
			if(it != ms.end()) ms.erase(it);
			else ++ans;
		}
		printf("%d\n", ms.size() + ans);
	}
	return 0;
}

