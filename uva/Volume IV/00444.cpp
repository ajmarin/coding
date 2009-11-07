/////////////////////////////////
// 00444 - Encoder and Decoder
/////////////////////////////////
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
char ans[250],word[250];
int i,j,num;
int main(void){
	while(gets(word)){
		if(isdigit(word[0])){
			std::reverse(word,word+strlen(word));
			for(i = j = 0 ; word[i]; ){
				if(word[i] == '1')
					num = 100*(word[i]-'0')+10*(word[i+1]-'0')+word[i+2]-'0',i+=3;
				else num = 10*(word[i]-'0')+word[i+1]-'0',i+=2;
				ans[j++] = num;
			}
			ans[j] = 0;
			puts(ans);
		} else {
			for(i = j= 0; word[i]; i++)
				if(word[i] < 100)
					ans[j++] = (word[i]/10)+'0',
					ans[j++] = (word[i]%10)+'0';
				else ans[j++] = (word[i]/100)+'0',
					 ans[j++] = ((word[i]/10)%10)+'0',
					 ans[j++] = (word[i]%10)+'0';
			ans[j] = 0;
			std::reverse(ans,ans+j);
			puts(ans);
		}
	}
	return 0;
}
