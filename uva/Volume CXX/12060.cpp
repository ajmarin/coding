#include <cstdio>

int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }

void reduce(int &num, int &den){
	int g = gcd(num, den);
	num /= g;
	den /= g;
}

int digits(int n){
	int r = 0;
	while(n) ++r, n /= 10;
	return r;
}

int main(void){
	for(int cnum(0), n; scanf("%d", &n) == 1 && n; ){
		int i, sum, z;
		int ip, num, den;

		for(i = sum = 0; i < n; ++i){
			scanf("%d", &z);
			sum += z;
		}

		printf("Case %d:\n", ++cnum);
		bool negative = sum < 0;
		if(negative) sum = -sum;

		ip = sum / n;
		num = sum % n;
		den = n;
		if(num) reduce(num, den);


		if(num){
			int denlen = digits(den);
			int spaces = digits(ip) + (negative << 1);
			for(int i = 0; i < spaces; ++i) putc(32, stdout);
			printf("%*d\n", denlen, num);
			if(negative) printf("- ");
			if(ip) printf("%d", ip);
			for(int i = 0; i < denlen; ++i) putc('-', stdout);
			printf("\n");
			for(int i = 0; i < spaces; ++i) putc(32, stdout);
			printf("%d\n", den);
		} else {
			if(negative) printf("- ");
			printf("%d\n", ip);
		}

	}
	return 0;
}

