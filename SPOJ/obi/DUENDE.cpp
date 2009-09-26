#include <cstdio>
#include <queue>
using namespace std;
struct P {
	int x, y;
	P(int i, int j) : x(i), y(j){}
};
queue < pair < P, int > > q;
char finish, m[10][10];
bool v[10][10];
void PUSH(int x, int y, int d){
	if(v[x][y] || m[x][y] == 2) return;
	v[x][y] = 1;
	q.push(make_pair(P(x,y),d));
}
int main(void){
	int c, i, j, r, sX, sY;
	memset(v,0,sizeof(v));
	scanf("%d%d",&r,&c);
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++){
			scanf("%d",&m[i][j]);
			if(m[i][j] == 3) sX = i, sY = j;
		}
	PUSH(sX,sY,0);
	while(!q.empty() && !finish){
		int X = q.front().first.x, Y = q.front().first.y;
		int d = q.front().second;
		q.pop();
		if(m[X][Y]){
			if(X < r-1) PUSH(X+1,Y,d+1);
			if(X) PUSH(X-1,Y,d+1);
			if(Y < c-1) PUSH(X,Y+1,d+1);
			if(Y) PUSH(X,Y-1,d+1);
		} else finish = d;
	}
	printf("%d\n",finish);
	return 0;
}
