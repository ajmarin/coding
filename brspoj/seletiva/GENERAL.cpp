#include <cstdio>

#define NN 100000

int t;
int n, k;
int **b, bs[NN]; /* bucket, bucketsize, aux */
unsigned long long c, total;
bool ok;

void mergesort(int a[], int n) {
	int i, j, k, s[NN], f = n/2;
	if(n <= 1) return;

	/* ordena metades */
	mergesort(a, f);
	mergesort(a+f, n-f);

	/* merge */
	for(i = 0, j = f, k = 0; i < f && j < n;)
		if(a[i] <= a[j]) s[k++] = a[i++];
		else s[k++] = a[j++], c += f-i;
	while(i < f) s[k++] = a[i++];
	while(j < n) s[k++] = a[j++];
	for(i = 0; i < n; i++) a[i] = s[i];
}

int main(void) {
	int i;

	scanf("%d", &t);

	while(t--) {
		scanf("%d %d", &n, &k);

		/* init */
		b = new int*[k];
		for(i = 0; i < k; i++) {
			bs[i] = 0;
			b[i] = new int[n/k + 1];
		}
		
		/* input */
		for(i = 0; i < n; i++) scanf("%d", &b[i%k][bs[i%k]++]);

		/* processa */
		total = 0;
		for(i = 0; i < k; i++) {
			c = 0;
			mergesort(b[i], bs[i]);
			total += c;
		}
		ok = true;
		for(i = 1; i < n && ok; i++) if(b[i%k][i/k] < b[(i-1)%k][(i-1)/k]) ok = false;

		/* output */
		if(!ok) printf("impossivel\n");
		else printf("%Ld\n", total);

		/* free */
		for(i = 0; i < k; i++) delete b[i];
		delete b;
	}

	return 0;
}
