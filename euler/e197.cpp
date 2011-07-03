#include <cmath>
#include <cstdio>
#include <ctime>

const double num = pow(2, 30.403243784);
const int LAST = 1001;
double u[LAST+1];

double f(double n){
	return floor(num / pow(2, n*n)) * 0.000000001;
}

int main(void){
	clock_t begin = clock();
	u[0] = -1;
	int at;
	for(at = 1; at <= LAST ; ++at){
		u[at] = f(u[at - 1]);
		if(at > 1 && fabs(u[at] - u[at - 2]) < 10e-10) break;
	}
	printf("Answer: %.9lf\n", u[at] + u[at - 1]);
	printf("Time spent: %.3lfs\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
	return 0;
}

