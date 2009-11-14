#include <cstdio>

struct CUBE {
	int a, b, f, l, r, sum, u;
	void rotate(char axis){
		char aux;
		switch(axis){
			case 'x': aux = b;
				b = r; r = f;
				f = l; l = aux;
				break;
			case 'y': aux = a;
				a = r; r = u;
				u = l; l = aux;
				break;
			case 'z': aux = a;
				a = f; f = u;
				u = b; b = aux;
				break;
		}
	}
	bool operator==(CUBE x) const {
		return (a == x.a && b == x.b && f == x.f &&
				l == x.l && r == x.r && u == x.u );
	}

} c[1000];

int main(void){
	int n;
	while(scanf("%d\n", &n) && n){
		int diff = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d %d %d %d %d", &c[i].a, &c[i].b, &c[i].l,
					&c[i].f, &c[i].r, &c[i].u);
			c[i].sum = c[i].a + c[i].b + c[i].f + c[i].l + c[i].r + c[i].u;
			bool u = 1;
			for(int j = 0; u && j < i; ++j){
				if(c[i].sum != c[j].sum) continue;
				for(char x = 0; u && x < 4; ++x){ 
					c[j].rotate('x');
					for(char y = 0; u && y < 4; ++y){
						c[j].rotate('y');
						for(char z = 0; u && z < 4; ++z){
							c[j].rotate('z');
							u ^= c[i] == c[j];
						}
					}
				}
			}
			diff += u;
		}
		printf("%d\n", diff);
	}
	return 0;
}

