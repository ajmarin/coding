#include <cmath>
#include <cstdio>
#include <ctime>

int ans = 0, day = 7;
int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool leap(int year){
	return ( ( !(year & 3) && year % 100 ) || !(year % 400) );
}
int main(void){
	clock_t ini = clock();
	for(int y = 1900; y < 2001; ++y)
		for(int m = 0; m < 12; ++m){
			ans += (day == 1 && y > 1900);
			int m_days = d[m] + (m == 1 ? leap(y) : 0);
			while(day <= m_days) day = day + 7;
			day %= m_days;
		}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

