#include <algorithm>
#include <cassert>
#include <cmath>
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

int main(void){
	assert(BigInt(69) > BigInt(52));
	assert(BigInt(1) - 1 == 0);
	assert(BigInt(873) > BigInt(218));
	assert(BigInt(159) < BigInt(951));
	assert(BigInt(873) - BigInt(218) == 655);
	assert(BigInt(1000) - BigInt(2) == 998);
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