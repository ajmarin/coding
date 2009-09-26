/////////////////////////////////
// 00352 - The Seasonal War
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned int eagle_count,n;
char dim,i,j;
char m[27][27];
bool v[27][27];
void recurse(char a, char b){
	if(v[a][b] || m[a][b] != '1') return;
	v[a][b] = 1;
	recurse(a+1,b+1);
	recurse(a+1,b);
	recurse(a+1,b-1);
	recurse(a,b-1);
	recurse(a-1,b-1);
	recurse(a-1,b);
	recurse(a-1,b+1);
	recurse(a,b+1);
}
int main(void){
	for(i = 0; i < 27; i++) m[i][0] = m[0][i] = '.';
	while(scanf("%u\n",&dim)!= EOF){
		n++;
		memset(v,0,sizeof(v));
		for(i = 0; i <= dim; i++) m[dim+1][i] = m[i][dim+1] = '.';
		for(i = 0; i < dim; i++) gets(m[i+1]+1);
		dim += 1; eagle_count = 0;		
		for(i = 1; i < dim; i++)
			for(j = 1; j < dim; j++)
				if(!v[i][j] && m[i][j] == '1')
					recurse(i,j), eagle_count++;
		printf("Image number %u contains %u war eagles.\n",n,eagle_count);
	}
	return 0;
}
