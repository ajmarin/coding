// Paste me into the FileEdit configuration dialog

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORD(a,b,c)	for(int a = b; a > c; --a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
int v[64][64];
int m, n;
vector < string > p;
bool cr(int i, int j, int s){
	for(int k = j; k < j + s; ++k) if(p[i][k] == 'W') return false;
	return true;
}
bool cc(int i, int j, int s){
	for(int k = i; k < i + s; ++k) if(p[k][j] == 'W') return false;
	return true;
}
class Painting {
public:
	int largestBrush( vector <string> picture ) {
		int c = picture[0].size(), r = picture.size();
		int b = min(c, r);
		p = picture;
		FOR(i, r) FOR(j, c) v[i][j] = 0;
		FOR(i, r) FOR(j, c){
			if(picture[i][j] == 'B'){
				int bs = 1, L = min(r - i, c - j);
				while(bs <= L){
					if(!cr(i + bs - 1, j, bs) || !cc(i, j + bs - 1, bs)){
						--bs;
						break;
					}
					++bs;
				}
				if(bs > L) bs = L;
				FORI(ii, i, i + bs) FORI(jj, j, j + bs)
					v[ii][jj] = max(v[ii][jj], bs);
			}
		}
		FOR(i, r) FOR(j, c) if(picture[i][j] == 'B') b = min(b, v[i][j]);
		return b;
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
			string picture[]          = {"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string picture[]          = {"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string picture[]          = {"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}
;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string picture[]          = {"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}
;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string picture[]          = {"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}
;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
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
