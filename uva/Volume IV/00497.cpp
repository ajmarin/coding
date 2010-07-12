/////////////////////////////////
// 00497 - Strategic Defense Initiative
/////////////////////////////////
#include<cstdio>
#define MAX 200005
int nums[MAX],p[MAX],b[MAX],cnum,i,idx,k,max,tail,tot,u,v;
char line[100];
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
	scanf("%u",&cnum);
	gets(line);
	gets(line);
	while(cnum--){
		i = 0;
		while(gets(line) && line[0]) sscanf(line,"%d",&nums[i++]); 
		tot = i;
		lis();
		printf("Max hits: %d\n",tail+1);
		for(i = 0; i <= tail; i++) printf("%d\n",nums[b[i]]);
		if(cnum) putchar('\n');
	}
	return 0;
}
