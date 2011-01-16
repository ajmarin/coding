/////////////////////////////////
// 00102 - Ecological Bin Packing
/////////////////////////////////
#include <cstdio>
int A,B,C,movs,mteste;

struct caixa {
	int m,v,t;//marrom,verde,transparente
	char cor;
};
int main(){
	struct caixa c[3];
    while (scanf("%d %d %d %d %d %d %d %d %d",&c[0].m,&c[0].v,&c[0].t,&c[1].m,&c[1].v,&c[1].t,&c[2].m,&c[2].v,&c[2].t)!=EOF){
		movs = 1000000000;
		mteste = 0;
		for(A = 0; A < 3; A++)
			for(B = 0; B < 3; B++){
				if (A == B) continue;
				C = 3 - (A+B);
				mteste = c[A].v + c[A].t + c[B].m + c[B].v + c[C].m +c[C].t;
				if(mteste < movs){
					movs = mteste;
					c[A].cor = 'B';
					c[B].cor = 'C';
					c[C].cor = 'G';
				}
			}
		printf("%c%c%c %d\n",c[0].cor ,c[1].cor,c[2].cor,movs);
	}
}