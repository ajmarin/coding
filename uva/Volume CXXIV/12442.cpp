#include <cstdio>

const int N = 50048;
int dep[N], stack[N], z[N];
bool stacked[N];

int main(void){
	int t; scanf("%d", &t);
	for(int c = 0, n; c++ < t; ){
		scanf("%d", &n);
		for(int a, b, i = 1; i <= n; ++i){
			dep[i] = 0;
			stacked[i] = false;
			scanf("%d %d", &a, &b);
			z[a] = b;
		}

		for(int i = 1; i <= n; ++i){
			if(dep[i]) continue;
			int chain = 0, cycle, j = i, top = 0;
			while(!dep[j]){
				stacked[stack[top++] = j] = true;
				dep[j] = ++chain;
				j = z[j];
			}
			cycle = dep[j];
			if(stacked[j]){
				cycle = dep[stack[top - 1]] - dep[j] + 1;
				do {
					dep[stack[--top]] = cycle;
					stacked[stack[top]] = false;
				} while(stack[top] != j);
			}
			for(int pos = 1; top >= 1; ++pos){
				dep[stack[--top]] = pos + cycle;
				stacked[stack[top]] = false;
			}
		}
		int ans, max_chain = -1;
		for(int i = 1; i <= n; ++i){
			if(dep[i] > max_chain){
				max_chain = dep[i];
				ans = i;
			}
		}
		printf("Case %d: %d\n", c, ans);
	}
	return 0;
}

