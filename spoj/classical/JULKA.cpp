#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;
class BigInt {
	public:
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
	BigInt operator -(BigInt b){
		BigInt r;
		if(*this == b) return BigInt("0");
		assert(*this >= b);
		int i, l1 = n.size(), l2 = b.n.size();
		for(i = 0; i < l2; ++i) b.n[i] = '9' - b.n[i] + '0';
		for(i = l2; i < l1; ++i) b.n += '9';
		r = *this + b;
		l1 = r.n.size();
		r.n[l1 - 1]--;
		r += 1;
		r.trim();
		for(i = 0; i < l2; ++i) b.n[i] = '9' - b.n[i] + '0';
		b.n = b.n.substr(0, l2);
		return r;
	}
	BigInt operator -=(BigInt b){
		return *this = *this - b;
	}
	BigInt operator -(long long a){
		return *this - BigInt(a);
	}
	BigInt operator -=(long long a){
		return *this = *this - BigInt(a);
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
	BigInt operator *=(BigInt b){
		return *this = *this * b;
	}
	BigInt operator *(long long a){
		return *this * BigInt(a);
	}
	BigInt operator *=(long long a){
		return *this = *this * BigInt(a);
	}
	BigInt operator >>(int x){
		BigInt r = *this;
		reverse(r.n.begin(), r.n.end());
		for(int i = 0; i < x; ++i){
			string result = "";
			int d = 0, sz = r.n.size();
			for(int i = 0; i < sz; ++i){
				d = d * 10 + r.n[i] - '0';
				result += (d >> 1) + '0';
				d &= 1;
			}
			r.n = result;
		}
		reverse(r.n.begin(), r.n.end());
		r.trim();
		return r;
	}
	BigInt sqroot(){
		string num = n; int l = n.size();
		reverse(num.begin(), num.end());
		BigInt r, rem, x(num.substr(0, 2 - (l & 1)));
		int f = l & 1 ? x.n[0] - '0' : 10 * (x.n[1] - '0') + (x.n[0] - '0');
		f = (int)sqrt(f);
		r = BigInt(f);
		rem = x - f * f;
		for(int i = 2 - (l & 1), d; i < l; i += 2){
			BigInt down = r * 20;
			rem = rem * 100 + num.substr(i, 2);
			rem.trim();
			for(d = 1; d < 10 && ((down + d) * d) <= rem; ++d);
			r.n = (char)(--d + '0') + r.n;
			rem = rem - (down + d) * d;
		}
		return r;
	}
	bool operator ==(BigInt b){
		return mycmp(b) == 0;
	}
	bool operator !=(BigInt b){
		return mycmp(b) != 0;
	}
	bool operator >(BigInt b){
		return mycmp(b) > 0;
	}
	bool operator >=(BigInt b){
		return mycmp(b) >= 0;
	}
	bool operator <(BigInt b){
		return mycmp(b) < 0;	
	}
	bool operator <=(BigInt b){
		return mycmp(b) <= 0;
	}
	bool operator ==(long long a){
		return *this == BigInt(a);
	}
	bool operator !=(long long a){
		return *this != BigInt(a);
	}
	bool operator >(long long a){
		return *this > BigInt(a);
	}
	bool operator >=(long long a){
		return *this >= BigInt(a);
	}
	bool operator <(long long a){
		return *this < BigInt(a);
	}
	bool operator <=(long long a){
		return *this <= BigInt(a);
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

char a[128], b[128];
int main(void){
	BigInt diff, klaudia, natalia, total;
	for(int i = 0; i < 10; ++i){
		scanf("%s %s", a, b);
		total = string(a);
		diff = string(b);
		natalia = (total - diff) >> 1;		
		klaudia = total - natalia;
		klaudia.show();
		natalia.show();
	}
	return 0;
}