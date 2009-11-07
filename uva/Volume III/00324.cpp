/////////////////////////////////
// 00324 - Factorial Frequencies
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
unsigned int c,i,it,len,n;
unsigned short oc[10];
char res[785];
void multi(){
	for(c = i = 0; res[i]; i++){
		c = (res[i]-'0')*it+c;
		res[i] = c%10+'0';
		c/=10;
	}
	while(c){
		res[i++] = '0'+c%10;
		c/=10;
	}
	res[i] = 0;
}
int main(void){
	while(scanf("%u",&n) && n){
		n = n+1;
		strcpy(res,"1");
		for(it = 2; it != n; it++)	multi();		
		memset(oc,0,sizeof(oc));
		len = strlen(res);
		for(it = 0; it != len; it++) oc[res[it]-'0']++;
		printf("%u! --\n   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",n-1,oc[0],oc[1],oc[2],oc[3],oc[4],oc[5],oc[6],oc[7],oc[8],oc[9]);
	}
	return 0;
}
