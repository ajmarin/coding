#include <cstdio>
const int INF = 1 << 29, N = 32;
int d[N][N];
char m[N][N];
bool v[N][N];
int main(void){
        for(int c, r; scanf("%d %d", &c, &r) == 2 && (c || r); ){
                int x, y;
                for(int i = 0; i < r; ++i){
                        scanf("%s", m[i]);
                        for(int j = 0; j < c; ++j){
                                if(m[i][j] == 'S') x = i, y = j;
                                d[i][j] = INF;
                                v[i][j] = false;
                        }
                }
                d[x][y] = 0;
                while(m[x][y] != 'D'){
                        v[x][y] = true;
                        for(int dx = -1; dx < 2; ++dx) for(int dy = -1; dy < 2; ++dy){
                                if(dx && dy) continue;
                                int nx = x + dx, ny =  y + dy;
                                if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                                if(!v[nx][ny] && m[nx][ny] != 'X'){
                                        int t = d[x][y];
                                        if(m[x][y] >= '0' && m[x][y] <= '9')
											t += m[x][y] - '0';
                                        if(t < d[nx][ny]) d[nx][ny] = t;
                                }
                        }
                        int mind = INF;
                        for(int i = 0; i < r; ++i)
                                for(int j = 0; j < c; ++j)
                                        if(!v[i][j] && d[i][j] < mind)
											x = i, y = j, mind = d[i][j];
                }
                printf("%d\n", d[x][y]);
        }
        return 0;
}

