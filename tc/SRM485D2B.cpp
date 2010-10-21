
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class AfraidOfEven {
	public:
	vector <int> restoreProgression( vector <int> v ) {
		int n = v.size() - 1;
		for(int i = 0; (v[0] << i) > 0; ++i)
			for(int j = 0; (v[n] << j) > 0; ++j){
				int r, t, x = v[0] << i, y = v[n] << j;
				if((y - x) % n) continue;
				r = (y - x) / n;
				for(int k = 1; k < n; ++k){
					x += r;
					if(x % v[k]) break;
					t = x / v[k];
					if(t & (t - 1)) break;
				}
				if(x == (y - r) && !(t & (t - 1))){
					v[0] <<= i; v[n] <<= j;
					for(int k = 1; k < n; ++k) v[k] = v[k - 1] + r;
					return v;
				}
			}
	}
};

