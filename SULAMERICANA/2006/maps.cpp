#include <cstdio>
#include <cstring>
#define NN 5005

char mapas[2][NN];
int t, x, y, tam;
bool finished;

int main(void) {
	int i;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",mapas[0]);
		tam = strlen(mapas[0]);
		
		/* cima */
		strncpy(mapas[1],mapas[0],tam+1);
		finished = false;
		for(i = tam-1; i > 0 && !finished; i--) {
			switch(mapas[0][i]) {
				case 's':
					mapas[1][i] = 'p';
					finished = true;
					break;
				case 'r':
					mapas[1][i] = 'q';
					finished = true;
					break;
				case 'p':
					mapas[1][i] = 's';
					break;
				case 'q':
					mapas[1][i] = 'r';
					break;
			}
		}
		if(finished) printf("%s ",mapas[1]);
		else printf("<none> ");

		/* baixo */

		strncpy(mapas[1],mapas[0],tam+1);
		finished = false;
		for(i = tam-1; i > 0 && !finished; i--) {
			switch(mapas[0][i]) {
				case 'p':
					mapas[1][i] = 's';
					finished = true;
					break;
				case 'q':
					mapas[1][i] = 'r';
					finished = true;
					break;
				case 's':
					mapas[1][i] = 'p';
					break;
				case 'r':
					mapas[1][i] = 'q';
					break;
			}
		}
		if(finished) printf("%s ",mapas[1]);
		else printf("<none> ");

		/* esquerda */

		strncpy(mapas[1],mapas[0],tam+1);
		finished = false;
		for(i = tam-1; i > 0 && !finished; i--) {
			switch(mapas[0][i]) {
				case 'q':
					mapas[1][i] = 'p';
					finished = true;
					break;
				case 'r':
					mapas[1][i] = 's';
					finished = true;
					break;
				case 'p':
					mapas[1][i] = 'q';
					break;
				case 's':
					mapas[1][i] = 'r';
					break;
			}
		}
		if(finished) printf("%s ",mapas[1]);
		else printf("<none> ");

		/* direita */

		strncpy(mapas[1],mapas[0],tam+1);
		finished = false;
		for(i = tam-1; i > 0 && !finished; i--) {
			switch(mapas[0][i]) {
				case 'p':
					mapas[1][i] = 'q';
					finished = true;
					break;
				case 's':
					mapas[1][i] = 'r';
					finished = true;
					break;
				case 'q':
					mapas[1][i] = 'p';
					break;
				case 'r':
					mapas[1][i] = 's';
					break;
			}
		}
		if(finished) printf("%s\n",mapas[1]);
		else printf("<none>\n");
	}
	return 0;
}
