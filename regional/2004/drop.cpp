#include <cstdio>
#define min(a,b) (a<b) ? a : b

struct string {
	char nome[30];
}names[25];

int nactive, cards[52], atual, temp[4], n, num, aux;
bool active[25], finished;

int main (void) {
	while(scanf("%d",&n)) {
		if(!n)
			break;
		for(int i = 0; i < n; i++) {
			scanf("%s", &names[i]);
			active[i] = true;
		}
		nactive = n;
		finished = false;
		for(int i = 0; i < 52; i++)
			scanf("%d",&cards[i]);
		atual = 0;
		while(!finished) {
			if(atual + nactive > 51) {
				finished = true;
				continue;
			}
			num = 14;
			for(int i = atual; i< atual+nactive; i++)
				num = min(num, cards[i]);
			for(int i = 0; i < 4; i++)
				temp[i] = -1;
			aux = 0;
			for(int i = atual; i < atual + nactive; i++) {
				if(cards[i] ==  num) {
					temp[aux] = i - atual;
					aux++;
				}
			}
			if(aux >= nactive) {
				finished = true;
				continue;
			}
			for(int i = 0; i < aux; i++) {
				for(int j = 0; j < n;  j++) {
					if(active[j])
						temp[i]--;
					if(temp[i] < 0) {
						active[j] = false;
						nactive--;
						for(int k = i+1; k < 4; k++)
							temp[k]--;
						break;
					}
				}
			}
			atual += nactive + aux;
			if(nactive == 1)
				finished = true;
		}
		for(int i = 0; i < n; i ++) {
			if(active[i]) {
				printf("%s ", names[i].nome);
			}
		}
		printf("\n");
	}
	return 0;
}
