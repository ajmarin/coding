#include <algorithm>
#include <cctype>
#include <cstdio>
#include <vector>

using namespace std;

#define NN 100038
/* {{{ FAST integer input */
#define X10(n)	((n << 3) + (n << 1))
#define RI		readint
const int MAXR = 65536;
char buf[MAXR], *lim = buf + MAXR - 1, *now = lim + 1;
bool adapt(){ // Returns true if there is a number waiting to be read, false otherwise
	while(now <= lim && !isdigit(*now)) ++now;
	if(now > lim){
		int r = fread(buf, 1, MAXR-1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		if(r == MAXR - 1){
			while(isdigit(*lim)) ungetc(*lim--, stdin);
			if(*lim == '-') ungetc(*lim--, stdin);
		}
		now = buf;
	}
	while(now <= lim && !isdigit(*now)) ++now;
	return now <= lim;
}
bool readint(int& n){ // Returns true on success, false on failure
	if(!adapt()) return false;
	bool ngtv = *(now - 1) == '-';
	for(n = 0; isdigit(*now); n = X10(n) + *now++ - '0');
	if(ngtv) n = -n;
	return true;
}
/* }}} end FAST integer input */

int nf[NN], p[NN], q[NN], v[NN];
vector < int > s[NN];

int main(void){
	for(int N, T; RI(N) && RI(T) && N; ){
		for(int i = 0; i <= N; ++i){
			nf[i] = v[i] = 0;
			s[i].clear();
		}
		for(int i = 1; i <= N; ++i){
			RI(p[i]);
			++nf[p[i]];
		}
		int h, t;
		h = t = 0;
		for(int i = 1; i <= N; ++i)
			q[t] = i, t += !nf[i];
		while(h != t){
			int x = q[h++], k = 0;
			int lim = (s[x].size() * T + 99)/100;
			vector < int > :: iterator it;
			if(!s[x].size()) v[x] = 1;
			else {
				sort(s[x].begin(), s[x].end());
				for(it = s[x].begin(); k < lim; it++, k++) v[x] += *it;
			}
			if(!x) break;
			if(!--nf[p[x]]) q[t++] = p[x];
			s[p[x]].push_back(v[x]);
		}
		printf("%d\n", v[0]);
	}
	return 0;
}

