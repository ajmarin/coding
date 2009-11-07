/////////////////////////////////
// 10161 - Ant on a Chessboard
/////////////////////////////////
#include<cstdio>
#include<cmath>
unsigned int root,time,x,y;
int main(void){
	while(scanf("%u",&time) && time){
		root = (int)(ceil(sqrt(time)));
		if(root&1){
			if(root*root - time < root) x = root*root-time+1, y = root;
			else x = root, y = time - (root-1)*(root-1);
		} else {
			if(root*root - time < root) x = root, y = root*root-time+1;
			else x = time - (root-1)*(root-1), y = root;
		}
		printf("%u %u\n",x,y);
	}
	return 0;
}

