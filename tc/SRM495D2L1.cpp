#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CarrotBoxesEasy {
public:
	int theIndex( vector <int> carrots, int K ) {
		int n = carrots.size();
		while(1){
			int idx = -1, max = 0;
			for(int i = 0; i < n; ++i)
				if(carrots[i] > max){
					max = carrots[i];
					idx = i;
				}
			carrots[idx]--;
			if(--K == 0) return idx;
		}
	}
};
