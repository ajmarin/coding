/////////////////////////////////
// 10104 - Euclid Problem
/////////////////////////////////
#include<cstdio>
int A,B;
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
Triple t;
int main(void){
	while(scanf("%d%d",&A,&B)!=EOF)
		if(A>=B) t = egcd(A,B),printf("%d %d %d\n",t.x,t.y,t.d);
		else t = egcd(B,A),printf("%d %d %d\n",t.y,t.x,t.d);
	return 0;
}
