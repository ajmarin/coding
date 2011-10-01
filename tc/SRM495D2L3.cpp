#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int LL;
bool adj[50][50][50][50], v[50][50];
int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, -1, 1, 0, 1};
int n;
void connect(int a, int b, int c, int d, int e, int f){
	adj[a][b][c][d] = adj[c][d][a][b] = 1;
	adj[a][b][e][f] = adj[e][f][a][b] = 1;
	adj[c][d][e][f] = adj[e][f][c][d] = 1;
}
LL dfs(int x, int y){
	LL r = 1;
	v[x][y] = 1;
	for(int d = 0; d < 6; ++d){
		int nx = x + dx[d], ny = y + dy[d];
		if(ny > nx || ny < 0 || nx < 0 || nx >= n) continue;
		if(adj[x][y][nx][ny] && !v[nx][ny]) r += dfs(nx, ny);
	}
	return r;
}		
class HexagonPuzzle {
public:
	int theCount( vector <string> b ) {
		LL r = 1;
		n = b.size();
		memset(adj, 0, sizeof(adj));
		memset(v, 0, sizeof(v));
		for(int i = 0; i < n - 1; ++i)
			for(int j = 0; j <= i; ++j)
				if(b[i][j] == '.'){
					if(b[i + 1][j] == '.' && b[i + 1][j + 1] == '.')
						connect(i, j, i + 1, j, i + 1, j + 1);
					if(j < i && b[i][j + 1] == '.' && b[i + 1][j + 1] == '.')
						connect(i, j, i, j + 1, i + 1, j + 1);
				}
		for(int i = 0; i < n - 1; ++i)
			for(int j = 0; j <= i; ++j)
				if(b[i][j] == '.' && !v[i][j])
					for(LL c = dfs(i, j); c > 2; r = (r * c--) % 1000000007);
		return (int) r;
	}
};
