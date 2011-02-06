#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,a,n)	for(int i = a; i < n; ++i)
#define FORD(i,a,n)	for(int i = a; i > n; --i)

const int N = 100000;
int A[N], B[N], X[N];
int main(void){
	int k, m, n, q;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; ++i)
		scanf("%d %d %d", &A[i], &B[i], &X[i]);
	long long sum = 0;
	for(int i = 0; i < k; ++i){
		scanf("%d", &q);		
		for(int i = 0; i < m; ++i) 
			if(q >= A[i] && q <= B[i]) sum += X[i] + q - A[i];		
	}
	cout << sum << endl;
	return 0;
}
