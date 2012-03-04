#include <cstdio>
int got[2048][2];
int v[2048];
int main(void){
	for(int i = 0; i < 2048; ++i) got[i][0] = got[i][1] = -1;
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i]);
		for(int j = 0; j < i; ++j){
			int sum = v[i] + v[j];
			got[sum][0] = i + 1;
			got[sum][1] = j + 1;
		}
	}
	int i;
	for(i = 0; i < n; ++i)
		if(got[v[i]][0] != got[v[i]][1]){
			printf("%d %d %d\n", 1+i, got[v[i]][0], got[v[i]][1]); 
			break;
		}
	if(i == n) puts("-1");
	return 0;
}
