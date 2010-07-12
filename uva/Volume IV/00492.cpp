/////////////////////////////////
// 00492 - Pig Latin
/////////////////////////////////
#include<cstdio>
#include<cctype>
#include<cstring>
char c,end;
int len, i;
char line[1000000];
bool isvowel(char k){
	if(k > 96 && k < 123) k -= 32;
	if(k == 'A' || k == 'E' || k == 'I' || k == 'O' || k == 'U') return 1;
	return 0;
}
int main(void){
	while(gets(line)){
		len = strlen(line);
		i = 0;
		while(i < len){
			while(!isalpha(*(line+i)) && i < len) putchar(line[i++]);
			if(i == len) break;
			if(isvowel(*(line+i))) { putchar(*(line+i)); end = 0;}
			else end = *(line+i);
			for(i = i+1; isalpha(*(line+i)); i++) putchar(*(line+i));
			if(end) putchar(end);
			printf("ay");
		}
		putchar('\n');
	}
		
	return 0;
}
