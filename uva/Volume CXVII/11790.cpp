#include <cstdio>

struct building {
	int h, maxd, maxi, w;
}b[10000];
int main(void){
	int maxdec, maxinc, n, t; scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		maxinc = maxdec = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", &b[i].h);
		for(int i = 0; i < n; ++i){
			scanf("%d", &b[i].w);
			if(b[i].w > maxinc) maxinc = b[i].w;
			if(b[i].w > maxdec) maxdec = b[i].w;
			b[i].maxd = b[i].maxi = b[i].w;
			//printf("Building %d, (%d, %d)\n", i, b[i].h, b[i].w);
			for(int j = 0; j < i; ++j){
				if(b[i].h > b[j].h){
					int temp = b[j].maxi + b[i].w;
					if(temp > b[i].maxi){
						b[i].maxi = temp;
						//printf("\tINC: (p, L) = (%d(%d), %d)\n", j, b[j].maxi, temp);
						if(temp > maxinc) maxinc = temp;
					}
				} else if(b[i].h < b[j].h){
					int temp = b[j].maxd + b[i].w;
					if(temp > b[i].maxd){
						b[i].maxd = temp;
						//printf("\tDEC: (p, L) = (%d(%d), %d)\n", j, b[j].maxd, temp);
						if(temp > maxdec) maxdec = temp;
					}
				}
			}
		}
		printf("Case %d. ", cnum);
		if(maxinc >= maxdec)	printf("Increasing (%d). Decreasing (%d).\n", maxinc, maxdec);
		else printf("Decreasing (%d). Increasing (%d).\n", maxdec, maxinc);
	}
	return 0;
}
