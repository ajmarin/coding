#include <cctype>
#include <cstdio>
#include <vector>
using namespace std;
#define IN getc( stdin )
#define FOR(a,b) for(int a = 0; a < b; ++a)
#define MP(a,b) make_pair(a,b)

const char dir[4] = { 'N', 'E', 'S', 'W' };
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int NN = 2500;

int cn[NN], g[NN], ln[NN], px[NN], py[NN], q[NN], v[50][50];
char a[50][51];
vector < pair< char, int > > adj[NN];
vector < pair< char, int > > ::iterator it;
void fint(register int *k){
	register char c = IN; *k = 0;
	while(!isdigit(c)) c = IN;
	while(isdigit(c)) *k = *k * 10 + c - '0', c = IN;
}
int main(void){
	int C, L, h, k, t, z;
	while(scanf("%d %d", &L, &C) && L){
		k = 0;
		FOR(x, L){
			a[x][C] = 0;
			FOR(y, C){
				adj[k].clear();
				ln[k] = x;
				cn[k] = y;
				g[k] = 0;
				v[x][y] = k++;
				a[x][y] = 'X';
			}
		}
		a[0][0] = '*';
		k = 0;
		FOR(x, L) FOR(y, C){
			fint(&z);
			if(z)
			FOR(d, 4){
				char nx = x + dx[d]*z, ny = y + dy[d]*z;
				if(nx < 0 || ny < 0 || nx >= L || ny >= C) continue;
				int H = v[nx][ny];
				adj[H].push_back( MP(dir[d], k) );	
			}
			k++;
		}
		h = t = 0;
		q[t++] = 0;
		g[0] = 1; 
		while(h != t){			
			z = q[h++];
			int ng = g[z] + 1;
			int ox = ln[z], oy = cn[z];
			for(it = adj[z].begin(); it != adj[z].end(); it++){
				int f = (*it).first, s = (*it).second;
				int x = ln[s], y = cn[s], ov = a[x][y];
				if(g[s]){
					if(g[s] == ng && (ox < px[s] || (ox == px[s] && oy < py[s]))){
						px[s] = ox;
						py[s] = oy;
						a[x][y] = f;
					}
				} else {
					g[s] = ng;
					px[s] = ox;
					py[s] = oy;
					a[x][y] = f;
					q[t++] = s;
				}
			}
		}
		FOR(i, L) puts(a[i]);
		putc(10, stdout);
	}
	return 0;
}
