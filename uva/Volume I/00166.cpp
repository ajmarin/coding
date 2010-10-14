#include <cstdio>

#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b) 	for(int a = 0; a < b; ++a)
int min(int x, int y){ return x < y ? x : y;}
int cc[6], cv[6] = {5, 10, 20, 50, 100, 200};
int change[500];
int count(int v){
	int cnt = 0, x;
	for(int i = 5; i >= 0; i--){
		x = min(cc[i], v / cv[i]);
		v -= x * cv[i];
		cnt += x;
	}
	if(v) cnt += 10000;
	return cnt;
}
int main(void){
	FOR(i, 6) cc[i] = 100;
	change[0] = 0;
	for(int i = 5; i < 501; i += 5) change[i] = count(i);
	while(1){
		int sum = 0, lim, minc = 10000, t, v;
		FOR(i, 6) scanf("%d", &cc[i]), sum += cc[i];
		scanf("%d.%2d", &v, &t);
		if(!sum) break;
		v = 100 * v + t;
		lim = v + 501;
		for(int i = v; i < lim; i += 5) minc = min(count(i) + change[i - v], minc);
		printf("%3d\n", minc);
	}
	return 0;
}

