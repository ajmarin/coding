/////////////////////////////////
// 11541 - Decoding
/////////////////////////////////
#include<cstdio>
#include<cctype>
char line[500];
char curr;
int c,i,j,n, cnumb = 1;
int main(void){
	scanf("%d\n",&c);	
	while(c){
		c--;
		gets(line);
		printf("Case %d: ",cnumb);
		for(i = 0; line[i] != '\0'; ){
			curr = line[i++];
			n = line[i++]-'0';
			while(isdigit(line[i])) n = 10*n + line[i++] - '0';
			for(j = 0; j < n; j++) putchar(curr);
		}
		putchar('\n');
		cnumb++;
	}
}