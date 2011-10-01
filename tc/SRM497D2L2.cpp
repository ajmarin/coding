#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool used[64];
class PermutationSignature {
public:
	vector <int> reconstruct( string signature ) {
		int n = signature.size();
		int c = 1;
		for(int i = 0; i <= n + 1; ++i) used[i] = 0;
		vector < int > r;
		for(int i = 0; i < n; ++i){
			if(signature[i] == 'D'){
				if(i == 0 || signature[i - 1] != 'D'){
					int add = 1;
					for(int j = i + 1; j < n; ++j){
						if(signature[j] == 'I') break;
						++add;
					}
					for(int j = 1; j <= n + 1; ++j){
						if(!used[j] && --add == -1){
							c = j; break;
						}
					}
				}
				used[c] = 1;
				r.push_back(c--);
			}
			else {
				while(used[c]) ++c;
				used[c] = 1;
				r.push_back(c);
			}
		}
		for(int i = 1; i <= n + 1; ++i) if(!used[i]) r.push_back(i);
		return r;
	}
};
