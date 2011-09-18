#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
#define NN 200000
#define MP make_pair
map< int, int > m;
set< pair<int, int> > seen;
int c[NN], cnt, p[NN], r[NN];
int get_index(int v){
	int &x = m[v];
	if(!x){
		x = cnt++;
		c[x] = r[x] = 0;
		p[x] = x;
	}
	return x;
}
int root(int a){
	return p[a] == a ? a : p[a] = root(p[a]);
}
bool union_find(int a, int b){
	p[a = root(a)] = b = root(b);
	return a != b;
}
int max_scc(){
	int ret = 0;
	for(int i = 1; i < cnt; ++i) ret = max(ret, ++r[p[i]]);
	return ret;
}
int main(void){
	for(int K, W; scanf("%d %d", &K, &W) == 2 && (K || W); ){
		int a, b, x, y;
		int cycles = 0;
		bool possible = true;
		cnt = 1;
		m.clear();
		seen.clear();
		for(int i = 0; i < W; ++i){
			scanf("%d %d", &a, &b);
			if(a > b) swap(a, b);
			x = get_index(a);
			y = get_index(b);
			if(seen.find(MP(x, y)) != seen.end()) continue;
			cycles += !union_find(x, y);
			seen.insert(MP(x, y));
			possible &= ++c[x] < 3 && ++c[y] < 3;
		}
		for(int i = 1; i < cnt; ++i) root(i);
		possible &= !cycles || max_scc() == K;
		puts(possible ? "Y" : "N");
	}
	return 0;
}

