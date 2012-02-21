#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

const int NC = 100;
int main(void){
	scanf("%*d");
	for(int n, q, s; scanf("%d %d %d", &n, &s, &q) == 3; ){
		queue<int> qc[n];
		stack<int> c;
		for(int i = 0, v, z; i < n; ++i){
			scanf("%d", &z);
			while(z--){
				scanf("%d", &v);
				qc[i].push(--v);
			}
		}
		int at = 0, minutes = 0;
		while(true){
			// Unloading
			while(!c.empty() && (c.top() == at || qc[at].size() < q)){
				if(c.top() != at) qc[at].push(c.top());
				c.pop();
				++minutes;
			}
			// Loading
			while(c.size() < s && !qc[at].empty()){
				c.push(qc[at].front());
				qc[at].pop();
				++minutes;
			}
			bool over = c.empty();
			for(int i = 0; over && i < n; ++i) over &= qc[i].empty();
			if(over) break;
			minutes += 2;
			at = (at + 1) % n;
		}
		printf("%d\n", minutes);
	}
}

