/////////////////////////////////
// 00103 - Stacking Boxes
/////////////////////////////////
#include<cstdio>
#include<algorithm>
struct box{
	unsigned int d[10],n;
}bxs[30];
char bnum, dim, end, i, j, max, p[30],q[30];
bool ord(box a, box b){
	return(a.d[0] < b.d[0]);
}
bool nest(box a, box b){
	char k;
	for(k = 0; k < dim; k++)
		if(a.d[k] >= b.d[k]) return 0;
	return 1;
}
void trace(char j,char b){
	if(b) trace(p[j],b-1), printf(" %u",bxs[j].n);
	else printf("%u",bxs[j].n);
}
int main(void){
	while(scanf("%u %u",&bnum,&dim)!=EOF){
		for(i = 0; i < bnum; i++){
			for(j = 0; j < dim; j++) scanf("%u",&bxs[i].d[j]);
			bxs[i].n = i+1;
			std::sort(bxs[i].d,bxs[i].d+dim);
		}
		std::sort(bxs,bxs+bnum,ord);
		for(i = 0; i < bnum; i++){
			max = 0;
			for(j = 0; j < i; j++)
				if(nest(bxs[j],bxs[i]) && q[j] > max)
					max = q[j], p[i] = j;
			q[i] = max+1;
		}
		for(max = i = 0; i < bnum; i++)
			if(q[i] > max) max = q[i], end = i;		
		printf("%u\n",max);
		trace(end,max-1);
		printf("\n");
	}
	return 0;
}

