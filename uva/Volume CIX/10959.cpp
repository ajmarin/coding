#include <cstdio>

#define FOR(i, n) for(int i = 0; i < n; ++i)
const int NN = 1024;
int d[NN], m[NN][NN], s[NN], q[NN], v[NN];

int main(void){
	int t; scanf("%d", &t);
	for(int a, b, p, z; t-- && scanf("%d%d", &p, &z) == 2; ){
		FOR(i, p) s[i] = 0, v[i] = false;
		FOR(i, z){
			scanf("%d%d", &a, &b);
			m[a][s[a]++] = b;
			m[b][s[b]++] = a;
		}
		q[0] = d[0] = 0;
		int head = 0, tail = 1;
		while(head != tail){
			int u = q[head++], number = d[u] + 1;
			for(int i = 0; i < s[u]; ++i){
				z = m[u][i];
				if(!v[z]){
					q[tail++] = z;
					v[z] = true;
					d[z] = number;
				}
			}
		}
		FOR(i, p) if(i) printf("%d\n", d[i]);
		if(t) puts("");
	}
	return 0;
}

