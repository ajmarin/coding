#include <cstdio>

#define N 16
#define NN (1 << 16)
int ck[NN], q[NN], qp, qs, r[N];
long long s[NN];
char opt[128];
void cast(int *x){
	*x = 0;
	for(char *p = opt; *p; ++p)
		*x = ((*x) << 1) + (*p == '1');
}
void push(int a, int b){
	*(q + qs) = a; *(ck + qs++) = b;
}
int main(void){
	int cs, n, t; scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		qp = qs = 0;
		scanf("%d", &n);
		for(int i = 0; i < (1 << n); ++i) s[i] = 0;
		scanf("%s", opt), cast(&cs);
		for(int i = 0; i < n; ++i) scanf("%s", opt), cast(r + i);
		push(0, cs);
		s[0] = 1;
		while(qp < qs){
			int cid = q[qp], cck = ck[qp++];
			for(int i = 0; i < n; ++i){
				int mm = 1 << i;
				if((cck & mm) && !(cid & mm)){
					int nid = cid | mm, nck = cck | r[n - i - 1];
					if(!s[nid]) push(nid, nck);
					s[nid] += s[cid];
				}
			}
		}
		printf("Case %d: %lld\n", cnum, s[(1 << n) - 1]);
	}
	return 0;
}
