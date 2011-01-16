#include <cstdio>
#define min(a,b) ((a<b)?(a):(b))
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
int FUUUUUUUCK(int a, int b, int c){
	int x, n;
	if(a < 0)
		n = (-a / b) + 1,
		x = a + b * n,
		x *= c;
	else
		n = (a / b),
		x = a - b * n,
		x *= c;
	if(x > 0) return x;
	else return 1<<31;
}
int main(void){
	int a, b, c, s, w;
	scanf("%d%d%d",&c,&a,&b);
	Triple t;
	if(a < b) a ^= b ^= a ^= b;
	t = egcd(a,b);
	t.x *= c/t.d; t.y *= c/t.d;
	s = a / t.d; w = b / t.d;
	//printf("x = %+d + %d * n\ny = %+d - %d * n\n",t.x,w,t.y,s);
	int res = min(FUUUUUUUCK(t.x,w,a),FUUUUUUUCK(t.y,s,b));
	printf("%d\n",res);
	return 0;
}
