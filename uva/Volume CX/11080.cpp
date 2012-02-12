#include <cstdio>

struct edge { int next, to; } e[20048];
enum { BLANK, BLUE, RED };

int ecnt;
int cnt[3], color[256], next[256];

void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.next = next[from];
	E.to = to;
	next[from] = ecnt++;
}


bool bicolor(int u, int c){
	bool r = true;
	color[u] = c;
	++cnt[c];
	for(int at = next[u], v; at != -1; at = e[at].next){
		v = e[at].to;
		if(color[v] == BLANK) r &= bicolor(v, 3 - c);
		else r &= color[v] == 3 - c;
	}
	return r;
}

int main(void){
	scanf("%*d");
	for(int e, v; scanf("%d %d", &v, &e) == 2; ){
		int guards = 0;
		ecnt = 0;
		for(int i = 0; i < v; ++i){
			next[i] = -1;
			color[i] = BLANK;
		}
		for(int i = 0, from, to; i < e; ++i){
			scanf("%d %d", &from, &to);
			add_edge(from, to);
			add_edge(to, from);
		}
		bool possible = true;
		for(int i = 0; possible && i < v; ++i)
			if(color[i] == BLANK){
				cnt[RED] = cnt[BLUE] = 0;
				possible &= bicolor(i, BLUE);
				if(cnt[BLUE] && cnt[RED]) guards += cnt[BLUE] < cnt[RED] ? cnt[BLUE] : cnt[RED];
				else ++guards;
			}
		printf("%d\n", possible ? guards : -1);
	}
	return 0;
}

