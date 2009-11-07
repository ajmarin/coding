/////////////////////////////////
// 00154 - Recycling
/////////////////////////////////
#include<cstdio>
#include<cstring>
int city[100][5],i,ic,j,k,min,record,sum;
char line[100],*ptr;
int getV(char c){
	if(c == 'P') return 1;
	if(c == 'G') return 2;
	if(c == 'S') return 3;
	if(c == 'A') return 4;
	return 5;
}
void assign(char a,char b){
	int k = getV(b), x;
	if(a == 'r') x = 0;
	else if(a == 'g') x = 1;
	else if(a == 'y') x = 2;
	else if(a == 'b') x = 3;
	else x = 4;
	city[ic][x] = k;
}
	
int main(void){
	while(true){
		gets(line);
		if(line[0] == '#') break;
		ic = 0;
		while(true){
			ptr = strtok(line,",");
			while(ptr!=NULL){
				assign(ptr[0],ptr[2]);
				ptr = strtok(NULL,",");
			}
			ic++;
			gets(line);
			if(line[0] == 'e') break;
		}
		if(ic == 1) {
			printf("%d\n",1);
			continue;
		}
		min = 600,record = 0;
		for(int i = 0;i < ic;i++){
			sum = 0;
			for(int j = 0;j < ic;j++){
				if(j == i) continue;
				for(int k = 0;k < 5;k++)
					if(city[i][k]!=city[j][k])	sum++;			
			}
			if(sum < min){
				min = sum;
				record = i;
			}
		}		
		printf("%d\n",record+1);		
	}
}
