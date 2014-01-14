#include <algorithm>
#include <cstdio>
using namespace std;

int cnt[128];
char ing[1024];

int main(void){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 128; ++j) cnt[j] = 0;
		scanf(" %s", ing);
		for(int j = 0; ing[j]; ++j) ++cnt[ing[j]];
		int pizzas = 100;
		pizzas = min(pizzas, cnt['A'] / 3);
		pizzas = min(pizzas, cnt['G']);
		pizzas = min(pizzas, cnt['I']);
		pizzas = min(pizzas, cnt['M']);
		pizzas = min(pizzas, cnt['R'] >> 1);
		pizzas = min(pizzas, cnt['T']);
		printf("%d\n", pizzas);
	}
	return 0;
}

