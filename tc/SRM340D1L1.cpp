#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ProblemsToSolve {
public:
   int minNumber( vector <int> pleasantness, int variety ) {
	   int ans = pleasantness.size(), n = ans;
	   for(int i = 0; i < n; ++i)
		   for(int j = i + 1; j < n; ++j)
			   if(abs(pleasantness[j] - pleasantness[i]) >= variety)
				   ans = min(ans, 1 + ((i + 1) >> 1) + ((j - i + 1) >> 1));
	   return ans;
   }
};
