#include <cstdio>

int n, ulist[100000], uls = 0;
bool usable[100000];
bool test(int x){
	bool v[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(int k = 0; k < 5; ++k){
		if(v[x % 10]++) return 0;
		x /= 10;
	}
	return 1;
}
void testn(int x, int &mask){
	int r;
	for(int k = 0; k < 5; ++k){
		r = 1 << (x % 10);
		if(r & mask){ mask = -1; return; }
		mask |= r;
		x = x / 10;
	}
}
int main(void){
	for(int i = 1234; i < 100000; ++i){
		usable[i] = test(i);
		if(usable[i]) ulist[uls++] = i;
	}
	for(scanf("%d", &n); n; ){
		int f = 0, mask, x;
		for(int i = 0; i < uls; ++i){
			mask = 0;
			if(ulist[i] % n) continue;
			x = ulist[i] / n;
			if(usable[x]){
				testn(ulist[i], mask);
				testn(x, mask);
				if(mask == -1) continue;
				f++;
				printf("%05d / %05d = %d\n", ulist[i], x, n);
			}
		}
		if(!f) printf("There are no solutions for %d.\n", n);
		if(scanf("%d", &n) && n) putc(10, stdout);
	}
	return 0;
}

