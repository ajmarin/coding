#include <cstdio>
#include <cstring>

int t, k;
char seq[3000000], *p, *n, *o, next[3000000];

int main(void) {
	scanf("%d", &t);
	while(t--) {
		scanf("%s %d", seq, &k);
		printf("%s\n", seq);
		while(k--) {
			int cnt = 1;
			o = next;
			for(p = seq, n = p+1; *p; p++, n++) {
				if(*p == *n) cnt++;
				else {
					sprintf(o, "%d%c", cnt, *p);
					while(*o) o++;
					cnt = 1;
				}
			}
			strcpy(seq, next);
			printf("%s\n", seq);
		}
		printf("\n");
	}

	return 0;
}
