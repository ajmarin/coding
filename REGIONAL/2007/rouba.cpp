#include <cstdio>

#define CC 10000
#define JJ 20

int num_cartas, num_jogadores;
int descarte[14], topo[JJ], tam[JJ];
int maior_monte;

int main(void) {
	int i, j, jogador, carta_da_vez;

	while(scanf("%d %d", &num_cartas, &num_jogadores)) {
		if(!num_cartas && !num_jogadores) break;

		for(i = 1; i <= 13; i++) descarte[i] = 0;

		for(i = 0; i < num_jogadores; i++) {
			topo[i] = -1;
			tam[i] = 0;
		}

		maior_monte = 0;

		for(i = 0; i < num_cartas; i++) {
			jogador = i % num_jogadores;
			scanf("%d", &carta_da_vez);

			if(descarte[carta_da_vez]) {
				descarte[carta_da_vez] = 0;
				topo[jogador] = carta_da_vez;
				tam[jogador] += 2;
				if(tam[jogador] > maior_monte)
					maior_monte = tam[jogador];
				i--;
				num_cartas--;
			} else {
				int roubou = 0;
				for(j = 0; j < num_jogadores; j++) {
					if(j == jogador) continue;
					if(topo[j] == carta_da_vez) {
						topo[j] = -1;
						tam[jogador] += tam[j] + 1;
						if(tam[jogador] > maior_monte)
							maior_monte = tam[jogador];
						topo[jogador] = carta_da_vez;
						tam[j] = 0;
						roubou = 1;
						break;
					}
				}
				if(roubou) {
					i--;
					num_cartas--;
				} else {
					if(topo[jogador] == carta_da_vez) {
						tam[jogador]++;
						if(tam[jogador] > maior_monte)
							maior_monte = tam[jogador];
						i--;
						num_cartas--;
					} else {
						descarte[carta_da_vez] = 1;
					}
				}
			}
		}

		printf("%d ", maior_monte);

		for(i = 0; i < num_jogadores; i++) {
			if(tam[i] == maior_monte)
				printf("%d ", i+1);
		}

		printf("\n");
	}

	return 0;
}
