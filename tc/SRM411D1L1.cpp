#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector < string > w;
string s;
int cnt[128], memo[64];
int same(string a, string b){
	int r = 0;
	for(char i = 'a'; i <= 'z'; ++i) cnt[i] = 0;
	int al = a.size(), bl = b.size();
	if(al != bl) return -1;
	for(int i = 0; i < al; ++i) ++cnt[a[i]], --cnt[b[i]];
	for(char i = 'a'; i <= 'z'; ++i)
		if(cnt[i]) return -1;
	for(int i = 0; i < al; ++i)
		r += a[i] != b[i];
	return r;
}
int test(int l){
	int cost = 1 << 29, len = s.size(), wl, ws = w.size();
	if(l == len) return 0;
	if(memo[l] != -1) return memo[l];
	for(int i = 0; i < ws; ++i){
		wl = w[i].size();
		if(l + wl > len) continue;
		int x = same(s.substr(l, wl), w[i]);
		if(x == -1) continue;
		cost = min(cost, x + test(l + wl));
	}
	return memo[l] = cost;
}
class SentenceDecomposition {
public:
   int decompose( string sentence, vector <string> validWords ) {
	   int r;
	   for(int i = 0; i < (int) sentence.size(); ++i) memo[i] = -1;
	   s = sentence; w = validWords;
	   r = test(0);
	   return r == (1 << 29) ? -1 : r;
   }
};
