#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector < string > w;
string s;
int cnt[128], memo[64];
int same(string a, string b){
	int r = 0;
	for(char i = 'a'; i <= 'z'; ++i) cnt[i] = 0;
	int al = a.size(), bl = b.size();
	if(al != bl) return -1;
	for(int i = 0; i < al; ++i) ++cnt[a[i]], --cnt[b[i]];
	for(char i = 'a'; i <= 'z'; ++i)
		if(cnt[i]) return -1;
	for(int i = 0; i < al; ++i)
		r += a[i] != b[i];
	return r;
}
int test(int l){
	int cost = 1 << 29, len = s.size(), wl, ws = w.size();
	if(l == len) return 0;
	if(memo[l] != -1) return memo[l];
#ifdef DBG
	printf("Testing for string %s (%d)\n", s.substr(l, len).c_str(), l);
#endif
	for(int i = 0; i < ws; ++i){
		wl = w[i].size();
#ifdef DBG
		printf("\tString %s has %d letters\n", w[i].c_str(), wl);
#endif
		if(l + wl > len) continue;
#ifdef DBG
		printf("\tTesting for match on %s [%d - %d] and %s\n", s.substr(l, wl).c_str(), l, l + wl, w[i].c_str());
#endif
		int x = same(s.substr(l, wl), w[i]);
		if(x == -1) continue;
#ifdef DBG
		printf("matched %s with %s\n", s.substr(l, wl).c_str(), w[i].c_str());
#endif
		cost = min(cost, x + test(l + wl));
	}
#ifdef DBG
	printf("Returning %d for string %s\n", cost, s.substr(l, len).c_str());
#endif
	return memo[l] = cost;
}
class SentenceDecomposition {
public:
   int decompose( string sentence, vector <string> validWords ) {
	   int r;
	   for(int i = 0; i < (int) sentence.size(); ++i) memo[i] = -1;
	   s = sentence; w = validWords;
	   r = test(0);
	   return r == (1 << 29) ? -1 : r;
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
			string sentence           = "neotowheret";
			string validWords[]       = {"one", "two", "three", "there"};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string sentence           = "abba";
			string validWords[]       = {"ab", "ac", "ad"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string sentence           = "thisismeaningless";
			string validWords[]       = {"this", "is", "meaningful"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string sentence           = "ommwreehisymkiml";
			string validWords[]       = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string sentence           = "ogodtsneeencs";
			string validWords[]       = {"go", "good", "do", "sentences", "tense", "scen"};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string sentence           = "sepawaterords";
			string validWords[]       = {"separate","words"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string sentence           = ;
			string validWords[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string sentence           = ;
			string validWords[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string sentence           = ;
			string validWords[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SentenceDecomposition().decompose(sentence, vector <string>(validWords, validWords + (sizeof validWords / sizeof validWords[0])));
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
