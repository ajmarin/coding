#include <cstdio>
#include <cstring>
int n;
int c[42][42], f[42][42], p[42], q[42];
bool v[42];
bool bfs(int s, int t) {
	int h = 0, i, j, tl = 0;
	memset(v, 0, n);
	q[tl++] = s;
	v[s] = 1;
	p[s] = -1;
	while(!v[t] && h != tl) {
		i = q[h++];
		for(j = 0; j < n; j++) {
			if(!v[j] && c[i][j] - f[i][j] > 0) {
				q[tl++] = j;
				v[j] = 1;
				p[j] = i;
			}
		}
	}
	return v[t];
}

int max_flow(int s, int t) {
	int i, mf = 0;
	memset(f, 0, sizeof(f));
	while(bfs(s, t)) {
		int cf = 1<<10;
		for(i = t; p[i] >= 0; i = p[i]){
			int temp = c[p[i]][i] - f[p[i]][i];
			if(temp < cf) cf = temp;
		}
		for(i = t; p[i] >= 0; i = p[i]) {
			f[p[i]][i] += cf;
			f[i][p[i]] -= cf;
		}
		mf += cf;
	}
	return mf;
}
int pts[42], m[42][42], ml[42];
const char *ans[2] = {"N","Y"};
int main(void){
	int a, b, G, M, N;
	char r;
	bool impossible;
	while(scanf("%d %d %d",&N, &M, &G) && N){
		n = N + 2;
		int MATCHES = (N - 1) * M, src = n - 1, snk = n - 2;
		impossible = 0;
		for(int i = 0; i < n; ++i){
			pts[i] = 0;
			ml[i] = MATCHES;
			for(int j = 0; j < n; ++j)
				c[i][j] = m[i][j] = 0;
		}
		for(int i = 0; i < G; ++i){
			scanf("%d %c %d", &a, &r, &b);
			if(r == '<') pts[b] += 2;
			else ++pts[a], ++pts[b];
			--ml[a], --ml[b];
			m[a][b] = m[b][a] = m[a][b] + 1;
		}
		for(int i = 1; i < N; ++i){
			int x = M - m[0][i];
			pts[0] += (x << 1);
			G += x;
			ml[i] -= x;
			m[0][i] = m[i][0] = 0;
		}
		for(int i = 1; i < N; ++i){
			int s = 0;
			for(int j = i + 1; j < N; ++j){
				int x = (M - m[i][j]) << 1;
				s += x;
				c[i][j] = x;
			}
			c[src][i] = s;
			int a = pts[0] - pts[i] - 1;
			int b = ml[i] << 1;
			if(a < 0){ impossible = 1; break; }
			if(a < b) c[i][snk] = a;
			else c[i][snk] = b;
		}
		if(!impossible){
			int flow = max_flow(src, snk);
			int left = MATCHES * N - 2 * G;
			puts(ans[flow == left]);
		} else puts("N");
	}
	return 0;
}

