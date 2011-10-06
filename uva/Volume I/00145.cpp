#include <cstdio>

double c[][3] = {
	{0.10, 0.06, 0.02},
	{0.25, 0.15, 0.05},
	{0.53, 0.33, 0.13},
	{0.87, 0.47, 0.17},
	{1.44, 0.80, 0.30}
};
				
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }

int match(int b1, int e1, int b2, int e2){
	if(b2 >= b1 && b2 <= e1) return min(e1, e2) - b2;
	if(e2 >= b1 && e2 <= e1) return e2 - max(b1, b2);
	if(b2 <= b1 && e2 >= b1) return e1 - b1;
	return 0;
}

int main(void){
	char type[8], phone[16];
	int hb, mb, he, me;
	while(scanf("%s %s %d %d %d %d", type, phone, &hb, &mb, &he, &me) == 6){
		int b = 60 * hb + mb, e = 60 * he + me, t = *type - 'A';
		int m[3] = {0, 0, 0};
		if(e > b){
			m[0] = match(480, 1080, b, e);						
			m[1] = match(1080, 1320, b, e);
			m[2] = e - b - m[0] - m[1];
		} else {
			m[0] = match(480, 1080, b, 1440) + match(480, 1080, 0, e);
			m[1] = match(1080, 1320, b, 1440) + match(1080, 1320, 0, e);
			m[2] = 1440 - (b - e) - m[0] - m[1];
		}
		double cost = c[t][0] * m[0] + c[t][1] * m[1] + c[t][2] * m[2];
		printf("%10s%6d%6d%6d%3s%8.2lf\n", phone, m[0], m[1], m[2], type, cost);
	}
	return 0;
}

