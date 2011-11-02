#include <algorithm>
#include <cstdio>

int list[10], run[1024], rs = 0, used = 0;
bool runaround(int x, int ls){
	int at, steps, v = 0;
	for(at = steps = 0; steps < ls; ++steps){
		if(v & (1 << at)) return false;
		v |= (1 << at);
		at = (at + list[at]) % ls;
	}
	return at == 0;
}
void generate(int x, int digits){
	if(digits && runaround(x, digits)) run[rs++] = x;
	if(digits == 7) return;
	for(int i = 1; i < 10; ++i) if(!(used & (1 << i))){
		used |= (1 << i);
		list[digits] = i;
		generate(x * 10 + i, digits + 1);
		used &= ~(1 << i);
	}
}
int main(void){
	generate(0, 0);
	std::sort(run, run + rs);
	for(int c = 0, m, n, u, v; scanf("%d", &n) == 1 && n; ){
		for(u = 0, v = rs; u < v; ){
			m = (u + v) >> 1;
			if(run[m] < n) u = m + 1;
			else v = m;
		}
		printf("Case %d: %d\n", ++c, run[u]);
	}
	return 0;
}

