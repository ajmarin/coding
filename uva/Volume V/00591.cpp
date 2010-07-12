/////////////////////////////////
// 00591 - Box of Bricks
/////////////////////////////////
#include <cstdio>
int main(){
	short set = 0, blocks,total = 0,media,move = 0;
	while(scanf("%hd",&blocks) && blocks){
		set++;
		move = 0;
		total = 0;
		short block [blocks];		
		for(int i=0; i<blocks;i++){
			scanf("%hd",&block[i]);
			total +=block[i];
		}
		media = total/blocks;
		for(int i =0; i < blocks;i++){
		 if(block[i]>media) move+= block[i]-media;
		}
		printf("Set #%hd\nThe minimum number of moves is %d.\n\n",set,move);
	}
}