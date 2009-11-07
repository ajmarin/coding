/////////////////////////////////
// 00437 - The Tower of Babylon
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef unsigned int UI;
struct block{
	UI x,y,h;
	block() {}
	block(UI a, UI b, UI c): x(a),y(b),h(c) {}
}bks[90];
UI cnum, d[3], h[90], maxh, test;
unsigned char p[90],bnum, i, j, last;
bool comp(block a, block b){
	return(a.x < b.x && a.y < b.y);
}
bool ord(block a, block b){
	return(a.x < b.x);
}
void show(block a){
	printf("%u %u %u\n",a.x,a.y,a.h);
}
int main(void){
	while(scanf("%u",&bnum) && bnum){
		cnum++;
		memset(h,0,sizeof(h));
		for(last = i = 0; i < bnum; i++){
			scanf("%u %u %u",&d[0],&d[1],&d[2]);
			std::sort(d,d+3);
			bks[last++] = block(d[0],d[1],d[2]);
			if(d[2] != d[1]) 
				bks[last++] = block(d[0],d[2],d[1]);
			if(d[0] != d[1]) 
				bks[last++] = block(d[1],d[2],d[0]);
		}
		std::sort(bks,bks+last,ord);
		//for(i = 0; i < last; i++) show(bks[i]);
		for(i = 0; i < last; i++){
			maxh = 0;
			for(j = 0; j < i; j++)
				if(comp(bks[j],bks[i]) && h[j] > maxh)
					maxh = h[j]+h[i];
			h[i] = maxh+bks[i].h;
		}
		for(maxh = i = 0; i < last; i++)
			if(h[i] > maxh) maxh = h[i];
		printf("Case %u: maximum height = %u\n",cnum,maxh);
	}
	return 0;
}
