#include <cstdio>
#include <map>
using namespace std;
const char *ans[2] = {"NO", "YES"};
int c, t[10000048];
map < int, int > m;
int remap(int x){
	if(m.count(x)) return m[x];
	return m[x] = c++;
}
void add(int a, int b){
	a = remap(a);
	b = remap(b);
	--t[a];
	++t[b];
}

int main(void){
	for(int i = 0; i < 10000048; ++i) t[i] = 0;
	for(int a, b, n, ok; scanf("%d", &n) && n; ){
		ok = 1;
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &a, &b);
			add(a, b);
		}
		for(int i = 0; i < c; ++i){
			ok &= !t[i];
			t[i] = 0;
		}
		puts(ans[ok]);
	}
	return 0;
}

