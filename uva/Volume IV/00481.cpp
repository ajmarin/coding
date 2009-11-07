/////////////////////////////////
// 00481 - What Goes Up
/////////////////////////////////
#include<cstdio>
#define MAX 200005
int nums[MAX],p[MAX],b[MAX],i,idx,k,max,tail,tot,u,v;
void lis(){
	tail = -1;
	if (tot < 1) return; 
	b[++tail] = 0; 
	for (i = 1; i < tot; i++) {
		if (nums[b[tail]] < nums[i]) {
			p[i] = b[tail];
			b[++tail] = i;
			continue;
		} 
		for (u = 0, v = tail; u < v;) {
			int c = (u + v) / 2;
			if (nums[b[c]] < nums[i]) u=c+1; else v=c;
		}
 
		if (nums[i] < nums[b[u]]) {
			if (u) p[i] = b[u-1];
			b[u] = i;
		}	
	} 
	for (u = tail+1, v = b[tail]; u--; v = p[v]) b[u] = v;
}

int main(void){
	i = 0;
	while(scanf("%d",&nums[i++])!=EOF) p[i-1] = -1;
	tot = i;
	lis();
	printf("%d\n-\n",tail+1);
	for(i = 0; i <= tail; i++) printf("%d\n",nums[b[i]]);
	return 0;
}
