#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool r[51][1001];
class ChangingSounds {
public:
   int maxFinal( vector <int> changeIntervals, int beginLevel, int maxLevel ) {
	   int n = changeIntervals.size(), v = maxLevel;
	   for(int i = 0; i < n; ++i)
		   for(int j = 0; j <= maxLevel; ++j)
			   r[i][j] = 0;
	   r[0][beginLevel] = 1;
	   for(int i = 1; i <= n; ++i)
		   for(int j = 0; j <= maxLevel; ++j)
			   if(r[i - 1][j]){
				   if(j + changeIntervals[i - 1] <= maxLevel)
					   r[i][j + changeIntervals[i - 1]] = 1;
				   if(j - changeIntervals[i - 1] >= 0)
					   r[i][j - changeIntervals[i - 1]] = 1;
			   }
	   while(v != -1 && !r[n][v]) --v;
	   return v;
   }
};
