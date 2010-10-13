#include <cstdio>
int n, need;
char ans[32];
void bt(int k, int have){
	if(k == n){
		ans[k] = 0;
		for(char *p = ans; *p; p++) putc(*p, stdout);
		putc(10, stdout);
		return;
	}
	if(have + (n - k) > need) ans[k] = '0', bt(k + 1, have);
	if(have < need) ans[k] = '1', bt(k + 1, have + 1);
}

int main(void){
	int t; scanf("%d", &t);
	for(;t-- && scanf("%d %d", &n, &need);){
		bt(0, 0);
		if(t) putc(10, stdout);
	}
	return 0;
}

