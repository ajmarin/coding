#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int accept[128];
class Filtering {
public:
	vector <int> designFilter( vector <int> sizes, string outcome ) {
		int n = sizes.size();
		vector < int > r;
		for(int i = 0; i < 128; ++i) accept[i] = 0;
		for(int i = 0; i < n; ++i){
			if(outcome[i] == 'A') accept[sizes[i]] = 1;
			else accept[sizes[i]] = -1;
		}
		int A, B, i;	
		for(A = 0; A < 128 && accept[A] != 1; ++A);
		for(B = 127; B > -1 && accept[B] != 1; --B);
		for(i = A; i <= B; ++i) if(accept[i] == -1)	break;
		if(i != B + 1) return r;
		r.push_back(A);
		r.push_back(B);
		return r;
	}
};
