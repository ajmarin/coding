#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct part {
	int cost, quality;
	part(int _c = 0, int _q = 0): cost(_c), quality(_q) {}
	bool operator<(part p) const{
		return cost < p.cost || (cost == p.cost && quality < p.quality);
	}
};
struct type { vector < part > option; int ui; } t[1024];
map < string, int > m;
int types;
char tname[1024][32];
int main(void){
	int T; scanf("%d", &T);
	while(T--){
		int budget, n;
		int c, q;
		m.clear();
		types = 1;
		scanf("%d %d", &n, &budget);
		for(int i = 0; i < n; ++i){
			scanf("%s %*s %d %d", tname[types], &c, &q);
			int &ptype = m[tname[types]];
			if(!ptype){
				ptype = types++;
				t[ptype].option.clear();
				t[ptype].ui = 0;
			}
			t[ptype].option.push_back(part(c, q));
		}
		for(int i = 1; i < types; ++i){
			sort(t[i].option.begin(), t[i].option.end());
			budget -= t[i].option[0].cost;
		}
		int minq = 1 << 30;
		for(bool upgraded = true; upgraded; ){
			upgraded = true;
			minq = 1 << 30;
			for(int i = 1; i < types; ++i){
				minq = min(t[i].option[t[i].ui].quality, minq);
			}
			for(int i = 1; upgraded && i < types; ++i)
				if(t[i].option[t[i].ui].quality == minq){
					int j, sz = t[i].option.size();
					budget += t[i].option[t[i].ui].cost;
					for(j = t[i].ui + 1; j < sz; ++j)
						if(t[i].option[j].quality > minq) break;
					if(j < sz && budget >= t[i].option[j].cost){
						t[i].ui = j;
					} else upgraded = false;
					budget -= t[i].option[t[i].ui].cost;
				}
		}
		printf("%d\n", minq);
	}

	return 0;
}

