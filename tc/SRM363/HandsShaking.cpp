#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long catalan(int x){
	long long r = 1;
	for(int i = x << 1, j = 1; i > x; --i, ++j) r = (r * i) / j;
	return r / (x + 1);
}

class HandsShaking {
public:
   long long countPerfect( int n ) {
	   return catalan(n >> 1);
   }
};
