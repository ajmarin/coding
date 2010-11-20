#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
#define FORD(i, n)	for(int i = n; i > -1; --i)
#define IN(x)		(x = getc(stdin))
#define MAX(a,b)	((a) > (b) ? (a) : (b))
#define MIN(a,b)	((a) < (b) ? (a) : (b))
#define OUT(x)		putc(x, stdout)

bool busy[8][8], safe[8][8];
char r1[8], r2[8], wk[8], b[8];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
void kill(char *str, bool rook){
	int x = str[0] - 'a', y = str[1] - '1';
	if(rook){
		for(int d = 0; d < 4; ++d){
			for(int i = 1; i < 8; ++i){
				int nx = x + dx[d] * i, ny = y + dy[d] * i;
				if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
				safe[nx][ny] = 0;
				if(busy[nx][ny]) break;
			}
		}
	} else {
		for(int d = 0; d < 8; ++d){
			int nx = x + dx[d], ny = y + dy[d];
			if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
			safe[nx][ny] = 0;
		}
	}
}
void show(){
	FOR(i, 8){
		FOR(j, 8) putc(safe[i][j] + '0', stdout);
		putc(10, stdout);
	}
	puts("----------------");
}
int main(void){
	scanf("%s %s %s %s", r1, r2, wk, b);
	FOR(i, 8) FOR(j, 8) safe[i][j] = 1, busy[i][j] = 0;
	busy[r1[0] - 'a'][r1[1] - '1'] = 1;
	busy[r2[0] - 'a'][r2[1] - '1'] = 1;
	busy[wk[0] - 'a'][wk[1] - '1'] = 1;
	kill(r1, 1);
	kill(r2, 1);
	kill(wk, 0);
	int myx = b[0] - 'a', myy = b[1] - '1';
	bool imfinethx = safe[myx][myy];
	for(int d = 0; !imfinethx && d < 8; ++d){
		int nx = myx + dx[d], ny = myy + dy[d];
		if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
		imfinethx |= safe[nx][ny];
	}
	if(imfinethx) puts("OTHER");
	else puts("CHECKMATE");
	return 0;
}

