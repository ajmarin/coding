#include <cstdio>
#include <cstdlib>
const int N = 6543210;
int p[N];
int find(int a){ return p[a] == -1 ? a : p[a] = find(p[a]); }
bool connect(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return false;
	if(rand() / RAND_MAX > 0.5) p[a] = b;
	else p[b] = a;
	return true;
}
bool connected(int a, int b){
	return find(a) == find(b);
}

char cmd[16];
int v[16];
int main(void){
	for(int n; scanf("%s", cmd) == 1; ){
		if(cmd[0] == 'd' || cmd[0] == 'D'){
			scanf("%d", &n);
			for(int i = 0; i <= n; ++i) p[i] = -1;
		} else {
			int cnt = 0, ds = 1, ss = 0, t = 1;
			while(scanf("%d", v + cnt) == 1) cnt++;
			if(cnt > 2) t = v[2];
			if(cnt > 3) ds = v[3];
			if(cnt > 4) ss = v[4];
			if(cmd[0] == 'c' || cmd[0] == 'C'){
				for(int i = 0, src = v[0], dst = v[1]; i < t; ++i){
					connect(src, dst);
					src += ss;
					dst += ds;
				}
			} else {
				int yc = 0;
				for(int i = 0, src = v[0], dst = v[1]; i < t; ++i){
					yc += connected(src, dst);
					src += ss;
					dst += ds;
				}
				printf("%d - %d\n", yc, t - yc);
			}
		}
	}
	return 0;
}

