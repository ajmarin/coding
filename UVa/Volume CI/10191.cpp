#include <algorithm>
#include <cstdio>

#define IN getc( stdin )
struct task {
	int hs, ms, he, me;
	bool operator<(const task k)const {
		return (hs < k.hs || (hs == k.hs && ms < k.ms));
	}
} t[128];

char ign[2048];

int main(void){
	int dnum = 0, N;
	t[0].he = 10; t[0].hs = t[0].me = t[0].ms = 0;
	while(scanf("%d",&N) == 1){
		for(int i = 1; i <= N; ++i){
			scanf("%2d:%2d %2d:%2d",&t[i].hs,&t[i].ms,&t[i].he,&t[i].me,ign);
			while(IN != '\n');
		}
		std::sort(t + 1, t + 1 + N);
		int idx, lnap, x = N + 1, y;
		t[x].hs = 18; t[x].ms = 0;
		lnap = 0; idx = 0;
		for(int k = 0; k < x; ++k){
			y = 60 * (t[k+1].hs - t[k].he) + t[k+1].ms - t[k].me;
			if(y > lnap){
				lnap = y;
				idx = k;
			}
		}
		int h = lnap / 60, m = lnap % 60;
		printf("Day #%d: the longest nap starts at %d:%02d and will last for",
				++dnum, t[idx].he, t[idx].me);
		if(h) printf(" %d hours and",h);
		printf(" %d minutes.\n",m);
	}
	return 0;
}

