#include <cstdio>
#include <cstring>
bool used[3072];
int main(void){
	memset(used, 0, 3072);
	int a, n; scanf("%d", &n);
	while(n--){
		scanf("%d", &a);
		used[a] = 1;
	}
	for(int i = 1; ; ++i)
		if(!used[i]){ printf("%d\n", i); break; }
	return 0;
}

