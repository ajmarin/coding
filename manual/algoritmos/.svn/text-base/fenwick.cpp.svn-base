/* Incrementa val o numero de ocorrencias do valor idx
 * atualizando todos os seus responsaveis <= que maxy
 */
void update(int idx ,int val){
	while (idx <= maxy)	tree[idx] += val, idx += (idx & -idx);
}
/* Le a frequencia acumulada de todos os numeros
 * ate idx, i.e 1 2 2 2 2 3 4, read(2) retorna 5
 */
int read(int idx){
	int sum = 0;
	if(idx > maxy) idx = maxy;
	while(idx > 0) sum += tree[idx], idx -= (idx & -idx);
	return sum;
}
