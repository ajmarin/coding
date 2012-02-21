#include <cstdio>
#include <queue>
using namespace std;

queue<int> left, right;
enum { LEFT, RIGHT };
int main(void){
	scanf("%*d");
	char side[16];
	for(int l, m; scanf("%d %d", &l, &m) == 2; ){
		l *= 100;
		for(int length; m--; ){
			scanf("%d %s", &length, side);
			if(*side == 'l') left.push(length);
			else right.push(length);
		}
		int crossed = 0, side = 0, sum = 0;
		while(!left.empty() || !right.empty()){
			sum = 0;
			if(side == LEFT){
				while(!left.empty() && sum < l){
					if(sum + left.front() > l) break;
					sum += left.front();
					left.pop();
				}
			} else if(side == RIGHT){
				while(!right.empty() && sum < l){
					if(sum + right.front() > l) break;
					sum += right.front();
					right.pop();
				}

			}
			++crossed;
			side = 1 - side;
		}
		printf("%d\n", crossed);
	}
	return 0;
}

