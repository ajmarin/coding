#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; ++i)
int M;
template <typename _T> class Matrix {
	int n;
public:
	vector < vector < _T > > m;
	Matrix(int _n){
		n = _n;
		m = vector< vector< _T > >(n, vector<_T>(n, 0));
	}
	void show(){
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) printf("%d%c", m[i][j], j == n - 1 ? 10 : 32);
	}
	vector<_T>& operator[](int a){ return m[a]; }
	Matrix pow(int p){
		Matrix r = Matrix(n), b = *this;
		for(int i = 0; i < n; ++i) r.m[i][i] = 1;
		while(p){
			if(p & 1) r *= b;
			b *= b;
			p >>= 1;
		}
		return r;
	}
	Matrix operator*=(Matrix& A){
		Matrix r = Matrix(n);
		FOR(i, n) FOR(j, n){
			_T sum = 0; 
			FOR(k, n) if(m[i][k] && A.m[k][j]) sum += (m[i][k] * A.m[k][j]);
			r[i][j] = sum;
		}
		return *this = r;
	}
};


int main(void){
	Matrix<int> m(2);
	m[0][0] = m[0][1] = m[1][0] = 1;
	m[1][1] = 0;
	for(int n, z; scanf("%d %d", &n, &z) == 2; ){
		if(n < 2) printf("%d\n", n);
		else printf("%d\n", m.pow(n - 1)[0][0] & (1 << z) - 1);
	}
	return 0;
}

