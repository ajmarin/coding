#include <cmath>
#include <cstdio>
#include <ctime>

const int MAX_SCORE = 99;
int v[32], ways = 0;
int min(int a, int b){ return a < b ? a : b; }
void bt(int s, int dart, int sdt, int thrown){
	/* s = current score
	** dart = number of the lowest dart that can be thrown at same score base
	** sdt = 1 if you can do singles and up, 2 for doubles and up, 3 only treble
	** thrown = number of darts thrown
	*/
	if(s > MAX_SCORE) return; // I dont want scores greater than MAX_SCORE
	ways++;
	if(thrown == 3) return; // I only have three darts
	for(int i = 1; i <= 20; ++i){
		if(sdt == 1){
			if(i >= dart) bt(s + 1*i, i, 1, thrown + 1);
			bt(s + 2*i, i, 2, thrown + 1);
			bt(s + 3*i, i, 3, thrown + 1);
		} else if(sdt == 2){
			if(i >= dart) bt(s + 2*i, i, 1, thrown + 1);
			bt(s + 3*i, i, 3, thrown + 1);
		} else if(i >= dart){
			bt(s + 3*i, i, 3, thrown + 1);
		}
	}
	if(sdt == 1) bt(s + 25, 25, 1, thrown + 1);
	if(sdt <= 2) bt(s + 50, 50, 2, thrown + 1);
}
int main(void){
	clock_t ini = clock();
	/* Guarantee the double throw */
	for(int i = 1; i < 21; ++i)	bt(2 * i, 1, 1, 1);
	bt(50, 1, 1, 1);
	int ans = ways;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
