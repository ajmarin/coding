#include <cstdio>
typedef unsigned int UI;
int max(int a, int b){ return a > b ? a : b; }

int main(void){
	int t; scanf("%d", &t);
	for(UI c = 0, n, tax = 0; t-- && scanf("%d", &n) == 1; tax = 0){
		if(n > 1180000) tax = 150000 + (n - 1179997) / 4;
		else if(n > 880000) tax = 90000 + (n - 879996) / 5;
		else if(n > 480000) tax = 30000 + (3*n - 1439981) / 20;
		else if(n > 180000) tax = (n - 179991) / 10;
		if(tax) tax = max(2000, tax);
		printf("Case %d: %d\n", ++c, tax);
	}
	return 0;
}

