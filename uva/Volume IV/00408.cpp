#include <cstdio>
int STEP, MOD;
const char *good = "Good Choice",
	  		*bad = "Bad Choice";
int f(int k) { return (k + STEP) % MOD; }
int main(void){
	int steps, tortoise, hare;
	while(scanf("%d%d",&STEP,&MOD)!= EOF){
		tortoise = f(0);
		hare = f(f(0));
		for(steps = 1; hare != tortoise; steps++){
			tortoise = f(tortoise);
			hare = f(f(hare));
		}
		printf("%10d%10d    ",STEP,MOD);
		if(steps == MOD) puts(good);
		else puts(bad);
		putc(10,stdout);
	}
	return 0;
}

