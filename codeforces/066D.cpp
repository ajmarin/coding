#include <cstdio>
int p[51] = 
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,
73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,
157,163,167,173,179,181,191,193,197,199,211,223,227,229,233};
int v[50];
int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }
int main(void){
	int n; scanf("%d", &n);
	v[0] = 6; v[1] = 15;
	for(int i = 2; i < 50; ++i) v[i] = 10 * p[i + 1];
	if(n == 2) puts("-1");
	else for(int i = 0; i < n; ++i) printf("%d\n", v[i]);
	return 0;
}

