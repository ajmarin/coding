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

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int changeIntervals[]     = {5, 3, 7};
			int beginLevel            = 5;
			int maxLevel              = 10;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int changeIntervals[]     = {15, 2, 9, 10};
			int beginLevel            = 8;
			int maxLevel              = 20;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int changeIntervals[]     = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
			int beginLevel            = 40;
			int maxLevel              = 243;
			int expected__            = 238;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
