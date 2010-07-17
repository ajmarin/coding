#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int m[32];
int main(void){
	int n, s, t, v, w;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i <= 30; ++i) m[i] = 0;
		while(n--){
			scanf("%d %d", &v, &w);
			for(int j = 31 - w, nw = 30; j--; nw--)
					m[nw] = max(m[nw], m[j] + v);
		}
		scanf("%d", &v);
		s = 0;
		while(v--){
			scanf("%d", &w);
			s += m[w];
		}
		printf("%d\n", s);
	}
	return 0;
}
