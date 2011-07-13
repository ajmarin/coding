#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,f,n)	for(int i = f; i < n; ++i)
const int M = 50;
int q[M], qs[M];
int combine3(int n){
	return n * (n - 1) * (n - 2) / 6;
}
int main(void){
	for(int m, n; scanf("%d %d", &n, &m) && (n || m); ){
		int ans3 = 0, ans4 = 0, z;
		FOR(i, M) q[i] = qs[i] = 0;
		FOR(i, n){
			scanf("%d", &z);
			++q[--z];
		}
		z = 0;
		FOR(i, m) if(q[i]) qs[z] = q[z] = q[i], ++z;
		m = z;
		FOR(i, m) if(i) qs[i] += qs[i - 1];
		/* 3 from same country */
		FOR(i, m) if(q[i] >= 3){
			z = combine3(q[i]);
			ans3 += z;
			/* 4th from a different country */
			ans4 += z * (n - q[i]);
			/* 4th from the same country */
			if(q[i] > 3) ans4 += z * (q[i] - 3)/4;
		}
		/* Three different countries */
		FOR(i, m) FORI(j, i + 1, m) FORI(k, j + 1, m){
			z = q[i] * q[j] * q[k];
			if(!z) continue;
			ans3 += z;
			// 4 different countries
			ans4 += z * (n - qs[k]);
			// 3 different (1 repeats)
			ans4 += (z * (q[i] - 1)) / 2;
			ans4 += (z * (q[j] - 1)) / 2;
			ans4 += (z * (q[k] - 1)) / 2;
		}

		printf("%d %d\n", ans3, ans4);
	}
	return 0;
}

