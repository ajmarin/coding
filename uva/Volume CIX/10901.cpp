#include <cstdio>

const int NN = 10048;
char where[16];
int at[NN], cross[NN];
bool side[NN];

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }

int main(void){
	int t; scanf("%d", &t);
	for(int m, n, z; t-- && scanf("%d %d %d", &n, &z, &m) == 3; ){
		int left, right, time = 0;
		for(int i = 0; i < m; ++i){
			scanf("%d %s", at + i, where);
			side[i] = where[0] == 'l';
		}
		for(left = 0; left < m && !side[left]; ++left);
		for(right = 0; right < m && side[right]; ++right);
		at[m] = 1 << 30;
		while(left < m || right < m){
			time = max(time, min(at[left], at[right]));
			for(int i = 0; i < n && at[left] <= time; ++i){
				cross[left] = time + z;
				while(++left < m && !side[left]);
			}
			time += z; // go right
			time = max(time, min(at[left], at[right]));
			for(int i = 0; i < n && at[right] <= time; ++i){
				cross[right] = time + z;
				while(++right < m && side[right]);
			}
			time += z; // back left
		}
		for(int i = 0; i < m; ++i) printf("%d\n", cross[i]);
		if(t) puts("");
	}
}

