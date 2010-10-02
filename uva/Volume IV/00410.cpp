#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
int s[10];
double am, imb;
int main(void){
	int C, C2, S, set = 0;
	while(scanf("%d %d", &C, &S) == 2){
		am = imb = 0;
		C2 = C << 1;
		for(int i = 0; i < (C2); ++i){
			if(i < S){
				scanf("%d", &s[i]);
				am += s[i];
			} else s[i] = 0;
		}
		am = am / C;
		sort(s, s + C2);
		printf("Set #%d\n", ++set);
		for(int i = 0; i < C; ++i){
			printf("%2d:", i);
			if(s[i]) printf(" %d", s[i]);
			imb += fabs(s[i] + s[C2 - i - 1] - am);
			if(s[C2 - i - 1]) printf(" %d", s[C2 - i - 1]);
			putc(10, stdout);
		}
		printf("IMBALANCE = %.5lf\n\n", imb);
	}
	return 0;
}

