#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 2001

struct slab { int a, b, d, v; };
int defdp[MAX], N;
int dp[MAX][2], sz[2], top, total;
slab s[401];
bool c, p, v[MAX], vdiff[1001];

bool ord(slab x, slab y){
	return ((x.d > y.d) || ((x.d == y.d) && (x.a > y.a)));
}
void include(int k){
	if(k > top || v[k]) return;
	v[k] = 1;
	dp[sz[c]++][c] = k;
}
bool DP(int ign){
	int i, j, k;
	top = min(total, 2000);
	dp[0][0] = p = 0;
	c = sz[0] = 1;
	for(i = 0; i < N; i++){
		if(i == ign) continue;
		memset(v,0,top);
		for(sz[c] = j = 0; j < sz[p]; j++){
			k = dp[j][p] + s[i].d;
			include(k);
			k = abs(dp[j][p] - s[i].d);
			include(k);
		}
		c = p;
		p = !p;
	}
	return v[0];
}
int main(void){
	int dis, dz, i, j, k, max_sum, sum;
	s[400].d = -15;
	while(scanf("%d",&N) && N){
		memset(vdiff, 0, sizeof(vdiff));
		for(sum = total = i = 0; i < N; i++){
			scanf("%d%d",&s[i].a,&s[i].b);
			if(s[i].b > s[i].a) swap(s[i].a,s[i].b);
			s[i].d = s[i].a - s[i].b;
			s[i].v = s[i].a + s[i].b;
			vdiff[s[i].d] = 1;
			total += s[i].d;
			sum += s[i].v;
		}
		if(N == 1){
			if(total) printf("0 discard %d %d\n",s[0].b,s[0].a);
			else printf("%d discard none\n",s[0].a);
			continue;
		}
		sort(s,s+N,ord);
		dis = max_sum = -1;
		if(DP(-1)){ printf("%d discard none\n",sum>>1); continue; }
		for(i = 0; i < sz[p]; i++) defdp[i] = dp[i][p];
		for(dz = sz[p], i = 0; i < dz; i++)
			if(defdp[i] < 1001 && vdiff[defdp[i]]){
				for(j = 0, k = N-1; j < k; ){
					int m = (j + k)>>1;
					if(s[m].d > defdp[i]) j = m+1;
					else k = m;
				}
				while(s[++j].d == defdp[i]);
				if(--j < dis || max_sum >= (sum-s[j].v)) continue;
				if(DP(j)) dis = j, max_sum = (sum - s[j].v);
			}
		if(max_sum == -1) printf("impossible\n");
		else printf("%d discard %d %d\n",max_sum>>1,s[dis].b,s[dis].a);

	}

	return 0;
}

