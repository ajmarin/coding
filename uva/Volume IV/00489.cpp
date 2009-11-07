/////////////////////////////////
// 00489 - Hangman Judge
/////////////////////////////////
#include<cstdio>
#include<cstring>
char word[100];
char guess[100];
int used[30];
char *found;
int burn,got,i,round;
bool won,lost;
int main(void){
	scanf("%d",&round);
	while(round!=-1){
		printf("Round %d\n",round);
		for(i = 0; i < 30; i++) used[i] = 0;
		scanf("%s",&word);
		scanf("%s",&guess);
		burn = got = won = lost = 0;		
		for(i = 0; i < strlen(guess); i++){
			if(used[guess[i]]) continue;
			used[guess[i]-'a'] = true;
			found=strchr(word,guess[i]);			
			if(found!=NULL) while(found!=NULL){			
				word[found-word] = ' ';
				got++;
				found=strchr(found+1,guess[i]);
			}
			else burn++;
			if(got == strlen(word)){
				won = 1;
				break;
			}
			else if(burn == 7){
				lost = 1;
				break;
			}
			
		}
		if(won) printf("You win.\n");
		else if(lost) printf("You lose.\n");
		else printf("You chickened out.\n");
		scanf("%d",&round);
	}
}
