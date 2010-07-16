#include <cstdio>
#include <string>
using namespace std;
int r[10], c[10];
int m[10][10], s[10][10];
string mn[] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10"};
string p(int i, int j){
	string r;
	if (j > i) r = "(" + p(i, s[i][j]) + " x " + p(s[i][j] + 1, j) + ")";
	else r = mn[i];
	return r;
}
int main(void){
	int cnum = 0, n;
	while(scanf("%d", &n) && n){
		int *pr = r, *pc = c;
		for(int i = 0; i < n; ++i, ++pr, ++pc){
			scanf("%d %d", pr, pc);
			for(int j = 0; j < n; ++j) m[i][j] = s[i][j] = 0;
		}
		for(int d = 1; d <= n; ++d){
			for(int i = 0; i < n - d; ++i){
				int j = i + d;
				m[i][j] = 0x7FFFFFFF;
				for(int k = i; k <= j - 1; ++k){
					int temp = m[i][k] + m[k + 1][j] + r[i] * c[k] * c[j];
					if(temp < m[i][j]){
						m[i][j] = temp;
						s[i][j] = k;
					}
				}
			}
		}
		printf("Case %d: %s\n", ++cnum, p(0, n - 1).c_str());
	}
	return 0;
}
