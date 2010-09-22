#include <cstdio>

int p[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int b[101];
int palitos(int x){
	int r = 0;
	while(x){
		r += p[x % 10];
		x /= 10;
	}
	return r;
}

char minans[512];
int main(void){
	for(int i = 1; i < 101; ++i) b[i] = 999999999;
	for(int i = 1; i < 1000; ++i){
		int cp = palitos(i);
		if(b[cp] > i) b[cp] = i;
	}
//	for(int i = 0; i < 100; ++i) printf("Best number with %d palitos = %d\n", i, b[i]);

	int imin, n, s, t;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &s);
		t = s;
		imin = 0;
		/* min */
		while(b[s] == 999999999) minans[imin++] = '8', s -= 7;
		printf("%d", b[s]);
		while(imin--) putc(minans[imin], stdout);
		putc(32, stdout);
		if(t & 1) putc('7', stdout), t -= 3;
		while(t) putc('1', stdout), t -= 2;
		putc(10, stdout);
	}
	return 0;
}


