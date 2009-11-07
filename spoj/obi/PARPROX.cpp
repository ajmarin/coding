#include <cstdio>
#include <cmath>
int main(void){
	int n;
	long long p[1000][2], dmin = 1LL<<50;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%lld%lld",&p[i][0],&p[i][1]);
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++){
			long long a, b, c;
			a = p[j][0] - p[i][0];
			b = p[j][1] - p[i][1];
			if((c = (a*a)+(b*b)) < dmin) dmin = c;
		}
	printf("%.3lf\n",sqrt(((double)dmin)));
}

