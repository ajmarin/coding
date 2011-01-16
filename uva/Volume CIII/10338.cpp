/////////////////////////////////
// 10338 - Mischievous Children
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned short int cnum,tnum;
unsigned int div;
unsigned long long ans,fact[21];
char i,idx,len,max_oc,oc[30],word[25];
int main(void){
	fact[0] = fact[1] = 1;
	for(i = 2; i < 21; i++) fact[i] = i*fact[i-1];
	scanf("%u\n",&cnum); tnum = 0;
	while(cnum--){
		tnum++;
		gets(word);
		memset(oc,0,sizeof(oc));
		for(div = 1,max_oc = i = 0; word[i]; i++)
			if(++oc[word[i]-'A'] > max_oc) 
				max_oc = oc[word[i]-'A'], idx = word[i]-'A';
		len = i;
		for(i = 0; i != 30; i++)
			if(i != idx) div *= fact[oc[i]];		
		ans = fact[len]/fact[max_oc]/div;
		printf("Data set %u: %u\n",tnum,ans);
	}
	return 0;
}
