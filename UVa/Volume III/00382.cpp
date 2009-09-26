/////////////////////////////////
// 00382 - Perfection
/////////////////////////////////
#include<cstdio>
#define MAX 60001
bool sieve[MAX];
bool added[MAX];
int primes[6056];
int i,j,k,n,sum,pos,first;
struct factor{
	int v;
	struct factor *next;
};
void build_sieve(){
	primes[pos++] = 2;
	for(i = 4; i < MAX; i+=2) sieve[i] = true;
	for(i = 3; i < MAX; i+=2)
		if(!sieve[i]){
			primes[pos++] = i;
			if(i < 245) for(j = i*i; j < MAX-1; j+=i) sieve[j] = true;
		}
}
void perfect(){
	sum = 1;
	k = n;
	factor *last,*novo,*atual,*root = NULL;	
	for(i = 0; k!=1; i++)
		while(k%primes[i]==0){
			novo = new factor;
			novo->v = primes[i];
			last = novo;
			if(root == NULL) root = novo;
			else {
				atual = root;				
				while(atual!=NULL){
					factor *a = new factor;
					a->v = primes[i]*atual->v;
					last->next = a;
					last = a;
					atual = atual->next;
				}
				atual = root;
				while(atual->next!=NULL) atual = atual->next;
				atual->next = novo;	
			}
			k/=primes[i];
		}
	for(atual = root; atual != NULL && sum < n; atual = atual->next)
		if(!added[atual->v] && atual->v < n){
			sum+=atual->v;
			added[atual->v] = 1;
		}
	if(sum == n) printf("%5d  PERFECT\n",n);
	else if(sum > n) printf("%5d  ABUNDANT\n",n);
	else printf("%5d  DEFICIENT\n",n);
}
int main(void){
	build_sieve();
	scanf("%d", &n);
	printf("PERFECTION OUTPUT\n");
	while(n){
		if(!sieve[n]) printf("%5d  DEFICIENT\n",n);
		else {
			for(i = 0; i < n; added[i] = 0, i++);
			perfect();
		}
		scanf("%d",&n);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
		
	
