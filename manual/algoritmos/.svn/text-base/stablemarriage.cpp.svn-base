int n;
int mpref[N][N], wpref[N][N]; /* preencher com lista de preferencias */
int mmatch[N], wmatch[N]; /* iniciar com -1 */

void smp_solve() {
	while(true) {
		int m = -1, w;
		for(i = 0; i < n && m == -1; i++)
			if(mmatch[i] == -1) m = i;
		if(m == -1) break; /* fim, nao tem nenhum homem nao-casado */

		for(j = 0; j < n; j++) {
			w = mpref[m][j];

			if(wmatch[w] == -1) {
				/* mulher w esta livre, faz (m, w) */
				mmatch[m] = w;
				wmatch[w] = m;
				break;
			} else {
				int ml = wmatch[w];
				int in_m, in_ml;

				/* encontra indices de ml e m */
				for(i = 0; i < n; i++) {
					if(wpref[w][i] == m) in_m = i;
					else if(wpref[w][i] == ml) in_ml = i;
				}

				if(in_m < in_ml) {
					/* desfaz (ml, w) e faz (m, w) */
					mmatch[ml] = -1;
					mmatch[m] = w;
					wmatch[w] = m;
					break;
				}
			}
		}
	}
}
