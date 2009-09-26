/////////////////////////////////
// 10035 - Primary Arithmetic
/////////////////////////////////
#include<cstdio>
long n1, n2;
int carries;
int getCarry();
int main(){		
	while(scanf("%d %d",&n1,&n2)){		
		if(n1 == n2 && n2 == 0) break;
		carries = getCarry();
		if(carries == 0) printf("No carry operation.\n");
		else if(carries == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n",carries);
	}
}
int getCarry(){
	int ret = 0, d1,d2, carry = 0;
	while(n1 != 0 || n2!=0){
		d1 = (int)n1%10; n1/=10;
		d2 = (int)n2%10; n2/=10;
		if(d1+d2+carry > 9){ 
			ret++;
			carry = 1;
		}
		else carry = 0;
	}
	return ret;
}

