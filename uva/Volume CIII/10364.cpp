#include <cstdio>

int first[4], n, v[32], wanted;
bool bt(int mask, int sum, int idx, int group){
	if(group == 4 && mask == (1 << n) - 1) return true;
	if(sum == wanted) return bt(mask, 0, first[group] + 1, group + 1);
	if(sum > wanted) return false;
	for(int i = idx; i < n; ++i) if(!(mask & (1 << i))){
		if(sum == 0) first[group] = i;
		if(bt(mask | (1 << i), sum + v[i], i+1, group))
			return true;
	}
	return false;
}
int main(void){
	int t; scanf("%d", &t);
	while(t-- && scanf("%d", &n) == 1){
		int sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", v + i);
			sum = sum + v[i];
		}
		if(sum & 3) puts("no");
		else {
			wanted = sum / 4;
			puts(bt(0, 0, 0, 0) ? "yes" : "no");
		}
	}
	return 0;
}

