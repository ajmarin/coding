#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct word {
	char s[32];
	int cnt[26], len;
	word(const char *w){
		for(len = 0; s[len] = w[len]; ++len);
		s[--len] = 0;
		for(int i = 0; i < 26; ++i) cnt[i] = 0;
		for(int i = 0; i != len; ++i) ++cnt[s[i] - 'A'];
	}
	word(){}
	bool operator<(const word &w) const{
		return strcmp(s, w.s) < 0;
	}
} w[2048];

char phrase[128], tmp[128];
int rem[26], wc, widx[64];
vector<string> ps, ws;

void bt(int d, int k, int last){
	if(!k){
		bool valid = true;
		for(int i = 0; valid && i < 26; ++i) valid &= !rem[i];
		if(valid){
			ws.clear();
			for(int i = 0; i < d; ++i) ws.push_back(string(w[widx[i]].s));
			sort(ws.begin(), ws.end());
			if(ps != ws){
				printf("%s =", phrase);
				for(int i = 0; i < d; ++i) printf(" %s", w[widx[i]].s);
				puts("");
			}
		}
		return;
	}
	for(int i = last; i < wc; ++i){
		bool usable = w[i].len <= k;
		for(int j = 0; usable && j < 26; ++j)
			usable &= w[i].cnt[j] <= rem[j];
		if(usable){
			for(int j = 0; j != w[i].len; ++j) --rem[w[i].s[j] - 'A'];
			widx[d] = i;
			bt(d + 1, k - w[i].len, i + 1);
			for(int j = 0; j != w[i].len; ++j) ++rem[w[i].s[j] - 'A'];
		}
	}

}

int main(void){
	while(true){
		for(wc = 0; fgets(phrase, 128, stdin) && *phrase != '#'; w[wc++] = word(phrase));
		if(wc == 0) break;
		sort(w, w + wc);
		for(int len, spaces; fgets(phrase, 128, stdin) && *phrase != '#'; ){
			for(int i = 0; i < 26; ++i) rem[i] = 0;
			for(len = spaces = 0; phrase[len]; ++len){
				if(phrase[len] >= 'A' && phrase[len] <= 'Z') ++rem[phrase[len] - 'A'];
				else if(phrase[len] == ' ') ++spaces;
			}
			phrase[--len] = 0;
			strcpy(tmp, phrase);
			ps.clear();
			for(char *p = strtok(tmp, " "); p != NULL; p = strtok(NULL, " "))
				ps.push_back(string(p));
			sort(ps.begin(), ps.end());
			bt(0, len - spaces, 0);
		}
	}
	return 0;
}

