#include <cstdio>
#include <algorithm>
using namespace std;

#define NN 100048
int m[NN];
int oc[NN];
int prev[NN][2];
bool p[NN], infeasible;

int main(void){
	int c, n, s, t, w;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &s, &n);
		infeasible = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &m[i]);
			m[i]--;
		}
		for(int i = 0; i < s; ++i){
			p[i] = 1;
			prev[i][0] = prev[i][1] = oc[i] = 0;
		}
		w = s;
		for(int i = 0; i < n; ++i){
			int x = m[i];
			if(oc[x]){
				int bw = i - prev[x][1];
				if(bw < s){ 
					int a, b;
					a = prev[x][1] - (s - bw - 1);
					b = prev[x][1];
					for(int i = a; i <= b; ++i){
						int k = (i + s) % s;
						w -= p[k];
						p[k] = 0;
					}
				}
			}
			if(++oc[x] > 2 && (i - prev[x][0] < s)){
				infeasible = 1;
				break;
			}
			prev[x][0] = prev[x][1];
			prev[x][1] = i;
		}
		if(infeasible) puts("0");
		else {
			printf("%d\n", w);
		}
	}
	return 0;
}

