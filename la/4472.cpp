#include <algorithm>
#include <cctype>
#include <cstdio>
#include <vector>

using namespace std;

#define IN getc ( stdin )
#define NN 100038

int nf[NN], p[NN], q[NN], v[NN];
vector < int > s[NN];

void fastint( register int *n ){
	register char c;
	*n = 0;
	while(!isdigit(c = IN));
	do { *n = 10 * *n + c - '0'; } while(isdigit(c = IN));
}
int main(void){
	int N, T;
	while(scanf("%d %d", &N, &T) && N){
		for(int i = 0; i <= N; ++i){
			nf[i] = v[i] = 0;
			s[i].clear();
		}
		for(int i = 1; i <= N; ++i){
			fastint(&p[i]);
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

