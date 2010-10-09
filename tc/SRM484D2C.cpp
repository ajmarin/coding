#include <cstdio>
#include <string>
#include <vector>
using namespace std;
typedef long long ret;
int n;
int mask[8];
int m1[4] = {0, 2, 5, 7};
int m2[4] = {1, 3, 4, 6};
int adj[4][3] ={{1, 3, 4},
				{1, 3, 6},
				{1, 4, 6},
				{3, 4, 6}};
void bitclear(int m, int i){
	mask[i] &= ~m;
}
void bitset(int m, int i){
	mask[i] |= m;
}
ret bt(int k){
	ret r = 0;
	int x = m1[k];
	if(k == 4){
		r = 1;
		for(int i = 0; i < 4; ++i) r *= __builtin_popcount(mask[m2[i]]);
		return r;
	}
	int pmask[4];
	for(int i = 0; i < n; ++i){
		int tmask = 1 << i;
		if(tmask & mask[x]){
			for(int j = 0; j < 3; ++j){
				int z = adj[k][j];
				pmask[j] = mask[z];
				mask[z] &= ~tmask;
			}
			r += bt(k + 1);			
			for(int j = 0; j < 3; ++j) mask[adj[k][j]] = pmask[j];
		}
	}
	return r;
}
class CubeColoring {
	public: ret theCount(vector < string >);
};
ret CubeColoring::theCount(vector < string > colors){
	n = colors[0].size();
	for(int i = 0; i < 8; ++i){
		mask[i] = 0;
		for(int j = 0; j < n; ++j)
			mask[i] |= ((colors[i][j] == 'Y') << (n - j - 1));
	}	
	return bt(0);
}
