#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct word {
	char w[16];
	int len;
	bool operator<(const word x) const{
		return len < x.len || (len == x.len && strcmp(w, x.w) < 0);
	}
} w[10048];
char sep[4];
int pos[16];
set < string > s;
vector < string > ans;
int main(void){
	int n; scanf("%d", &n);
	int len_sum = 0, line_size;
	for(int i = 0; i < n; ++i){
		scanf("%s", w[i].w);
		len_sum += w[i].len = strlen(w[i].w);
	}
	scanf("%s", sep);
	sort(w, w + n);
	pos[w[0].len] = 0;
	line_size = (len_sum + (n >> 1)) / (n>>1);
	s.insert(string(w[0].w));
	for(int i = 1; i < n; ++i){
		s.insert(string(w[i].w));
		if(w[i].len != w[i - 1].len) pos[w[i].len] = i;
	}
	while(!s.empty()){
		string bgn = *s.begin(), end;
		pos[bgn.size()]++;
		int idx_match = pos[line_size - bgn.size() - 1]++;
		end = string(w[idx_match].w);
		string opta = bgn + sep + end;
		string optb = end + sep + bgn;
		if(opta < optb) ans.push_back(opta);
		else ans.push_back(optb);
		s.erase(bgn);
		s.erase(end);
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < (int)ans.size(); ++i)
		printf("%s\n", ans[i].c_str());
	return 0;
}

