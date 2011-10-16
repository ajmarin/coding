#include <cstdio>
#include <queue>
using namespace std;

int main(void){
	for(int n, z; scanf("%d", &n) == 1 && n > 1; ){
		long long ans = 0, x, y;
		priority_queue < int, vector<int>, greater<int> > q;
		for(int i = 0; i < n; ++i) scanf("%d", &z), q.push(z);
		while(q.size() > 1){
			x = q.top(); q.pop();
			y = q.top(); q.pop();
			ans += (x += y);
			if(q.empty()) break;
			q.push(x);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

