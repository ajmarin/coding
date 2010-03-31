#include <cmath>
#include <cstdio>
#include <ctime>

bool used[10];
int best[15], n[10], sol[15];
const int p[10] = { 4, 9, 5, 0, 6, 1, 7, 2, 8, 3 };
const int s[15] = { 0, 5, 6, 1, 6, 7, 2, 7, 8, 3, 8, 9, 4, 9, 5};
int sum, test;
void go(int x){
	if(x == 3) sum = n[4] + n[9] + n[5];
	if(x > 3 && x < 10 && x % 2){
		int pos = (x - 3)/ 3 * 3;
		test = n[s[pos]] + n[s[pos + 1]] + n[s[pos + 2]];
		if(test != sum) return;
	}
	if(x == 10){
		test = n[3] + n[8] + n[9];
		if(test != sum) return;
		int min = 11, pos;
		for(int i = 0; i < 5; ++i) if(n[i] < min) min = n[i], pos = i;
		pos *= 3;
		for(int i = 0; i < 15; ++i) sol[i] = n[s[(i + pos) % 15]];
		int i = 0; while(sol[i] == best[i]) ++i;
		if(sol[i] > best[i]) for(i = 0; i < 15; ++i) best[i] = sol[i];
		//putc(10, stdout);
		return;
	}
	for(int i = 1; i < 10; ++i){
		if(used[i]) continue;
		n[p[x]] = i;
		used[i] = 1;
		go(x + 1);
		used[i] = 0;
	}
}
		
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < 15; ++i) best[i] = 0;
	n[4] = 10;
	go(1);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: ");
	for(int i = 0; i < 15; ++i) printf("%d", best[i]);
	putc(10, stdout);
	return 0;
}
