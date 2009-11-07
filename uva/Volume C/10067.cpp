#include <cctype>
#include <cstdio>
#include <cstring>

#define IN getc( stdin )
#define NN 10000

typedef unsigned short int USI;
bool v[NN];
USI q[NN], s[NN];
USI a[2] = {1, 9};
USI dig[4];

void GET(register USI *n, char d){
	register char c;
	*n = 0;
	for(char a = 0; a < d; ++a){
		while(!isdigit(c = IN));
		*n = *n * 10 + c - '0';
	}
}
USI mount(USI a, USI b, USI c, USI d){
	return 1000 * a + 100 * b + 10 * c + d;
}

int main(void){
	USI B, F, N, S, T;
	scanf("%hd",&T);
	while(T--){
		GET(&S, 4); GET(&F, 4);
		scanf("%hd",&N);
		memset(v, 0, NN);
		while(N--){
			GET(&B, 4);
			v[B] = 1;
		}
		USI h, t;
		h = t = s[S] = 0;
		q[t++] = S;
		v[S] = 1;
		while(h != t){
			USI x = q[h++], y = x;
			for(char i = 0; i < 4; ++i) dig[i] = y % 10, y /= 10;
			for(char i = 0; i < 4; ++i){
				for(char j = 0; j < 2; ++j){
					USI b = dig[i];
					dig[i] = (dig[i] + a[j]) % 10;
					USI y = mount(dig[3], dig[2], dig[1], dig[0]);
					if(!v[y]){
						v[y] = 1;
						q[t++] = y;
						s[y] = s[x] + 1;
					}
					dig[i] = b;
				}
			}
			if(v[F]) break;
		}
		if(v[F]) printf("%hd\n",s[F]);
		else puts("-1");
	}
	return 0;
}

