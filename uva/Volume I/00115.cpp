#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

#define NN 300
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a)   ((a)< 0?-(a):(a))

struct node {
	char n[32];
	int d, p, pb;
} n[NN]; 

map < string , int > m;
int nc;
bool v[NN];
char n1[NN], n2[NN];

int rdfs(int k){
	if(k == -1) return 0;
	if(v[k]) return n[k].d;
	v[k] = 1;
	n[k].d = 1 + rdfs(n[k].p);
	return n[k].d;
}
int insert(const char *p){
	n[nc].p = -1;
	n[nc].pb = 0;
	strcpy(n[nc].n, p);
	return (m[string(p)] = nc++);
}
int main(void){
	m.clear(); nc = 0;
	int a, b;
	while(scanf("%s %s", &n1, &n2) && strcmp(n1,"no.child")){
		if(m.find(string(n1)) != m.end()) a = m[string(n1)];
		else a = insert(n1);
		if(m.find(string(n2)) != m.end()) b = m[string(n2)];
		else b = insert(n2);
		n[a].p = b;
		n[b].pb++;
	}
	for(int i = 0; i < nc; ++i) if(!n[i].pb) rdfs(i);
	while(scanf("%s %s", &n1, &n2) == 2){
		a = b = -1;
		if(m.find(string(n1)) != m.end()) a = m[string(n1)];
		if(m.find(string(n2)) != m.end()) b = m[string(n2)];
		if(a == -1 || b == -1) puts("no relation");
		else {
			int upa, upb, da = n[a].d, db = n[b].d;
			upa = upb = 0;
			while(n[a].d > db) a = n[a].p, ++upa;
			while(n[b].d > da) b = n[b].p, ++upb;
			if(a == b){
				int k = MAX(upa, upb);
				while(k > 2) fputs("great ", stdout), k--;
				if(k > 1) fputs("grand ", stdout);
				if(upa > upb) puts("child");
				else puts("parent");
			} else {
				while(a != b && n[a].p != -1 && n[b].p != -1){
					a = n[a].p, ++upa;
					b = n[b].p, ++upb;
				}
				if(a != b) puts("no relation");
				else {
					int j = ABS(upa - upb), k = MIN(upa, upb) - 1;
					if(!k && upa == upb) puts("sibling");
					else if(j) printf("%d cousin removed %d\n",k,j);
					else printf("%d cousin\n",k);
				}
			}
		}

	}
	return 0;
}

