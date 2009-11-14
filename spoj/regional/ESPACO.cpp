#include <cstdio>
#include <climits>
#include <string>
#include <list>
 
#define foreach(i, c) for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
 
using namespace std;
 
struct arquivo {
	string nome;
	int inicio;
	int fim;
};
 
list<arquivo> disco;
int tamanho_disco, num_comandos;
bool erro;
int p[8];
 
/* Funções auxiliares {{{ */
list<arquivo>::iterator disco_aloca(int tamanho) {
	list<arquivo>::iterator ans = (list<arquivo>::iterator) NULL;
	int size = INT_MAX;
	 
	if(disco.empty() && tamanho_disco < tamanho) return ans;
	else if(disco.empty()) return disco.begin();
	 
	if(disco.begin()->inicio >= tamanho) {
		size = disco.begin()->inicio;
		ans = --disco.begin();
	}
	 
	foreach(arq, disco) {
		list<arquivo>::iterator proximo = arq; proximo++;
		if(proximo == disco.end()) {
			if(tamanho_disco - arq->fim >= tamanho && tamanho_disco - arq->fim < size) {
				size = tamanho_disco - arq->fim;
				ans = arq;
			}
		} else {
			if(proximo->inicio - arq->fim >= tamanho && proximo->inicio - arq->fim < size) {
				size = proximo->inicio - arq->fim;
				ans = arq;
			}
		}
	}
	 
	return ans;
}
 
list<arquivo>::iterator disco_encontra(string nome) {
	foreach(arq, disco) if(arq->nome == nome) return arq;
	return (list<arquivo>::iterator) NULL;
}
 
int tam_mult(char c) {
	if(c == 'M') return 1024;
	if(c == 'G') return 1024*1024;
	return 1;
}
/* }}} */
 
/* Funções de acesso ao disco {{{ */
void disco_otimiza() {
	if(disco.empty()) return;
	 
	int delta = -disco.begin()->inicio;
	disco.begin()->inicio += delta;
	disco.begin()->fim += delta;
	 
	foreach(arq, disco) {
		list<arquivo>::iterator proximo = arq; proximo++;
		if(proximo == disco.end()) break;
		 
		delta = arq->fim - proximo->inicio;
		proximo->inicio += delta;
		proximo->fim += delta;
	}
}
 
bool disco_remove(string nome) {
	list<arquivo>::iterator it = disco_encontra(nome);
	if(it == (list<arquivo>::iterator) NULL) return false;
	disco.erase(it);
	return true;
}
 
bool disco_insere(string nome, int tamanho) {
	list<arquivo>::iterator livre = disco_aloca(tamanho);
	// if(livre == (list<arquivo>::iterator) NULL) return false;
	 
	/* gambs */
	if(livre == (list<arquivo>::iterator) NULL) {
		disco_otimiza();
		livre = disco_aloca(tamanho);
		if(livre == (list<arquivo>::iterator) NULL) return false;
	}
	 
	arquivo arq;
	arq.nome = nome;
	arq.inicio = livre->fim;
	arq.fim = arq.inicio + tamanho;
	disco.insert(++livre, arq);
	 
	return true;
}
/* }}} */
 
#ifdef DEBUG
void imprime_disco() {
	foreach(arq, disco)
		printf("%s: %d-%d\n", arq->nome.c_str(), arq->inicio, arq->fim);
	printf("\n");
}
#endif
 
int main(void) {
	char comando[16], nome[16];
	char mult;
	int i;
	 
	while(scanf("%d", &num_comandos)) {
		if(num_comandos == 0) break;
		 
		/* init */
		disco.clear();
		erro = false;
		 
		/* input */
		scanf("%d%cb", &tamanho_disco, &mult);
		tamanho_disco *= tam_mult(mult);
		for(i = 0; i < num_comandos; i++) {
			scanf("%s", comando);
			 
			if(comando[0] == 'i') {
				/* insere */
				int tamanho;
				scanf("%s %d%cb", nome, &tamanho, &mult);
				if(erro) continue;
#ifdef DEBUG
				printf("executando insere %s %d%c\n", nome, tamanho, mult);
#endif
				tamanho *= tam_mult(mult);
				erro = !disco_insere(string(nome), tamanho);
			} else if(comando[0] == 'r') {
				/* remove */
				scanf("%s", nome);
				if(erro) continue;
#ifdef DEBUG
				printf("executando remove %s\n", nome);
#endif
				disco_remove(string(nome));
			} else if(comando[0] == 'o') {
				/* otimiza */
				if(erro) continue;
#ifdef DEBUG
				printf("executando otimiza\n");
#endif
				disco_otimiza();
			}
			 
#ifdef DEBUG
			imprime_disco();
#endif
		}
		 
		/* determina p[] */
		int block_size = tamanho_disco/8;
		for(i = 0; i < 8; i++) p[i] = block_size;
		foreach(arq, disco) {
			int low = arq->inicio/block_size;
			int hi = arq->fim/block_size;
			 
			if(low == hi) {
				p[low] -= (arq->fim - arq->inicio);
			} else {
				p[low] -= ((low+1)*block_size - arq->inicio);
				for(i = low+1; i < hi; i++) p[i] = 0;
				p[hi] -= (arq->fim - hi*block_size);
			}
		}
		 
		/* output */
		int vazio = block_size;
		int medio = 3*block_size;
		if(erro) printf("ERRO: disco cheio\n");
		else {
#ifdef DEBUG
			printf("%d %d %d\n", vazio, medio, block_size);
#endif
			for(i = 0; i < 8; i++) {
				p[i] *= 4;
#ifdef DEBUG
				printf("%d: %d\n", i, p[i]);
#endif
				if(p[i] <= vazio) printf("[#]");
				else if(p[i] > vazio && p[i] <= medio) printf("[-]");
				else printf("[ ]");
			}
			printf("\n");
		}
	}
	 
	return 0;
}

