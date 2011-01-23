#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long a[32], b[32];
class ForbiddenStrings {
public:
   long long countNotForbidden( int n ) {
	   a[0] = 1;
	   a[1] = 3;
	   a[2] = 6;
	   b[1] = 0;
	   b[2] = 3;
	   for(int i = 3; i <= n; ++i){
		   a[i] = (b[i - 1] << 1) + a[i - 1];
		   b[i] = b[i - 1] + a[i - 1];
	   }
	   return a[n] + b[n];

   }
};
