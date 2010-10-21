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

class MicrowaveSelling {
	public:
	int mostAttractivePrice( int minPrice, int maxPrice ) {
		int maxt9 = 0, maxn = 0;
		for(int i = minPrice; i <= maxPrice; ++i){
			int x = i, c = 0;
			while(x && x % 10 == 9){
				c++, x /= 10;
			}
			if(c >= maxt9){
				maxt9 = c;
				maxn = i;
			}
		}
		return maxn;
	}
};

