#include<cstdio>
int a, b, current, dice, i, P, player, S, winner;
int pos[10], t[3], trapped[10];
bool trap[10001];
int main(void){
	while(scanf("%d%d",&P,&S) && P){
		for(i = 0; i < P; i++) pos[i] = trapped[i] = 0;
		current = 0;
		scanf("%d%d%d",&t[0],&t[1],&t[2]);
		trap[t[0]] = trap[t[1]] = trap[t[2]] = 1;
		scanf("%d",&dice);
		for(i = 0; i < dice; i++){
			//printf("\t\tPLAY: %d\n",current+1);
			if(trapped[current]){
				//printf("Player %d is trapped, lost turn.\n",current+1);
				trapped[current] = 0;
				i--;
				current = (current+1)%P;
				continue; 
			}
			scanf("%d%d",&a,&b);			
			int move = a+b;			
			pos[current] += move;
			//printf(" Player %d moved %d and is at %d\n",current+1, move,pos[current]);
			if(pos[current] > S) winner = current+1;
			if(trap[pos[current]]) trapped[current] = 1;
			current = (current+1)%P;
		}
		trap[t[0]] = trap[t[1]] = trap[t[2]] = 0;
		printf("%d\n",winner);
	}
	return 0;
}