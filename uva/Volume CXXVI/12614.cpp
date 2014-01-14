#include <algorithm>
#include <cstdio>
using namespace std;

int main(void){
	int n; scanf("%d", &n);	
	for(int b, c = 0, y, z; c++ < n; ){
		scanf("%d", &z);
		for(b = 0; z--; scanf("%d", &y), b = max(b, y));
		printf("Case %d: %d\n", c, b);
	}
	return 0;
}

