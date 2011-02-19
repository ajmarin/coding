#include <cstdio>
#define F(i,n) for(i=1;i<=n;++i)
#define R(x) scanf("%d",&x)
int main(void){
	int i,j,*k,m[108][108],n,t,z; R(t);
	while(t--){
		R(n);z=0;
		F(i,n)F(j,i)
			R(m[i][j]),
			k=m[i-1],
			z=(m[i][j]+=k[j-1]>k[j]?k[j-1]:k[j])>z?m[i][j]:z;
		printf("%d\n",z);
	}
}

