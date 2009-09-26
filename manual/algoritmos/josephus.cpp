int joseph(int n){
	vector< int >  v;
	int dir, died, i, m;
	/* dir = 1	:= horario
	 * dir = 0	:= anti-horario
	 * m		:= passos para matar o proximo
	 * died		:= guarda quem vai morrer
	 */
	for(i = 0; i < n; i++) v.push_back(i);
	/* Inicializacao:
	 * se o sentido for horario
	 * died = 1, senao died = 0
	 * m = 1 (mata todos em sequencia)
	 */
	died = dir;
	m = 1;
	/* mata ate o penultimo */
	for(i = 0; i < (n-1); i++){
		if(dir) died = (died-1+m)%(n-i);
		else {
			m = -m;
			died = (died+m);
			while(died < 0) died += (n-i);
			died%=(n-i);
		}
		m = 0; // atualiza o valor da proxima contagem
		v.erase(v.begin()+died);
	}
	/* retorna o numero do sobrevivente */
	return *v.begin();
}

