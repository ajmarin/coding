
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BunnyComputer {
public:
   int getMaximum( vector <int> v, int k ) {
	   int n = v.size(), r = 0; ++k;
	   for(int i = 0; i < k; ++i){
		   int cnt = 0, sum = 0;
		   for(int j = i; j < n; j += k) sum += v[j], ++cnt;
		   if(cnt & 1){
			   int min = (1 << 25);
			   for(int j = i; j < n; j += 2 * k) if(v[j] < min) min = v[j];
			   sum -= min;
		   }
		   r += sum;
	   }
	   return r;
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
			int preference[]          = { 3, 1, 4, 1, 5, 9, 2, 6 };
			int k                     = 2;
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int preference[]          = { 3, 1, 4, 1, 5, 9, 2, 6 };
			int k                     = 1;
			int expected__            = 31;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int preference[]          = { 1, 2, 3, 4, 5, 6 };
			int k                     = 3;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int preference[]          = { 487, 2010 };
			int k                     = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

	   case 4: {
			int preference[]          = {979595, 979675, 980007, 980772, 981772, 985833, 999837, 979596, 979680, 980189, 980806, 981824, 986226, 987304, 979597, 979686, 980265, 981198, 981846, 981923, 987725, 979603, 979692, 980306, 981205, 981381, 982048, 988845, 979615, 979755, 980342, 980444, 981519, 983358, 989670, 979634, 979841, 979929, 980548, 981550, 984182, 989691, 979661, 979675, 979973, 980705, 981551, 985581, 999309};
			int k                     = 6;
			int expected__            = 41274115;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int preference[]          = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int preference[]          = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
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
