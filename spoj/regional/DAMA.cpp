#include<cstdio>
#include<cstdlib>
int xi,yi,xf,yf;
bool a,b;
int main(void){
	while(scanf("%d %d %d %d\n",&xi,&yi,&xf,&yf) && xi){
		a = xi == xf;
		b = yi == yf;
		if(a && b) putchar('0');
		else if(a || b || (abs(xf-xi) == abs(yf-yi))) putchar('1');
		else putchar('2');
		putchar('\n');
	}
	return 0;
}
