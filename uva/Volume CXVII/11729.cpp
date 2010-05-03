#include <algorithm>
#include <cstdio>

struct task{
	int b, j;
	bool operator<(const task x)const{
		return (j/(double)b) + j < (x.j/double(x.b)) + x.j;
	}
}t[1024]; 


int main(void){
	int end, n, now;
	for(int cnum = 1; scanf("%d", &n) && n; cnum++){
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &t[i].b, &t[i].j);
		std::sort(t, t + n);
		now = end = 0;
		for(int i = n; i--; ){
			now = now + t[i].b;
			int temp = now + t[i].j;
			if(temp > end) end = temp;
		}
		printf("Case %d: %d\n", cnum, end);
	}
	return 0;
}

