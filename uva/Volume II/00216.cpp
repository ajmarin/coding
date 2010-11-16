#include <cmath>
#include <cstdio>
bool connected[8];
double bd[8], d[8], mind;
int bc[8], c[8], x[8], y[8];
int bb, begin;
int sqr(int x){ return x * x; }
double dist(int a, int b){ return sqrt(sqr(x[a] - x[b]) + sqr(y[a] - y[b])); }
void bt(int k, int n, double td, int tc){
	connected[k] = 1;
	if(tc < n) {
		for(int i = 0; i < n; ++i)
			if(!connected[i]){
				c[k] = i;
				d[k] = dist(k, i) + 16;
				bt(i, n, td + d[k], tc + 1);
			}
	}
	if(tc == n && td < mind){
		mind = td;
		for(int i = 0; i < n; ++i) bc[i] = c[i], bd[i] = d[i];
		begin = bb;
	}
	connected[k] = 0;
	c[k] = d[k] = -1;
}
int main(void){
	for(int i = 0; i < 8; ++i) c[i] = d[i] = -1, connected[i] = 0;
	for(int n, network = 1; scanf("%d", &n) == 1 && n; ++network){
		for(int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);
		mind = 1e10;
		for(int i = 0; i < n; ++i) bb = i, bt(i, n, 0, 1);
		puts("**********************************************************");
		printf("Network #%d\n", network);
		for(int i = begin, j = bc[i]; j != -1; i = j, j = bc[j])
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", 
					x[i], y[i], x[j], y[j], bd[i]);
		printf("Number of feet of cable required is %.2lf.\n", mind);
	}
	return 0;
}

