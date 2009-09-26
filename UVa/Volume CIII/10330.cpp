/////////////////////////////////
// 10330 - Power Transmission
/////////////////////////////////
#include<cstdio>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 202
#define oo 1<<30
int cap[MAX_NODES][MAX_NODES]; // array das capacidades
int flow[MAX_NODES][MAX_NODES];     // matriz de flow
int color[MAX_NODES]; // necessario para bfs
int pred[MAX_NODES];  // array para armazenar o caminho
int b,d,head,i,increment,j,m,n,tail,x,y,z,lim_sup;
//fila para bfs
int q[MAX_NODES];
void enqueue (int x) {
    q[tail] = x;
    tail++;
    color[x] = GRAY;
}

int dequeue () {
    int x = q[head];
    head++;
    color[x] = BLACK;
    return x;
}
//Busca em nível.
int bfs (int start, int target) {	
    for (i = 0; i < lim_sup; i++) color[i] = WHITE;
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head!=tail) {
		i = dequeue();
	    // Procura nos brancos v. Se a capacidade de u a v
	    // na rede residual e positiva, enfileire v
		for (j = 0; j < lim_sup; j++) {
			if (color[j]==WHITE && cap[i][j]-flow[i][j]>0) {
				enqueue(j);
				pred[j] = i;
			}
		}
    }    
    // Se a cor do alvo for preta, significa que ele foi alcancado
    return color[target]==BLACK;
}

int min (int x, int y) {
    return x<y ? x : y; //obvio.
}
// Algoritmo de Ford-Fulkerson
int max_flow (int source, int sink) {    
    // Limpa a matriz de flow.
    int max_flow = 0;
    for (i = 0; i< lim_sup; i++) for (j = 0; j < lim_sup; j++)flow[i][j] = 0;	
    // enquanto existir um caminho aumentante, aumentar o fluxo ao longo do mesmo.
    while (bfs(source,sink)) {    	
        // Determina o incremento do fluxo.
		increment = oo;
		for (i = lim_sup-1; pred[i]!=-1; i=pred[i]) {
			increment = min(increment,cap[pred[i]][i]-flow[pred[i]][i]);			
		}
		// Incrementa o fluxo.
		for (i = lim_sup-1; pred[i]!=-1; i=pred[i]) {
			flow[pred[i]][i] += increment;
			flow[i][pred[i]] -= increment;
		}
		max_flow += increment;
    }
    // Nenhum caminho aumentante restou, fim.
    return max_flow;
}
// Le as entradas e chama o Ford-Fulkerson
int main(void){
	while(scanf("%d",&n)!=EOF){
		lim_sup = (n+1)<<1;
		for(i = 0; i < lim_sup; i++) for(j = 0; j < lim_sup; j++) cap[i][j] = 0;
		for(i = 1; i <= n; scanf("%d",&cap[i][n+i]),i++);
		scanf("%d",&m);
		for(i = 0; i < m; cap[n+x][y] = z,i++)	scanf("%d %d %d",&x,&y,&z);
		scanf("%d %d",&b,&d);
		for(i = 0; i < b; cap[0][x] = oo,i++) scanf("%d",&x);
		for(i = 0; i < d; cap[n+x][2*n+1] = oo,i++) scanf("%d",&x);		
		printf("%d\n",max_flow(0,2*n+1));
	}
	return 0;
}
