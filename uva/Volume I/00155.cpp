#include <cstdio>

int ins, x, y;
int dx[4] = {-1,1,1,-1};
int dy[4] = {-1,-1,1,1};

inline int sqr(int k){ return (k*k);}
inline int d2(int xx, int yy){ return sqr(xx - x) + sqr(yy - y);}

bool inside(int cx, int cy, int L){
	int max_x = cx + L, min_x = cx - L;
	int max_y = cy + L, min_y = cy - L;
	if(x > max_x || x < min_x || y > max_y || y < min_y) return 0;
	return 1;
}
void sq(int cx, int cy, int L){
	int min_d = 1<<30, c;
	ins += inside(cx, cy, L);
	if(L < 2) return;
	for(int i = 0; i < 4; ++i){
		int nx = cx + dx[i] * L;
		int ny = cy + dy[i] * L;
		int d = d2(nx,ny);
		if(d < min_d) min_d = d, c = i;
	}
	sq(cx + dx[c] * L, cy + dy[c] * L, L>>1);
}
int main(void){
	int k;
	while(scanf("%d%d%d",&k,&x,&y) && k){
		ins = 0; sq(1024, 1024, k);
		printf("%3d\n",ins);
	}
	return 0;
}

