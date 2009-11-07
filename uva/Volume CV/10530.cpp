/////////////////////////////////
// 10530 - Guessing Game
/////////////////////////////////
#include<cstdio>
char n, sol;
const char *honest = "Stan may be honest";
const char *dishonest = "Stan is dishonest";
bool lying;
void guess(int k){
	char ans[9];
	gets(ans);
	if(ans[0] == 'r'){ sol = k;return;}
	else {
		scanf("%d\n",&n);
		guess(n);
		if(ans[4] == 'h'){
			if(sol >= k) lying = 1;
		}else if(sol <= k) lying = 1;
	}
}
int main(void){
	while(scanf("%d\n",&n) && n){
		lying = 0;
		guess(n);
		if(lying) puts(dishonest);
		else puts(honest);
	}
	return 0;
}
