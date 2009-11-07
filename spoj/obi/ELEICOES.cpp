#include <cstdio>
#include <map>
using namespace std;
map < int , int > m;
struct CAND{
	int s, id;
} cand[100000];
int main(void){
	int c, i, idx, max, n, v;
	scanf("%d",&n);
	c = idx = max = 0;
	m.clear();
	while(n--){
		scanf("%d",&v);
		if(m.find(v) == m.end()) m[v] = c++, cand[m[v]].s = 0;
		i = m[v];
		cand[i].id = v;
		if(++cand[i].s > max) max = cand[i].s, idx = i;
	}
	printf("%d\n",cand[idx].id);
}
