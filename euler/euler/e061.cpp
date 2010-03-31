#include <cstdio>
#include <ctime>

int cnt[6], n[6][100], s[6], w[6];
bool over = 0, used[6];
void go(int c){
	if(c == 5 && ((s[5] % 100) == (s[0] / 100))){
		over = 1;
		return;
	}
	int end = s[c] % 100;
	for(int i = 0; i < 5; ++i){
		if(used[i]) continue;
		for(int j = 0; j < cnt[i]; ++j){
			int k = n[i][j];
			if(k/100 == end){
				used[i] = 1;
				s[c + 1] = k;
				w[c + 1] = i;
				go(c + 1);
				if(over) return;
				s[c + 1] = 0;
				w[c + 1] = 0;
				used[i] = 0;
			}
		}
	}
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 0; i < 6; ++i) cnt[i] = used[i] = 0;
	/* Generates four digit triangular 	numbers */
	for(int i = 45; i < 141; ++i) n[0][cnt[0]++] = (i * i + i) >> 1;
	printf("Triangle:\t%d\t%d\t%d\n", cnt[0], n[0][0], n[0][cnt[0] - 1]);
	/* Generates four digit square 		numbers */
	for(int i = 32; i < 100; ++i) n[1][cnt[1]++] = i * i;
	printf("Square:\t\t%d\t%d\t%d\n", cnt[1], n[1][0], n[1][cnt[1] - 1]);
	/* Generates four digit pentagonal 	numbers */
	for(int i = 26; i < 82; ++i) n[2][cnt[2]++] = (3 * i * i - i) >> 1;
	printf("Pentagonal:\t%d\t%d\t%d\n", cnt[2], n[2][0], n[2][cnt[2] - 1]);
	/* Generates four digit hexagonal  	numbers */
	for(int i = 23; i < 71; ++i) n[3][cnt[3]++] = (2 * i * i - i);
	printf("Hexagonal:\t%d\t%d\t%d\n", cnt[3], n[3][0], n[3][cnt[3] - 1]);
	/* Generates four digit heptagonal 	numbers */
	for(int i = 21; i < 64; ++i) n[4][cnt[4]++] = (5 * i * i - 3 * i) >> 1;
	printf("Heptagonal:\t%d\t%d\t%d\n", cnt[4], n[4][0], n[4][cnt[4] - 1]);
	/* Generates four digit octagonal  	numbers */
	for(int i = 19; i < 59; ++i) n[5][cnt[5]++] = (3 * i * i - 2 * i);
	printf("Octagonal:\t%d\t%d\t%d\n", cnt[5], n[5][0], n[5][cnt[5] - 1]);
	for(int i = 0; !over && i < cnt[5]; ++i) w[0] = 5, s[0] = n[5][i], go(0);
	if(over) {
		for(int i = 0; i < 6; ++i){
			if(i) printf(" + ");
			printf("%d (%d)", s[i], w[i] + 3);
			ans += s[i];
		}
		printf(" = %d\n", ans);
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
