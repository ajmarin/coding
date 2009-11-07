#include <cstdio>

int abs(int x) { return x < 0 ? -x : x; }

int main(void) {
	int ax, ay, bx, by;

	while(scanf("%d %d %d %d", &ax, &ay, &bx, &by)) {
		if(ax == 0 && ay == 0 && bx == 0 && by == 0)
			break;

		if(ax == bx) {
			if(ay == by) printf("0\n");
			else printf("1\n");
		} else {
			if(ay == by) printf("1\n");
			else {
				if(abs(ax - bx) == abs(ay - by)) printf("1\n");
				else printf("2\n");
			}
		}
	}

	return 0;
}
