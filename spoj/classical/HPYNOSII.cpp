#include <cctype>
#include <cstdio>
 
int sqr[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
bool v[1024];
int chain[1024];
const int MAX = 2048;
/* Writing integers */
char ob[MAX], *at = ob, *end = ob + MAX - 1;
void flush_buffer(){
	fwrite(ob, 1, at - ob, stdout);
	at = ob;
}
void buffer(int k){
	if(at + 10 > end) flush_buffer();
	int d[10], dc = 0;
	if(k < 0) *at++ = '-', k = -k;
	while(k) d[dc++] = k % 10, k /= 10;
	for(int k = dc; k--; *at++ = d[k] + '0');
	*at = 0;
	*at++ = 10;
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

int sdsq(int k){
        int r = 0;
        for(; k; r += sqr[k % 10], k /= 10);
        return r;
}
int calc_chain(int n){  
        int c;
        for(int i = 0; i < 1024; ++i) v[i] = false;
        for(c = 0; n != 1; ++c){
                if(v[n = sdsq(n)]) break;
                v[n] = true;
        }
        return v[1] ? c : -1;
}
int main(void){
        int t; readint(t);
        for(int i = 0; i < 1024; ++i) chain[i] = calc_chain(i);
        while(t--){
                int c = 0, n; readint(n);
                if(n > 1024) n = sdsq(n), ++c;
                if(chain[n] == -1) buffer(-1);
				else buffer(c + chain[n]);
        }
		flush_buffer();
}

