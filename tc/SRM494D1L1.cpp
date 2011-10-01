#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORD(a,b,c)	for(int a = b; a > c; --a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
int v[64][64];
int m, n;
vector < string > p;
bool cr(int i, int j, int s){
	for(int k = j; k < j + s; ++k) if(p[i][k] == 'W') return false;
	return true;
}
bool cc(int i, int j, int s){
	for(int k = i; k < i + s; ++k) if(p[k][j] == 'W') return false;
	return true;
}
class Painting {
public:
	int largestBrush( vector <string> picture ) {
		int c = picture[0].size(), r = picture.size();
		int b = min(c, r);
		p = picture;
		FOR(i, r) FOR(j, c) v[i][j] = 0;
		FOR(i, r) FOR(j, c){
			if(picture[i][j] == 'B'){
				int bs = 1, L = min(r - i, c - j);
				while(bs <= L){
					if(!cr(i + bs - 1, j, bs) || !cc(i, j + bs - 1, bs)){
						--bs;
						break;
					}
					++bs;
				}
				if(bs > L) bs = L;
				FORI(ii, i, i + bs) FORI(jj, j, j + bs)
					v[ii][jj] = max(v[ii][jj], bs);
			}
		}
		FOR(i, r) FOR(j, c) if(picture[i][j] == 'B') b = min(b, v[i][j]);
		return b;
	}
};
