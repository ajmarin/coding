/////////////////////////////////
// 11222 - Only I did it!
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
unsigned int champion,cnum,i,k,max,tnum;
unsigned int probs[3],sol[3][1000],u_sol[3][1000],u_tail[3];
unsigned int occ[10001];
int main(void){
	scanf("%u\n",&cnum); tnum =0;
	while(cnum--){
		tnum++;
		memset(occ,0,sizeof(occ));
		for(k = 0; k != 3; k++){
			scanf("%u",&probs[k]);
			for(i = 0; i < probs[k]; i++)
				scanf("%u",&sol[k][i]), occ[sol[k][i]]++;
			std::sort(sol[k],sol[k]+probs[k]);
		}
		u_tail[0] = u_tail[1] = u_tail[2] = max = champion = 0;
		for(k = 0; k != 3; k++){
			for(i = 0; i < probs[k]; i++)
				if(occ[sol[k][i]]==1) 
					u_sol[k][u_tail[k]++] = sol[k][i];
			if(u_tail[k] > max)
				max = u_tail[k], champion = k;
		}
		printf("Case #%u:\n",tnum);
		for(k = champion; k!=3; k++)
			if(u_tail[k] == max){
				printf("%u %u",k+1,max);
				for(i = 0; i != max; i++)
					printf(" %u",u_sol[k][i]);
				putchar('\n');
			}
	}
	return 0;
}
		
