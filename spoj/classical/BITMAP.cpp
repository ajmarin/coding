#include <cstdio>
#include <queue>
using namespace std;
const int MAXD = 192;
char m[MAXD][MAXD];
int dist[MAXD][MAXD], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
queue < pair< int, int > > q;
int main(void){
	int t, x, y; scanf("%d", &t);
	while(t--){
		scanf("%d %d\n", &x, &y);
		for(int i = 0; i < x; ++i){
			scanf("%s", m[i]);
			for(int j = 0; j < y; ++j) dist[i][j] = 1024;
		}
		for(int i = 0; i < x; ++i) 
			for(int j = 0; j < y; ++j)
				if(m[i][j] == '1'){
					q.push(make_pair(j + (i << 8), 0));
					dist[i][j] = 0;
				}
		while(!q.empty()){
			int key = q.front().first, depth = q.front().second; q.pop();
			int i = key >> 8, j = key & 255;
			if(depth > dist[i][j]) continue;
			for(int dir = 0; dir < 4; ++dir){
				int nx = i + dx[dir], ny = j + dy[dir];
				if(nx < 0 || ny < 0 || nx >= x || ny >= y) continue;
				if(dist[nx][ny] > depth + 1){
					dist[nx][ny] = depth + 1;
					q.push(make_pair(ny + (nx << 8), depth + 1));
				}
			}
		}
		for(int i = 0; i < x; ++i) 
			for(int j = 0; j < y; ++j)
				printf("%d%c", dist[i][j], j == y-1 ? '\n': ' ');
	}
	return 0;
}

