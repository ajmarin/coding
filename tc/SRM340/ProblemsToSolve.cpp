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
			int pleasantness[]        = {1, 2, 3};
			int variety               = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ProblemsToSolve().minNumber(vector <int>(pleasantness, pleasantness + (sizeof pleasantness / sizeof pleasantness[0])), variety);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int pleasantness[]        = {1, 2, 3, 4, 5};
			int variety               = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ProblemsToSolve().minNumber(vector <int>(pleasantness, pleasantness + (sizeof pleasantness / sizeof pleasantness[0])), variety);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int pleasantness[]        = {10, 1, 12, 101};
			int variety               = 100;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ProblemsToSolve().minNumber(vector <int>(pleasantness, pleasantness + (sizeof pleasantness / sizeof pleasantness[0])), variety);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int pleasantness[]        = {10, 1};
			int variety               = 9;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ProblemsToSolve().minNumber(vector <int>(pleasantness, pleasantness + (sizeof pleasantness / sizeof pleasantness[0])), variety);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int pleasantness[]        = {6, 2, 6, 2, 6, 3, 3, 3, 7};
			int variety               = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ProblemsToSolve().minNumber(vector <int>(pleasantness, pleasantness + (sizeof pleasantness / sizeof pleasantness[0])), variety);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int pleasantness[]        = ;
			int variety               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ProblemsToSolve().minNumber(vector <int>(pleasantness, pleasantness + (sizeof pleasantness / sizeof pleasantness[0])), variety);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int pleasantness[]        = ;
			int variety               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ProblemsToSolve().minNumber(vector <int>(pleasantness, pleasantness + (sizeof pleasantness / sizeof pleasantness[0])), variety);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int pleasantness[]        = ;
			int variety               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ProblemsToSolve().minNumber(vector <int>(pleasantness, pleasantness + (sizeof pleasantness / sizeof pleasantness[0])), variety);
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
