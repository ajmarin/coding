#include <cstdio>

#define ABS(a)	 ((a)< 0?-(a):(a))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int main(void){
	int H, M, N;
	scanf("%d\n",&N);
	while(N--){
		char a, b, c, d;
		scanf("%c%c:%c%c\n",&a,&b,&c,&d);
		a -= '0'; b -= '0'; c -= '0'; d -= '0';
		H = 10 * a + b;
		M = 10 * c + d;
		int RM = (60 - M)%60;
		int RH = 12 - H - (RM%30 != 0) - (M == 30);
		if(RH <= 0) RH += 12;
		printf("%02d:%02d\n",RH,RM);
	}
	return 0;
}

