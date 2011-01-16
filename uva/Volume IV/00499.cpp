/////////////////////////////////
// 00499 - What's The Frequency, Kenneth?
/////////////////////////////////
#include<cstdio>
char s[1000];
int fmax,freq[127],i;
int main(void){
	while(gets(s)){
		for(fmax = 0,i = 0; i < 127; freq[i] = 0,i++);
		for(i = 0; s[i] != '\0'; i++){
			if(s[i] < 65 || s[i] > 122 || (s[i] > 90 && s[i] < 97)) continue;
			freq[s[i]]++;
			if(freq[s[i]] > fmax) fmax++;
		}
		for(i = 0; i < 127; i++)
			if(freq[i] == fmax) putchar(i);
		printf(" %d\n",fmax);
	}
	return 0;
}
