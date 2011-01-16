#include <cstdio>
struct A {
	int id, nota;
}aln[1032];
int main(void){
	for(int i, max, n, t = 1; scanf("%d",&n) && n; t++){
		for(max = i = 0; i < n; i++){
			scanf("%d%d",&aln[i].id,&aln[i].nota);
			if(aln[i].nota > max) max = aln[i].nota;
		}
		printf("Turma %d\n",t);
		for(i = 0;  i < n; i++)	
			if(aln[i].nota == max) printf("%d ",aln[i].id);
		printf("\n\n");
	}
	return 0;
}
