#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector < string > ans;
int bt(int k, int uk, int y, int n){
	if(k == ans.size()) return uk == 0;
	int r = 0;
	if(uk){
		if(ans[k][0] == 'Y') r += uk * bt(k + 1, uk - 1, y + 1, n);
		else r += uk * bt (k + 1, uk - 1, y, n + 1);
	}
	if(ans[k][0] == 'Y' && y) r += y * bt(k + 1, uk, y, n);
	else if(ans[k][0] == 'N' && n) r += n * bt(k + 1, uk, y, n);
	return r;
}
class TheQuestionsAndAnswersDivOne {
public:
   int find( int questions, vector <string> answers ) {
	   ans = answers;
	   return bt(0, questions, 0, 0);
   }
};
