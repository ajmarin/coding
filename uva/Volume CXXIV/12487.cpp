#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; ++i)
const int N = 128;
double p[N], p2[N];
bool adj[N][N];
int cnt[N];
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
			for(int j = 0; j < n; ++j) printf("%.3lf%c", m[i][j], j == n - 1 ? 10 : 32);
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
	for(int n, a, b, c; scanf("%d %d %d %d", &n, &a, &b, &c) == 4; ){
		Matrix<double> m = Matrix<double>(n);
		--a; --b; --c;
		FOR(i, n){
			p[i] = i == a ? 1 : 0;
			cnt[i] = 0;
			FOR(j, n) adj[i][j] = 0;
		}
		for(int x, y, i = 1; i < n; ++i){
			scanf("%d %d", &x, &y);
			--x; --y;
			adj[x][y] = adj[y][x] = 1;
			++cnt[x]; ++cnt[y];
		}
		FOR(i, n){
			if(i == b || i == c) m[i][i] = 1;
			else {
				double newp = 1 / double(cnt[i]);
				FOR(j, n) if(adj[i][j]) m[i][j] = newp;
			}
		}
		m = m.pow(1 << 15);
		double ans = 0;
		FOR(j, n) ans += p[j] * m[j][b];
		printf("%.6lf\n", ans);
	}
	return 0;
}

