#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <string>
using namespace std;
struct BigInt {
	string n;
	BigInt(string num = "0"){
		n = num;
		reverse(n.begin(), n.end());
	}
	BigInt(long long num){
		n = num ? "" : "0";
		while(num) n += num % 10 + '0', num /= 10;
	}
	BigInt operator +(BigInt b){
		BigInt r;
		r.n = n;
		int c, i, l1 = r.n.size(), l2 = b.n.size();
		for(i = l1; i < l2; ++i) r.n += '0';
		for(i = l2; i < l1; ++i) b.n += '0';
		for(c = i = 0; i < l1 || i < l2; ++i){
			r.n[i] = ((c = r.n[i] - '0' + b.n[i] - '0' + c) % 10) + '0';
			c /= 10;
		}
		if(c) r.n += c + '0', ++i;
		b.n = b.n.substr(0, l2);
		return r;
	}
	BigInt operator +=(BigInt b){
		return *this = *this + b;
	}
	BigInt operator +(long long a){
		return *this + BigInt(a);
	}
	BigInt operator +=(long long a){
		return *this = *this + BigInt(a);
	}
	BigInt operator *(BigInt b){
		BigInt r, s;
		int c, i, j, l1 = n.size(), l2 = b.n.size();
		for(i = 0; i < l1; ++i){
			s.n = string(i, '0');
			for(c = j = 0; j < l2; ++j){
				s.n += (c = (n[i] - '0') * (b.n[j] - '0') + c) % 10 + '0';
				c /= 10;
			}
			while(c) s.n += ((c % 10) + '0'), c /= 10;
			r = r + s;
		}
		r.trim();
		return r;
	}
	void trim(){
		int i; for(i = n.size(); --i && n[i] == '0'; )
		n = n.substr(0, i);
	}
	int mycmp(BigInt b){
		int i, l1 = n.size(), l2 = b.n.size();
		if(l1 != l2) return (l1 > l2) - (l1 < l2);
		for(i = l1; i-- && n[i] == b.n[i]; );
		if(i == -1) return 0;
		return (n[i] > b.n[i]) - (n[i] < b.n[i]);
	}
	void show(){		
		printf("%s\n", to_string().c_str());
	}	
	string to_string(){
		string s = n;
		reverse(s.begin(), s.end());
		return s;
	}
};

BigInt dp[51][1001];
int main(void){
	for(int i = 0; i < 1001; ++i) dp[0][i] = BigInt(i == 0);
	for(int i = 1; i <= 50; ++i)
		for(int j = 0; j < 10; ++j)
			for(int k = j; k < 1001; ++k)
				dp[i][k] += dp[i-1][k-j];
	for(int n, s; scanf("%d %d", &n, &s) == 2; ){
		if(s & 1) puts("0");
		else {
			s >>= 1;
			(dp[n][s]*dp[n][s]).show();
		}
	}
	return 0;
}

