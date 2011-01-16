/////////////////////////////////
// 10301 - Rings and Glue
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define fdp 1e-6
double xc[100],yc[100],r[100],cdis;
int circles,current,i,max;
bool v[100];
void DFS(int k){
	v[k] = true;
	int c;
	for(c = 0; c < circles; c++){
		if(c == k || v[c]) continue;
		cdis = sqrt((xc[k]-xc[c])*(xc[k]-xc[c])+(yc[k]-yc[c])*(yc[k]-yc[c]));
		if(cdis <= (r[k]+r[c]) && cdis >= fabs(r[k]-r[c])){
			current++;
			DFS(c);
		}
	}
}
int main(void){
	while(scanf("%d",&circles) && circles!=-1){
		for(i = 0; i < circles; v[i] = 0,i++) 	scanf("%lf %lf %lf",&xc[i],&yc[i],&r[i]);
		for(max = 0,i = 0; i < circles; i++) 
			if(!v[i]){
				current = 1;
				DFS(i);
				if(current > max) max= current;
			}
		if(max!=1) printf("The largest component contains %d rings.\n",max);
		else printf("The largest component contains 1 ring.\n");
	}
	return 0;
}
