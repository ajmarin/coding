#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

#define IN getc( stdin )

struct node {
	int v, l;
	char p[312];
	bool operator<(const node x) const {
		return (l < x.l || (l == x.l && strcmp(p, x.p) < 0));
	}
} n[300];

map < string , int > m;
char test[312];

int main(void){
	register char c, *p;
	int i, *k, nc;
	while(c != EOF){
		m.clear();
		for(nc = 0; ; nc++){
			while(c != '(') c = IN;
			if((c = IN) == ')') break;
			for(k = &(n[nc].v), *k = 0; c != ','; *k = *k * 10 + c - '0', c = IN);
			for(p = n[nc].p; (c = IN) != ')'; *p++ = c);
			*p = 0; n[nc].l = p - n[nc].p;
		}
		sort(n, n + nc);
		for(i = 0; i != nc; ++i){
			if(i && !strcmp(n[i].p, n[i-1].p)) break;
			if(n[i].l){
				strcpy(test, n[i].p);
				test[n[i].l - 1] = 0;
				if(m.find(string(test)) == m.end()) break;
			}
			m[string(n[i].p)] = i;
		}
		if(i != nc) puts("not complete");
		else {
			for(i = 0; i != nc; ++i){
				if(i) putc(' ', stdout);
				printf("%d",n[i].v);
			}
			putc(10, stdout);
		}
		while(c != EOF && c != '(') c = IN;
	}
	return 0;
}

