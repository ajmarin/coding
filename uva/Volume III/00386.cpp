/////////////////////////////////
// 00386 - Perfect Cubes
/////////////////////////////////
#include<cstdio>
unsigned int i,j,k,l;
int main(void){
	for(i = 6; i < 201; i++)
		for(j = 2; j < i-2; j++)
			for(k = j+1; k < i-1; k++)
				for(l = k+1; l < i; l++)
					if(j*j*j+k*k*k+l*l*l == i*i*i)
						printf("Cube = %u, Triple = (%u,%u,%u)\n",i,j,k,l);
	return 0;
}

