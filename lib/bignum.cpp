#include <algorithm>
#include <cassert>
#include <cstdio>
#include <string>
using namespace std;
class BigInt {
	string n;
	public:
	BigInt(string num = "0"){
		n = num;
		reverse(n.begin(), n.end());
	}
	BigInt(long long num){
		n = "";
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
	bool operator ==(BigInt b){
		return n == b.n;
	}
	bool operator ==(long long a){
		return *this == BigInt(a);
	}
	bool operator >(BigInt b){
		return n.size() > b.n.size() || n.compare(b.n) > 0;
	}
	bool operator >=(BigInt b){
		return n.size() >= b.n.size() || n.compare(b.n) >= 0;
	}
	bool operator <(BigInt b){
		return n.size() < b.n.size() || n.compare(b.n) < 0;	
	}
	bool operator <=(BigInt b){
		return n.size() <= b.n.size() || n.compare(b.n) <= 0;
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
	void show(){		
		printf("%s\n", to_string().c_str());
	}
	string to_string(){
		string s = n;
		reverse(s.begin(), s.end());
		return s;
	}
};
int main(void){
	assert(BigInt(5) * BigInt(2) == BigInt(10));
	assert(BigInt(777) * BigInt(3333) == BigInt(2589741));
	assert(BigInt(1LL<<62) + BigInt(1LL<<62) == BigInt("9223372036854775808"));
	assert(BigInt(1LL<<60) + BigInt(1LL<<60) == 1LL<<61);
	assert(BigInt(1LL<<50) * BigInt(1LL<<10) == BigInt(1LL<<60));
	assert(BigInt(2) > BigInt("1"));
	assert(BigInt(1LL<<30) >= BigInt(1LL<<30));
	assert(BigInt("123456789999999999998") < BigInt("123456789999999999999"));
	assert(BigInt("123456789999999999999") <= BigInt("123456789999999999999"));
	assert(BigInt("1723") < 88884);
	assert(BigInt("123") > 122);
	assert(BigInt(140) >= 140);
	assert(BigInt(130) <= 130);
	printf("TEST SUCEEDED\n");
	return 0;
}