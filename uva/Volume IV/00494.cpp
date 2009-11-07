/////////////////////////////////
// 00494 - Kindergarten Counting Game
/////////////////////////////////
#include<cstdio>
#include<cctype>
char line[100000],first,last;
int count,i;
int main(void){
	while(gets(line)){
		for(count=i=0;line[i]!='\0';){
			while(!isalpha(line[i]) && line[i]!='\0')i++;
			if(line[i]!='\0') count++;
			while(isalpha(line[i]))i++;
		}
		printf("%d\n",count);
	}
	return 0;
}
