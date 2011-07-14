#include <cstdio>

const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *wd[7] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday",
	"Wednesday", "Thursday"};
int cd[12];
int main(void){
	int t; scanf("%d", &t);
	cd[0] = days[0];
	for(int i = 1; i < 12; ++i) cd[i] = days[i] + cd[i - 1];
	for(int d, m; t-- && scanf("%d %d", &m, &d); ){
		int nday = d;
		if(--m) nday += cd[m - 1];
		//printf("%d %d -> %d\n", m, d, nday);
		puts(wd[nday % 7]);
	}
	return 0;
}

