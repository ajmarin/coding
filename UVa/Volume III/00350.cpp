/////////////////////////////////
// 00350 - Pseudo-Random Numbers
/////////////////////////////////
#include<cstdio>
unsigned int casen,f,i,l,length,m,z;
unsigned int used[10000];
int main(void){
	casen = 0;
	while(scanf("%u %u %u %u",&z,&i,&m,&l) && z){
		casen++;
		printf("Case %u: ",casen);
		f = l;
		length = 1;
		for(int k = 0; k < m; used[k] = 0, k++);
		while(!used[l]){
			used[l] = length;
			l = (z*l+i)%m;			
			length++;
		}
		printf("%u\n",(l==f?length-1:length-used[f]-1));
	}
	return 0;
}
