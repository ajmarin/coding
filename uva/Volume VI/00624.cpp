#include <cctype>
#include <cstdio>

#define IN getc( stdin )
#define NN 20040

void tni( register int *n ){
	register char c;
	while(!isdigit(c = IN));
	for(*n = 0; isdigit(c); c = IN) *n = *n * 10 + c - '0';
}
bool oc[NN];
int list[NN], n[NN], p[NN], v[32];

int main(void){
	int i, L, N, NS, T;
	while(scanf("%d",&T) == 1){
		tni(&N);
		for(i = 0; i <= T; ++i) oc[i] = p[i] = 0;
		L = NS = 0;
		for(i = 0; i < N; ++i, ++NS){
			tni(v + i); 
			for(int j = 0; j < L; ++j){
				int k = list[j] + v[i];
				if(k > T || oc[k]) continue;
				oc[k] = 1;
				n[NS++] = k;
				p[k] = list[j];
			}
			if(!oc[v[i]]){
				oc[v[i]] = 1;
				n[NS++] = v[i];
				p[v[i]] = 0;
			}
			while(NS--) list[L++] = n[NS];
		}
		for(i = T; !oc[i]; i--);
		int s = i;
		do { printf("%d ",i - p[i]); } while(i = p[i]);
		printf("sum:%d\n", s);
	}
	return 0;
}

