#include <cstdio>

int md[16] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1, -1, -1};
int ml(int month, int year){
	return md[month] + (month == 2 && year % 400 != 0 && year % 4 == 0);
}
int main(void){
	int t; scanf("%d", &t);
	for(int cn = 0, d, m, y; scanf("%2d%2d%4d", &m, &d, &y) == 3; ){
		int days_left = 280;
		while(days_left--){
			++d;
			if(d > ml(m, y)) d = 1, ++m;
			if(m > 12) m = 1, ++y;
		}
		printf("%d %02d/%02d/%04d ", ++cn, m, d, y);
		if((m == 1 && d >= 21) || (m == 2 && d <= 19)) puts("aquarius");
		else if((m == 2 && d >= 20) || (m == 3 && d <= 20)) puts("pisces");
		else if((m == 3 && d >= 21) || (m == 4 && d <= 20)) puts("aries");
		else if((m == 4 && d >= 21) || (m == 5 && d <= 21)) puts("taurus");
		else if((m == 5 && d >= 22) || (m == 6 && d <= 21)) puts("gemini");
		else if((m == 6 && d >= 22) || (m == 7 && d <= 22)) puts("cancer");
		else if((m == 7 && d >= 23) || (m == 8 && d <= 21)) puts("leo");
		else if((m == 8 && d >= 22) || (m == 9 && d <= 23)) puts("virgo");
		else if((m == 9 && d >= 24) || (m == 10 && d <= 23)) puts("libra");
		else if((m == 10 && d >= 24) || (m == 11 && d <= 22)) puts("scorpio");
		else if((m == 11 && d >= 23) || (m == 12 && d <= 22)) puts("sagittarius");
		else if((m == 12 && d >= 23) || (m == 1 && d <= 20)) puts("capricorn");
	}

	return 0;
}

