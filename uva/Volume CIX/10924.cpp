/////////////////////////////////
// 10924 - Prime Words
/////////////////////////////////
#include<cstdio>
#include<cstring>
bool sieve[1600];
unsigned short i,j,value;
unsigned char convert[130];
char word[25];
int main(void){
	memset(sieve,1,sizeof(sieve));
	for(i=4;i<1600;i+=2) sieve[i] = 0;
	for(i = 3; i < 40; i+=2)
		if(sieve[i]) for(j = i*i; j < 1600; j+=i) sieve[j] = 0;
	for(i = 'a'; i < 'z'+1; i++) convert[i] = i-'a'+1, convert[i-32] = convert[i]+26;
	while(scanf("%s",&word)!=EOF){
		for(value = i = 0; word[i]; i++) value += convert[word[i]];
		if(sieve[value]) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}
	return 0;
}
