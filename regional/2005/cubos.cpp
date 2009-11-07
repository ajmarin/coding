#include <cstdio>
#include <set>

using namespace std;

#define cubo2int(cub) (cub.a + cub.b*10 + cub.c*100 + cub.d*1000 + cub.e*10000 + cub.f*100000)
struct cubo { int a, b, c, d, e, f; };
set<int> cubos;
int n, tipos;

void rotx(cubo &c) {
	int t = c.a;
	c.a = c.c;
	c.c = c.f;
	c.f = c.e;
	c.e = t;
}

void roty(cubo &c) {
	int t = c.a;
	c.a = c.b;
	c.b = c.f;
	c.f = c.d;
	c.d = t;
}

void rotz(cubo &c) {
	int t = c.b;
	c.b = c.c;
	c.c = c.d;
	c.d = c.e;
	c.e = t;
}

int main(void) {
	int i, x, y, z;

	while(scanf("%d", &n)) {
		if(n == 0) break;
		
		cubos.clear();
		tipos = 0;

		/* input */
		for(i = 0; i < n; i++) {
			bool found = false;
			cubo c;
			scanf("%d %d %d %d %d %d", &c.a, &c.b, &c.c, &c.d, &c.e, &c.f);
			for(x = 0; x < 3; x++) {
				for(y = 0; y < 4; y++) {
					for(z = 0; z < 4; z++) {
						if(cubos.count(cubo2int(c)) == 0) {
							cubos.insert(cubo2int(c));
							found = true;
						}
						rotz(c);
					}
					roty(c);
				}
				rotx(c);
			}

			if(found) tipos++;
		}

		/* output */
		printf("%d\n", tipos);
	}

	return 0;
}
