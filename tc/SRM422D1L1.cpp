#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int p[7] = {2, 3, 5, 7, 11, 13, 17};
int c[7] = {153, 816, 8568, 31824, 31824, 8568, 18};
double calc(int x){
	double pw = x / (double) 100, r = 0;
	for(int i = 0; i < 7; ++i)
		r += pow(pw, p[i]) * pow(1 - pw, 18 - p[i]) * c[i];
	return r;
}

class PrimeSoccer {
public:
   double getProbability( int skillOfTeamA, int skillOfTeamB ) {
	   double pa = calc(skillOfTeamA), pb = calc(skillOfTeamB);
	   return pa + pb - pa * pb;
   }
};
