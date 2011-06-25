#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char train[16];

int solve(char *t, int n, char target){
	if(n == 0) return 0;
	int moves = 1;
	if(t[0] == target) return solve(t + 1, n - 1, target + 1);
	if(t[n - 1] != target){
		int i;
		for(i = 0; i < n; ++i) if(t[i] == target) break;
		reverse(t + i, t + n);
		++moves;
	}
	reverse(t, t + n);
	return moves + solve(t + 1, n - 1, target + 1);
}

int findMaximixArrangement(int n, int idx = -1){
	int count = 0, maximix = 2 * n - 3;
	char o[16];
	for(int i = 0; i < n; ++i) o[i] = 'A' + i;
	o[n] = 0;
	do {
		strcpy(train, o);
		if(solve(train, n, 'A') == maximix) ++count;
		if(count == idx){
			printf("%s -> %d\n", o, maximix);
			return -1;
		}
	} while(std::next_permutation(o, o + n));
	return count;
}

int main(void){
	findMaximixArrangement(11, 1);
	return 0;
}

