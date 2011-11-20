#include <cstdio>
#include <queue>
using namespace std;

const int NN = 1024;
int q[NN], s[NN];
priority_queue < int > pq;

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int head = 0, tail = 0, top = 0;
		int is_pq = 1, is_q = 1, is_s = 1;
		pq = priority_queue < int >();
		for(int a, b, i = 0; i < n; ++i){
			scanf("%d %d", &a, &b);
			if(a == 1){
				q[tail++] = b;
				s[top++] = b;
				pq.push(b);
			} else {
				is_q &= head != tail && q[head++] == b;
				is_s &= top && s[--top] == b;
				is_pq &= !pq.empty() && pq.top() == b;
				if(!pq.empty()) pq.pop();
			}
		}
		if(is_q + is_s + is_pq > 1) puts("not sure");
		else if(is_q) puts("queue");
		else if(is_s) puts("stack");
		else if(is_pq) puts("priority queue");
		else puts("impossible");
	}
	return 0;
}

