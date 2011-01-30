#include <cmath>
#include <cstdio>
#include <ctime>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,a,n)	for(int i = a; i < n; ++i)
#define FORD(i,a,n)	for(int i = a; i > n; --i)

int abs(int a){ return a < 0 ? -a : a; }
int main(void){
	int n, x1, x2, y1, y2;
	scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
	int dist = 1 << 15, d1[4], d2[4];
	if((x1 == x2 && (x1 == 0 || x1 == n)) ||  (y1 == y2 && (y1 == 0 || y1 == n)))
		dist = abs(x1 - x2) + abs(y1 - y2);
	else {
		d1[0] = x1 + y1;
		d2[0] = x2 + y2;
		//printf("Dist to (0, 0) = [%d] [%d]\n", d1[0], d2[0]);
		d1[1] = (n - x1) + y1;
		d2[1] = (n - x2) + y2;
		//printf("Dist to (n, 0) = [%d] [%d]\n", d1[1], d2[1]);
		d1[2] = (n - x1) + (n - y1);
		d2[2] = (n - x2) + (n - y2);
		//printf("Dist to (n, n) = [%d] [%d]\n", d1[2], d2[2]);
		d1[3] = x1 + (n - y1);
		d2[3] = x2 + (n - y2);
		//printf("Dist to (0, n) = [%d] [%d]\n", d1[3], d2[3]);
		for(int i = 0; i < 4; ++i)
			if(d1[i] + d2[i] < dist) dist = d1[i] + d2[i];
	}
	//printf("oi\n");
	printf("%d\n", dist);
	return 0;
}
