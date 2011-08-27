#include <clocale>
#include <cstdio>
int main(void){
	int T;
	scanf("%d", &T);
	setlocale(LC_ALL, "en_US.UTF-8");
	for(int cnum = 0; cnum++ < T; ){
		double r = 0, z;
		for(int i = 0; i < 12; ++i, r += z) scanf("%lf", &z);
		printf("%d $%'.2lf\n", cnum, r / 12.0);
	}
	return 0;
}

