#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define REP(a,b) for(a = 0; a < b; a++)
#define NN 128

struct point { int x, y; };
struct line { point a, b; int sqd2;};
point tree[NN];
line LL[NN];

int sqd(point a, point b){
	int dx = a.x - b.x, dy = a.y - b.y;
	return ((dx*dx)+(dy*dy));
}
/* {{{ Hopcroft-Karp */
#define tr(x) for(typeof(g[x].begin())it = g[x].begin(); it != g[x].end(); it++)

int dx[NN], dy[NN], px[NN], py[NN], q[NN];
vector <int> g[NN];

bool BFS(int n, int m){
	bool f = 0;
	int i, h = 0, t = 0;
	memset(dx,0,n<<2);
	memset(dy,0,m<<2);
	for(i = 0; i < n; i++) if(px[i] == -1) q[t++] = i;
	while(h < t){
		int x = q[h++];
		tr(x) if(!dy[(*it)]){
			dy[(*it)] = dx[x] + 1;
			if(py[(*it)] == -1) f = 1;
			else dx[py[(*it)]] = dy[(*it)]+1, q[t++] = py[(*it)];
		}
    }
    return f;
}
bool DFS(int x){
	tr(x) if(dy[(*it)] == dx[x]+1){
		dy[(*it)] = 0;
		if(py[(*it)] == -1 || DFS(py[(*it)]))
			return px[x] = (*it), py[(*it)] = x, true;
	}
	return false;
}
int hopcroft_karp(int n, int m){
	int i, mm = 0;
	memset(px,-1,n<<2);
	memset(py,-1,m<<2);
	while(BFS(n, m))
		for(i = 0; i < n; i++)
			mm += (px[i] == -1 && DFS(i));
    return mm;
}
/* }}} */
int main(void){
	int i, j, M, N, T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d", &N, &M);
		REP(i,N) g[i].clear();
		REP(i,N){
			scanf("%d %d", &LL[i].a.x, &LL[i].a.y);
			if(i){
				int p = i-1;
				LL[p].b.x = LL[i].a.x;
				LL[p].b.y = LL[i].a.y;
				LL[p].sqd2 = sqd(LL[p].a,LL[p].b)<<1;
			}
		}
		REP(i,M){
			scanf("%d %d", &tree[i].x, &tree[i].y);
			REP(j,N-1) {
				int d1 = sqd(tree[i],LL[j].a);
				int d2 = sqd(tree[i],LL[j].b);
				if(d1+d2 <= LL[j].sqd2){
					//printf("Tree(%d,%d)\n\tto (%d,%d) = %d\n\t",tree[i].x,tree[i].y,LL[j].a.x,LL[j].a.y,d1);
					//printf("to (%d,%d) = %d\n",LL[j].b.x,LL[j].b.y,d2);
					//printf("\tSum = %d <= %d\n",d1+d2, LL[j].sqd2);
					g[j].push_back(i);
				}
			}
		}
		printf("%d\n", hopcroft_karp(N-1, M)+N);
		printf("%d %d", LL[0].a.x, LL[0].a.y);
		REP(i,N-1){
			if(px[i] != -1 && py[px[i]] == i) printf(" %d %d",tree[px[i]].x,tree[px[i]].y);
			printf(" %d %d",LL[i].b.x,LL[i].b.y);
		}
		putc(10, stdout);
		if(T) putc(10, stdout);
	}
	return 0;
}
