#include<cstdio>
#include<cmath>
int i, t, x[4],y[4],z[4];
double misto_quente;
int main(void){
	scanf("%d",&t);
	while(t--){	
		scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x[0],&y[0],&z[0],
		&x[1],&y[1],&z[1],&x[2],&y[2],&z[2],&x[3],&y[3],&z[3]);
		for(i = 0; i < 3; i++){
			x[i] -= x[3]; y[i] -= y[3];	z[i] -= z[3];
		}
		misto_quente = (
		(x[0]*y[1]*z[2]+y[0]*z[1]*x[2]+z[0]*x[1]*y[2])-
		(z[0]*y[1]*x[2]+x[0]*z[1]*y[2]+y[0]*x[1]*z[2])
		)/6.000000;
		printf("%.6lf\n",fabs(misto_quente));
	}
	return 0;
}