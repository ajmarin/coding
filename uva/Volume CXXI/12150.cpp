#include <cstdio>
#include <cstring>
int p[1024];
int main(void){
	int dpos, i, n, pos, who;
	while(scanf("%d",&n) && n){
		bool valid = true;
		memset(p,0,n<<2);
		for(i = 0; i < n; i++){
			scanf("%d %d", &who, &dpos);
			pos = i + dpos;
			if(valid &= !(pos < 0 || pos >= n || p[pos])) p[pos] = who;
		}
		if(valid) for(i = 0; i < n; i++) printf("%d%c", p[i], i == n - 1 ? 10 : 32);
		else puts("-1");
	}
	return 0;
}
