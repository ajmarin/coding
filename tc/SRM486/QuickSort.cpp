#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map < vector < int >, double > m;
double quick_cost(vector < int > v){
	int n = v.size();
	double exp = 0;
	map < vector < int >, double>:: iterator it = m.find(v);
	if(it != m.end()) return it->second;
	if(n <= 1) return 0;
	for(int i = 0; i < n; ++i){
		int p = v[i];
		vector < int > low;
		vector < int > high;
		for(int j = 0; j < n; ++j){
			if(j == i) continue;
			if(v[j] < p){
				low.push_back(v[j]);
				if(j > i) exp += 1;
			} else {
				high.push_back(v[j]);
				if(j < i) exp += 1;
			}
		}
		exp += quick_cost(low) + quick_cost(high);
	}
	return m[v] = exp / (double) n;
}
class QuickSort {
public:
	double getEval( vector <int> L ) {
		return quick_cost(L);
	}
};
