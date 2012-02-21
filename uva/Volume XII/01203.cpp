#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
char line[1024];
int period[3072];
int main(void){
	priority_queue< PII, vector<PII>, greater<PII> > pq;
	for(int p, q; fgets(line, 1024, stdin) && *line != '#'; pq.push(make_pair(p, q))){
		sscanf(line, "%*s %d %d", &q, &p);
		period[q] = p;
	}
	for(int n = 1; --n || scanf("%d", &n) == 1; ){
		int ts = pq.top().first, qnum = pq.top().second;
		printf("%d\n", qnum);
		pq.pop();
		pq.push(make_pair(ts + period[qnum], qnum));
	}
}

