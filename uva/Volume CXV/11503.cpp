#include <cstdio>
#include <map>
#include <string>
using namespace std;

const int N = 200096;
int cnt, p[N], s[N];
map < string, int > m;

int root(int a){ return p[a] = p[a] == a ? a : root(p[a]); }

int union_find(int a, int b){
	p[a = root(a)] = b = root(b);
//	printf("groups %d [%d] and %d [%d]\n", a, s[a], b, s[b]);
	if(a != b) s[a] += s[b];
	return s[b] = s[a];
}

int get_mapping(string s){
	int &z = m[s];
	return z = !z ? ++cnt : z; 
}

int main(void){
	scanf("%*d");
	char a[32], b[32];
	for(int n; scanf("%d", &n) == 1; ){
		m.clear();
		cnt = 0;
		for(int i = 1; i <= (n << 1); ++i){
			p[i] = i;
			s[i] = 1;
		}
		for(int i = 0; i < n; ++i){
			scanf("%s %s", a, b);
			printf("%d\n", union_find(get_mapping(a), get_mapping(b)));
		}
	}
	return 0;
}

