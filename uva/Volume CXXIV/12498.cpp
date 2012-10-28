#include <algorithm>
#include <cstdio>
using namespace std;

char s[64][64];

int main(void){
	int t; scanf("%d", &t);
	for(int r, c, cnum(0); cnum++ < t && scanf("%d %d", &r, &c) == 2; ){
		bool possible = true;
		for(int i = 0; i < r; ++i){
			scanf("%s", s[i]);
			bool has_zero = false;
			for(int j = 0; !has_zero && j < c; ++j)
				has_zero |= s[i][j] == '0';
			possible &= has_zero;
		}
		printf("Case %d: ", cnum);
		if(!possible) puts("-1");
		else {
			int min_moves = r * c, moves;
			int cL, cR, dL, dR;
			for(int col = 0; col < c; ++col){
				moves = 0;
				for(int row = 0; row < r; ++row){
					dL = dR = 128;
					for(cL = col; cL >= 0 && s[row][cL] == '1'; --cL);
					if(cL != -1) dL = col - cL;
					for(cR = col; cR < c && s[row][cR] == '1'; ++cR);
					if(cR != c) dR = cR - col;
					moves += min(dL, dR);
				}
				min_moves = min(min_moves, moves);
			}
			printf("%d\n", min_moves);
		}
	}
	return 0;
}

