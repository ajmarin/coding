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
			int questions             = 2;
			string answers[]          = {"No", "Yes"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int questions             = 2;
			string answers[]          = {"No", "No", "No"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int questions             = 3;
			string answers[]          = {"Yes", "No", "No", "Yes"};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int questions             = 3;
			string answers[]          = {"Yes", "Yes", "Yes", "No"};
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
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
