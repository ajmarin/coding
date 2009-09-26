#include <cstdio>
#include <cctype>
char line[500];
int main(void){
	int a, i, num, sum, test = 1;
	char sign;
	while(scanf("%d\n",&num) && num){		
		gets(line);
		sign = '+'; sum = 0;
		for(i = 0; line[i]; i++){
			a = 0;
			while(isdigit(line[i]))
				a *= 10, a += (line[i]-'0'), i++;
			if(sign == '+') sum += a;
			else sum -= a;
			sign = line[i];
			if(!sign) break;
		}
		printf("Teste %d\n%d\n\n",test++, sum);
	}
	return 0;
}
