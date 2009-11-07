/////////////////////////////////
// 11233 - Deli Deli
/////////////////////////////////
#include<cstdio>
#include<cstring>
char list[20][25],plu[20][25],word[25],i,j;
unsigned int L,N;
void search(){
	for(j = 0; j != L; j++)
		if(strcmp(list[j],word)==0) return;
}
bool iscons(char c){
	switch(c){
		case 'a': case'e':
		case 'i': case'o':
		case 'u': return 0;
		default: return 1;
	}
}
int main(void){
	scanf("%u %u",&L,&N);
	for(i = 0; i < L; i++)
		scanf("%s %s",&list[i],&plu[i]);
	for(i = 0; i < N; i++){
		scanf("%s",&word);
		search();
		if(j!=L) puts(plu[j]);
		else {
			j = strlen(word);
			if(j > 1 && word[j-1] == 'y' && iscons(word[j-2])){
				word[j-1] = 'i', word[j] = 'e';
				word[j+1] = 's', word[j+2] = 0;
			}
			else if(word[j-1] == 'o' ||
					word[j-1] == 's' ||
					word[j-1] == 'x' ||
					(j > 1 && word[j-1] == 'h' &&
					(word[j-2] == 'c' ||
					word[j-2] == 's')))
				word[j] = 'e', word[j+1] = 's', word[j+2] = 0;
			else word[j] = 's', word[j+1] = 0;
			puts(word);
		}
	}
	return 0;
}
	
