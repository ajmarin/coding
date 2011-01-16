#include <cstdio>
#include <cmath>
#include <algorithm>
struct Team {
	int AC,CTIME,TRIES,PTIME;
	bool operator<(const Team t) const {
		return (AC == t.AC ? PTIME < t.PTIME : AC > t.AC);
	}
} t[128];
int main(void){
	char time[50];
	int i, j, P, T, trie, tries;
	float lim, min, max;
	bool showtime = 0;
	while(scanf("%d%d",&T,&P) && T){
		for(i = 0; i < T; i++){
			t[i].AC = t[i].TRIES = t[i].CTIME = 0;
			for(j = 0; j < P; j++){
				scanf("%d/%s",&tries,time);
				if(time[0] != '-'){
					int tac = atoi(time);
					t[i].AC++;
					t[i].TRIES += tries;
					t[i].CTIME += tac;
				}
			}
			t[i].TRIES -= t[i].AC;
			t[i].PTIME = t[i].CTIME + 20 * t[i].TRIES;

		}
		std::sort(t,t+T);
		int LOW, HIGH, TI, TJ, CI, CJ;
		min = 0; max = 1<<30;

		for(i = 0; i < T; i++)
			for(j = i+1; j < T; j++){
				if(t[i].AC != t[j].AC) break;

				TI = t[i].TRIES;
				CI = t[i].CTIME;
				TJ = t[j].TRIES;
				CJ = t[j].CTIME;

				if(TI > TJ){
					lim = (CJ - CI)/float(TI - TJ);
					if(max > lim) max = lim;
				} else if(TI < TJ && CI > CJ){
					lim = (CI - CJ)/float(TJ - TI);
					if(min < lim) min = lim;
				}
			}

		LOW = floor(min)+1;
		if(LOW>20) printf("20 20\n");
		else{
			if(max < (1<<30)){
				if(max == floor(max)) HIGH = int(max) - 1;
				else HIGH = int(max);
				if(HIGH > 19) printf("%d %d\n", LOW, HIGH);
				else printf("20 20\n");

			} else printf("%d *\n",LOW);
		}

		
	}
	return 0;
}

