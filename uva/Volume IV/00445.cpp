/////////////////////////////////
// 00445 - Marvelous Mazes
/////////////////////////////////
#include<cstdio>
#include<cctype>
#include<string>
std::string s;
unsigned short int i;
char line[450], k;
int main(void){
	while(gets(line)){
		for(k = i = 0; line[i]; i++){
			while(isdigit(line[i])) {k = k + (line[i]-'0');i++;}		
			if(line[i]=='!') putchar('\n');
			else {
				s = "";
				if(line[i]!='b') while(k--) s.push_back(line[i]);
				else while(k--) s.push_back(' ');
				k = 0;
				printf("%s",s.c_str());
			}
		}
		putchar('\n');
	}
	return 0;
}
