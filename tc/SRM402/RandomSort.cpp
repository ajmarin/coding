#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map < int, double > m;

int rep(vector < int > v){
	int r = 0;
	for(int i = 0; i < (int) v.size(); ++i) r = r * 10 + v[i];
	return r;
}
double order(vector < int > v){
	double r = 0;
	int t = 0, vr = rep(v), vs = v.size();
	map < int, double > :: iterator f;
	if((f = m.find(vr)) != m.end()) return (*f).second;
	for(int i = 0; i < vs; ++i)
		for(int j = i + 1; j < vs; ++j)
			if(v[i] > v[j]){
				swap(v[i], v[j]);
				r += 1 + order(v);
				t++;
				swap(v[i], v[j]);
			}
	if(t) return m[vr] = r / t;
	return m[vr] = 0;
}
class RandomSort {
	public:
		double getExpected( vector <int> permutation ) {
			return order(permutation);
		}
};
