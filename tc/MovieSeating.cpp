
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int fc[128], fr[128];
long long fact(int n, int k){
	long long r = 1;
	for(int i = n; i > k; i--) r *= i; 
	return r;
}
class MovieSeating {
public:
   long long getSeatings( int numFriends, vector <string> hall ) {
	   long long r = 0;
	   int col = hall[0].size(), row = hall.size();
	   for(int i = 0; i < row; fr[i++] = 0);
	   for(int j = 0; j < col; fc[j++] = 0);
	   for(int i = 0; i < row; ++i){
		   for(int j = 0; j < col; ++j) if(hall[i][j] == '.') fc[j]++, fr[i]++;
		   if(fr[i] >= numFriends) r += fact(fr[i], fr[i] - numFriends);
	   }
	   for(int j = 0; j < col; ++j) 
		   if(fc[j] >= numFriends) r += fact(fc[j], fc[j] - numFriends);
	   return r >> (numFriends == 1);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int numFriends            = 2;
			string hall[]             = { ".#..",
  ".##.",
  "...." };
			long long expected__      = 34;

			clock_t start__           = clock();
			long long received__      = MovieSeating().getSeatings(numFriends, vector <string>(hall, hall + (sizeof hall / sizeof hall[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int numFriends            = 2;
			string hall[]             = { "..#",
  ".##",
  "..." };
			long long expected__      = 16;

			clock_t start__           = clock();
			long long received__      = MovieSeating().getSeatings(numFriends, vector <string>(hall, hall + (sizeof hall / sizeof hall[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int numFriends            = 5;
			string hall[]             = { "..####..", 
  ".###.##.",
  ".######.",
  "#.#.#.#." };
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = MovieSeating().getSeatings(numFriends, vector <string>(hall, hall + (sizeof hall / sizeof hall[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int numFriends            = 8;
			string hall[]             = { "........" };
			long long expected__      = 40320;

			clock_t start__           = clock();
			long long received__      = MovieSeating().getSeatings(numFriends, vector <string>(hall, hall + (sizeof hall / sizeof hall[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int numFriends            = ;
			string hall[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MovieSeating().getSeatings(numFriends, vector <string>(hall, hall + (sizeof hall / sizeof hall[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int numFriends            = ;
			string hall[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MovieSeating().getSeatings(numFriends, vector <string>(hall, hall + (sizeof hall / sizeof hall[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numFriends            = ;
			string hall[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MovieSeating().getSeatings(numFriends, vector <string>(hall, hall + (sizeof hall / sizeof hall[0])));
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
