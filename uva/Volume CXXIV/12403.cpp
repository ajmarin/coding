#include <cstdio>

int main(void){
	for(int t; scanf("%d", &t) == 1; ){
		int amount, balance = 0;
		char operation[16];
		while(t--){
			scanf("%s", operation);
			if(*operation == 'r') printf("%d\n", balance);
			else scanf("%d", &amount), balance += amount;
		}
	}
	return 0;
}

