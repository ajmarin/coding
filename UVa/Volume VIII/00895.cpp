/////////////////////////////////
// 00895 - Word Problem
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<cctype>
char c,has[26],j,need[26],words[1000][15],test[40];
unsigned short i,count,total;
bool cando;
int main(void){
	i = 0;
	while(gets(words[i++]) && words[i-1][0] != '#');	
	total = i-1;
	while(gets(test) && test[0] != '#'){
		memset(has,0,sizeof(has));
		for(i = 0; test[i]; i++)
			if(isalpha(test[i])) has[test[i]-'a']++;
		for(count = i = 0; i < total; i++){
			memset(need,0,sizeof(need));
			for(cando = 1,j = 0; words[i][j] && cando; j++){
				c = words[i][j]-'a';
				if(++need[c] > has[c]) cando = 0;
			}
			if(cando) count++;
		}
		printf("%u\n",count);
	}
}

