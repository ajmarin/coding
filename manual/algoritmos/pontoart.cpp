int nos, nArvore;				/* inicializar nArvore = 0 */
int grafo[MAX_NOS][MAX_NOS];
int tras[MAX_NOS];
int arvore[MAX_NOS];			/* iniciar em -1 */
int raiz, arcosArvoreRaiz;

void pontoArt(int no) {
	nArvore++;
	arvore[no] = nArvore;
	tras[no] = arvore[no];

	for(int i = 0; i < nos; i++) {
		if(grafo[no][i] && i != no) {
			if(arvore[i] == -1) {
				if(no == raiz)
					arcosArvoreRaiz++;
				pontoArt(i);
				if(tras[i] >= arvore[no] && ((no == raiz && arcosArvoreRaiz > 1) || no != raiz)) {
					/* 'no' eh um ponto de articulacao */
					printf("%d ", no);
				} else {
					tras[no] = min(tras[no], tras[i]);
				}
			} else {
				tras[no] = min(tras[no], arvore[i]);
			}
		}
	}
}

void all_pontoarts() {
	int v;

	nArvore = 0;

	for(v = 0; v < nos; v++)
		arvore[v] = -1;

	for(v = 0; v < nos; v++) {
		if(arvore[v] == -1) {
			arcosArvoreRaiz = 0;
			raiz = v;
			pontoArt(v);
		}
	}
}

