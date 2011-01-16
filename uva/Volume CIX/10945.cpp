/////////////////////////////////
// 10945 - Mother bear
/////////////////////////////////
#include<cctype>
#include<cstdio>
#include<cstring>
int i,j;
char sent[1000000];
bool palindrome;
const char *ok = "You won't be eaten!", *uh = "Uh oh..";
bool cmp(char a, char b){
	if(a > 'Z') a -= 32;
	if(b > 'Z') b -= 32;
	return (a == b);
}
int main(void){
	while(gets(sent) && strcmp(sent,"DONE")){
		for(palindrome = 1,i = 0, j = strlen(sent)-1; palindrome; i++,j--){
			while(!isalpha(sent[i]) && i < j) i++;
			while(!isalpha(sent[j]) && j > i) j--;
			if(i < j) palindrome = cmp(sent[i],sent[j]);			
			else break;
		}
		if(palindrome) puts(ok);
		else puts(uh);
	}
	return 0;
}
