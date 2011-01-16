/////////////////////////////////
// 10033 - Interpreter
/////////////////////////////////
#include<cstdio>
short RAM[1000][3];
int reg[10], counter,i,idx,op,ADDRESS;
char line[5];
int main(void){
	scanf("%d\n",&counter);	
	while(counter){
		counter--;
		for(idx = 0; idx < 1000; idx++) RAM[idx][0] = RAM[idx][1] = RAM[idx][2] = 0;
		for(idx = 0; idx < 10; reg[idx] = 0,idx++);		
		for(i = 0; gets(line) && line[0] != 0;i++){
			RAM[i][0] = line[0]-'0';
			RAM[i][1] = line[1]-'0';
			RAM[i][2] = line[2]-'0';
		}		
		for(op = 1,idx = 0; ;op++,idx++) {			
			if(RAM[idx][0] == 0 && reg[RAM[idx][2]]) idx = reg[RAM[idx][1]]-1;
			else if(RAM[idx][0] == 1 && RAM[idx][1] == 0 && RAM[idx][2] == 0) break;
			else if(RAM[idx][0] == 2) reg[RAM[idx][1]] = RAM[idx][2];
			else if(RAM[idx][0] == 3) reg[RAM[idx][1]] = (reg[RAM[idx][1]]+RAM[idx][2])%1000;
			else if(RAM[idx][0] == 4) reg[RAM[idx][1]] = (reg[RAM[idx][1]]*RAM[idx][2])%1000;
			else if(RAM[idx][0] == 5) reg[RAM[idx][1]] =  reg[RAM[idx][2]];
			else if(RAM[idx][0] == 6) reg[RAM[idx][1]] = (reg[RAM[idx][1]]+reg[RAM[idx][2]])%1000;
			else if(RAM[idx][0] == 7) reg[RAM[idx][1]] = (reg[RAM[idx][1]]*reg[RAM[idx][2]])%1000;
			else if(RAM[idx][0] == 8) {
				ADDRESS = reg[RAM[idx][2]];
				reg[RAM[idx][1]] = 100*RAM[ADDRESS][0]+10*RAM[ADDRESS][1]+RAM[ADDRESS][2];
			}
			else if(RAM[idx][0] == 9) {
				ADDRESS = reg[RAM[idx][2]];
				RAM[ADDRESS][0] = reg[RAM[idx][1]]/100;
				RAM[ADDRESS][1] = (reg[RAM[idx][1]]%100)/10;
				RAM[ADDRESS][2] = reg[RAM[idx][1]]%10;
			}
			
		}
		printf("%d\n",op);
		if(counter) putchar('\n');
	}
	return 0;
}