#include <cstdio>

int main(void){
	int b, d, i, x;
	char c, num[1050];
	while(true){
		c = getc( stdin );
		if(c == '0') break;
		for(i = x = 0; c != '\n'; i++, c = getc( stdin )){
			x += c;
			num[i] = c; 
		}
		num[i] = d = 0;
		x -= '0'*i;
		if(x%9) printf("%s is not a multiple of 9.\n",num);
		else{
			d = 1;
			while(x != 9){
				b = x; x = 0;
				while(b) x+=(b%10),b/=10;
				d++;
			}
			printf("%s is a multiple of 9 and has 9-degree %d.\n",num,d);
		}
	}
	return 0;
}

