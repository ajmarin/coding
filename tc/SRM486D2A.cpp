#include <cstdio>

typedef int ret;
int holes[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
class DigitHoles {
	public:
		ret numHoles(int);
};
ret DigitHoles::numHoles(int n){
	ret r = 0;
	while(n){
		r += holes[n % 10];
		n /= 10;
	}
	return r;
}

