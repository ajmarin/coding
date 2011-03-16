#include <cctype>
#include <cstdio>

int d[128][128];
const int MAX = 4096;
/* Writing integers */
char ob[MAX], *at = ob, *end = ob + MAX - 1;
void flush_buffer(){
	fwrite(ob, 1, at - ob, stdout);
	at = ob;
}
void buffer(int k, char sep){
	if(at + 10 > end) flush_buffer();
	int d[10], dc = 0;
	if(k < 0) *at++ = '-', k = -k;
	while(k) d[dc++] = k % 10, k /= 10;
	for(int k = dc; k--; *at++ = d[k] + '0');
	*at = 0;
	*at++ = sep;
}
/* Reading integers */
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int &n){
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	for(n = 0; isdigit(*now); n = (n << 1) + (n << 3) + *now++ - '0');
}

int main(void){
	int c, lim, s, t;
	int *n, *p;
	for(readint(t); t--; ){
		readint(s); readint(c);
		for(int i = 0; i < s; ++i) readint(d[0][i]);
		for(lim = s; lim--; ){
			bool change = false;
			n = d[s - lim];
			p = d[s - lim - 1];
			for(int i = 0; i < lim; ++i){
				n[i] = p[i + 1] - p[i];
				change |= i && n[i] != n[i - 1];
			}
			if(!change){
				for(int i = lim; i < lim + c; ++i) n[i] = n[0];
				break;
			}
		}
		while(lim++ < s){
			n = d[s - lim];
			p = d[s - lim + 1]      ;
			for(int i = lim; i < lim + c; ++i) n[i] = n[i - 1] + p[i - 1]; 
		}
		if(s > 1) for(int i = s; i < s + c; ++i) buffer(n[i], i==s+c-1?10:32);
		else for(int i = 0; i < c; ++i) buffer(d[0][0], i==c-1?10:32);
	}
	flush_buffer();
	return 0;
}

