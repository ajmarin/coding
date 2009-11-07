/////////////////////////////////
// 00186 - Trip Routing
/////////////////////////////////
#include<cstring>
#include<cstdlib>
#include<cstdio>
char hashc[101][21];
char hashe[201][11]; 
char temp[101]; 
int adj[101][101];
int adj2[101][101]; 
int a,b,c,d,indexc, index2;
bool visitado[27];
int dist[27];
int anterior[27];
int total;
const int oo = 1<<30;
void mostrarRota(int S)
{
   if(S==anterior[S]) return;
   mostrarRota(anterior[S]);
   total+=adj[anterior[S]][S];
   printf("%-20s %-20s %-10s %5d\n",hashc[anterior[S]],hashc[S],hashe[adj2[anterior[S]][S]],adj[anterior[S]][S]);
}
int hash(bool type, char* str)
{
   if(type){
		int i;
      for(i=1; i<=indexc; i++){
         if(strcmp(hashc[i], str)==0) return i;
      }
      strcpy(hashc[++indexc], str);
      return indexc;
   }
   else{
      int i;
      for(i=1; i<=index2; i++){
         if(strcmp(hashe[i], str)==0) return i;
      }
      strcpy(hashe[++index2], str);
      return index2;
   }
}
int main()
{   
   int i, j;
   for(i = 1; i < 100; i++){
      for(j = 1; j < 100; j++){
         adj[i][j]=oo;
      }
   }
   while(gets(temp)){
      if(strlen(temp)==0) break;      
      a=hash(1, strtok(temp, ","));
      b=hash(1, strtok(NULL, ","));
      c=hash(0, strtok(NULL, ","));
      d=atoi(strtok(NULL, "\n"));
      if(d < adj[a][b]){
			adj[a][b]=adj[b][a]=d;
			adj2[a][b]=adj2[b][a]=c;
		}
   }
   while(gets(temp)){
      int inicio=hash(1, strtok(temp, ","));
      int fim=hash(1, strtok(NULL, "\n"));
      for(i=1; i< 27; dist[i] = oo,i++) visitado[i] = anterior[i] = 0;
      visitado[inicio]=1;
      for(i=1; i< 27; i++){
         dist[i]=adj[inicio][i];
         anterior[i]=inicio;
      }
      while(true){
         int min=oo, valormin;
         for(i = 1; i< 27; i++){
            if(dist[i]<min&&!visitado[i]){
               min = dist[i];
               valormin = i;
            }
         }
         visitado[valormin]=1;
         for(i = 1; i< 27; i++){
            if(dist[i]>dist[valormin]+adj[valormin][i]&&!visitado[i]){
               dist[i]=dist[valormin]+adj[valormin][i];
               anterior[i]=valormin;
            }
         }
         if(valormin==fim){
            total=0;
            printf("\n\n%-20s %-20s %-10s %-5s\n","From","To","Route","Miles");
            printf("-------------------- -------------------- ---------- -----\n");
            mostrarRota(valormin);
            printf("%58s\n","-----");
            printf("%47s %10d\n","Total", total);
            break;
         }
      }
   }
   return 0;
}
