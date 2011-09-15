#include <cstdio>
#include <map>
#include <string>
using namespace std;
map < string, string > back;
map < string, int > cnt;

char line[128];
bool valid[128];
bool digit(char c){ return c >= '0' && c <= '9'; }
bool upper(char c){ return c >= 'A' && c <= 'Z'; }
bool lower(char c){ return c >= 'a' && c <= 'z'; }
void to_upper(char& c){ c = c - (lower(c) << 5); }
void addLine(){
	char tmp[128];
	char abbr[128];
	for(int i = 0, j; line[i]; ++i){
		for(j = 0; valid[line[i + j]]; ++j) tmp[j] = line[i + j] + (upper(line[i + j]) << 5) ;
		if(j){
			tmp[j] = 0;
			char saved = line[i + j];
			line[i + j] = 0;
			if(digit(tmp[1])){ // abbreviation
				if(cnt[tmp] == 1){
					string show = back[tmp].c_str();
					if(upper(line[i])) to_upper(show[0]);
					if(upper(line[i + j - 1])) 
						for(int k = 1; k < (int)show.size(); ++k)
							to_upper(show[k]);
					printf("%s", show.c_str());
				}
				else printf("%s", &line[i]);
			} else { // just a word
				if(j >= 4){
					sprintf(abbr, "%c%d%c", tmp[0], j-2, tmp[j-1]);
					if(back[abbr] != tmp) ++cnt[abbr];
					back[abbr] = tmp;
				}
				printf("%s", &line[i]);
			}
			line[i + j] = saved;
			i = i + j - 1;
		} else putc(line[i], stdout);
	}
	puts("");
}
int main(void){
	for(int i = 0; i < 128; ++i) valid[i] = false;
	for(int c = 'A'; c <= 'Z'; ++c) valid[c] = true;
	for(int c = 'a'; c <= 'z'; ++c) valid[c] = true;
	for(int c = '0'; c <= '9'; ++c) valid[c] = true;
	for(int f(0); gets(line); ++f){
		if(f) puts("");
		back.clear();
		cnt.clear();
		do {
			addLine();
		} while(gets(line) && line[0] != 0);
	}

	return 0;
}

