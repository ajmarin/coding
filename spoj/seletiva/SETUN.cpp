#include<cstdio>
#include<cstdlib>
int b3[20];
int absn, acc, current, dist, i, n;
int main(void){
	b3[0] = 1;
	for(i = 1; i  < 20; i++) b3[i] = 3*b3[i-1];//, printf("%d\n",b3[i]);
	while(scanf("%d",&n)!=EOF){
		current = 0;
		absn = abs(n);
		for(acc = i = 0; (acc+=b3[i]) < absn; i++);
		for(; i > -1; i--){
			if(current < n){
				dist = n - current;
				if(abs(current+b3[i]-n) < dist)
					current += b3[i], putchar('+');
				else putchar('0');
			} else {
				dist = current - n;
				if(abs(current-b3[i]-n) < dist)
					current -= b3[i], putchar('-');
				else putchar('0');
			}
		}
		putchar('\n');
	}
	return 0;
}