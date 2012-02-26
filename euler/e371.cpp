#include <cmath>
#include <cstdio>

const int NN = 1024;

double p[NN], p500[NN];

int main(void){
	p500[499] = 2;
	p[499] = (1000 + p500[499]) / 500;
	for(int i = 499; i--; ){
		p500[i] = (1000 + (998 - (i << 1)) * p500[i + 1]) / (999 - i);
		p[i] = (1000 + (998 - (i << 1)) * p[i + 1] + p500[i]) / (999 - i);
	}
	printf("%.8lf\n", p[0]);
	return 0;
}

