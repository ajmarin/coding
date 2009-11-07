#include <cstdio>

int main(void){
	int N, T;
	char t[5];
	float q;
	scanf("%d", &T);
	for(int cnum = 0; cnum < T; ){
		printf("%d ", ++cnum);
		scanf("%f %s", &q, t);
		switch(t[0]){
			case 'k': printf("%.4f lb\n", q * 2.2046); break;
			case 'g': printf("%.4f l\n", q * 3.7854); break;
			case 'l':
				if(t[1] == 'b') printf("%.4f kg\n", q * 0.4536);
				else printf("%.4f g\n", q * 0.2642);
				break;
		}
	}
	return  0;
}

