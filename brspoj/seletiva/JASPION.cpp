#include<cstdio>
#include<map>
#include<string>
#include<list>
#include<cstring>
using namespace std;
map<string,int> dict;
string ans, corr[1000024];
char line[100], *ptr, trans[100], word[100];
int cases, i, lines, words;
int main(void){
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d\n",&words,&lines);
		dict.clear();
		for(i = 0; i < words; i++){
			gets(word);
			gets(trans);
			dict[string(word)] = i;
			corr[i] = string(trans);			
		}
		for(i = 0; i < lines; i++){
			gets(line);
			ans = "";
			ptr = strtok(line," ");
			while(ptr!=NULL){
				if(dict.find(string(ptr)) != dict.end()) ans += corr[dict[string(ptr)]];
				else ans += string(ptr);
				ptr = strtok(NULL," ");
				if(ptr!=NULL) ans += " ";				
			}
			puts(ans.c_str());
		}
		if(cases) putchar('\n');	
	}
	return 0;
}

