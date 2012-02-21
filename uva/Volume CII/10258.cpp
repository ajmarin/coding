#include <algorithm>
#include <cstdio>
using namespace std;

const int NC = 100, NP = 10;
char line[1024];
struct player {
	int penalty[NP], solved[NP];
	int n, ps, submissions, tp;
	void clear(int num){
		n = num;
		ps = submissions = tp = 0;
		for(int i = 0; i < NP; ++i) solved[i] = penalty[i] = 0;
	}
	bool operator<(const player p) const {
		return ps > p.ps || (ps == p.ps && tp < p.tp) || (ps == p.ps && tp == p.tp && n < p.n);
	}
} p[100];

int main(void){
	int player, problem, time;
	char verdict[16];
	int t;
	gets(line);
	sscanf(line, "%d", &t);
	gets(line);
	while(t--){
		for(int i = 0; i < NC; ++i) p[i].clear(i);
		while(gets(line) && line[0]){
			sscanf(line, "%d %d %d %s", &player, &problem, &time, verdict);
			--player; --problem;
			if(*verdict == 'C' && !p[player].solved[problem]){
				p[player].solved[problem] = 1;
				p[player].ps++;
				p[player].tp += time + p[player].penalty[problem];
			} else if(*verdict == 'I' && !p[player].solved[problem]) 
				p[player].penalty[problem] += 20;
			++p[player].submissions;
		}
		sort(p, p + NC);
		for(int i = 0; i < NC; ++i) if(p[i].submissions)
			printf("%d %d %d\n", p[i].n + 1, p[i].ps, p[i].tp);
		if(t) puts("");
	}
	return 0;
}

