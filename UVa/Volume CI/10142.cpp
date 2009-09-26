/////////////////////////////////
// 10142 - Australian Voting
/////////////////////////////////
#include<cstdio>
#include<cstring>
int cases,candidates,ballot[1000][20],votes[21],front[1000], winners,i,nballots=0,max_votes=0,shown=0,min_votes = 0;
char names[21][85], line[3000],*number;
bool elim[25], show = 0, show2 = 1;
void count_winners(){
	winners = 0;
	for(i = 1; i <= candidates;i++)
		if(!elim[i] && votes[i] == max_votes) winners++;
}
int findmin(){
	int min = 10000;
	for(i = 1; i <= candidates;i++)
		if(!elim[i] && votes[i] < min) min = votes[i];
	return min;
}
void eliminate(){
	for(i = 1; i <= candidates; i++)
			if(votes[i] == min_votes)
				elim[i] = true;
}
int main(void){
	scanf("%d",&cases);
	while(cases){
		cases--;
		nballots = max_votes = shown =  min_votes = 0;
		scanf("%d\n",&candidates);
		for(i = 1; i <= candidates; gets(names[i]),i++);
		while(gets(line)){
			if(line[0] == 0) break;
			number = strtok(line," ");
			for(i = 0; i < candidates; i++){
				sscanf(number,"%d ",&ballot[nballots][i]);				
				number = strtok(NULL," ");
			}
			nballots++;
		}
		for(i = 0; i <= candidates; votes[i] = elim[i] = 0,i++);
		for(i = 0; i < nballots; front[i] = 0,i++);		
		for(i = 0; i < nballots; i++) max_votes = (++votes[ballot[i][0]] > max_votes? votes[ballot[i][0]]: max_votes);	
		min_votes = findmin();
		count_winners();
		while(max_votes <= nballots/2 && winners*max_votes != nballots){	
			eliminate();
			for(i = 0; i < nballots; i++)
				if(elim[ballot[i][front[i]]]){
					while(elim[ballot[i][++front[i]]]);
					max_votes = (++votes[ballot[i][front[i]]] > max_votes? votes[ballot[i][front[i]]]: max_votes);
				}
			min_votes = findmin();
			count_winners();
		}	
		for(shown = 0,i = 1; shown != winners; i++)	
			if(!elim[i] && votes[i] == max_votes){
				printf("%s\n",names[i]);
				shown++;
			}
		if(cases) putchar('\n');
	}		
	return 0;
}
