#include <cstdio>
#include <queue>

using namespace std;

#define NN 256
#define HH 60*24
#define INF 1<<15
#define SRC 0
#define SINK 1
#define PES(i) ((i)+2)
#define BUS(i) (p+(i)+2)

int c[NN][NN], f[NN][NN];
int v[NN], pr[NN];
int n;

bool bfs(int s, int t) {
        queue<int> q;
        int i, j;
        for(i = 0; i < n; i++)
                v[i] = 0;
        q.push(s);
        v[s] = 1;
        pr[s] = -1;
        while(!q.empty() && v[t] == 0) {
                i = q.front();
                q.pop();
                for(j = 0; j < n; j++) {
                        if(v[j] == 0 && c[i][j] - f[i][j] > 0) {
                                q.push(j);
                                v[j] = 1;
                                pr[j] = i;
                        }
                }
        }
        return v[t] == 1;
}

int maxflow(int s, int t) {
        int mf = 0;
        int i, j;

        for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                        f[i][j] = 0;

        while(bfs(s, t)) {
                int cf = INF;

                for(i = t; pr[i] >= 0; i = pr[i])
                        cf = min(cf, c[pr[i]][i] - f[pr[i]][i]);

                for(i = t; pr[i] >= 0; i = pr[i]) {
                        f[pr[i]][i] += cf;
                        f[i][pr[i]] -= cf;
                }

                mf += cf;
        }

        return mf;
}

int t;
int b, p;
int busid[HH][NN], busnum[HH];

int main(void) {
	int i, j, k, h, m, ti, flow;

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &p, &b);

		/* init */
		n = p+b+2;
		for(i = 0; i < HH; i++) busnum[i] = 0;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				c[i][j] = 0;

		/* input */
		for(i = 0; i < b; i++) {
			scanf("%d:%d", &h, &m), ti = h*60+m;
			busid[ti][busnum[ti]++] = i;
		}
		for(i = 0; i < p; i++) {
			scanf("%d", &k);
			c[SRC][PES(i)] = 1;
			while(k--) {
				scanf("%d:%d", &h, &m), ti = h*60+m;
				for(j = 0; j < busnum[ti]; j++)
					c[PES(i)][BUS(busid[ti][j])] = INF;
			}
		}

		/* processa */
		int k = p/b - 1;
		do {
			k++;
			for(i = 0; i < b; i++)
				c[BUS(i)][SINK] = k;
			flow = maxflow(SRC, SINK);
		} while(flow < p);

		/* output */
		printf("%d\n", k);
	}

	return 0;
}
