#include <algorithm>
#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)

int books[10048];

int main(void){

	for(int m, n, y, z; scanf("%d", &n) == 1 && n; ){
		FOR(i, n) scanf("%d", books + i);
		std::sort(books, books + n);
		scanf("%d", &m);
		for(int i = 0, j = n - 1; i < j; ){
			int sum = books[i] + books[j];
			if(sum == m) y = i++, z = j--;
			else if(sum < m) ++i;
			else --j;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", books[y], books[z]);
	}
	return 0;
}

