#include <cstdio>
#include <cstring>
#include <cassert>

#define FORI(a,b,c) for(char a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)
#define NN 12

char connections[128], map[128], rot[NN][NN];
char dx[4] = {-1, 0, 1, 0};
char dy[4] = {0, 1, 0, -1};
bool connected[NN][NN][4], h[NN][NN], v[NN][NN];
const char *dirname[4] = {"NORTH","EAST","SOUTH","WEST"};
int R, C;

void bt(char x, char y, char r){
	//printf("Called as (%d,%d)[%d]\n",x,y,r);
	assert(r < 4);
	assert(x < R);
	assert(x >= 0);
	assert(y < C);
	assert(y >= 0);
	//printf("Rotation for (0,0) = %d\n",rot[0][0]);
	rot[x][y] = r;
	//printf("Rotation for (0,0) = %d\n",rot[0][0]);
	v[x][y] = 1;
	h[x][y] = 1;
	FOR(dir, 4){
		char nr = (r + dir) % 4;
		if(!connected[x][y][nr]) continue;
		char nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 0 || ny < 0 || nx >= R || ny >= C ||
		(v[nx][ny] && !connected[nx][ny][(rot[nx][ny] + dir + 2) % 4])){
			h[x][y] = 0;
			break;
		}
	}
	if(h[x][y]) FOR(dir, 4){
		char nr = (r + dir) % 4;
		/* verifica se esta conectado na direcao (NESW)*/
		if(!connected[x][y][nr]) continue;
		//printf("\nPiece (%d,%d) rotated %d, connected %s(%d)\n",x,y,r,dirname[dir],dir);
		char nx = x + dx[dir], ny = y + dy[dir];
		/* se a direcao para a qual esta conectado
		   esta fora do tabuleiro, FUDEU, vaza.
		*/
		if(nx < 0 || ny < 0 || nx >= R || ny >= C){
			//printf("\tAnd it's out of bounds..GG\n");
			h[x][y] = 0;
			break;
		}
		/* tenta rotacionar a peca adjacente para satisfazer a
		   atual, se ela ja foi visitada, portanto esta fixa
		   e nao conecta com a atual, FUDEU, vaza.
		*/
		if(v[nx][ny]){
			//printf("\tChecking with neighbour (%d,%d)[%d]\n",nx,ny,rot[nx][ny]);
			char adjr = rot[nx][ny];
			if(!connected[nx][ny][(adjr + dir + 2) % 4]){
				//printf("\t(%d,%d)[%d] didnt answer :/\n",nx,ny,rot[nx][ny]);
				h[x][y] = 0;
				break;
			}
			//printf("\t(%d,%d) is my FRIEND!!\n",nx,ny);
		} else FOR(adj, 4){
			if(!connected[nx][ny][(adj + dir + 2) % 4]) continue;
			//printf("\t(%d,%d) Connected with(%d,%d) xD\n",x,y,nx,ny);
			bt(nx, ny, adj);
			if(h[nx][ny]) break;
		}
		if(!h[nx][ny]){
			//printf("\t(%d,%d): (%d,%d) doesn't want to PLAY with ME =(\n",x,y,nx,ny);
			h[x][y] = 0;
			break;
		}
	}
	/*if(h[x][y]) //printf("\t\t(%d,%d): I'm FUCKING HAPPY!\n",x,y);
	else //printf("\t\t(%d,%d): Life sucks, give me a beer.\n",x,y);
	*/
	v[x][y] = h[x][y];
}

		
int main(void){
	map['N'] = 0; map['E'] = 1;
	map['S'] = 2; map['W'] = 3;
	while(scanf("%d %d",&R,&C) && R){
		memset(connected, 0, sizeof(connected));
		memset(h, 0, sizeof(h));
		memset(v, 0, sizeof(v));
		memset(rot, 0, sizeof(rot));
		FOR(i,R) FOR(j, C){
			scanf("%s",connections);
			if(connections[0] == 'x') continue;
			for(char *L = connections; *L; L++)
				connected[i][j][map[*L]] = 1;
		}
		FOR(i, R) FOR(j, C){
			if(!v[i][j]) FOR(k, 4) if(!h[i][j]) bt(i,j,k);
			if(!h[i][j]) goto OWNED;
		}
		printf("SOLVABLE\n");
		continue;
OWNED:
		printf("UNSOLVABLE\n");
	}
	return 0;
}

