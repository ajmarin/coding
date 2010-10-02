#include <cstdio>
#include <set>
using namespace std;
multiset<int> k;
int h[32768], n;
int main(){
	multiset < int >::iterator it;
	for (int c, fail, m, n, v; scanf("%d %d",&n,&m)!=EOF && (n || m); ){
		k.clear(); c = fail = 0;
		for(int i = 0; i < n; ++i) scanf("%d", &h[i]);
		for(int i = 0; i < m; ++i) scanf("%d", &v), k.insert(v);
		for(int i = 0; i < n; ++i){
			if((it = k.lower_bound(h[i])) == k.end()){ fail = 1; break;}
			c += *it;
			k.erase(it);
		}
		if(fail) puts("Loowater is doomed!");
		else printf("%d\n", c);
	}
}

