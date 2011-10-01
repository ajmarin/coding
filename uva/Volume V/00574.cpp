#include <algorithm>
#include <cstdio>

int sum_count, total;
int t[32], v[32];
void bt(int sum, int idx, int terms){
	if(sum > total) return;
	if(sum == total){
		++sum_count;
		printf("%d", t[0]);
		for(int i = 1; i < terms; ++i) printf("+%d", t[i]);
		puts("");
		return;
	}
	if(idx < 0) return;
	int j, k, z;
	for(j = idx; j-- && v[j] == v[idx]; );
	for(k = terms; k < terms + idx - j; ++k) t[k] = v[idx];
	for(z = idx - j + 1; z--; ) bt(sum + v[idx] * z, j, terms + z);
}
int main(void){
	for(int n; scanf("%d %d", &total, &n) == 2 && n; ){
		for(int i = 0; i < n; ++i) scanf("%d", v + i);
		std::sort(v, v + n);
		printf("Sums of %d:\n", total);
		sum_count = 0;
		bt(0, n - 1, 0);
		if(!sum_count) puts("NONE");
	}
	return 0;
}

