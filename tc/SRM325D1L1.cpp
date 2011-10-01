#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

double c[3000];
class FenceRepairing {
public:
   double calculateCost( vector <string> boards ) {
	   string f;
	   for(int i = 0; i < (int)boards.size(); ++i) f += boards[i];
	   int n = f.size();
	   f = " " + f;
	   c[0] = 0;
	   for(int i = 1; i <= n; ++i){
		   c[i] = 5000;
		   if(f[i] == '.') c[i] = c[i - 1];
		   for(int j = 0; j < i; ++j)
			   c[i] = min(c[i], c[j] + sqrt(i - j));
	   }
	   return c[n];
   }
};
