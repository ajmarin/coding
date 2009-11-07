#include <cstdio>
#include <cstdlib>

#define NN 2048

struct box {
	int a, b, c;

	box() { a = b = c = 0; }

	box(int x, int y, int z) {
		int t;
		a = x; b = y; c = z;
		if(c > a) {
			t = a;
			a = c;
			c = t;
		}
		if(b > a) {
			t = a;
			a = b;
			b = t;
		}
		if(c > b) {
			t = b;
			b = c;
			c = t;
		}
	}

	int calcVolume() {
		return a*b*c;
	}

	bool cabeEm(box caixa) {
		return (a <= caixa.a && b <= caixa.b && c <= caixa.c);
	}

	bool operator==(box &caixa) {
		return (caixa.a == a && caixa.b == b && caixa.c == c);
	}
};

int boxcmp(const void *a, const void *b) {
	int va = ((box*)a)->calcVolume();
	int vb = ((box*)b)->calcVolume();
	if(va > vb) return 1;
	else if(vb > va) return -1;
	return 0;
}

int n, m;
box stock[NN];
box gift;

int main(void) {
	int i, j, k;
	int x, y, z;

	while(scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0) break;

		/* input */
		scanf("%d %d %d", &x, &y, &z);
		gift = box(x, y, z);
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &z);
			stock[i] = box(x, y, z);
		}

		/* ordena stock */
		qsort(stock, m, sizeof(box), boxcmp);

		/* percorre stock */
		bool found = false;
		for(i = 0; i < m; i++) {
			if(gift.cabeEm(stock[i])) {
				/* verifica se tem n caixas do tipo stock[i] */
				int cnt = 0;
				for(j = i; j < m; j++)
					if(stock[i] == stock[j])
						cnt++;
				if(cnt >= n) {
					found = true;
					break;
				}
			}
		}

		/* output */
		if(found) printf("%d\n", stock[i].calcVolume() - gift.calcVolume());
		else printf("impossible\n");
	}

	return 0;
}
