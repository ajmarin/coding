int idx[4000], nnnn, low[4000], SCC[4000], stack[4000], scc_count, top;
bool stacked[4000], NO;
void push(int a){
	stack[top++] = a;
	stacked[a] = 1;
}
int pop(){
	stacked[stack[--top]] = 0;
	return stack[top];
}
void tarjan(int k){

	idx[k] = low[k] = nnnn = nnnn+1;
	stack[top++] = k;
	stacked[k] = 1;
	for(typeof(adj[k].begin())it = adj[k].begin(); it != adj[k].end(); it++){
		int nadj = (*it);
		if(idx[nadj] == -1){
			tarjan(nadj);
			low[k] = MIN(low[k],low[nadj]);
		} else if(stacked[nadj]) {
			low[k] = MIN(low[k],idx[nadj]);
		}		
	}
	if(low[k] == idx[k]){
		scc_count++;
		int x = -1;
		while(x != k)SCC[x = pop()] = scc_count;
	}
}
