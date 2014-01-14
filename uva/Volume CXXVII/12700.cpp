#include <cstdio>

int main(void){
	char match_details[32];
	int t; scanf("%d", &t);
	for(int c = 0, n; c < t && scanf("%d", &n) == 1; ){
		scanf("%s", match_details);
		int a, b, w, ties;
		for(int i = b = w = ties = 0; match_details[i]; ++i){
			b += match_details[i] == 'B';
			w += match_details[i] == 'W';
			ties += match_details[i] == 'T';
		}
		a = n - (b + w + ties);
		printf("Case %d: ", ++c);
		if(a == n) puts("ABANDONED");
		else if(w == n - a) puts("WHITEWASH");
		else if(b == n - a) puts("BANGLAWASH");
		else if(b == w) printf("DRAW %d %d\n", b, ties);
		else if(b > w) printf("BANGLADESH %d - %d\n", b, w);
		else printf("WWW %d - %d\n", w, b);
	}
	return 0;
}

