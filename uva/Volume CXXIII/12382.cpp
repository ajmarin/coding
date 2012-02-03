#include <algorithm>
#include <cstdio>
using namespace std;

#define NN 1024
int r[NN];

int main(void){
	int t; scanf("%d", &t);
	for(int rows, cols; t-- && scanf("%d %d", &rows, &cols) == 2; ){
		int lighten = 0;
		for(int i = 0; i < rows; ++i){
			scanf("%d", r + i);
			lighten += r[i];
		}
		for(int i = 0, z; i < cols; ++i){
			scanf("%d", &z);
			sort(r, r + rows);
			for(int row = rows; z && row--; ){
				if(!r[row]) break;
				z -= r[row] > 0;
				r[row] -= r[row] > 0;
			}
			lighten += z;
		}
		printf("%d\n", lighten);
	}
	return 0;
}

