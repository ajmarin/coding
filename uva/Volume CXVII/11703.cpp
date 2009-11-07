#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

#define ABS(a)		((a)< 0?-(a):(a))
#define ALL(x)		(x.begin(), x.end())
#define ALLI(x,n)	(x, x+n)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b)	FORI(a,0,b)
#define GETI(a)		scanf("%d",&a)
#define GETS(a)		scanf("%s",a)
#define GETL(a) 	fgets(a, sizeof(a), stdin)
#define IN 			getc( stdin )
#define MAX(a,b)	((a)>(b)?(a):(b))
#define MIN(a,b) 	((a)<(b)?(a):(b))
#define OUT(x)		putc(x, stdout)
#define TR(x) 		for(typeof(x.begin())it=x.begin();it!=x.end();++it)

inline double sqr(double k){ return (k*k); }
int x[1000032];
int main(void){
	int N;
	x[0] = 1;
	FORI(i, 1, 1000030){
		int a = floor(i - sqrt(i));
		int b = floor(log(i));
		int c = floor(i * sqr(sin(i)));
		x[i] = (x[a] + x[b] + x[c])%1000000;
	}
	while(scanf("%d",&N) && (N != -1)){
		printf("%d\n",x[N]);
	}
	return 0;
}

