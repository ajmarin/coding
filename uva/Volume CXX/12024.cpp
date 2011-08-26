#include <cstdio>
template<class _T> _T Permutations(_T n){ // Returns n!
	return n ? Permutations(n - 1) * n : 1;
}
template<class _T> _T Combinations(_T n, _T k){ // Returns n! / ( k! (n - k)! )
	_T r = 1;
	if(k < n - k) k = n - k;
	for(_T i = n; i > k; --i) r *= i, r /= (n - i + 1);
	return r;
}
template <class _T> _T PermutationsWithoutFixedPoints(_T n){
	_T r = 0;
	for(_T i = 2; i <= n; ++i){
		_T ways = Combinations(n, i) * Permutations(n - i);
		if(i & 1) r -= ways;
		else r += ways;
	}
	return r;
}
int answer[16][2];
int main(void){
	int T, n;
	for(int i = 2; i < 13; ++i){
		answer[i][0] = PermutationsWithoutFixedPoints(i);
		answer[i][1] = Permutations(i);
	}
	for(scanf("%d", &T); T--; ){
		scanf("%d", &n);
		printf("%d/%d\n", answer[n][0], answer[n][1]);
	}
	return 0;
}

