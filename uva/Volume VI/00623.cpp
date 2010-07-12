/////////////////////////////////
// 00623 - 500!
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<string>
std::string ans;
unsigned int c,i,it,len,n;
char res[1001][3000];
void multi(){
	strcpy(res[it],res[it-1]);
	for(c = i = 0; res[it][i]; i++){
		c = (res[it][i]-'0')*it+c;
		res[it][i] = c%10+'0';
		c/=10;
	}
	while(c){
		res[it][i++] = '0'+c%10;
		c/=10;
	}
	res[it][i] = 0;
}
int main(void){
	n = 1001;
	ans[0] = ans[1] = 1;
	strcpy(res[0],"1");
	strcpy(res[1],"1");	
	it = 2;
	while(scanf("%u",&n)==1){
		while(it <= n){
			multi(), it++;
		}
		len = strlen(res[n]);
		ans = "";
		for(i = len-1; i; i--) ans.push_back(res[n][i]);
		ans.push_back(res[n][0]);		
		printf("%u!\n%s\n",n,ans.c_str());
	}
	return 0;
}
