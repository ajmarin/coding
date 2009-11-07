#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <utility>

using namespace std;

char rot[3] = {-1, 0, 1};
char rotn[4] = {-2, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char connections[8], map[128];
int ex, ey, sx, sy, R, C;

struct STATE {
	char x, y, r;
	int s;
	STATE(char _x=0, char _y=0, char _r=0, int _s =0):
		x(_x),y(_y),r(_r),s(_s){}
};

deque < STATE > q;
bool visited[20][20][4][1600];
int  steps[20][20][4][1600];
bool connected[20][20][4];


void QUEUEIT(char x, char y, char r, int spare, int step){
	if(visited[x][y][r][spare]) return;
	q.push_back(STATE(x,y,r,spare));	
	visited[x][y][r][spare] = 1;
	steps[x][y][r][spare] = step;
}
int BFS(){
	memset(visited, 0, sizeof(visited));
	q.clear();
	
	QUEUEIT(sx, sy, 0, 0, 0);
	while(!q.empty()){
		STATE stt = q.front(); q.pop_front();
		char c_x = stt.x, c_y = stt.y, c_r = stt.r;
		int c_s = stt.s, c_steps = steps[c_x][c_y][c_r][c_s];
		if(c_x == ex && c_y == ey) return c_steps;
		for(char i = 0;  i < 3; ++i){
			char new_rot = (c_r+rot[i]+4)%4;
			int spare_r = c_s + !(rot[i] & 1);
			QUEUEIT(c_x, c_y, new_rot, spare_r, c_steps+1);
			for(char dir = 0; dir < 4; ++dir){
				if(!connected[c_x][c_y][(dir+new_rot)%4]) continue;
				char nx = c_x + dx[dir], ny = c_y + dy[dir];
				if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				for(char j = 0; j < 4; ++j){
					if(abs(rotn[j]) > spare_r) continue;
					char new_rot2 = (rotn[j]+4)%4;
					if(!connected[nx][ny][(dir+new_rot2+2)%4]) continue;
					int spare_r2 = spare_r - abs(rotn[j]);
					QUEUEIT(nx, ny, new_rot2, spare_r2, c_steps + 1);
				}
			}
		}
	}
}
int main(void){
	map['N'] = 0; map['E'] = 1;
	map['S'] = 2; map['W'] = 3;
	while(scanf("%d %d",&R,&C) && R){
		memset(connected, 0, sizeof(connected));
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);		
		--sx; --sy; --ex; --ey;
		for(char i = 0; i < R; ++i)
			for(char j = 0; j < C; ++j){
			scanf("%s",connections);
			if(connections[0] == 'x') continue;
			for(char *L = connections; *L; L++)
				connected[i][j][map[*L]] = 1;
		}
		printf("%d\n",BFS());
	}
	return 0;
}
