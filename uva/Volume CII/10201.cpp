/////////////////////////////////
// 10201 - Adventures in Moving - Part IV
/////////////////////////////////
#include<cstdio>
#include<cstring>
#define MAX_POSTOS 101
int candidato,custo,i,litros,mais_barato,n,npostos,pos_atual,pos_final;
int pos[MAX_POSTOS];
int preco[MAX_POSTOS];
char ch;
bool possivel,achou;
int main(void){
	scanf("%d",&n);
	while(n){
		n--;		
		scanf("%d",&pos_final);
		ch = getchar();
		for(i = 0; ;ch = getchar(),i++){
			if((ch = getchar()) == '\n') break;
			ungetc(ch,stdin);
			if(scanf("%d %d",&pos[i],&preco[i])==EOF) break;
		}
		possivel = 1;
		npostos = i;
		pos[npostos] = pos_final = pos_final+100;
		preco[npostos++] = 0;
		if(pos[0] > 100 || npostos == 1) possivel = 0;
		else for(i = 1;possivel && i < npostos; i++) if(pos[i]-pos[i-1] > 200) possivel = 0;
		if(possivel) {
			litros = 100;
			pos_atual = custo = candidato = 0;
			while(pos_atual+litros < pos_final){
				achou = 0;
				for(i = candidato, mais_barato = 2001; pos_atual+litros >= pos[i]; i++)
					if(preco[i] < mais_barato){
						mais_barato = preco[i];
						candidato = i;
					}
				litros -= pos[candidato]-pos_atual;
				pos_atual = pos[candidato];
				for(i = candidato+1; i < npostos && pos[i] - pos_atual < 200; i++)
					if(preco[i] < preco[candidato]){						
						custo += preco[candidato]*(pos[i]-pos_atual-litros);
						litros = 0;
						pos_atual = pos[i];
						candidato = i;
						achou = 1;
						break;
					}			
				if(!achou) {					
					custo += preco[candidato++]*(200-litros);
					litros = 200;
				}				
			}
		}
		(possivel? printf("%d\n",custo):printf("Impossible\n"));
		if(n) printf("\n");		
	}
}