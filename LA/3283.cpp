#include <cstdio>
#include <cstring>
#include <cctype>

#define IN getc( stdin ) 
#define NN 500050

int d[NN], nv[NN], p[NN], q[NN], v[NN];
int main(void){
	int h, maxval, t, N;
	for(int i = 0; i < NN; ++i) d[i] = nv[i] = 0;
	while(scanf("%d\n",&N) && N){
		p[0] = -1; nv[0] = 0;
		int *pp = p+1, *vv = v+1;
		for(int i = 1; i < N; ++i){
			scanf("%d %d",pp,vv);
			nv[i] = 0; d[*pp]++;
			pp++; vv++;
		}
		h = maxval = t = 0;
		for(int i = 0; i < N; ++i) q[t] = i, t += (!d[i]);
		while(h != t){
			int x = q[h++];
			if(p[x] == -1) continue;
			int val = nv[x] + v[x], mm = val + nv[p[x]];
			if(mm > maxval) maxval = mm;
			if(val > nv[p[x]]) nv[p[x]] = val;
			q[t] = p[x];
			t += !--d[p[x]];
		}
		printf("%d\n",maxval);

	}
	return 0;
}

