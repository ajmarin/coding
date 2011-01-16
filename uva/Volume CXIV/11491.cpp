/////////////////////////////////
// 11491 - Erasing and Winning
/////////////////////////////////
#include<cstdio>
int digits,erase,curr,queue[10][100000],head[10],tail[10],i,toshow,last;
char line[100005];
int main(void){
	while(scanf("%d %d\n",&digits,&erase) && digits){
		gets(line);			
		for(i = 0; i < 10; i++) head[i] = tail[i] = 0;
		for(i = 0; i < digits; i++){
			curr = line[i]-'0';
			queue[curr][tail[curr]++] = i;
		}
		for(last = 0,toshow = digits-erase;toshow; ){
			for(i = 9; i > -1; i--){
				while(head[i] != tail[i] && queue[i][head[i]] < last) head[i]++;
				if(head[i]!=tail[i] && queue[i][head[i]] <= digits-toshow){
					toshow--;
					putchar(i+'0');
					last = queue[i][head[i]++];
					break;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}