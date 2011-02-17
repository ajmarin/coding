#include <cstdio>
int main(void){
	char unit[8];
	float v;
	int t; scanf("%d", &t);
	for(int c = 0; c++ < t; ){
		scanf("%f %s", &v, unit);
		if(*unit == 'k') printf("%d %.4lf lb\n", c, v * 2.2046);
		else if(*unit == 'g') printf("%d %.4lf l\n", c, v * 3.7854); 
		else if(*(unit+1) == 'b') printf("%d %.4lf kg\n", c, v * 0.4536);
		else printf("%d %.4lf g\n", c, v * 0.2642);
	}
	return 0;
}

