/////////////////////////////////
// 10106 - Product
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
void add(char v1[], char v2[]){
	int i,d,c=0;
	int l1=strlen(v1);
	int l2=strlen(v2);
	for(i=l1;i<l2;i++) v1[i]='0';
	for(i=l2;i<l1;i++) v2[i]='0';
	for(i=0;i<l1||i<l2;i++)	{
		d=(v1[i]-'0')+(v2[i]-'0')+c;
		c=d/10;d%=10;
		v1[i]='0'+d;
	}
	while(c){
		v1[i]='0'+(c%10);
		c/=10;i++;
	}
	v1[i]='\0';
	v2[l2]='\0';
}
char tmp[260];
char tmp1[260];
char tmpd[10][260]; 
char bs[260];
void multi(char v1[], char v2[]){
	bs[0]='\0';
	int l2=strlen(v2);
	int i;
	strcpy(tmpd[0],"0");
	for(i=1;i<10;i++){
		strcpy(tmpd[i],tmpd[i-1]);
		add(tmpd[i],v1);
	}
	strcpy(v1,"0");
	for(i=0;i<l2;i++)	{
		strcpy(tmp,bs); bs[i]='0';bs[i+1]='\0';
		strcat(tmp,tmpd[v2[i]-'0']);
		add(v1,tmp);
	}
}
char X[260],Y[260];
int main(void){
	while(scanf("%s%s",X,Y)==2){
		std::reverse(X,X+strlen(X));
		std::reverse(Y,Y+strlen(Y));
		multi(X,Y);
		std::reverse(X,X+strlen(X));
		puts(X);
	}
	return 0;
}