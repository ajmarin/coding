#include <cstdio>
const int N = 10048, M = 1000048;
int box[N], p[M];
int find(int a){ return p[a] == a ? a : p[a] = find(p[a]); }
bool connected(int a, int b){ return find(box[a]) == find(box[b]); }
void u(int a, int b){
	a = find(box[a]); b = find(box[b]);
	if(a > b) p[a] = b;
	else p[b] = a;
}
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int a, b, nbox = n+1, queries = 0, yes = 0;
		char op[16];
		for(int i = 0; i <= n; ++i) box[i] = p[i] = i;
		while(scanf("%s", op) && op[0] != 'e'){
			switch(*op){
				case 'c':
					scanf("%d %d", &a, &b);
					u(a, b);
					break;
				case 'd':
					scanf("%d", &a);
					box[a] = nbox;
					p[nbox] = nbox++;
					break;
				case 'q':
					scanf("%d %d", &a, &b);
					++queries;
					yes += connected(a, b);
					break;
			}
		}
		printf("%d , %d\n", yes, queries - yes);
	}
	return 0;
}

