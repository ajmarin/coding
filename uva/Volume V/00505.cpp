#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

const char *wd[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
const char *month[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
	"JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
const int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

map < string, int > tz;

int md(int month, int year){
	return month_days[month] + (month == 1 && (!(year % 400) || (!(year & 3) && year % 100)));
}

int main(void){
	char c, f[8], mt[8], w[8], year[8];
	int a, b, d, h, m, s, y;
	tz["UT"] = 0; tz["GMT"] = 0; tz["EDT"] = -240;
	tz["CDT"] = -300; tz["MDT"] = -360; tz["PDT"] = -420;
	while(scanf(" %[A-Z], %d %[A-Z] %s %2d:%2d:%2d %s", w, &d, mt, year, &h, &m, &s, f) == 8){
//		printf("%s, %d %s %d %d:%d:%d %s\n", w, d, mt, y, h, m, s, f);
		int diff, mn, t, wn;
		sscanf(year, "%d", &y);
		for(mn = 0; strcmp(month[mn], mt); ++mn);
		for(wn = 0; strcmp(wd[wn], w); ++wn);
		if(!year[2]) y += 1900;
		if(sscanf(f, "%c%2d%2d", &c, &a, &b) == 3){
			if(c == '-') diff = 180 + (60 * a + b);
			else diff = 180 - (60 * a + b);
		} else diff = 180 - tz[f];
		t = 60 * h + m + diff;
		if(t >= 1440){
			t -= 1440;
			wn = (wn + 1) % 7;
			if(++d > md(mn, y)){
				d = 1;
				if(++mn > 11){
					mn = 0;
					++y;
				}
			}
		} else if(t < 0){
			t += 1440;
			wn = (wn + 6) % 7;
			if(--d < 1){
				if(--mn < 0){
					mn = 11;
					--y;
				}
				d = md(mn, y);
			}
		}
		printf("%s, %02d %s %04d %02d:%02d:%02d +0300\n", wd[wn], d, month[mn], y, t / 60, t % 60, s);
	}
	return 0;
}

