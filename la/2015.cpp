#include <cstdio>
#include <set>
using namespace std;

#define FOR(i,n)	for(int i = 0; i < n; ++i)
char pattern[5][10];
struct card {
	int v[5][5];
	void read(){ FOR(i, 5) FOR(j, 5) scanf("%d", &v[i][j]); }
	bool operator==(card c){
		set < int > x, y;
		FOR(i, 5) FOR(j, 5) if(pattern[i][j] == 'X'){
			x.insert(v[i][j]);
			y.insert(c.v[i][j]);
		}
		return x == y;
	}
} c[128];

int main(void){
	for(int game = 0; ; ){
		FOR(i, 5) scanf("%s", pattern[i]);
		int cards;
		scanf("%d", &cards);
		if(!cards) break;
		if(game++) puts("");
		printf("Game %d\n", game);
		FOR(i, cards) c[i].read();
		FOR(i, cards) FOR(j, i)
			if(c[j] == c[i]){
				printf("Card %d is equivalent to card %d\n", i+1, j+1);
				break;
			}
	}
	return 0;
}

