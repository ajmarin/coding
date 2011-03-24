#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct b {
	int x,y,h;
	b() {}
	b(int a, int b, int c): x(a),y(b),h(c) {}
}bks[90];
int d[3], h[90], test;
bool comp(b x, b y){ return(x.x < y.x && x.y < y.y); }
bool ord(b x, b y){ return(x.x < y.x) || (x.x == y.x && x.y < y.y); }
int main(void){
	for(int bnum; scanf("%d",&bnum) && bnum; ){
		int i, j, last, maxh;
		memset(h,0,sizeof(h));
		for(last = i = 0; i < bnum; i++){
			scanf("%d %d %d", d, d+1, d+2);
			sort(d, d+3);
			bks[last++] = b(d[0], d[1], d[2]);
			if(d[2] != d[1]) bks[last++] = b(d[0], d[2], d[1]);
			if(d[0] != d[1]) bks[last++] = b(d[1], d[2], d[0]);
		}
		sort(bks, bks+last, ord);
		for(i = 0; i < last; i++){
			maxh = 0;
			for(j = 0; j < i; j++)
				if(comp(bks[j],bks[i])) maxh = max(maxh, h[j]);
			h[i] = maxh+bks[i].h;
		}
		for(maxh = i = 0; i < last; i++) maxh = max(maxh, h[i]);
		printf("%d\n", maxh);
	}
	return 0;
}

