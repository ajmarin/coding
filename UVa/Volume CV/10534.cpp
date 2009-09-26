#include <cstdio>
#include <cctype>
#define NN 10000
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))
int b[NN], lr[NN], nums[NN];
int lis(int n){
	if (n < 1) return 0;
	int i, min, max, u, v, tail = -1;
	b[++tail] = 0;
	for (lr[0] = i = 1; i < n; lr[i++] = tail+1) {
		if (nums[b[tail]] < nums[i]) {
			b[++tail] = i;
			continue;
		}
		for (u = 0, v = tail; u < v;) {
			int c = (u + v)>>1;
			if (nums[b[c]] < nums[i]) u=c+1; else v=c;
		}
		if (nums[i] < nums[b[u]]) b[u] = i;
	}
	b[0] = n-1;
	max = tail = 0;
	for(i = n-1; i--; ){
		if(nums[b[tail]] < nums[i]) b[++tail] = i;
		else {
			for(u = 0, v = tail; u < v;) {
				int c = (u+v)>>1;
				if(nums[b[c]] < nums[i]) u=c+1; else v=c;
			}
			if(nums[i] < nums[b[u]]) b[u] = i;
		}
		max = MAX(max,MIN(tail+1,lr[i]));
	}
	return (max<<1)-1;
}
void fastint( register int *n ){
	register char c;
	*n = 0;
	while(!isdigit(c = getc( stdin )));
	do {
		switch( c ){
			case ' ': case '\n': return;
			default: (*n) *= 10; (*n) += ( c - '0' ); break;
		}
	}while( ( c = getc( stdin ) ));
}
int main(void){
	int i, N;
	while(scanf("%d\n",&N)==1){
		for(i = 0; i < N; i++) fastint(&nums[i]);
		printf("%d\n",lis(N));
	}
	return 0;
}

