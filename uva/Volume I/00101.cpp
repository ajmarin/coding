/////////////////////////////////
// 00101 - The Blocks Problem
/////////////////////////////////
#include<cstdio>
#include<cstring>
int nBlock;
struct block{
	int v,pile;
	struct block*abo;
	struct block*bel;
};
void goBack(block *a){
	if(a == NULL) return;
	goBack(a->abo);
	a->bel->abo = NULL;
	a->bel = NULL;
	a->pile = a->v;
}
void moveOnto(block *a, block *b){
	if(a->bel!=NULL) a->bel->abo = NULL;
	goBack(a->abo);
	goBack(b->abo);
	b->abo = a;
	a->pile = b->pile;
	a->bel = b;
}
void moveOver(block *a, block *b){
	if(a->bel!=NULL) a->bel->abo = NULL;
	while(b->abo!=NULL) b = b->abo;
	goBack(a->abo);
	b->abo = a;
	a->pile = b->pile;
	a->bel = b;
}
void pileOver(block *a, block *b){
	if(a->bel!=NULL) a->bel->abo = NULL;
	while(b->abo!=NULL) b = b->abo;
	b->abo = a;	
	a->bel = b;
	while(a!=NULL){
		a->pile = b->pile;
		a = a->abo;
	}
}
void pileOnto(block *a, block *b){
	if(a->bel!=NULL) a->bel->abo = NULL;
	goBack(b->abo);
	b->abo = a;	
	a->bel = b;
	while(a!=NULL){
		a->pile = b->pile;
		a = a->abo;
	}
}
void showeet(block **b){
	block *aux;
	for(int i = 0; i < nBlock; i++){
		printf("%d:",i);
		if(b[i]->bel == NULL){
			aux = b[i];
			while(aux != NULL){
				printf(" %d",aux->v);
				aux = aux->abo;
			}
		}
		printf("\n");
	}
}
int main(void){
	char cmd[5], mode[5];
	int b1,b2;
	scanf("%d\n",&nBlock);
	struct block*b[nBlock];
	for(int i = 0; i < nBlock; i++){
		b[i] = new block;
		b[i]->v = b[i]->pile = i;
		b[i]->abo = b[i]->bel = NULL;
	}
	while(true){
		scanf("%s ",&cmd);
		if(strcmp(cmd,"quit")==0) break;		
		scanf(" %d %s %d\n",&b1,&mode,&b2);
		if(b1 == b2 || b[b1]->pile == b[b2]->pile) continue;
		if(strcmp(cmd,"move")==0){
			if(strcmp(mode,"onto")==0) moveOnto(b[b1],b[b2]);
			else moveOver(b[b1],b[b2]);
		}
		else if(strcmp(mode,"onto")==0) pileOnto(b[b1],b[b2]);
		else pileOver(b[b1],b[b2]);
	}
	showeet(b);
	return 0;
}
