#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
set < int > s;
char d[16];
int chain(int k){
	int a = 0, b = 0, c;
	for(c = 0; k; c++) d[c] = '0' + (k % 10), k /= 10;
	d[c] = 0;
	sort(d, d + c);
	for(int i = 0; i < c; ++i){
		a = a * 10 + (d[i] - '0');
		b = b * 10 + (d[c - i - 1] - '0');
	}
	printf("%d - %d = %d\n", b, a, b - a);
	return b - a;
}

int main(void){
	for(int cl, n; scanf("%d", &n) == 1 && n; ){
		s.clear();
		printf("Original number was %d\n", n);
		for(cl = 1, n = chain(n); s.find(n) == s.end(); ++cl){
			s.insert(n);
			n = chain(n);
		}
		printf("Chain length %d\n\n", cl);
	}
	return 0;
}

