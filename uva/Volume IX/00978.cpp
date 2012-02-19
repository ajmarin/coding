#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> green;
priority_queue<int> blue;
int bf[100048][2];

int main(void){
	for(int t = 1; --t || scanf("%d", &t) == 1; ){
		int bc, fields, gc;
		scanf("%d %d %d", &fields, &gc, &bc);
		for(int i = 0, z; i < gc; ++i) scanf("%d", &z), green.push(z);
		for(int i = 0, z; i < bc; ++i) scanf("%d", &z), blue.push(z);
		while(!green.empty() && !blue.empty()){
			int battles = 0, diff;
			while(!green.empty() && !blue.empty() && battles < fields){
				bf[battles][0] = green.top(); green.pop();
				bf[battles][1] = blue.top(); blue.pop();
				++battles;
			}
			while(battles--){
				diff = bf[battles][0] - bf[battles][1];
				if(diff > 0) green.push(diff);
				else if(diff < 0) blue.push(-diff);
			}
		}
		if(!green.empty()){
			puts("green wins");
			while(!green.empty()) printf("%d\n", green.top()), green.pop();
		} else if(!blue.empty()){
			puts("blue wins");
			while(!blue.empty()) printf("%d\n", blue.top()), blue.pop();
		} else puts("green and blue died");
		if(t > 1) puts("");
	}
	return 0;
}

