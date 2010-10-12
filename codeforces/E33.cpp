#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
#define FOR(a,b) 	for(int a = 0; a < b; ++a)
#define FORI(a,b,c) for(int a = b; a < c; ++a)
struct task {
	int d, n, v;
	char subject[64];
	bool operator<(const task t) const {
		return d < t.d;
	}
} t[128];
bool busy[1440];
char student[128][64], subject[128][64];
int done[43200], g[128][43200], worked[43200];
int FMD = 0;
map< string, int > subj;
void batraque(int n, int j, int cnt){
	if(n == 0){ printf("%d\n", cnt); return; }
	if(g[n][j] == g[n - 1][j]) batraque(n - 1, j, cnt);
	else {
		int end = j - 1, start = j - subj[string(t[--n].subject)];
		batraque(n, start, cnt + 1);
		int d1, d2, h1, h2, m1, m2;
		d1 = (start / FMD) + 1; d2 = (end / FMD) + 1;
		start %= FMD; end %= FMD;
		h1 = done[start] / 60; h2 = done[end] / 60;
		m1 = done[start] - 60 * h1; m2 = done[end] - 60 * h2;
		printf("%d %d %02d:%02d %d %02d:%02d\n", t[n].n, d1, h1, m1, d2, h2, m2);
	}
}
int main(void){
	int cost, k, m, n;
	int day, h1, h2, m1, m2;
	scanf("%d %d %d", &m, &n, &k);
	subj.clear();
	FOR(i, m) scanf("%s", subject[i]);
	FOR(i, m){
		scanf("%d", &cost);
		subj[string(subject[i])] = cost;
	}
	FOR(i, 1440) busy[i] = 0;
	FOR(i, 4){
		scanf("%2d:%2d-%2d:%2d", &h1, &m1, &h2, &m2);
		int l = 60 * h1 + m1, r = 60 * h2 + m2 + 1;
		FORI(j, l, r) busy[j] = 1;
	}
	FOR(i, k * 1440) {
		worked[i] = FMD;
		if(!busy[i % 1440]) done[FMD++] = i;
	}
	FMD /= k;
	k = k * FMD + 1;
	FOR(i, n){
		scanf("%s %d %2d:%2d %d", t[i].subject, &day, &h1, &m1, &t[i].v); 
		t[i].d = worked[(day - 1) * 1440 + 60 * h1 + m1];
		t[i].n = i + 1;
		string s = string(t[i].subject);
		if(subj.count(s) == 0) t[i].d = -1;
	}
	if(FMD == 0) { printf("0\n0\n"); return 0; }
	sort(t, t + n);
	FOR(j, k) g[0][j] = 0;
	FOR(i, n){
		int deadline = t[i].d;
		int *c = g[i], *n = g[i + 1];
		cost = k;
		if(deadline != -1) cost = subj[string(t[i].subject)];
		FORI(j, 0, cost) n[j] = c[j];
		FOR(j, k){
			int end = j + cost;
			if(end > deadline){
				while(end <= k) n[end] = c[end], end++;
				j = end;
			}
			else n[end] = max(c[j] + t[i].v, c[end]);
		}
	}
	int idx = -1, profit = 0;
	FOR(i, k) if(g[n][i] > profit) profit = g[n][i], idx = i;
	printf("%d\n", profit);
	batraque(n, idx, 0);
	return 0;
}

