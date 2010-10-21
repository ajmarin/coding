
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int m, n;
bool test(int r, int c, const vector <string> &b){
	char z = b[r][c];
	for(int i = 1; i <= r; ++i)
		for(int j = 1; j <= c; ++j)
			if(b[r - i][c] == z && b[r][c - j] == z && b[r - i][c - j] == z)
				return 0;
	return 1;
}
void bt(int k, int &cnt, vector <string> &b){
	if(k == (n * m)){ ++cnt; return; }
	int c = k % m, r = k / m;
	if(b[r][c] == '?'){
		b[r][c] = 'B';
		if(test(r, c, b)) bt(k + 1, cnt, b);
		b[r][c] = 'W';
		if(test(r, c, b)) bt(k + 1, cnt, b);
		b[r][c] = '?';
	} else if(test(r, c, b)) bt(k + 1, cnt, b);
}
class RectangleAvoidingColoringEasy {
	public:
	int count( vector <string> board ) { 
		int cnt = 0;
		m = board[0].size();
		n = board.size();
		bt(0, cnt, board);
		return cnt;
	}
};

