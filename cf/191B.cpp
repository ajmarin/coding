#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i,n) for(i = 0; i < n; ++i)
int c[100048], z[100048];

bool ord(int a, int b){ return c[a] > c[b]; }

int main(void){
	for(int i, n, k; cin >> n >> k; ){
		long long int m, s = 0;
		cin >> m;
		FOR(i, n) cin >> c[i], z[i] = i;
		sort(z, z + n - 1, ord);
		FOR(i, k) s += c[z[i]];
		if(s <= m) cout << n << endl;
		else {
			FOR(i, n) if(s - c[z[k - 1]] + c[i] > m) break;
			cout << (i+1) << endl;
		}
	}
	return 0;
}

