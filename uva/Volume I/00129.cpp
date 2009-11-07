#include <cstdio>
#include <cstring>

//#define DEBRG 

int n, L, N;
char LS, o[65536], s[32768];
bool done;

bool h(int r){
	int c, i, CLS = (r + 3) >> 1;
	char *a, *b, *d;
	for(i = 2; i < CLS; i++){
		for(c = 0, a = s + r, b = d = s + r - i; a > d; )
			if (*a-- == *b--) c++;
			else break;
		if (c == i) return 0;
	}
	return 1;
}
void bt(int k){
	if(n == N){ s[k] = 0; done = 1; return; }
	for(char i = 'A'; i < LS; ++i){
		if(k && s[k - 1] == i) continue;
		s[k] = i;
		if (!h(k)) continue;
		n++; bt(k + 1);
		if(done) return;
	}
}
int main(void){
	while(scanf("%d%d",&N,&L) && N){
		memset(s, 0, N);
		done = n = 0; LS = 'A' + L;
		bt(0);
		register char *c = o, *d; int i;
		for(d = s, i = 0; *d; d++, i++){
			if(i){
				if(!(i & 63)) *c++ = 10;
				else if(!(i & 3)) *c++ = ' ';
			}
			*c++ = *d;
		}
		*c = 0;
		puts(o);
		printf("%d\n",d - s);
	}
	return 0;
} 
