/////////////////////////////////
// 00490 - Rotating Sentences
/////////////////////////////////
#include<cstdio>
#include<cstring>
char sent[105][105], i,j,k,maxlen;
int main(void){
	for(maxlen = i = 0;gets(sent[i]);i++){
		k = strlen(sent[i]);
		if(k > maxlen) maxlen = k;
	}
	for(j = 0; j != maxlen; putchar('\n'),j++)
		for(k = i-1; k >= 0; k--)
			if(sent[k][j]) putchar(sent[k][j]);
			else putchar(' ');
	return 0;
}
	