#include <cstdio>
#define FOR(i,e)		for(int i = 0; i < e; ++i)
#define FORD(i,s,e)		for(int i = s; i > e; --i)
#define FOREACH(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define FORI(i,s,e)		for(int i = s; i < e; ++i)
#define IN(x)			(x = getc(stdin))
#define OUT(x)			putc(x, stdout)
template <class _T> _T MAX(_T a, _T b){ return a > b ? a : b; }
template <class _T> _T MIN(_T a, _T b){ return a < b ? a : b; }

int low[32], high[32];
int main(void){
	int d, max_hours = 0, min_hours = 0, time_studied;
	scanf("%d %d", &d, &time_studied);
	FOR(i, d){
		scanf("%d %d", &low[i], &high[i]);
		min_hours += low[i];
		max_hours += high[i];
	}
	if(time_studied >= min_hours && time_studied <= max_hours){
		int slack_use = time_studied - min_hours;
		puts("YES");
		FOR(i, d){
			int extra = MIN(high[i] - low[i], slack_use);
			slack_use -= extra;
			printf("%d%c", low[i] + extra, i == d - 1 ? '\n' : ' ');
		}
	} else puts("NO");
	return 0;
}

