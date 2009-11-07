#include <cstdio>
#include <cstring>

#define F 1000000007
#define MIN(a,b) ((a)<(b)?(a):(b))
#define NN 1010

typedef long long LL;

struct Triple{
    LL d, x, y;
    Triple() {}
    Triple( LL q, LL w, LL e ) : d( q ), x( w ), y( e ) {}
};
Triple egcd( LL a, LL b ){
    if(!b) return Triple(a, 1, 0);
    Triple q = egcd(b, a%b);
    return Triple(q.d, q.y, q.x-a/b*q.y);
}
LL invmod( LL a, LL n )
{
    Triple t = egcd( a, n );
    if( t.d > 1 ) return 0;
    LL r = t.x % n;
    return( r < 0 ? r + n : r );
}
long long im[NN], fact[NN], c[NN][NN];
LL C( LL a, LL b ){
	int LM = MIN(b, a - b), LIM;
	if(c[a][LM]) return c[a][LM];
	c[a][0] = 1; LIM = (a + 3) >> 1;
	for(int U = a, D = 1; D < LIM; ++D, --U)
		c[a][D] = (((c[a][D-1] * U)%F) * im[D])% F;
	return c[a][LM];
}

int main(void){
	int K, M, N, T, X;
	fact[0] = fact[1] = im[1] = 1;
	memset(c, 0, sizeof(c));
	for(int i = 2; i < NN; ++i){
		im[i] = invmod(i, F);
		fact[i] = (i * fact[i - 1]) % F;
	}
	scanf("%d",&T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d %d %d",&N, &M, &K);
		long long ans = C( M, K ), aux = 0;
		X = M - K;
		for(int a = 0, k = N - K; a <= X; ++a, --k){
			if(a & 1) aux = aux - (C( X, a ) * fact[k] )%F;
			else aux = aux + (C( X, a ) * fact[k])%F;
		}
		while(aux < 0) aux += F;
		aux %= F;
		printf("Case %d: %lld\n", ++cnum, (ans * aux) % F);
	}
	return 0;
}


