int idx[NN], nnnn, low[NN], SCC[NN], s[NN], scc_count, top;
bool ins[NN], NO;
#define MIN (a,b) ((a)>(b)?(b):(a))
void push(int a){
	s[top++] = a;
	ins[a] = 1;
}
int pop(){
	ins[s[--top]] = 0;
	return s[top];
}
void cleartarjan(){
	nnnn = top = 0;
}
void tarjan(int k){

	idx[k] = low[k] = nnnn = nnnn+1;
	push(k);
	for(typeof(adj[k].begin())it = adj[k].begin(); it != adj[k].end(); it++){
		int nadj = (*it);
		if(idx[nadj] == -1){
			tarjan(nadj);
			low[k] = MIN(low[k],low[nadj]);
		} else if(ins[nadj]) {
			low[k] = MIN(low[k],idx[nadj]);
		}		
	}
	if(low[k] == idx[k]){
		scc_count++;
		int x = -1;
		while(x != k)SCC[x = pop()] = scc_count;
	}
}
