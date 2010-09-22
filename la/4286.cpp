#include <algorithm>
#include <cctype>
#include <cstdio>
#include <vector>
#define IN getc(stdin)
using namespace std;
vector < pair < int , int > > v(65536, make_pair(0, 0));
int maxd, n;
void parse(int d){
	char c = IN;
	if(c == '['){
		parse(d + 1);
		IN;
		parse(d + 1);
		IN;
	} else{
		int x = 0;
		while(isdigit(c)){
			x = x * 10 + (c - '0');
			c = IN;
		}
		ungetc(c, stdin);
		v[n] = make_pair(x, d);
		n++;
	}
	if(d > maxd) maxd = d;
}

int main(void){
	int mine, t; scanf("%d", &t);
	while(t--){
		IN;
		maxd = n = 0;
		parse(0);
		for(int i = 0; i < n; ++i){
			int *a = &v[i].first, *b = &v[i].second;
			*b = (1 << (maxd - *b));
			while(!(*a & 1) && !(*b & 1)) *a >>= 1, *b >>= 1;
		}
		mine = n;
		sort(v.begin(), v.begin() + n);
		for(int i = 0, j = 0; i < n && j < n; ){
			while(j < n && v[i] == v[j]) ++j;
			mine = min(mine, n - j + i);
			i = j;
		}
		printf("%d\n", mine);
	}

	return 0;
}
