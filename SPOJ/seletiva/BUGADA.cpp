#include <cstdio>

#define BASE 1300031
struct Triple{
    int d, x, y;
    Triple() {}
    Triple( int q, int w, int e ) : d( q ), x( w ), y( e ) {}
};
/* Retorna uma tripla T, onde
** gcd(a,b) = T.d = T.x * a + T.y * b
*/
Triple egcd( int a, int b ){
    if(!b) return Triple(a, 1, 0);
    Triple q = egcd(b, a%b);
    return Triple(q.d, q.y, q.x-a/b*q.y);
}
/* Retorna x tal que ax = 1 (mod n) */
int invmod( int a, int n )
{
    Triple t = egcd( a, n );
    if( t.d > 1 ) return 0;
    int r = t.x % n;
    return( r < 0 ? r + n : r );
}

int main(void){
	int c, N, P, T;
	long long x, i, imod[15002];
	for(i = 1; i < 15002; i++) imod[i] = invmod(i,BASE);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&P);
		if(P > (N+2+(N<<1))>>1) P = 3*N - P;
		for(i = 3*N, c = x = 1; c <= P; i--, c++)
			x = (x*i*imod[c])%BASE;
		printf("%lld\n",x);
	}
	return 0;
}

