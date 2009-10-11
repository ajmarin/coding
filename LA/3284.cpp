#include <cstdio>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define FOR(a,b,c) for(short a = b; a < c; ++a)
struct match {
	short t1, t2;
	short a, b, c, d, e, f;
	match(short _t1, short _a, short _b, short _c, short _t2, short _d, short _e, short _f):
		t1(_t1),a(_a),b(_b),c(_c),t2(_t2),d(_d),e(_e),f(_f){}
	match(){}
}m[200];

struct team {
	char name[25];
	short p, bp;
	bool operator<(const team x) const{
		return (strcmp(name,x.name) < 0);
	}
}t[20];

struct score {
	short n, sc;
	bool operator<(const score x) const{ return sc > x.sc; }
}s[20];

char n1[25], n2[25];

map < string , short > nm;

int main(void){
	short A1, A2, B1, B2, C1, C2, M, N, TM;
	short a, b, cnum = 0, tm;
	while(scanf("%hd%hd",&N,&M) && (N||M)){
		nm.clear();	tm = 0;
		TM = (N*M)>>1;
		for(short i = 0; i < N; ++i) t[i].bp = N;
		for(short i = 0; i < TM; ++i){
			scanf("%s %hd %hd %hd %s %hd %hd %hd",&n1,&A1,&B1,&C1,&n2,&A2,&B2,&C2);
			if(nm.find(string(n1)) != nm.end()) a = nm[string(n1)];
			else a = nm[string(n1)] = tm, strcpy(t[tm].name, n1), tm++;
			if(nm.find(string(n2)) != nm.end()) b = nm[string(n2)];
			else b = nm[string(n2)] = tm, strcpy(t[tm].name, n2), tm++;
			m[i] = match(a,A1,B1,C1,b,A2,B2,C2);
		}
		FOR(win, 2, 6) FOR(drw, 1, win) FOR(A, 1, 6)
		FOR(B, 1, 6) FOR(C, 1, 6) FOR(J, 1, 6) FOR(K, 1, 11){
			for(short i = 0; i < N; ++i) t[i].p = 0;
			for(short i = 0; i < TM; ++i){
				if(m[i].a >= J) ++t[m[i].t1].p;
				if(m[i].d >= J) ++t[m[i].t2].p;
				short s1 = m[i].a * A + m[i].b * B + m[i].c * C;
				short s2 = m[i].d * A + m[i].e * B + m[i].f * C;
				short diff = abs(s1 - s2);
				if(diff){
					if(s1 > s2){
						t[m[i].t1].p += win;
						if(diff <= K) ++t[m[i].t2].p;
					} else {
						t[m[i].t2].p += win;
						if(diff <= K) ++t[m[i].t1].p;
					}
				} else {
					t[m[i].t1].p += drw;
					t[m[i].t2].p += drw;
				}
			}
			for(short i = 0; i < N; ++i){
				s[i].n = i; s[i].sc = t[i].p;
			}
			sort(s, s + N);
			for(short i = 0, pos = 0, ties = 0; i < N; ++i, ++ties){
				if(i && s[i].sc != s[i-1].sc) pos += ties, ties = 0;
				if(t[s[i].n].bp > pos) t[s[i].n].bp = pos;
			}
		}
		sort(t, t + N);
		printf("%hd\n",++cnum);
		for(short i = 0; i < N; ++i)
			printf("%s %hd\n",t[i].name,t[i].bp+1);
	}
	return 0;
}

