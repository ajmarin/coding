#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
#define FORD(i, n)	for(int i = n; i > -1; --i)
#define IN(x)		(x = getc(stdin))
#define MAX(a,b)	((a) > (b) ? (a) : (b))
#define MIN(a,b)	((a) < (b) ? (a) : (b))
#define OUT(x)		putc(x, stdout)

int a[128], b[128];
int main(void){
	int n, v;
	int sum = 0;
	scanf("%d %d", &n, &v);
	FOR(i, n) scanf("%d", &a[i]), sum += a[i];
	FOR(i, n) scanf("%d", &b[i]);
	double x = 1e10;
	FOR(i, n) x = min(x, b[i] / (double)a[i]);
	printf("%.6lf\n", min((double)v, x * sum));
	return 0;
}

