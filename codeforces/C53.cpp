#include <cmath>
#include <cstdio>
#include <iostream>
#include <ctime>
using namespace std;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,a,n)	for(int i = a; i < n; ++i)
#define FORD(i,a,n)	for(int i = a; i > n; --i)
const long long BASE = 1000000007;
struct Triple{
    long long d, x, y;
    Triple() {}
    Triple( long long q, long long w, long long e ) : d( q ), x( w ), y( e ) {}
};
Triple egcd( long long a, long long b ){
    if(!b) return Triple(a, 1, 0);
    Triple q = egcd(b, a%b);
    return Triple(q.d, q.y, q.x-a/b*q.y);
}
long long invmod( long long a, long long n ){
    Triple t = egcd( a, n );
    if( t.d > 1 ) return 0;
    long long r = t.x % n;
    return( r < 0 ? r + n : r );
}
int main(void){
	long long ans, den = 1, num = 2;
	int n;
	scanf("%d", &n);
	FORI(i, 2, n+1){
		num = (num * ((i<<2) - 2)) % BASE;
		den = (den * i) % BASE;
	}
	ans = (num * invmod(den, BASE) - n + BASE) % BASE;
	cout << ans << endl;
	return 0;
}

/* 
** Number of increasing sequences of length n using only numbers 1..n
** a[i] > a[i - 1] for i > 0
** a[i] >= 1 && a[i] <= n for i = 0..n-1
** Representing sequence as a string formed by '_' and '+'
** where '_' means show number and '+' means add 1 (we start with 1)
** e.g. 1444 = _ + + + _ _ _
** We have n-1 '+' and n '_' 
** The number of possible sequences of size n is to count all permutations:
** F(n) = (2*n + 1)!
** with n-1 '+' repeating and n '_' repeating 
** to remove duplicates:
** G(n) = (2*n + 1)! / ((n - 1)! * n!)
** G(n) is the number of increasing sequences
** if we want increasing or decreasing sequences - H(n):
** H(n) = 2 * G(n) - n
** H(n) = 2 * (2n + 1)! / (n-1)! / n! = 2 * n * (2n+1)! / (n*(n-1)!) / n! - n
** H(n) = 2n! / (n!)^2 - n
** H(n) = C(2n, n) - n
*/