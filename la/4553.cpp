#include <cstdio>

int n, v[10048];
bool doit(int k, int obj){
	if(k == n) return 1;
	int i, sum = 0;
	for(i = k; i < n && sum < obj; i++)
		sum += v[i];
	if(sum == obj) return doit(i, obj);
	return 0;
}
int main(void){
	int z; scanf("%d", &z);
	for(int c; scanf("%d %d", &c, &n) == 2; ){
		int sum = 0, total = 0;
		for(int i = 0; i < n; ++i) scanf("%d", &v[i]), total += v[i];
		for(int i = 0; i < n; ++i){
			sum += v[i];
			if(!(total % sum) && doit(i + 1, sum)){
				printf("%d %d\n", c, sum);
				break;
			}
		}
	}
	return 0;
}

