#include <cstdio>
#include <cstring>
#include <cctype>

#define NN 10000
#define IN getc( stdin )

int q[NN], p[NN], B[15];
bool v[NN];
void fastint( register int *n ){
	register char c;
	*n = 0;
	while(!isdigit(c = IN));
	do {
		(*n) *= 10; (*n) += ( c - '0' );
		c = IN;
	} while(isdigit(c));
}
int main(void){
	int L, U, R, cnum = 0;
	int h, t;
	while(true){
		fastint(&L); fastint(&U); fastint(&R);
		if(!(L || U || R)) break;
		memset(v,0,sizeof(v));
		printf("Case %d: ",++cnum);
		h = t = 0;
		q[t++] = L;
		v[L] = 1;
		p[L] = 0;
		for(int i = 0; i < R; ++i) fastint(&B[i]);
		while(h != t && !v[U]){
			int x = q[h++], press = p[x];
			for(int i = 0; i  < R; ++i){
				int y = (x + B[i])%10000;
				if(!v[y]){
					v[y] = 1;
					q[t++] = y;
					p[y] = press + 1;
				}
			}
			if(v[U]) break;
		}
		if(v[U]) printf("%d\n",p[U]);
		else printf("Permanently Locked\n");
	}
	return 0;
}

