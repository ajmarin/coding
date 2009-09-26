/////////////////////////////////
// 10008 - What's Cryptanalysis?
/////////////////////////////////
#include<cstdio>
char c;
char str[500];
int max[30];
int occ[30];
int n;
struct node{
	int value, let;
	struct node*next;
};
int main(void){
	int i = 0,n;
	scanf("%d",&n);
	while(n+1){
		gets(str);
		n--;
		i = 0;
		while(str[i]){
			c = str[i++];
			if(c > 64 && c < 91)
				occ[c-65]++;
			else if(c > 96 && c < 123)
				occ[c-97]++;
		}
	}
	node*root = new node;
	for(i = 0; occ[i]==0; i++);
	root->value = occ[i];
	root->let = i+65;
	node*aux;
	for(i++; i < 26; i++){
		if(occ[i]){
			node*novo = new node;
			novo->value = occ[i];
			novo->let = i+65;	
			aux = root;
			if(novo->value > root->value){
				root = novo;
				novo->next = aux;
			}
			else {
				while(aux->next != NULL && aux->next->value >= novo->value) aux = aux->next;			
				novo->next = aux->next;
				aux->next = novo;
			}
		}
	}
	aux = root;
	while(aux!=NULL && aux->value > 0){
		printf("%c %d\n",aux->let,aux->value);
		aux = aux->next;
	}
	return 0;	
}

