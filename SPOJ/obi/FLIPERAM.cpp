#include <cstdio>
#include <algorithm>
int v[10000], i, m, n;
bool inv(int a, int b){
	return a > b;
}
int main(void){
	scanf("%d%d",&n,&m);
	for(i = 0; i < n; i++) scanf("%d",&v[i]);
	std::sort(v,v+n,inv);
	for(i = 0; i < m; i++) printf("%d\n",v[i]);
	return 0;
}
