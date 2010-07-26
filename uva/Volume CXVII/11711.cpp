#include <cstdio>
#include <cstring>
const int N = 1024;

struct state {
	int x;
	int t[2][3];
} s[N];
char t[N], x[N];
int ms[N], sc;
int get(int i){
	if(ms[i] == -1){
		s[sc].t[0][0] = s[sc].t[1][0] = -1;
		s[sc].x = i;
		ms[i] = sc++;
	}
	return ms[i];
}
int main(void){
	int a, b, cn, cp, n, m, qn, qp;
	char mov;
	for(int i = 0; i < N; ++i) ms[i] = -1;
	while(scanf("%d %d", &n, &m) && n){
		sc = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d %d %d %c", &qp, &cp, &qn, &cn, &mov);
			a = get(qp), b = get(qn);
			s[a].t[cp][0] = b;
			s[a].t[cp][1] = cn;
			s[a].t[cp][2] = ((mov == 'R') << 1) - 1;
		}
		for(int i = 0; i < m; ++i){
			scanf("%d %d", &a, &b);
			memset(t, 0, N); memset(x, 0, N);
			for(int j = 0; j < a || j < b; ++j){
				t[j] = j < a;
				x[j] = j < b;
			}
			int it, p, st = ms[0];
			for(it = p = 0; it < 10000; ++it){
				//printf("At state [%d] (%d, %d) ->", p, s[st].x, t[p]);
				int *tr = s[st].t[t[p]];				
				st = tr[0];
				if(st == -1) break;
				t[p] = tr[1];
				p += tr[2];
				//for(int j = 0; j < 10; ++j) putc(t[j] + '0', stdout); putc(10, stdout);				
				if(p < 0 || p >= 1000) break;
				//printf("(%d, %d) %c\n", s[st].x, tr[1], tr[2] == 1 ? 'R' : 'L');
			}
			//putc(10, stdout);
			if(p < 0 || p >= 1000) puts("MLE");
			else if(it == 10000) puts("TLE");
			else {
				//for(int j = 0; t[j]; ++j) putc(t[j] + '0', stdout); putc(10, stdout);
				//for(int j = 0; x[j]; ++j) putc(x[j] + '0', stdout); putc(10, stdout);
				if(strcmp(t, x)) puts("WA");
				else puts("AC");
			}
		}
		for(state * st = s; st < s + sc; ++st) ms[st->x] = -1;
	}
	return 0;
}
