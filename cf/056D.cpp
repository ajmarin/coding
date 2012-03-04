#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
string h, w;
char word[1024];
int type[1024][1024], memo[1024][1024];
int l1, l2;
int min(int a, int b){ return a < b ? a : b; }
int r(int a, int b){
	if(memo[a][b] != -1) return memo[a][b];
	if(a == l1 && b == l2){ // Done
		return memo[a][b] = type[a][b] = 0;
	}
	if(b == l2){			// DELETE until h == w type < 0
		return memo[a][b] = -(type[a][b] = a - l1);
	}
	if(a == l1){			// INSERT until h == w type > 0
		return memo[a][b] = type[a][b] = l2 - b;
	}
	int test1 = 1 + r(a, b + 1); 	// INSERT test
	int test2 = 1 + r(a + 1, b); 	// DELETE test
	if(test1 < test2){				// INSERT is better
		type[a][b] = 1;
		memo[a][b] = test1;
	} else {						// DELETE is better
		type[a][b] = -1;
		memo[a][b] = test2;
	}
	if(h[a] == w[b]){ 				// No move required
		int v = r(a + 1, b + 1);
		if(v < memo[a][b]){			// Is it better?
			memo[a][b] = v;
			type[a][b] = 0;
		}
	} else {						// Try replace
		int v = 1 + r(a + 1, b + 1);
		if(v < memo[a][b]){
			memo[a][b] = v;
			type[a][b] = 1234;
		}
	}
	return memo[a][b];
}
int main(void){
	scanf("%s", word); h = string(word);
	scanf("%s", word); w = string(word);
	l1 = h.size(), l2 = w.size();
	for(int i = 0; i <= l1; ++i) for(int j = 0; j <= l2; ++j) memo[i][j] = -1;
	printf("%d\n", r(0, 0));
	for(int i = 0, j = 0; i < l1 || j < l2; ){
		if(type[i][j] == 0) ++i, ++j;
		else if(type[i][j] == 1234) printf("REPLACE %d %c\n", j + 1, w[j]), ++i, ++j;
		else if(type[i][j] == 1)	printf("INSERT %d %c\n", j + 1, w[j]), ++j;
		else if(type[i][j] == -1)	printf("DELETE %d\n", j + 1), ++i;
		else if(type[i][j] > 0) for( ; j < l2; ++j) printf("INSERT %d %c\n", j + 1, w[j]);
		else if(type[i][j] < 0) for( ; i < l1; ++i) printf("DELETE %d\n", j + 1);
	}
	return 0;
}

