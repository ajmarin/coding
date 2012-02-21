#include <algorithm>
#include <cstdio>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

unordered_map< long long, int > m;
int v[8];
long long stmask[10048];

int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		m.clear();
		for(int s = n; s--; ){
			long long mask = 0;
			for(int i = 0; i < 5; ++i) scanf("%d", v + i);
			sort(v, v + 5);
			for(int i = 0; i < 5; ++i) mask = (mask << 9) | v[i];
			stmask[s] = mask;
			++m[mask];
		}
		int ans = 0, cnt = 0;
		for(unordered_map<long long, int>::iterator it = m.begin(); it != m.end(); ++it)
			if(it -> second > cnt) cnt = it -> second;
		for(int s = 0; s < n; ++s) ans += m[stmask[s]] == cnt;
		printf("%d\n", ans);
	}
	return 0;
}

