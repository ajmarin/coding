#include <cstdio>

int main(void){
	int s, t;
	for(scanf("%d", &t); t-- && scanf("%*d %d", &s); )
		puts(1-s ? "Airborne wins." : "Pagfloyd wins.");
	return 0;
}

