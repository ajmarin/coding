#include <cstdio>
#include <map>
#include <string>
using namespace std;
#define FOREACH(it,s,e)	for(typeof(s) it = s; it != e; it++)
map < string, int > score;
string player[1024];
int round_score[1024];
char name[64];
int main(void){
	int maxs = 0, n, z; scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s %d", name, &z);
		round_score[i] = score[player[i] = string(name)] += z;
	}
	FOREACH(it, score.begin(), score.end()) if(it -> second > maxs) maxs = it -> second;
	for(int i = 0; i < n; ++i)
		if(round_score[i] >= maxs && score[player[i]] == maxs){
			printf("%s\n", player[i].c_str());
			//printf("did score %d on round %d\n", round_score[i], i + 1);
			return 0;
		}
	return 0;
}

