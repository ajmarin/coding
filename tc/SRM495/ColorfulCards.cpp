#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s = "";
int m[1024][1024];
bool prime(int x){
	if(x < 2) return false;
	if(x == 2 || x == 3 || x == 5 || x == 7) return true;
	if(!(x & 1) || !(x % 3)) return false;
	for(int i = 6; ; i += 6){
		int t1 = i + 1, t2 = i - 1;
		if(!(x % t1) || !(x % t2)) return false;
		if(t2 * t2 > x) return true;
	}
}
void build_string(int n){
	s = "";
	for(int i = 1; i < n; ++i){
		if(prime(i)) s += "R";
		else s += "B";
	}
}
int LCS(string x, string y){
	int l1 = x.size(), l2 = y.size();
	for(int i = 0; i < 64; ++i) m[0][i] = m[i][0] = 0;
	for(int i = 1; i <= l1; ++i)	
		for(int j = 1; j <= l2; ++j)
			if(x[i - 1] == y[j - 1])
				m[i][j] = m[i - 1][j - 1] + 1;
			else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
	return m[l1][l2];
}
class ColorfulCards {
public:
	vector <int> theCards( int N, string colors ) {
		vector < int > ans;
		build_string(N + 1);
		int minj = -1, cs = colors.size(), l = s.size();
		for(int i = 0; i < cs; ++i){
			string x = colors.substr(i, cs - i);
			int j;
			for(j = minj + 1; j < l; ++j)
				if(s[j] == x[0]){ minj = j; break; }
			string y = s.substr(minj + 1, l - (minj + 1));
			if(LCS(y, x) == cs - i) ans.push_back(-1);
			else ans.push_back(minj + 1);
		}
		return ans;
	}
};
