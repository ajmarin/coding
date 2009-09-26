/////////////////////////////////
// 00167 - The Sultan's Successors
/////////////////////////////////
#include<cstdio>
#include<cstdlib>
#define MAXCAND 8
unsigned int cnum,i,j,max,temp;
char m[8][8];
void getcand(int a[], int k, int c[], int *cnd){
	int i,j;
	bool go;
	*cnd = 0;
	for(i = 0; i < 8; i++){
		go = 1;
		for(j = 0; go && j < k ; j++)
			go = !(abs(k-j) == abs(i-a[j]) || a[j] == i);
		if(go)	c[(*cnd)++] = i;
	}
}
void btrack(int a[], int k){
	int c[8];
	int cand = 8;
	int i;
	if(k == 8){
		for(temp = i = 0; i < 8; i++) temp += m[i][a[i+1]];
		if(temp > max) max = temp;
	}
	else {
		++k;
		getcand(a,k,c,&cand);
		for (i = 0; i < cand; i++) {
			a[k] = c[i];
			btrack(a,k);
		}
	}
}
int main (void){
	int a[9];
	scanf("%d",&cnum);
	while(cnum--){
		max = 0;
		for(i = 0; i < 8; i++) for(j = 0; j < 8; j++) scanf("%u",&m[i][j]);
		btrack(a,0);
		printf("%5u\n",max);
	}
	return 0;
}

