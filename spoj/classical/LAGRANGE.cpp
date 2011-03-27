#include <cmath>
#include <cstdio>

const int LIM = 32769;
int lim[LIM], w[LIM];
void bt(int m, int s, int d){
	if(s >= LIM) return;
	++w[s];
	if(d == 4) return;
	for(int i = m; i < lim[s]; ++i) bt(i, s + i*i, d + 1);
}
int main(void){
	for(int i = 0; i < LIM; ++i) w[i] = 0, lim[i] = floor(sqrt(LIM - i) + 1);
	bt(1, 0, 0);
	for(int n; scanf("%d", &n) == 1 && n; printf("%d\n", w[n]));
	return 0;
}

