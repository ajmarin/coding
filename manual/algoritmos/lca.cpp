int n, m;
int adj[NN][NN], deg[NN];
int anc[NN], col[NN]; /* inicializar ancestor = -1, col = 0 */
int qn, qu[NN], qv[NN]; /* queries (u,v) */

void tarjanlca(int u) { /* chame inicialmente na raiz */
	int i, v;
	makeset(u);
	anc[u] = u;
	for(i = 0; i < deg[u]; i++) {
		v = adj[u][i];
		if(anc[v] == -1) { /* verifica se foi visitado */
			tarjanlca(v);
			unionset(u, v);
			anc[findset(u)] = u;
		}
	}
	col[u] = 1;
	for(i = 0; i < qn; i++) {
		/* procura nas queries */
		if(qu[i] == u && col[qv[i]])
			printf("LCA(%d, %d) = %d\n", u+1, qv[i]+1, anc[findset(qv[i])]+1);
		if(qu[i] != qv[i] && qv[i] == u && col[qu[i]])
			printf("LCA(%d, %d) = %d\n", u+1, qu[i]+1, anc[findset(qu[i])]+1);
	}
}
