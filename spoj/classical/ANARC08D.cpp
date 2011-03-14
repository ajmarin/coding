#include <cstdio>

int s[401][801], max_sum, n;
void test_sum(int line, int left, int right, int sum){
	if(line < 0 || line >= n) return;
	if(left <= 0 || right > 1 + (line << 1)) return;
	sum += s[line][right] - s[line][left - 1];
	if(sum > max_sum) max_sum = sum;
	if(!(left & 1)) test_sum(line - 1, left - 2, right, sum);
	else test_sum(line + 1, left, right + 2, sum);
}
int main(void){
	for(int i = 0; i < 401; ++i) s[i][0] = 0;
	for(int cnum = 0; scanf("%d", &n) == 1 && n; ){
		max_sum = 1 << 31;
		for(int i = 0, l; i < n; ++i){
			l = (i << 1) + 1;
			for(int j = 1; j <= l; ++j){
				scanf("%d", &s[i][j]);
				s[i][j] += s[i][j - 1];
			}
		}
		for(int i = 0, l; i < n; ++i){
			l = (i << 1) + 1;
			for(int j = 1; j <= l; ++j) test_sum(i, j, j, 0);
		}
		printf("%d. %d\n", ++cnum, max_sum);
	}
	return 0;
}

