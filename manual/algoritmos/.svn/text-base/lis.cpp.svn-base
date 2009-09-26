int b[MAX]; // ARRAY DE INDICES DA LIS
int p[MAX]; // ARARY DE PREDECESSORES
int nums[MAX]; // ARRAY DE NUMEROS
void lis(int n){
	if (n < 1) return;
	int i, u, v, tail = -1;
	b[++tail] = 0;
	memset(p,-1,sizeof(int)*n);
	for (i = 1; i < n; i++) {
		/* 
		 * Se o numero atual(nums[i])for maior
		 * que o ultimo elemento da LIS
		 * insira-o no fim da LIS e va
		 * para o proximo numero
		 */
		if (nums[b[tail]] < nums[i]) {
			p[i] = b[tail];
			b[++tail] = i;
			continue;
		}
		/* 
		 * Busca binaria para encontrar
		 * o melhor lugar para inserir
		 * o numero atual (nums[i])
		 */
		for (u = 0, v = tail; u < v;) {
			int c = (u + v)>>1;
			if (nums[b[c]] < nums[i]) u=c+1; else v=c;
		}
 		/*
		 * Substitui o elemento da posicao
		 * u da LIS se, e somente se, 
		 * o numero atual for menor que ele
		 */
		if (nums[i] < nums[b[u]]) {
			if (u) p[i] = b[u-1];
			b[u] = i;
		}	
	}
	/* arruma o array de predecessores */
	for (u = tail+1, v = b[tail]; u--; v = p[v]) b[u] = v;
	/* print */
	for(i =0; i <= tail; i++) printf("%d\n",nums[b[i]]);
}

