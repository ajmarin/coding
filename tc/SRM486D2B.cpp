#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef long long ret;
class MovieSeating {
	public:
		ret getSeatings(int, vector < string >);
};
long long fact(int a){
	long long r = 1;
	for(int x = 2; x <= a; ++x) r *= x;
	return r;
}
long long comb(int a, int b){
	long long r = 1;
	if(a - b > b) b = a - b;
	for(int x = b + 1; x <= a; ++x) r *= x;
	r /= fact(a - b);
}
ret MovieSeating::getSeatings(int f, vector < string > h){
	ret r = 0;
	vector < int > rcnt(h.size(), 0);
	vector < int > ccnt(h[0].size(), 0);
	for(int i = 0; i < h.size(); ++i){
		for(int j = 0; j < h[i].size(); ++j)
			if(h[i][j] == '.') rcnt[i]++, ccnt[j]++;
		if(rcnt[i] >= f) r += comb(rcnt[i], f) * fact(f);
	}
	if(f > 1)
		for(int i = 0; i < h[0].size(); ++i)
			if(ccnt[i] >= f) r += comb(ccnt[i], f) * fact(f);

	return r;
}

