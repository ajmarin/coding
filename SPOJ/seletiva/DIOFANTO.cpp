#include<cstdio>
struct Triple{
    int d, x, y;
    Triple() {}
    Triple( int q, int w, int e ) : d( q ), x( w ), y( e ) {}
};
Triple egcd( int a, int b ){
    if(!b) return Triple(a, 1, 0);
    Triple q = egcd(b, a%b);
    return Triple(q.d, q.y, q.x-a/b*q.y);
}
int invmod( int a, int n )
{
    Triple t = egcd( a, n );
    if( t.d > 1 ) return 0;
    int r = t.x % n;
    return( r < 0 ? r + n : r );
}
int c, i, j, n, t;
long long inv[1000000], k, r;
long long MMM = 1300031;
int main(void){
	inv[1] = 1;
	for(i = 2; i < 1000000; i++)
		inv[i] = (inv[i-1]*invmod(i,1300031))%MMM;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&c);
		int p = ((c < n-1) ? c : n-1);
		for(k = c+n-1, r = i = 1; i <= p; i++,k--)
			r = (r*k)%MMM;
		printf("%lld\n",((r%MMM)*(inv[p]%MMM))%MMM);
	}
	return 0;
}