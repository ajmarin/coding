/////////////////////////////////
// 00231 - Testing the CATCHER
/////////////////////////////////
#include<cstdio>
short int q[32768],h[32768],i,idx,k,max,tot,tnum;
int main(void){
	scanf("%d",&h[0]);
	while(true){
		i = 0;tnum++;
		while(scanf("%d",&h[++i]) && h[i]!=-1);
		for(tot = i, i = 0; i < tot; i++){
			max = 0;
			for(k = 0; k < i; k++)
				if(h[k] >= h[i] && q[k] > max) max = q[k];
			q[i] = max+1;
		}
		for(max = i = 0; i < tot; i++)
			if(q[i] > max) max = q[i], idx = i;
		printf("Test #%u:\n  maximum possible interceptions: %u\n",tnum,max);
		if(scanf("%d",&h[0]) && h[0]!=-1) putchar('\n');
		else return 0;
	}
}
		
