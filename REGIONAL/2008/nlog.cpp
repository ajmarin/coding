#include <cstdio>

int num_queries;
int cx, cy;

int main(void) {
	int i;

	while(scanf("%d", &num_queries)) {
		if(num_queries == 0)
			break;

		scanf("%d %d", &cx, &cy);

		for(i = 0; i < num_queries; i++) {
			int x, y;

			scanf("%d %d", &x, &y);

			if(x == cx || y == cy)
				printf("divisa\n");
			else {
				char a, b;

				if(y > cy) a = 'N';
				else a = 'S';

				if(x > cx) b = 'E';
				else b = 'O';

				printf("%c%c\n", a, b);
			}
		}
	}

	return 0;
}
