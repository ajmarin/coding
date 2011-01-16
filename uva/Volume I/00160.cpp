/////////////////////////////////
// 00160 - Factors and Factorials
/////////////////////////////////
#include<cstdio>
int pfact[101][98];
int curr[98];
int primes[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int counter,i,j,k;
void getFactors(){
	for(j = 2; j < 98;curr[j]=0,j++);
	for(j = i; j > 1; j--)
		for(k = j; k > 1;k--){
			if(k > 97) k = 97;
			curr[k] += pfact[j][k];
		}
}
int main(void){
	for(i = 2; i < 101; i++)
		for(j = 0,k = i; k!=1; j++)
			while(k%primes[j]==0) {
				pfact[i][primes[j]]++;
				k /= primes[j];
			}
	scanf("%d",&i);
	while(i){		
		getFactors();
		printf("%3d! =",i);
		for(j = 2,counter =0; j < 98 && j <= i ; j++)
			if(curr[j]){
				if(counter == 15){
					printf("\n      ");
					counter = 0;
				}
				printf("%3d",curr[j]);
				counter++;				
			}
		printf("\n");
		scanf("%d",&i);
	}
	return 0;
}
