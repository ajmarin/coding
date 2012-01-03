#include <cstdio>
#include <ctime>
#include <queue>
#include <set>
using namespace std;

template <class _T> _T gcd(_T a, _T b){ return b ? gcd(b, a % b) : a; }

template <class _T>
struct frac {
	_T num, den;
	frac(_T n, _T d): num(n), den(d) {}
	frac operator+(const frac& f) const {
		_T new_den = (den / gcd(den, f.den)) * f.den;
		return frac(num * new_den / den + f.num * new_den / f.den, new_den);
	}
	frac inv() const {
		return frac(den, num);
	}
	bool operator<(const frac& f) const {
		return num * f.den < den * f.num;
	}
	bool operator==(const frac& f) const {
		return num == f.num && den == f.den;
	}
};

typedef frac<int> FI;
set< FI > s[20];

int main(void){
	const int MAX_DEPTH = 18;
	clock_t begin = clock();
	s[1].insert(FI(1, 1));
	printf("%4s %9s %9s %8s\n", "#CAP", "EXACTLY", "UP TO", "TIME");
	for(int i = 1; i <= MAX_DEPTH; ++i){
		clock_t it_begin = clock();
		int hs = i >> 1;
		for(int j = 1; j <= hs; ++j){
			set<FI>::const_iterator ia, ib;
			for(ia = s[j].begin(); ia != s[j].end(); ++ia)
				for(ib = s[i - j].begin(); ib != s[i - j].end(); ++ib){
					s[i].insert( (*ia) + (*ib) );
					s[i].insert( (ia->inv() + ib->inv()).inv() );
				}
		}
		for(set<FI>::const_iterator it = s[i].begin(); it != s[i].end(); ++it)
			s[MAX_DEPTH].insert(*it);
		printf("[%2d] %9d %9d %7.3lfs\n", i, s[i].size(), s[MAX_DEPTH].size(),
				(clock() - it_begin) / double(CLOCKS_PER_SEC));
	}
	printf("Answer: %d\n", s[MAX_DEPTH].size());
	printf("Time spent: %.3lfs\n", (clock() - begin) / double(CLOCKS_PER_SEC));
	return 0;
}

