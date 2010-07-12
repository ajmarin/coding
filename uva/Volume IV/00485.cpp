/////////////////////////////////
// 00485 - Pascal's Triangle of Death
/////////////////////////////////
#include<cstdio>
#include<cstring>
char curr[300][65];
char aux[65],temp[65];
char ans[105][65];
unsigned char i,j,k,len;
void add(unsigned char idx){
	unsigned char i,c=0;
	unsigned char l1 = strlen(aux);
	unsigned char l2 = strlen(curr[idx+1]);
	strcpy(temp,curr[idx+1]);
	for(i = l1; i < l2; i++) aux[i] = '0';
	for(i = 0; i < l2; i++){		
		c = (aux[i]-'0')+(curr[idx+1][i]-'0')+c;
		curr[idx+1][i] = (c%10)+'0';
		c/=10;
	}
	if(c) curr[idx+1][i++] = '1';
	curr[idx+1][i] = 0;
	aux[l1] = 0;
	strcpy(aux,temp);
}
void pascalit(){
	printf("1");
	strcpy(aux,curr[0]);
	for(j = 0; j < i/2; j++){
		add(j);
		len = strlen(curr[j+1]);
		for(k = len;k;k--) ans[j][len-k] = curr[j+1][k-1];
		ans[j][len] = 0;
		printf(" %s",ans[j]);
	}
	if(i&1) k = j;
	else k = j-1;
	for(j = j+1; j < i; j++,k--){		
		strcpy(curr[j],curr[k]);
		printf(" %s",ans[k-1]);
	}
	printf(" 1\n");
}
int main(void){
	printf("1\n");
	printf("1 1\n");
	printf("1 2 1\n");	
	strcpy(curr[0],"1");
	strcpy(curr[1],"2");
	for(i = 3; i < 205; i++){
		strcpy(curr[i],"1");
		pascalit();
	}
	return 0;
}
