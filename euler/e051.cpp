#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

#define MAX 1000000
#define SQMAX 1000
int ans = 0, c = 0, pl[100000];
bool p[MAX];
void test(int k){
	char dc[11] = "0000000000", num[7], test[7], digits = 0;
	int x = k;
	while(k) dc[k % 10]++, num[digits++] = k % 10 + '0', k /= 10;
	num[digits] = 0;
	reverse(num, num + digits);
	for(int i = 0; i < 10; ++i)
		if(dc[i] > '2'){
			int pp = 10;
			for(int j = 0; j < 10; ++j){
				if(!j && num[0] - '0' == i) { --pp; continue; }
				strcpy(test, num);
				for(int k = 0; num[k]; ++k)
					if(num[k] == i + '0') test[k] = j + '0';
				if(!p[atoi(test)] && --pp < 8) break;
			}
			if(pp == 8) ans = x;
		}
}
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < MAX; ++i) p[i] = 1;
	p[0] = p[1] = 0; pl[0] = 2;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < SQMAX; i += 2)
		if(p[i]){
			pl[c++] = i;
			for(int j = i * i; j < MAX; j += i) p[j] = 0;
		}
	for(int i = SQMAX + !(SQMAX & 1); i < MAX; i += 2)
		if(p[i]) pl[c++] = i;
	for(int i = 0; !ans; ++i) test(i);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

