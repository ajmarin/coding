#include <cstdio>

int yuanfen(const char *s, int n){
	int cnt = 0, digits[64];
	for(int i = 0; s[i]; ++i){
		int v = s[i] - 'A' + n;
		int stack[8], top = 0;
		while(v){
			stack[top++] = v % 10;
			v /= 10;
		}
		while(top--) digits[cnt++] = stack[top];
	}
	while(cnt > 2){
		cnt--;
		for(int i = 0; i < cnt; ++i){
			digits[i] = (digits[i] + digits[i + 1]) % 10;
		}
		if(cnt == 3 && digits[0] == 1 && digits[1] == 0 && digits[2] == 0)
			return 100;
	}
	return 10 * digits[0] + digits[1];
}

int main(void){
	for(char s[16]; scanf("%s", s) == 1; ){
		int i;
		for(i = 1; i <= 10000; ++i){
			if(yuanfen(s, i) == 100){
				printf("%d\n", i);
				break;
			}
		}
		if(i > 10000) puts(":(");
	}
	return 0;
}

