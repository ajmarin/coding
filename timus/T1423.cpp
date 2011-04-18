#include <cstdio>
#include <cstring>
/* key, key length, text, text length, partial match table */
int kmp(char *key, int kl, char *text, int tl, int *T){
	for(int i = 0, m = 0; m + i < tl; )
		if(key[i] == text[m + i]){ if(++i == kl) return m; }
		else m += i - T[i], i = T[i] + (T[i] == -1);
	return -1;
}
/* key, key length, partial match table */
void kmp_table(char *key, int kl, int *T){
	T[0] = -1; T[1] = 0;
	for(int cnd = 0, pos = 2; pos < kl; )
		if(key[pos - 1] == key[cnd]) T[pos++] = ++cnd;
		else if(cnd > 0) cnd = T[cnd];
		else T[pos++] = 0;
}
const int N = 1 << 19;
char k[N], t[N];
int f[N];
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		scanf("%s", t);
		for(int i = n; i < (n << 1); ++i) t[i] = t[i - n];
		t[n << 1] = 0;
		scanf("%s", k);
		kmp_table(k, n, f);
		int x = kmp(k, n, t, n<<1, f);
		if(x != -1){
			printf("%d\n", (n - x) % n);
		}
		else {
			puts("-1");
		}
	}
	return 0;
}

