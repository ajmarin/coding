#include <cstdio>
#include <algorithm>

using namespace std;

#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)

struct TEAM {
	int n, score, subs, c_sol;
	bool solved[16];
	bool operator<(const TEAM x) const{
		if(score > x.score) return 1;
		if(score == x.score){
			if(c_sol < x.c_sol) return 1;
			if(c_sol == x.c_sol){
				if(subs < x.subs) return 1;
				if(subs == x.subs && n < x.n) return 1;
			}
		}
		return 0;
	}

} t[16];
int pv[16];
int main(void){
	int cnum = 0, S, T, P;
	int team;
	char prob[200], ver[200];
	while(scanf("%d%d",&T,&P) && (T||P)){
		FOR(i,T){
			t[i].subs = t[i].score = t[i].c_sol = 0;
			t[i].n = i+1;
			FOR(j, P) t[i].solved[j] = 0;
		}
		FOR(i,P) scanf("%d",&pv[i]);
		scanf("%d",&S);
		FOR(i,S){
			scanf("%d %s %s",&team,&prob[0],&ver[0]);
			prob[0] -= 'A'; --team;
			if(t[team].solved[prob[0]]) continue;
			t[team].subs++;
			if(ver[0] == 'A'){
				t[team].solved[prob[0]] = 1;
				t[team].score += pv[prob[0]];
				t[team].c_sol++;
			}
		}
		sort(t,t+T);
		printf("%d\n",++cnum);
		FOR(i,T) printf("%d %d\n",t[i].n,t[i].score);

	}
	return 0;
}


