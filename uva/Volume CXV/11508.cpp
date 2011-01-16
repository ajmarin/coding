/////////////////////////////////
// 11508 - Life on Mars?
/////////////////////////////////
#include<cstdio>
#include<algorithm>
int v[100000], newv[100000];
int aux,i,inplace,j, max;
char c;
void show(){
	for(j =0; j < (i-1); j++) printf("%d ",newv[j]);
	printf("%d\n",newv[i-1]);
}
int main(void){
	while(true){
		i = max = inplace = aux = 0;
		while(c != '\n'){			
			scanf("%d%c",&v[i],&c);
			if(v[i] > max) max = v[i];			
			i++;
		}
		if(i == 1 && v[0] == 0) break;
		if(max >= i) printf("Message hacked by the Martians!!!\n");		
		else {
			std::sort(v,v+i);
			for(j = 0; j < i; newv[j] = -1, j++);
			for(j = 0; j < i; j++){
				if(newv[v[j]] == -1){
					newv[v[j]] = v[j];
					v[j] = -1;
					inplace++;
				}
			}
			if(inplace != i){
				for(j = 0; j < i && inplace !=i; j++){
					while(newv[aux]!=-1)aux++;
					if(v[j] != -1){
						newv[aux++] = v[j];
						inplace++;										
					}
				}
			}
			show();			
		}		
		c = 'a';
	}
	return 0;
}