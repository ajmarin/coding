#include <algorithm>
#include <cstdio>

using namespace std;

struct person {
	char name[32];
	int d, m, y;
	bool operator<(const person &p) const {
		return y < p.y || (y == p.y && (m < p.m || (m == p.m && d < p.d)));
	}
} p[128];

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		for(int i = 0; i < n; ++i) scanf("%s %d %d %d", p[i].name, &p[i].d, &p[i].m, &p[i].y);
		sort(p, p + n);
		printf("%s\n%s\n", p[n - 1].name, p[0].name);
	}
	return 0;
}

