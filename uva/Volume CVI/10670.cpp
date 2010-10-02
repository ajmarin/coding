#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int cost(int n, int m, int a, int b){
	if(a == 0) return 0;
	int c = 0, lim = b / a, dist = n - m, m2 = m << 1;
	while(n >= m2){
		if((n - (n >> 1)) * a < b) break;
		n >>= 1;
		dist = n - m;
		c += b;
	}
	c += dist * a;
	return c;
}
struct agency {
	char name[32];
	int cost;
	bool operator<(agency a) const {
		return cost < a.cost || (cost == a.cost && strcmp(name, a.name) < 0);
	}
} ag[128];
int main(void){
	int a, b, l, m, n, t;
	scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		printf("Case %d\n", cnum);
		scanf("%d %d %d\n", &n, &m, &l);
		for(int i = 0; i < l; ++i){
			scanf("%[A-Z]:%d,%d\n", ag[i].name, &a, &b);
			ag[i].cost = cost(n, m, a, b);
		}
		sort(ag, ag + l);
		for(int i = 0; i < l; ++i)
			printf("%s %d\n", ag[i].name, ag[i].cost);
	}
	return 0;
}

