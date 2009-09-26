#include <cstdio>
int v[100], n;
int main(void){
	int goal, i, j, n, poss, sum, x, y;
	for(int t = 1; scanf("%d%d%d",&x,&y,&n) && n; t++){
		for(sum = i = poss = 0; i < n; i++)
			scanf("%d",&v[i]), sum += v[i];
		sum = sum+x+y;
		if(!(sum&1)){
			goal = sum >> 1;
			if(x > y) goal -= x;
			else goal -= y;
			if(goal < 0) goto OUT;
			bool p[goal+1];
			for(i = 0; i < goal+1; i++)
				p[i] = 0;
			p[0] = 1;
			for(i = 0; i < n && !p[goal]; i++)
				for(j = goal-v[i]; j > -1; j--)
					if(p[j]) p[j+v[i]] = 1;
			poss = p[goal];
			
		}
		OUT:
		printf("Teste %d\n%c\n\n",t,(poss? 'S':'N'));
	}
	return 0;
}
