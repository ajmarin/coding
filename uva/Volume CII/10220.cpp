/////////////////////////////////
// 10220 - I Love Big Numbers !
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned int c,i,it,n;
char res[3500];
unsigned int ans[1001];
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
void calcans(){
	ans[it] = 0;
	for(i = 0; res[i] ; i++) ans[it] += res[i];
	ans[it] -= i*'0';
}
int main(void){
	n = 1001;
	ans[0] = ans[1] = 1;
	strcpy(res,"1");
	for(it = 2; it != n; it++) multi(), calcans();
	while(scanf("%u",&n)==1) printf("%u\n",ans[n]);
	return 0;
}
