#include <cstdio>

int p[1048576];

int root(int a){
	return p[a] = p[a] == a ? a : root(p[a]);
}

void union_find(int a, int b){
	p[root(a)] = root(b);
}

int main(void){
	char corq, line[1024];
	for(int t = 1; --t || scanf("%d", &t) == 1; ){
		int n, s = 0, u = 0;
		scanf("%d\n", &n);
		for(int i = 1; i <= n; ++i) p[i] = i;
		for(int a, b; fgets(line, 1024, stdin) && sscanf(line, " %c %d %d", &corq, &a, &b) == 3; ){
			if(corq == 'c')	union_find(a, b);
			else {
				if(root(a) == root(b)) ++s;
				else ++u;
			}
		}
		printf("%d,%d\n", s, u);
		if(t > 1) puts("");
	}
	return 0;
}
