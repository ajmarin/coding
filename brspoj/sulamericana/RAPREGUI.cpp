#include <cstdio>
#include <algorithm>
#include <cstdlib>

#define INF 0x3f3f3f3f
#define NN 1000000
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))
#define FOR(a,b) for(int a = 0; a < b; ++a)
#define FORI(a,b,c) for(int a = b; a < c; ++a)

using namespace std;

struct MAPIT{ int v;}VAL[NN];

bool v[NN], l[NN];
int d[NN], HR[NN], dx[24], dy[24];
int effort[]={ 0, 2, 5, 2, 3, 6, 5, 6, 7};
int sx, sy, ex, ey, C, C1, C2, R, R1, R2, W;

inline bool operator<(const MAPIT& a, const MAPIT& b){
	if(HR[a.v]<HR[b.v]) return false;
	return true;
}

int main(void){
	int p = 0;
	FOR(i, 25){
		if(i == 12) continue;
		dx[p] = i/5 - 2;
		dy[p++] = i%5 - 2;
	}
	while(scanf("%d%d",&C,&R) && C){
		int total = C*R;
		FOR(i, total) v[i] = l[i] = 0, d[i] = INF;
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey), sx--, sy--, ex--, ey--;
		int END = ey * C + ex;
		scanf("%d",&W);
		FOR(i,W){
			scanf("%d%d%d%d",&C1,&R1,&C2,&R2), C1--, R1--;
			int idx, o, u; bool *L;
			for(idx = R1*C; R1 < R2; idx=(++R1)*C)
				for(o = C1, idx+=o, L=&l[idx]; o < C2; o++, idx++, *L++ = 1);
		}
		
		int rrr = 1;
		VAL[0].v = sy*C + sx;
		HR[VAL[0].v] = d[VAL[0].v] = 0;
		
		while(rrr > 0){
			int u = VAL[0].v;
			pop_heap(VAL,VAL+rrr--);
			if(v[u]) continue;
			if(u == END) break;
			int ux = u/C, uy = u%C;
			v[u] = l[u] = 1;
			FOR(i, 24){
				int nx = ux + dx[i], ny = uy + dy[i];
				if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				int o = nx*C + ny;
				if(l[o]) continue;
				int nd = effort[3*abs(dx[i]) + abs(dy[i])]+ d[u];
				if(d[o] > nd){
					int ndx = abs(ey - nx), ndy = abs(ex - ny);
					d[o] = nd;
					HR[o] = nd + 3*(MIN(ndx,ndy))+2*(abs(ndx-ndy));
					VAL[rrr++].v = o;
					push_heap(VAL,VAL+rrr);
				}
			}
		}
		if(d[END] < INF) printf("%d\n",d[END]);
		else printf("impossible\n");
	}
	return 0;
}

