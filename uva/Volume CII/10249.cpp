#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXT = 70;
const int MAXN = 50;
#define FOR(i,n) for(int i = 0; i < n; ++i)
int cap[MAXN], tord[MAXT], ts[MAXT];
int map[MAXT][100];
bool ord(int a, int b){
	return ts[a] > ts[b];
}
int main(void){
	for(int m, n; scanf("%d %d", &m, &n) == 2 && (m || n); ){
		bool possible = true;
		FOR(i, m){ // for each team
			scanf("%d", ts + i); // read team size
			tord[i] = i;
		}
		FOR(i, n) // for each table
			scanf("%d", cap + i); // read table capacity
		sort(tord, tord + m, ord);
		FOR(i, m){
			int j, k, team = tord[i];
			for(j = k = 0; j < n && k < ts[team]; ++j)
				if(cap[j]){
					--cap[j];
					map[team][k++] = j + 1;
				}
			if(!(possible &= k == ts[team])) break;
		}
		puts(possible ? "1" : "0");
		if(possible) FOR(i, m) FOR(j, ts[i])
			printf("%d%c", map[i][j], j == ts[i] - 1 ? 10 : 32);
	}
	return 0;
}
