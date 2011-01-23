#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[41][2];
class NumberofFiboCalls {
public:
   vector <int> fiboCallsMade( int n ) {
	   vector < int > v(2);
	   dp[0][0] = dp[1][1] = 1;
	   dp[0][1] = dp[1][0] = 0;
	   for(int i = 2; i <= n; ++i){
		   dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		   dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	   }
	   v[0] = dp[n][0];
	   v[1] = dp[n][1];
	   return v;
   }
};
