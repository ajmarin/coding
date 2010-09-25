#include <cstdio>
#include <map>
using namespace std;
#define NN 100048
int next[NN][2], deg[NN], unmap[NN], p[NN];
int c = 0;
map <int, int> m;
int remap(int k){
	if(m.count(k)) return m[k];
	unmap[c] = k;
	return m[k] = c++;
}
void add(int a, int b){
	int x = remap(a), y = remap(b);
	next[x][deg[x]++] = y;
	next[y][deg[y]++] = x;
}
int main(void){
	int a, at, b, n, p = -1;
	scanf("%d", &n);
	m.clear();
	for(int i = 0; i < n; ++i) deg[i] = 0;
	for(int i = 0; i < n; ++i) scanf("%d %d", &a, &b), add(a, b);
	for(int i = 0; i <= n; ++i) if(deg[i] == 1) at = i;
	printf("%d", unmap[at]);
	do {
		if(next[at][0] == p) p = at, at = next[at][1];
		else p = at, at = next[at][0];
		printf(" %d", unmap[at]);
	} while(deg[at] == 2);
	putc(10, stdout);
	return 0;
}

